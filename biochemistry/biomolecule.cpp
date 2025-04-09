#include "./biomolecule.hpp"

using namespace std;

namespace scifir
{
	biomolecule::biomolecule() : bio_type()
	{
	}

	biomolecule::biomolecule(biomolecule_type x) : bio_type(x)
	{
	}

	string biomolecule_type_name(biomolecule_type x)
	{
		if (x == biomolecule_type::carbohidrate)
		{
			return "carbohidrate";
		}
		else if (x == biomolecule_type::lipid)
		{
			return "lipid";
		}
		else if (x == biomolecule_type::protein)
		{
			return "protein";
		}
	}
}
