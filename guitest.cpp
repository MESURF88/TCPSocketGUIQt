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

  resize(800, 800);
  setLayout(layout1);
  
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