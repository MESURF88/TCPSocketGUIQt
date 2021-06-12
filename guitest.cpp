#include "guitest.h"

GuiThread::~GuiThread( )
{
	stopThread();
	setRunThread(false);
}


void GuiThread::setRunThread(bool newVal )
{
  QMutexLocker lock( &mMutex );
  mRunThread = newVal;
}

bool GuiThread::getRunThread()
{
  QMutexLocker lock( &mMutex );
  return mRunThread;
}

void GuiThread::setDone(const bool newVal)
{
  QMutexLocker lock( &mMutex );
  mDone = newVal;
}

bool GuiThread::isDone()
{
  QMutexLocker lock( &mMutex );
  return mDone;
}

void GuiThread::run()
{
	printf("gui started");
    while (state == GuiState::ACTIVE) {

		Sleep( 50 );
    } // while

  setDone( true );
}


void GuiThread::startThread()
{
  state = GuiState::ACTIVE;
  setRunThread( true );
  start();
}

void GuiThread::stopThread()
{
  state = GuiState::INACTIVE;
}
