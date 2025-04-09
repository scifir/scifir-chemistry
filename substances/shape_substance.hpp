#ifndef SCIFIR_CHEMISTRY_SUBSTANCES_SHAPE_SUBSTANCE_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_SUBSTANCES_SHAPE_SUBSTANCE_HPP_INCLUDED

#include "matter.hpp"
#include "shape_substance_constituent.hpp"

#include "scifir/units.hpp"

#include <vector>

using namespace std;

namespace scifir
{
	class shape_substance
	{
		public:
			shape_substance();
			shape_substance(const shape_substance&);
			shape_substance(shape_substance&&);

			shape_substance& operator=(const shape_substance&);
			shape_substance& operator=(shape_substance&&);

			bool is_element() const;
			bool is_compound() const;
			bool is_alloy() const;

			mass get_mass() const;

			vector<shape_substance_constituent> constituents;
			//figure_3d shape;
	};
}

#endif // SCIFIR_CHEMISTRY_SUBSTANCES_SHAPE_SUBSTANCE_HPP_INCLUDED

