#include <QMutex>

class EpochTimer : public QObject
{
	Q_OBJECT
	
public:
    explicit EpochTimer();
	
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