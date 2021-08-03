#
# Demo GPIO
#
# Copyright (C) 2019-2020, Hensoldt Cyber GmbH
#

cmake_minimum_required(VERSION 3.17)

os_set_config_file(system_config.h)

#-------------------------------------------------------------------------------
project(demo_mailbox C)

DeclareCAmkESComponent(
    RPi_MAILBOX
    SOURCES
        ./main.c
    INCLUDES
        ./
        ./plat/${PLATFORM}
        # no include paths needed
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
