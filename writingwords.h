#ifndef WRITINGWORDS_H
#define WRITINGWORDS_H

#include <QDialog>
#include <QString>

namespace Ui {
class WritingWords;
}

class WritingWords : public QDialog
{
    Q_OBJECT

public:
    explicit WritingWords(QWidget *parent = 0);
    void getVal(QStringList &w, QStringList &t);
    ~WritingWords();

private:
    QStringList words;
    QStringList translation;
    Ui::WritingWords *ui;
};

#endif // WRITINGWORDS_H
