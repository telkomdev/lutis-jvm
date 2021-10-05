cmake_minimum_required(VERSION 3.10)
# https://cmake.org/cmake/help/v3.0/policy/CMP0042.html
# cmake_policy(SET CMP0042 NEW)
set (CMAKE_CXX_STANDARD 14)

project (lutis)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/../src/main/resources)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(HEADER_FILES
    header/com_wuriyanto_lab_lutisjvm_Lutis.h
    header/Type.h
    header/Core.h
)

set(SOURCE_FILES
    src/Lutis.cc
)

# -------------------- JNI --------------------

find_package(JNI REQUIRED)

# -------------------- Image Magick --------------------
set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:${PROJECT_SOURCE_DIR}/vendor/image_magick/lib/pkgconfig")
set(ImageMagick_EXECUTABLE_DIR ${PROJECT_SOURCE_DIR}/vendor/image_magick/bin)
set(ImageMagick_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/vendor/image_magick/include/ImageMagick-7)
set(ImageMagick_LIBRARIES ${PROJECT_SOURCE_DIR}/vendor/image_magick/lib)

add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16 )
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0 )

find_package(ImageMagick REQUIRED COMPONENTS convert Magick++ MagickCore)
# -------------------- Image Magick --------------------

include_directories(${ImageMagick_INCLUDE_DIRS} ${JNI_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} -L${ImageMagick_LIBRARIES} ${JNI_LIBRARIES} )

MESSAGE( [Main] " PROJECT_NAME = ${PROJECT_NAME}")
MESSAGE( [Main] " CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
MESSAGE( [Main] " CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
MESSAGE( [Main] " PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
MESSAGE( [Main] " ImageMagick_FOUND = ${ImageMagick_FOUND}")
MESSAGE( [Main] " ImageMagick_INCLUDE_DIRS = ${ImageMagick_INCLUDE_DIRS}")
MESSAGE( [Main] " ImageMagick_LIBRARIES = ${ImageMagick_LIBRARIES}")
MESSAGE( [Main] " JNI_FOUND = ${JNI_FOUND}")
MESSAGE( [Main] " JNI_INCLUDE_DIRS = ${JNI_INCLUDE_DIRS}")
MESSAGE( [Main] " JNI_LIBRARIES = ${JNI_LIBRARIES}")