#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings settings(this->orgnizationName, this->appName);
    ui->plainTextEditMain->setPlainText(settings.value("content").toString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

// returns number of words in str

int MainWindow::countWords(const char *str)
{
   if (str == NULL)
      return -1;

   bool inSpaces = true;
   int numWords = 0;

   while (*str != '\0')
   {
      if (std::isspace(*str))
      {
         inSpaces = true;
      }
      else if (inSpaces)
      {
         numWords++;
         inSpaces = false;
      }

      ++str;
   }

   return numWords;
}
void MainWindow::on_plainTextEditMain_textChanged()
{
    QSettings settings(this->orgnizationName, this->appName);
    settings.setValue("content", this->ui->plainTextEditMain->toPlainText());
    this->ui->labelWordCount->setText(
        QStringLiteral("Word Count: %1").arg(this->countWords(this->ui->plainTextEditMain->toPlainText().toStdString().c_str()))
    );
}


void MainWindow::on_pushButtonExit_clicked()
{
    QCoreApplication::quit();
}

