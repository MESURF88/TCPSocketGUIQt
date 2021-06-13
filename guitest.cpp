#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLCDNumber>
#include <QLabel>

#include "handle_manager.h"
#include "epoch_timer.h"
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
	printf("\ngui started");
    while (state == GuiState::ACTIVE) {

		Sleep( 50 );
    } // while

  setDone( true );
}


void GuiThread::startThread()
{
  state = GuiState::ACTIVE;
  setRunThread( true );
  QWidget *window = new QWidget();
  QGridLayout *layout1 = new QGridLayout();
  QLabel *hello = new QLabel;
  hello->setText("<center>Hello World!</center>");
  QLCDNumber *timerDisplay = new QLCDNumber;
  QPushButton *quitButton = new QPushButton("Quit");
  quitButton->setAutoDefault(false);
  layout1->addWidget(hello);
  layout1->addWidget(timerDisplay);
  layout1->addWidget(quitButton);

  window->setWindowTitle("UDP Socket GUI");
  window->resize(800, 800);
  window->setLayout(layout1);
  window->show();
  
  //start timer thread
  TimerThread *epochTmr = new TimerThread();
  epochTmr->startThread();
  start();
}

void GuiThread::stopThread()
{
  state = GuiState::INACTIVE;
}
