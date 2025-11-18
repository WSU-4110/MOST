#ifndef QUIZREVIEW_H
#define QUIZREVIEW_H

#include <QWidget>

class QuizWindow;

class QuizReview : public QWidget
{
    Q_OBJECT
public:
    explicit QuizReview(QuizWindow* quizWin, QWidget *parent);
    void showStudyQuestionReview(int i);
    void setReviewIndex(int i) { reviewIndex = i; };
private slots:
    void on_pushButtonNextQuestion_3_clicked();
    void on_pushButtonPreviousQuestion_3_clicked();
private:
    QuizWindow* quizWindow;
    int reviewIndex = 0;

    // current idea for displaying stored questions to study
    int questionStudyIndex = 0;
};

#endif // QUIZREVIEW_H
