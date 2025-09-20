#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "master.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui -> setupUi(this);
    SetConsoleTitleA("Class Terminator");
    hWnd = (HWND)this -> winId();
    ::SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 100, 100, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREPOSITION);
    CreateThread(NULL, 0, KeyHookLLThreadProc, NULL, 0, NULL);
    CreateThread(NULL, 0, MouseHookLLThreadProc, NULL, 0, NULL);
    CreateThread(NULL, 0, KeyHookThreadProc, NULL, 0, NULL);
    CreateThread(NULL, 0, MouseHookThreadProc, NULL, 0, NULL);
    CreateThread(NULL, 0, WindowHookThreadProc, NULL, 0, NULL);
    CreateThread(NULL, 0, WindowSwitchThreadProc, NULL, 0, NULL);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    WindowSwitchProc();
}


void MainWindow::on_pushButton_4_clicked() {
    WindowHookProc();
}


void MainWindow::on_pushButton_2_clicked() {
    Suspend_service();
}


void MainWindow::on_pushButton_3_clicked() {
    Resume_service();
}


void MainWindow::on_pushButton_5_clicked() {
    Check_Class_service();
}

void MainWindow::on_lineEdit_editingFinished()
{
    processName = (LPCSTR)ui->lineEdit->text().toLocal8Bit();
}

