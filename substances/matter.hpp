#ifndef SCIFIR_CHEMISTRY_SUBSTANCES_MATTER_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_SUBSTANCES_MATTER_HPP_INCLUDED

#include "substance.hpp"

#include <vector>

using namespace std;

namespace scifir
{
	class matter
	{
		public:

			enum type : char {NO_MATTER, SUBSTANCE, MIXTURE, NATURAL_OBJECT, ARTIFICIAL_OBJECT, NATURAL_GENETIC_INFORMATION, ARTIFICIAL_GENETIC_INFORMATION, ORGANELLE, CELL, TISSUE, ORGAN, ANIMAL, PLANT, FUNGI, MICROORGANISM, DEVICE, ELECTRONIC_CIRCUIT, ASTRONOMICAL_OBJECT, ASTRONOMICAL_BODY};

			enum subtype : char {NO_SUBTYPE, ELEMENT, MOLECULE, ALLOY, HOMOGENEOUS_MIXTURE, HETEROGENEOUS_MIXTURE, MINERAL, ROCK, PLANET_EARTH, PLANET_SAND, PLANET_WATER, PLANET_AIR, };

			matter();

			vector<substance> substances;
			vector<matter> matters;
	};
}

#endif // SCIFIR_CHEMISTRY_SUBSTANCES_MATTER_HPP_INCLUDED
