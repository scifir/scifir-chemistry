#include "./atomic_bond.hpp"

#include "scifir/units.hpp"

using namespace std;

namespace scifir
{
	atomic_bond::atomic_bond() : atom1(),atom2(),weight(),bond_length()
	{
	}

	atomic_bond::atomic_bond(const shared_ptr<atom>& x,const shared_ptr<atom>& y,atomic_bond_order new_atomic_bond_order) : atom1(x),atom2(y),weight(new_atomic_bond_order),bond_length("1 mm")
	{
	}

	int atomic_bond::get_total_electrons() const
	{
		switch(weight)
		{
		case atomic_bond_order::SINGLE:
			return 2;
		case atomic_bond_order::DUAL:
			return 4;
		case atomic_bond_order::TRIPLE:
			return 6;
		default:
			return 2;
		}
	}

	bool atomic_bond::is_bond(const string& x) const
	{
		if (x.size() != 3)
		{
			return false;
		}
		return false;
		/*if ((x[0] == atom1_lock->get_symbol() and x[2] == atom2_lock->get_symbol()) or (x[2] == atom1_lock->get_symbol() and x[0] == atom2_lock->get_symbol()))
		{
			if((x[1] == '-' and weight == atomic_bond_order::SINGLE) or (x[1] == '=' and weight == atomic_bond_order::DUAL) or (x[1] == '≡' and weight == atomic_bond_order::TRIPLE))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}*/
	}
}
