set(CONF_FILE prj.conf)

if(CONFIG_TC_HAS_GPS OR CONFIG_TC_HAS_ACCELEROMETER OR CONFIG_TC_USER_DEBUG OR CONFIG_TC_VARIANT_RS485 OR CONFIG_TC_JIGA_REF)
message("\n!!! A PLACA GERADA É UMA VARIANTE.\n")

set(OVERLAYS "")
if(CONFIG_TC_HAS_GPS)
    list(APPEND OVERLAYS
       " ${CMAKE_CURRENT_LIST_DIR}/boards/arm/tc_ext_p3/variants/gps.overlay"
    )
    list(APPEND SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/src/tc_gps_thread.c"
    )
    message(" + GPS enabled")
endif()
if(CONFIG_TC_HAS_ACCELEROMETER)
    list(APPEND OVERLAYS
    " ${CMAKE_CURRENT_LIST_DIR}/boards/arm/tc_ext_p3/variants/accelerometer.overlay"
    )
    list(APPEND CONF_FILE " ${CMAKE_CURRENT_LIST_DIR}/boards/arm/tc_ext_p3/variants/accelerometer.conf")
    message(" + Accelerometer enabled")
endif()
if(CONFIG_TC_USER_DEBUG)
    list(APPEND OVERLAYS
    " ${CMAKE_CURRENT_LIST_DIR}/boards/arm/tc_ext_p3/variants/user_debug.overlay"
    )
    list(APPEND CONF_FILE " ${CMAKE_CURRENT_LIST_DIR}/boards/arm/tc_ext_p3/variants/user_debug.conf")
    message(" + User debug enabled")
endif()

if(CONFIG_TC_JIGA_REF)
    list(APPEND OVERLAYS
    " ${CMAKE_CURRENT_LIST_DIR}/boards/arm/tc_ext_p3/variants/tc_jiga_ref.overlay"
    )
    list(APPEND CONF_FILE " ${CMAKE_CURRENT_LIST_DIR}/boards/arm/tc_ext_p3/variants/tc_jiga_ref.conf")
    message(" + TC Jiga Reference")
endif()  

if(CONFIG_TC_VARIANT_RS485)
    message(" + RS485 enabled / RS232 disabled")
endif()

if(CONFIG_TC_FW_UPDATE)
    list(APPEND OVERLAYS
    " ${CMAKE_CURRENT_LIST_DIR}/boards/arm/tc_ext_p3/variants/fw_update.overlay"
    )
    list(APPEND CONF_FILE " ${CMAKE_CURRENT_LIST_DIR}/boards/arm/tc_ext_p3/variants/fw_update.conf")
    message(" + Firmware update enabled")
endif()

message(" > Overlays set: ${OVERLAYS}\n")
set(DTC_OVERLAY_FILE ${OVERLAYS})

endif()


