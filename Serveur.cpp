#include "Serveur.h"
#include "mb.h"
#include "mbpollthread.h"

Serveur::Serveur()
	: m_pPoll(nullptr)
{
	if ( eMBTCPInit( MB_TCP_PORT_USE_DEFAULT ) != MB_ENOERR )
	{
		qDebug() << "can't initialize modbus stack!";
		return;
	} else
		qDebug() << "Iinitialize modbus stack success!";

	startPollingThread();
}

bool Serveur::startPollingThread()
{
	if ( m_pPoll == nullptr ) {
		m_pPoll = new mbPollThread(this);
	}
	if ( m_pPoll != nullptr ) {
		if ( m_pPoll->isRunning() )
			return false;
		else
			m_pPoll->start();
	}
	return true;
}

void Serveur::stopPollingThread()
{
}

