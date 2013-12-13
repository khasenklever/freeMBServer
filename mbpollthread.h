/*--------------------------------------------------------------------------------------*/
/* 
 * File :		mbpollthread.h
 * Author :		Yeugjong Oh
 * Date :		12/13/13
 * Comment :	Modbus polling thread
 */
/*--------------------------------------------------------------------------------------*/

#ifndef __MBPOLLTHREAD_H__
#define __MBPOLLTHREAD_H__

#include <QThread>
#include <QMutex>

class mbPollThread : public QThread
{
   Q_OBJECT

public:
	explicit mbPollThread(QObject *parent = 0);

protected:
   virtual void run();

signals:
   void signalGUI(QString);

private:
	// variable that mutex protects
    bool m_bStop;
};


#endif	// __MBPOLLTHREAD_H__

