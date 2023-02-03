# aht10_driver
Linux device driver for AHT10 temperature sensor

### Compiling the module for Linux (arm64)
export ARCH=arm64

export CROSS_COMPILE=aarch64-linux-gnu-

export LINUX_DIR="*path-to-linux-precompiled-headers*"

make

### Compile the device tree overlay
dtc -@ -I dts -O dtb -o aht10_overlay.dtbo aht10_overlay.dts

### Compile the demo app
cd app

make

### Install the module on target (Raspberry Pi 4):
sudo dtoverlay aht10_overlay.dtbo

dtoverlay -l

sudo insmod aht10.ko

dmesg | tail

### Run the demo app on target
sudo ./aht

### NOTE
The floating point temperature calculation is done in the demo app (in Linux User Space).

### Remove the Module and Overlay
sudo rmmod aht10

sudo dtoverlay -d aht10_overlay

