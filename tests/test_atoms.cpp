#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

#include "../atoms/atom.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace scifir;

TEST_CASE("atom class","Full test of atom class") {
	SECTION("atom class constructors")
	{
		scifir::atom a(atom::He);
	}
}

