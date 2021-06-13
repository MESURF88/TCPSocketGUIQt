#include "epoch_timer.h"

TimerThread::~TimerThread( )
{
	stopThread();
	setRunThread(false);
}


void TimerThread::setRunThread(bool newVal )
{
  QMutexLocker lock( &mMutex );
  mRunThread = newVal;
}

bool TimerThread::getRunThread()
{
  QMutexLocker lock( &mMutex );
  return mRunThread;
}

void TimerThread::setDone(const bool newVal)
{
  QMutexLocker lock( &mMutex );
  mDone = newVal;
}

bool TimerThread::isDone()
{
  QMutexLocker lock( &mMutex );
  return mDone;
}

void TimerThread::run()
{
	printf("\nepoch timer started");
    while (state == TimerState::ACTIVE) {


    } // while

  setDone( true );
}


void TimerThread::startThread()
{
  state = TimerState::ACTIVE;

  start();
}

void TimerThread::stopThread()
{
  state = TimerState::INACTIVE;
}
