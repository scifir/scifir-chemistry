cmake_minimum_required(VERSION 3.13.0)

cmake_policy(SET CMP0048 NEW) # This policy sets the VERSION variable with the project() command

project(scifir-chemistry VERSION 1.0.0 DESCRIPTION "scifir-chemistry is a library that provides atom, molecule and related classes to be used as normal types for scientific software, with units of measure coming from scifir-units included in all functions that are more precise with them." HOMEPAGE_URL "https://www.github.com/scifir/scifir-chemistry" LANGUAGES "CXX")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER_VERSION 13.2)

include(extra/FindLinuxDistribution.cmake)

if (DEFINED LINUX_LIBRARY_DIR)
	set(Boost_LIBRARY_DIR ${LINUX_LIBRARY_DIR})
endif()

if (NOT DEFINED LINUX_LIBRARY_DIR AND PLATFORM MATCHES "linux")
	set(CMAKE_LIBRARY_PATH "/usr/lib/*;/usr/lib;/usr/lib64")
endif()

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(BUILD_TESTING "Build test programs" OFF)
option(DEBUG_FLAGS "Add debug flags" OFF)
option(WARNING_FLAGS "Add warning flags" OFF)

if(DEBUG_FLAGS)
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Og")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /EHsc")
	endif()
	if(BUILD_TESTING AND (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage -lgcov")
	endif()
endif()

if(WARNING_FLAGS)
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall")
	endif()
endif()

if(DEFINED(${INCLUDE_PATH}))
	include_directories(${INCLUDE_PATH})
endif()
if(DEFINED(${LINK_PATH}))
	link_directories(${LINK_PATH})
endif()

set(Boost_NO_BOOST_CMAKE ON)
set(Boost_NO_SYSTEM_PATHS ON)
set(Boost_USE_DEBUG_LIBS        OFF)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.66.0 REQUIRED COMPONENTS system)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif()

if(!Boost_FOUND)
  message("Libraries of Boost not found, configure Boost_ variables properly and/or install Boost adequately. You can search the documentation of FindBoost, part of CMake, to learn the Boost_ variables to configure. Inside the README.md of scifir-units is also the explanation of how to configure Boost_ variables.")
endif()

find_package(ICU 72 COMPONENTS uc REQUIRED)

if(!ICU_FOUND)
	message("Library ICU not found, install it in your system first.")
endif()

set(TARGET_H
analytical
atoms
molecules
biochemistry
particles
substances)

file(GLOB_RECURSE TARGET_SRC analytical/*.cpp atoms/*.cpp molecules/*.cpp biochemistry/*.cpp particles/*.cpp substances/*.cpp constants.cpp)

add_library(scifir-chemistry ${TARGET_SRC})
target_link_libraries(scifir-chemistry scifir-units Boost::system ${ICU_LIBRARIES})

if(BUILD_TESTING)

	find_package(Catch2 CONFIG REQUIRED)

	if(!Catch2_FOUND)
		message("Catch2 not found, tests can't be build.")
	endif()

	if(Catch2_FOUND)
		enable_testing()
		
		add_executable(test_atomic_orbital tests/test_atomic_orbital.cpp)
		target_link_libraries(test_atomic_orbital PRIVATE Catch2::Catch2WithMain scifir-chemistry scifir-units Boost::system ${ICU_LIBRARIES})
		add_test(NAME test_atomic_orbital COMMAND test_atomic_orbital)
		set_tests_properties(test_atomic_orbital PROPERTIES LABELS tests)

		add_executable(test_atoms tests/test_atoms.cpp)
		target_link_libraries(test_atoms PRIVATE Catch2::Catch2WithMain scifir-chemistry scifir-units Boost::system ${ICU_LIBRARIES})
		add_test(NAME test_atoms COMMAND test_atoms)
		set_tests_properties(test_atoms PROPERTIES LABELS tests)

		add_executable(test_atomic_bond tests/test_atomic_bond.cpp)
		target_link_libraries(test_atomic_bond PRIVATE Catch2::Catch2WithMain scifir-chemistry scifir-units Boost::system ${ICU_LIBRARIES})
		add_test(NAME test_atomic_bond COMMAND test_atomic_bond)
		set_tests_properties(test_atomic_bond PROPERTIES LABELS tests)

		add_executable(test_molecule tests/test_molecule.cpp)
		target_link_libraries(test_molecule PRIVATE Catch2::Catch2WithMain scifir-chemistry scifir-units Boost::system ${ICU_LIBRARIES})
		add_test(NAME test_molecule COMMAND test_molecule)
		set_tests_properties(test_molecule PROPERTIES LABELS tests)

		include(CTest)
		include(Catch)
	endif()
endif()

install(TARGETS scifir-chemistry ARCHIVE DESTINATION lib)
install(FILES chemistry.hpp DESTINATION include/scifir)
install(DIRECTORY ${TARGET_H} DESTINATION include/scifir/chemistry
	FILES_MATCHING PATTERN "*.hpp")
