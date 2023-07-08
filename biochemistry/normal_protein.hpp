#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_NORMAL_PROTEIN_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_NORMAL_PROTEIN_HPP_INCLUDED

#include "biochemistry/aminoacid.hpp"
#include "biochemistry/protein.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class normal_protein : public protein
	{
		public:
			normal_protein();

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

bool operator ==(const scifir::normal_protein&,const scifir::normal_protein&);
bool operator !=(const scifir::normal_protein&,const scifir::normal_protein&);

ostream& operator <<(ostream&,const scifir::normal_protein&);

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_NORMAL_PROTEIN_HPP_INCLUDED
