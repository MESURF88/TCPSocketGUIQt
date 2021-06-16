#include <QDateTime>
//TODO: remove QDebug
#include <QDebug>

//TODO: #include "handle_manager.h"
#include "epoch_timer.h"

EpochTimer::EpochTimer()
{
	state = TimerState::ACTIVE;
}