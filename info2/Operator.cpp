#include "Operator.h"



Operator::Operator(char oper, int zahl1, int zahl2)
{
    op = oper;
    z1= zahl1;
    z2 = zahl2;


}

Operator::~Operator(){


}
char Operator::getOperator(){

    return op;
}

int Operator::getZahl1(){
    return z1;
}
int Operator::getZahl2(){
    return z2;
}
