#include "./lipid.hpp"

using namespace std;

namespace scifir
{
	lipid::lipid() : biomolecule(biomolecule::LIPID), lipid_type()
	{}
	
	lipid::lipid(const string& new_name, lipid::type new_type) : biomolecule(biomolecule::LIPID,new_name), lipid_type(new_type)
	{}

	string lipid::get_systematic_name() const
	{
		return "";
	}
}
