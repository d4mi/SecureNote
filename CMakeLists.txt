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
    src/UI/NoteForm.ui
    src/UI/NotesBrowser.ui
    src/UI/TopPanel.ui
    src/UI/MainAreaForm.ui
    src/UI/NotesBrowserForm.ui
    src/UI/CalendarForm.ui
    src/UI/PasswordNoteForm.ui
)

set( GUI_SRC
  include/GUI/MainWindow.h src/GUI/MainWindow.cpp
  include/GUI/NoteForm.h src/GUI/NoteForm.cpp
  include/GUI/StyleConfigurator.h src/GUI/StyleConfigurator.cpp
  include/GUI/TopPanel.h src/GUI/TopPanel.cpp
  include/GUI/MainAreaForm.h src/GUI/MainAreaForm.cpp
  include/GUI/NotesBrowserForm.h src/GUI/NotesBrowserForm.cpp
  include/GUI/CalendarForm.h src/GUI/CalendarForm.cpp
  include/GUI/PasswordNoteForm.h src/GUI/PasswordNoteForm.cpp
)

set( SECURITY_SRC
  include/Security/ICrypto.h
  include/Security/CryptoOpenSSL.h src/Security/CryptoOpenSSL.cpp
  include/Security/HexUtils.h src/Security/HexUtils.cpp
)

set( MODEL_SRC
  include/Model/Note.h src/Model/Note.cpp
  include/Model/User.h src/Model/User.cpp
  include/Model/PagePassword.h src/Model/PagePassword.cpp
)

set( DAL_SCR
  include/DAL/NotesRepository.h src/DAL/NotesRepository.cpp
)

set( WEBCAPTURE_SRC
  include/WebCapture/IWebScreenshoter.h
  include/WebCapture/WebScreenshoter.h src/WebCapture/WebScreenshoter.cpp
)

set( COMMON_SRC
  include/Common/NonCopyable.h
)

set( TEST_SRC
  test/SecurityTest.cpp
  test/SecurityStringToHex.cpp
  test/SecurityAes.cpp
)

add_executable(DataKeeper 
  src/main.cpp
  ${GUI_SRC}
  ${SECURITY_SRC}
  ${MODEL_SRC}
  ${DAL_SCR}
  ${WEBCAPTURE_SRC}
  ${COMMON_SRC}
  ${UI_HDRS}
)

qt5_use_modules(DataKeeper Widgets WebKit WebKitWidgets)

find_package (Threads)
target_link_libraries(DataKeeper ${CMAKE_SOURCE_DIR}/lib/libgtest.a)
target_link_libraries(DataKeeper ${CMAKE_SOURCE_DIR}/lib/libgmock.a)
target_link_libraries(DataKeeper ${CMAKE_SOURCE_DIR}/lib/libcrypto.a)
target_link_libraries(DataKeeper dl)
target_link_libraries(DataKeeper ${CMAKE_THREAD_LIBS_INIT})

target_link_libraries(DataKeeper ${Qt5Widgets_LIBRARIES})

#install(TARGETS DataKeeper DESTINATION bin)

