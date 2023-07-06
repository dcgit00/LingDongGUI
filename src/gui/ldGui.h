#ifndef _LD_GUI_H_
#define _LD_GUI_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "stdbool.h"
#include "stdint.h"

#include "arm_2d.h"
#include <math.h>
#include <assert.h>
#include "arm_2d_helper.h"
#include "./arm_extra_controls.h"
#include "./__common.h"
#include "arm_2d_disp_adapter_0.h"
//#include "ldMemory.h"
#include "xString.h"
#include "xList.h"
#include "xBtn.h"


//btnռ��0-10

#define SIGNAL_TOUCH_HOLD_MOVE      11 // �����ƶ�

//#define SIGNAL_TOUCH_CHECK_PRESSED      4 // ��״̬����
//#define SIGNAL_TOUCH_CHECK_RELEASED      5 // ��״̬�ͷ�
//
//#define SIGNAL_VALUE_CHANGED           7 //���ݱ仯
//#define SIGNAL_WIDGET_ACTIVE           8 //����ؼ�
//#define SIGNAL_EIDTING_FINISHED           9 //�༭����
//#define SIGNAL_SYS_TIME_OUT             10//gui�����ʱ��





extern uint8_t pageNumNow;
extern uint8_t pageTarget;

void ldGuiInit(void);
void ldGuiLogicLoop(void);
void ldGuiLoop(const arm_2d_tile_t *ptParent,bool bIsNewFrame);
void ldGuiQuit(void);
void ldGuiJumpPage(uint8_t pageNum);
    
#ifdef __cplusplus
}
#endif

#endif //_LD_GUI_H_
