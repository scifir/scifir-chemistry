#include "particles/electron.hpp"

#include <iostream>
using namespace std;

namespace scifir
{
    const mass electron::common_mass(12,"g");

    electron::electron() : spin()
    {
    }

	electron::electron(float new_spin)
	{
		if(new_spin != -0.5 and new_spin != 0.5)
		{
			cerr << "Electron bad defined, the spin has to be 0.5 or -0.5" << endl;
		}
		spin = new_spin;
	}
}
