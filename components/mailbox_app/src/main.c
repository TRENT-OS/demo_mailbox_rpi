/**
 * Copyright (C) 2019-2020, Hensoldt Cyber GmbH
 */

#include <stdio.h>
#include <lib_debug/Debug.h>

#include <platsupport/plat/mailbox.h>
#include <platsupport/plat/mailbox_util.h>

#include <camkes.h>
#include <camkes/io.h>

mailbox_t           mbox;
ps_io_ops_t         io_ops;

void post_init(void)
{
    Debug_LOG_DEBUG("[%s] %s", get_instance_name(), __func__);

    int ret = camkes_io_ops(&io_ops);
    if (ret )
    {
        Debug_LOG_ERROR("camkes_io_ops() failed: rslt = %i", ret);
        return;
    }

    //gpio initialization
    ret = mailbox_init(&io_ops,&mbox);
    if(ret < 0)
    {
        ZF_LOGE("Failed to initialize mailbox.");
        return;
    }

    Debug_LOG_INFO("%s done",__func__);
}

int run()
{
    // Test bcm2837_get_clock_rate()
    Debug_LOG_DEBUG("EMMC clock rate: %d",bcm2837_get_clock_rate(&mbox,CLOCK_ID_EMMC));
    Debug_LOG_DEBUG("UART clock rate: %d",bcm2837_get_clock_rate(&mbox,CLOCK_ID_UART));
    Debug_LOG_DEBUG("ARM clock rate: %d",bcm2837_get_clock_rate(&mbox,CLOCK_ID_ARM));
    Debug_LOG_DEBUG("CORE clock rate: %d",bcm2837_get_clock_rate(&mbox,CLOCK_ID_CORE));

    return 0;
}
