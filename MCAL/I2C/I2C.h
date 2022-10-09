/*
 * I2C.h
 *
 *  Created on: Sep 29, 2021
 *      Author: omar
 */

#ifndef MCAL_I2C_I2C_H_
#define MCAL_I2C_I2C_H_



/*
 *
 *
 * #define I2C_START         0x08
#define I2C_REP_START     0x10
#define I2C_MT_SLA_W_ACK  0x18
#define I2C_MT_SLA_R_ACK  0x40
#define I2C_MT_DATA_ACK   0x28
#define I2C_MR_DATA_ACK   0x50
#define I2C_MR_DATA_NACK  0x58
*/

void I2C_Init();
void I2C_Start();
void I2C_Stop();
void I2C_Write(u8 data);
u8 I2C_Read_ACK();
u8 I2C_Read_NO_ACK();
u8 I2C_Status();





#endif /* MCAL_I2C_I2C_H_ */


