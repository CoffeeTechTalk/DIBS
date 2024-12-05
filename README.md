# DIBS
DIBS (Debian ISO Builder Suite) is a set of helper scripts packaged with a TUI application to create a custom Debian-live ISO.

**DISCLAIMER:** I am in no way responsible for anything that happens to your machine if you run this, I will implement basic checks and stops, but nothing more, the code is designed to make **BIG** changes to whichever directory you point it into, along with changes that have system-wide consequences.

As such if you make changes yourself you are the sole beneficiary of any headache your changes cause.

## 1. Why?
The main inspiration for this project has been my personal experience on embedded projects where a semi-minimal non-persistent OS is needed and experimentation with packages is impossible due to a lack of internet connection.

## 2. How?
### 2.1. Build Dependencies
* g++
* libncurses5

### 2.2. Run Dependencies
The dependencies to run the scripts are as ***Tested on Debian 12***:
* awk
* bash

### 2.2. Configuration
Configuration is done through a terminal user interface (TUI), using a static binary, DIBS creates a configuration file that helper scripts then read and

#### 2.2.1. Settings
The supported settings are:
* Set name of project and final ISO
* Pick a flavor of Debian
* Add new user
* Manage users, passwords and groups
* Manage list of additional packages including [offline packages](#231-offline-packages)
* 

### 2.3. Advanced Configuration
If you need to setup additional functionality beyond what is available via apt-get, then this is the section for you!

#### 2.3.1. User Files
Additional user files and directories may be added by placing them in the **user** directory, by default the content of this directory will be copied to **/usr/DIBS** within the new filesystem.

To pick a specific location for each file or directory, simply use the file picker under "User Files" in the TUI.

#### 2.3.1. Offline packages
#### 2.3.1. Networking

## 3. Special Thanks

## 4. Who?

## 5. DISCLAIMER
I am in no way responsible for anything that happens to your machine if you run this program.

The only guarantee I'll provide is that I personally use it.

I have implemented basic checks and stops, but nothing more, the code is designed to make **BIG** changes to whichever directory you point it into, along with changes that have system-wide consequences, point it in the wrong direction, and you will be
