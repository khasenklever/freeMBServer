/*--------------------------------------------------------------------------------------*/
/* 
 * File :		Serveur.h
 * Author :		Marc Fournier
 * Date :		12/07/10
 * Comment :	Modbus server
 */
/*--------------------------------------------------------------------------------------*/

#ifndef HEADER_Serveur_H
#define HEADER_Serveur_H

#include <QCoreApplication>
#include <QtNetwork>

class mbPollThread;

class Serveur : QObject
{
    Q_OBJECT

    public:
        Serveur();
		bool	startPollingThread();
		void	stopPollingThread();


		mbPollThread	*m_pPoll;
};

#endif

