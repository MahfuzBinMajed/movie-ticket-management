#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , count1(1)
    , count2(1)
    , count3(1)
{
    ui->setupUi(this);

    connect(ui->movies_btn, &QPushButton::clicked, this, [this](){
        ui->stackedWidget->setCurrentWidget(ui->moviesPage);
    });

    connect(ui->hall_btn, &QPushButton::clicked, this, [this](){
        ui->stackedWidget->setCurrentWidget(ui->hallPage);
    });

    connect(ui->screening_btn, &QPushButton::clicked, this, [this](){
        ui->stackedWidget->setCurrentWidget(ui->screeningPage);
    });

    connect(ui->ok_btn, &QPushButton::clicked, this, &MainWindow::ticketFunction);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ticketFunction()
{
    QString name = ui->name->text();
    QString id = ui->id->text();
    QString movieName = ui->movieName->text();

    QString hall;
    QString seat;
    QString time;

    if(movieName == "The Avengers")
    {
        if(count1 > 10)
        {
            QMessageBox::warning(this,
                                 "Error",
                                 "Hall 1 is full.");
            return;
        }

        hall = "Hall 1";
        seat = QString::number(count1++);
        time = "7:30 PM";
    }

    else if(movieName == "Home Alone")
    {
        if(count1 > 10)
        {
            QMessageBox::warning(this,
                                 "Error",
                                 "Hall 1 is full.");
            return;
        }

        hall = "Hall 1";
        seat = QString::number(count1++);
        time = "11:00 AM";
    }

    else if(movieName == "Ice Age")
    {
        if(count1 > 10)
        {
            QMessageBox::warning(this,
                                 "Error",
                                 "Hall 1 is full.");
            return;
        }

        hall = "Hall 1";
        seat = QString::number(count1++);
        time = "8:00 AM";
    }

    else if(movieName == "Thor: Ragnarok")
    {
        if(count2 > 10)
        {
            QMessageBox::warning(this,
                                 "Error",
                                 "Hall 2 is full.");
            return;
        }

        hall = "Hall 2";
        seat = QString::number(count2++);
        time = "7:30 PM";
    }

    else if(movieName == "Baby's Day Out")
    {
        if(count2 > 10)
        {
            QMessageBox::warning(this,
                                 "Error",
                                 "Hall 2 is full.");
            return;
        }

        hall = "Hall 2";
        seat = QString::number(count2++);
        time = "11:00 AM";
    }

    else if(movieName == "Moana")
    {
        if(count2 > 10)
        {
            QMessageBox::warning(this,
                                 "Error",
                                 "Hall 2 is full.");
            return;
        }

        hall = "Hall 2";
        seat = QString::number(count2++);
        time = "8:00 AM";
    }

    else if(movieName == "Kung Fu Panda")
    {
        if(count3 > 10)
        {
            QMessageBox::warning(this,
                                 "Error",
                                 "Hall 3 is full.");
            return;
        }

        hall = "Hall 3";
        seat = QString::number(count3++);
        time = "7:30 PM";
    }

    else if(movieName == "Bean")
    {
        if(count3 > 10)
        {
            QMessageBox::warning(this,
                                 "Error",
                                 "Hall 3 is full.");
            return;
        }

        hall = "Hall 3";
        seat = QString::number(count3++);
        time = "11:00 AM";
    }

    else if(movieName == "Madagascar")
    {
        if(count3 > 10)
        {
            QMessageBox::warning(this,
                                 "Error",
                                 "Hall 3 is full.");
            return;
        }

        hall = "Hall 3";
        seat = QString::number(count3++);
        time = "8:00 AM";
    }

    else
    {
        QMessageBox::warning(this,
                             "Error",
                             "Movie not found.");
        return;
    }

    QMessageBox::information(
        this,
        "Ticket",
        "Name: " + name +
            "\nID: " + id +
            "\nMovie: " + movieName +
            "\nHall: " + hall +
            "\nSeat: " + seat +
            "\nTime: " + time
        );
}