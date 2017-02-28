#ifndef WORDSADDING_H
#define WORDSADDING_H

#include <QDialog>

namespace Ui {
class WordsAdding;
}

class WordsAdding : public QDialog
{
    Q_OBJECT

public:
    explicit WordsAdding(QWidget *parent = 0);
    ~WordsAdding();
    void getVal(QStringList &w, QStringList &t);
private:

    QStringList words;
    QStringList translation;
    Ui::WordsAdding *ui;
};

#endif // WORDSADDING_H
