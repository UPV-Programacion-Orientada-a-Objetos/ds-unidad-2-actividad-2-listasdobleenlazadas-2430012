cmake_minimum_required(VERSION 3.10)
project(prt7_decoder)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Directorio de código fuente
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# Archivos fuente
set(SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/ListaDeCarga.cpp
    ${SRC_DIR}/RotorDeMapeo.cpp
)

# Archivos de encabezado (solo para claridad)
set(HEADERS
    ${SRC_DIR}/TramaBase.h
    ${SRC_DIR}/TramaLoad.h
    ${SRC_DIR}/TramaMap.h
    ${SRC_DIR}/ListaDeCarga.h
    ${SRC_DIR}/RotorDeMapeo.h
)

add_executable(prt7_decoder ${SOURCES} ${HEADERS})
