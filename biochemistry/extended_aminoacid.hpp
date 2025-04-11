#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_EXTENDED_AMINOACID_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_EXTENDED_AMINOACID_HPP_INCLUDED

#include "./aminoacid.hpp"
#include "./full_extended_aminoacid.hpp"

#include <map>
#include <string>

using namespace std;

namespace scifir
{
	extern map<string,int> extended_aminoacids_number;
	extern map<int,full_extended_aminoacid> extended_aminoacids;
	extern int extended_aminoacids_storage_count;

	class extended_aminoacid : public aminoacid
	{
		public:
			extended_aminoacid();
			extended_aminoacid(const string&);

			inline int& get_number()
			{
				return extended_type_number;
			}

			inline const int& get_number() const
			{
				return extended_type_number;
			}

		private:
			int extended_type_number;
	};

	void store_extended_aminoacid(const string&);
}

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_EXTENDED_AMINOACID_HPP_INCLUDED
