#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "system.h"
#include "sidebar.h"
#include "constants.h"

//include graph info class
#include "../../../!Includes/plot/graph_info.h"

#include <iostream>
using namespace std;

class animate{
public:
    //constructor of animate class
    animate();

    //window functions
    void run();            //update all events occuring while the window is open
    void processEvents();  //process specific events from keyboard or mouse
    void update();         //update data for next frame
    void render();         //clear, draw and display
    void Draw();           //draw all objects or shapes

    string mouse_pos_string(sf::RenderWindow& window);

private:
    sf::RenderWindow window;            //window were the objects are going to be animated
    sf::CircleShape mousePoint;         //The little red dot
    sf::RectangleShape input;           //The little red dot

    System system;                      //container for all the animated objects
    int command;                        //command to send to system

    sf::Font font;                      //font to draw on main screen
    sf::Text myTextLabel;               //text to draw on main screen
    std::string playertext;             //text to draw on main screen
    sf::Text _input;                    //text to draw on main screen

    bool mouseIn;                       //mouse is in the screen
    bool click_in;                      //bool for click in a specific area

    Sidebar sidebar;                    //rectangular message sidebar
    sf::RectangleShape rect;

    Graph graph;                        //graph class and graph info structure
    graph_info * _graph, gra;
    Vector <string> input_eqts;
};

string mouse_pos_string(sf::RenderWindow& window);
//check partially the input
bool check_input(char input);

#endif // GAME_H
