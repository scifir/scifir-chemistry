#include "./carbohidrate.hpp"

using namespace std;

namespace scifir
{
	carbohidrate::carbohidrate() : type()
	{}

	carbohidrate::carbohidrate(carbohidrate_type x) : type(x)
	{}

	string carbohidrate_name(carbohidrate_type x)
	{
		if (x == carbohidrate_type::GLUCOSE)
		{
			return "glucose";
		}
		else if (x == carbohidrate_type::LACTOSE)
		{
			return "lactose";
		}
		else if (x == carbohidrate_type::GALACTOSE)
		{
			return "galactose";
		}
		else if (x == carbohidrate_type::MALTOSE)
		{
			return "maltose";
		}
		else if (x == carbohidrate_type::SACAROSE)
		{
			return "sacarose";
		}
		else if (x == carbohidrate_type::FRUCTOSE)
		{
			return "fructose";
		}
	}
}

bool operator ==(const scifir::carbohidrate& x,const scifir::carbohidrate& y)
{
	return x.get_type() == y.get_type();
}

bool operator !=(const scifir::carbohidrate& x,const scifir::carbohidrate& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const scifir::carbohidrate& x)
{
	return os << carbohidrate_name(x.get_type());
}
