#include "./atom.hpp"

#include "../molecules/atomic_bond.hpp"
#include "../constants.hpp"

#include <cmath>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

namespace scifir
{
	vector<vector<int>> electronic_configuration_order
	{
		{1, orbital::s},
		{2, orbital::s},
		{2, orbital::p},
		{3, orbital::s},
		{3, orbital::p},
		{4, orbital::s},
		{3, orbital::d},
		{4, orbital::p},
		{5, orbital::s},
		{4, orbital::d},
		{5, orbital::p},
		{6, orbital::s},
		{4, orbital::f},
		{5, orbital::d},
		{6, orbital::p},
		{7, orbital::s},
		{5, orbital::f},
		{6, orbital::d},
		{7, orbital::p}
	};

	atom::orbital_configuration::orbital_configuration() : period(),orbital_type(),electrons()
	{
	}

	atom::orbital_configuration::orbital_configuration(int new_period,orbital::type new_orbital_type,int new_electrons) : period(new_period),orbital_type(new_orbital_type),electrons(new_electrons)
	{
	}

	string atom::orbital_configuration::display() const
	{
		return std::to_string(period) + std::to_string(orbital_type) + std::to_string(electrons);
	}

	vector<atom::orbital_configuration> atom::electronic_configuration = {
		atom::orbital_configuration(1,orbital::s,2),
		atom::orbital_configuration(2,orbital::s,2),
		atom::orbital_configuration(2,orbital::p,6),
		atom::orbital_configuration(3,orbital::s,2),
		atom::orbital_configuration(3,orbital::p,6),
		atom::orbital_configuration(4,orbital::s,2),
		atom::orbital_configuration(3,orbital::d,10),
		atom::orbital_configuration(4,orbital::p,6),
		atom::orbital_configuration(5,orbital::s,2),
		atom::orbital_configuration(4,orbital::d,10),
		atom::orbital_configuration(5,orbital::p,6),
		atom::orbital_configuration(6,orbital::s,2),
		atom::orbital_configuration(4,orbital::f,14),
		atom::orbital_configuration(5,orbital::d,10),
		atom::orbital_configuration(6,orbital::p,6),
		atom::orbital_configuration(7,orbital::s,2),
		atom::orbital_configuration(5,orbital::f,14),
		atom::orbital_configuration(6,orbital::d,10),
		atom::orbital_configuration(7,orbital::p,6),
		atom::orbital_configuration(6,orbital::f,14),
		atom::orbital_configuration(7,orbital::d,10),
		atom::orbital_configuration(7,orbital::f,14)
	};

	atom::atom() : species(),charge(),neutrons()
	{}

	atom::atom(const atom& x) : species(x.get_species()),charge(x.get_ionic_charge()),neutrons(x.get_mass_number())
	{}
	
	atom::atom(atom&& x) : species(std::move(x.get_species())),charge(std::move(x.get_ionic_charge())),neutrons(std::move(x.get_mass_number()))
	{}

	atom::atom(atom::atomic_species new_atomic_species) : species(new_atomic_species),charge(),neutrons()
	{}

	atom::atom(const string& new_atomic_species) : species(create_atomic_species(new_atomic_species)),charge(),neutrons()
	{}

	atom& atom::operator =(const atom& x)
	{
		species = x.get_species();
		charge = x.get_ionic_charge();
		neutrons = x.get_mass_number();
		return *this;
	}

	atom& atom::operator =(atom&& x)
	{
		species = std::move(x.get_species());
		charge = std::move(x.get_ionic_charge());
		neutrons = std::move(x.get_mass_number());
		return *this;
	}

	string atom::get_name() const
	{
		switch (species)
		{
			case atom::H:
				return "hydrogen";
			case atom::D:
				return "deuterium";
			case atom::T:
				return "tritium";
			case atom::He:
				return "helium";
			case atom::Li:
				return "lithium";
			case atom::Be:
				return "beryllium";
			case atom::B:
				return "boron";
			case atom::C:
				return "carbon";
			case atom::N:
				return "nitrogen";
			case atom::O:
				return "oxygen";
			case atom::F:
				return "fluorine";
			case atom::Ne:
				return "neon";
			case atom::Na:
				return "sodium";
			case atom::Mg:
				return "magnesium";
			case atom::Al:
				return "aluminum";
			case atom::Si:
				return "silicon";
			case atom::P:
				return "phosphorus";
			case atom::S:
				return "sulfur";
			case atom::Cl:
				return "chlorine";
			case atom::Ar:
				return "argon";
			case atom::K:
				return "potassium";
			case atom::Ca:
				return "calcium";
			case atom::Sc:
				return "scandium";
			case atom::Ti:
				return "titanium";
			case atom::V:
				return "vanadium";
			case atom::Cr:
				return "chromium";
			case atom::Mn:
				return "manganese";
			case atom::Fe:
				return "iron";
			case atom::Co:
				return "cobalt";
			case atom::Ni:
				return "nickel";
			case atom::Cu:
				return "copper";
			case atom::Zn:
				return "zinc";
			case atom::Ga:
				return "gallium";
			case atom::Ge:
				return "germanium";
			case atom::As:
				return "arsenic";
			case atom::Se:
				return "selenium";
			case atom::Br:
				return "bromine";
			case atom::Kr:
				return "krypton";
			case atom::Rb:
				return "rubidium";
			case atom::Sr:
				return "strontium";
			case atom::Y:
				return "yttrium";
			case atom::Zr:
				return "zirconium";
			case atom::Nb:
				return "niobium";
			case atom::Mo:
				return "molybdenum";
			case atom::Tc:
				return "technetium";
			case atom::Ru:
				return "ruthenium";
			case atom::Rh:
				return "rhodium";
			case atom::Pd:
				return "palladium";
			case atom::Ag:
				return "silver";
			case atom::Cd:
				return "cadmium";
			case atom::In:
				return "indium";
			case atom::Sn:
				return "tin";
			case atom::Sb:
				return "antomony";
			case atom::Te:
				return "tellurium";
			case atom::I:
				return "iodine";
			case atom::Xe:
				return "xenon";
			case atom::Cs:
				return "cesium";
			case atom::Ba:
				return "barium";
			case atom::La:
				return "lanthanum";
			case atom::Ce:
				return "cerium";
			case atom::Pr:
				return "praseodymium";
			case atom::Nd:
				return "neodymium";
			case atom::Pm:
				return "promethium";
			case atom::Sm:
				return "samarium";
			case atom::Eu:
				return "europium";
			case atom::Gd:
				return "gadolinium";
			case atom::Tb:
				return "terbium";
			case atom::Dy:
				return "dysprosium";
			case atom::Ho:
				return "holmium";
			case atom::Er:
				return "erbium";
			case atom::Tm:
				return "thulium";
			case atom::Yb:
				return "ytterbium";
			case atom::Lu:
				return "lutetium";
			case atom::Hf:
				return "hafnium";
			case atom::Ta:
				return "tantalum";
			case atom::W:
				return "tungsten";
			case atom::Re:
				return "rhenium";
			case atom::Os:
				return "osmium";
			case atom::Ir:
				return "iridium";
			case atom::Pt:
				return "platinum";
			case atom::Au:
				return "gold";
			case atom::Hg:
				return "mercury";
			case atom::Tl:
				return "thallium";
			case atom::Pb:
				return "lead";
			case atom::Bi:
				return "bismuth";
			case atom::Po:
				return "polonium";
			case atom::At:
				return "astatine";
			case atom::Rn:
				return "radon";
			case atom::Fr:
				return "francium";
			case atom::Ra:
				return "radium";
			case atom::Ac:
				return "actinium";
			case atom::Th:
				return "thorium";
			case atom::Pa:
				return "protactinium";
			case atom::U:
				return "uranium";
			case atom::Np:
				return "neptunium";
			case atom::Pu:
				return "plutonium";
			case atom::Am:
				return "americium";
			case atom::Cm:
				return "curium";
			case atom::Bk:
				return "berkelium";
			case atom::Cf:
				return "californium";
			case atom::Es:
				return "einsteinium";
			case atom::Fm:
				return "fermium";
			case atom::Md:
				return "mendelevium";
			case atom::No:
				return "nobelium";
			case atom::Lr:
				return "lawrencium";
			case atom::Rf:
				return "rutherfordium";
			case atom::Db:
				return "dubnium";
			case atom::Sg:
				return "seaborgium";
			case atom::Bh:
				return "bohrium";
			case atom::Hs:
				return "hassium";
			case atom::Mt:
				return "meitnerium";
			case atom::Ds:
				return "darmstadtium";
			case atom::Rg:
				return "roentgenium";
			case atom::Cn:
				return "copernicium";
			case atom::Nh:
				return "nihonium";
			case atom::Fl:
				return "flerovium";
			case atom::Mc:
				return "moscovium";
			case atom::Lv:
				return "livermorium";
			case atom::Ts:
				return "tennessine";
			case atom::Og:
				return "oganesson";
		}
		return "";
	}

	string atom::get_symbol() const
	{
		return std::to_string(species);
	}

	atom::atomic_group atom::get_atomic_group() const
	{
		switch (species)
		{
			case atom::H:
				return atom::IA;
			case atom::D:
				return atom::IA;
			case atom::T:
				return atom::IA;
			case atom::He:
				return atom::VIIIA;
			case atom::Li:
				return atom::IA;
			case atom::Be:
				return atom::IIA;
			case atom::B:
				return atom::IIIA;
			case atom::C:
				return atom::IVA;
			case atom::N:
				return atom::VA;
			case atom::O:
				return atom::VIA;
			case atom::F:
				return atom::VIIA;
			case atom::Ne:
				return atom::VIIIA;
			case atom::Na:
				return atom::IA;
			case atom::Mg:
				return atom::IIA;
			case atom::Al:
				return atom::IIIA;
			case atom::Si:
				return atom::IVA;
			case atom::P:
				return atom::VA;
			case atom::S:
				return atom::VIA;
			case atom::Cl:
				return atom::VIIA;
			case atom::Ar:
				return atom::VIIIA;
			case atom::K:
				return atom::IA;
			case atom::Ca:
				return atom::IIA;
			case atom::Sc:
				return atom::IIIB;
			case atom::Ti:
				return atom::IVB;
			case atom::V:
				return atom::VB;
			case atom::Cr:
				return atom::VIB;
			case atom::Mn:
				return atom::VIIB;
			case atom::Fe:
				return atom::VIIIB;
			case atom::Co:
				return atom::VIIIB;
			case atom::Ni:
				return atom::VIIIB;
			case atom::Cu:
				return atom::IB;
			case atom::Zn:
				return atom::IIB;
			case atom::Ga:
				return atom::IIIA;
			case atom::Ge:
				return atom::IVA;
			case atom::As:
				return atom::VA;
			case atom::Se:
				return atom::VIA;
			case atom::Br:
				return atom::VIIA;
			case atom::Kr:
				return atom::VIIIA;
			case atom::Rb:
				return atom::IA;
			case atom::Sr:
				return atom::IIA;
			case atom::Y:
				return atom::IIIB;
			case atom::Zr:
				return atom::IVB;
			case atom::Nb:
				return atom::VB;
			case atom::Mo:
				return atom::VIB;
			case atom::Tc:
				return atom::VIIB;
			case atom::Ru:
				return atom::VIIIB;
			case atom::Rh:
				return atom::VIIIB;
			case atom::Pd:
				return atom::VIIIB;
			case atom::Ag:
				return atom::IB;
			case atom::Cd:
				return atom::IIB;
			case atom::In:
				return atom::IIIA;
			case atom::Sn:
				return atom::IVA;
			case atom::Sb:
				return atom::VA;
			case atom::Te:
				return atom::VIA;
			case atom::I:
				return atom::VIIA;
			case atom::Xe:
				return atom::VIIIA;
			case atom::Cs:
				return atom::IA;
			case atom::Ba:
				return atom::IIA;
			case atom::La:
				return atom::LA;
			case atom::Ce:
				return atom::LA;
			case atom::Pr:
				return atom::LA;
			case atom::Nd:
				return atom::LA;
			case atom::Pm:
				return atom::LA;
			case atom::Sm:
				return atom::LA;
			case atom::Eu:
				return atom::LA;
			case atom::Gd:
				return atom::LA;
			case atom::Tb:
				return atom::LA;
			case atom::Dy:
				return atom::LA;
			case atom::Ho:
				return atom::LA;
			case atom::Er:
				return atom::LA;
			case atom::Tm:
				return atom::LA;
			case atom::Yb:
				return atom::LA;
			case atom::Lu:
				return atom::LA;
			case atom::Hf:
				return atom::IVB;
			case atom::Ta:
				return atom::VB;
			case atom::W:
				return atom::VIB;
			case atom::Re:
				return atom::VIIB;
			case atom::Os:
				return atom::VIIIB;
			case atom::Ir:
				return atom::VIIIB;
			case atom::Pt:
				return atom::VIIIB;
			case atom::Au:
				return atom::IB;
			case atom::Hg:
				return atom::IIB;
			case atom::Tl:
				return atom::IIIA;
			case atom::Pb:
				return atom::IVA;
			case atom::Bi:
				return atom::VA;
			case atom::Po:
				return atom::VIA;
			case atom::At:
				return atom::VIIA;
			case atom::Rn:
				return atom::VIIIA;
			case atom::Fr:
				return atom::IA;
			case atom::Ra:
				return atom::IIA;
			case atom::Ac:
				return atom::AC;
			case atom::Th:
				return atom::AC;
			case atom::Pa:
				return atom::AC;
			case atom::U:
				return atom::AC;
			case atom::Np:
				return atom::AC;
			case atom::Pu:
				return atom::AC;
			case atom::Am:
				return atom::AC;
			case atom::Cm:
				return atom::AC;
			case atom::Bk:
				return atom::AC;
			case atom::Cf:
				return atom::AC;
			case atom::Es:
				return atom::AC;
			case atom::Fm:
				return atom::AC;
			case atom::Md:
				return atom::AC;
			case atom::No:
				return atom::AC;
			case atom::Lr:
				return atom::AC;
			case atom::Rf:
				return atom::IVB;
			case atom::Db:
				return atom::VB;
			case atom::Sg:
				return atom::VIB;
			case atom::Bh:
				return atom::VIIB;
			case atom::Hs:
				return atom::VIIIB;
			case atom::Mt:
				return atom::VIIIB;
			case atom::Ds:
				return atom::VIIIB;
			case atom::Rg:
				return atom::IB;
			case atom::Cn:
				return atom::IIB;
			case atom::Nh:
				return atom::IIIA;
			case atom::Fl:
				return atom::IVA;
			case atom::Mc:
				return atom::VA;
			case atom::Lv:
				return atom::VIA;
			case atom::Ts:
				return atom::VIIA;
			case atom::Og:
				return atom::VIIIA;
		}
		return atom::NO_GROUP;
	}

	int atom::get_period() const
	{
		if (species == atom::H or species == atom::D or species == atom::T or species == atom::He)
		{
			return 1;
		}
		else if (species == atom::Li or species == atom::Be or species == atom::B or species == atom::C or species == atom::N or species == atom::O or species == atom::F or species == atom::Ne)
		{
			return 2;
		}
		else if (species == atom::Na or species == atom::Mg or species == atom::Al or species == atom::Si or species == atom::P or species == atom::S or species == atom::Cl or species == atom::Ar)
		{
			return 3;
		}
		else if (species == atom::K or species == atom::Ca or species == atom::Sc or species == atom::Ti or species == atom::V or species == atom::Cr or species == atom::Mn or species == atom::Fe or species == atom::Co or species == atom::Ni or species == atom::Cu or species == atom::Zn or species == atom::Ga or species == atom::Ge or species == atom::As or species == atom::Se or species == atom::Br or species == atom::Kr)
		{
			return 4;
		}
		else if (species == atom::Rb or species == atom::Sr or species == atom::Y or species == atom::Zr or species == atom::Nb or species == atom::Mo or species == atom::Tc or species == atom::Ru or species == atom::Rh or species == atom::Pd or species == atom::Ag or species == atom::Cd or species == atom::In or species == atom::Sn or species == atom::Sb or species == atom::Te or species == atom::I or species == atom::Xe)
		{
			return 5;
		}
		else if (species == atom::Cs or species == atom::Ba or species == atom::La or species == atom::Ce or species == atom::Pr or species == atom::Nd or species == atom::Pm or species == atom::Sm or species == atom::Eu or species == atom::Gd or species == atom::Tb or species == atom::Dy or species == atom::Ho or species == atom::Er or species == atom::Tm or species == atom::Yb or species == atom::Lu or species == atom::Hf or species == atom::Ta or species == atom::W or species == atom::Re or species == atom::Os or species == atom::Ir or species == atom::Pt or species == atom::Au or species == atom::Hg or species == atom::Tl or species == atom::Pb or species == atom::Bi or species == atom::Po or species == atom::At or species == atom::Rn)
		{
			return 6;
		}
		else if (species == atom::Fr or species == atom::Ra or species == atom::Ac or species == atom::Th or species == atom::Pa or species == atom::U or species == atom::Np or species == atom::Pu or species == atom::Am or species == atom::Cm or species == atom::Bk or species == atom::Cf or species == atom::Es or species == atom::Fm or species == atom::Md or species == atom::No or species == atom::Lr or species == atom::Rf or species == atom::Db or species == atom::Sg or species == atom::Bh or species == atom::Hs or species == atom::Mt or species == atom::Ds or species == atom::Rg or species == atom::Cn or species == atom::Nh or species == atom::Fl or species == atom::Mc or species == atom::Lv or species == atom::Ts or species == atom::Og)
		{
			return 7;
		}
		return 0;
	}

	int atom::get_z() const
	{
		switch (species)
		{
			case atom::H:
				return 1;
			case atom::D:
				return 1;
			case atom::T:
				return 1;
			case atom::He:
				return 2;
			case atom::Li:
				return 3;
			case atom::Be:
				return 4;
			case atom::B:
				return 5;
			case atom::C:
				return 6;
			case atom::N:
				return 7;
			case atom::O:
				return 8;
			case atom::F:
				return 9;
			case atom::Ne:
				return 10;
			case atom::Na:
				return 11;
			case atom::Mg:
				return 12;
			case atom::Al:
				return 13;
			case atom::Si:
				return 14;
			case atom::P:
				return 15;
			case atom::S:
				return 16;
			case atom::Cl:
				return 17;
			case atom::Ar:
				return 18;
			case atom::K:
				return 19;
			case atom::Ca:
				return 20;
			case atom::Sc:
				return 21;
			case atom::Ti:
				return 22;
			case atom::V:
				return 23;
			case atom::Cr:
				return 24;
			case atom::Mn:
				return 25;
			case atom::Fe:
				return 26;
			case atom::Co:
				return 27;
			case atom::Ni:
				return 28;
			case atom::Cu:
				return 29;
			case atom::Zn:
				return 30;
			case atom::Ga:
				return 31;
			case atom::Ge:
				return 32;
			case atom::As:
				return 33;
			case atom::Se:
				return 34;
			case atom::Br:
				return 35;
			case atom::Kr:
				return 36;
			case atom::Rb:
				return 37;
			case atom::Sr:
				return 38;
			case atom::Y:
				return 39;
			case atom::Zr:
				return 40;
			case atom::Nb:
				return 41;
			case atom::Mo:
				return 42;
			case atom::Tc:
				return 43;
			case atom::Ru:
				return 44;
			case atom::Rh:
				return 45;
			case atom::Pd:
				return 46;
			case atom::Ag:
				return 47;
			case atom::Cd:
				return 48;
			case atom::In:
				return 49;
			case atom::Sn:
				return 50;
			case atom::Sb:
				return 51;
			case atom::Te:
				return 52;
			case atom::I:
				return 53;
			case atom::Xe:
				return 54;
			case atom::Cs:
				return 55;
			case atom::Ba:
				return 56;
			case atom::La:
				return 57;
			case atom::Ce:
				return 58;
			case atom::Pr:
				return 59;
			case atom::Nd:
				return 60;
			case atom::Pm:
				return 61;
			case atom::Sm:
				return 62;
			case atom::Eu:
				return 63;
			case atom::Gd:
				return 64;
			case atom::Tb:
				return 65;
			case atom::Dy:
				return 66;
			case atom::Ho:
				return 67;
			case atom::Er:
				return 68;
			case atom::Tm:
				return 69;
			case atom::Yb:
				return 70;
			case atom::Lu:
				return 71;
			case atom::Hf:
				return 72;
			case atom::Ta:
				return 73;
			case atom::W:
				return 74;
			case atom::Re:
				return 75;
			case atom::Os:
				return 76;
			case atom::Ir:
				return 77;
			case atom::Pt:
				return 78;
			case atom::Au:
				return 79;
			case atom::Hg:
				return 80;
			case atom::Tl:
				return 81;
			case atom::Pb:
				return 82;
			case atom::Bi:
				return 83;
			case atom::Po:
				return 84;
			case atom::At:
				return 85;
			case atom::Rn:
				return 86;
			case atom::Fr:
				return 87;
			case atom::Ra:
				return 88;
			case atom::Ac:
				return 89;
			case atom::Th:
				return 90;
			case atom::Pa:
				return 91;
			case atom::U:
				return 92;
			case atom::Np:
				return 93;
			case atom::Pu:
				return 94;
			case atom::Am:
				return 95;
			case atom::Cm:
				return 96;
			case atom::Bk:
				return 97;
			case atom::Cf:
				return 98;
			case atom::Es:
				return 99;
			case atom::Fm:
				return 100;
			case atom::Md:
				return 101;
			case atom::No:
				return 102;
			case atom::Lr:
				return 103;
			case atom::Rf:
				return 104;
			case atom::Db:
				return 105;
			case atom::Sg:
				return 106;
			case atom::Bh:
				return 107;
			case atom::Hs:
				return 108;
			case atom::Mt:
				return 109;
			case atom::Ds:
				return 110;
			case atom::Rg:
				return 111;
			case atom::Cn:
				return 112;
			case atom::Nh:
				return 113;
			case atom::Fl:
				return 114;
			case atom::Mc:
				return 115;
			case atom::Lv:
				return 116;
			case atom::Ts:
				return 117;
			case atom::Og:
				return 118;
		}
		return 0;
	}

	int atom::get_valence_number() const
	{
		if (get_atomic_group() == IA)
		{
			return 1;
		}
		else if(get_atomic_group() == IIA)
		{
			return 2;
		}
		else if(get_atomic_group() == IIIA)
		{
			return 3;
		}
		else if(get_atomic_group() == IVA)
		{
			return 4;
		}
		else if(get_atomic_group() == VA)
		{
			return 5;
		}
		else if(get_atomic_group() == VIA)
		{
			return 6;
		}
		else if(get_atomic_group() == VIIA)
		{
			return 7;
		}
		else if(get_atomic_group() == VIIIA)
		{
			return 8;
		}
		if (get_atomic_group() == IIIB)
		{
			return 3;
		}
		else if (get_atomic_group() == IVB)
		{
			return 4;
		}
		else if (get_atomic_group() == VB)
		{
			return 5;
		}
		else if (get_atomic_group() == VIB)
		{
			return 6;
		}
		else if (get_atomic_group() == VIIB)
		{
			return 7;
		}
		else if (get_atomic_group() == VIIIB)
		{
			if (get_z() == 26 or get_z() == 44 or get_z() == 76 or get_z() == 108)
			{
				return 8;
			}
			else if (get_z() == 27 or get_z() == 45 or get_z() == 77 or get_z() == 109)
			{
				return 9;
			}
			else if (get_z() == 28 or get_z() == 46 or get_z() == 78 or get_z() == 110)
			{
				return 10;
			}
		}
		else if (get_atomic_group() == IB)
		{
			return 11;
		}
		else if (get_atomic_group() == IIB)
		{
			return 12;
		}
		return 1;
	}

	int atom::get_mass_number() const
	{
		return neutrons;
	}

	int atom::get_common_mass_number() const
	{
		switch (species)
		{
			case atom::H:
				return 0;
			case atom::D:
				return 1;
			case atom::T:
				return 2;
			case atom::He:
				return 2;
			case atom::Li:
				return 4;
			case atom::Be:
				return 5;
			case atom::B:
				return 6;
			case atom::C:
				return 6;
			case atom::N:
				return 7;
			case atom::O:
				return 8;
			case atom::F:
				return 10;
			case atom::Ne:
				return 10;
			case atom::Na:
				return 12;
			case atom::Mg:
				return 12;
			case atom::Al:
				return 14;
			case atom::Si:
				return 14;
			case atom::P:
				return 16;
			case atom::S:
				return 16;
			case atom::Cl:
				return 18;
			case atom::Ar:
				return 22;
			case atom::K:
				return 20;
			case atom::Ca:
				return 20;
			case atom::Sc:
				return 24;
			case atom::Ti:
				return 26;
			case atom::V:
				return 28;
			case atom::Cr:
				return 28;
			case atom::Mn:
				return 30;
			case atom::Fe:
				return 30;
			case atom::Co:
				return 32;
			case atom::Ni:
				return 31;
			case atom::Cu:
				return 35;
			case atom::Zn:
				return 35;
			case atom::Ga:
				return 39;
			case atom::Ge:
				return 41;
			case atom::As:
				return 42;
			case atom::Se:
				return 45;
			case atom::Br:
				return 45;
			case atom::Kr:
				return 49;
			case atom::Rb:
				return 47;
			case atom::Sr:
				return 45;
			case atom::Y:
				return 50;
			case atom::Zr:
				return 51;
			case atom::Nb:
				return 52;
			case atom::Mo:
				return 54;
			case atom::Tc:
				return 56;
			case atom::Ru:
				return 57;
			case atom::Rh:
				return 58;
			case atom::Pd:
				return 60;
			case atom::Ag:
				return 61;
			case atom::Cd:
				return 64;
			case atom::In:
				return 66;
			case atom::Sn:
				return 69;
			case atom::Sb:
				return 71;
			case atom::Te:
				return 76;
			case atom::I:
				return 74;
			case atom::Xe:
				return 77;
			case atom::Cs:
				return 78;
			case atom::Ba:
				return 81;
			case atom::La:
				return 82;
			case atom::Ce:
				return 82;
			case atom::Pr:
				return 82;
			case atom::Nd:
				return 84;
			case atom::Pm:
				return 84;
			case atom::Sm:
				return 88;
			case atom::Eu:
				return 89;
			case atom::Gd:
				return 93;
			case atom::Tb:
				return 94;
			case atom::Dy:
				return 97;
			case atom::Ho:
				return 98;
			case atom::Er:
				return 99;
			case atom::Tm:
				return 100;
			case atom::Yb:
				return 103;
			case atom::Lu:
				return 104;
			case atom::Hf:
				return 106;
			case atom::Ta:
				return 108;
			case atom::W:
				return 110;
			case atom::Re:
				return 111;
			case atom::Os:
				return 114;
			case atom::Ir:
				return 115;
			case atom::Pt:
				return 117;
			case atom::Au:
				return 118;
			case atom::Hg:
				return 121;
			case atom::Tl:
				return 123;
			case atom::Pb:
				return 125;
			case atom::Bi:
				return 126;
			case atom::Po:
				return 125;
			case atom::At:
				return 125;
			case atom::Rn:
				return 136;
			case atom::Fr:
				return 136;
			case atom::Ra:
				return 138;
			case atom::Ac:
				return 138;
			case atom::Th:
				return 142;
			case atom::Pa:
				return 140;
			case atom::U:
				return 146;
			case atom::Np:
				return 144;
			case atom::Pu:
				return 150;
			case atom::Am:
				return 248;
			case atom::Cm:
				return 151;
			case atom::Bk:
				return 150;
			case atom::Cf:
				return 153;
			case atom::Es:
				return 155;
			case atom::Fm:
				return 157;
			case atom::Md:
				return 157;
			case atom::No:
				return 157;
			case atom::Lr:
				return 159;
			case atom::Rf:
				return 163;
			case atom::Db:
				return 157;
			case atom::Sg:
				return 160;
			case atom::Bh:
				return 157;
			case atom::Hs:
				return 161;
			case atom::Mt:
				return 159;
			case atom::Ds:
				return 159;
			case atom::Rg:
				return 161;
			case atom::Cn:
				return 173;
			case atom::Nh:
				return 173;
			case atom::Fl:
				return 175;
			case atom::Mc:
				return 175;
			case atom::Lv:
				return 177;
			case atom::Ts:
				return 177;
			case atom::Og:
				return 176;
		}
		return 0;
	}

	length atom::get_atomic_radius() const
	{
		switch (species)
		{
			case atom::H:
				return 1.09_Å;
			case atom::D:
				return 2.12562_fm;
			case atom::T:
				return 1.7591_fm;
			case atom::He:
				return 0_m;
			case atom::Li:
				return 152_pm;
			case atom::Be:
				return 112_pm;
			case atom::B:
				return 90_pm;
			case atom::C:
				return 69_pm;
			case atom::N:
				return 65_pm;
			case atom::O:
				return 60_pm;
			case atom::F:
				return 50_pm;
			case atom::Ne:
				return 0_pm;
			case atom::Na:
				return 186_pm;
			case atom::Mg:
				return 160_pm;
			case atom::Al:
				return 143_pm;
			case atom::Si:
				return 111_pm;
			case atom::P:
				return 100_pm;
			case atom::S:
				return 100_pm;
			case atom::Cl:
				return 100_pm;
			case atom::Ar:
				return 0_pm;
			case atom::K:
				return 227_pm;
			case atom::Ca:
				return 197_pm;
			case atom::Sc:
				return 162_pm;
			case atom::Ti:
				return 147_pm;
			case atom::V:
				return 134_pm;
			case atom::Cr:
				return 128_pm;
			case atom::Mn:
				return 127_pm;
			case atom::Fe:
				return 126_pm;
			case atom::Co:
				return 125_pm;
			case atom::Ni:
				return 124_pm;
			case atom::Cu:
				return 128_pm;
			case atom::Zn:
				return 134_pm;
			case atom::Ga:
				return 135_pm;
			case atom::Ge:
				return 122_pm;
			case atom::As:
				return 119_pm;
			case atom::Se:
				return 120_pm;
			case atom::Br:
				return 120_pm;
			case atom::Kr:
				return 0_pm;
			case atom::Rb:
				return 248_pm;
			case atom::Sr:
				return 215_pm;
			case atom::Y:
				return 180_pm;
			case atom::Zr:
				return 160_pm;
			case atom::Nb:
				return 146_pm;
			case atom::Mo:
				return 139_pm;
			case atom::Tc:
				return 136_pm;
			case atom::Ru:
				return 134_pm;
			case atom::Rh:
				return 134_pm;
			case atom::Pd:
				return 137_pm;
			case atom::Ag:
				return 144_pm;
			case atom::Cd:
				return 151_pm;
			case atom::In:
				return 167_pm;
			case atom::Sn:
				return 140_pm;
			case atom::Sb:
				return 140_pm;
			case atom::Te:
				return 140_pm;
			case atom::I:
				return 140_pm;
			case atom::Xe:
				return 0_pm;
			case atom::Cs:
				return 265_pm;
			case atom::Ba:
				return 222_pm;
			case atom::La:
				return 187_pm;
			case atom::Ce:
				return 181.8_pm;
			case atom::Pr:
				return 182_pm;
			case atom::Nd:
				return 181_pm;
			case atom::Pm:
				return 183_pm;
			case atom::Sm:
				return 180_pm;
			case atom::Eu:
				return 180_pm;
			case atom::Gd:
				return 180_pm;
			case atom::Tb:
				return 177_pm;
			case atom::Dy:
				return 178_pm;
			case atom::Ho:
				return 176_pm;
			case atom::Er:
				return 176_pm;
			case atom::Tm:
				return 176_pm;
			case atom::Yb:
				return 176_pm;
			case atom::Lu:
				return 174_pm;
			case atom::Hf:
				return 159_pm;
			case atom::Ta:
				return 146_pm;
			case atom::W:
				return 139_pm;
			case atom::Re:
				return 137_pm;
			case atom::Os:
				return 135_pm;
			case atom::Ir:
				return 136_pm;
			case atom::Pt:
				return 139_pm;
			case atom::Au:
				return 144_pm;
			case atom::Hg:
				return 151_pm;
			case atom::Tl:
				return 170_pm;
			case atom::Pb:
				return 175_pm;
			case atom::Bi:
				return 156_pm;
			case atom::Po:
				return 168_pm;
			case atom::At:
				return 0_pm;
			case atom::Rn:
				return 0_pm;
			case atom::Fr:
				return 348_pm;
			case atom::Ra:
				return 283_pm;
			case atom::Ac:
				return 195_pm;
			case atom::Th:
				return 179.8_pm;
			case atom::Pa:
				return 163_pm;
			case atom::U:
				return 156_pm;
			case atom::Np:
				return 155_pm;
			case atom::Pu:
				return 159_pm;
			case atom::Am:
				return 173_pm;
			case atom::Cm:
				return 174_pm;
			case atom::Bk:
				return 170_pm;
			case atom::Cf:
				return 0_pm;
			case atom::Es:
				return 0_pm;
			case atom::Fm:
				return 0_pm;
			case atom::Md:
				return 0_pm;
			case atom::No:
				return 0_pm;
			case atom::Lr:
				return 0_pm;
			case atom::Rf:
				return 150_pm;
			case atom::Db:
				return 139_pm;
			case atom::Sg:
				return 132_pm;
			case atom::Bh:
				return 128_pm;
			case atom::Hs:
				return 126_pm;
			case atom::Mt:
				return 128_pm;
			case atom::Ds:
				return 132_pm;
			case atom::Rg:
				return 138_pm;
			case atom::Cn:
				return 147_pm;
			case atom::Nh:
				return 170_pm;
			case atom::Fl:
				return 180_pm;
			case atom::Mc:
				return 187_pm;
			case atom::Lv:
				return 183_pm;
			case atom::Ts:
				return 0_pm;
			case atom::Og:
				return 0_pm;
		}
		return 0_pm;
	}

	mass atom::get_standard_atomic_mass() const
	{
		switch (species)
		{
			case atom::H:
				return 1.008_amu;
			case atom::D:
				return 1.008_amu;
			case atom::T:
				return 1.008_amu;
			case atom::He:
				return 4.003_amu;
			case atom::Li:
				return 6.941_amu;
			case atom::Be:
				return 9.012_amu;
			case atom::B:
				return 10.811_amu;
			case atom::C:
				return 12.011_amu;
			case atom::N:
				return 14.007_amu;
			case atom::O:
				return 15.999_amu;
			case atom::F:
				return 18.998_amu;
			case atom::Ne:
				return 20.180_amu;
			case atom::Na:
				return 22.99_amu;
			case atom::Mg:
				return 24.305_amu;
			case atom::Al:
				return 26.982_amu;
			case atom::Si:
				return 28.086_amu;
			case atom::P:
				return 30.974_amu;
			case atom::S:
				return 32.066_amu;
			case atom::Cl:
				return 35.453_amu;
			case atom::Ar:
				return 39.948_amu;
			case atom::K:
				return 39.098_amu;
			case atom::Ca:
				return 40.078_amu;
			case atom::Sc:
				return 44.956_amu;
			case atom::Ti:
				return 47.88_amu;
			case atom::V:
				return 50.942_amu;
			case atom::Cr:
				return 51.996_amu;
			case atom::Mn:
				return 54.938_amu;
			case atom::Fe:
				return 55.933_amu;
			case atom::Co:
				return 58.933_amu;
			case atom::Ni:
				return 58.693_amu;
			case atom::Cu:
				return 63.546_amu;
			case atom::Zn:
				return 65.39_amu;
			case atom::Ga:
				return 69.732_amu;
			case atom::Ge:
				return 72.61_amu;
			case atom::As:
				return 74.922_amu;
			case atom::Se:
				return 78.972_amu;
			case atom::Br:
				return 79.904_amu;
			case atom::Kr:
				return 84.8_amu;
			case atom::Rb:
				return 84.468_amu;
			case atom::Sr:
				return 87.62_amu;
			case atom::Y:
				return 88.906_amu;
			case atom::Zr:
				return 91.224_amu;
			case atom::Nb:
				return 92.906_amu;
			case atom::Mo:
				return 95.95_amu;
			case atom::Tc:
				return 98.907_amu;
			case atom::Ru:
				return 101.07_amu;
			case atom::Rh:
				return 102.906_amu;
			case atom::Pd:
				return 106.42_amu;
			case atom::Ag:
				return 107.858_amu;
			case atom::Cd:
				return 112.411_amu;
			case atom::In:
				return 114.818_amu;
			case atom::Sn:
				return 118.71_amu;
			case atom::Sb:
				return 121.760_amu;
			case atom::Te:
				return 127.6_amu;
			case atom::I:
				return 126.904_amu;
			case atom::Xe:
				return 131.29_amu;
			case atom::Cs:
				return 132.905_amu;
			case atom::Ba:
				return 137.327_amu;
			case atom::La:
				return 138.906_amu;
			case atom::Ce:
				return 140.115_amu;
			case atom::Pr:
				return 140.908_amu;
			case atom::Nd:
				return 144.24_amu;
			case atom::Pm:
				return 144.913_amu;
			case atom::Sm:
				return 150.36_amu;
			case atom::Eu:
				return 151.966_amu;
			case atom::Gd:
				return 157.25_amu;
			case atom::Tb:
				return 158.925_amu;
			case atom::Dy:
				return 162.50_amu;
			case atom::Ho:
				return 164.930_amu;
			case atom::Er:
				return 167.26_amu;
			case atom::Tm:
				return 168.934_amu;
			case atom::Yb:
				return 173.04_amu;
			case atom::Lu:
				return 174.967_amu;
			case atom::Hf:
				return 178.49_amu;
			case atom::Ta:
				return 180.948_amu;
			case atom::W:
				return 183.85_amu;
			case atom::Re:
				return 186.207_amu;
			case atom::Os:
				return 190.23_amu;
			case atom::Ir:
				return 192.22_amu;
			case atom::Pt:
				return 195.08_amu;
			case atom::Au:
				return 196.967_amu;
			case atom::Hg:
				return 200.59_amu;
			case atom::Tl:
				return 204.383_amu;
			case atom::Pb:
				return 207.2_amu;
			case atom::Bi:
				return 208.98_amu;
			case atom::Po:
				return 208.982_amu;
			case atom::At:
				return 209.987_amu;
			case atom::Rn:
				return 222.018_amu;
			case atom::Fr:
				return 223.02_amu;
			case atom::Ra:
				return 226.025_amu;
			case atom::Ac:
				return 227.028_amu;
			case atom::Th:
				return 232.038_amu;
			case atom::Pa:
				return 231.036_amu;
			case atom::U:
				return 238.029_amu;
			case atom::Np:
				return 237.048_amu;
			case atom::Pu:
				return 244.064_amu;
			case atom::Am:
				return 243.061_amu;
			case atom::Cm:
				return 247.070_amu;
			case atom::Bk:
				return 247.070_amu;
			case atom::Cf:
				return 251.080_amu;
			case atom::Es:
				return 254_amu;
			case atom::Fm:
				return 257.095_amu;
			case atom::Md:
				return 258.1_amu;
			case atom::No:
				return 259.101_amu;
			case atom::Lr:
				return 262_amu;
			case atom::Rf:
				return 267_amu;
			case atom::Db:
				return 262_amu;
			case atom::Sg:
				return 266_amu;
			case atom::Bh:
				return 264_amu;
			case atom::Hs:
				return 190.23_amu;
			case atom::Mt:
				return 268_amu;
			case atom::Ds:
				return 269_amu;
			case atom::Rg:
				return 272_amu;
			case atom::Cn:
				return 285_amu;
			case atom::Nh:
				return 0_amu;
			case atom::Fl:
				return 289_amu;
			case atom::Mc:
				return 0_amu;
			case atom::Lv:
				return 298_amu;
			case atom::Ts:
				return 0_amu;
			case atom::Og:
				return 0_amu;
		}
		return 0_amu;
	}

	float atom::get_electronegativity() const
	{
		switch (species)
		{
			case atom::H:
				return 4.0f;
			case atom::D:
				return 2.0f;
			case atom::T:
				return 0.8f;
			case atom::He:
				return 0.0f;
			case atom::Li:
				return 0.98f;
			case atom::Be:
				return 1.57f;
			case atom::B:
				return 2.04f;
			case atom::C:
				return 2.55f;
			case atom::N:
				return 3.04f;
			case atom::O:
				return 3.44f;
			case atom::F:
				return 3.98f;
			case atom::Ne:
				return 0.0f;
			case atom::Na:
				return 0.93f;
			case atom::Mg:
				return 1.31f;
			case atom::Al:
				return 1.61f;
			case atom::Si:
				return 1.90f;
			case atom::P:
				return 2.19f;
			case atom::S:
				return 2.58f;
			case atom::Cl:
				return 3.16f;
			case atom::Ar:
				return 0.0f;
			case atom::K:
				return 0.82f;
			case atom::Ca:
				return 1.0f;
			case atom::Sc:
				return 1.36f;
			case atom::Ti:
				return 1.54f;
			case atom::V:
				return 1.63f;
			case atom::Cr:
				return 1.66f;
			case atom::Mn:
				return 1.55f;
			case atom::Fe:
				return 1.83f;
			case atom::Co:
				return 1.88f;
			case atom::Ni:
				return 1.91f;
			case atom::Cu:
				return 1.90f;
			case atom::Zn:
				return 1.65f;
			case atom::Ga:
				return 1.81f;
			case atom::Ge:
				return 2.01f;
			case atom::As:
				return 2.18f;
			case atom::Se:
				return 2.55f;
			case atom::Br:
				return 2.96f;
			case atom::Kr:
				return 3.00f;
			case atom::Rb:
				return 0.82f;
			case atom::Sr:
				return 0.95f;
			case atom::Y:
				return 1.22f;
			case atom::Zr:
				return 1.33f;
			case atom::Nb:
				return 1.6f;
			case atom::Mo:
				return 2.16f;
			case atom::Tc:
				return 1.9f;
			case atom::Ru:
				return 2.2f;
			case atom::Rh:
				return 2.28f;
			case atom::Pd:
				return 2.20f;
			case atom::Ag:
				return 1.93f;
			case atom::Cd:
				return 1.69f;
			case atom::In:
				return 1.78f;
			case atom::Sn:
				return 1.96f;
			case atom::Sb:
				return 2.05f;
			case atom::Te:
				return 2.1f;
			case atom::I:
				return 2.66f;
			case atom::Xe:
				return 2.6f;
			case atom::Cs:
				return 0.79f;
			case atom::Ba:
				return 0.89f;
			case atom::La:
				return 1.10f;
			case atom::Ce:
				return 1.12f;
			case atom::Pr:
				return 1.13f;
			case atom::Nd:
				return 1.14f;
			case atom::Pm:
				return 1.13f;
			case atom::Sm:
				return 1.17f;
			case atom::Eu:
				return 1.2f;
			case atom::Gd:
				return 1.20f;
			case atom::Tb:
				return 1.2f;
			case atom::Dy:
				return 1.22f;
			case atom::Ho:
				return 1.23f;
			case atom::Er:
				return 1.24f;
			case atom::Tm:
				return 1.25f;
			case atom::Yb:
				return 1.1f;
			case atom::Lu:
				return 1.27f;
			case atom::Hf:
				return 1.3f;
			case atom::Ta:
				return 1.5f;
			case atom::W:
				return 2.36f;
			case atom::Re:
				return 1.9f;
			case atom::Os:
				return 2.2f;
			case atom::Ir:
				return 2.20f;
			case atom::Pt:
				return 2.28f;
			case atom::Au:
				return 2.54f;
			case atom::Hg:
				return 2.00f;
			case atom::Tl:
				return 1.62f;
			case atom::Pb:
				return 1.87f;
			case atom::Bi:
				return 2.02f;
			case atom::Po:
				return 2.0f;
			case atom::At:
				return 2.2f;
			case atom::Rn:
				return 2.2f;
			case atom::Fr:
				return 0.79f;
			case atom::Ra:
				return 0.9f;
			case atom::Ac:
				return 1.1f;
			case atom::Th:
				return 1.3f;
			case atom::Pa:
				return 1.5f;
			case atom::U:
				return 1.38f;
			case atom::Np:
				return 1.36f;
			case atom::Pu:
				return 1.28f;
			case atom::Am:
				return 1.3f;
			case atom::Cm:
				return 1.3f;
			case atom::Bk:
				return 1.3f;
			case atom::Cf:
				return 1.3f;
			case atom::Es:
				return 1.3f;
			case atom::Fm:
				return 1.3f;
			case atom::Md:
				return 1.3f;
			case atom::No:
				return 1.3f;
			case atom::Lr:
				return 1.3f;
			case atom::Rf:
				return 0.0f;
			case atom::Db:
				return 0.0f;
			case atom::Sg:
				return 0.0f;
			case atom::Bh:
				return 0.0f;
			case atom::Hs:
				return 0.0f;
			case atom::Mt:
				return 0.0f;
			case atom::Ds:
				return 0.0f;
			case atom::Rg:
				return 0.0f;
			case atom::Cn:
				return 0.0f;
			case atom::Nh:
				return 0.0f;
			case atom::Fl:
				return 0.0f;
			case atom::Mc:
				return 0.0f;
			case atom::Lv:
				return 0.0f;
			case atom::Ts:
				return 0.0f;
			case atom::Og:
				return 0.0f;
			case atom::NO_SPECIES:
				return 0.0f;
		}
		return 0.0f;
	}

	bool atom::is_radioactive() const
	{
		if (get_z() > 83)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	molar_energy atom::get_ionization_energy() const
	{
		switch (species)
		{
			case atom::H:
				return molar_energy("1312 kJ/mol");
			case atom::D:
				return molar_energy("1312 kJ/mol");
			case atom::T:
				return molar_energy("1312 kJ/mol");
			case atom::He:
				return molar_energy("2372.3 kJ/mol");
			case atom::Li:
				return molar_energy("520.2 kJ/mol");
			case atom::Be:
				return molar_energy("899.5 kJ/mol");
			case atom::B:
				return molar_energy("800.6 kJ/mol");
			case atom::C:
				return molar_energy("1086.5 kJ/mol");
			case atom::N:
				return molar_energy("1402.3 kJ/mol");
			case atom::O:
				return molar_energy("1313.9 kJ/mol");
			case atom::F:
				return molar_energy("1681 kJ/mol");
			case atom::Ne:
				return molar_energy("2080.7 kJ/mol");
			case atom::Na:
				return molar_energy("495.8 kJ/mol");
			case atom::Mg:
				return molar_energy("737.7 kJ/mol");
			case atom::Al:
				return molar_energy("577.5 kJ/mol");
			case atom::Si:
				return molar_energy("786.5 kJ/mol");
			case atom::P:
				return molar_energy("1011.8 kJ/mol");
			case atom::S:
				return molar_energy("999.6 kJ/mol");
			case atom::Cl:
				return molar_energy("1251.2 kJ/mol");
			case atom::Ar:
				return molar_energy("1520.6 kJ/mol");
			case atom::K:
				return molar_energy("418.8 kJ/mol");
			case atom::Ca:
				return molar_energy("589.8 kJ/mol");
			case atom::Sc:
				return molar_energy("633.1 kJ/mol");
			case atom::Ti:
				return molar_energy("658.8 kJ/mol");
			case atom::V:
				return molar_energy("650.9 kJ/mol");
			case atom::Cr:
				return molar_energy("652.9 kJ/mol");
			case atom::Mn:
				return molar_energy("717.3 kJ/mol");
			case atom::Fe:
				return molar_energy("762.5 kJ/mol");
			case atom::Co:
				return molar_energy("760.4 kJ/mol");
			case atom::Ni:
				return molar_energy("737.1 kJ/mol");
			case atom::Cu:
				return molar_energy("745.5 kJ/mol");
			case atom::Zn:
				return molar_energy("906.4 kJ/mol");
			case atom::Ga:
				return molar_energy("578.8 kJ/mol");
			case atom::Ge:
				return molar_energy("762 kJ/mol");
			case atom::As:
				return molar_energy("947.0 kJ/mol");
			case atom::Se:
				return molar_energy("941.0 kJ/mol");
			case atom::Br:
				return molar_energy("1139.9 kJ/mol");
			case atom::Kr:
				return molar_energy("1350.8 kJ/mol");
			case atom::Rb:
				return molar_energy("403 kJ/mol");
			case atom::Sr:
				return molar_energy("549.5 kJ/mol");
			case atom::Y:
				return molar_energy("600 kJ/mol");
			case atom::Zr:
				return molar_energy("640.1 kJ/mol");
			case atom::Nb:
				return molar_energy("652.1 kJ/mol");
			case atom::Mo:
				return molar_energy("684.3 kJ/mol");
			case atom::Tc:
				return molar_energy("702 kJ/mol");
			case atom::Ru:
				return molar_energy("710.2 kJ/mol");
			case atom::Rh:
				return molar_energy("719.7 kJ/mol");
			case atom::Pd:
				return molar_energy("804.4 kJ/mol");
			case atom::Ag:
				return molar_energy("731.0 kJ/mol");
			case atom::Cd:
				return molar_energy("867.8 kJ/mol");
			case atom::In:
				return molar_energy("558.3 kJ/mol");
			case atom::Sn:
				return molar_energy("708.6 kJ/mol");
			case atom::Sb:
				return molar_energy("834 kJ/mol");
			case atom::Te:
				return molar_energy("869.3 kJ/mol");
			case atom::I:
				return molar_energy("1008.4 kJ/mol");
			case atom::Xe:
				return molar_energy("1170.4 kJ/mol");
			case atom::Cs:
				return molar_energy("375.7 kJ/mol");
			case atom::Ba:
				return molar_energy("502.9 kJ/mol");
			case atom::La:
				return molar_energy("538.1 kJ/mol");
			case atom::Ce:
				return molar_energy("534.4 kJ/mol");
			case atom::Pr:
				return molar_energy("527 kJ/mol");
			case atom::Nd:
				return molar_energy("533.1 kJ/mol");
			case atom::Pm:
				return molar_energy("540 kJ/mol");
			case atom::Sm:
				return molar_energy("544.5 kJ/mol");
			case atom::Eu:
				return molar_energy("547.1 kJ/mol");
			case atom::Gd:
				return molar_energy("593.4 kJ/mol");
			case atom::Tb:
				return molar_energy("565.8 kJ/mol");
			case atom::Dy:
				return molar_energy("573.0 kJ/mol");
			case atom::Ho:
				return molar_energy("581.0 kJ/mol");
			case atom::Er:
				return molar_energy("589.3 kJ/mol");
			case atom::Tm:
				return molar_energy("596.7 kJ/mol");
			case atom::Yb:
				return molar_energy("603.4 kJ/mol");
			case atom::Lu:
				return molar_energy("523.5 kJ/mol");
			case atom::Hf:
				return molar_energy("658.5 kJ/mol");
			case atom::Ta:
				return molar_energy("761 kJ/mol");
			case atom::W:
				return molar_energy("770 kJ/mol");
			case atom::Re:
				return molar_energy("760 kJ/mol");
			case atom::Os:
				return molar_energy("840 kJ/mol");
			case atom::Ir:
				return molar_energy("880 kJ/mol");
			case atom::Pt:
				return molar_energy("870 kJ/mol");
			case atom::Au:
				return molar_energy("890.1 kJ/mol");
			case atom::Hg:
				return molar_energy("1007.1 kJ/mol");
			case atom::Tl:
				return molar_energy("589.4 kJ/mol");
			case atom::Pb:
				return molar_energy("715.6 kJ/mol");
			case atom::Bi:
				return molar_energy("703 kJ/mol");
			case atom::Po:
				return molar_energy("812.1 kJ/mol");
			case atom::At:
				return molar_energy("899.003 kJ/mol");
			case atom::Rn:
				return molar_energy("1037 kJ/mol");
			case atom::Fr:
				return molar_energy("393 kJ/mol");
			case atom::Ra:
				return molar_energy("509.3 kJ/mol");
			case atom::Ac:
				return molar_energy("499 kJ/mol");
			case atom::Th:
				return molar_energy("587 kJ/mol");
			case atom::Pa:
				return molar_energy("568 kJ/mol");
			case atom::U:
				return molar_energy("597.6 kJ/mol");
			case atom::Np:
				return molar_energy("604.5 kJ/mol");
			case atom::Pu:
				return molar_energy("584.7 kJ/mol");
			case atom::Am:
				return molar_energy("578 kJ/mol");
			case atom::Cm:
				return molar_energy("581 kJ/mol");
			case atom::Bk:
				return molar_energy("601 kJ/mol");
			case atom::Cf:
				return molar_energy("608 kJ/mol");
			case atom::Es:
				return molar_energy("619 kJ/mol");
			case atom::Fm:
				return molar_energy("627 kJ/mol");
			case atom::Md:
				return molar_energy("635 kJ/mol");
			case atom::No:
				return molar_energy("641.6 kJ/mol");
			case atom::Lr:
				return molar_energy("478.6 kJ/mol");
			case atom::Rf:
				return molar_energy("579.9 kJ/mol");
			case atom::Db:
				return molar_energy("656.1 kJ/mol");
			case atom::Sg:
				return molar_energy("752.6 kJ/mol");
			case atom::Bh:
				return molar_energy("742.9 kJ/mol");
			case atom::Hs:
				return molar_energy("733.3 kJ/mol");
			case atom::Mt:
				return molar_energy("800.8 kJ/mol");
			case atom::Ds:
				return molar_energy("955.2 kJ/mol");
			case atom::Rg:
				return molar_energy("1022.7 kJ/mol");
			case atom::Cn:
				return molar_energy("1154.9 kJ/mol");
			case atom::Nh:
				return molar_energy("704.9 kJ/mol");
			case atom::Fl:
				return molar_energy("823.9 kJ/mol");
			case atom::Mc:
				return molar_energy("538.4 kJ/mol");
			case atom::Lv:
				return molar_energy("723.6 kJ/mol");
			case atom::Ts:
				return molar_energy("742.9 kJ/mol");
			case atom::Og:
				return molar_energy("839.4 kJ/mol");
		}
		return molar_energy();
	}

	length atom::get_covalent_radius() const
	{
		switch (species)
		{
			case atom::H:
				return 31_pm;
			case atom::D:
				return 31_pm;
			case atom::T:
				return 31_pm;
			case atom::He:
				return 28_pm;
			case atom::Li:
				return 128_pm;
			case atom::Be:
				return 96_pm;
			case atom::B:
				return 84_pm;
			case atom::C:
				return 69_pm;
			case atom::N:
				return 71_pm;
			case atom::O:
				return 66_pm;
			case atom::F:
				return 64_pm;
			case atom::Ne:
				return 58_pm;
			case atom::Na:
				return 166_pm;
			case atom::Mg:
				return 141_pm;
			case atom::Al:
				return 121_pm;
			case atom::Si:
				return 111_pm;
			case atom::P:
				return 107_pm;
			case atom::S:
				return 105_pm;
			case atom::Cl:
				return 102_pm;
			case atom::Ar:
				return 106_pm;
			case atom::K:
				return 203_pm;
			case atom::Ca:
				return 176_pm;
			case atom::Sc:
				return 170_pm;
			case atom::Ti:
				return 160_pm;
			case atom::V:
				return 153_pm;
			case atom::Cr:
				return 139_pm;
			case atom::Mn:
				return 139_pm;
			case atom::Fe:
				return 132_pm;
			case atom::Co:
				return 126_pm;
			case atom::Ni:
				return 124_pm;
			case atom::Cu:
				return 132_pm;
			case atom::Zn:
				return 122_pm;
			case atom::Ga:
				return 122_pm;
			case atom::Ge:
				return 122_pm;
			case atom::As:
				return 119_pm;
			case atom::Se:
				return 120_pm;
			case atom::Br:
				return 120_pm;
			case atom::Kr:
				return 116_pm;
			case atom::Rb:
				return 220_pm;
			case atom::Sr:
				return 195_pm;
			case atom::Y:
				return 190_pm;
			case atom::Zr:
				return 175_pm;
			case atom::Nb:
				return 164_pm;
			case atom::Mo:
				return 154_pm;
			case atom::Tc:
				return 147_pm;
			case atom::Ru:
				return 146_pm;
			case atom::Rh:
				return 142_pm;
			case atom::Pd:
				return 139_pm;
			case atom::Ag:
				return 145_pm;
			case atom::Cd:
				return 144_pm;
			case atom::In:
				return 142_pm;
			case atom::Sn:
				return 139_pm;
			case atom::Sb:
				return 139_pm;
			case atom::Te:
				return 138_pm;
			case atom::I:
				return 139_pm;
			case atom::Xe:
				return 140_pm;
			case atom::Cs:
				return 244_pm;
			case atom::Ba:
				return 215_pm;
			case atom::La:
				return 207_pm;
			case atom::Ce:
				return 204_pm;
			case atom::Pr:
				return 203_pm;
			case atom::Nd:
				return 201_pm;
			case atom::Pm:
				return 199_pm;
			case atom::Sm:
				return 198_pm;
			case atom::Eu:
				return 198_pm;
			case atom::Gd:
				return 196_pm;
			case atom::Tb:
				return 194_pm;
			case atom::Dy:
				return 192_pm;
			case atom::Ho:
				return 192_pm;
			case atom::Er:
				return 189_pm;
			case atom::Tm:
				return 190_pm;
			case atom::Yb:
				return 187_pm;
			case atom::Lu:
				return 187_pm;
			case atom::Hf:
				return 175_pm;
			case atom::Ta:
				return 170_pm;
			case atom::W:
				return 162_pm;
			case atom::Re:
				return 151_pm;
			case atom::Os:
				return 144_pm;
			case atom::Ir:
				return 141_pm;
			case atom::Pt:
				return 136_pm;
			case atom::Au:
				return 136_pm;
			case atom::Hg:
				return 132_pm;
			case atom::Tl:
				return 145_pm;
			case atom::Pb:
				return 146_pm;
			case atom::Bi:
				return 148_pm;
			case atom::Po:
				return 140_pm;
			case atom::At:
				return 150_pm;
			case atom::Rn:
				return 150_pm;
			case atom::Fr:
				return 260_pm;
			case atom::Ra:
				return 221_pm;
			case atom::Ac:
				return 215_pm;
			case atom::Th:
				return 206_pm;
			case atom::Pa:
				return 200_pm;
			case atom::U:
				return 196_pm;
			case atom::Np:
				return 190_pm;
			case atom::Pu:
				return 187_pm;
			case atom::Am:
				return 180_pm;
			case atom::Cm:
				return 169_pm;
			case atom::Bk:
				return 0_pm;
			case atom::Cf:
				return 0_pm;
			case atom::Es:
				return 0_pm;
			case atom::Fm:
				return 0_pm;
			case atom::Md:
				return 0_pm;
			case atom::No:
				return 0_pm;
			case atom::Lr:
				return 0_pm;
			case atom::Rf:
				return 157_pm;
			case atom::Db:
				return 149_pm;
			case atom::Sg:
				return 143_pm;
			case atom::Bh:
				return 141_pm;
			case atom::Hs:
				return 134_pm;
			case atom::Mt:
				return 129_pm;
			case atom::Ds:
				return 128_pm;
			case atom::Rg:
				return 121_pm;
			case atom::Cn:
				return 122_pm;
			case atom::Nh:
				return 180_pm;
			case atom::Fl:
				return 177_pm;
			case atom::Mc:
				return 156_pm;
			case atom::Lv:
				return 162_pm;
			case atom::Ts:
				return 156_pm;
			case atom::Og:
				return 157_pm;
		}
		return 0.0_pm;
	}

	length atom::get_van_der_waals_radius() const
	{
		switch (species)
		{
			case atom::H:
				return 120_pm;
			case atom::D:
				return 120_pm;
			case atom::T:
				return 120_pm;
			case atom::He:
				return 140_pm;
			case atom::Li:
				return 182_pm;
			case atom::Be:
				return 153_pm;
			case atom::B:
				return 192_pm;
			case atom::C:
				return 170_pm;
			case atom::N:
				return 155_pm;
			case atom::O:
				return 152_pm;
			case atom::F:
				return 135_pm;
			case atom::Ne:
				return 154_pm;
			case atom::Na:
				return 227_pm;
			case atom::Mg:
				return 173_pm;
			case atom::Al:
				return 184_pm;
			case atom::Si:
				return 210_pm;
			case atom::P:
				return 180_pm;
			case atom::S:
				return 180_pm;
			case atom::Cl:
				return 175_pm;
			case atom::Ar:
				return 188_pm;
			case atom::K:
				return 275_pm;
			case atom::Ca:
				return 231_pm;
			case atom::Sc:
				return 211_pm;
			case atom::Ti:
				return 0_pm;
			case atom::V:
				return 0_pm;
			case atom::Cr:
				return 0_pm;
			case atom::Mn:
				return 0_pm;
			case atom::Fe:
				return 0_pm;
			case atom::Co:
				return 0_pm;
			case atom::Ni:
				return 163_pm;
			case atom::Cu:
				return 140_pm;
			case atom::Zn:
				return 139_pm;
			case atom::Ga:
				return 187_pm;
			case atom::Ge:
				return 211_pm;
			case atom::As:
				return 185_pm;
			case atom::Se:
				return 190_pm;
			case atom::Br:
				return 185_pm;
			case atom::Kr:
				return 202_pm;
			case atom::Rb:
				return 303_pm;
			case atom::Sr:
				return 249_pm;
			case atom::Y:
				return 0_pm;
			case atom::Zr:
				return 0_pm;
			case atom::Nb:
				return 0_pm;
			case atom::Mo:
				return 0_pm;
			case atom::Tc:
				return 0_pm;
			case atom::Ru:
				return 0_pm;
			case atom::Rh:
				return 0_pm;
			case atom::Pd:
				return 163_pm;
			case atom::Ag:
				return 172_pm;
			case atom::Cd:
				return 158_pm;
			case atom::In:
				return 193_pm;
			case atom::Sn:
				return 217_pm;
			case atom::Sb:
				return 206_pm;
			case atom::Te:
				return 206_pm;
			case atom::I:
				return 198_pm;
			case atom::Xe:
				return 216_pm;
			case atom::Cs:
				return 343_pm;
			case atom::Ba:
				return 268_pm;
			case atom::La:
				return 0_pm;
			case atom::Ce:
				return 0_pm;
			case atom::Pr:
				return 0_pm;
			case atom::Nd:
				return 0_pm;
			case atom::Pm:
				return 0_pm;
			case atom::Sm:
				return 0_pm;
			case atom::Eu:
				return 0_pm;
			case atom::Gd:
				return 0_pm;
			case atom::Tb:
				return 0_pm;
			case atom::Dy:
				return 0_pm;
			case atom::Ho:
				return 0_pm;
			case atom::Er:
				return 0_pm;
			case atom::Tm:
				return 0_pm;
			case atom::Yb:
				return 0_pm;
			case atom::Lu:
				return 0_pm;
			case atom::Hf:
				return 0_pm;
			case atom::Ta:
				return 0_pm;
			case atom::W:
				return 0_pm;
			case atom::Re:
				return 0_pm;
			case atom::Os:
				return 0_pm;
			case atom::Ir:
				return 0_pm;
			case atom::Pt:
				return 175_pm;
			case atom::Au:
				return 166_pm;
			case atom::Hg:
				return 155_pm;
			case atom::Tl:
				return 196_pm;
			case atom::Pb:
				return 202_pm;
			case atom::Bi:
				return 207_pm;
			case atom::Po:
				return 197_pm;
			case atom::At:
				return 202_pm;
			case atom::Rn:
				return 220_pm;
			case atom::Fr:
				return 348_pm;
			case atom::Ra:
				return 283_pm;
			case atom::Ac:
				return 0_pm;
			case atom::Th:
				return 0_pm;
			case atom::Pa:
				return 0_pm;
			case atom::U:
				return 186_pm;
			case atom::Np:
				return 0_pm;
			case atom::Pu:
				return 0_pm;
			case atom::Am:
				return 0_pm;
			case atom::Cm:
				return 0_pm;
			case atom::Bk:
				return 0_pm;
			case atom::Cf:
				return 0_pm;
			case atom::Es:
				return 0_pm;
			case atom::Fm:
				return 0_pm;
			case atom::Md:
				return 0_pm;
			case atom::No:
				return 0_pm;
			case atom::Lr:
				return 0_pm;
			case atom::Rf:
				return 0_pm;
			case atom::Db:
				return 0_pm;
			case atom::Sg:
				return 0_pm;
			case atom::Bh:
				return 0_pm;
			case atom::Hs:
				return 0_pm;
			case atom::Mt:
				return 0_pm;
			case atom::Ds:
				return 0_pm;
			case atom::Rg:
				return 0_pm;
			case atom::Cn:
				return 0_pm;
			case atom::Nh:
				return 0_pm;
			case atom::Fl:
				return 0_pm;
			case atom::Mc:
				return 0_pm;
			case atom::Lv:
				return 0_pm;
			case atom::Ts:
				return 0_pm;
			case atom::Og:
				return 0_pm;
		}
		return 0.0_pm;
	}

	/*cas_number atom::get_cas_number() const
	{
		switch (species)
		{
			case atom::H:
				return cas_number("12385-13-6");
			case atom::D:
				return cas_number("7782-39-0");
			case atom::T:
				return cas_number("10028-17-8");
			case atom::He:
				return cas_number("7440-59-7");
			case atom::Li:
				return cas_number("7439-93-2");
			case atom::Be:
				return cas_number("7440-41-7");
			case atom::B:
				return cas_number("7440-42-8");
			case atom::C:
				return cas_number("7440-44-0");
			case atom::N:
				return cas_number("17778-37-9");
			case atom::O:
				return cas_number("7782-44-7");
			case atom::F:
				return cas_number("7782-41-4");
			case atom::Ne:
				return cas_number("7440-01-9");
			case atom::Na:
				return cas_number("7440-23-5");
			case atom::Mg:
				return cas_number("7439-95-4");
			case atom::Al:
				return cas_number("7429-90-5");
			case atom::Si:
				return cas_number("7440-21-3");
			case atom::P:
				return cas_number("7723-14-0");
			case atom::S:
				return cas_number("7704-34-9");
			case atom::Cl:
				return cas_number("7782-50-5");
			case atom::Ar:
				return cas_number("7440-37-1");
			case atom::K:
				return cas_number("7440-09-7");
			case atom::Ca:
				return cas_number("7440-70-2");
			case atom::Sc:
				return cas_number("7440-20-2");
			case atom::Ti:
				return cas_number("7440-32-6");
			case atom::V:
				return cas_number("7440-62-2");
			case atom::Cr:
				return cas_number("7440-47-3");
			case atom::Mn:
				return cas_number("7439-96-5");
			case atom::Fe:
				return cas_number("7439-89-6");
			case atom::Co:
				return cas_number("7440-48-4");
			case atom::Ni:
				return cas_number("7440-02-0");
			case atom::Cu:
				return cas_number("7440-50-8");
			case atom::Zn:
				return cas_number("7440-66-6");
			case atom::Ga:
				return cas_number("7440-55-3");
			case atom::Ge:
				return cas_number("7440-56-4");
			case atom::As:
				return cas_number("7440-38-2");
			case atom::Se:
				return cas_number("7782-49-2");
			case atom::Br:
				return cas_number("7726-95-6");
			case atom::Kr:
				return cas_number("7439-90-9");
			case atom::Rb:
				return cas_number("7440-17-7");
			case atom::Sr:
				return cas_number("7440-24-6");
			case atom::Y:
				return cas_number("7440-65-5");
			case atom::Zr:
				return cas_number("7440-67-7");
			case atom::Nb:
				return cas_number("7440-03-1");
			case atom::Mo:
				return cas_number("7439-98-7");
			case atom::Tc:
				return cas_number("7440-26-8");
			case atom::Ru:
				return cas_number("7440-18-8");
			case atom::Rh:
				return cas_number("7440-16-6");
			case atom::Pd:
				return cas_number("7440-05-3");
			case atom::Ag:
				return cas_number("7440-22-4");
			case atom::Cd:
				return cas_number("7440-43-9");
			case atom::In:
				return cas_number("7440-74-6");
			case atom::Sn:
				return cas_number("7440-31-5");
			case atom::Sb:
				return cas_number("7440-36-0");
			case atom::Te:
				return cas_number("13494-80-9");
			case atom::I:
				return cas_number("7553-56-2");
			case atom::Xe:
				return cas_number("7440-63-3");
			case atom::Cs:
				return cas_number("7440-46-2");
			case atom::Ba:
				return cas_number("7440-39-3");
			case atom::La:
				return cas_number("7439-91-0");
			case atom::Ce:
				return cas_number("7440-45-1");
			case atom::Pr:
				return cas_number("7440-10-0");
			case atom::Nd:
				return cas_number("7440-00-8");
			case atom::Pm:
				return cas_number("7440-12-2");
			case atom::Sm:
				return cas_number("7440-19-9");
			case atom::Eu:
				return cas_number("7440-53-1");
			case atom::Gd:
				return cas_number("7440-54-2");
			case atom::Tb:
				return cas_number("7440-27-9");
			case atom::Dy:
				return cas_number("7429-91-6");
			case atom::Ho:
				return cas_number("7440-60-0");
			case atom::Er:
				return cas_number("7440-52-0");
			case atom::Tm:
				return cas_number("7440-30-4");
			case atom::Yb:
				return cas_number("7440-64-4");
			case atom::Lu:
				return cas_number("7439-94-3");
			case atom::Hf:
				return cas_number("7440-58-6");
			case atom::Ta:
				return cas_number("7440-25-7");
			case atom::W:
				return cas_number("7440-33-7");
			case atom::Re:
				return cas_number("7440-15-5");
			case atom::Os:
				return cas_number("7440-04-2");
			case atom::Ir:
				return cas_number("7439-88-5");
			case atom::Pt:
				return cas_number("7440-06-4");
			case atom::Au:
				return cas_number("7440-57-5");
			case atom::Hg:
				return cas_number("7439-97-6");
			case atom::Tl:
				return cas_number("7440-28-0");
			case atom::Pb:
				return cas_number("7439-92-1");
			case atom::Bi:
				return cas_number("7440-69-9");
			case atom::Po:
				return cas_number("7440-08-6");
			case atom::At:
				return cas_number("7440-68-8");
			case atom::Rn:
				return cas_number("10043-92-2");
			case atom::Fr:
				return cas_number("7440-73-5");
			case atom::Ra:
				return cas_number("7440-14-4");
			case atom::Ac:
				return cas_number("7440-34-8");
			case atom::Th:
				return cas_number("7440-29-1");
			case atom::Pa:
				return cas_number("7440-13-3");
			case atom::U:
				return cas_number("7440-61-1");
			case atom::Np:
				return cas_number("7439-99-8");
			case atom::Pu:
				return cas_number("7440-07-5");
			case atom::Am:
				return cas_number("7440-35-9");
			case atom::Cm:
				return cas_number("7440-51-9");
			case atom::Bk:
				return cas_number("7440-40-6");
			case atom::Cf:
				return cas_number("7440-71-3");
			case atom::Es:
				return cas_number("7429-92-7");
			case atom::Fm:
				return cas_number("7440-72-4");
			case atom::Md:
				return cas_number("7440-11-1");
			case atom::No:
				return cas_number("10028-14-5");
			case atom::Lr:
				return cas_number("22537-19-5");
			case atom::Rf:
				return cas_number("53850-36-5");
			case atom::Db:
				return cas_number("53850-35-4");
			case atom::Sg:
				return cas_number("54038-81-2");
			case atom::Bh:
				return cas_number("54037-14-8");
			case atom::Hs:
				return cas_number("54037-57-9");
			case atom::Mt:
				return cas_number("54038-01-6");
			case atom::Ds:
				return cas_number("54083-77-1");
			case atom::Rg:
				return cas_number("54386-24-2");
			case atom::Cn:
				return cas_number("54084-26-3");
			case atom::Nh:
				return cas_number("54084-70-7");
			case atom::Fl:
				return cas_number("54085-16-4");
			case atom::Mc:
				return cas_number("54085-64-2");
			case atom::Lv:
				return cas_number("54100-71-9");
			case atom::Ts:
				return cas_number("54101-14-3");
			case atom::Og:
				return cas_number("54144-19-3");
		}
		return cas_number();
	}*/

	bool atom::is_factible() const
	{
		if (get_ionic_charge() > get_z())
		{
			return false;
		}
		if (atom::is_atomic_group_a())
		{
			if (atom::is_atom_specimen(atom::H) or atom::is_atom_specimen(atom::He))
			{
				if ((get_ionic_charge() < 0) and (std::abs(get_ionic_charge()) > (2 - get_z())))
				{
					return false;
				}
			}
			else
			{
				if ((get_ionic_charge() < 0) and (std::abs(get_ionic_charge()) > (8 - get_z())))
				{
					return false;
				}
			}
		}
		return true;
	}

	int atom::get_ionic_charge() const
	{
		atom::atomic_group x_atomic_group = get_atomic_group();
		switch (x_atomic_group)
		{
			case atom::IA:
				return 1 + charge;
			case atom::IIA:
				return 2 + charge;
			case atom::IIIA:
				return 3 + charge;
			case atom::IVA:
				return 4 + charge;
			case atom::VA:
				return -3 + charge;
			case atom::VIA:
				return -2 + charge;
			case atom::VIIA:
				return -1 + charge;
			case atom::VIIIA:
				return 0 + charge;
			default:
				return 0 + charge;
		}
		return 0 + charge;
	}

	int atom::get_electrons_number() const
	{
		return get_z() - charge;
	}

	vector<atom::orbital_configuration> atom::get_electronic_configuration() const
	{
		int electrons_number = get_electrons_number();
		int total_electrons = 0;
		vector<atom::orbital_configuration> electronic_configuration = vector<atom::orbital_configuration>();
		for (const auto& x_orbital_configuration : atom::electronic_configuration)
		{
			if ((total_electrons + x_orbital_configuration.electrons) <= electrons_number)
			{
				electronic_configuration.push_back(x_orbital_configuration);
				total_electrons += x_orbital_configuration.electrons;
				if (total_electrons == electrons_number)
				{
					break;
				}
			}
			else
			{
				int pending_electrons = electrons_number - total_electrons;
				atom::orbital_configuration x_configuration = orbital_configuration(x_orbital_configuration.period,x_orbital_configuration.orbital_type,pending_electrons);
				electronic_configuration.push_back(x_configuration);
				break;
			}
		}
		return electronic_configuration;
	}

	string atom::display_electronic_configuration() const
	{
		ostringstream out;
		vector<atom::orbital_configuration> electronic_configuration = get_electronic_configuration();
		for (const auto& x : electronic_configuration)
		{
			out << x.display() << " ";
		}
		return out.str();
	}

	int atom::get_lone_pairs() const
	{
		return (get_valence_number() - charge) / 2;
	}

	mass atom::get_real_mass() const
	{
		return mass(get_z() * scifir::proton_mass + get_mass_number() * scifir::neutron_mass);
	}

	mass atom::get_electrons_mass() const
	{
		return mass(get_electrons_number() * scifir::electron_mass);
	}

	bool atom::is_exotic() const
	{
		return false;
	}

	scifir::color atom::get_atomic_color() const
    {
		if (get_z() == 1)
		{
			return scifir::color(239,239,239);
		}
		switch(get_atomic_group())
		{
			case IA:
				return scifir::color(244,212,66);
			case IIA:
				return scifir::color(244,128,66);
			case IIIA:
				return scifir::color(66,197,244);
			case IVA:
				return scifir::color(40,40,40);
			case VA:
				return scifir::color(43,145,79);
			case VIA:
				return scifir::color(244,66,66);
			case VIIA:
				return scifir::color(244,66,220);
		}
		return scifir::color(70,70,70);
    }

	atomic_drawing atom::get_atomic_pattern() const
	{
		switch(get_period())
		{
		case 1:
			return atomic_drawing::NONE;
		case 2:
			return atomic_drawing::NONE;
		case 3:
			return atomic_drawing::LINE;
		case 4:
			return atomic_drawing::PREPICATED_LINE;
		case 5:
			return atomic_drawing::WAVE_LINE;
		case 6:
			return atomic_drawing::PREPICATED_WAVE_LINE;
		case 7:
			return atomic_drawing::CIRCLES;
		}
		return atomic_drawing::NONE;
	}

	molecular_geometry atom::get_molecular_geometry(int bonds_number) const
	{
		// Check number of bonds and of unpaired electrons
		if (bonds_number == 2)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::LINEAR;
			}
			else if(get_lone_pairs() == 1)
			{
				return molecular_geometry::BENT;
			}
			else if(get_lone_pairs() == 2)
			{
				return molecular_geometry::BENT;
			}
			else if(get_lone_pairs() == 3)
			{
				return molecular_geometry::LINEAR;
			}
		}
		else if(bonds_number == 3)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::TRIGONAL_PLANAR;
			}
			else if(get_lone_pairs() == 1)
			{
				return molecular_geometry::TRIGONAL_PYRAMIDAL;
			}
			else if(get_lone_pairs() == 2)
			{
				return molecular_geometry::T_SHAPED;
			}
		}
		else if(bonds_number == 4)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::TETRAHEDRAL;
			}
			else if(get_lone_pairs() == 1)
			{
				return molecular_geometry::SEESAW;
			}
			else if(get_lone_pairs() == 2)
			{
				return molecular_geometry::SQUARE_PLANAR;
			}
		}
		else if(bonds_number == 5)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::TRIGONAL_BIPYRAMIDAL;
			}
			else if(get_lone_pairs() == 1)
			{
				return molecular_geometry::SQUARE_PYRAMIDAL;
			}
			else if(get_lone_pairs() == 2)
			{
				return molecular_geometry::PLANAR_PENTAGONAL;
			}
		}
		else if(bonds_number == 6)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::OCTAHEDRAL;
			}
			else if(get_lone_pairs() == 1)
			{
				return molecular_geometry::PENTAGONAL_PYRAMIDAL;
			}
		}
		else if(bonds_number == 7)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::PENTAGONAL_BIPYRAMIDAL;
			}
		}
		else if(bonds_number == 8)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::SQUARE_ANTIPRISTAMIC;
			}
		}
		else if(bonds_number == 9)
		{
			if(get_lone_pairs() == 0)
			{
				return molecular_geometry::TRICAPPED_TRIGONAL_PRISMATIC;
			}
		}
		return molecular_geometry::NONE;
	}

	bool atom::is_valence_full() const
	{
		if(is_atomic_group_a())
		{
			if((get_z() == 1 or get_z() == 2) and get_valence_electrons_number() == 2)
			{
				return true;
			}
			else if(get_valence_electrons_number() == 8)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}

	bool atom::is_chiral() const
	{
		return true;
	}

	string atom::save() const
	{
		ostringstream output;
		output << get_symbol();
		if (is_uncommon_isotope())
		{
			output << "[" << neutrons << "]";
		}
		return output.str();
	}

	scifir::angle get_molecular_geometry_angle(const atom& x,molecular_geometry_position position1,molecular_geometry_position position2)
	{
		switch (x.get_molecular_geometry(1))
		{
			case molecular_geometry::LINEAR:
				return scifir::angle(180.0f);
			case molecular_geometry::BENT:
				if (x.get_lone_pairs() == 1)
				{
					return scifir::angle(120.0f);
				}
				else if(x.get_lone_pairs() == 2)
				{
					return scifir::angle(109.5);
				}
			case molecular_geometry::TRIGONAL_PLANAR:
				return scifir::angle(120.0f);
			case molecular_geometry::TRIGONAL_PYRAMIDAL:
				return scifir::angle(109.5);
			case molecular_geometry::T_SHAPED:
				if ((position1 == molecular_geometry_position::T_SHAPED_AX and position2 == molecular_geometry_position::T_SHAPED_EQ) or (position1 == molecular_geometry_position::T_SHAPED_EQ and position2 == molecular_geometry_position::T_SHAPED_AX))
				{
					return scifir::angle(90.0f);
				}
				else if (position1 == molecular_geometry_position::T_SHAPED_AX and position2 == molecular_geometry_position::T_SHAPED_AX)
				{
					return scifir::angle(180.0f);
				}
			case molecular_geometry::TETRAHEDRAL:
				return scifir::angle(109.5);
			case molecular_geometry::SEESAW:
				if (position1 == molecular_geometry_position::SEESAW_AX and position2 == molecular_geometry_position::SEESAW_AX)
				{
					return scifir::angle(173.1f);
				}
				else if (position1 == molecular_geometry_position::SEESAW_EQ and position2 == molecular_geometry_position::SEESAW_EQ)
				{
					return scifir::angle(101.6f);
				}
				else if ((position1 == molecular_geometry_position::SEESAW_AX and position2 == molecular_geometry_position::SEESAW_EQ) or (position2 == molecular_geometry_position::SEESAW_AX and position1 == molecular_geometry_position::SEESAW_EQ))
				{
					return scifir::angle(90.0f);
				}
			case molecular_geometry::SQUARE_PLANAR:
				return scifir::angle(90.0f);
			case molecular_geometry::TRIGONAL_BIPYRAMIDAL:
				if (position1 == molecular_geometry_position::TRIGONAL_BIPYRAMIDAL_AX and position2 == molecular_geometry_position::TRIGONAL_BIPYRAMIDAL_AX)
				{
					return scifir::angle(180.0f);
				}
				else if ((position1 == molecular_geometry_position::TRIGONAL_BIPYRAMIDAL_AX and position2 == molecular_geometry_position::TRIGONAL_BIPYRAMIDAL_EQ) or (position1 == molecular_geometry_position::TRIGONAL_BIPYRAMIDAL_EQ and position2 == molecular_geometry_position::TRIGONAL_BIPYRAMIDAL_AX))
				{
					return scifir::angle(90.0f);
				}
				else if (position1 == molecular_geometry_position::TRIGONAL_BIPYRAMIDAL_EQ and position2 == molecular_geometry_position::TRIGONAL_BIPYRAMIDAL_EQ)
				{
					return scifir::angle(120.0f);
				}
			case molecular_geometry::SQUARE_PYRAMIDAL:
				return scifir::angle(90.0f);
			case molecular_geometry::PLANAR_PENTAGONAL:
				return scifir::angle(72.0f);
			case molecular_geometry::OCTAHEDRAL:
				return scifir::angle(90.0f);
			case molecular_geometry::PENTAGONAL_PYRAMIDAL:
				if ((position1 == molecular_geometry_position::PENTAGONAL_PYRAMIDAL_AX and position2 == molecular_geometry_position::PENTAGONAL_PYRAMIDAL_EQ) or (position1 == molecular_geometry_position::PENTAGONAL_PYRAMIDAL_EQ and position2 == molecular_geometry_position::PENTAGONAL_PYRAMIDAL_AX))
				{
					return scifir::angle(90.0f);
				}
				else if (position1 == molecular_geometry_position::PENTAGONAL_PYRAMIDAL_EQ and position2 == molecular_geometry_position::PENTAGONAL_PYRAMIDAL_EQ)
				{
					return scifir::angle(72.0f);
				}
			case molecular_geometry::PENTAGONAL_BIPYRAMIDAL:
				if (position1 == molecular_geometry_position::PENTAGONAL_BIPYRAMIDAL_AX and position2 == molecular_geometry_position::PENTAGONAL_BIPYRAMIDAL_AX)
				{
					return scifir::angle(180.0f);
				}
				else if (position1 == molecular_geometry_position::PENTAGONAL_BIPYRAMIDAL_EQ and position2 == molecular_geometry_position::PENTAGONAL_BIPYRAMIDAL_EQ)
				{
					return scifir::angle(72.0f);
				}
				else if ((position1 == molecular_geometry_position::PENTAGONAL_BIPYRAMIDAL_AX and position2 == molecular_geometry_position::PENTAGONAL_BIPYRAMIDAL_EQ) or (position1 == molecular_geometry_position::PENTAGONAL_BIPYRAMIDAL_EQ and position2 == molecular_geometry_position::PENTAGONAL_BIPYRAMIDAL_AX))
				{
					return scifir::angle(90.0f);
				}
			case molecular_geometry::SQUARE_ANTIPRISTAMIC:
				return scifir::angle(50.0f);
			case molecular_geometry::TRICAPPED_TRIGONAL_PRISMATIC:
				return scifir::angle(50.0f);
		}
		return scifir::angle(180.0f);
	}

	bool are_isotopes(const atom& x,const atom& y)
	{
		return (x.get_z() == y.get_z() and x.get_mass_number() != y.get_mass_number());
	}

	bool are_isobares(const atom& x,const atom& y)
	{
		return (x.get_mass_number() == y.get_mass_number() and x.get_z() != y.get_z());
	}

	bool are_isoelectronics(const atom& x,const atom& y)
	{
		return (x.display_electronic_configuration() == y.display_electronic_configuration());
	}

	bool same_element(const atom& x,const atom& y)
	{
		return (x.get_z() == y.get_z() and x.get_mass_number() == y.get_mass_number());
	}

	bool same_specimen(const atom& x,const atom& y)
	{
		return (x.get_species() == y.get_species());
	}

	string to_string(const atom::atomic_species& x)
	{
		switch (x)
		{
			case atom::H:
				return "H";
			case atom::D:
				return "D";
			case atom::T:
				return "T";
			case atom::He:
				return "He";
			case atom::Li:
				return "Li";
			case atom::Be:
				return "Be";
			case atom::B:
				return "B";
			case atom::C:
				return "C";
			case atom::N:
				return "N";
			case atom::O:
				return "O";
			case atom::F:
				return "F";
			case atom::Ne:
				return "Ne";
			case atom::Na:
				return "Na";
			case atom::Mg:
				return "Mg";
			case atom::Al:
				return "Al";
			case atom::Si:
				return "Si";
			case atom::P:
				return "P";
			case atom::S:
				return "S";
			case atom::Cl:
				return "Cl";
			case atom::Ar:
				return "Ar";
			case atom::K:
				return "K";
			case atom::Ca:
				return "Ca";
			case atom::Sc:
				return "Sc";
			case atom::Ti:
				return "Ti";
			case atom::V:
				return "V";
			case atom::Cr:
				return "Cr";
			case atom::Mn:
				return "Mn";
			case atom::Fe:
				return "Fe";
			case atom::Co:
				return "Co";
			case atom::Ni:
				return "Ni";
			case atom::Cu:
				return "Cu";
			case atom::Zn:
				return "Zn";
			case atom::Ga:
				return "Ga";
			case atom::Ge:
				return "Ge";
			case atom::As:
				return "As";
			case atom::Se:
				return "Se";
			case atom::Br:
				return "Br";
			case atom::Kr:
				return "Kr";
			case atom::Rb:
				return "Rb";
			case atom::Sr:
				return "Sr";
			case atom::Y:
				return "Y";
			case atom::Zr:
				return "Zr";
			case atom::Nb:
				return "Nb";
			case atom::Mo:
				return "Mo";
			case atom::Tc:
				return "Tc";
			case atom::Ru:
				return "Ru";
			case atom::Rh:
				return "Rh";
			case atom::Pd:
				return "Pd";
			case atom::Ag:
				return "Ag";
			case atom::Cd:
				return "Cd";
			case atom::In:
				return "In";
			case atom::Sn:
				return "Sn";
			case atom::Sb:
				return "Sb";
			case atom::Te:
				return "Te";
			case atom::I:
				return "I";
			case atom::Xe:
				return "Xe";
			case atom::Cs:
				return "Cs";
			case atom::Ba:
				return "Ba";
			case atom::La:
				return "La";
			case atom::Ce:
				return "Ce";
			case atom::Pr:
				return "Pr";
			case atom::Nd:
				return "Nd";
			case atom::Pm:
				return "Pm";
			case atom::Sm:
				return "Sm";
			case atom::Eu:
				return "Eu";
			case atom::Gd:
				return "Gd";
			case atom::Tb:
				return "Tb";
			case atom::Dy:
				return "Dy";
			case atom::Ho:
				return "Ho";
			case atom::Er:
				return "Er";
			case atom::Tm:
				return "Tm";
			case atom::Yb:
				return "Yb";
			case atom::Lu:
				return "Lu";
			case atom::Hf:
				return "Hf";
			case atom::Ta:
				return "Ta";
			case atom::W:
				return "W";
			case atom::Re:
				return "Re";
			case atom::Os:
				return "Os";
			case atom::Ir:
				return "Ir";
			case atom::Pt:
				return "Pt";
			case atom::Au:
				return "Au";
			case atom::Hg:
				return "Hg";
			case atom::Tl:
				return "Tl";
			case atom::Pb:
				return "Pb";
			case atom::Bi:
				return "Bi";
			case atom::Po:
				return "Po";
			case atom::At:
				return "At";
			case atom::Rn:
				return "Rn";
			case atom::Fr:
				return "Fr";
			case atom::Ra:
				return "Ra";
			case atom::Ac:
				return "Ac";
			case atom::Th:
				return "Th";
			case atom::Pa:
				return "Pa";
			case atom::U:
				return "U";
			case atom::Np:
				return "Np";
			case atom::Pu:
				return "Pu";
			case atom::Am:
				return "Am";
			case atom::Cm:
				return "Cm";
			case atom::Bk:
				return "Bk";
			case atom::Cf:
				return "Cf";
			case atom::Es:
				return "Es";
			case atom::Fm:
				return "Fm";
			case atom::Md:
				return "Md";
			case atom::No:
				return "No";
			case atom::Lr:
				return "Lr";
			case atom::Rf:
				return "Rf";
			case atom::Db:
				return "Db";
			case atom::Sg:
				return "Sg";
			case atom::Bh:
				return "Bh";
			case atom::Hs:
				return "Hs";
			case atom::Mt:
				return "Mt";
			case atom::Ds:
				return "Ds";
			case atom::Rg:
				return "Rg";
			case atom::Cn:
				return "Cn";
			case atom::Nh:
				return "Nh";
			case atom::Fl:
				return "Fl";
			case atom::Mc:
				return "Mc";
			case atom::Lv:
				return "Lv";
			case atom::Ts:
				return "Ts";
			case atom::Og:
				return "Og";
		}
		return "";
	}

	string to_string(const atom::atomic_group& x)
	{
		switch (x)
		{
			case atom::IA:
				return "IA";
			case atom::IIA:
				return "IIA";
			case atom::IIIA:
				return "IIIA";
			case atom::IVA:
				return "IVA";
			case atom::VA:
				return "VA";
			case atom::VIA:
				return "VIA";
			case atom::VIIA:
				return "VIIA";
			case atom::VIIIA:
				return "VIIIA";
			case atom::IB:
				return "IB";
			case atom::IIB:
				return "IIB";
			case atom::IIIB:
				return "IIIB";
			case atom::IVB:
				return "IVB";
			case atom::VB:
				return "VB";
			case atom::VIB:
				return "VIB";
			case atom::VIIB:
				return "VIIB";
			case atom::VIIIB:
				return "VIIIB";
			case atom::AC:
				return "AC";
			case atom::LA:
				return "LA";
			case atom::NO_GROUP:
				return "NO_GROUP";
		}
		return "NO_GROUP";
	}

	string to_string(const atomic_block& x)
	{
		switch (x)
		{
			case atomic_block::s:
				return "s";
			case atomic_block::p:
				return "p";
			case atomic_block::d:
				return "d";
			case atomic_block::f:
				return "f";
		}
		return "";
	}

	string to_string(const orbital::type x)
	{
		switch (x)
		{
			case orbital::s:
				return "s";
			case orbital::p:
				return "p";
			case orbital::d:
				return "d";
			case orbital::f:
				return "f";
		}
		return "";
	}

	atom::atomic_species create_atomic_species(const string& x)
	{
		if (x == "NO_SPECIES")
		{
			return atom::NO_SPECIES;
		}
		else if (x == "H")
		{
			return atom::H;
		}
		else if (x == "D")
		{
			return atom::D;
		}
		else if (x == "T")
		{
			return atom::T;
		}
		else if (x == "He")
		{
			return atom::He;
		}
		else if (x == "Li")
		{
			return atom::Li;
		}
		else if (x == "Be")
		{
			return atom::Be;
		}
		else if (x == "B")
		{
			return atom::B;
		}
		else if (x == "C")
		{
			return atom::C;
		}
		else if (x == "N")
		{
			return atom::N;
		}
		else if (x == "O")
		{
			return atom::O;
		}
		else if (x == "F")
		{
			return atom::F;
		}
		else if (x == "Ne")
		{
			return atom::Ne;
		}
		else if (x == "Na")
		{
			return atom::Na;
		}
		else if (x == "Mg")
		{
			return atom::Mg;
		}
		else if (x == "Al")
		{
			return atom::Al;
		}
		else if (x == "Si")
		{
			return atom::Si;
		}
		else if (x == "P")
		{
			return atom::P;
		}
		else if (x == "S")
		{
			return atom::S;
		}
		else if (x == "Cl")
		{
			return atom::Cl;
		}
		else if (x == "Ar")
		{
			return atom::Ar;
		}
		else if (x == "K")
		{
			return atom::K;
		}
		else if (x == "Ca")
		{
			return atom::Ca;
		}
		else if (x == "Sc")
		{
			return atom::Sc;
		}
		else if (x == "Ti")
		{
			return atom::Ti;
		}
		else if (x == "V")
		{
			return atom::V;
		}
		else if (x == "Cr")
		{
			return atom::Cr;
		}
		else if (x == "Mn")
		{
			return atom::Mn;
		}
		else if (x == "Fe")
		{
			return atom::Fe;
		}
		else if (x == "Co")
		{
			return atom::Co;
		}
		else if (x == "Ni")
		{
			return atom::Ni;
		}
		else if (x == "Cu")
		{
			return atom::Cu;
		}
		else if (x == "Zn")
		{
			return atom::Zn;
		}
		else if (x == "Ga")
		{
			return atom::Ga;
		}
		else if (x == "Ge")
		{
			return atom::Ge;
		}
		else if (x == "As")
		{
			return atom::As;
		}
		else if (x == "Se")
		{
			return atom::Se;
		}
		else if (x == "Br")
		{
			return atom::Br;
		}
		else if (x == "Kr")
		{
			return atom::Kr;
		}
		else if (x == "Rb")
		{
			return atom::Rb;
		}
		else if (x == "Sr")
		{
			return atom::Sr;
		}
		else if (x == "Y")
		{
			return atom::Y;
		}
		else if (x == "Zr")
		{
			return atom::Zr;
		}
		else if (x == "Nb")
		{
			return atom::Nb;
		}
		else if (x == "Mo")
		{
			return atom::Mo;
		}
		else if (x == "Tc")
		{
			return atom::Tc;
		}
		else if (x == "Ru")
		{
			return atom::Ru;
		}
		else if (x == "Rh")
		{
			return atom::Rh;
		}
		else if (x == "Pd")
		{
			return atom::Pd;
		}
		else if (x == "Ag")
		{
			return atom::Ag;
		}
		else if (x == "Cd")
		{
			return atom::Cd;
		}
		else if (x == "In")
		{
			return atom::In;
		}
		else if (x == "Sn")
		{
			return atom::Sn;
		}
		else if (x == "Sb")
		{
			return atom::Sb;
		}
		else if (x == "Te")
		{
			return atom::Te;
		}
		else if (x == "I")
		{
			return atom::I;
		}
		else if (x == "Xe")
		{
			return atom::Xe;
		}
		else if (x == "Cs")
		{
			return atom::Cs;
		}
		else if (x == "Ba")
		{
			return atom::Ba;
		}
		else if (x == "La")
		{
			return atom::La;
		}
		else if (x == "Ce")
		{
			return atom::Ce;
		}
		else if (x == "Pr")
		{
			return atom::Pr;
		}
		else if (x == "Nd")
		{
			return atom::Nd;
		}
		else if (x == "Pm")
		{
			return atom::Pm;
		}
		else if (x == "Sm")
		{
			return atom::Sm;
		}
		else if (x == "Eu")
		{
			return atom::Eu;
		}
		else if (x == "Gd")
		{
			return atom::Gd;
		}
		else if (x == "Tb")
		{
			return atom::Tb;
		}
		else if (x == "Dy")
		{
			return atom::Dy;
		}
		else if (x == "Ho")
		{
			return atom::Ho;
		}
		else if (x == "Er")
		{
			return atom::Er;
		}
		else if (x == "Tm")
		{
			return atom::Tm;
		}
		else if (x == "Yb")
		{
			return atom::Yb;
		}
		else if (x == "Lu")
		{
			return atom::Lu;
		}
		else if (x == "Hf")
		{
			return atom::Hf;
		}
		else if (x == "Ta")
		{
			return atom::Ta;
		}
		else if (x == "W")
		{
			return atom::W;
		}
		else if (x == "Re")
		{
			return atom::Re;
		}
		else if (x == "Os")
		{
			return atom::Os;
		}
		else if (x == "Ir")
		{
			return atom::Ir;
		}
		else if (x == "Pt")
		{
			return atom::Pt;
		}
		else if (x == "Au")
		{
			return atom::Au;
		}
		else if (x == "Hg")
		{
			return atom::Hg;
		}
		else if (x == "Tl")
		{
			return atom::Tl;
		}
		else if (x == "Pb")
		{
			return atom::Pb;
		}
		else if (x == "Bi")
		{
			return atom::Bi;
		}
		else if (x == "Po")
		{
			return atom::Po;
		}
		else if (x == "At")
		{
			return atom::At;
		}
		else if (x == "Rn")
		{
			return atom::Rn;
		}
		else if (x == "Fr")
		{
			return atom::Fr;
		}
		else if (x == "Ra")
		{
			return atom::Ra;
		}
		else if (x == "Ac")
		{
			return atom::Ac;
		}
		else if (x == "Th")
		{
			return atom::Th;
		}
		else if (x == "Pa")
		{
			return atom::Pa;
		}
		else if (x == "U")
		{
			return atom::U;
		}
		else if (x == "Np")
		{
			return atom::Np;
		}
		else if (x == "Pu")
		{
			return atom::Pu;
		}
		else if (x == "Am")
		{
			return atom::Am;
		}
		else if (x == "Cm")
		{
			return atom::Cm;
		}
		else if (x == "Bk")
		{
			return atom::Bk;
		}
		else if (x == "Cf")
		{
			return atom::Cf;
		}
		else if (x == "Es")
		{
			return atom::Es;
		}
		else if (x == "Fm")
		{
			return atom::Fm;
		}
		else if (x == "Md")
		{
			return atom::Md;
		}
		else if (x == "No")
		{
			return atom::No;
		}
		else if (x == "Lr")
		{
			return atom::Lr;
		}
		else if (x == "Rf")
		{
			return atom::Rf;
		}
		else if (x == "Db")
		{
			return atom::Db;
		}
		else if (x == "Sg")
		{
			return atom::Sg;
		}
		else if (x == "Bh")
		{
			return atom::Bh;
		}
		else if (x == "Hs")
		{
			return atom::Hs;
		}
		else if (x == "Mt")
		{
			return atom::Mt;
		}
		else if (x == "Ds")
		{
			return atom::Ds;
		}
		else if (x == "Rg")
		{
			return atom::Rg;
		}
		else if (x == "Cn")
		{
			return atom::Cn;
		}
		else if (x == "Nh")
		{
			return atom::Nh;
		}
		else if (x == "Fl")
		{
			return atom::Fl;
		}
		else if (x == "Mc")
		{
			return atom::Mc;
		}
		else if (x == "Lv")
		{
			return atom::Lv;
		}
		else if (x == "Ts")
		{
			return atom::Ts;
		}
		else if (x == "Og")
		{
			return atom::Og;
		}
		return atom::NO_SPECIES;
	}
}

bool operator ==(const scifir::atom& x,const scifir::atom& y)
{
	return (x.get_z() == y.get_z() and x.get_mass_number() == y.get_mass_number() and scifir::are_isoelectronics(x,y));
}

bool operator !=(const scifir::atom& x,const scifir::atom& y)
{
	return !(x == y);
}

ostream& operator <<(ostream& os,const scifir::atom& x)
{
	ostringstream charge_text;
	if (x.get_ionic_charge() < 0)
	{
		charge_text << abs(x.get_ionic_charge()) << "-";
	}
	else if (x.get_ionic_charge() > 0)
	{
		charge_text << abs(x.get_ionic_charge()) << "+";
	}
	return os << x.get_symbol().c_str() << charge_text.str();
}
