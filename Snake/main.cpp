#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int GameMenu(char Symbol)
{

    Hell:
        system ("CLS");
    cout<<"Welcome to Snake!"<<endl;
    cout<<"*****************"<<endl;
    cout<<"Press S to Start"<<endl;
    cout<<"Press Q to Quit"<<endl;
    cout<<"Press I for Info"<<endl;

    Symbol=getch();

    switch(Symbol)
    {
    case 'S':
        cout<<"S"<<endl;
        break;
    case 's':
        cout<<"s"<<endl;
        break;
    case 'I':
        cout<<"I"<<endl;
        break;
    case 'i':
        cout<<""<<endl;
        break;
    case 'Q':
        cout<<"Q"<<endl;
        break;
    case 'q':
        cout<<"Q"<<endl;
        break;
    default :
        cout<<"Wrong character"<<endl;

        goto Hell;
    }

    return Symbol;


}

int main()
{
    system("color A");
    char Starter=GameMenu(Starter);
    cout<<"elementas: "<<Starter<<endl;
    //system ("CLS");
    return 0;
}
