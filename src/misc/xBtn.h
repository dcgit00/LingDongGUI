/*
 * Copyright 2021-2023 Ou Jianbo 59935554@qq.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#ifndef _X_BTN_H_
#define _X_BTN_H_

#include <stdint.h>
#include <stdbool.h>

#include "stdint.h"
#include "stdbool.h"
#include "stdlib.h"
#include "ldCommon.h"

#define BTN_NO_OPERATION         0 //��ⰴ���ް����ź�
#define BTN_PRESS                1 //��ⰴ�������ź�
#define BTN_HOLD_DOWN            2 //��ⰴ����ס�����ź�
#define BTN_RELEASE              3 //��ⰴ���ͷ��ź�
#define BTN_DOUBLE_CLICK         4 //��ⰴ��˫���ź�
#define BTN_REPEAT_COUNT         5 //��ȡ��������
#define BTN_HOLD_TIME            6 //��ȡ������ס���ŵ�ʱ��
#define BTN_LONG_START           7 //��ⰴ����������һ�ε��ź�
#define BTN_LONG_SHOOT           8 //��ⰴ����������һ�κ������������ź�

#define BTN_MALLOC               ldMalloc
#define BTN_FREE                 ldFree

typedef struct {
    size_t addrOrNum;
    uint8_t FSM_State;
    uint8_t doubleClickCount;
    uint8_t repeatCount;
    uint16_t repeatTimeOutCount;
    uint16_t holdCount;
    uint16_t shootCount;
    uint16_t nameId;
    bool (*getBtnStateFunc)(size_t);
    bool btnNewState:1;
    bool btnOldState:1;
    bool isPressed:1;
    bool isReleased:1;
//    bool isClicked:1;
    bool isDoubleClicked:1;
    bool isRepeatEnd:1;
    bool isShoot:1;
}xBtnInfo_t;

void xBtnInit(size_t addrOrNum,uint16_t nameId,bool (*getBtnStateFunc)(size_t));
void xBtnConfig(uint8_t debounceMs,uint16_t longPressMs,uint16_t longShootMs,uint16_t clickTimeOutMs);
void xBtnTick(uint8_t cycleMs);
uint16_t xBtnGetState(uint16_t nameIdOrNum,uint8_t state);
void xBtnClean(void);










#endif //_X_BTN_H_
