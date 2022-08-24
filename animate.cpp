#include "animate.h"
#include <fstream>

animate::animate():sidebar(WORK_PANEL, SIDE_BAR)
{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Graphing Calculator");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will

    //    system = System();

    window.setFramerateLimit(40);
    mouseIn = true;
    click_in = false;

    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Game CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("../arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    cout<<"animate instantiated successfully."<<endl;

    //set the size and position of each cell
    rect.setSize (sf::Vector2f(CELL_SIZE,CELL_SIZE));

    //    string eq = "sin(x)+(cos(x))^2-sin(200*x+PI)";
    //    string eq = "sin(x)";
    //        string eq = "x^(2^x)";

    //    graph.set_eqt (eq);
    _graph = graph.get_graph_info();

    _input = sf::Text(playertext, font);
    _input.setCharacterSize(50);
    _input.setFillColor(sf::Color::Black);
    _input.setPosition(sf::Vector2f(230, 150));

    input.setFillColor(sf::Color(191,255,128)); //(192,192,192)); //silver
    input.setOutlineColor(sf::Color::Black);
    input.setOutlineThickness(5);
    input.setPosition(sf::Vector2f (200, 100));
    input.setSize(sf::Vector2f(1000, 150));
}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.

    //call graph draw to draw the graph on screen
    graph.Draw(window);

    //    if (mouseIn){
    //        window.draw(mousePoint);
    //    }

    sidebar[SB_KEY_PRESSED] = to_string(_graph->_points);
    sidebar.draw(window);
    //window.draw(playertext);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    //window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .

    if (click_in == true){
        //for input equations
        window.draw (input);
        window.draw(_input);
    }
}

void animate::update(){
    //cause changes to the data for the next frame
    //pass the command and the graph info structure
    system.Step(command, _graph);
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);

    }
}

void animate::render(){
    window.clear(sf::Color::White);
    Draw();
    window.display();
}

void animate::processEvents()
{
    sf::Event event;
    float mouseX, mouseY;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;
            // key pressed
        case sf::Event::KeyPressed:
            if (click_in == false){
                switch(event.key.code){
                case sf::Keyboard::I:
                    //                   sidebar[SB_KEY_PRESSED] = "ZOOM IN";
                    command = 1;
                    break;
                case sf::Keyboard::O:
                    //                   sidebar[SB_KEY_PRESSED] = "ZOOM OUT";
                    command = 2;
                    break;
                case sf::Keyboard::Left:
                    //                   sidebar[SB_KEY_PRESSED] = "LEFT ARROW";
                    command = 3;
                    break;
                case sf::Keyboard::Right:
                    command = 4;
                    break;
                case sf::Keyboard::Up:
                    command = 5;
                    break;
                case sf::Keyboard::Down:
                    command = 6;
                    break;
                case sf::Keyboard::M:   //more points
                    sidebar[SB_KEY_PRESSED] = to_string(_graph->_points);
                    command = 7;
                    break;
                case sf::Keyboard::N:  //less points
                    sidebar[SB_KEY_PRESSED] = to_string(_graph->_points);
                    command = 8;
                    break;
                case sf::Keyboard::A:  //increment angle for rotation
                    command = 9;
                    break;
                case sf::Keyboard::T:
                    command = 12;      //increment theta for polar graph
                    break;
                case sf::Keyboard::R:
                    graph.reset_graph();
                    break;
                case sf::Keyboard::P:  //set polar
                    command = 11;
                    break;
                case sf::Keyboard::Escape:
                    sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                    window.close();
                    break;
                }
            }
            break;
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;
        case sf::Event::MouseLeft:
            mouseIn = false;
            break;
        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            break;
        case sf::Event::TextEntered:
            //read in the chars and add into a string then
            //print in the screen and pass to the graph info to graph
            if (click_in == true && static_cast <char>(event.text.unicode) != '\n'){
                if (check_input (static_cast <char>(event.text.unicode)) == true){
                    playertext += static_cast <char> (event.text.unicode);
                    _input.setString(playertext);
                }
                //output error is wrong input
                else if (check_input (static_cast <char>(event.text.unicode)) == false){
                    cout << " ERROR INPUT " <<endl;
                    _input.setString("ERROR");
                    playertext.clear();
                }
            } //if finished inputting pass the equation, clear strings
            else if (static_cast <char>(event.text.unicode) == '\n'){
                click_in = false;
                if (playertext.size() != 0 ){
                    graph.set_equation(playertext);
                    sidebar.get_graph_info( _graph, window, click_in);
                }
                playertext.clear();
                _input.setString(playertext);
            }

            break;
        case sf::Event::MouseButtonReleased:
            //in click on the input box set flag to be true
            if (event.mouseButton.x > 1770 && event.mouseButton.x  < 2396
                    && event.mouseButton.y > 120 &&event.mouseButton.y < 268){
                click_in = true;

            }//else pass the graph and window info to sidebar
            sidebar.get_graph_info(_graph,window, click_in);
            break;
        default:
            break;
        }
    }
}
void animate::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render(); //clear/draw/display
    }
    //clear text files and leave some equations
    graph.delete_sv_eq("historial.txt","n", true);
    graph.clear_save();
    graph.save ("sin(x)+(cos(x))^2-sin(200*x+PI)",1);
    graph.save ("sin(x^x)/(2^((x^x-PI/2)/PI))",1);
    graph.save ("sin(x^2)/gamma(x)",1);

    cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string animate::mouse_pos_string(sf::RenderWindow& window){

    double x = 0;
    if (sf::Mouse::getPosition(window).x < _graph->_window_dimension.x){
        x = (((_graph->_domain.y - _graph->_domain.x )/_graph->_window_dimension.x)+_graph->_scale);
    }
    return "(" +
            to_string((sf::Mouse::getPosition(window).x -_graph->_origin.x)*
                      x)+
            ", " +
            to_string(( _graph->_origin.y - sf::Mouse::getPosition(window).y)*
                      x) +
            ")";
//    return "(" +
//            to_string((sf::Mouse::getPosition(window).x ))+
//            ", " +
//            to_string(( sf::Mouse::getPosition(window).y)) +
//            ")";
}

bool check_input(char input){
    //check input char partially
    if ((input >= 40 && input <= 58 &&  input != 46 &&  input != 44 ) ||
            (input == 115 || input ==106 || input ==110 || input == 99 ||
             input == 111 || input ==115 || input == 116 || input == 101 ||
             input == 120 ||input == 97  || input ==105 )
            ||( input == 94 && input != 91 && input != 93 && input != 96)){
        return true;
    }
    return false;
}
