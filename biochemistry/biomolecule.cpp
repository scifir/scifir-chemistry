#include "./biomolecule.hpp"

using namespace std;

namespace scifir
{
	biomolecule::biomolecule() : biomolecule_type(),name()
	{}

	biomolecule::biomolecule(biomolecule::type x) : biomolecule_type(x),name()
	{}

	biomolecule::biomolecule(biomolecule::type x,const string& new_name) : biomolecule_type(x),name(new_name)
	{}

	string biomolecule_type_name(biomolecule::type x)
	{
		if (x == biomolecule::CARBOHIDRATE)
		{
			return "carbohidrate";
		}
		else if (x == biomolecule::LIPID)
		{
			return "lipid";
		}
		else if (x == biomolecule::AMINOACID)
		{
			return "aminaocid";
		}
		else if (x == biomolecule::PROTEIN)
		{
			return "protein";
		}
		return "";
	}
}
