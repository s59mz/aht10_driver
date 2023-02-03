/*  Demo application for AHT10 sensor
 *
 *  Copyright (C) 2023 Matjaz Zibert - S59MZ
 *
 *  Linux app for device driver
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>

#include "../aht10_ioctl.h"

int main(int argc, char **argv) {

	int fd;
	int ret;
	struct ioctl_dev ioctl_dev;
	float temp;
	float humd;

	if (argc !=3) {
		printf("Use aht 1|2 read\n");
		return 0;
	}

	if (!strcmp(argv[1], "1")) {
		fd = open("/dev/aht10mz38", O_RDWR);
	}
	else if (!strcmp(argv[1], "2")) {
		fd = open("/dev/aht10mz39", O_RDWR);
	}
	else {
		printf("Use aht 1|2 read\n");
		return 0;
	}


	if (fd <= 0) {
		printf("Can't open fd = %d\n", fd);
	}

	if (!strcmp(argv[2], "reset")) {

		ret = ioctl(fd, IOCTL_AHT10_RESET, &ioctl_dev);

	} else if (!strcmp(argv[2], "init")) {
	
		ret = ioctl(fd, IOCTL_AHT10_INIT, &ioctl_dev);

	} else if (!strcmp(argv[2], "read")) {
	
		ret = ioctl(fd, IOCTL_AHT10_READ, &ioctl_dev);

	} else {
		printf("Use aht 1|2 reset|init|read\n");
		close(fd);
		return 0;
	}

	if (ret < 0) {
		printf("Can't ioctl, ret = %d\n", ret);
		close(fd);
		return 0;
	}

	ret = close(fd);

	if (ret < 0) {
		printf("Can't close, ret = %d\n", ret);
	}

	if (strcmp(argv[2], "read"))
		return 0;

	temp = (float) ((200 * (float) ioctl_dev.temp) / 1048576.0) - 50;
	humd = (100 * (float) ioctl_dev.humd) / 1048576;

	printf("Temp: %.3f'C,\tHumd: %f\n", temp, humd);
	
	return 0;
}
