#include "TCPClient_Support.h"

void SocketThreadBase::setRunThread(bool newVal )
{
  QMutexLocker lock( &mMutex );
  mRunThread = newVal;
}

bool SocketThreadBase::getRunThread()
{
  QMutexLocker lock( &mMutex );
  return mRunThread;
}


int SocketThreadBase::waitForInput( QTcpSocket *socket )
{
  int bytesAvail = -1;
  while (socket->state() == QAbstractSocket::ConnectedState && getRunThread() && bytesAvail < 0) {
    if (socket->waitForReadyRead( 100 )) {
      bytesAvail = socket->bytesAvailable();
    }
    else {
      
      Sleep( 50 );
    }
  }
  return bytesAvail;
}

QString SocketThreadBase::readLine(QTcpSocket *socket )
{
  QString line = "";
  int bytesAvail = waitForInput( socket );
  if (bytesAvail > 0) {
    int cnt = 0;
    bool endOfLine = false;
    bool endOfStream = false;
    while (cnt < bytesAvail && (!endOfLine) && (!endOfStream)) {
      char ch;
      int bytesRead = socket->read(&ch, sizeof(ch));
      if (bytesRead == sizeof(ch)) {
	cnt++;
	line.append( ch );
	if (ch == '\r') {
	  endOfLine = true;
	}
      }
      else {
	endOfStream = true;
      }
    }
  }
  return line;
}


void SocketThreadBase::writeLine(QTcpSocket *socket, const QString &line)
{
  if (line.length() > 0) {
    socket->write( line.toUtf8().constData() );
    if (! socket->waitForBytesWritten()) {
      if (getIdentity() == SERVER) {
	printf("Server - ");
      }
      else if (getIdentity() == CLIENT) {
	printf("Client - ");
      }
      else {
	printf("Unknown identity - ");
      }
      printf("writeLine: the write to the socket failed\n");
    }
  }
}
