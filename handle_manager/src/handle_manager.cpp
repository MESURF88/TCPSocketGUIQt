#include <QSemaphore>

#include "handle_manager.h"


extern QSemaphore TCPRecvUsed;
extern QSemaphore TCPRecvFree;

extern quint64 sharedEpochTime;