#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_AMINOACID_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_AMINOACID_HPP_INCLUDED

#include <iostream>
#include <string>

#include "./biomolecule.hpp"

using namespace std;

namespace scifir
{
	class aminoacid : public biomolecule
	{
		public:
			enum type {Ala,Arg,Asn,Asp,Cys,Glu,Gln,Gly,His,Ile,Leu,Lys,Met,Phe,Pro,Pyl,Sec,Ser,Thr,Trp,Tyr,Val,OTHER,AMINOACID_ERROR};

			aminoacid();
			aminoacid(aminoacid::type);
			aminoacid(const string&);

			bool is_valid() const;

			string get_name() const;
			string get_abbreviation() const;
			string get_one_letter_abbreviation() const;

			aminoacid::type aminoacid_type;
	};

	string aminoacid_name(aminoacid::type);
	string aminoacid_abbreviation(aminoacid::type);
	string aminoacid_one_letter_abbreviation(aminoacid::type);

	aminoacid::type create_aminoacid_type(const string&);

	bool is_aminoacid(const string&);
}

bool operator == (const scifir::aminoacid&,const scifir::aminoacid&);
bool operator != (const scifir::aminoacid&,const scifir::aminoacid&);

ostream& operator <<(ostream&,scifir::aminoacid&);

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_AMINOACID_HPP_INCLUDED
