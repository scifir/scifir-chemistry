#include "molecules/chemical_reaction.hpp"

using namespace std;

namespace scifir
{
	chemical_reaction::chemical_reaction() : reactants(),products()
	{}

	scifir::enthalpy chemical_reaction::get_enthalpy_change() const
	{
		return scifir::enthalpy();
	}

	scifir::entropy chemical_reaction::get_entropy_change() const
	{
		return scifir::entropy();
	}
}
