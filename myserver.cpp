#include <QMessageBox>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QWidget>

#include "myserver.h"
#include "mythread.h"

MyServer::MyServer(QObject *parent):
  QTcpServer(parent)
{
}


void MyServer::StartServer()
{
  if (!this->listen(QHostAddress::Any, 1234))
  {
	QMessageBox* msg;
    msg = new QMessageBox();
    //msg->setIcon(QMessageBox.Critical);
    //msg->setWindowTitle("title");
    //msg->setText("text");
  }
  else
  {
  QWidget diag;
  //Server is now listening..
  QGridLayout *layout1 = new QGridLayout();
  QLabel* centerLabel = new QLabel;
  centerLabel->setText("<center>UNIX Epoch Time!</center>");
  
  QLCDNumber* timerDisplay = new QLCDNumber;
  QPushButton *quitButton = new QPushButton("Quit");
  quitButton->setAutoDefault(false);
  layout1->addWidget(centerLabel);
  layout1->addWidget(timerDisplay);
  layout1->addWidget(quitButton);

  diag.resize(800, 800);
  diag.setLayout(layout1);
  }
}


void MyServer::incomingConnections(int socketDescriptor)    //Incoming connections
{
  MyThread *thread = new MyThread(socketDescriptor,this);
  
  connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
  
  //Start a new thread for the connection
  thread->start();    //Which will cause the run() function
}