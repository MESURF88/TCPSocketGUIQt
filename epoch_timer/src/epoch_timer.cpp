#include <QDateTime>
//TODO: remove QDebug
#include <QDebug>

//TODO: #include "handle_manager.h"
#include "epoch_timer.h"

#ifdef _WIN32
  #include "windows.h"
#else
  // macro to allow sleep to work on Linux
  #include <unistd.h>
  #define Sleep(x) usleep((x)*1000)
#endif

TimerThread::TimerThread(QObject *parent) :
    QThread(parent)
{
	state == TimerState::ACTIVE;
}

void TimerThread::run()
{
	printf("\nepoch timer started");
    while (state == TimerState::ACTIVE) {
		Sleep( 1000 );
		epochTimer++;
        /*TODO: TCPRecvFree.acquire();        
        sharedEpochTime = epochTimer;
        TCPRecvUsed.release();*/
        emit updateEpochTime();
	    qDebug() << epochTimer;
    } // while

}

// TODO: fix with to protected
void TimerThread::stopThread()
{
	state = TimerState::INACTIVE;
}