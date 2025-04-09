# TODO - scifir-chemistry

## CURRENT (1)

- TODO: if it's correct to use get_name() and get_abbreviation() with override for the ultimate_aminoacid class cause that can maybe increase the size of each instance

## IMPORTANT (1)

- TODO: use molecule_literal where it's needed instead of another name for the respective variable

## C++ (2)

- TODO: the include path of the library should point previous to the root of the project maybe (in order to include it always by its full name)
- TODO: molecule.cpp: rapidxml shouldn't be aliased as namespace (maybe other files too)

## SCIFIR MOLECULES VISUALIZER (2)

- TODO: .mm file extension (abbreviation of Mscience Molecule)
- TODO: support proteins (check if possible for all proteins first)

## SCIFIR CHEMISTRY CREATOR (1)

- TODO: Chemistry Creator program for creating molecules with .mm extension

## ATOMS (25)

- TODO: solve the type of atomic_bond by setting it as member-variable

- TODO: 3D graphical functions: get_image_3d(),get_molecular_geometry_angle(const atom&) finish two angles
- TODO: atom::get_molecular_geometry_angle() needs good the square_antipristamic and tricapped_trigonal_prismatic values
- TODO: 2D graphical functions: get_image_2d(),get_detailed_image_2d()
- TODO: finish atom::get_atomic_color() using an enum for all colors
- TODO: review all electrical classes, atom::get_lone_pairs() among others
- TODO: finish normal_atom::get_electronic_configuration()
- TODO: finish create_species(const string&). Place it inside a constructor instead of there

- TODO: atomic_bond should have a child class for the atomic bonds that are not geometrically identical but have different angles based on the position

- TODO: create the first isotope class
- TODO: create all common isotopes of chemistry
- TODO: create_atom() should detect ions and isotopes (and more of the nomenclature, if it exists)

- TODO: change atom::group to enum class atomic_group
- TODO: class atomic_group (use instead of a class some name() and other functions for atom::group)
- TODO: function atom::is_chiral()
- TODO: is_factible(), is_valence_full(), get_valence_number() should work for atomic_group_b(), lanthanides and actinides
- TODO: finish some properties of some atoms (like radioactive)
- TODO: create triple_point and melting_point (maybe point classes)

- TODO: ionic_charge() maybe should have non-bonded and bonded form
- TODO: get_electrons_number() maybe is unfinished
- TODO: get_file_format() should be outside atom

- TODO: what's speed of sound of atoms
- TODO: what's half-life and unit to represent it
- TODO: ordering for atoms

- TODO: get_standard_atomic_weight() and get_atomic_weight() in order to allow to get the mass of a mol

## DETAILED ATOMS (3)

- TODO: finish detailed atoms
- TODO: finish electron_cloud object
- TODO: electron cloud functions: get_electron_cloud(),print_electron_cloud()

## AFTER NEW ATOMS (5)

- TODO: print_image_2d(),print_image_3d(),get_image_2d(),get_detailed_image_2d(),get_image_3d()
- TODO: use a better criteria than the atomic number to determine radioactivity
- TODO: finish is_factible() function
- TODO: get_ionic_charge() for metals
- TODO: is_exotic()

## DOCUMENTATION OF ATOMS (4)

- TODO: document that is_atom_specimen() is always used instead of get_z() or get_symbol() to test for the specimen, cause for isotopes the string symbol can change
- TODO: document the nomenclature of the cas number
- TODO: document that the unfinished atoms doesn't have their values actually calculated. Document which values and atoms aren't completed
- TODO: document that normal_atom template-class isn't an abstract class because it's not intended to be used directly

## MOLECULES (19)

- TODO: implement the bond_length inside atomic_bond class
- TODO: 3D display
- TODO: 2D display of molecules by printing inside 2D a 3D molecule
- TODO: handlind of molecule_literals (valid_molecule_literal-with error messages)
- TODO: molecule::has_functional_group(functional_group)
- TODO: molecule::get_dipole()
- TODO: molecule::is_polar() and molecule::is_apolar()
- TODO: are_isomers(), are_conformational_isomers(), are_enantiomers()
- TODO: are_miscible(), are_inmiscible()
- TODO: molecule::is_cyclical() and molecule::is_acyclical()
- TODO: is_eter(), and all the others of those functions
- TODO: molecule::get_formula(),molecule::print(),operator << of molecule
- TODO: operator == and operator != of molecule
- TODO: ether, carboxilic_acid, and all the other molecule subclasses of normal_molecule in order to have the same clarity as with units length, mass, etc.
- TODO: normal_molecule.cpp: rapidxml shouldn't be aliased as namespace
- TODO: normal_molecule.cpp: see which is the best method to travel rapidxml, if to use file<> of rapidxml of if to use the actual fstream
- TODO: ordering for molecules
- TODO: .msm should have \<atom\> with nick attribute to abbreviate special atoms
- TODO: see which functions of molecule change now that bit_molecule is being used and add those functions to normal_molecule, being the ones of molecule class pure-virtual

## BIOCHEMISTRY (5)

- TODO: find out if the better way to store new ultimate aminoacids is with the global variable map or if it's better another approach
- TODO: global carbohidrates pointing to the molecule object
- TODO: protein class, with special format to store and load it
- TODO: molecule::is_biochemical()
- TODO: Store the proteins only one time, and to calculate a lot of them use that unique instead for the data purpose. For movement modeling, with one instance is enough, and use position coordinates and rotation coordinates to store the data of each protein

## MATTER (1)

- TODO: extended_matter class, or some similar class, that handles things that aren't matter, like light, waves, and some massless particles

## DATA (1)

- TODO: find more exact values of the ionization energies of deuterium and tritium, and their covalent radius, van der waals radius

## REGEX OF MOLECULE NAMES (11)

//(((([0-9]+-)|([0-9]+,[0-9]+-di))((meth)|(eth)|(prop)|(but)|(pent)|(hex)|(hept)|(oct)|(non)|(dec))yl-)*((([0-9]+-)|([0-9]+,[0-9]+-di))((meth)|(eth)|(prop)|(but)|(pent)|(hex)|(hept)|(oct)|(non)|(dec))yl)|((([0-9]+-)|([0-9]+,[0-9]+-di))((meth)|(eth)|(prop)|(but)|(pent)|(hex)|(hept)|(oct)|(non)|(dec))yl)?)((meth)|(eth)|(prop)|(but)|(pent)|(hex)|(hept)|(oct)|(non)|(dec))((ane)|(anol))
// prefixes of names: (([0-9]+-)|([0-9]+,[0-9]+-di))
// radical names: ((meth)|(eth)|(prop)|(but)|(pent)|(hex)|(hept)|(oct)|(non)|(dec))
// compound type: ((ane)|(anol))
// regex structure: (${radical_regex_with_hyphen}*${radical_regex}|${radical_regex}?)${radical_names}${compound_types}
// add the conformations: \(((E)|(Z))\)

- TODO: search all the basic IUPAC rules
- TODO: search the general document of IUPAC that doesn't includes something more
- TODO: search if they're libraries that handle IUPAC names
- TODO: function for veryfing the name (the basic one)
- TODO: function for generating the prefix based on a number
- TODO: function for generating the prefix of the form n,...,n-\<prefix\>
- TODO: function for generating the radical based on a number
- TODO: support the n- names of compound type
- TODO: array (or function) of compound types
- TODO: support the translation
- TODO: use regex replacement inside the constructor of molecules to get the data to create the molecule (if possible with bool)

## CHEMICAL REACTIONS (3)

- TODO: Finish basic member-functions of the class
- TODO: Reaction is_safe() member-function, related to T change, entropy change, etc.
- TODO: Add all toxicology knowledge inside chemical_reaction and molecule, in order to know if a reaction is safe or not

## UNFINISHED ATOMS (2)

- TODO: Nh (atoms_iiia.hpp), Fl (atoms_iva.hpp), Mc (atoms_va.hpp), Lv (atoms_via.hpp), At y Ts (atoms_viia.hpp), He and the other noble gases (atoms_viiia.hpp), Y (atoms_iiib.hpp), all ivb (atoms_ivb.hpp), all vb (atoms_vb.hpp), all vib (atoms_vib.hpp),
- TODO: Mn doesn´t documents  covalent radius dual spin

## FUTURE (1)

- TODO: bit_molecule class maybe has sense for some cases
