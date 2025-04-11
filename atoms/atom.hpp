#ifndef SCIFIR_CHEMISTRY_ATOMS_ATOM_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_ATOMS_ATOM_HPP_INCLUDED

#include <cmath>
#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "scifir/units.hpp"

#include "atomic_orbital.hpp"

using namespace std;

namespace scifir
{
	enum class atomic_block {s,p,d,f};

	enum class molecular_geometry {NONE, LINEAR,TRIGONAL_PLANAR,BENT,TETRAHEDRAL,TRIGONAL_PYRAMIDAL,TRIGONAL_BIPYRAMIDAL,SEESAW,T_SHAPED,OCTAHEDRAL,SQUARE_PYRAMIDAL,SQUARE_PLANAR,PENTAGONAL_BIPYRAMIDAL,PENTAGONAL_PYRAMIDAL,PLANAR_PENTAGONAL,SQUARE_ANTIPRISTAMIC,TRICAPPED_TRIGONAL_PRISMATIC};
	
	enum class molecular_geometry_position {LINEAR,BENT,TRIGONAL_PLANAR,TRIGONAL_PYRAMIDAL,T_SHAPED_AX,T_SHAPED_EQ,TETRAHEDRAL,SEESAW_AX,SEESAW_EQ,SQUARE_PLANAR,TRIGONAL_BIPYRAMIDAL_AX,TRIGONAL_BIPYRAMIDAL_EQ,SQUARE_PYRAMIDAL_AX,SQUARE_PYRAMIDAL_EQ,PLANAR_PENTAGONAL,OCTAHEDRAL,PENTAGONAL_PYRAMIDAL_AX,PENTAGONAL_PYRAMIDAL_EQ,PENTAGONAL_BIPYRAMIDAL_AX,PENTAGONAL_BIPYRAMIDAL_EQ,SQUARE_ANTIPRISTAMIC,TRICAPPED_TRIGONAL_PRISMATIC};
	
	enum class atomic_bond_type {IONIC,COVALENT,METALLIC};
	
	enum class atomic_bond_weight {SINGLE,DUAL,TRIPLE};
	
	enum class crystal_structure {BCC,HEXAGONAL};
	
	enum class magnetic_ordering {DIAMAGNETIC,PARAMAGNETIC};
	
	enum class atomic_drawing {NONE,LINE,PREPICATED_LINE,WAVE_LINE,PREPICATED_WAVE_LINE,CIRCLES}; // This definition has been created in Scifir to give to each atom species a different drawing style that allows to differentiate it from other atoms of other species

	extern vector<vector<int>> electronic_configuration_order;

	class atom
	{
		public:

			enum atomic_species {NO_SPECIES, H, D, T, He, Li, Be, B, C, N, O, F, Ne, Na, Mg, Al, Si, P, S, Cl, Ar, K, Ca, Sc, Ti, V, Cr, Mn, Fe, Co, Ni, Cu, Zn, Ga, Ge, As, Se, Br, Kr, Rb, Sr, Y, Zr, Nb, Mo, Tc, Ru, Rh, Pd, Ag, Cd, In, Sn, Sb, Te, I, Xe, Cs, Ba, La, Ce, Pr, Nd, Pm, Sm, Eu, Gd, Tb, Dy, Ho, Er, Tm, Yb, Lu, Hf, Ta, W, Re, Os, Ir, Pt, Au, Hg, Tl, Pb, Bi, Po, At, Rn, Fr, Ra, Ac, Th, Pa, U, Np, Pu, Am, Cm, Bk, Cf, Es, Fm, Md, No, Lr, Rf, Db, Sg, Bh, Hs, Mt, Ds, Rg, Cn, Nh, Fl, Mc, Lv, Ts, Og, CUSTOM_ATOMIC_SPECIES};

			enum atomic_group {NO_GROUP, IA, IIA, IIIA, IVA, VA, VIA, VIIA, VIIIA, IB, IIB, IIIB, IVB, VB, VIB, VIIB, VIIIB, LA, AC};

			class orbital_configuration
			{
				public:
					orbital_configuration();
					orbital_configuration(int,orbital::type,int);

					string display() const;

					int period;
					orbital::type orbital_type;
					int electrons;
			};

			atom();
			explicit atom(atom::atomic_species);
			explicit atom(const string&);

			inline atom::atomic_species get_specimen() const
			{
				return species;
			}

			string get_name() const;
			string get_symbol() const;

			atom::atomic_group get_atomic_group() const;
			int get_period() const;
			//virtual const atomic_block& get_atomic_block() const = 0;

			int get_z() const;
			int get_valence_number() const;
			int get_mass_number() const;
			int get_common_mass_number() const;

			length get_atomic_radius() const;
			mass get_standard_atomic_mass() const;

			float get_electronegativity() const;
			bool is_radioactive() const;

			/*virtual const temperature& get_melting_point() const = 0;
			virtual const temperature& get_boiling_point() const = 0;
			virtual const density& get_density_stp() const = 0;

			virtual const molar_enthalpy& get_heat_of_fusion() const = 0;
			virtual const molar_enthalpy& get_heat_of_vaporization() const = 0;
			virtual const molar_heat_capacity& get_heat_capacity() const = 0;*/

			molar_energy get_ionization_energy() const;
			length get_covalent_radius() const;
			length get_van_der_waals_radius() const;

			/*virtual const crystal_structure get_crystal_structure() const = 0;
			virtual const thermal_conductivity& get_thermal_conductivity() const = 0;
			virtual const magnetic_ordering& get_magnetic_ordering() const = 0;
			virtual const magnetic_susceptibility& get_magnetic_susceptibility() const = 0;*/
			//cas_number get_cas_number() const;

			inline bool is_atom_specimen(atom::atomic_species x) const
			{
				return (x == species);
			}

			bool is_factible() const;

			int get_ionic_charge() const;

            inline bool is_ion() const
            {
            	return (get_ionic_charge() != 0);
            }

            inline bool is_anion() const
            {
            	return (get_ionic_charge() < 0);
            }

            inline bool is_cation() const
            {
            	return (get_ionic_charge() > 0);
            }

            inline bool is_neutral() const
            {
            	return (get_ionic_charge() == 0);
            }

            inline bool is_metallic() const
            {
            	return (is_pure_metal() or is_transition_metal());
            }

            inline bool is_pure_metal() const
            {
            	return (get_atomic_group() == IA or get_atomic_group() == IIA);
            }

            inline bool is_transition_metal() const
            {
            	return (get_atomic_group() == IB or get_atomic_group() == IIB or get_atomic_group() == IIIB or get_atomic_group() == IVB or get_atomic_group() == VB or get_atomic_group() == VIB or get_atomic_group() == VIIB or get_atomic_group() == VIIIB);
            }

            inline bool is_non_metal() const
            {
            	return (get_z() == 1 or get_z() == 6 or get_z() == 7 or get_z() == 8 or get_z() == 9 or get_z() == 15 or get_z() == 16 or get_z() == 17 or get_z() == 34 or get_z() == 35 or get_z() == 53 or get_z() == 2 or get_z() == 10 or get_z() == 18 or get_z() == 36 or get_z() == 54 or get_z() == 86);
            }

            inline bool is_metalloid() const
            {
            	return (get_z() == 5 or get_z() == 6 or get_z() == 13 or get_z() == 14 or get_z() == 32 or get_z() == 33 or get_z() == 34 or get_z() == 51 or get_z() == 52 or get_z() == 84 or get_z() == 85);
            }

            inline bool is_alkali_metal() const
            {
            	return (get_atomic_group() == atom::IA);
            }

            inline bool is_alkaline_earth_metal() const
            {
            	return (get_atomic_group() == atom::IIA);
            }

            inline bool is_boron_group() const
            {
            	return (get_atomic_group() == atom::IIIA);
            }

            inline bool is_carbon_group() const
            {
            	return (get_atomic_group() == atom::IVA);
            }

            inline bool is_nitrogen_group() const
            {
            	return (get_atomic_group() == atom::VA);
            }

            inline bool is_chalcogen() const
            {
            	return (get_atomic_group() == atom::VIA);
            }

            inline bool is_halogen() const
            {
            	return (get_atomic_group() == atom::VIIA);
            }

            inline bool is_noble_gas() const
            {
            	return (get_atomic_group() == atom::VIIIA);
            }

            inline bool is_lanthanide() const
            {
            	return (get_atomic_group() == atom::LA);
            }

            inline bool is_actinide() const
            {
            	return (get_atomic_group() == atom::AC);
            }

            inline bool is_rare_earth() const
            {
            	return (is_lanthanide() or is_atom_specimen(atom::Sc) or is_atom_specimen(atom::Y));
            }

            inline bool is_atomic_group_a() const
            {
				return (get_atomic_group() == atom::IA or get_atomic_group() == atom::IIA or get_atomic_group() == atom::IIIA or get_atomic_group() == atom::IVA or get_atomic_group() == atom::VA or get_atomic_group() == atom::VIA or get_atomic_group() == atom::VIIA or get_atomic_group() == atom::VIIIA);
            }

            inline bool is_atomic_group_b() const
            {
				return (get_atomic_group() == atom::IB or get_atomic_group() == atom::IIB or get_atomic_group() == atom::IIIB or get_atomic_group() == atom::IVB or get_atomic_group() == atom::VB or get_atomic_group() == atom::VIB or get_atomic_group() == atom::VIIB or get_atomic_group() == atom::VIIIB);
            }

            int get_electrons_number() const;

			inline int get_valence_electrons_number() const
			{
				return (get_valence_number() - get_ionic_charge());
			}

			vector<atom::orbital_configuration> get_electronic_configuration() const;

            string display_electronic_configuration() const;

			int get_lone_pairs() const;

            mass get_real_mass() const;

            inline mass get_real_mass_simplified() const
            {
				int calculated_mass = get_z() + get_mass_number();
            	return mass(calculated_mass,"amu");
            }

            mass get_electrons_mass() const;

            inline mass get_total_mass() const
            {
            	return mass(get_real_mass() + get_electrons_mass());
            }

            inline bool is_common_isotope() const
            {
            	return (get_common_mass_number() == neutrons);
            }

            inline bool is_uncommon_isotope() const
            {
            	return !is_common_isotope();
            }

            virtual bool is_exotic() const;

            scifir::color get_atomic_color() const;

			atomic_drawing get_atomic_pattern() const;

			molecular_geometry get_molecular_geometry(int) const;

			bool is_valence_full() const;

			bool is_chiral() const;

			inline bool is_achiral() const
			{
				return !is_chiral();
			}

			/*electron_cloud get_electron_cloud() const
			{

			}*/

			string save() const;

		private:
			atom::atomic_species species;
			int8_t charge;
			int8_t neutrons;

			static vector<atom::orbital_configuration> electronic_configuration;
	};

	scifir::angle get_molecular_geometry_angle(const atom&);

	bool are_isotopes(const atom&,const atom&);
	bool are_isobares(const atom&,const atom&);
	bool are_isoelectronics(const atom&,const atom&);
	bool same_element(const atom&,const atom&);
	bool same_specimen(const atom&,const atom&);

	string to_string(const atom::atomic_species&);
	string to_string(const atom::atomic_group&);
	string to_string(const atomic_block&);
	string to_string(const orbital::type);

	atom::atomic_species create_atomic_species(const string&);
}

bool operator ==(const scifir::atom&,const scifir::atom&);
bool operator !=(const scifir::atom&,const scifir::atom&);
ostream& operator <<(ostream&,const scifir::atom&);

#endif // SCIFIR_CHEMISTRY_ATOMS_ATOM_HPP_INCLUDED
