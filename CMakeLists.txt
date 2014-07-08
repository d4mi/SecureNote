cmake_minimum_required(VERSION 2.8)

project("DataKeeper")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") 

include_directories(include)
add_executable(DataKeeper 
  src/Security/CryptoOpenSSL.cpp
  src/Security/HexUtils.cpp
  test/SecurityTest.cpp
  test/SecurityStringToHex.cpp
  test/SecurityAes.cpp)

find_package (Threads)
target_link_libraries(DataKeeper ${CMAKE_SOURCE_DIR}/lib/libgtest.a)
target_link_libraries(DataKeeper ${CMAKE_SOURCE_DIR}/lib/libgmock.a)
target_link_libraries(DataKeeper ${CMAKE_SOURCE_DIR}/lib/libcrypto.a)
target_link_libraries(DataKeeper dl)
target_link_libraries(DataKeeper ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS DataKeeper DESTINATION bin)