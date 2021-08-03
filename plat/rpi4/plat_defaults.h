/* Copyright (C) 2020, HENSOLDT Cyber GmbH */

/**
 * @file
 * @brief The main mailbox component
 */

#pragma once

// NOTE: VideoCore has this at 0x7E00b000
#define RPi_MAILBOX_HW_BCM2837_DATAPORT_PADDR     0xfe00b000
#define RPi_MAILBOX_HW_BCM2837_DATAPORT_SIZE      0x1000

#define RPi_MAILBOX_HW_COMPONENT_DEFINE( \
    _name_) \
    \
    component _name_ { \
        hardware; \
        dataport  Buf(RPi_MAILBOX_HW_BCM2837_DATAPORT_SIZE)  regBase; \
    }

#define RPi_MAILBOX_COMPONENT_DEFINE( \
    _name_) \
    \
    component _name_ { \
        control; \
        dataport  Buf(RPi_MAILBOX_HW_BCM2837_DATAPORT_SIZE)  regBase; \
    }

#define RPi_MAILBOX_INSTANCE_CONNECT( \
    _inst_, \
    _inst_hw_) \
    \
    connection seL4HardwareMMIO \
        _inst_ ## _mmio( \
            from _inst_.regBase, \
            to   _inst_hw_.regBase \
        );

#define RPi_MAILBOX_HW_INSTANCE_CONFIGURE_SELF( \
    _inst_) \
    \
    _inst_.regBase_paddr  = RPi_MAILBOX_HW_BCM2837_DATAPORT_PADDR; \
    _inst_.regBase_size   = RPi_MAILBOX_HW_BCM2837_DATAPORT_SIZE;

#define CONFIGURE_INSTANCE_MAILBOX_DRV( \
            _inst_drv_, \
            _dma_size_) \
    \
    _inst_drv_.dma_pool  = _dma_size_;
