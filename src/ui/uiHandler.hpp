#pragma once

#include <ncursesw/ncurses.h> // possibly windows related problem #TODO: test on linux to see if ncurses/ is needed
#include <string>
#include <vector>
#include <iostream>

/*
██╗   ██╗██╗
██║   ██║██║
██║   ██║██║
██║   ██║██║
╚██████╔╝██║
 ╚═════╝ ╚═╝
Libary for handling the TUI
Author: Aharon B.
Date: 2024-12-06
The TUI should look something like this:
+---------------------------------+
| "Logo"         |                |
|                |                |
| "Setting1"     |                |
| "Setting2"     |                |
|  .             |                |
|  .             |                |
|  .             |                |
|_________________________________|
| status and stuff                |
+---------------------------------+
only now do I relise the amount of work i created for myself :(
*/
class filePicker{
// TODO: submenu with a simple file picker, or just use user input idc
};

class Option {
public:
    // Constructors
    option(std::string title, std::string value);
    option(std::string title);

    // Getters
    inline std::string getTitle() const;
    inline std::string getValue() const;
    inline bool getIsEditable() const;

    // Setters
    void setTitle(std::string title);
    void setValue(std::string value);
    void setIsEditable(bool isEditable);

    // Methods
    void drawOption();
};

class Menu {
public:
    // Constructors
    menu(std::string title, std::vector<Option> options);
    menu(std::string title);

    // Getters
    inline std::string getTitle() const;
    std::vector<std::string> getOptions() const;
    inline size_t getNumOptions() const;
    void *getSubMenu() const;

    // Setters
    void setTitle(std::string title);
    void setOptions(std::vector<std::string> options);
    void addOption(std::string option);
    void setSubMenu(void *subMenu);

    // Methods
    void drawMenu();
private:
    std::string title;
    std::vector<std::string> options;
    size_t numOptions = 0;
    void *subMenu; // point to submenu, IE left menu option pointing to right hand menu or pop up


};

class PopUp {
    // TODO: submenu that pops up and asks for basic user input
};

/*
uiHandler is the main class for handling the TUI, it holds the main window
and all the menus, it also handles the input and output to the TUI

uiHandler holds menu classes each representing a setting that can be interacted with
*/
class uiHandler {

};
