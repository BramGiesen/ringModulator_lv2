# ISC License
#
# Copyright (c) 2018 Jakob Dübel
#
# Permission to use, copy, modify, and/or distribute this software for
# any purpose with or without fee is hereby granted, provided that the
# above copyright notice and this permission notice appear in all
# copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
# WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
# AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
# DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA
# OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
# TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

cmake_minimum_required(VERSION 3.4.3)

# For versioning read https://semver.org/ and
# http://lv2plug.in/ns/lv2core/lv2core.html#minorVersion
project(ringModulator
    VERSION 0.1.0
    LANGUAGES CXX C)

set(LV2_URI_PREFIX https://github.com/BramGiesen/)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# LV2 dependency
find_package(LV2 REQUIRED)
include_directories(${LV2_INCLUDE_DIRS})

# LV2 bundle directory
set(LV2_BUNDLE_DIR "${PROJECT_NAME}.lv2")
add_custom_target(bundle
    COMMAND ${CMAKE_COMMAND} -E
        make_directory ${LV2_BUNDLE_DIR})

# Position independed code is set automatically
add_library(${PROJECT_NAME} MODULE
   src/audioProcess.h src/audioProcess.cpp)
add_dependencies(${PROJECT_NAME} bundle)
set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${LV2_BUNDLE_DIR})

configure_file(data/manifest.ttl.in ${PROJECT_BINARY_DIR}/${LV2_BUNDLE_DIR}/manifest.ttl)
configure_file(data/seealso.ttl.in ${PROJECT_BINARY_DIR}/${LV2_BUNDLE_DIR}/${PROJECT_NAME}.ttl)

install(DIRECTORY ${PROJECT_BINARY_DIR}/${LV2_BUNDLE_DIR} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/lv2)
