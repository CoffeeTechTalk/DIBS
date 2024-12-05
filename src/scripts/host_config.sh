#!/bin/bash

# This script creates all the necessary files and directories for the host to be able to create the ISO
# first load using the TUI the user settings, please note that if a user manually uses this script
# with improper arguments, bad things might happen.

# Load all arguments that were passed to the script via the TUI
# $1 - The name of the project and as such the name of its root directory
# $2 - The name of the project directory
# $3 - The name of the desired Debian flavor
if [ -z "$1" ]
then
    echo "Host Config Error: No project name supplied." >&2
    exit 1
else
  project_name=$1
fi

if [ -z "$2" ]
then
    echo "Host Config Error: No project directory supplied." >&2
    exit 1
else
  project_path=$2/$project_name
fi

if [ -z "$3" ]
then
    echo "Host Config Error: No Debian flavor supplied." >&2
    exit 1
else
  deb_flavor=$3
fi


# Create the necessary directories

# Prepare