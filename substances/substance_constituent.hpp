#ifndef SCIFIR_CHEMISTRY_SUBSTANCES_SUBSTANCE_CONSTITUENT_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_SUBSTANCES_SUBSTANCE_CONSTITUENT_HPP_INCLUDED

#include "../molecules/molecule.hpp"

#include "scifir/units.hpp"

using namespace std;

namespace scifir
{
	class substance_constituent
	{
		public:
			substance_constituent();
			substance_constituent(const substance_constituent&);
			substance_constituent(substance_constituent&&);

			substance_constituent& operator=(const substance_constituent&);
			substance_constituent& operator=(substance_constituent&&);

			scifir::molecule molecule;
			scifir::mole amount;
	};
}

#endif // SCIFIR_CHEMISTRY_SUBSTANCES_SUBSTANCE_CONSTITUENT_HPP_INCLUDED
