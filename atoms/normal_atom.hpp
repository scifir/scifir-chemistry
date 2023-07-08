#ifndef SCIFIR_CHEMISTRY_ATOMS_NORMAL_ATOM_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_ATOMS_NORMAL_ATOM_HPP_INCLUDED

#include "atoms/atom.hpp"

#include "scifir/units/units.hpp"
#include "particles.hpp"

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

			virtual bool is_exotic() const
			{
				return false;
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

			virtual int get_ionic_charge() const
			{
				return ionic_charge;
			}

			virtual int get_electrons_number() const
            {
            	return (atom_crtp<T>::get_z() - get_ionic_charge());
            }

            virtual const unsigned int get_mass_number() const
            {
            	return mass_number;
            }

            virtual string get_electronic_configuration() const
            {
            	int remaining_electrons = get_electrons_number();
            	if (remaining_electrons == 0)
				{
					return "empty configuration";
				}
				return "";
            }

            virtual int get_lone_pairs() const
            {
            	int unpaired_electrons = get_electrons_number();
            	for (const auto& bond : atom::get_bonds())
				{
					shared_ptr<atomic_bond> bond_lock = bond.lock();
					//unpaired_electrons -= bond_lock->get_total_electrons();
				}
				return unpaired_electrons / 2;
            }

            virtual mass get_real_mass() const
            {
            	return mass(atom_crtp<T>::get_z() * scifir::proton::common_mass,"amu");
            }

            virtual mass get_electrons_mass() const
            {
            	return mass(get_electrons_number() * scifir::electron::common_mass,"amu");
            }

			virtual void print_image_2d() const
			{
			}

			virtual void print_image_3d() const
			{
			}

			virtual string get_file_format() const
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
