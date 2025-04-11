#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_CARBOHIDRATE_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_CARBOHIDRATE_HPP_INCLUDED

#include "./carbohidrate.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace scifir
{
	enum class carbohidrate_type {GLUCOSE,LACTOSE,GALACTOSE,MALTOSE,SACAROSE,FRUCTOSE};

	class carbohidrate
	{
		public:
			carbohidrate();
			carbohidrate(carbohidrate_type);

			inline carbohidrate_type& get_type()
			{
				return type;
			}

			inline const carbohidrate_type& get_type() const
			{
				return type;
			}

		private:
			carbohidrate_type type;
	};

	string carbohidrate_name(carbohidrate_type);
}

bool operator ==(const scifir::carbohidrate&,const scifir::carbohidrate&);
bool operator !=(const scifir::carbohidrate&,const scifir::carbohidrate&);

ostream& operator <<(ostream&,const scifir::carbohidrate&);

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_CARBOHIDRATE_HPP_INCLUDED
