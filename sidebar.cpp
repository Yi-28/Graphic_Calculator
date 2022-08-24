#include "sidebar.h"
#include "constants.h"
#include <cstring>
Sidebar::Sidebar(){

}

Sidebar::Sidebar(float left, float width):_left(left), _width(width){
    cout<<"Sidebar CTOR: TOP"<<endl;
    items.reserve(50);

    //set up the sidebar rectangle:
    rect.setFillColor(sf::Color(0,204,204)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left - 150, 0));
    rect.setSize(sf::Vector2f(width + 150, SCREEN_HEIGHT));
    cout<<"Sidebar CTOR: about to load font."<<endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("../Roboto-Thin.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout<<"Sidebar CTOR: loaded font."<<endl;

    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout<<"Sidebar CTOR: Text object initialized."<<endl;
    sb_text.setFont(font);
    sb_text.setCharacterSize(30);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setColor(sf::Color::Black);

    //this is how you would position text on screen:
    //sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));

    items.push_back("sidebar sample text");
    //Fill the items vector with empty strings so that we can use [] to read them:
    for (int i=0 ; i<30; i++){
        items.push_back("");
    }
    cout<<"Sidebar: CTOR: Exit."<<endl;

    //input text
    input.setFillColor(sf::Color((255,207,228))); //(192,192,192)); //silver
    input.setOutlineColor(sf::Color::Black);
    input.setOutlineThickness(5);
    input.setPosition(sf::Vector2f (200, 100));
    input.setSize(sf::Vector2f(1000, 150));

    //density or num of points
    density = sf::Text("Density = ", font);
    density.setCharacterSize(30);
    density.setStyle(sf::Text::Bold);
    density.setFillColor(sf::Color::Black);
    density.setPosition(sf::Vector2f(1810, 70));

    //function
    function = sf::Text("f(x) = ", font);
    function.setCharacterSize(30);
    function.setOutlineThickness(2);
    function.setOutlineColor(sf::Color(136,204,0));
    function.setStyle(sf::Text::Bold);
    function.setFillColor(sf::Color::Black);
    function.setPosition(sf::Vector2f(1792, 150));

    //rectangle of the function
    rect_Eqt.setFillColor(sf::Color::White); //silver
    rect_Eqt.setPosition(sf::Vector2f(left - 150, 120));
    rect_Eqt.setSize(sf::Vector2f(width + 150, 150));
    rect_Eqt.setOutlineThickness(2);
    rect_Eqt.setOutlineColor(sf::Color::Black);

    //delete box
    _delete.setFillColor(sf::Color::Black); //silver
    _delete.setPosition(sf::Vector2f(2114, 280));
    _delete.setSize(sf::Vector2f(224, 68));
    _delete.setOutlineThickness(2);
    _delete.setOutlineColor(sf::Color(192,192,192));

    //save buttom
    save = sf::Text("SAVE ", font);
    save.setCharacterSize(30);
    save.setPosition(sf::Vector2f(1844, 700));

    //equations
    eq = sf::Text("Equations: ", font);
    eq.setCharacterSize(30);
    eq.setStyle(sf::Text::Bold);
    eq.setFillColor(sf::Color::Black);
    eq.setPosition(sf::Vector2f(1844, 296));

    string s = graph.get_eqt();
    eqt2 = sf::Text(s, font);
    eqt2.setCharacterSize(30);
    eqt2.setStyle(sf::Text::Bold);
    eqt2.setFillColor(sf::Color::Black);
    eqt2.setPosition(sf::Vector2f(1884, 150));

    eqt.setCharacterSize(30);
    eqt.setStyle(sf::Text::Bold);
    eqt.setFillColor(sf::Color::Black);

    //HISTORIAL
    eqt1 = sf::Text("HISTORIAL", font);
    eqt1.setPosition(sf::Vector2f(2005, 700));
    eqt1.setOutlineThickness(3);
    eqt1.setStyle(sf::Text::Bold);
    eqt1.setOutlineColor(sf::Color::Black);

}

void Sidebar::get_graph_info (graph_info *& gra, sf::RenderWindow& window, bool click){
    //get the information to delete or save the corresponding equations

    int x = sf::Mouse::getPosition(window).x;
    int y = sf::Mouse::getPosition(window).y;

    Vector <string> eqts;
    graph.load_graph ("aaa.txt", eqts);
    string eqt = gra->_equation;
    int size = eqts.size() ;

    int index = size - 1- (y -365)/59;
    cout << endl << index << endl;
    if (size != 0 && (x >= 2114) && (y >= 280) && (x <= 2394)&& (y < 350)){
        graph.delete_sv_eq ("aaa.txt", eqt,false);
    }
    //call load graph
    graph.load_graph ("aaa.txt", eqts);
    if (size != 0 && (x >= 1844) && (y >= 365) && (x <= 2394)&&(y < 696)){
        if (index > -1){
            cout <<endl<<  " eq = " << eqts [index] <<endl;
            eqt = eqts [index];
        }
        gra->_equation = eqt;
        eqt2 = sf::Text(gra->_equation, font);
    }
    else if ((x >= 1844) && (y >= 788) && (x <= 2128)&&(y <= 864)) {
        graph.save(gra->_equation,1);
    }
    else if((x >= 2088) && (y >= 788) && (x <= 2394)&&(y <= 864)){
        graph.delete_sv_eq ("historial.txt", "," ,true);
    }
    graph.load_graph ("historial.txt", eqts);
    size = eqts.size() ;
    index = size - 1- (y -916)/59;
    if (size != 0 && (x >= 1900) && (y >= 916) && (x <= 2394)&&(y < 1270)){
        if (index > -1){
            cout <<endl<<  " eq = " << eqts [index] <<endl;
            eqt = eqts [index];
        }
        gra->_equation = eqt;
        eqt2 = sf::Text(gra->_equation, font);
    }
    //set new equation string to print to the screen
    if (click == false){
        graph.save (gra->_equation, 2);
        historial_eqts(window, gra);
    }
    eqt2 = sf::Text(gra->_equation, font);
    eqt2.setFillColor(sf::Color::Black);
}

void Sidebar::draw(sf::RenderWindow& window){
    const double VERTICAL_LINE_SPACING = 5.0;
    const double LEFT_MARGIN = 10.0;

    window.draw(rect);
    float height = 10;

    //draw the coordinates
    for (vector<string>::iterator it = items.begin();
                                it!= items.end(); it++){
        bool blank = false;
        if (strlen(it->c_str()) == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
            sb_text.setString("BLANK");
        }
        else{
            sb_text.setString(it->c_str());
        }
        sb_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN +100, height));
        height += sb_text.getLocalBounds().height+VERTICAL_LINE_SPACING;
        if (!blank)
            window.draw(sb_text);
    }
    //draw the corresponding equations and rextangles
    window.draw(rect_Eqt);
    window.draw(function);

    //density
    density = sf::Text("Density = ", font);
    density.setStyle(sf::Text::Bold);
    density.setFillColor(sf::Color::Black);
    density.setPosition(sf::Vector2f(1810, 70));
    window.draw(density);

    //coodiantes
    density = sf::Text("Coordinates = ", font);
    density.setStyle(sf::Text::Bold);
    density.setFillColor(sf::Color::Black);
    density.setPosition(sf::Vector2f(1810, 15));
    window.draw(density);

    //save buttom and text
    _save.setFillColor(sf::Color(136,204,0));
    _save.setPosition(sf::Vector2f(1910, 770));
    _save.setRadius(55);
    _save.setOutlineThickness(2);
    _save.setOutlineColor(sf::Color::Black);
    window.draw(_save);

    _save.setFillColor(sf::Color::White);
    _save.setPosition(sf::Vector2f(2115, 770));
    _save.setRadius(55);
    _save.setOutlineThickness(2);
    _save.setOutlineColor(sf::Color::Black);
    window.draw(_save);

    //save
    save = sf::Text("SAVE ", font);
    save.setPosition(sf::Vector2f(1930, 800));
    save.setFillColor(sf::Color::Black);
    save.setStyle(sf::Text::Bold);

    window.draw(save);

    save = sf::Text("CLEAR ", font);
    save.setPosition(sf::Vector2f(2128, 800));
    save.setFillColor(sf::Color::Black);
    save.setStyle(sf::Text::Bold);
    window.draw(save);

    //print the equations for saved and historial parts
    window.draw(eqt1);

    eq = sf::Text("Equations: ", font);
    eq.setCharacterSize(30);
    eq.setStyle(sf::Text::Bold);
    eq.setFillColor(sf::Color::Black);
    eq.setPosition(sf::Vector2f(1844, 296));
    window.draw(eq);

    window.draw(_delete);

    eq = sf::Text("DELETE", font);
    eq.setCharacterSize(30);
    eq.setStyle(sf::Text::Bold);
    eq.setOutlineThickness(1);
    eq.setOutlineColor(sf::Color::White);
    eq.setFillColor(sf::Color::White);
    eq.setPosition(sf::Vector2f(2164, 296));
    window.draw(eq);

    //save equations and historial to load the equations and print
    //out on the sidebar
    saved_eqts (window, false);
    historial_eqts (window, graph.get_graph_info());

    eqt2.setFillColor(sf::Color::Black);
    eqt2.setOutlineThickness(2);
    eqt2.setOutlineColor(sf::Color(136,204,0));
    eqt2.setPosition(sf::Vector2f(1884, 150));
    window.draw(eqt2);
}

void Sidebar::saved_eqts (sf::RenderWindow& window, bool save){
    //find out the equations from the text file
    if (save == false){
        int y = 365;
        Vector <string> eqts;
        graph.load_graph ("aaa.txt", eqts);

        //load each one and print on the screen
        for (int i = eqts.size() - 1; i > -1; i--){
            eqt = sf::Text( eqts [i], font);
            eqt.setPosition(sf::Vector2f(1844, y));
            eqt.setStyle(sf::Text::Bold);
            eqt.setFillColor(sf::Color::Black);
            window.draw(eqt);
            y += 55;
        }
    }
    else if (save == true) {
        graph.save (_graph->_equation,1);
    }
}

void Sidebar::historial_eqts (sf::RenderWindow& window, graph_info * gra){

    //find out the equations from the text file
    int y = 916;
    Vector <string> eqts;
    graph.load_graph ("historial.txt", eqts);

    //load each one and print on the screen as
    //a column of equations
    for (int i = eqts.size() - 1; i > -1; i--){
        eqt = sf::Text( eqts [i], font);
        eqt.setFillColor(sf::Color::Black);
        eqt.setStyle(sf::Text::Bold);
        eqt.setPosition(sf::Vector2f(1900, y));
        window.draw(eqt);
        y += 55;
    }
}

string& Sidebar::operator [](int index){
    return items[index];
}
