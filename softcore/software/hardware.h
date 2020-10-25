/*
 * hardware.h
 *
 *  Created on: May 20, 2019
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 * 
 * 
 * riscv-multicycle Hardware Map (registers)
 * -----------------------------------------
 * IO MAP mapped to  addr >= 0x4000000 
 * 
 * 
 */


#ifndef __HARDWARE_H
#define __HARDWARE_H

#include <stdint.h>

#define CPU_CLOCK 1000000     /*!< PLL is adjusted to 1 MHz */

#ifndef _IO
#define _IO volatile uint8_t
#endif

#define _IO8 _IO

#ifndef _IO16
#define _IO16 volatile uint16_t
#endif

#ifndef _IO32
#define _IO32 volatile uint32_t
#endif

#ifndef _IO32S
#define _IO32S volatile int32_t
#endif

#define PERIPH_BASE		((uint32_t)0x4000000)          /*!< Peripheral base address */
#define SDRAM_BASE		((uint32_t)0x6000000)          /*!< Peripheral base address */

#define SDRAM 			(*(_IO32 *) (SDRAM_BASE))		/*!< SDRAM base address */

#define INBUS 			(*(_IO32 *) (PERIPH_BASE))			/*!< Generic INPUT BUS - 32-bit register */
#define OUTBUS			(*(_IO32 *) (PERIPH_BASE + 4))		/*!< Generic OUPUT BUS - 32-bit register */
#define SEGMENTS		(*(_IO32 *) (PERIPH_BASE + 8))		/*!< Generic INPUT BUS - 32-bit register */
#define UART_TX			(*(_IO32 *) (PERIPH_BASE + 12))		/*!< Generic INPUT BUS - 32-bit register */
#define UART_RX			(*(_IO32 *) (PERIPH_BASE + 16))		/*!< Generic INPUT BUS - 32-bit register */
#define INDATA_ADC		(*(_IO32 *) (PERIPH_BASE + 20))		/*!< Generic INPUT BUS - 32-bit register */
#define CH_ADC_FEED		(*(_IO32 *) (PERIPH_BASE + 24))		/*!< Generic OUPUT BUS - 32-bit register */
#define SEL_CH_ADC		(*(_IO32 *) (PERIPH_BASE + 28))	
#define I2C				(*(_IO32 *) (PERIPH_BASE + 32))	

#define TIMER_ADDRESS			(*(_IO32 *) (PERIPH_BASE + 32))		/*!< Generic INPUT BUS - 32-bit register */
//#define TIMER_RESERVED	(TIMER + 32)

#define SPI_TX		(*(_IO32 *) (PERIPH_BASE + 32))	
#define SPI_RX		(*(_IO32 *) (PERIPH_BASE + 36))	

#define TFT_DATA0		(*(_IO32 *) (PERIPH_BASE + 32))	
#define TFT_DATA1		(*(_IO32 *) (PERIPH_BASE + 36))
#define TFT_DATA2		(*(_IO32 *) (PERIPH_BASE + 40))	
#define TFT_RETURN		(*(_IO32 *) (PERIPH_BASE + 44))	
	
#define DIG_FILT_CTRL   (*(_IO32 *) (PERIPH_BASE + 80))
#define DIG_FILT_IN     (*(_IO32 *) (PERIPH_BASE + 84))
#define DIG_FILT_OUT    (*(_IO32 *) (PERIPH_BASE + 88))	



#endif //HARDWARE_H
