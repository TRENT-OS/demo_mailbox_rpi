#
# Demo GPIO
#
# Copyright (C) 2020-2024, HENSOLDT Cyber GmbH
# 
# SPDX-License-Identifier: GPL-2.0-or-later
#
# For commercial licensing, contact: info.cyber@hensoldt.net
#

cmake_minimum_required(VERSION 3.17)

#-------------------------------------------------------------------------------
# use the SDK
find_package("os-sdk" REQUIRED)
os_sdk_set_defaults()
os_sdk_setup(CONFIG_FILE "system_config.h" CONFIG_PROJECT "system_config")

# Set additional include paths.
CAmkESAddCPPInclude("plat/${PLATFORM}")

#-------------------------------------------------------------------------------
project(demo_mailbox C)

DeclareCAmkESComponent(
    RPi_MAILBOX
    SOURCES
        main.c
    INCLUDES
        # no include paths needed
    C_FLAGS
        -Wall
        -Werror
    LIBS
        os_core_api
        lib_debug
        platsupport
)

os_sdk_create_CAmkES_system("demo_mailbox.camkes")
