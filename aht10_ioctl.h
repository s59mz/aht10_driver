/*  The simplest kernel module.
 *
 *  Copyright (C) 2023 Matjaz Zibert - S59MZ
 *
 *  Linux I2C device driver for AHT10 temperature sensor
 */

#ifndef __AHT10_IOCTL_H_MZ__
#define __AHT10_IOCTL_H_MZ__

#include <linux/ioctl.h>

#define IOCTL_AHT10_RESET	_IO('M', 1)
#define IOCTL_AHT10_INIT	_IO('M', 2)
#define IOCTL_AHT10_READ	_IOR('M', 3, struct ioctl_dev)

// convert tempereture register value to Celsius degrees
#define convert_temp(x)		((float) ((200 * (float) (x)) / 1048576) - 50)

// convert humidity register value to %RH
#define convert_humd(x)		((100 * (float) (x)) / 1048576)

struct ioctl_dev {
	unsigned int temp;	// temperature reg data - need to be converted
	unsigned int humd;	// humidity reg data - need to be converted
};

#endif
