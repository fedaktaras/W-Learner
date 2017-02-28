#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("W-Learner");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoadWords_clicked()
{

    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "Text File (*.txt)");
    std::string s1, s, s2;
    file.open(file_name.toStdString());
    if(!file.is_open())
    {
        ui->label->setText("Can't open file");
        QTimer::singleShot(1000, this, SLOT(refresh()));
        return;
    }
    file>>s1;
    file.ignore();
    while(std::getline(file, s))
    {
        int separator = s.find_first_of("|");
        s2 = s.substr(s.find_first_not_of(' ', separator+2), s.find_last_not_of(' '));
        s=s.substr(0, separator);
        s1 = s.substr(s.find_first_not_of(' '), s.find_last_not_of(' ')+1);
        words.push(std::pair<std::string, std::string>(s1, s2));
    }
    file.close();
    refresh();
}

void MainWindow::on_line_returnPressed()
{
    ui->line->setEnabled(false);
    if (!words.empty() )
    {
        words.pop();
    }
    else
    {
        current.first = "";
        current.second = "";
        ui->wordsLeft->setText("No Words to learn");
        ui->label->clear();
        return;
    }

    if (ui->line->text().toStdString()==current.first)
    {
        ui->line->setStyleSheet("color: #76ee00");
        QTimer::singleShot(1000, this, SLOT(refresh()));
    }
    else
    {
        ui->line->setStyleSheet("color: #ee3b3b");
        words.push(current);
        QTimer::singleShot(1000, this, SLOT(blink()));
    }
}

void MainWindow::refresh()
{
    ui->line->setStyleSheet("color: #000000");
    ui->line->setEnabled(true);
    ui->line->clear();
    ui->line->setFocus();
    if (words.size()<2)
    {
        if(words.size()<1)
        {
            ui->wordsLeft->setText("No Words to learn");
            ui->label->clear();
        }
        else
            ui->wordsLeft->setText("1 Word Left");
    }
    else
        ui->wordsLeft->setText(QString::number(words.size()) + " Words Left");
    startLesson();
}
void MainWindow::startLesson()
{
    if (!words.empty())
    {
        current = words.front();
        ui->label->setText(QString::fromStdString(current.second));
    }
}

void MainWindow::on_pushButton_clicked()
{
    std::vector<std::pair<std::string, std::string>> x;
    while(!words.empty())
    {
        x.push_back(words.front());
        words.pop();
    }
    std::random_shuffle(x.begin(), x.end());

    for (auto it = x.begin(); it!=x.end(); ++it)
    {
        words.push(*it);
    }
    refresh();
}
//void loadFromWritingWords(QStringList *w, QStringList *t)
//{

//}

void MainWindow::on_DeleteWords_clicked()
{
    while(!words.empty())
    {
        words.pop();
    }
    ui->label->setText("");
    ui->wordsLeft->setText("No Words to learn");
    ui->line->setEnabled(false);
    current.first = "";
    current.second = "";
}
void MainWindow::blink()
{
    ui->line->setText(QString::fromStdString(current.first));
    ui->line->setStyleSheet("color: #76ee00");
    QTimer::singleShot(300, this, SLOT(refresh()));

}

void MainWindow::on_write_words_clicked()
{
    w = new WritingWords;
    connect(w, SIGNAL(accepted()), this, SLOT(loadFromDialog()));
    w->show();
}

void MainWindow::loadFromDialog()
{
    //int var = 9;
    w->getVal(wordsQSList, translationQSList);
    qDebug()<<"var";
    auto it_t = translationQSList.begin();
    auto it = wordsQSList.begin();
    while(it!=wordsQSList.end())
    {
        words.push(std::pair<std::string, std::string>(it->toStdString(), it_t->toStdString()));
        it++;
        it_t++;
    }
    refresh();
}
