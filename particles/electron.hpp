#ifndef SCIFIR_CHEMISTRY_PARTICLES_ELECTRON_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_PARTICLES_ELECTRON_HPP_INCLUDED

#include "scifir/units.hpp"

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

#endif // SCIFIR_CHEMISTRY_PARTICLES_ELECTRON_HPP_INCLUDED
