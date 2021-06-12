#ifdef _WIN32
  #include "windows.h"
#else
  // macro to allow sleep to work on Linux
  #include <unistd.h>
  #define Sleep(x) usleep((x)*1000)
#endif
#include <QMutex>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QString>

class SocketThreadBase
{
public:
  SocketThreadBase(const QString &ipAddr, const ushort port ) : mIP( ipAddr ), mPort( port )
  {
    mRunThread = false;
  }
  enum Identity {
    BAD_IDENTITY,
    SERVER,
        CLIENT
  };
  virtual void startThread() = 0;
  virtual void stopThread() = 0;
  virtual Identity getIdentity() = 0;
protected:
  QMutex mMutex;
  const QString mIP;
  const ushort mPort;

  void setRunThread( bool newVal );
  bool getRunThread();
  void run();
  QString readLine(QTcpSocket *socket );
  int waitForInput( QTcpSocket *socket );
  void writeLine( QTcpSocket *client, const QString &line );
private:
  bool mRunThread;
};
