#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_LIPID_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_LIPID_HPP_INCLUDED

#include <string>

#include "./biomolecule.hpp"

using namespace std;

namespace scifir
{
	class lipid : public biomolecule
	{
		public:
			enum type { FATTY_ACID, TRIACYLGLYCEROL, GLYCEROPHOSPHOLIPID, SPHINGOLIPID, CHOLESTEROL };

			lipid();
			explicit lipid(const string& new_name, lipid::type new_type);

			string get_systematic_name() const;

			lipid::type lipid_type;
	};
}

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_LIPID_HPP_INCLUDED
