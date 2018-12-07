CMAKE_MINIMUM_REQUIRED( VERSION 3.10 )
PROJECT( redeye )

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig)
find_package(ImageMagick COMPONENTS MagickWand)

include_directories(${ImageMagick_INCLUDE_DIRS})

add_definitions(-DMAGICKCORE_HDRI_ENABLE=0)
add_definitions(-DMAGICKCORE_QUANTUM_DEPTH=16)

ADD_EXECUTABLE(redeye redeye.cc src/main_form.cc src/cbzfile.cc src/magickwand_image.cc)

TARGET_LINK_LIBRARIES(redeye fltk)
TARGET_LINK_LIBRARIES(redeye fltk_images)
TARGET_LINK_LIBRARIES(redeye zip)
TARGET_LINK_LIBRARIES(redeye ${ImageMagick_LIBRARIES})
