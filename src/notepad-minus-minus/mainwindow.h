#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_plainTextEditMain_textChanged();
    void on_pushButtonExit_clicked();

    void on_spinBoxFontSize_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

    const QString orgnizationName = "ak-studio";
    const QString appName = "notepad-minus-minus";

    int countWords(const char *str);
};
#endif // MAINWINDOW_H
