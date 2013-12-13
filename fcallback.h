/*--------------------------------------------------------------------------------------*/
/* 
 * File :		fcallback.h
 * Author :		Yeugjong Oh
 * Date :		12/13/13
 * Comment :	callbacks for freeModbus
 */
/*--------------------------------------------------------------------------------------*/

#ifndef __FCALLBACK_H__
#define __FCALLBACK_H__

/* ----------------------- Defines ------------------------------------------*/
#define PROG            _T("freemodbus")

#define REG_INPUT_START 1000
#define REG_INPUT_NREGS 4
#define REG_HOLDING_START 2000
#define REG_HOLDING_NREGS 130

typedef enum 
{
    STOPPED,
    RUNNING,
    SHUTDOWN
} PollThreadState;

#ifdef __cplusplus
extern "C" {
#endif

extern	void	initThreadState();
extern	void eSetPollingThreadState( PollThreadState eNewState );
extern	PollThreadState	eGetPollingThreadState(  );
#ifdef __cplusplus
}
#endif

#endif	// __FCALLBACK_H__