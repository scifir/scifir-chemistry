#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_BIOMOLECULE_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_BIOMOLECULE_HPP_INCLUDED

#include <string>

using namespace std;

namespace scifir
{
	enum class biomolecule_type {protein,lipid,carbohidrate};

	class biomolecule
	{
		public:
			biomolecule();
			biomolecule(biomolecule_type);

			inline biomolecule_type& get_biomolecule_type()
			{
				return bio_type;
			}

			inline const biomolecule_type& get_biomolecule_type() const
			{
				return bio_type;
			}

		private:
			biomolecule_type bio_type;
	};

	string biomolecule_type_name(biomolecule_type);
}

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_BIOMOLECULE_HPP_INCLUDED
