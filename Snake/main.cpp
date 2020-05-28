#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>

using namespace std;

int GameMenu(char Symbol)
{
Hell:
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
        system ("CLS");
        goto Hell;
    }

    return Symbol;
}

enum objects {EMPTY, WALL, SNAKE_HEAD, SNAKE_TAIL, FRUIT};
objects** Map;

//map size
const int m_x = 40;
const int m_y = 10;

//inheritation
class GameObject
{
public:

    virtual void update() = 0;
};

class Snake : public GameObject
{
public:

    void update();

private:
    int _x = 19; //snake spawn location
    int _y = 4; //by x and y coordinates
    int _x_old, _y_old; //old coordinates
    int _direction = 3; //default snake location on start
    int _tsize = 0; //snake tail size

    struct Tail
    {
        int x;
        int y;
    };
    //Array of tails
    vector<Tail>tails;

    void _KeyBoard();
    void _MoveSnake();
    void _AddTail();
    bool _Ate();
    void _MoveTail();
    void _Collision();
};
//player input check

int main()
{
    system("color A");
    char Starter=GameMenu(Starter);
    //cout<<"elementas: "<<Starter<<endl;
    system ("CLS");
    if(Starter=='S' || Starter=='s')
    {

    }
    else if(Starter=='I' || Starter=='i')
    {
        cout<<"Snake game developed by Titas"<<endl;
    }
    else if(Starter=='Q' || Starter=='q')
    {
        cout<<"QQQ"<<endl;
    }
    return 0;
}
