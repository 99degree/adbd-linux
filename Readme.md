# Limitation
Openssl version < 1.1, must be 1.0, as the 1.1 has broken API

# Info
Base on:https://github.com/hadess/adbd

Modify for Yocto building and common Linux based OS.

# Compiling in normal Linux OS
```
RANLIB=ranlib AR=ar CXX=g++ CC=gcc make
```
# Usage
	PostmarketOS loaded into target device storage
	Compile as static bin and put it in target device /sbin
	Do chmod a+x /sbin/adbd
	Add adbd --device_banner=device& into device init script
	Host pc do adb connect 172.16.42.1 5555
	then do adb devices
	List of devices attached
	172.16.42.1:5555        device
	adb shell date
	Sat Jan  9 02:32:26 GMT 1971


