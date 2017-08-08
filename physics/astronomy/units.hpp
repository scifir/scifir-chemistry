#ifndef PHYSICS_ASTRONOMY_UNITS_HPP_INCLUDED
#define PHYSICS_ASTRONOMY_UNITS_HPP_INCLUDED

#include "physics/basic/units/unit.hpp"
#include "physics/basic/units/scalar_unit.hpp"
#include "physics/basic/units/vector_unit.hpp"

using namespace std;

namespace physics::units
{
	class specific_angular_momentum : public vector_unit_crtp<specific_angular_momentum>
	{
		public:
			using vector_unit_crtp::vector_unit_crtp;

			static const string dimensions_match;
	};
}

#endif // PHYSICS_ASTRONOMY_UNITS_HPP_INCLUDED
