#include "Klammer.h"
#include <cmath>
#include <sstream>

string sWert;
double dWert;


Klammer::Klammer()
{
    //ctor
}
Klammer::Klammer(string w)
{
    sWert = w;
}

Klammer::~Klammer()
{
    //dtor
}

double Klammer::getWert()
{

    int anfang,ende, zaehler=0;

    string sKlammer, sKomplett;


    for(int i=0; i<sWert.size(); i++)
    {

        if(sWert[i]==40)
        {


            if(zaehler == 0)
            {
                anfang=i+1;
            }

            zaehler++;

        }

        else if(sWert[i]==41)
        {

            if(zaehler == 1)
            {
                ende=i-1;


                for(int h=anfang; h<=ende; h++)
                {
                    sKlammer += sWert[h];
                }
                cout<<"neue Klammer: "<<sKlammer<<endl;
                Klammer objKlammer(sKlammer);






//Sin,Cos,Tan Cotan prüfung
//neue Klammer an sWert[i] gefunden

                double tempErg, tempErg2;
                char* temp;
                stringstream ss;
                if(i>2)
                {
                    //inverse trigonometrische Funktionen
                    if(i>3&&sWert[anfang-5]=='a')
                    {
                        switch(sWert[anfang-4])
                        {
                        case 's':
                            tempErg =objKlammer.getWert();
                            tempErg2 = asin(tempErg);

                            tempErg2 = ((double)((int)(tempErg2*100000)))/100000;

                            if(tempErg2 >1||tempErg2<-1){
                                cout << "Fehler: auserhalb Definitionsbereich"<<endl;
                            }


                            cout <<"arcsin "<<tempErg <<" = " <<tempErg2<< endl;

                            sKomplett.erase(anfang-5,anfang);


                            ss << tempErg2;

                            cout <<ss.str()<<endl;
                            sKomplett.insert(anfang-5,ss.str());
                            break;


                        case 'c':
                            tempErg =objKlammer.getWert();
                            tempErg2 = acos(tempErg);

                            tempErg2 = ((double)((int)(tempErg2*100000)))/100000;

                            if(tempErg2 >1||tempErg2<-1){
                                cout << "Fehler: auserhalb Definitionsbereich"<<endl;
                            }

                            cout <<"arccos "<<tempErg <<" = " <<tempErg2<< endl;

                            sKomplett.erase(anfang-5,anfang);


                            ss << tempErg2;

                            cout <<ss.str()<<endl;
                            sKomplett.insert(anfang-5,ss.str());
                            break;
                        case 't':
                            tempErg =objKlammer.getWert();
                            tempErg2 = atan(tempErg);
                            tempErg2 = ((double)((int)(tempErg2*100000)))/100000;


                            cout <<"arctan "<<tempErg <<" = " <<tempErg2<< endl;

                            sKomplett.erase(anfang-5,anfang);


                            ss << tempErg2;

                            cout <<ss.str()<<endl;
                            sKomplett.insert(anfang-5,ss.str());
                            break;




                        default:

                            ss << objKlammer.getWert();
                            sKomplett += ss.str();

                        }

                    }
                    else
                    {

                        switch(sWert[anfang-4])
                        {
                        case 's':
                            tempErg =objKlammer.getWert();
                            tempErg2 = sin(tempErg);

                            tempErg2 = ((double)((int)(tempErg2*100000)))/100000;

                            cout <<"sinus "<<tempErg <<" = " <<tempErg2<< endl;

                            sKomplett.erase(anfang-4,anfang);


                            ss << tempErg2;

                            cout <<ss.str()<<endl;
                            sKomplett.insert(anfang-4,ss.str());
                            break;

                        case 'c':
                            tempErg =objKlammer.getWert();
                            tempErg2 = cos(tempErg);

                            tempErg2 = ((double)((int)(tempErg2*100000)))/100000;


                            cout <<"cosinus "<<tempErg <<" = " <<tempErg2<< endl;

                            sKomplett.erase(anfang-4,anfang);


                            ss << tempErg2;

                            cout <<ss.str()<<endl;
                            sKomplett.insert(anfang-4,ss.str());
                            break;

                        case 't':
                            tempErg =objKlammer.getWert();
                            tempErg2 = tan(tempErg);

                            tempErg2 = ((double)((int)(tempErg2*100000)))/100000;


                            cout <<"tangens "<<tempErg <<" = " <<tempErg2<< endl;

                            sKomplett.erase(anfang-4,anfang);


                            ss << tempErg2;

                            cout <<ss.str()<<endl;
                            sKomplett.insert(anfang-4,ss.str());
                            break;




                        default:

                            ss << objKlammer.getWert();
                            sKomplett += ss.str();

                        }
                    }
                }

            }






            zaehler--;

        }

        else
        {
            if(zaehler==0)
            {
                sKomplett += sWert[i];
            }

        }

    }

    cout <<"Klammer berechnen: ( "<<sKomplett<<" )"<<endl;
    Berechnung neueRechnung(sKomplett);

    double erg=neueRechnung.getErgebnis();
    cout <<"Klammer berechnet: "<<(erg)<<endl;
    return erg;

}


