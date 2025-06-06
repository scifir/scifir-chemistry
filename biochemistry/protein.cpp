#include "./protein.hpp"

#include <cmath>
#include <sstream>

using namespace std;

namespace scifir
{
	protein::protein() : biomolecule(biomolecule::PROTEIN),aminoacids()
	{}

	protein::protein(const string& new_name,const vector<aminoacid::type>& new_aminoacids) : biomolecule(biomolecule::PROTEIN,new_name),aminoacids(new_aminoacids)
	{}

	protein::protein(const string& new_name,const vector<aminoacid>& new_aminoacids) : biomolecule(biomolecule::PROTEIN,new_name),aminoacids()
	{
		for(const aminoacid& new_aminoacid : new_aminoacids)
		{
			aminoacids.push_back(new_aminoacid.aminoacid_type);
		}
	}

	protein::protein(const string& new_name,const string& init_protein) : biomolecule(biomolecule::PROTEIN,new_name),aminoacids()
	{
		if ((init_protein.length() / 3) == (std::floor(init_protein.length()) / 3))
		{
			for (int i = 0; i < init_protein.length(); i += 3)
			{
				aminoacids.push_back(create_aminoacid_type(init_protein.substr(i,3)));
			}
		}
	}

	string protein::get_aminoacid_sequence() const
	{
		ostringstream out;
		for (int i = 0; i < aminoacids.size(); i++)
		{
			out << aminoacid_abbreviation(aminoacids[i]);
			if (i != aminoacids.size())
			{
				out << "-";
			}
		}
		return out.str();
	}

	string protein::get_aminoacid_one_letter_sequence() const
	{
		ostringstream out;
		for (int i = 0; i < aminoacids.size(); i++)
		{
			out << aminoacid_one_letter_abbreviation(aminoacids[i]);
			if (i != aminoacids.size())
			{
				out << "-";
			}
		}
		return out.str();
	}
}

bool operator ==(const scifir::protein& x,const scifir::protein& y)
{
	if (x.aminoacids.size() != y.aminoacids.size())
	{
		return false;
	}
	for (int i = 0; i < x.aminoacids.size(); i++)
	{
		if (x.aminoacids[i] != y.aminoacids[i])
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
