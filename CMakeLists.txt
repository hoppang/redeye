CMAKE_MINIMUM_REQUIRED( VERSION 3.10 )
PROJECT( redeye )

find_package(ImageMagick COMPONENTS MagickWand)

include_directories(${ImageMagick_INCLUDE_DIRS})

add_definitions(-DMAGICKCORE_HDRI_ENABLE=0)
add_definitions(-DMAGICKCORE_QUANTUM_DEPTH=16)

ADD_EXECUTABLE(redeye redeye.cc src/main_form.cc src/cbzfile.cc src/magickwand_image.cc)

TARGET_LINK_LIBRARIES(redeye fltk)
TARGET_LINK_LIBRARIES(redeye fltk_images)
TARGET_LINK_LIBRARIES(redeye zip)
TARGET_LINK_LIBRARIES(redeye MagickWand-6.Q16)
TARGET_LINK_LIBRARIES(redeye MagickCore-6.Q16)
