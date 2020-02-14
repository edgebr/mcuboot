/*
 * Copyright (c) 2018 STMicroelectronics
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * This file is a temporary workaround for mapping of the generated information
 * to the current driver definitions.  This will be removed when the drivers
 * are modified to handle the generated information, or the mapping of
 * generated data matches the driver definitions.
 */

#define DT_UART_STM32_UART_5_BASE_ADDRESS DT_ST_STM32_UART_40005000_BASE_ADDRESS
#define DT_UART_STM32_UART_5_BAUD_RATE DT_ST_STM32_UART_40005000_CURRENT_SPEED
#define DT_UART_STM32_UART_5_NAME DT_ST_STM32_UART_40005000_LABEL
#define DT_UART_STM32_UART_5_IRQ_PRI DT_ST_STM32_UART_40005000_IRQ_0_PRIORITY
#define DT_UART_STM32_UART_5_CLOCK_BITS DT_ST_STM32_UART_40005000_CLOCK_BITS
#define DT_UART_STM32_UART_5_CLOCK_BUS DT_ST_STM32_UART_40005000_CLOCK_BUS
#define DT_UART_STM32_UART_5_HW_FLOW_CONTROL DT_ST_STM32_UART_40005000_HW_FLOW_CONTROL
#define DT_UART_5_IRQ DT_ST_STM32_UART_40005000_IRQ_0
