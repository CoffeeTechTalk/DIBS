#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <cstdlib>
#include "../cfg/iniMan.hpp"

class sysHandler{
public:
    // Constructor

    // Getters

    // Setters

    // Methods - Rootfs
    bool init();       // create project root then exit
    bool bootstrap();  // debootstrap
    bool copyFiles();  // copy user files to rootfs
    bool createBoot(); // create boot configuration
    bool createISO();  // create ISO image

private:
    std::string currentDir;
    std::string homeDir;
    std::string projectRoot; // post-init creates a directory for the project
    bool dirOK;
    std::vector<std::string> files;

};