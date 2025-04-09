#include "./normal_molecule.hpp"
#include "../atoms/atom.hpp"

#include "boost/algorithm/string.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace scifir
{
	normal_molecule::normal_molecule() : molecule(),atoms(),bonds()
	{
	}

	normal_molecule::normal_molecule(string new_file) : molecule(),atoms(),bonds()
	{
		/*xml_document<> doc;
		if (new_file.substr(0,10) == "<molecule>")
		{
			string cstr;
			doc.parse<0>(&new_file[0]);
		}
		else
		{
			ifstream theFile (new_file);
			stringstream buffer;
			buffer << theFile.rdbuf();
			theFile.close();
			string file_content (buffer.str());
			vector<char> file_content_vector (file_content.begin(),file_content.end());
			file_content_vector.push_back('\0');
			doc.parse<0>(&file_content_vector[0]);
		}
		xml_node<> * root_node;
		root_node = doc.first_node("molecule");
		xml_node<> * atoms_node = root_node->first_node("atoms");
		vector<string> file_atoms = vector<string>();
		string atoms_content = atoms_node->value();
		boost::split(file_atoms,atoms_content,boost::is_any_of(" "));
		for (const string& atom_symbol : file_atoms)
		{
			atoms.push_back(make_shared<atom>(atom_symbol));
		}
		xml_node<> * bonds_node = root_node->first_node("bonds");
		vector<string> file_bonds = vector<string>();
		string bonds_content = bonds_node->value();
		boost::split(file_bonds,bonds_content,boost::is_any_of(";"));
		unsigned int atom1_index = 0;
		for (const string& bond_list : file_bonds)
		{
			vector<string> file_atom_bonds = vector<string>();
			boost::split(file_atom_bonds,bond_list,boost::is_any_of(" "));
			for (const string& atom2 : file_atom_bonds)
			{
				unsigned int atom2_index;
				atomic_bond_weight weight;
				size_t is_double_bond = atom2.find("d");
				if (is_double_bond != std::string::npos)
				{
					weight = atomic_bond_weight::dual;
					atom2_index = stoi(atom2.substr(0,1)) - 1;
				}
				else
				{
					size_t is_triple_bond = atom2.find("t");
					if (is_triple_bond != std::string::npos)
					{
						weight = atomic_bond_weight::triple;
						atom2_index = stoi(atom2.substr(0,1)) - 1;
					}
					else
					{
						weight = atomic_bond_weight::single;
						atom2_index = stoi(atom2) - 1;
					}
				}
				/*if (!atoms[atom1_index]->bonded_to(*atoms[atom2_index]))
				{
					shared_ptr<atomic_bond> new_atomic_bond = make_shared<atomic_bond>(atoms[atom1_index],atoms[atom2_index],weight);
					bonds.push_back(new_atomic_bond);
					atoms[atom1_index]->add_bond(new_atomic_bond);
					atoms[atom2_index]->add_bond(new_atomic_bond);
				}*/
				/*atom2_index++;
			}
			atom1_index++;
		}*/
	}

	normal_molecule::normal_molecule(vector<shared_ptr<atom>> new_atoms,vector<shared_ptr<atomic_bond>> new_bonds) : molecule(),atoms(new_atoms),bonds(new_bonds)
	{
	}
}
