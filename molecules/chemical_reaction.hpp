#ifndef SICIF_CHEMISTRY_MOLECULES_CHEMICAL_REACTION_HPP_INCLUDED
#define SICIF_CHEMISTRY_MOLECULES_CHEMICAL_REACTION_HPP_INCLUDED

#include "../atoms/atom.hpp"
#include "./molecule.hpp"

#include "scifir/units.hpp"
#include "boost/variant.hpp"

using namespace std;

namespace scifir
{
	class chemical_reaction
	{
		public:
			chemical_reaction();

			inline const vector<boost::variant<shared_ptr<molecule>,shared_ptr<atom>>>& get_reactants() const
			{
				return reactants;
			}

			inline const vector<boost::variant<shared_ptr<molecule>,shared_ptr<atom>>>& get_products() const
			{
				return products;
			}

			scifir::energy get_enthalpy_change() const;
			scifir::entropy get_entropy_change() const;

		private:
			vector<boost::variant<shared_ptr<molecule>,shared_ptr<atom>>> reactants;
			vector<boost::variant<shared_ptr<molecule>,shared_ptr<atom>>> products;
	};
}

#endif // SICIF_CHEMISTRY_MOLECULES_CHEMICAL_REACTION_HPP_INCLUDED
