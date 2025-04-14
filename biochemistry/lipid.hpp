#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_LIPID_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_LIPID_HPP_INCLUDED

#include <string>

using namespace std;

namespace scifir
{
	class lipid
	{
		public:
			enum type { FATTY_ACID, TRIACYLGLYCEROL, GLYCEROPHOSPHOLIPID, SPHINGOLIPID, CHOLESTEROL };

			lipid();
			explicit lipid(lipid::type new_type);

			string get_systematic_name() const;

			string name;

		private:
			lipid::type lipid_type;
	};
}

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_LIPID_HPP_INCLUDED
