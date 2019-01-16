cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp ClasesBases/File.cpp ClasesBases/File.h Aeropuerto/Avion.cpp Aeropuerto/Avion.h Aeropuerto/Vuelo.cpp Aeropuerto/Vuelo.h ClasesBases/Procesos.cpp ClasesBases/Procesos.h ClasesBases/Planificacion.cpp ClasesBases/Planificacion.h)