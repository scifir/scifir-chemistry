#include "./aminoacid.hpp"
#include "./extended_aminoacid.hpp"

using namespace std;

namespace scifir
{
	aminoacid::aminoacid() : aminoacid_type()
	{
	}

	aminoacid::aminoacid(aminoacid::type x) : aminoacid_type(x)
	{
	}

	aminoacid::aminoacid(const string& x) : aminoacid_type()
	{
		if (is_aminoacid(x))
		{
			aminoacid_type = create_aminoacid_type(x);
		}
		else
		{
			aminoacid_type = aminoacid::ERROR;
		}
	}

	bool aminoacid::is_valid() const
	{
		return (aminoacid_type != aminoacid::ERROR);
	}

	string aminoacid::get_name() const
	{
		if (aminoacid_type != aminoacid::OTHER)
		{
			return aminoacid_name(aminoacid_type);
		}
		else
		{
			extended_aminoacid x_ultimate = reinterpret_cast<const extended_aminoacid&>(*this);
			return extended_aminoacids[x_ultimate.get_number()].get_name();
		}
	}

	string aminoacid::get_abbreviation() const
	{
		if (aminoacid_type != aminoacid::OTHER)
		{
			return aminoacid_abbreviation(aminoacid_type);
		}
		else
		{
			extended_aminoacid x_ultimate = reinterpret_cast<const extended_aminoacid&>(*this);
			return extended_aminoacids[x_ultimate.get_number()].get_abbreviation();
		}
	}

	string aminoacid_name(aminoacid::type x)
	{
		if (x == aminoacid::Ala)
		{
			return "Alanine";
		}
		else if (x == aminoacid::Arg)
		{
			return "Arginine";
		}
		else if (x == aminoacid::Asn)
		{
			return "Asparagine";
		}
		else if (x == aminoacid::Asp)
		{
			return "Aspartic acid";
		}
		else if (x == aminoacid::Cys)
		{
			return "Cysteine";
		}
		else if (x == aminoacid::Glu)
		{
			return "Glutamic acid";
		}
		else if (x == aminoacid::Gln)
		{
			return "Glutamine";
		}
		else if (x == aminoacid::Gly)
		{
			return "Glycine";
		}
		else if (x == aminoacid::His)
		{
			return "Histidine";
		}
		else if (x == aminoacid::Ile)
		{
			return "Isoleucine";
		}
		else if (x == aminoacid::Leu)
		{
			return "Leucine";
		}
		else if (x == aminoacid::Lys)
		{
			return "Lysine";
		}
		else if (x == aminoacid::Met)
		{
			return "Methionine";
		}
		else if (x == aminoacid::Phe)
		{
			return "Phenylalanine";
		}
		else if (x == aminoacid::Pro)
		{
			return "Proline";
		}
		else if (x == aminoacid::Pyl)
		{
			return "Pyrrolysine";
		}
		else if (x == aminoacid::Sec)
		{
			return "Selenocysteine";
		}
		else if (x == aminoacid::Ser)
		{
			return "Serine";
		}
		else if (x == aminoacid::Thr)
		{
			return "Threonine";
		}
		else if (x == aminoacid::Trp)
		{
			return "Tryptophan";
		}
		else if (x == aminoacid::Tyr)
		{
			return "Tyrosine";
		}
		else if (x == aminoacid::Val)
		{
			return "Valine";
		}
		else if (x == aminoacid::ERROR)
		{
			return "Error";
		}
		else if (x == aminoacid::OTHER)
		{
			return "Other";
		}
		return "";
	}

	string aminoacid_abbreviation(aminoacid::type x)
	{
		if (x == aminoacid::Ala)
		{
			return "Ala";
		}
		else if (x == aminoacid::Arg)
		{
			return "Arg";
		}
		else if (x == aminoacid::Asn)
		{
			return "Asn";
		}
		else if (x == aminoacid::Asp)
		{
			return "Asp";
		}
		else if (x == aminoacid::Cys)
		{
			return "Cys";
		}
		else if (x == aminoacid::Glu)
		{
			return "Glu";
		}
		else if (x == aminoacid::Gln)
		{
			return "Gln";
		}
		else if (x == aminoacid::Gly)
		{
			return "Gly";
		}
		else if (x == aminoacid::His)
		{
			return "His";
		}
		else if (x == aminoacid::Ile)
		{
			return "Ile";
		}
		else if (x == aminoacid::Leu)
		{
			return "Leu";
		}
		else if (x == aminoacid::Lys)
		{
			return "Lys";
		}
		else if (x == aminoacid::Met)
		{
			return "Met";
		}
		else if (x == aminoacid::Phe)
		{
			return "Phe";
		}
		else if (x == aminoacid::Pro)
		{
			return "Pro";
		}
		else if (x == aminoacid::Pyl)
		{
			return "Pyl";
		}
		else if (x == aminoacid::Sec)
		{
			return "Sec";
		}
		else if (x == aminoacid::Ser)
		{
			return "Ser";
		}
		else if (x == aminoacid::Thr)
		{
			return "Thr";
		}
		else if (x == aminoacid::Trp)
		{
			return "Trp";
		}
		else if (x == aminoacid::Tyr)
		{
			return "Tyr";
		}
		else if (x == aminoacid::Val)
		{
			return "Val";
		}
		else if (x == aminoacid::ERROR)
		{
			return "Err";
		}
		else if (x == aminoacid::OTHER)
		{
			return "000";
		}
		return "";
	}

	string aminoacid_one_letter_abbreviation(aminoacid::type x)
	{
		if (x == aminoacid::Ala)
		{
			return "A";
		}
		else if (x == aminoacid::Arg)
		{
			return "R";
		}
		else if (x == aminoacid::Asn)
		{
			return "N";
		}
		else if (x == aminoacid::Asp)
		{
			return "D";
		}
		else if (x == aminoacid::Cys)
		{
			return "C";
		}
		else if (x == aminoacid::Glu)
		{
			return "E";
		}
		else if (x == aminoacid::Gln)
		{
			return "Q";
		}
		else if (x == aminoacid::Gly)
		{
			return "G";
		}
		else if (x == aminoacid::His)
		{
			return "H";
		}
		else if (x == aminoacid::Ile)
		{
			return "I";
		}
		else if (x == aminoacid::Leu)
		{
			return "L";
		}
		else if (x == aminoacid::Lys)
		{
			return "K";
		}
		else if (x == aminoacid::Met)
		{
			return "M";
		}
		else if (x == aminoacid::Phe)
		{
			return "F";
		}
		else if (x == aminoacid::Pro)
		{
			return "P";
		}
		else if (x == aminoacid::Pyl)
		{
			return "O";
		}
		else if (x == aminoacid::Sec)
		{
			return "U";
		}
		else if (x == aminoacid::Ser)
		{
			return "S";
		}
		else if (x == aminoacid::Thr)
		{
			return "T";
		}
		else if (x == aminoacid::Trp)
		{
			return "W";
		}
		else if (x == aminoacid::Tyr)
		{
			return "Y";
		}
		else if (x == aminoacid::Val)
		{
			return "V";
		}
		else if (x == aminoacid::ERROR)
		{
			return "0";
		}
		else if (x == aminoacid::OTHER)
		{
			return "1";
		}
		return "";
	}

	aminoacid::type create_aminoacid_type(const string& x)
	{
		if (x == "Ala")
		{
			return aminoacid::Ala;
		}
		else if (x == "Arg")
		{
			return aminoacid::Arg;
		}
		else if (x == "Asn")
		{
			return aminoacid::Asn;
		}
		else if (x == "Asp")
		{
			return aminoacid::Asp;
		}
		else if (x == "Cys")
		{
			return aminoacid::Cys;
		}
		else if (x == "Glu")
		{
			return aminoacid::Glu;
		}
		else if (x == "Gln")
		{
			return aminoacid::Gln;
		}
		else if (x == "Gly")
		{
			return aminoacid::Gly;
		}
		else if (x == "His")
		{
			return aminoacid::His;
		}
		else if (x == "Ile")
		{
			return aminoacid::Ile;
		}
		else if (x == "Leu")
		{
			return aminoacid::Leu;
		}
		else if (x == "Lys")
		{
			return aminoacid::Lys;
		}
		else if (x == "Met")
		{
			return aminoacid::Met;
		}
		else if (x == "Phe")
		{
			return aminoacid::Phe;
		}
		else if (x == "Pro")
		{
			return aminoacid::Pro;
		}
		else if (x == "Pyl")
		{
			return aminoacid::Pyl;
		}
		else if (x == "Sec")
		{
			return aminoacid::Sec;
		}
		else if (x == "Ser")
		{
			return aminoacid::Ser;
		}
		else if (x == "Thr")
		{
			return aminoacid::Thr;
		}
		else if (x == "Trp")
		{
			return aminoacid::Trp;
		}
		else if (x == "Tyr")
		{
			return aminoacid::Tyr;
		}
		else if (x == "Val")
		{
			return aminoacid::Val;
		}
		else
		{
			return aminoacid::OTHER;
		}
	}

	bool is_aminoacid(const string& x)
	{
		if (x == "Ala" or x == "Arg" or x == "Asn" or x == "Asp" or x == "Cys" or x == "Glu" or x == "Gln" or x == "Gly" or x == "His" or x == "Ile" or x == "Leu" or x == "Lys" or x == "Met" or x == "Phe" or x == "Pro" or x == "Pyl" or x == "Sec" or x == "Ser" or x == "Thr" or x == "Trp" or x == "Tyr" or x == "Val")
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool operator == (const scifir::aminoacid& x,const scifir::aminoacid& y)
{
	return (x.aminoacid_type == y.aminoacid_type);
}

bool operator != (const scifir::aminoacid& x,const scifir::aminoacid& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,scifir::aminoacid& x)
{
	return os << x.get_abbreviation();
}
