/*
 * I2C.c
 *
 *  Created on: Sep 29, 2021
 *      Author: omar
 */
#include "REG.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C.h"

/************************* start eng fatmat ************************/

void TWI_INIT_MASTER(u8 Master_Address)
{
	SET_BIT(TWCR,6);	// enabel ack bit
	TWBR = 0x02; // bit rate value from the formula

	CLR_BIT(TWSR,0) ;	// set prescaller
	CLR_BIT(TWSR,1) ;	// set prescaller
	SET_BIT(TWCR,2) ;	// i2c enable bit
	// check if the master node will be addressed

	if (Master_Address != 0 )
	{
		TWAR = (Master_Address << 1) ;
	}

	else
	{
		// do nothing

	}

}









/************************* end eng fatma *****************************/


void I2C_Init()
{

	TWBR = 0x02; // bit rate value from the formula

	SET_BIT(TWCR,0); // Interrupt enable
	SET_BIT(SREG,7); // to enable global interrupt
	SET_BIT(TWCR,2); // i2c enable bit

	TWSR = 0x00; // too zeros the Status register
//	TWAR = 0b00000010; // he give an address to the slave register
}

void I2C_Start()
{
	/*TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(Bit_Is_Clear(TWCR,TWINT));*/
}

void I2C_Stop()
{
	//TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void I2C_Write(u8 data)
{
	/*TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(Bit_Is_Clear(TWCR,TWINT));*/
}

u8 I2C_Read_ACK()
{
	/*TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(Bit_Is_Clear(TWCR,TWINT));
	return TWDR;*/
}

u8 I2C_Read_NO_ACK()
{
	/*TWCR = (1<<TWINT)|(1<<TWEN);
	while(Bit_Is_Clear(TWCR,TWINT));*/
	return TWDR;
}

u8 I2C_Status()
{
	/*uint8 status;
	status = (TWSR & 0xF8);
	return status;*/
}
