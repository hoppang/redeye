# CMAKE_MINIMUM_REQUIRED( VERSION 3.10 )
PROJECT( redeye )

ADD_EXECUTABLE( redeye redeye.cc src/main_form.cc src/cbzfile.cc )
TARGET_LINK_LIBRARIES(redeye fltk)
TARGET_LINK_LIBRARIES(redeye fltk_images)
TARGET_LINK_LIBRARIES(redeye zip)
