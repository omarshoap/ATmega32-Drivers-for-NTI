/*
 * SPI.c
 *
 *  Created on: Sep 27, 2021
 *      Author: omar
 */


#include "REG.h"
#include "BIT_MATH.h"
#include "DIO.h"


#include "SPI.h"
#include "SPI_CFG.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define SPR0  0
#define SPR1  1
#define CPHA  2
#define CPOL  3
#define MSTR  4
#define DORD  5
#define SPE   6
#define SPIE  7

void SPI_INIT(void)
{
	/* Set MOSI and SCK output, all others input */
	DIO_PIN_DIRECTION(DIO_PORTB,5,OUTPUT);
	DIO_PIN_DIRECTION(DIO_PORTB,7,OUTPUT);
	/* Enable SPI, Master, set clock rate fck/16 */
	SET_BIT(SPCR,SPIE);  // to intrrupt enable
	SET_BIT(SPCR,SPE);   // to spi enable
	CLR_BIT(SPCR,DORD);  // data order MSB
	SET_BIT(SPCR,MSTR);  // master slave select
	CLR_BIT(SPCR,CPOL);  // falling or rising
	CLR_BIT(SPCR,CPHA);  // setup or sample
	SET_BIT(SPCR,SPR0);  // clock prescaler F/128
	SET_BIT(SPCR,SPR1);


}


//***** this was copy paste *****//

/*void SPI_MasterInit(void){
	/* Set MOSI and SCK output, all others input */
//	DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK);
	/* Enable SPI, Master, set clock rate fck/16 */
//	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
//}
//void SPI_MasterTransmit(char cData){
	/* Start transmission */
//	SPDR = cData;
	/* Wait for transmission complete */
//	while(!(SPSR & (1<<SPIF)));
//}
//void SPI_SlaveInit(void){
	/* Set MISO output, all others input */
//	DDR_SPI = (1<<DD_MISO);
	/* Enable SPI */
//	SPCR = (1<<SPE);
//}
//char SPI_SlaveReceive(void){
	/* Wait for reception complete */
//	while(!(SPSR & (1<<SPIF)));
	/* Return data register */
//	return SPDR;
//}






