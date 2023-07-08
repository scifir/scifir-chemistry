cmake_minimum_required(VERSION 3.7.1)

include_directories(. /usr/local/include/scifir/units)
link_directories("${CMAKE_INSTALL_PREFIX}/lib")

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(TARGET_LOCAL_H
particles.hpp)

set(TARGET_H
analytical
atoms
molecules
biochemistry
particles
substances)

file(GLOB_RECURSE TARGET_SRC analytical/*.cpp atoms/*.cpp molecules/*.cpp biochemistry/*.cpp particles/*.cpp substances/*.cpp constants.cpp)

project(msci_chemistry)

add_library(msci_chemistry ${TARGET_SRC})
target_link_libraries(msci_chemistry boost_locale-mt boost_system-mt boost_thread-mt iconv scifir_units)

install(TARGETS msci_chemistry ARCHIVE DESTINATION lib)
install(FILES chemistry.hpp DESTINATION include/msci)
install(FILES ${TARGET_LOCAL_H} DESTINATION include/msci/chemistry)
install(DIRECTORY ${TARGET_H} DESTINATION include/msci/chemistry
	FILES_MATCHING PATTERN "*.hpp")
