cmake_minimum_required(VERSION 2.8.8)

project("DataKeeper")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

include_directories(/usr/include/qt5)
include_directories(include)

QT5_WRAP_UI(UI_HDRS
    src/UI/MainWindow.ui
)

add_executable(DataKeeper 
  src/main.cpp
  include/GUI/MainWindow.h src/GUI/MainWindow.cpp

  include/Security/CryptoOpenSSL.h src/Security/CryptoOpenSSL.cpp
  include/Security/HexUtils.h src/Security/HexUtils.cpp

  include/Model/Note.h src/Model/Note.cpp
  include/Model/User.h src/Model/User.cpp

  # test/SecurityTest.cpp
  # test/SecurityStringToHex.cpp
  # test/SecurityAes.cpp

  ${UI_HDRS}
)

qt5_use_modules(DataKeeper Widgets)

find_package (Threads)
target_link_libraries(DataKeeper ${CMAKE_SOURCE_DIR}/lib/libgtest.a)
target_link_libraries(DataKeeper ${CMAKE_SOURCE_DIR}/lib/libgmock.a)
target_link_libraries(DataKeeper ${CMAKE_SOURCE_DIR}/lib/libcrypto.a)
target_link_libraries(DataKeeper dl)
target_link_libraries(DataKeeper ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(DataKeeper ${Qt5Widgets_LIBRARIES})

#install(TARGETS DataKeeper DESTINATION bin)

