#ifndef Z_NOTES_H
#define Z_NOTES_H


//OJOJ GRAPH CLASS TAKE THE POINTS AND DRAW IN THE SCREEN OJO
//ESTO ESTA EN LA MIERCOLES


//No podia encontrar el text file toca eliminar una parte del
//directory para q aparezca en el debug folder ojojojojojojo


//------------------------------------------
//   Definitions
//------------------------------------------

////constructor
//template <typename T>
//node<T> ::node()
//{
//    _item = 0;     //let _item =0
//    _next = NULL;  //and _next pointing at null

//}

//without switch to each case

//        if (tmp->get_type() == INTEGER|| tmp->get_type() == VARIABLE){
//            postfix.push(tmp);
//        }
//        //if token type = 3 verify operator
//        else if (tmp->get_type() == 3) {

//            if (tmp->prec() == ')'){
//                postfix.push(operators.pop());
//                tmp = operators.pop();

//                while (tmp->prec() != '('){
//                    postfix.push(tmp);
//                    tmp = operators.pop();
//                }
//            }
//            else if (operators.empty() == false && tmp->prec() != '(') {
//                if (tmp->prec() < operators.front()->prec()){
//                    operators.push(tmp);
//                }
//                else if (tmp->prec() >= operators.front()->prec()) {
//                    postfix.push(operators.pop());
//                    if (operators.size() != false){
//                        postfix.push(operators.pop());
//                    }
//                    operators.push(tmp);
//                }
//            }
//            else {
//                operators.push(tmp);
//            }
//        }
#endif // Z_NOTES_H
