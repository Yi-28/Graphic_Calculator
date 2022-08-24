#ifndef CONSTANTS_H
#define CONSTANTS_H

const float SCREEN_WIDTH = 2400;
const float SCREEN_HEIGHT = 1645;
const float WORK_PANEL = SCREEN_WIDTH*4/5;
const float SIDE_BAR = SCREEN_WIDTH*1/5;

const int SB_MOUSE_POSITION = 0;
const int SB_MOUSE_CLICKED = SB_MOUSE_POSITION + 1;
const int SB_KEY_PRESSED = SB_MOUSE_CLICKED + 1;

//const int MAX_ROWS = 190;   //max rows of the grid
//const int MAX_COLS = 270;  //max columns of the grid
const int MAX_ROWS = 1340;   //max rows of the grid
const int MAX_COLS = 1900;  //max columns of the grid
const int CELL_SIZE = 5;  //cell size of each cell

#endif // CONSTANTS_H
