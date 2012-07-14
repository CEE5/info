#include "Berechnung.h"
#include "Operator.h"

string rechnung;
Berechnung::Berechnung()
{
    //ctor
}
Berechnung::Berechnung(string input)
{
    rechnung = input;
}

Berechnung::~Berechnung()
{
    //dtor
}
double Berechnung::getErgebnis()
{

    vector <double> zahlen;
    vector <Operator> operatoren;
    string zahl;
    int zahlenIndex=0;
    int operatorIndex=0;
    int negativFlag =1;

    for(int i=0; i<rechnung.size(); i++)
    {

        //Zeichen ist ein Operator
        if((41<rechnung[i] && rechnung[i]<48)&& rechnung[i]!='.')
        {
//               cout << "Operator: " << rechnung[i] <<endl;


            //Operator vor Minus oder Minus am Anfang
            if((i>0 &&(rechnung[i]=='-')&& 41<rechnung[i-1] && rechnung[i-1]<48) ||(i==0 && rechnung[i]=='-'))
            {

                negativFlag = -1;
            }

            else
            {

                zahlen.push_back(atof(zahl.data())*negativFlag);
                zahl="";
                zahlenIndex++;
                negativFlag=1;

                if(negativFlag ==1)
                {
                    Operator temp(rechnung[i], zahlenIndex-1, zahlenIndex);
                    operatoren.push_back(temp);

                    operatorIndex++;
                }
            }




        }
        //Zeichen ist eine Ziffer
        else if(47<rechnung[i] && rechnung[i]<58||rechnung[i]=='.')
        {
            //             cout << "Zahl: " << rechnung[i] << endl;

            zahl += rechnung[i];
        }



        //char* temp;
        //sprintf(temp, "%f\n", objKlammer.getWert());
    }

    //letzte Zahl hinzufügen

    zahlen.push_back(atof(zahl.data())*negativFlag);
    zahlenIndex++;
    negativFlag=1;





//Rechenoperationen
    double ergebnis =0;
    double tempErgebnis=0;

    for(int h=0; h<operatoren.size(); h++)
    {

        if(operatoren[h].getOperator()=='*')
        {


            tempErgebnis = zahlen[h] * zahlen[h+1];

            cout << zahlen[h] <<" * " << zahlen[h+1] << " = " << tempErgebnis << endl;

            zahlen[h] = tempErgebnis;
            zahlen.erase(zahlen.begin()+h+1);
            operatoren.erase(operatoren.begin()+h);

        }

    }

    for(int h=0; h<operatoren.size(); h++)
    {

        if(operatoren[h].getOperator()=='/')
        {


            if(zahlen[h+1]==0)
            {
                cout <<"Fehler /0"<<endl;
            }

            tempErgebnis = zahlen[h] / zahlen[h+1];

            cout << zahlen[h] <<" / " << zahlen[h+1] << " = " << tempErgebnis << endl;

            zahlen[h] = tempErgebnis;
            zahlen.erase(zahlen.begin()+h+1);
            operatoren.erase(operatoren.begin()+h);

        }

    }

    for(int h=0; h<operatoren.size(); h++)
    {

        if(operatoren[h].getOperator()=='+')
        {


            tempErgebnis = zahlen[h] + zahlen[h+1];

            cout << zahlen[h] <<" + " << zahlen[h+1] << " = " << tempErgebnis << endl;

            zahlen[h] = tempErgebnis;
            zahlen.erase(zahlen.begin()+h+1);
            operatoren.erase(operatoren.begin()+h);

        }

    }
    for(int h=0; h<operatoren.size(); h++)
    {

        if(operatoren[h].getOperator()=='-')
        {


            tempErgebnis = zahlen[h] - zahlen[h+1];

            cout << zahlen[h] <<" - " << zahlen[h+1] << " = " << tempErgebnis << endl;

            zahlen[h] = tempErgebnis;
            zahlen.erase(zahlen.begin()+h+1);
            operatoren.erase(operatoren.begin()+h);

        }

    }













    return zahlen[0];

}
