#include <QMutex>
#include <QThread>

class TimerThread : public QThread
{
	Q_OBJECT
public:
    explicit TimerThread(QObject *parent = 0);
    void run();
	void stopThread();
	
  enum TimerState {
    ACTIVE,
	INACTIVE
  };
signals:
    void updateEpochTime();

private:
  int state;
  quint64 epochTimer;
};