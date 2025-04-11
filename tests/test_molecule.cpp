#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

#include "../molecules/molecule.hpp"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using namespace scifir;

TEST_CASE("molecule class","Full test of molecule class") {
	SECTION("molecule class constructors")
	{
		/*scifir::molecule a(vector<atom>{ atom(atom::C),atom(atom::H),atom(atom::H),atom(atom::H),atom(atom::H) },vector<atomic_bond_builder>{atomic_bond_builder(0,1),atomic_bond_builder(0,2),atomic_bond_builder(0,3),atomic_bond_builder(0,4)});*/
	}
}
