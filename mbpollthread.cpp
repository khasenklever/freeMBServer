#include "mbpollthread.h"
#include <QString>
#include "mb.h"
#include "fcallback.h"



mbPollThread::mbPollThread(QObject *parent)
	: QThread(parent)
{
	initThreadState();
}

void mbPollThread::run()
{
    eSetPollingThreadState( RUNNING );

    if( eMBEnable(  ) == MB_ENOERR )
    {
        do
        {
            if( eMBPoll(  ) != MB_ENOERR )
                break;
        }
        while( eGetPollingThreadState(  ) != SHUTDOWN );
    }

    ( void )eMBDisable(  );

    eSetPollingThreadState( STOPPED );
}