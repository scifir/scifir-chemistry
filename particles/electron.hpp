#ifndef ELECTRON_HPP_INCLUDED
#define ELECTRON_HPP_INCLUDED

#include "scifir/units/units.hpp"

namespace scifir
{
	class electron
	{
		public:
			electron();
			electron(float);

			float spin;

			static const mass common_mass;
	};
}

#endif // ELECTRON_HPP_INCLUDED
