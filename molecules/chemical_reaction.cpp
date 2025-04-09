#include "./chemical_reaction.hpp"

using namespace std;

namespace scifir
{
	chemical_reaction::chemical_reaction() : reactants(),products()
	{}

	scifir::energy chemical_reaction::get_enthalpy_change() const
	{
		return scifir::energy();
	}

	scifir::entropy chemical_reaction::get_entropy_change() const
	{
		return scifir::entropy();
	}
}
