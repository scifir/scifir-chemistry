#include "biochemistry/normal_carbohidrate.hpp"

using namespace std;

namespace scifir
{
	normal_carbohidrate::normal_carbohidrate() : carbohidrate(),type()
	{
	}

	normal_carbohidrate::normal_carbohidrate(carbohidrate_type x) : carbohidrate(),type(x)
	{
	}

	string carbohidrate_name(carbohidrate_type x)
	{
		if (x == carbohidrate_type::glucose)
		{
			return "glucose";
		}
		else if (x == carbohidrate_type::lactose)
		{
			return "lactose";
		}
		else if (x == carbohidrate_type::galactose)
		{
			return "galactose";
		}
		else if (x == carbohidrate_type::maltose)
		{
			return "maltose";
		}
		else if (x == carbohidrate_type::sacarose)
		{
			return "sacarose";
		}
		else if (x == carbohidrate_type::fructose)
		{
			return "fructose";
		}
	}
}

bool operator ==(const scifir::normal_carbohidrate& x,const scifir::normal_carbohidrate& y)
{
	return x.get_type() == y.get_type();
}

bool operator !=(const scifir::normal_carbohidrate& x,const scifir::normal_carbohidrate& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const scifir::normal_carbohidrate& x)
{
	return os << carbohidrate_name(x.get_type());
}
