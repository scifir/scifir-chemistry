#ifndef MSCI_CHEMISTRY_BIOCHEMISTRY_AMINOACID_HPP_INCLUDED
#define MSCI_CHEMISTRY_BIOCHEMISTRY_AMINOACID_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

namespace scifir
{
	class aminoacid
	{
		public:
			enum type {Ala,Arg,Asn,Asp,Cys,Glu,Gln,Gly,His,Ile,Leu,Lys,Met,Phe,Pro,Pyl,Sec,Ser,Thr,Trp,Tyr,Val,Other,Err};

			aminoacid();
			aminoacid(aminoacid::type);
			aminoacid(const string&);

			inline aminoacid::type& get_type()
			{
				return aminoacid_type;
			}

			inline const aminoacid::type& get_type() const
			{
				return aminoacid_type;
			}

			bool is_valid() const;

			string get_name() const;
			string get_abbreviation() const;

		private:
			aminoacid::type aminoacid_type;
	};

	string aminoacid_name(aminoacid::type);
	string aminoacid_abbreviation(aminoacid::type);

	aminoacid::type create_aminoacid_type(const string&);

	bool is_aminoacid(const string&);
}

bool operator == (const scifir::aminoacid&,const scifir::aminoacid&);
bool operator != (const scifir::aminoacid&,const scifir::aminoacid&);

ostream& operator <<(ostream&,scifir::aminoacid&);

#endif // MSCI_CHEMISTRY_BIOCHEMISTRY_AMINOACID_HPP_INCLUDED
