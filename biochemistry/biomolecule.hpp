#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_BIOMOLECULE_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_BIOMOLECULE_HPP_INCLUDED

#include <string>

using namespace std;

namespace scifir
{
	class biomolecule
	{
		public:
			enum type {AMINOACID, PROTEIN, CARBOHIDRATE, LIPID};

			string name;
		
			protected:
			biomolecule();
			explicit biomolecule(biomolecule::type);
			explicit biomolecule(biomolecule::type,const string& new_name);

			inline const biomolecule::type& get_biomolecule_type() const
			{
				return biomolecule_type;
			}

		private:
			biomolecule::type biomolecule_type;
	};

	string biomolecule_type_name(biomolecule::type);
}

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_BIOMOLECULE_HPP_INCLUDED
