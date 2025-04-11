#include "./atomic_bond_builder.hpp"

using namespace std;

namespace scifir
{
	atomic_bond_builder::atomic_bond_builder(int new_atom1,int new_atom2,atomic_bond_weight new_weight) : atom1(new_atom1),atom2(new_atom2),weight(new_weight)
	{}
}