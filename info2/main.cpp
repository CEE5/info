#include <iostream>
#include "Klammer.h"
#include <cmath>

using namespace std;

int main()
{
     int zahlenIndex=0;
    int operatorIndex=0;
string in,input;

    OUTERMOST: while (1) {
        cin.clear();
        input="";
        string zahl ="";


        cout << endl << "Eingabe: (mit Strg+D beenden)"<<endl;



        while(cin >> in){
            input += in;
            if(cin.eof()){
                in = "";
                break;
            }
        }
        cout << endl<< "Eingabe: " << input << endl;
        cout <<"Länge der Eingabe: " << input.size() <<endl;
        cout << "-------------------------------------"<<endl;
        cout <<endl;
        cout <<endl;


//Eingabe Korrektur
        for(int i=0; i<input.size();i++){
            if(input[i]=='p' &&input[i+1]=='i'){
                input.erase(input.begin()+i,(input.begin()+(i+2)));

                input.insert(i,"3.141592");

            }

        }



        Klammer objKlammer(input);

        double ergebnis = objKlammer.getWert();
        cout <<endl <<"Ergebnis: "<<endl <<input<<" = "<< ergebnis<<endl;




    }
    return 0;
}
