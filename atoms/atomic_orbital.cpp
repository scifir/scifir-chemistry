#include "./atomic_orbital.hpp"

#include <sstream>
#include <vector>

using namespace std;

namespace scifir
{
	orbital::orbital() : orbital_specie(orbital::s),electrons(0),period(0)
	{}

	orbital::orbital(const orbital& x) : orbital_specie(x.orbital_specie),electrons(x.electrons),period(x.period)
	{}

	orbital::orbital(orbital&& x) : orbital_specie(std::move(x.orbital_specie)),electrons(std::move(x.electrons)),period(std::move(x.period))
	{}

	orbital::orbital(int new_period, orbital::type new_orbital_specie, int electron_number)
	{
		orbital_specie = new_orbital_specie;
		period = new_period;
		electrons = vector<scifir::electron>();
		if(electron_number >= 1)
		{
			scifir::electron electron1 = scifir::electron(-0.5);
			electrons.push_back(electron1);
			if(electron_number == 2)
			{
				scifir::electron electron2 = scifir::electron(0.5);
				electrons.push_back(electron2);
			}
		}
	}

	orbital& orbital::operator =(const orbital& x)
	{
		orbital_specie = x.orbital_specie;
		electrons = x.electrons;
		period = x.period;
		return *this;
	}

	orbital& orbital::operator =(orbital&& x)
	{
		orbital_specie = std::move(x.orbital_specie);
		electrons = std::move(x.electrons);
		period = std::move(x.period);
		return *this;
	}

	orbital_group::orbital_group(orbital::type new_orbital_specie)
	{
		orbitals = vector<orbital>();
		orbital_specie = new_orbital_specie;
		switch(orbital_specie)
		{
			case orbital::s:
				orbital_max = 1;
				break;
			case orbital::p:
				orbital_max = 3;
				break;
			case orbital::d:
				orbital_max = 5;
				break;
			case orbital::f:
				orbital_max = 7;
				break;
		}
	}

	void orbital_group::add(orbital new_orbital)
	{
		orbitals.push_back(new_orbital);
	}

	vector<orbital>::size_type orbital_group::total_orbitals()
	{
		return orbitals.size();
	}

	bool orbital_group::is_full()
	{
		if(orbital_specie == orbital::s and total_orbitals() == orbital_max)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int orbital_group::period()
	{
		return orbitals[0].period;
	}

	int orbital_group::total_electrons()
	{
		int total_electrons = 0;
		for(auto& orbital : orbitals)
		{
			total_electrons += int(orbital.electrons.size());
		}
		return total_electrons;
	}

	string orbital_group::display_orbitals()
	{
		ostringstream output;
		for(auto& orbital : orbitals)
		{
			output << orbital;
		}
		return output.str();
	}

	orbital orbital_group::operator [](int number)
	{
		return orbitals[number];
	}

	string to_string(orbital::type x)
	{
		if (x == orbital::s)
		{
			return "s";
		}
		else if (x == orbital::p)
		{
			return "p";
		}
		else if (x == orbital::d)
		{
			return "d";
		}
		else if (x == orbital::f)
		{
			return "f";
		}
		return "";
	}
}

ostream& operator <<(ostream& os, const scifir::orbital& orbital)
{
	ostringstream output;
	output << orbital.period << to_string(orbital.orbital_specie) << orbital.electrons.size();
	return os << output.str();
}

ostream& operator <<(ostream& os, scifir::orbital_group orbital_group)
{
	ostringstream output;
	output << orbital_group.period() /*<< orbital_group.name()*/ << orbital_group.total_electrons();
	return os << output.str();
}
