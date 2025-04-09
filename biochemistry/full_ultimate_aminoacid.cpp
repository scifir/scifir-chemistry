#include "./full_ultimate_aminoacid.hpp"

using namespace std;

namespace scifir
{
	full_ultimate_aminoacid::full_ultimate_aminoacid() : abbreviation(),name(),molecule_literal()
	{
	}

	full_ultimate_aminoacid::full_ultimate_aminoacid(const string& new_abbreviation,const string& new_name,const string& new_molecule_literal) : abbreviation(new_abbreviation),name(new_name),molecule_literal(new_molecule_literal)
	{
	}
}
