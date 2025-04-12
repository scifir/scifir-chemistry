#ifndef SCIFIR_CHEMISTRY_ATOMS_ATOMIC_ORBITAL_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_ATOMS_ATOMIC_ORBITAL_HPP_INCLUDED

#include <string>
#include <vector>

#include "../particles/electron.hpp"

using namespace std;

namespace scifir
{
	class orbital
	{
		public:
			enum type {s,p,d,f};

			orbital();
			orbital(const orbital& x);
			orbital(orbital&& x);
			explicit orbital(int new_period, orbital::type new_orbital_specie, int electron_number);

			orbital& operator =(const orbital& x);
			orbital& operator =(orbital&& x);

			orbital::type orbital_specie;
			vector<scifir::electron> electrons;
			int period;
	};

	class orbital_group
	{
		public:
			vector<orbital> orbitals;
			orbital::type orbital_specie;
			unsigned int orbital_max;

			orbital_group(orbital::type);
			void add(orbital);
			vector<orbital>::size_type total_orbitals();
			bool is_full();
			string name();
			int period();
			int total_electrons();
			string display_orbitals();

			orbital operator [](int);
	};

	string to_string(orbital::type x);
}

ostream& operator <<(ostream&, const scifir::orbital&);
ostream& operator <<(ostream&, scifir::orbital_group);

#endif // SCIFIR_CHEMISTRY_ATOMS_ATOMIC_ORBITAL_HPP_INCLUDED
