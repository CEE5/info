#ifndef OPERATOR_H
#define OPERATOR_H


class Operator
{


    public:
        Operator();
        Operator(char op, int z1,int z2);
        virtual ~Operator();

        char getOperator();
        int getZahl1();
        int getZahl2();


    protected:
    private:
        char op;
        int z1;
        int z2;
};

#endif // OPERATOR_H
