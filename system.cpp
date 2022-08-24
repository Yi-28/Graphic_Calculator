#include "system.h"
#include "random.h"

#include <iostream>

#include <constants.h>
System::System()
{
//    Random r;
//    int xpos = 100;
//    int ypos = 100;
//    //the shape of the object, along with its velocity, acceleration,
//    //position, etc. should be part of the individual object.
//    shape = sf::CircleShape(10);
//    shape.setPosition(sf::Vector2f(xpos, ypos));
//    vel = sf::Vector2f(r.Next(-5,5), r.Next(-5,5)); //random velocity
//    int r_ = r.Next(0,255);
//    int g_ = r.Next(0,255);
//    int b_ = r.Next(0,255);
//    shape.setFillColor(sf::Color(r_, g_, b_));

}


//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command, graph_info *& graph){

    //swith command to the corresponding case
    switch (command) {
    case 1: //zoom in by changing the scale
        graph->_domain += sf::Vector2f (1, -1);
        graph->_range += sf::Vector2f (1, -1);
        break;
    case 2: //zoom out by changing the scale
        graph->_domain += sf::Vector2f (-1, 1);
        graph->_range += sf::Vector2f (-1, 1);
        break;
    case 3:  //move to the left by moving the origin to the left
        graph->_domain += sf::Vector2f (1, 1);
        break;
    case 4:   //move to the right by moving the origin to the right
        graph->_domain -= sf::Vector2f (1, 1);
        break;
    case 5:  //move to the up by moving the origin to the up
        graph->_range += sf::Vector2f (1,1);
        break;
    case 6:   //move to the down by moving the origin to the down
        graph->_range -= sf::Vector2f (1,1);

        break;
    case 7:  //increment points
        graph->_points += 200;
        break;
    case 8:  //decrment points
        if (graph->_points > 0){
            graph->_points -= 200;
        }
        break;
    case 9:  //increment angle for rotation
        if (graph->polar == true){
            graph->_angle += (3.14/4);
        }
        else {
            graph->_angle += 10;
        }
        break;
    case 11: //set polar flag to be true
        graph->polar = true;
        break;
    case 12: //increment theta for polar graph
        graph->_theta += (3.14/4);
        break;
    }
}

void System::Draw(sf::RenderWindow& window){
    //clear and draw shapes
    window.clear();
    window.draw(shape);
//    _graph.Draw (window);
}
