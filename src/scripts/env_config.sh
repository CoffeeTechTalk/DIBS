#!/bin/bash

# This script to be run inside the chroot environment, it will perform the following actions (AS ROOT):
# - Download the requested kernel
# - Download any requested packages
# - Uninstall any requested packages
# - add users and set their passwords
# - set the root password
# - set the hostname
# - set the locale
# - set the timezone
# - set the keyboard layout
# - set the network configuration
# - set the grub configuration
