/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'Processor' in SOPC Builder design 'QsysSystem'
 * SOPC Builder design path: ../../QsysSystem.sopcinfo
 *
 * Generated: Thu Nov 03 10:42:40 PDT 2022
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00001820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1d
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EXCEPTION_ADDR 0x10000020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1d
#define ALT_CPU_NAME "Processor"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 0
#define ALT_CPU_RESET_ADDR 0x10000000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00001820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1d
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EXCEPTION_ADDR 0x10000020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1d
#define NIOS2_NUM_OF_SHADOW_REG_SETS 0
#define NIOS2_RESET_ADDR 0x10000000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS


/*
 * GREEN_LEDs configuration
 *
 */

#define ALT_MODULE_CLASS_GREEN_LEDs altera_avalon_pio
#define GREEN_LEDS_BASE 0x2060
#define GREEN_LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define GREEN_LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define GREEN_LEDS_CAPTURE 0
#define GREEN_LEDS_DATA_WIDTH 8
#define GREEN_LEDS_DO_TEST_BENCH_WIRING 0
#define GREEN_LEDS_DRIVEN_SIM_VALUE 0
#define GREEN_LEDS_EDGE_TYPE "NONE"
#define GREEN_LEDS_FREQ 50000000
#define GREEN_LEDS_HAS_IN 0
#define GREEN_LEDS_HAS_OUT 1
#define GREEN_LEDS_HAS_TRI 0
#define GREEN_LEDS_IRQ -1
#define GREEN_LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define GREEN_LEDS_IRQ_TYPE "NONE"
#define GREEN_LEDS_NAME "/dev/GREEN_LEDs"
#define GREEN_LEDS_RESET_VALUE 0
#define GREEN_LEDS_SPAN 16
#define GREEN_LEDS_TYPE "altera_avalon_pio"


/*
 * JTAG_UART configuration
 *
 */

#define ALT_MODULE_CLASS_JTAG_UART altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x2090
#define JTAG_UART_IRQ 1
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/JTAG_UART"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * KEYS configuration
 *
 */

#define ALT_MODULE_CLASS_KEYS altera_avalon_pio
#define KEYS_BASE 0x2020
#define KEYS_BIT_CLEARING_EDGE_REGISTER 0
#define KEYS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define KEYS_CAPTURE 1
#define KEYS_DATA_WIDTH 4
#define KEYS_DO_TEST_BENCH_WIRING 0
#define KEYS_DRIVEN_SIM_VALUE 0
#define KEYS_EDGE_TYPE "RISING"
#define KEYS_FREQ 50000000
#define KEYS_HAS_IN 1
#define KEYS_HAS_OUT 0
#define KEYS_HAS_TRI 0
#define KEYS_IRQ 2
#define KEYS_IRQ_INTERRUPT_CONTROLLER_ID 0
#define KEYS_IRQ_TYPE "EDGE"
#define KEYS_NAME "/dev/KEYS"
#define KEYS_RESET_VALUE 0
#define KEYS_SPAN 16
#define KEYS_TYPE "altera_avalon_pio"


/*
 * On_Chip_Mem configuration
 *
 */

#define ALT_MODULE_CLASS_On_Chip_Mem altera_avalon_onchip_memory2
#define ON_CHIP_MEM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ON_CHIP_MEM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ON_CHIP_MEM_BASE 0x0
#define ON_CHIP_MEM_CONTENTS_INFO ""
#define ON_CHIP_MEM_DUAL_PORT 0
#define ON_CHIP_MEM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ON_CHIP_MEM_INIT_CONTENTS_FILE "QsysSystem_On_Chip_Mem"
#define ON_CHIP_MEM_INIT_MEM_CONTENT 1
#define ON_CHIP_MEM_INSTANCE_ID "NONE"
#define ON_CHIP_MEM_IRQ -1
#define ON_CHIP_MEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ON_CHIP_MEM_NAME "/dev/On_Chip_Mem"
#define ON_CHIP_MEM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ON_CHIP_MEM_RAM_BLOCK_TYPE "AUTO"
#define ON_CHIP_MEM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ON_CHIP_MEM_SINGLE_CLOCK_OP 0
#define ON_CHIP_MEM_SIZE_MULTIPLE 1
#define ON_CHIP_MEM_SIZE_VALUE 4096
#define ON_CHIP_MEM_SPAN 4096
#define ON_CHIP_MEM_TYPE "altera_avalon_onchip_memory2"
#define ON_CHIP_MEM_WRITABLE 1


/*
 * RED_LEDs configuration
 *
 */

#define ALT_MODULE_CLASS_RED_LEDs altera_avalon_pio
#define RED_LEDS_BASE 0x2070
#define RED_LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define RED_LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define RED_LEDS_CAPTURE 0
#define RED_LEDS_DATA_WIDTH 18
#define RED_LEDS_DO_TEST_BENCH_WIRING 0
#define RED_LEDS_DRIVEN_SIM_VALUE 0
#define RED_LEDS_EDGE_TYPE "NONE"
#define RED_LEDS_FREQ 50000000
#define RED_LEDS_HAS_IN 0
#define RED_LEDS_HAS_OUT 1
#define RED_LEDS_HAS_TRI 0
#define RED_LEDS_IRQ -1
#define RED_LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RED_LEDS_IRQ_TYPE "NONE"
#define RED_LEDS_NAME "/dev/RED_LEDs"
#define RED_LEDS_RESET_VALUE 0
#define RED_LEDS_SPAN 16
#define RED_LEDS_TYPE "altera_avalon_pio"


/*
 * SDRAM configuration
 *
 */

#define ALT_MODULE_CLASS_SDRAM altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x10000000
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/SDRAM"
#define SDRAM_POWERUP_DELAY 100.0
#define SDRAM_REFRESH_PERIOD 7.8125
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x19
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 10
#define SDRAM_SDRAM_DATA_WIDTH 32
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 0
#define SDRAM_SPAN 134217728
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 5.4
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 15.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 15.0
#define SDRAM_T_WR 14.0


/*
 * SYSID configuration
 *
 */

#define ALT_MODULE_CLASS_SYSID altera_avalon_sysid_qsys
#define SYSID_BASE 0x2088
#define SYSID_ID 0
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/SYSID"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1667496464
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * SevSeg4MSB configuration
 *
 */

#define ALT_MODULE_CLASS_SevSeg4MSB altera_avalon_pio
#define SEVSEG4MSB_BASE 0x2030
#define SEVSEG4MSB_BIT_CLEARING_EDGE_REGISTER 0
#define SEVSEG4MSB_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEVSEG4MSB_CAPTURE 0
#define SEVSEG4MSB_DATA_WIDTH 32
#define SEVSEG4MSB_DO_TEST_BENCH_WIRING 0
#define SEVSEG4MSB_DRIVEN_SIM_VALUE 0
#define SEVSEG4MSB_EDGE_TYPE "NONE"
#define SEVSEG4MSB_FREQ 50000000
#define SEVSEG4MSB_HAS_IN 0
#define SEVSEG4MSB_HAS_OUT 1
#define SEVSEG4MSB_HAS_TRI 0
#define SEVSEG4MSB_IRQ -1
#define SEVSEG4MSB_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEVSEG4MSB_IRQ_TYPE "NONE"
#define SEVSEG4MSB_NAME "/dev/SevSeg4MSB"
#define SEVSEG4MSB_RESET_VALUE 0
#define SEVSEG4MSB_SPAN 16
#define SEVSEG4MSB_TYPE "altera_avalon_pio"


/*
 * SevSegment_4LSB configuration
 *
 */

#define ALT_MODULE_CLASS_SevSegment_4LSB altera_avalon_pio
#define SEVSEGMENT_4LSB_BASE 0x2050
#define SEVSEGMENT_4LSB_BIT_CLEARING_EDGE_REGISTER 0
#define SEVSEGMENT_4LSB_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SEVSEGMENT_4LSB_CAPTURE 0
#define SEVSEGMENT_4LSB_DATA_WIDTH 32
#define SEVSEGMENT_4LSB_DO_TEST_BENCH_WIRING 0
#define SEVSEGMENT_4LSB_DRIVEN_SIM_VALUE 0
#define SEVSEGMENT_4LSB_EDGE_TYPE "NONE"
#define SEVSEGMENT_4LSB_FREQ 50000000
#define SEVSEGMENT_4LSB_HAS_IN 0
#define SEVSEGMENT_4LSB_HAS_OUT 1
#define SEVSEGMENT_4LSB_HAS_TRI 0
#define SEVSEGMENT_4LSB_IRQ -1
#define SEVSEGMENT_4LSB_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SEVSEGMENT_4LSB_IRQ_TYPE "NONE"
#define SEVSEGMENT_4LSB_NAME "/dev/SevSegment_4LSB"
#define SEVSEGMENT_4LSB_RESET_VALUE 0
#define SEVSEGMENT_4LSB_SPAN 16
#define SEVSEGMENT_4LSB_TYPE "altera_avalon_pio"


/*
 * Switches configuration
 *
 */

#define ALT_MODULE_CLASS_Switches altera_avalon_pio
#define SWITCHES_BASE 0x2040
#define SWITCHES_BIT_CLEARING_EDGE_REGISTER 0
#define SWITCHES_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SWITCHES_CAPTURE 0
#define SWITCHES_DATA_WIDTH 18
#define SWITCHES_DO_TEST_BENCH_WIRING 0
#define SWITCHES_DRIVEN_SIM_VALUE 0
#define SWITCHES_EDGE_TYPE "NONE"
#define SWITCHES_FREQ 50000000
#define SWITCHES_HAS_IN 1
#define SWITCHES_HAS_OUT 0
#define SWITCHES_HAS_TRI 0
#define SWITCHES_IRQ -1
#define SWITCHES_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SWITCHES_IRQ_TYPE "NONE"
#define SWITCHES_NAME "/dev/Switches"
#define SWITCHES_RESET_VALUE 0
#define SWITCHES_SPAN 16
#define SWITCHES_TYPE "altera_avalon_pio"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/JTAG_UART"
#define ALT_STDERR_BASE 0x2090
#define ALT_STDERR_DEV JTAG_UART
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/JTAG_UART"
#define ALT_STDIN_BASE 0x2090
#define ALT_STDIN_DEV JTAG_UART
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/JTAG_UART"
#define ALT_STDOUT_BASE 0x2090
#define ALT_STDOUT_DEV JTAG_UART
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "QsysSystem"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0 altera_avalon_timer
#define TIMER_0_ALWAYS_RUN 0
#define TIMER_0_BASE 0x2000
#define TIMER_0_COUNTER_SIZE 32
#define TIMER_0_FIXED_PERIOD 0
#define TIMER_0_FREQ 50000000
#define TIMER_0_IRQ 0
#define TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_LOAD_VALUE 49999
#define TIMER_0_MULT 0.001
#define TIMER_0_NAME "/dev/timer_0"
#define TIMER_0_PERIOD 1
#define TIMER_0_PERIOD_UNITS "ms"
#define TIMER_0_RESET_OUTPUT 0
#define TIMER_0_SNAPSHOT 1
#define TIMER_0_SPAN 32
#define TIMER_0_TICKS_PER_SEC 1000
#define TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
