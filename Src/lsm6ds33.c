#include "lsm6ds33.h"

extern I2C_HandleTypeDef hi2c1;

void lsm_write_reg(uint8_t reg, uint8_t value)
{
	HAL_I2C_Mem_Write(&hi2c1, LSM6DS33_ADDR, reg, 1, &value, sizeof(value), 100);
}

uint8_t lsm_read_reg(uint8_t reg)
{
	uint8_t value = 0;

	HAL_I2C_Mem_Read(&hi2c1, LSM6DS33_ADDR, reg, 1, &value, sizeof(value), 100);

	return value;
}

int16_t lsm_read_value(uint8_t reg)
{
	int16_t value = 0;

	HAL_I2C_Mem_Read(&hi2c1, LSM6DS33_ADDR, reg | 0x80, 1, (uint8_t*)&value, sizeof(value), 100);

	return value;
}

void lsm6ds33_init(void)
{
	// ODR: 416Hz, Full-scale: 8g, BW_XL: 200Hz
	lsm_write_reg(CTRL1_XL, 0x6D);
	// Enable tap detection on X, Y, Z axis
	lsm_write_reg(TAP_CFG, 0x0E);
	// Set tap threshold
	lsm_write_reg(TAP_THS_6D, 0x03);
	// Set Duration, Quite and Shock time windows
	lsm_write_reg(INT_DUR2, 0x7F);
	// Single tap enabled (SINGLE_DOUBLE_TAP = 0)
	lsm_write_reg(WAKE_UP_THS, 0x00);
	// Single tap interrupt driven to INT1 pin -- enable latch
	lsm_write_reg(MD1_CFG, 0x40);
}

void lsm6ds33_inactivity(void)
{
	lsm_write_reg(CTRL1_XL, 0x60);
	lsm_write_reg(WAKE_UP_DUR, 0x00);
	lsm_write_reg(WAKE_UP_THS, 0x42);
	lsm_write_reg(MD1_CFG, 0x80);
}