/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief IWDG 例程，通过 HW 层接口实现
 *
 * - 实验现象：
 *   1. 修改宏定义 __IWDG_FEED_TIME_MS 的值，超过 1500ms(存在 5ms 误差)，芯片复位；
 *   2. 修改宏定义 __IWDG_FEED_TIME_MS 的值，小于 1500ms(存在 5ms 误差)，程序正常运行。
 *
 * \par 源代码
 * \snippet demo_mm32l373_hw_iwdg.c src_mm32l373_hw_iwdg
 *
 * \internal
 * \par Modification history
 * - 1.00 17-04-26  sdy, first implementation.
 * \endinternal
 */

/**
 * \addtogroup demo_if_mm32l373_hw_iwdg
 * \copydoc demo_mm32l373_hw_iwdg.c
 */

/** [src_mm32l373_hw_iwdg] */
#include "ametal.h"
#include "am_board.h"
#include "am_vdebug.h"
#include "amhw_mm32l373_rcc.h"
#include "amhw_mm32_iwdg.h"
#include "demo_mm32_entries.h"
#include "demo_mm32l373_core_entries.h"

/**
 * \brief 看门狗超时时间
 *
 * \note 因为看门狗内部时钟WDTOSC存在误差，所以__IWDG_TIMEOUT_MS对应的实际时间
 *       存在误差。
 */
#define __IWDG_TIMEOUT_MS       1500

/**
 * \brief 看门狗喂狗时间，若喂狗时间超过__IWDG_TIMEOUT_MS的值（大于5ms以上）,
 *        会产生看门狗事件。
 */
#define __IWDG_FEED_TIME_MS     1000

/**
 * \brief 例程入口
 */
void demo_mm32l373_core_hw_iwdg_entry (void)
{
    AM_DBG_INFO("demo mm32l373_core std iwdg!\r\n");

    amhw_mm32l373_rcc_lsi_enable();

    demo_mm32_hw_iwdg_entry(MM32L373_IWDG,
                           __IWDG_TIMEOUT_MS,
                           __IWDG_FEED_TIME_MS);
}
/** [src_mm32l373_hw_iwdg] */

/* end of file */
