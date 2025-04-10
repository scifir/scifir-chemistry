#ifndef SCIFIR_CHEMISTRY_ATOMS_ATOMIC_ORBITAL_HPP_INCLUDED
#define SCIFIR_CHEMISTRY_ATOMS_ATOMIC_ORBITAL_HPP_INCLUDED

#include "../particles/electron.hpp"

#include <string>
#include <vector>

using namespace std;

namespace scifir
{
	enum class orbital_symbol {s, p, d, f};

	class orbital
	{
		public:
			enum type {s,p,d,f};

			orbital(orbital_symbol, int, int);

			orbital_symbol orbital_specie;
			string name;
			vector<scifir::electron> electrons;
			int period;
	};

	class orbital_s : public orbital
	{
		public:
			orbital_s(int, int);
	};

	class orbital_p : public orbital
	{
		public:
			orbital_p(int, int);
	};

	class orbital_d : public orbital
	{
		public:
			orbital_d(int, int);
	};

	class orbital_f : public orbital
	{
		public:
			orbital_f(int, int);
	};

	orbital create_orbital(orbital_symbol, int, int);

	class orbital_group
	{
		public:
			vector<orbital> orbitals;
			orbital_symbol orbital_specie;
			unsigned int orbital_max;

			orbital_group(orbital_symbol);
			void add(orbital);
			vector<orbital>::size_type total_orbitals();
			bool is_full();
			string name();
			int period();
			int total_electrons();
			string display_orbitals();

			orbital operator [](int);
	};
}

ostream& operator <<(ostream&, const scifir::orbital&);
ostream& operator <<(ostream&, scifir::orbital_group);

#endif // SCIFIR_CHEMISTRY_ATOMS_ATOMIC_ORBITAL_HPP_INCLUDED
