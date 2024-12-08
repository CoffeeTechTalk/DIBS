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
*/
class filePicker{

};

class menu {

};

class popUp {

};

/*
uiHandler is the main class for handling the TUI, it holds the main window
and all the menus, it also handles the input and output to the TUI

uiHandler holds menu classes each representing a setting that can be interacted with
*/
class uiHandler {

};
