#!/bin/bash

# This script creates all the necessary files and directories for the host to be able to create the ISO
# first load using the TUI the user settings, please note that if a user manually uses this script
# with improper arguments, bad things might happen.

# the script performs the following actions:
# Load all arguments that were passed to the script via the TUI
# - Create the necessary directories
# - Perform debootstrap to create the initial rootfs
# - Copy extra user files to the rootfs

## Default values
current_directory=$(pwd)
default_project_name="DIBS_Project"
default_project_root="."
default_deb_flavor=buster


# Load all arguments that were passed to the script via the TUI
# $1 - The name of the project and as such the name of its root directory
# $2 - The name of the project directory
# $3 - The name of the desired Debian flavor
if [ -z "$1" ]
then
  echo "Host Config Error: No project name supplied." >&2
  project_name=${default_project_name}
  echo "Host Config Info: Setting project name to '${project_name}'."
else
  project_name=$1
fi

if [ -z "$2" ]
then
  echo "Host Config Error: No project directory supplied." >&2
  project_root="."
  project_path="${project_root}/${project_name}"
  echo "Host Config Info: Setting project path to ${project_root}."
else
  project_root=$2
  project_path="${project_root}/${project_name}"
fi

if [ -z "$3" ]
then
  echo "Host Config Error: No Debian flavor supplied." >&2
  deb_flavor=buster
  echo "Host Config Info: Setting Debian flavor to '${deb_flavor}'."
else
  deb_flavor=$3
fi


# Create the necessary directories
mkdir -p ${project_path}
cd ${project_path}
mkdir -p rootfs iso/live iso/boot/grub
