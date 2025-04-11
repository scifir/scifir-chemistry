#ifndef SCIFIR_CHEMISTRY_ATOMS_NORMAL_ATOM_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_ATOMS_NORMAL_ATOM_HPP_INCLUDED

#include "./atom.hpp"

#include "scifir/units.hpp"

#include <cmath>
#include <cstdint>
#include <sstream>

using namespace scifir;

namespace scifir
{
	template<typename T>
	class normal_atom : public atom_crtp<T>
	{
		public:
			normal_atom(int new_ionic_charge = 0,int new_neutrons_number = T::mass_number) : atom_crtp<T>(),mass_number(new_neutrons_number),ionic_charge(new_ionic_charge)
			{
				if (static_cast<unsigned int>(new_ionic_charge) > atom_crtp<T>::get_z())
				{
					throw "ionic charge is greater than z";
				}
			}

			virtual bool is_factible() const
			{
				if (static_cast<unsigned int>(get_ionic_charge()) > atom_crtp<T>::get_z())
				{
					return false;
				}
				if (atom::is_atomic_group_a())
				{
					if (atom::is_atom_specimen(atom_symbol::H) or atom::is_atom_specimen(atom_symbol::He))
					{
						if ((get_ionic_charge() < 0) and (static_cast<unsigned int>(std::abs(get_ionic_charge())) > (2 - atom_crtp<T>::get_z())))
						{
							return false;
						}
					}
					else
					{
						if ((get_ionic_charge() < 0) and (static_cast<unsigned int>(std::abs(get_ionic_charge())) > (8 - atom_crtp<T>::get_z())))
						{
							return false;
						}
					}
				}
				return true;
			}

			virtual string save() const
			{
				ostringstream output;
				output << atom_crtp<T>::get_symbol();
				if (atom::is_uncommon_isotope())
				{
					output << "[" << mass_number << "]";
				}
				return output.str();
			}

		private:
			uint8_t mass_number;
			uint8_t ionic_charge;
	};
}

#endif // SCIFIR_CHEMISTRY_ATOMS_NORMAL_ATOM_HPP_INCLUDED
