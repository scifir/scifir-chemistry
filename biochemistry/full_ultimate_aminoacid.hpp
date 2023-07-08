#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_FULL_ULTIMATE_AMINOACID_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_FULL_ULTIMATE_AMINOACID_HPP_INCLUDED

#include <string>

using namespace std;

namespace scifir
{
	class full_ultimate_aminoacid
	{
		public:
			full_ultimate_aminoacid();
			full_ultimate_aminoacid(const string&,const string&,const string&);

			inline string& get_abbreviation()
			{
				return abbreviation;
			}

			inline const string& get_abbreviation() const
			{
				return abbreviation;
			}

			inline string& get_name()
			{
				return name;
			}

			inline const string& get_name() const
			{
				return name;
			}

			inline string& get_molecule_literal()
			{
				return molecule_literal;
			}

			inline const string& get_molecule_literal() const
			{
				return molecule_literal;
			}

		private:
			string abbreviation;
			string name;
			string molecule_literal;
	};
}

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_FULL_ULTIMATE_AMINOACID_HPP_INCLUDED
