#ifndef LSM6DS33_H_
#define LSM6DS33_H_

#include "stm32f1xx_hal.h"
#include "main.h"

#define FUNC_CFG_ACCESS					0x01
#define FIFO_CTRL1							0x06
#define FIFO_CTRL2							0x07
#define FIFO_CTRL3							0x08
#define FIFO_CTRL4							0x09
#define FIFO_CTRL5							0x0A
#define ORIENT_CFG_G 						0x0B
#define	INT1_CTRL								0x0D
#define INT2_CTRL								0x0E
#define WHO_AM_I								0x0F
#define CTRL1_XL         				0x10
#define CTRL2_G           			0x11
#define CTRL3_C           			0x12
#define LSM6DS33_ADDR						0xD6
#define CTRL9_XL								0x18
#define CTRL10_C								0x19

#define STATUS_REG							0x1e

#define OUTX_L_G								0x22
#define OUTX_H_G								0x23
#define OUTY_L_G								0x24
#define OUTY_H_G								0x25
#define OUTZ_L_G								0x26
#define OUTZ_H_G								0x27
#define OUTX_L_XL								0x28
#define OUTX_H_XL								0x29
#define OUTY_L_XL								0x2a
#define OUTY_H_XL								0x2b
#define OUTZ_L_XL								0x2c
#define OUTZ_H_XL								0x2d

#define TAP_CFG									0x58
#define TAP_THS_6D							0x59
#define INT_DUR2								0x5a
#define WAKE_UP_THS							0x5b
#define WAKE_UP_DUR							0x5c
#define FREE_FALL								0x5d
#define MD1_CFG									0x5e
#define MD2_CFG									0x5f

void lsm6ds33_init(void);
void lsm6ds33_inactivity(void);

#endif /* LSM6DS33_H_ */
