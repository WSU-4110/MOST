cmake_minimum_required(VERSION 3.16)
project(MOST VERSION 0.1 LANGUAGES CXX)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# add Qt SQL module
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql Test)
set(PROJECT_SOURCES
        main.cpp
)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MOST
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        FlashcardModule/flashcardmaker.cpp FlashcardModule/flashcardmaker.h FlashcardModule/flashcardmaker.ui
        QuizModule/quizwindow.cpp QuizModule/quizwindow.h QuizModule/quizwindow.ui
        Homepage/homepage.cpp Homepage/homepage.h Homepage/homepage.ui
        FlashcardModule/flashcardmaker.cpp FlashcardModule/flashcardmaker.h FlashcardModule/flashcardmaker.ui FlashcardModule/flashcardstudy.cpp FlashcardModule/flashcardstudy.h FlashcardModule/flashcardstudy.ui
        images/flash-card-color.png images/flash-cards.png images/home.png images/quiz-color.png images/quiz.png
        resources.qrc

        images/flash-card-color.png images/flash-card.png images/flash-cards.png images/home.png images/left-arrow.png images/quiz-color.png images/quiz.png
        images/flash-card-color.png images/flash-card.png images/flash-cards.png images/home.png images/left-arrow.png images/quiz-color.png images/quiz.png images/right-arrow.png
        images/flash-card-color.png images/flash-card.png images/flash-cards.png images/home.png images/left-arrow.png images/quiz-color.png images/quiz.png images/right-arrow.png
        images/flash-card-color.png images/flash-card.png images/flash-cards.png images/home.png images/left-arrow.png images/output-onlinepngtools.png images/quiz-color.png images/quiz.png images/right-arrow.png
        Database/database.cpp Database/database.h   Database/databasequiz.cpp Database/databasequiz.h

        Database/databaseflashcard.h Database/databaseflashcard.cpp
        QuizModule/quizmenu.cpp

        FlashcardModule/flashCards.h

        Database/database2.h Database/database2.cpp
        Database/flashCardData.h
        Database/flashCardData.cpp
    )
else()
    if(ANDROID)
        add_library(MOST SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(MOST
            ${PROJECT_SOURCES}
        )
    endif()
endif()
target_link_libraries(MOST PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql) # link Qt to SQL
# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.MOST)
endif()
set_target_properties(MOST PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS MOST
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MOST)
endif()


# *** ADDED FOR UNIT TEST ***

function(add_qt_test TARGET_NAME)
  add_executable(${TARGET_NAME} ${ARGN})
  target_link_libraries(${TARGET_NAME}
    PRIVATE
      Qt${QT_VERSION_MAJOR}::Test
      Qt${QT_VERSION_MAJOR}::Widgets
      Qt${QT_VERSION_MAJOR}::Sql
  )
  add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME} --verbose)
endfunction()

# Find Qt Test module
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

#Make the test executable run automatically after build
add_custom_target(run_tests
    COMMAND UnitTests
    DEPENDS UnitTests
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Enable testing
include(CTest)
enable_testing()

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(TEST_SOURCES
    UnitTest/quizwindowunittest.cpp
    UnitTest/quizwindowunittest.h
    QuizModule/quizwindow.cpp
    QuizModule/quizwindow.h
)

set(UI
    QuizModule/quizwindow.ui
)

# separating the build of each executable below

# homepage test
qt_add_executable(tst_homepage
  MANUAL_FINALIZATION
  UnitTest/UnitTest.cpp

  Homepage/homepage.cpp
  Homepage/homepage.ui

  QuizModule/quizmenu.cpp
  QuizModule/quizwindow.cpp
  QuizModule/quizwindow.ui

  FlashcardModule/flashcardmaker.cpp
  FlashcardModule/flashcardmaker.ui

  FlashcardModule/flashcardstudy.cpp
  FlashcardModule/flashcardstudy.ui

  Database/flashCardData.cpp
  Database/database2.cpp
  Database/database.cpp
  Database/databasequiz.cpp
  Database/databaseflashcard.cpp
)

target_link_libraries(tst_homepage
  PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql
)


target_include_directories(tst_homepage PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(tst_homepage PROPERTIES
  AUTOUIC_SEARCH_PATHS
    "${CMAKE_CURRENT_SOURCE_DIR}/Homepage;${CMAKE_CURRENT_SOURCE_DIR}/QuizModule;${CMAKE_CURRENT_SOURCE_DIR}/FlashcardModule"
)

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(tst_homepage)
endif()

add_test(NAME tst_homepage COMMAND tst_homepage --verbose)

# database quiz test
qt_add_executable(tst_databasequiz
  MANUAL_FINALIZATION
  UnitTest/unittest_databasequiz.cpp
  Database/databasequiz.cpp
  Database/database.cpp
)

target_link_libraries(tst_databasequiz
  PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql
)

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(tst_databasequiz)
endif()

add_test(NAME tst_databasequiz COMMAND tst_databasequiz --verbose)

# flashcard study test
qt_add_executable(tst_flashcardstudy
  MANUAL_FINALIZATION
  UnitTest/tst_flashcardstudy.cpp

  FlashcardModule/flashcardstudy.cpp

  Database/database.cpp
  Database/databaseflashcard.cpp
)

target_link_libraries(tst_flashcardstudy
  PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql
)
target_compile_definitions(tst_flashcardstudy PRIVATE UNIT_TEST)
target_include_directories(tst_flashcardstudy PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(tst_flashcardstudy PROPERTIES
  AUTOUIC_SEARCH_PATHS
    "${CMAKE_CURRENT_SOURCE_DIR}/Homepage;${CMAKE_CURRENT_SOURCE_DIR}/QuizModule;${CMAKE_CURRENT_SOURCE_DIR}/FlashcardModule"
)

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(tst_flashcardstudy)
endif()

add_test(NAME tst_flashcardstudy COMMAND tst_flashcardstudy --verbose)

# flashcard maker test
qt_add_executable(tst_flashcardmaker
  MANUAL_FINALIZATION
  FlashcardModule/FlashCardMakerTest.cpp
  FlashcardModule/flashcardmaker.cpp
  FlashcardModule/flashcardmaker.ui

  Homepage/homepage.cpp
  Homepage/homepage.ui

  QuizModule/quizwindow.cpp
  QuizModule/quizwindow.ui

  FlashcardModule/flashcardstudy.cpp
  FlashcardModule/flashcardstudy.ui

  Database/flashCardData.cpp
  Database/database2.cpp
  Database/database.cpp
  Database/databaseflashcard.cpp
)

target_link_libraries(tst_flashcardmaker
  PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql
)

target_include_directories(tst_flashcardmaker PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

set_target_properties(tst_flashcardmaker PROPERTIES
  AUTOUIC_SEARCH_PATHS
    "${CMAKE_CURRENT_SOURCE_DIR}/Homepage;${CMAKE_CURRENT_SOURCE_DIR}/QuizModule;${CMAKE_CURRENT_SOURCE_DIR}/FlashcardModule"
)

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(tst_flashcardmaker)
endif()

add_test(NAME tst_flashcardmaker COMMAND tst_flashcardmaker --verbose)

# quiz window test
qt_add_executable(quizwindowUnitTests
  MANUAL_FINALIZATION
  UnitTest/quizwindowunittest.cpp
  QuizModule/quizwindow.cpp
  QuizModule/quizwindow.ui
)

target_include_directories(quizwindowUnitTests PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(quizwindowUnitTests PROPERTIES
  AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/QuizModule"
)

# Link Qt Widgets, SQL and Test modules
target_link_libraries(quizwindowUnitTests PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(quizwindowUnitTests)
endif()

add_test(NAME quizwindowUnitTests COMMAND quizwindowUnitTests --verbose)

