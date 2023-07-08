#ifndef MSCI_CHEMISTRY_BIOCHEMISTRY_ULTIMATE_AMINOACID_HPP_INCLUDED
#define MSCI_CHEMISTRY_BIOCHEMISTRY_ULTIMATE_AMINOACID_HPP_INCLUDED

#include "biochemistry/aminoacid.hpp"
#include "biochemistry/full_ultimate_aminoacid.hpp"

#include <map>
#include <string>

using namespace std;

namespace scifir
{
	extern map<string,int> ultimate_aminoacids_number;
	extern map<int,full_ultimate_aminoacid> ultimate_aminoacids;
	extern int ultimate_aminoacids_storage_count;

	class ultimate_aminoacid : public aminoacid
	{
		public:
			ultimate_aminoacid();
			ultimate_aminoacid(const string&);

			inline int& get_number()
			{
				return ultimate_type_number;
			}

			inline const int& get_number() const
			{
				return ultimate_type_number;
			}

		private:
			int ultimate_type_number;
	};

	void store_ultimate_aminoacid(const string&);
}

#endif // MSCI_CHEMISTRY_BIOCHEMISTRY_ULTIMATE_AMINOACID_HPP_INCLUDED
