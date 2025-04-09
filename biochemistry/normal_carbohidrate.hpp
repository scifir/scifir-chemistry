#ifndef SCIFIR_CHEMISTRY_BIOCHEMISTRY_NORMAL_CARBOHIDRATE_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_BIOCHEMISTRY_NORMAL_CARBOHIDRATE_HPP_INCLUDED

#include "./carbohidrate.hpp"

#include <iostream>
#include <string>

using namespace std;

namespace scifir
{
	enum class carbohidrate_type {glucose,lactose,galactose,maltose,sacarose,fructose};

	class normal_carbohidrate : public carbohidrate
	{
		public:
			normal_carbohidrate();
			normal_carbohidrate(carbohidrate_type);

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

bool operator ==(const scifir::normal_carbohidrate&,const scifir::normal_carbohidrate&);
bool operator !=(const scifir::normal_carbohidrate&,const scifir::normal_carbohidrate&);

ostream& operator <<(ostream&,const scifir::normal_carbohidrate&);

#endif // SCIFIR_CHEMISTRY_BIOCHEMISTRY_NORMAL_CARBOHIDRATE_HPP_INCLUDED
