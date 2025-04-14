#include "./carbohidrate.hpp"

using namespace std;

namespace scifir
{
	carbohidrate::carbohidrate() : biomolecule(biomolecule::CARBOHIDRATE),carbohidrate_type()
	{}

	carbohidrate::carbohidrate(carbohidrate::type new_carbohidrate_type,const string& new_name) : biomolecule(biomolecule::CARBOHIDRATE,new_name),carbohidrate_type(new_carbohidrate_type)
	{}

	string carbohidrate_name(carbohidrate::common x)
	{
		if (x == carbohidrate::GLUCOSE)
		{
			return "glucose";
		}
		else if (x == carbohidrate::LACTOSE)
		{
			return "lactose";
		}
		else if (x == carbohidrate::GALACTOSE)
		{
			return "galactose";
		}
		else if (x == carbohidrate::MALTOSE)
		{
			return "maltose";
		}
		else if (x == carbohidrate::SACAROSE)
		{
			return "sacarose";
		}
		else if (x == carbohidrate::FRUCTOSE)
		{
			return "fructose";
		}
		return "";
	}
}

bool operator ==(const scifir::carbohidrate& x,const scifir::carbohidrate& y)
{
	return x.carbohidrate_type == y.carbohidrate_type;
}

bool operator !=(const scifir::carbohidrate& x,const scifir::carbohidrate& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const scifir::carbohidrate& x)
{
	return os << x.name;
}
