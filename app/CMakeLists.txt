cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/cpp/icu
                    src/main/cpp/icu/common
                    )

add_library( testmain SHARED src/main/cpp/native-lib.cpp )

add_library(testicuuc SHARED IMPORTED)
set_target_properties(testicuuc PROPERTIES IMPORTED_LOCATION ../../../../jniLibs/${ANDROID_ABI}/libtesticuuc.so)

find_library( log-lib log )

target_link_libraries( testmain ${log-lib} testicuuc )
