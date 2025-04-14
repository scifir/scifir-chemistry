#include "./lipid.hpp"

using namespace std;

namespace scifir
{
	lipid::lipid() : lipid_type()
	{}
	
	lipid::lipid(lipid::type new_type) : lipid_type(new_type)
	{}

	string lipid::get_systematic_name() const
	{
		return "";
	}
}
