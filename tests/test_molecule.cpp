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
		scifir::molecule a({ atom(atom::C),atom(atom::H),atom(atom::H),atom(atom::H),atom(atom::H) },{atomic_bond_builder(0,1),atomic_bond_builder(0,2),atomic_bond_builder(0,3),atomic_bond_builder(0,4)});
		CHECK(a.get_canonical_formula() == "CH4");
		scifir::molecule b({ atom::C,atom::H,atom::H,atom::H,atom::H },{ {0,1},{0,2},{0,3},{0,4} });
		CHECK(a.get_canonical_formula() == "CH4");
	}
}
