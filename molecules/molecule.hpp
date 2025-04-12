#ifndef SCIFIR_CHEMISTRY_MOLECULES_MOLECULE_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_MOLECULES_MOLECULE_HPP_INCLUDED

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include "../atoms/atom.hpp"
#include "./atomic_bond.hpp"
#include "./atomic_bond_builder.hpp"

#include "scifir/units.hpp"

using namespace std;

namespace scifir
{
	enum class functional_group {CARBONYL, AMINE, NITRILE, CARBOXYLIC_ACID, ESTER, ALCOHOL, ETHER, PHENYL};

	class molecule
	{
		public:
			molecule();
			explicit molecule(const vector<atom>& new_atoms,const vector<atomic_bond_builder>& new_atomic_bonds);
			explicit molecule(const vector<atom::atomic_species>& new_atoms,const vector<atomic_bond_builder>& new_atomic_bonds);

			virtual vector<shared_ptr<atom>> get_atoms() const;
			virtual vector<shared_ptr<atomic_bond>> get_bonds() const;
			virtual int get_total_atoms() const;

			bool is_factible() const;

			mass get_standard_atomic_mass() const;
			mass get_real_mass() const;
			mass get_real_mass_simplified() const;
			mass get_electrons_mass() const;

			inline mass get_total_mass() const
            {
            	return mass(get_real_mass() + get_electrons_mass());
            }

            string get_name() const;
			string get_formula() const;
			string get_canonical_formula() const;

			int get_ionic_charge() const;
            bool is_ion() const;
            bool is_anion() const;
            bool is_cation() const;
            bool is_neutral() const;

            inline bool is_very_big_molecule() const
            {
            	return (get_total_atoms() <= 500);
            }

            //dipole get_dipole() const;

            bool has_atom(atom::atomic_species) const;
            bool has_bond(const string&) const;
            bool has_bond_group(const string&) const;
            bool has_functional_group(functional_group) const;

            virtual void add_atom(const atom&);

            virtual bool is_cyclical() const;
            virtual bool is_acyclical() const;
            bool is_polar() const;
            bool is_apolar() const;
            bool is_chiral() const;
            bool is_achiral() const;
            bool is_protic() const;
            bool is_aprotic() const;

            inline bool is_organic() const
			{
				return has_bond("C-H");
			}

			inline bool is_inorganic() const
			{
				return !is_organic();
			}

            bool is_biochemical() const;

            int number_of_chiral_atoms() const;
            int number_of_enantiomers() const;

            bool is_eter() const;

            virtual void save(const string&,const string&) const;

		private:
			///tuple<shared_ptr<atom>,scifir::coordinates_3d<>> get_image_3d_calculate_atom_position(shared_ptr<atom>,tuple<shared_ptr<atom>,scifir::coordinates_3d<>>,tuple<shared_ptr<atom>,scifir::coordinates_3d<>>) const;
			//void get_atoms_image_3d(vector<tuple<shared_ptr<atom>,scifir::coordinates_3d<>>>) const;
			//void get_unpaired_electrons_image_3d(vector<tuple<scifir::coordinates_3d,math_vector>>) const;
			//void get_bonds_image_3d(vector<tuple<shared_ptr<atom>,scifir::coordinates_3d<>>>) const;
			
			vector<shared_ptr<atom>> atoms;
			vector<shared_ptr<atomic_bond>> bonds;
	};

	bool are_isomers(const molecule&,const molecule&);
	bool are_conformational_isomers(const molecule&,const molecule&);
	bool are_enantiomers(const molecule&,const molecule&);
	bool are_miscible(const molecule&,const molecule&);
	bool are_inmiscible(const molecule&,const molecule&);

	string generate_hash(const molecule&);
}

ostream& operator <<(ostream&,const scifir::molecule&);
bool operator ==(const scifir::molecule&,const scifir::molecule&);
bool operator !=(const scifir::molecule&,const scifir::molecule&);

#endif // SCIFIR_CHEMISTRY_MOLECULES_MOLECULE_HPP_INCLUDED
