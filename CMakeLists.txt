cmake_minimum_required(VERSION 3.16)

project(MOST VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add Qt SQL module
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

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
        QuizModule/quizmenu.h
        QuizModule/quizcreate.h QuizModule/quizcreate.cpp
        QuizModule/quizstudy.h QuizModule/quizstudy.cpp
        QuizModule/quizquestion.h
        QuizModule/quizqbuilder.h
        QuizModule/quizqbuilder.cpp
        QuizModule/quizbank.h QuizModule/quizbank.cpp
        QuizModule/quizsession.h QuizModule/quizsession.cpp
        QuizModule/quizbank.cpp QuizModule/quizbank.h QuizModule/quizcreate.cpp QuizModule/quizcreate.h QuizModule/quizmenu.cpp QuizModule/quizmenu.h QuizModule/quizqbuilder.cpp QuizModule/quizqbuilder.h QuizModule/quizquestion.h QuizModule/quizsession.cpp QuizModule/quizsession.h QuizModule/quizstudy.cpp QuizModule/quizstudy.h QuizModule/quizwindow.cpp QuizModule/quizwindow.h QuizModule/quizwindow.ui
        QuizModule/quizreview.h QuizModule/quizreview.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET merged APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MOST SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
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
