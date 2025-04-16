#ifndef SCIFIR_CHEMISTRY_MOLECULES_ATOMIC_BOND_BUILDER_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_MOLECULES_ATOMIC_BOND_HPP_INCLUDED

#include <memory>

#include "../atoms/atom.hpp"
#include "scifir/units.hpp"

using namespace std;

namespace scifir
{
	class atomic_bond_builder
	{
		public:
			atomic_bond_builder();
			atomic_bond_builder(int new_atom1,int new_atom2,atomic_bond_order new_weight = atomic_bond_order::SINGLE);

			int atom1;
			int atom2;
			atomic_bond_order weight;
	};
}

#endif // SCIFIR_CHEMISTRY_MOLECULES_ATOMIC_BOND_HPP_INCLUDED
