#ifndef __HEATINGSYSTEM_H___
#define __HEATINGSYSTEM_H___

/*
 * Main include file for project Heating System
 * Contains macros, includes etc for all devices
 * Designed by Roman A. Paramonov
 *
*/

// **** COMMON DATA TYPE ****

#ifdef HTSYS_MAIN_CONTROLLER

#include "stm32f4xx_conf.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

#include "FreeRTOS.h"
#include "task.h"

#include "htsysDisplay.h"  // big color sensor LCD
#include "htsysIODev.h"    // 2-lines LCD with 4 buttons
#include "htsysSound.h"
#include "htsysMainCtrl.h"
#include "htsysConParser.h"
#include "htsysADC.h"
#include "htsysDiscrete.h"

#endif

#ifdef HTSYS_REMOTE_CONTROLLER

#include "stm32f4xx_conf.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

#include "FreeRTOS.h"
#include "task.h"
#include "htsysRemoteCtrl.h"
#include "htsysIODev.h"    // 2-lines LCD with 4 buttons
#include "htsysSound.h"
#include "htsysConParser.h"

#endif

#ifdef HTSYS_DEBUG_CONSOLE
#endif

#ifdef HTSYS_MONITOR
#endif

#endif
