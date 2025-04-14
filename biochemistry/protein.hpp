#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_PROTEIN_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_PROTEIN_HPP_INCLUDED

#include "./biomolecule.hpp"
#include "./aminoacid.hpp"
#include "./protein.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	class protein : public biomolecule
	{
		public:
			protein();
			explicit protein(const string& new_name,const vector<aminoacid::type>& new_aminoacids);
			explicit protein(const string& new_name,const string& init_protein);

			string get_aminoacid_sequence() const;
			string get_aminoacid_one_letter_sequence() const;

			vector<aminoacid::type> aminoacids;
	};
}

bool operator ==(const scifir::protein&,const scifir::protein&);
bool operator !=(const scifir::protein&,const scifir::protein&);

ostream& operator <<(ostream&,const scifir::protein&);

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_PROTEIN_HPP_INCLUDED
