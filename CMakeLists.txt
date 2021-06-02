#
# Demo GPIO
#
# Copyright (C) 2019-2020, Hensoldt Cyber GmbH
#

cmake_minimum_required(VERSION 3.7.2)

os_set_config_file(system_config.h)

#-------------------------------------------------------------------------------
project(demo_mailbox C)

DeclareCAmkESComponent(
    RPi_MAILBOX
    INCLUDES
        # no include paths needed
    SOURCES
        components/mailbox_app/src/main.c
    C_FLAGS
        -Wall
        -Werror
    LIBS
        os_core_api
        lib_debug
        platsupport
)

DeclareAndCreateCamkESSystem(demo_mailbox.camkes)
GenerateSimulateScript()
