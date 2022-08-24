#ifndef SYSTEM_H
#define SYSTEM_H

#include "../../../!Includes/Graph/graph.h"

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
class System
{
public:
    //constructor of system class
    System();
    //step and pass int the command and graph structure
    void Step(int command, graph_info *&graph);

    //draw the shapes or objects
    void Draw(sf::RenderWindow& widnow);


private:
//    vector<Particle> system;
    sf::CircleShape shape;
    sf::Vector2f vel;

    Graph _graph;     //graph classa and graph info
    graph_info *gra;
};


#endif // SYSTEM_H
