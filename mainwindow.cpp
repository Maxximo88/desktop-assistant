#include "mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mainWidget = new QWidget();
    layout = new QVBoxLayout();
    titleLayout = new QHBoxLayout();

    mainWidget->setLayout(layout);
    setCentralWidget(mainWidget);

    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    setWindowOpacity(0.6);

    initUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initUI()
{
    QPushButton *closeButton = new QPushButton();
    closeButton->setFixedSize(19, 19);
    closeButton->setObjectName("CloseButton");
    closeButton->setFocusPolicy(Qt::NoFocus);

    layout->addLayout(titleLayout);
    layout->addStretch();

    titleLayout->addStretch();
    titleLayout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, this, &QApplication::quit);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setPen(QColor("#FFFFFF"));
    painter.setBrush(QColor("#000000"));
    painter.drawRect(rect());
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton)
        move(e->globalPos() - p);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        p = e->globalPos() - frameGeometry().topLeft();
    }
}