#include "./ultimate_aminoacid.hpp"

using namespace std;

namespace scifir
{
	map<string,int> ultimate_aminoacids_number = map<string,int>();
	map<int,full_ultimate_aminoacid> ultimate_aminoacids = map<int,full_ultimate_aminoacid>();
	int ultimate_aminoacids_storage_count = 0;

	ultimate_aminoacid::ultimate_aminoacid() : aminoacid(),ultimate_type_number()
	{
	}

	ultimate_aminoacid::ultimate_aminoacid(const string& new_abbreviation) : aminoacid(aminoacid::Other),ultimate_type_number()
	{
		store_ultimate_aminoacid(new_abbreviation);
		ultimate_type_number = scifir::ultimate_aminoacids_number[new_abbreviation];
	}

	void store_ultimate_aminoacid(const string& x)
	{
		if (scifir::ultimate_aminoacids_number.count(x) == 0)
		{
			ultimate_aminoacids_number[x] = ultimate_aminoacids_storage_count;
			ultimate_aminoacids_storage_count++;
		}
	}
}
