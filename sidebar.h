#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "../../../!Includes/plot/graph_info.h"
#include "../../../!Includes/Graph/graph.h"
#include "../../../!Includes/List_functions/list_iterated_class.h"

class Sidebar
{
public:
    //constructor
    Sidebar();
    Sidebar(float left, float width);
    void draw(sf::RenderWindow& window);
    string& operator [](int index);

    //get graph into
    void get_graph_info (graph_info *& graph, sf::RenderWindow &window, bool click);
    //equation selected
    void equation_selected ();  //retrun the command number especific menu option
    //saved equations
    void saved_eqts (sf::RenderWindow& window, bool save);
    //historial of inputs
    void historial_eqts (sf::RenderWindow& window, graph_info *gra);

private:
    sf::RectangleShape rect;            //sidebar rectangles for
    sf::RectangleShape rect_Eqt;        //buttons
    sf::RectangleShape _delete;
    sf::CircleShape _save;              //circle for save and clear

    sf::RectangleShape input;           //sidebar rectangle

    vector<string> items;               //strings to place on the sidebar
    sf::Font font;                      //used to draw text
    sf::Text sb_text;                   //used to draw strings on the window object
    sf::Text scale;                     //used to draw strings on the window object

    sf::Text function;       //function
    sf::Text density;        //number of points
    sf::Text save;           //save text

    sf::Text eq;             //equations
    sf::Text eqt;
    sf::Text eqt1;
    sf::Text eqt2;
    sf::Text eqt3;

    float _left;
    float _width;
    Graph graph;

    graph_info * _graph;   //graph struture

};

#endif // SIDEBAR_H
