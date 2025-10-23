/****************************************************************************
** Meta object code from reading C++ file 'quizwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../QuizModule/quizwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quizwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN10QuizWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto QuizWindow::qt_create_metaobjectdata<qt_meta_tag_ZN10QuizWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QuizWindow",
        "on_pushButtonCreatePage_clicked",
        "",
        "on_pushButtonStudyPage_clicked",
        "on_pushButtonReturn_clicked",
        "on_pushButtonReturn_2_clicked",
        "on_pushButtonReturn_3_clicked",
        "on_pushButtonReturn_4_clicked",
        "on_pushButtonCreateQuestion_clicked",
        "on_pushButtonOverwriteQuestion_clicked",
        "on_pushButtonDeleteQuestion_clicked",
        "on_pushButtonNextQuestion_clicked",
        "on_pushButtonPreviousQuestion_clicked",
        "on_pushButtonNextQuestion_2_clicked",
        "on_pushButtonPreviousQuestion_2_clicked",
        "on_pushButtonSubmitQuiz_clicked",
        "on_pushButtonReview_clicked",
        "on_pushButtonNextQuestion_3_clicked",
        "on_pushButtonPreviousQuestion_3_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_pushButtonCreatePage_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonStudyPage_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonReturn_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonReturn_2_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonReturn_3_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonReturn_4_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonCreateQuestion_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonOverwriteQuestion_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonDeleteQuestion_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonNextQuestion_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonPreviousQuestion_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonNextQuestion_2_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonPreviousQuestion_2_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonSubmitQuiz_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonReview_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonNextQuestion_3_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pushButtonPreviousQuestion_3_clicked'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QuizWindow, qt_meta_tag_ZN10QuizWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QuizWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QuizWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QuizWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QuizWindowE_t>.metaTypes,
    nullptr
} };

void QuizWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QuizWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_pushButtonCreatePage_clicked(); break;
        case 1: _t->on_pushButtonStudyPage_clicked(); break;
        case 2: _t->on_pushButtonReturn_clicked(); break;
        case 3: _t->on_pushButtonReturn_2_clicked(); break;
        case 4: _t->on_pushButtonReturn_3_clicked(); break;
        case 5: _t->on_pushButtonReturn_4_clicked(); break;
        case 6: _t->on_pushButtonCreateQuestion_clicked(); break;
        case 7: _t->on_pushButtonOverwriteQuestion_clicked(); break;
        case 8: _t->on_pushButtonDeleteQuestion_clicked(); break;
        case 9: _t->on_pushButtonNextQuestion_clicked(); break;
        case 10: _t->on_pushButtonPreviousQuestion_clicked(); break;
        case 11: _t->on_pushButtonNextQuestion_2_clicked(); break;
        case 12: _t->on_pushButtonPreviousQuestion_2_clicked(); break;
        case 13: _t->on_pushButtonSubmitQuiz_clicked(); break;
        case 14: _t->on_pushButtonReview_clicked(); break;
        case 15: _t->on_pushButtonNextQuestion_3_clicked(); break;
        case 16: _t->on_pushButtonPreviousQuestion_3_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *QuizWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuizWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QuizWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QuizWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
