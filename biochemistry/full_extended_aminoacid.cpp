#include "./full_extended_aminoacid.hpp"

using namespace std;

namespace scifir
{
	full_extended_aminoacid::full_extended_aminoacid() : abbreviation(),name(),molecule_literal()
	{
	}

	full_extended_aminoacid::full_extended_aminoacid(const string& new_abbreviation,const string& new_name,const string& new_molecule_literal) : abbreviation(new_abbreviation),name(new_name),molecule_literal(new_molecule_literal)
	{
	}
}
