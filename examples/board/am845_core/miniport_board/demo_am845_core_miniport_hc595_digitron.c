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
 * \brief MiniPort-595 + MiniPort-View 例程，通过标准接口实现
 *
 * - 操作步骤
 *   1. 先将 MiniPort-595 扩展板直接与 AM845-Core 的 MiniPort 相连接；
 *   2. 将 MiniPort-View 扩展板与 MiniPort-595 接口相连接。
 *
 * - 实验现象：
 *   1. 可以看到数值 0 ~ 59 的秒计数器；
 *   2. 数值小于 30 时，个位闪烁，大于 30 时十位闪烁。
 *
 * \par 源代码
 * \snippet demo_am845_core_miniport_hc595_digitron.c src_am845_core_miniport_hc595_digitron
 *
 * \internal
 * \par Modification history
 * - 1.00 15-07-21  tee, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_am845_core_miniport_hc595_digitron
 * \copydoc demo_am845_core_miniport_hc595_digitron.c
 */

/** [src_am845_core_miniport_hc595_digitron] */
#include "ametal.h"
#include "am_vdebug.h"
#include "am_lpc84x_inst_init.h"
#include "demo_std_entries.h"

/**
 * \brief 例程入口
 */
void demo_am845_core_miniport_hc595_digitron_entry (void)
{
    AM_DBG_INFO("demo am845_core miniport hc595 digitron!\r\n");
    am_miniport_view_595_inst_init();

    demo_std_digitron_60s_counting_entry(0);
}
/** [src_am845_core_miniport_hc595_digitron] */

/* end of file */
