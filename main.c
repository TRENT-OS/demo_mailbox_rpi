/**
 * Copyright (C) 2019-2020, Hensoldt Cyber GmbH
 */

#include <plat.h>
#include <stdio.h>
#include <lib_debug/Debug.h>

#include <camkes.h>
#include <camkes/io.h>

mailbox_t           mbox;
ps_io_ops_t         io_ops;
mailbox_functions_t mbox_func;

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

    plat_init(&mbox_func);

    Debug_LOG_INFO("%s done",__func__);
}

int run()
{
    // Test bcmxxxx_get_clock_rate()
    Debug_LOG_DEBUG("Test 1: x_get_clock_rate()");
    Debug_LOG_DEBUG("EMMC clock rate: %d",(&mbox_func)->get_clock_rate(&mbox,CLOCK_ID_EMMC));
    Debug_LOG_DEBUG("UART clock rate: %d",(&mbox_func)->get_clock_rate(&mbox,CLOCK_ID_UART));
    Debug_LOG_DEBUG("ARM clock rate: %d",(&mbox_func)->get_clock_rate(&mbox,CLOCK_ID_ARM));
    Debug_LOG_DEBUG("CORE clock rate: %d",(&mbox_func)->get_clock_rate(&mbox,CLOCK_ID_CORE));

    Debug_LOG_DEBUG("Test x_get_clock_rate() passed!\n\n");


    // Test bcmxxxx_get_mac_address()
    Debug_LOG_DEBUG("Test 2: x_get_mac_address()");
    uint8_t mac_address[6] = {0};
    (&mbox_func)->get_mac_address(&mbox,mac_address);
    Debug_LOG_DEBUG("Board MAC address is: %2x:%2x:%2x:%2x:%2x:%2x",
                    mac_address[0],mac_address[1],mac_address[2],
                    mac_address[3],mac_address[4],mac_address[5]
                    );

    Debug_LOG_DEBUG("Test x_get_mac_address() passed!\n\n");

    Debug_LOG_DEBUG("All tests passed!");

    return 0;
}
