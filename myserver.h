#include <QTcpServer>

class MyServer : public QTcpServer
{
  Q_OBJECT

  public:
    explicit MyServer(QObject *parent=0);
    
    //Start the server
    void StartServer();

  signals:

  public slots:

  protected:
    void incomingConnections(int socketDescriptor);   //This is where we deal with incoming connections

};