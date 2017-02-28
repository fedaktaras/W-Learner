#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtCore>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QTextEdit>
#include <QDialog>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
#include "writingwords.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void loadFromDialog();
private slots:
    void on_LoadWords_clicked();

    void on_line_returnPressed();



    void refresh();

    void blink();

    void on_pushButton_clicked();

    void on_DeleteWords_clicked();

    void on_write_words_clicked();

private:
    std::pair<std::string, std::string > current;
    std::queue < std::pair<std::string, std::string >  > words;
    std::ifstream file;
    std::string toCompare;
    WritingWords *w;
    QStringList wordsQSList;
    QStringList translationQSList;
    void openFile(QString);
    void readFromFile();
    void startLesson();
    void showResultOfOpening();
    //void loadFromWritingWords(QStringList &w, QStringList &t);



    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
