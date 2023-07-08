#ifndef SCIFIR_CHEMISTRY_MOLECULES_NORMAL_MOLECULE_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_MOLECULES_NORMAL_MOLECULE_HPP_INCLUDED

#include <memory>
#include <string>
#include <vector>

#include "molecules/molecule.hpp"

using namespace std;

namespace scifir
{
	class normal_molecule : public molecule
	{
		public:
			normal_molecule();
			normal_molecule(string);
			normal_molecule(vector<shared_ptr<atom>>,vector<shared_ptr<atomic_bond>>);

			virtual vector<shared_ptr<atom>> get_atoms() const;
			virtual vector<shared_ptr<atomic_bond>> get_bonds() const;
			virtual int get_total_atoms() const;

			virtual void add_atom(const atom&);

			virtual void save(const string&,const string&) const;

		private:
			vector<shared_ptr<atom>> atoms;
			vector<shared_ptr<atomic_bond>> bonds;
	};
}

#endif // SCIFIR_CHEMISTRY_MOLECULES_NORMAL_MOLECULE_HPP_INCLUDED
