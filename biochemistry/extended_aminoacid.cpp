#include "./extended_aminoacid.hpp"

using namespace std;

namespace scifir
{
	map<string,int> extended_aminoacids_number = map<string,int>();
	map<int,full_extended_aminoacid> extended_aminoacids = map<int,full_extended_aminoacid>();
	int extended_aminoacids_storage_count = 0;

	extended_aminoacid::extended_aminoacid() : aminoacid(),extended_type_number()
	{
	}

	extended_aminoacid::extended_aminoacid(const string& new_abbreviation) : aminoacid(aminoacid::OTHER),extended_type_number()
	{
		store_extended_aminoacid(new_abbreviation);
		extended_type_number = scifir::extended_aminoacids_number[new_abbreviation];
	}

	void store_extended_aminoacid(const string& x)
	{
		if (scifir::extended_aminoacids_number.count(x) == 0)
		{
			extended_aminoacids_number[x] = extended_aminoacids_storage_count;
			extended_aminoacids_storage_count++;
		}
	}
}
