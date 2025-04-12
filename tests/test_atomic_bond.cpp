#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

#include "../molecules/atomic_bond.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

TEST_CASE("atomic_bond class","Full test of atomic_bond class") {
	//scifir::atom a = scifir::atom(scifir::atom::H);
	cout << "size weak: "<< sizeof(weak_ptr<scifir::atom>) << endl;
	cout << "size shared: "<< sizeof(shared_ptr<scifir::atom>) << endl;
}
