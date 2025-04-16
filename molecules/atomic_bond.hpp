#ifndef SCIFIR_CHEMISTRY_MOLECULES_ATOMIC_BOND_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_MOLECULES_ATOMIC_BOND_HPP_INCLUDED

#include <memory>

#include "../atoms/atom.hpp"
#include "scifir/units.hpp"

using namespace std;

namespace scifir
{
	class atomic_bond
	{
		public:
			atomic_bond();
			atomic_bond(const shared_ptr<atom>&,const shared_ptr<atom>&,atomic_bond_order);

			inline const shared_ptr<atom>& get_atom1() const
			{
				return atom1;
			}

			inline const shared_ptr<atom>& get_atom2() const
			{
				return atom2;
			}

			inline const length& get_bond_length() const
			{
				return bond_length;
			}

			inline const atomic_bond_order& get_atomic_bond_weight() const
			{
				return weight;
			}

			/*inline enthalpy get_bond_enthalpy()
			{
				//return bond_enthalpy;
			}*/

			inline bool is_covalent() const
			{
				return (is_covalent_polar() or is_covalent_apolar());
			}

			inline bool is_covalent_polar() const
			{
				return !is_covalent_apolar();
			}

			inline bool is_covalent_apolar() const
			{
				return (atom1->get_electronegativity() == atom2->get_electronegativity());
			}

			inline bool is_ionic() const
			{
				return ((atom1->get_electronegativity() - atom2->get_electronegativity()) >= 2);
			}

			inline atomic_bond_type get_atomic_bond_type()
			{
				if (atom1->is_non_metal() and atom2->is_metallic())
				{
					return atomic_bond_type::IONIC;
				}
				else if(atom1->is_non_metal() and atom2->is_non_metal())
				{
					return atomic_bond_type::COVALENT;
				}
				else if(atom1->is_metallic() and atom2->is_metallic())
				{
					return atomic_bond_type::METALLIC;
				}
			}

			inline bool is_flexible() const
			{
				return (weight == atomic_bond_order::SINGLE);
			}

			inline bool is_rigid() const
			{
				return !is_flexible();
			}

			inline bool is_single() const
			{
				return (weight == atomic_bond_order::SINGLE);
			}

			inline bool is_double() const
			{
				return (weight == atomic_bond_order::DUAL);
			}

			inline bool is_triple() const
			{
				return (weight == atomic_bond_order::TRIPLE);
			}

			int get_total_electrons() const;
			bool is_bond(const string&) const;

		private:
			shared_ptr<atom> atom1;
			shared_ptr<atom> atom2;
			atomic_bond_order weight;
			length bond_length;
			//enthalpy bond_enthalpy;
	};
}

#endif // SCIFIR_CHEMISTRY_MOLECULES_ATOMIC_BOND_HPP_INCLUDED
