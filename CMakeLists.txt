cmake_minimum_required(VERSION 3.13)
project(Simulatore)

set(CMAKE_C_STANDARD_99)

add_executable(Simulatore main.c ManageFile.c Atmosphere.c Atmosphere.h CI_utente.c CI_utente.h)