#ifndef __SPI_DRIVER_H
#define __SPI_DRIVER_H

// This file has been prepared for Doxygen automatic documentation generation.
/*! \file ********************************************************************
*
* Atmel Corporation
*
* \li File:               spi_via_usi_driver.c
* \li Compiler:           IAR EWAAVR 3.10c
* \li Support mail:       avr@atmel.com
*
* \li Supported devices:  All devices with Universal Serial Interface (USI)
*                         capabilities can be used.
*                         The example is written for ATmega169.
*
* \li AppNote:            AVR319 - Using the USI module for SPI communication.
*
* \li Description:        Example on how to use the USI module for communicating
*                         with SPI compatible devices. The functions and variables
*                         prefixed 'spiX_' can be renamed to be able to use several
*                         spi drivers (using different interfaces) with similar names.
*                         Some basic SPI knowledge is assumed.
*
*                         $Revision: 1.4 $
*                         $Date: Monday, September 13, 2004 12:08:54 UTC $
****************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>



/* USI port and pin definitions.
 */
#define USI_OUT_REG		PORTA	//!< USI port output register.
#define USI_IN_REG		PINA	//!< USI port input register.
#define USI_DIR_REG		DDRA	//!< USI port direction register.
#define USI_CLOCK_PIN	PA4		//!< USI clock I/O pin.
#define USI_DATAOUT_PIN	PA5		//!< USI data output pin.
#define USI_DATAIN_PIN	PA6		//!< USI data input pin.
#define USI_SS_PIN		PA7		//!< USI (Software) Slave Select pin.



/*  Speed configuration:
 *  Bits per second = CPUSPEED / PRESCALER / (COMPAREVALUE+1) / 2.
 *  Maximum = CPUSPEED / 64.
 */
#define TC0_PRESCALER_VALUE 256		//!< Must be 1, 8, 64, 256 or 1024.
#define TC0_COMPARE_VALUE   1		//!< Must be 0 to 255. Minimum 31 with prescaler CLK/1.




/*! \brief  Initialize USI as SPI master.
 *
 *  This function sets up all pin directions and module configurations.
 *  Use this function initially or when changing from slave to master mode.
 *  Note that the stored USIDR value is cleared.
 *
 *  \param spi_mode  Required SPI mode, must be 0 or 1.
 *  In external clock mode 0 (USICS0 = 0), DI is sampled at positive edges, and DO is
 *  changed (USI Data Register is shifted by one) at negative edges. In external clock
 *  mode 1 (USICS0 = 1) data is sampled at negative and output is changed at positive
 *  edges. The USI clock modes corresponds to the SPI data mode 0 and 1.
 */
void spiX_initmaster( char spi_mode );



/*! \brief  Initialize USI as SPI slave.
 *
 *  This function sets up all pin directions and module configurations.
 *  Use this function initially or when changing from master to slave mode.
 *  Note that the stored USIDR value is cleared.
 *
 *  \param spi_mode  Required SPI mode, must be 0 or 1.
 */
void spiX_initslave( char spi_mode );



/*! \brief  Put one byte on bus.
 *
 *  Use this function like you would write to the SPDR register in the native SPI module.
 *  Calling this function in master mode starts a transfer, while in slave mode, a
 *  byte will be prepared for the next transfer initiated by the master device.
 *  If a transfer is in progress, this function will set the write collision flag
 *  and return without altering the data registers.
 *
 *  \returns  0 if a write collision occurred, 1 otherwise.
 */
char spiX_put( unsigned char val );



/*! \brief  Get one byte from bus.
 *
 *  This function only returns the previous stored USIDR value.
 *  The transfer complete flag is not checked. Use this function
 *  like you would read from the SPDR register in the native SPI module.
 */
unsigned char spiX_get();



/*! \brief  Wait for transfer to complete.
 *
 *  This function waits until the transfer complete flag is set.
 *  Use this function like you would wait for the native SPI interrupt flag.
 */
void spiX_wait();

#endif
