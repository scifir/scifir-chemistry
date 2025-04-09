#ifndef SCIFIR_CHEMISTRY_SUBSTANCES_SHAPE_SUBSTANCE_CONSTITUENT_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_SUBSTANCES_SHAPE_SUBSTANCE_CONSTITUENT_HPP_INCLUDED

#include "molecules/molecule.hpp"

#include "scifir/units.hpp"

using namespace std;

namespace scifir
{
	class shape_substance_constituent
	{
		public:
			shape_substance_constituent();
			shape_substance_constituent(const shape_substance_constituent&);
			shape_substance_constituent(shape_substance_constituent&&);

			shape_substance_constituent& operator=(const shape_substance_constituent&);
			shape_substance_constituent& operator=(shape_substance_constituent&&);

			scifir::molecule molecule;
			scifir::mole amount;
			vector<point_3d<>> positions;
	};
}

#endif // SCIFIR_CHEMISTRY_SUBSTANCES_SHAPE_SUBSTANCE_CONSTITUENT_HPP_INCLUDED

