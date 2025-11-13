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
# Find Qt Test module
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

# Add for unit tests
set(TEST_SOURCES
    UnitTest/UnitTest.cpp
    FlashcardModule/flashcardmaker.cpp
    QuizModule/quizwindow.cpp
    QuizModule/quizmenu.cpp
    Homepage/homepage.cpp
    FlashcardModule/flashcardstudy.cpp
    Database/database.h
    Database/database.cpp
    Database/databasequiz.h
    Database/databasequiz.cpp
    Database/databaseflashcard.h
    Database/databaseflashcard.cpp
    UnitTest/unittest_databasequiz.cpp
)

add_executable(UnitTests ${TEST_SOURCES})

# Fix the WinMain error for MinGW (console app)
set_target_properties(UnitTests PROPERTIES WIN32_EXECUTABLE OFF)

# Link Qt Widgets, SQL and Test modules
target_link_libraries(UnitTests PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql Qt${QT_VERSION_MAJOR}::Test)

#Make the test executable run automatically after build
add_custom_target(run_tests
    COMMAND UnitTests
    DEPENDS UnitTests
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# Enable testing
include(CTest)
enable_testing()

# Add the test executable
add_executable(FlashCardMakerTest
    FlashcardModule/FlashCardMakerTest.cpp
    FlashcardModule/flashcardmaker.cpp
    Database/flashCardData.cpp
    Database/Database2.cpp
)

# Link against Qt modules your code needs
target_link_libraries(FlashCardMakerTest
    PRIVATE
        Qt6::Test       # Provides QTest
        Qt6::Widgets
        Qt6::Core
        Qt6::Gui
        Qt6::Sql
)

# Include your headers
target_include_directories(FlashCardMakerTest PRIVATE
    FlashcardModule
    Database
)

# Add the test to CTest so you can run it with `ctest`
add_test(NAME FlashCardMakerTest COMMAND FlashCardMakerTest)

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

qt_add_executable(quizwindowUnitTests
    MANUAL_FINALIZATION
    ${TEST_SOURCES}
    ${UI}
)

# Link Qt Widgets, SQL and Test modules
target_link_libraries(quizwindowUnitTests PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(quizwindowUnitTests)
endif()

