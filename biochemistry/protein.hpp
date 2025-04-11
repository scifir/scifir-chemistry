#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_PROTEIN_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_PROTEIN_HPP_INCLUDED

#include "./aminoacid.hpp"
#include "./protein.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class protein
	{
		public:
			protein();

			inline vector<aminoacid::type>& get_aminoacids()
			{
				return aminoacids;
			}

			inline const vector<aminoacid::type>& get_aminoacids() const
			{
				return aminoacids;
			}

			inline int number_of_aminoacids()
			{
				return aminoacids.size();
			}

			inline int number_of_aminoacids() const
			{
				return aminoacids.size();
			}

			aminoacid::type operator [](int);
			aminoacid::type operator [](int) const;

			string get_aminoacid_sequence() const;

			void add_aminoacid(aminoacid::type);

		private:
			vector<aminoacid::type> aminoacids;
	};
}

bool operator ==(const scifir::protein&,const scifir::protein&);
bool operator !=(const scifir::protein&,const scifir::protein&);

ostream& operator <<(ostream&,const scifir::protein&);

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_PROTEIN_HPP_INCLUDED
