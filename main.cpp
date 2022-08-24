/*  Author: Yi Tong Zhuang Zhuo
 *  Project: Graphing Calculator
 *  Purpose: Design a program using sfml to graph equations like a graphing calculator
 *  Note: Make use of inheritance on token classes to create the infix and postfix
 *        queues.
 *        Create linear transformation class to convert coord into screen coord as well
 *        as to rotate the graph or graph in polar coordinates
 *        Use a graph class to make changes the graph on the graph info structure
 *        There are also plot, shunting yard classes to separate the code into different
 *        fields working on specific tasks.
 */

//include the animate and test shunting yard class
#include "animate.h"
#include "../../../!Includes/Shunting_Yard/test_shunting_yard.h"

using namespace std;

int main()
{
    //run the program
    animate game;
    game.run();

//    test_shunting_y();

    cout<<endl<<endl<<"------ MAIN EXITING --------------------------"<<endl;
    return 0;
}

