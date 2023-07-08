#include "molecules/molecule.hpp"

using namespace std;

namespace scifir
{
	molecule::molecule()
	{
	}

	bool molecule::is_factible() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom: atoms)
		{
			/*if (!atom->is_factible())
			{
				return false;
			}*/
		}
		return true;
	}

	mass molecule::get_standard_atomic_mass() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		mass atoms_mass = 0_g;
		for (const auto& atom: atoms)
		{
			atoms_mass += atom->get_standard_atomic_mass();
		}
		return atoms_mass;
	}

	mass molecule::get_real_mass() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		mass atoms_mass = 0_g;
		for (const auto& atom: atoms)
		{
			atoms_mass += atom->get_real_mass();
		}
		return atoms_mass;
	}

	mass molecule::get_real_mass_simplified() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		mass atoms_mass = 0_g;
		for (const auto& atom: atoms)
		{
			atoms_mass += atom->get_real_mass_simplified();
		}
		return atoms_mass;
	}

	mass molecule::get_electrons_mass() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		mass atoms_mass = 0_g;
		for (const auto& atom: atoms)
		{
			atoms_mass += atom->get_electrons_mass();
		}
		return atoms_mass;
	}

	string molecule::get_name() const
	{
		return "unfinished";
	}

	string molecule::get_formula() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		ostringstream formula_text;
		return formula_text.str();
	}

	string molecule::get_canonical_formula() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		vector<shared_ptr<atom>> atoms_used = vector<shared_ptr<atom>>();
		ostringstream formula_text;
		for (const shared_ptr<atom>& atom1 : atoms)
		{
			int atom_number = 0;
			bool is_repeated = false;
			for (const shared_ptr<atom>& atom_used : atoms_used)
			{
				if (same_specimen(*atom_used,*atom1))
				{
					is_repeated = true;
				}
			}
			if (is_repeated)
			{
				continue;
			}
			for (const shared_ptr<atom>& atom2 : atoms)
			{
				if (same_specimen(*atom1,*atom2))
				{
					atom_number++;
				}
			}
			formula_text << atom1->get_symbol().c_str() << atom_number;
			atoms_used.push_back(atom1);
		}
		return formula_text.str();
	}

	int molecule::get_ionic_charge() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		int ionic_charge = 0;
		for (const auto& atom : atoms)
		{
			ionic_charge += atom->get_ionic_charge();
		}
		return ionic_charge;
	}

	bool molecule::is_ion() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom : atoms)
		{
			if (!atom->is_ion())
			{
				return false;
			}
		}
		return true;
	}

	bool molecule::is_anion() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom : atoms)
		{
			if (!atom->is_anion())
			{
				return false;
			}
		}
		return true;
	}

	bool molecule::is_cation() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom : atoms)
		{
			if (!atom->is_cation())
			{
				return false;
			}
		}
		return true;
	}

	bool molecule::is_neutral() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom : atoms)
		{
			if (!atom->is_neutral())
			{
				return false;
			}
		}
		return true;
	}

	bool molecule::has_atom(atom::specimen x) const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom: atoms)
		{
			if (atom->is_atom_specimen(x))
			{
				return true;
			}
		}
		return false;
	}

	bool molecule::has_bond(const string& x) const
	{
		vector<shared_ptr<atomic_bond>> bonds = get_bonds();
		for (const auto& bond : bonds)
		{
			if (bond->is_bond(x))
			{
				return true;
			}
		}
		return false;
	}

	bool molecule::has_bond_group(const string& x) const
	{
		return true;
	}

	bool molecule::has_functional_group(functional_group x) const
	{
		if (x == functional_group::carbonyl)
		{
			return has_bond("C=0");
		}
	}

	bool molecule::is_cyclical() const
    {
		return true;
    }

    bool molecule::is_acyclical() const
    {
		return true;
    }

    bool molecule::is_polar() const
    {
		return true;
    }

    bool molecule::is_apolar() const
	{
		return true;
	}

	bool molecule::is_chiral() const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom: atoms)
		{
			if (atom->is_chiral())
			{
				return true;
			}
		}
		return false;
	}

    bool molecule::is_achiral() const
    {
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom: atoms)
		{
			if (atom->is_achiral())
			{
				return true;
			}
		}
		return false;
    }

    bool molecule::is_protic() const
    {
    	return (has_bond("O-H") or has_bond("N-H"));
    }

    bool molecule::is_aprotic() const
    {
		return !is_protic();
    }

    int molecule::number_of_chiral_atoms() const
    {
    	vector<shared_ptr<atom>> atoms = get_atoms();
    	int i = 0;
		for (const auto& atom: atoms)
		{
			if (atom->is_chiral())
			{
				i++;
			}
		}
		return i;
    }

    int molecule::number_of_enantiomers() const
    {
		return 2^number_of_chiral_atoms();
    }

    /*void molecule::get_image_3d() const
    {

    }*/

    void molecule::print_image_3d() const
    {

    }

	tuple<shared_ptr<atom>,scifir::point_3d<>> molecule::get_image_3d_calculate_atom_position(shared_ptr<atom> new_atom,tuple<shared_ptr<atom>,scifir::point_3d<>> previous_atom,tuple<shared_ptr<atom>,scifir::point_3d<>> previous_atom2) const
    {
		// Calculate the position based on the geometry of the previous_atom, each geometry gives a different position to calculate of, based on the angle of the two bonds (the new and the previous one)
		vector<weak_ptr<atomic_bond>> bonds = new_atom->get_bonds();
		for (const auto& bond : bonds)
		{
			//tuple<shared_ptr<atom>,scifir::point_3d<>> get_image_3d_calculate_atom_position();
		}
    }

    void molecule::get_atoms_image_3d(vector<tuple<shared_ptr<atom>,scifir::point_3d<>>> atom_positions) const
	{
		vector<shared_ptr<atom>> atoms = get_atoms();
		for (const auto& atom : atoms)
		{
			// get atom 3d image calling atom.get_image_3d() or similar
			// use the vector<scifir::point_3d> to position the image related to the full image
		}
	}

	/*void molecule::get_unpaired_electrons_image_3d(vector<tuple<scifir::point_3d,math_vector>> electron_positions) const
	{
		// the math_vector is for directions
	}*/

	void molecule::get_bonds_image_3d(vector<tuple<shared_ptr<atom>,scifir::point_3d<>>> atom_positions) const
	{
		vector<shared_ptr<atomic_bond>> bonds = get_bonds();
		for (const auto& bond: bonds)
		{
			// get atomic bond 3d image by creating a cillinder and connecting it between the two centers of the atoms
		}
	}

	string generate_hash(const molecule& x)
	{
		return "123" + std::to_string(x.get_total_atoms());
	}
}
