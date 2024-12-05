/*
██████╗ ██╗██████╗ ███████╗
██╔══██╗██║██╔══██╗██╔════╝
██║  ██║██║██████╔╝███████╗
██║  ██║██║██╔══██╗╚════██║
██████╔╝██║██████╔╝███████║
╚═════╝ ╚═╝╚═════╝ ╚══════╝

Created by:     Aharon (CoffeeTechTalk) B.
Date:           2024-12-04
Description:    Main file for the DIBS project.
Changelog:
  Ver: 0.0.0: initial project structure built and commited
*/

#include <ncurses.h>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {
    initscr(); // init and clear screen
    printw("Hello World !!!");
    refresh();
    getch();
    endwin(); // end ncurses and free memory
    return 0;
}