#include <QDialog>
#include <QMutex>
#include <QLabel>
#include <QLCDNumber>
#include <QThread>

#include "epoch_timer.h"

class GuiClass : public QDialog
{
	Q_OBJECT
public:
  explicit GuiClass(QWidget *parent = 0);
  ~GuiClass();

public slots:
    void onEpochTimeChanged();
protected:

private:
  TimerThread *epochTmr;
  QLabel *centerLabel;
  QLCDNumber *timerDisplay;
  quint64 epochToDisplay;
};