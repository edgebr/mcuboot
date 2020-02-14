/*
 * Copyright (c) 2018 Trucks Control
 *
 */

#include <device.h>
#include <init.h>
#include <kernel.h>
#include <pinmux.h>
#include <pinmux/stm32/pinmux_stm32.h>
#include <sys_io.h>

/* pin assignments for NUCLEO-F413ZH board */
static const struct pin_config pinconf[] = {
#ifdef CONFIG_UART_2
    {STM32_PIN_PA2, STM32F4_PINMUX_FUNC_PA2_USART2_TX},
    {STM32_PIN_PA3, STM32F4_PINMUX_FUNC_PA3_USART2_RX},
#endif /* #ifdef CONFIG_UART_2 */

#ifdef CONFIG_UART_3
    {STM32_PIN_PC5, (STM32_PINMUX_ALT_FUNC_7 | STM32_PUSHPULL_PULLUP)},   // RX
    {STM32_PIN_PB10, (STM32_PINMUX_ALT_FUNC_7 | STM32_PUSHPULL_NOPULL)},  // TX
#endif                                                                    /* #ifdef CONFIG_UART_3 */

#ifdef CONFIG_UART_4
    {STM32_PIN_PA12, STM32F4_PINMUX_FUNC_PA12_UART4_TX},
    {STM32_PIN_PA11, STM32F4_PINMUX_FUNC_PA11_UART4_RX},
#endif /* #ifdef CONFIG_UART_4 */

#ifdef CONFIG_UART_5
    {STM32_PIN_PD2, (STM32_PINMUX_ALT_FUNC_8 | STM32_PUSHPULL_NOPULL)},   // RX
    {STM32_PIN_PC12, (STM32_PINMUX_ALT_FUNC_8 | STM32_PUSHPULL_NOPULL)},  // TX
#endif                                                                    /* #ifdef CONFIG_UART_5 */

#ifdef CONFIG_UART_6
    {STM32_PIN_PC6, STM32F4_PINMUX_FUNC_PC6_USART6_TX},
    {STM32_PIN_PC7, (STM32_PINMUX_ALT_FUNC_8 | STM32_PUPDR_NO_PULL)},
#endif /* #ifdef CONFIG_UART_6 */

#ifdef CONFIG_TC_HAS_ACCELEROMETER
#ifdef CONFIG_I2C_1
    {STM32_PIN_PB6, (STM32_PINMUX_ALT_FUNC_4 | STM32_OPENDRAIN_PULLUP)},  // SCL
    {STM32_PIN_PB7, (STM32_PINMUX_ALT_FUNC_4 | STM32_OPENDRAIN_PULLUP)},  // SDA
#endif
#endif  // CONFIG_TC_HAS_ACCELEROMETER
};

static int pinmux_stm32_init(struct device *port)
{
    ARG_UNUSED(port);

    stm32_setup_pins(pinconf, ARRAY_SIZE(pinconf));

    return 0;
}

SYS_INIT(pinmux_stm32_init, PRE_KERNEL_1, CONFIG_PINMUX_STM32_DEVICE_INITIALIZATION_PRIORITY);
