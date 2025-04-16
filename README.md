# scifir-chemistry

Welcome! scifir-chemistry is part of the scifir collection, a collection of scientific libraries to develop scientific inventions and scientific software. scifir-chemistry is yet in alpha stage, it's not finished and ready to be used widely, but it's useful for scifir-biology, and then it has been published because it already works with it without problems. Enjoy!

## Atoms and molecules

scifir-chemistry has atoms and molecules to use inside scientific software! It's under development, but a big amount is ready. It'll be completed in some months!

## Team

scifir-chemistry is developed by [Ismael Correa](https://github.com/Iarfen/), a software developer of 34 years old. You can email if you find bugs, request new features, or have any other need, at ismael.correa.castro@gmail.com.

## Core features

### About the SQLite database

The **sqlite database** is included with scifir-chemistry with the file **extra/scifir-chemistry-data**. That file is used by scifir-chemistry to obtain the data of molecules and substances that are not programmed directly inside the code because of being too many different values to be all contained inside the code. It's better to handle that case with a database, an sqlite is used for that. Use scifir-chemistry-data along the rest of scifir-chemistry for the same projects you program with scifir-chemistry.

### Molecules

The molecule class handles all molecules, and, also, any other, as defined by the IUPAC, **molecular entity**. So, although in general they represent molecules, a molecule object can represent a single atom, an ion, a radical, and any other related molecular entity. A molecule represents an atom when it contains no bonds and contains a single atom.

### Substance

The substance class handles all chemical substances, which can be any set of molecular entities with a defined amount of moles. So, a substance represents X moles of a given set of molecular entities. The difference between a substance an a mixture is that the mixture can be separated in different substances. Then, only non-separable molecular entities can conform a substance.

### Matter

The matter class handles any kind of matter in the universe. It can be any object, technology, life form, liquid, gas, or astronomical object present in the universe. To accomplish that, the matter class contains a set of substances, each of those forming part of the matter.

The types available for the matter class are the following:

- **substance:** A substance is any chemical substance that is not composed of parts separable by physical means.
- **mixture:** A mixture is composed of two or more substances.
- **artificial_object:** An artificial object is any object of artificial origin, created by humans or by another life form.
- **natural_object:** A natural object is an object whose origin is natural, it has been formed naturally with time.
- **organelle:** To describe life forms internally, an organelle is the first structure to define, it's composed of different mixtures and substances.
- **cell:** A cell is composed of organelles.
- **tissue:** A tissue if composed of cells.
- **organ:** An organ is composed of various tissues.
- **animal:** An animal.
- **plant:** A plant.
- **fungi:** A fungi.
- **microorganism:** A microorganism, can be any bacteria, virus, protist, or of any other type.
- **device:** A device is any electronic circuit with a component that has processing capabilities.
- **electronic_circuit:** Any electronic circuit that is not a device.
- **astronomical_object:** Any astronomical object, like planets and moons. All astronomical objects have to be classified with this type, they can be classified as **natural_object**.
- **astronomical_body:** Any astronomical body, like galaxies.

### References

- Functional groups: https://en.wikipedia.org/wiki/Functional_group