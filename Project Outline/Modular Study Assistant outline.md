# CSC 4100 - Modular Study Assistant





##### What will this applications accomplish?

This applications will help individuals study more effectively through interactive tools like flashcards and multiple choices quizzes. It will offer a clean, Wi-Fi-independent interface designed for speed, privacy, and modularity. Users can create, save, and review study materials locally without relying on internet access.



##### What are the roles for the project ?

Role A - Flashcard module(UI + logic)

Role B - Multiple-choice quiz module(UI + logic)

Role C - File I/O + data models + overall structure + UI polish





## Project Roadmap



##### Week 1: Planning \& Environment Setup



###### Goals

-Finalize features and app structure

-Set up Qt/C++ dev environment and Git

-Sketch UI mockups

###### 

###### Tasks

-Install Qt creator

-Ensure everyone in the group is added to the GitHub team

-Design UI wireframes(main window, flashcards, quiz)

-Define basic class structure(Flashcard, QuizQuestion, StudyModule, etc.)

-Set up shared dev environment



###### Deliverables

-Project skeleton with placeholder UI

-GitHub repo and Qt project meshing 



##### Week 2: Learn Qt \& Build Basic UI



###### Goals

-Learn Qt widgets and layouts

-Build working UI for flashcards and quiz screens



###### Tasks

-Person A: Flashcard UI prototype (add, edit, delete)

-Person B: Quiz screen prototype (question, options, next button)

-Person C: Main window with tab or menu-based module switching



###### Deliverables

-Working front-end UI for both modules (buttons in place, not worried about functionality)





##### Week 3: Implement Flashcard Logic



###### Goals

-Implement core logic for flashcards

-Add/create/delete in memory



###### Tasks

-Define FlashCard class

-Implement FlashcardManager (std::vector<Flashcard>)

-Connect UI buttons to logic

-Add form validation (empty fields, etc.)



###### Deliverables

Fully working Flashcard UI (data existing in memory)



##### Week 4: Implement Quiz Logic



###### Goals

-Add in-memory system (std::vector<QuizQuestion>, temporary until file I/O)

-Add multiple-choice template

-load questions from predefined list or flashcards



###### Tasks

-Define QuizQuestion, QuizManager, and QuizTemplate

-Show question with options

-Handle answer checking, scores, and moving to next question

-Add basic result summary screen

-Add dropdown in the quiz UI to select template

-Default quiz template is Multiple-choice



###### Deliverables

-Basic quiz system working with static data (no file I/O yet)





##### Week 5: Add Save \& Load Functionality



###### Goals

-Implement local file storage (JSON or custom format)



###### Tasks

-Person A: Connect flashcard data to save/load

-Person B: Connect flashcard data to save/load

-Person C: File handler class using QFile / QJsonDocument

-Add buttons: "Save", "Load"

-Save selected template with quiz data



###### Deliverables

-Data can be save/loaded locally via file system



##### Week 6: UI Improvements \& Data



###### Goals

-Polish UI with Qt layouts and styling

-Improve flashcard/quiz UI layout and responsiveness

-Optional: Add dark/light theme toggle



###### Tasks

-Use Qsettings to remember last used file

-Improve flashcard/quiz UI layout and responsiveness

-Optional: Add dark/light theme toggle

-Optional: True/False quiz template (QuizTemplateManager)



###### Deliverables

-Fully functional and polished UI for both modules



##### Week 7: Review \& Add Minor Features



###### Goals

-Add finishing touches to logic

-Optional feature: shuffle cards, mark favorites, retake quiz



###### Tasks

-Flashcard shuffle button

-Quiz retake or "review wrong answer"

-Add help/about menu



###### Deliverables

-Complete application core functionality



##### Week 8: Error Handling \& UI Polish



###### Goals

-Improve user experience with dialogs and validations

-Add basic error and exception handling



###### Tasks

-QMessageBox for save/load errors

-Confirm before delting cards

-Validate input fields



###### Deliverables

-Stable, crash-resistant app





##### Week 9: Testing, Bug Fixes, and Code Cleanup



###### Goals

-Ensure app works correctly under all use cases

-Clean code, write README



###### Tasks

-Manual testing (creating large data sets, edge cases)

-Review comments and documentations

-Cleanup code (unused variables, dead code)



###### Deliverables

-Polished, bug-free application ready to present





##### Week 10: Final Presentation \& Packaging



###### Goals

-Prepare for demo and final submission

-Package app for Windows/Linux



###### Tasks

-Build executable

-Prepare for final demo



###### Deliverables

-Demo-ready applications





/ModularStudyAssistant

├── main.cpp

├── MainWindow.ui

├── MainWindow.cpp/.h

├── modules/

│   ├── Flashcards/

│   │   ├── FlashcardManager.cpp/.h

│   │   ├── FlashcardWidget.ui/.cpp/.h

│   ├── Quiz/

│   │   ├── QuizManager.cpp/.h

│   │   ├── QuizWidget.ui/.cpp/.h

├── storage/

│   ├── FileManager.cpp/.h

├── models/

│   ├── Flashcard.h

│   ├── QuizQuestion.h

├── resources/

│   ├── icons/

│   └── stylesheets/




















