#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

#include "handle_manager.h"
#include "guitest.h"

#ifdef _WIN32
  #include "windows.h"
#else
  // macro to allow sleep to work on Linux
  #include <unistd.h>
  #define Sleep(x) usleep((x)*1000)
#endif

GuiClass::GuiClass(QWidget *parent) :
    QDialog(parent)
{
  printf("\ngui started");
  epochToDisplay = 0u;
  
  QGridLayout *layout1 = new QGridLayout();
  centerLabel = new QLabel;
  centerLabel->setText("<center>UNIX Epoch Time!</center>");
  
  timerDisplay = new QLCDNumber;
  QPushButton *quitButton = new QPushButton("Quit");
  quitButton->setAutoDefault(false);
  layout1->addWidget(centerLabel);
  layout1->addWidget(timerDisplay);
  layout1->addWidget(quitButton);

  this->resize(800, 800);
  this->setLayout(layout1);
  
  //start timer thread
  epochTmr = new TimerThread(this);
  epochTmr->start();
  
  
  // connect signal/slot for the epoch time updates
  connect(epochTmr, SIGNAL(updateEpochTime(int)),
		  this, SLOT(onEpochTimeChanged(int)));
}

GuiClass::~GuiClass( )
{

}

void GuiClass::onEpochTimeChanged()
{
	/*TODO: TCPRecvUsed.acquire();        
	epochToDisplay = sharedEpochTime;
	TCPRecvFree.release();*/
    timerDisplay->display(QString::number(epochToDisplay));
}