#ifdef _WIN32
  #include "windows.h"
#else
  // macro to allow sleep to work on Linux
  #include <unistd.h>
  #define Sleep(x) usleep((x)*1000)
#endif
#include <QMutex>
#include <QThread>

class GuiThread : public QThread
{
public:
  ~GuiThread();
  void startThread();
  void stopThread();
  bool isDone();

  enum GuiState {
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