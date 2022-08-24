#ifndef Z_WORK_REPORT_H
#define Z_WORK_REPORT_H


/*
//=========================================
          REPORT
//=========================================

- VIDEO LINK:  https://www.youtube.com/watch?v=CRNwV-8EEpo&t=

MENU OPTIONS

Input box: to read in a equation to graph on screen
Delete: delete the saved equations
Save: save the current graphed function
Clear: clear the historial
Keyboard:
- Arrows: to move the graph up, down, left, and right
- P: to switch to polar graph
- T: to increment the theta for polar graph
- M and L: to increment and decrement points or density
- A: to rotate the graph
- R: to reset the graph to its original or first plotted


IMPLEMENTED:
 - MOTION

I implemented usin arrow buttoms to move the graph.
It was not an easy to asjust the graoh because to find the coordinates
to fit on screen base on domain, points, scale neede linear transformation.
I have a linear transformation class to convert into polar, get screen coordinates,
get the origin adjusting the dimension with the domain and matrices to
transforman. As well as using any proivided angle.

 - SAVE AND DELETE IN TEXT FILE

I have a save and load functino to save and delete equations for the saved list
and also for the historial. Both are managed within the sidebar which will call
the graph class to provide a vector of the stirng equations and draw them on screen.
In order to save, select or delete, sidebar will get the position to set the new
equation, save or delete with the graph class.


CLASSES
The animate class is the link between the main window or screen with the functions that
are created to modify the objects.
The sidebar class contains all the menu options and any other functions that
are needed to be done in the sidebar or menu panel.
The system class will connect the SMFL with the functions of game of life
which is in charge of calling the add random,clear, step, save and load functions.

 MORE CLASSES:
 - Graph class: in charge of calling the other classes to obtain the correct fomart
   of the equation and connect to the others and get the plots to plot on scree.
 - Plot class: it will run the equation through tokenize and shunting yard to get the
   postfix equation. Then it will go through rpn to be evaluated and call a liner
   transformation function to get polar coordinates in polar mode.
 - graph_info: it is a structure to get the info of the graph and passed through the
   rest of the classes
 - Shunting yard: it will run the infix queue and convert into postfix by using
   an enum list for each type of token.
 - Tokenize: it will convert the string into a queue of tokens by using the derived
   classs of token using inheritance.
 - Liner transformation: it will conver the coordinates into screen coordinates
   as well as to get polar or rotated points
 - Rpn: it will evalutate on variable of the equation in order to get the other variable
 - Additional classes are vector, queue, stack and constant classes to operated
   along with the more complext classes and code.

REFLECTION:
The project was long and at the beginning was hard to understand each class.
The way how all the functions and objects to be animated are connected by different classes.
Starting by the lower classes like token class whichc will be use to create each
specific type of token like integer, operator, variable or function to get
the infix and then convert into postfix function.
Every class are created with the purpose to maintain order and let the programmer
have a organize and readable code.
It was difficult to find a solution to get the coordinates to the screen and the
solution is by using the linear transformation as well for rotating the graph
it will use the rotation matrix which involves an angle.
Also, it was very important to consider when to use x and y as vectors because
the screen will not use negative values and also consider that the origin is actually
the left up corner.
The project was a challenge for every CS 3A student and test how much we understand
and learn during the semester.
Therefore, this project involved almost everything we learned in the course.
Finally, finishing the project will make us more conscious of bugs and the correct
way to keep functions or variables, use inheritance, queues and stacks become an
important part of this project.
Adding to all of that, this is another stage for my Computer Science major
and I learned more about the world of a programmer.
I am grateful to have taken this class with professor Sassan Barkeshli.

*/
#endif // Z_WORK_REPORT_H
