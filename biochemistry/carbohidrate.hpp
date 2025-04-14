#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_CARBOHIDRATE_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_CARBOHIDRATE_HPP_INCLUDED

#include <iostream>
#include <string>

#include "./biomolecule.hpp"

using namespace std;

namespace scifir
{
	class carbohidrate : public biomolecule
	{
		public:
			enum type {MONOSACHARIDE, POLYSACHARIDE};
			enum common {GLUCOSE,LACTOSE,GALACTOSE,MALTOSE,SACAROSE,FRUCTOSE};

			carbohidrate();
			explicit carbohidrate(carbohidrate::type new_carbohidrate_type,const string& new_name);
			explicit carbohidrate(carbohidrate::common new_carbohidrate_species);

			carbohidrate::type carbohidrate_type;
	};

	string carbohidrate_name(carbohidrate::common x);
}

bool operator ==(const scifir::carbohidrate& x,const scifir::carbohidrate& y);
bool operator !=(const scifir::carbohidrate& x,const scifir::carbohidrate& y);

ostream& operator <<(ostream& os,const scifir::carbohidrate& x);

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_CARBOHIDRATE_HPP_INCLUDED
