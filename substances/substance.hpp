#ifndef SCIFIR_CHEMISTRY_SUBSTANCES_SUBSTANCE_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_SUBSTANCES_SUBSTANCE_HPP_INCLUDED

#include "./substance_constituent.hpp"
#include "../molecules/molecule.hpp"

#include "scifir/units.hpp"

#include <vector>

using namespace std;

namespace scifir
{
	class substance
	{
		public:
			substance();
			substance(const substance&);
			substance(substance&&);

			substance& operator=(const substance&);
			substance& operator=(substance&&);

			bool is_element() const;
			bool is_compound() const;
			bool is_alloy() const;

			mass get_mass() const;

			vector<substance_constituent> constituents;
	};
}

#endif // SCIFIR_CHEMISTRY_SUBSTANCES_SUBSTANCE_HPP_INCLUDED
