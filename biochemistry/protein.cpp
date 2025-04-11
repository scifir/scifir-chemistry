#include "./protein.hpp"

#include <sstream>

using namespace std;

namespace scifir
{
	protein::protein() : aminoacids()
	{
	}

	aminoacid::type protein::operator [](int i)
	{
		return aminoacids.at(i);
	}

	aminoacid::type protein::operator [](int i) const
	{
		return aminoacids.at(i);
	}

	string protein::get_aminoacid_sequence() const
	{
		ostringstream out;
		for (int i = 0; i < number_of_aminoacids(); i++)
		{
			out << aminoacid_abbreviation(aminoacids[i]);
			if (i != number_of_aminoacids())
			{
				out << "-";
			}
		}
		return out.str();
	}

	void protein::add_aminoacid(aminoacid::type x)
	{
		aminoacids.push_back(x);
	}
}

bool operator ==(const scifir::protein& x,const scifir::protein& y)
{
	if (x.number_of_aminoacids() != y.number_of_aminoacids())
	{
		return false;
	}
	for (int i = 0; i < x.number_of_aminoacids(); i++)
	{
		if (x[i] != y[i])
		{
			return false;
		}
	}
	return true;
}

bool operator !=(const scifir::protein& x,const scifir::protein& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const scifir::protein& x)
{
	return os << x.get_aminoacid_sequence();
}
