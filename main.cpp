#include <QApplication>

#include "myserver.h"

int main(int argc, char *argv[])
{
  //QCoreApplication a(argc, argv);
  QApplication a(argc, argv);
  
  MyServer* server = new MyServer();
  server->StartServer();
  
  return a.exec();
}