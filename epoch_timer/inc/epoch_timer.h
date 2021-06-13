#include <QMutex>
#include <QThread>

class TimerThread : public QThread
{
public:
  ~TimerThread();
  void startThread();
  void stopThread();
  bool isDone();

  enum TimerState {
    ACTIVE,
	INACTIVE
  };
protected:
  QMutex mMutex;
  void setRunThread( bool newVal );
  bool getRunThread();
  void run();
  void setDone( const bool newVal );

private:
  int state;
  bool mRunThread;
  bool mDone;
};