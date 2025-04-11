# TO-DO - scifir-chemistry

- **Number of TO-DOs:** 55

## CURRENT (1)

- TODO: if it's correct to use get_name() and get_abbreviation() with override for the ultimate_aminoacid class cause that can maybe increase the size of each instance

## IMPORTANT (1)

- TODO: use molecule_literal where it's needed instead of another name for the respective variable

## ATOMS (16)

- TODO: atom::get_molecular_geometry_angle() needs good the square_antipristamic and tricapped_trigonal_prismatic values
- TODO: finish atom::get_atomic_color() using an enum for all colors
- TODO: review all electrical classes, atom::get_lone_pairs() among others
- TODO: finish atom::get_electronic_configuration()

- TODO: constructor atom(const string&) should detect ions and isotopes (and more of the nomenclature, if it exists)

- TODO: class atomic_group (use instead of a class some name() and other functions for atom::group)
- TODO: function atom::is_chiral()
- TODO: is_factible(), is_valence_full(), get_valence_number() should work for atomic_group_b(), lanthanides and actinides
- TODO: finish some properties of some atoms (like radioactive)

- TODO: ionic_charge() maybe should have non-bonded and bonded form

- TODO: what's speed of sound of atoms
- TODO: what's half-life and unit to represent it
- TODO: ordering for atoms

- TODO: get_standard_atomic_weight() and get_atomic_weight() in order to allow to get the mass of a mol

- TODO: add sqlite to save and get data of atoms and molecules
- TODO: create triple_point and melting_point (maybe point classes)

## AFTER NEW ATOMS (5)

- TODO: use a better criteria than the atomic number to determine radioactivity
- TODO: finish is_factible() function
- TODO: get_ionic_charge() for metals
- TODO: create all common isotopes of chemistry
- TODO: exotic atoms

## DOCUMENTATION OF ATOMS (4)

- TODO: document that is_atom_specimen() is always used instead of get_z() or get_symbol() to test for the specimen, cause for isotopes the string symbol can change
- TODO: document the nomenclature of the cas number
- TODO: document that the unfinished atoms doesn't have their values actually calculated. Document which values and atoms aren't completed
- TODO: document that normal_atom template-class isn't an abstract class because it's not intended to be used directly

## MOLECULES (15)

- TODO: atomic_bond should have a child class for the atomic bonds that are not geometrically identical but have different angles based on the position
- TODO: implement the bond_length inside atomic_bond class
- TODO: handling of molecule_literals (valid_molecule_literal-with error messages)
- TODO: molecule::has_functional_group(functional_group)
- TODO: molecule::get_dipole()
- TODO: molecule::is_polar() and molecule::is_apolar()
- TODO: are_isomers(), are_conformational_isomers(), are_enantiomers()
- TODO: are_miscible(), are_inmiscible()
- TODO: molecule::is_cyclical() and molecule::is_acyclical()
- TODO: is_ether(), and all the others of those functions
- TODO: molecule::get_formula(),operator << of molecule
- TODO: operator == and operator != of molecule
- TODO: ether, carboxilic_acid, and all the other molecule subclasses of normal_molecule in order to have the same clarity as with units length, mass, etc.
- TODO: ordering for molecules
- TODO: .msm should have \<atom\> with nick attribute to abbreviate special atoms

## BIOCHEMISTRY (5)

- TODO: global carbohidrates pointing to the molecule object
- TODO: protein class, with special format to store and load it
- TODO: molecule::is_biochemical()
- TODO: Store the proteins only one time, and to calculate a lot of them use that unique instead for the data purpose. For movement modeling, with one instance is enough, and use position coordinates and rotation coordinates to store the data of each protein
- TODO: add abbreviation of one letter to aminoacids

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
- TODO: Mn doesn´t documents covalent radius dual spin

## FUTURE (2)

- TODO: bit_molecule class maybe has sense for some cases
- TODO: maybe the spectrometer and/or the crystallographer can need some generic class that should be inside scifir-chemistry

## FUTURE - BIOCHEMISTRY (1)

- TODO: find out if the better way to store new extended aminoacids is with the global variable map or if it's better another approach

## FUTURE - GRAPHICS (4)

- TODO: for atom class: print_image_2d(),print_image_3d(),get_image_2d(),get_detailed_image_2d(),get_image_3d()
- TODO: print the electron cloud
- TODO: print the molecule in 3D
- TODO: 2D display of molecules by printing inside 2D a 3D molecule

## FUTURE - DETAILED ATOMS (1)

- TODO: finish detailed atoms

## APART - SCIFIR MOLECULES VISUALIZER (2)

- TODO: .mm file extension (abbreviation of Mscience Molecule)
- TODO: support proteins (check if possible for all proteins first)

## APART - SCIFIR CHEMISTRY CREATOR (1)

- TODO: Chemistry Creator program for creating molecules with .mm extension
