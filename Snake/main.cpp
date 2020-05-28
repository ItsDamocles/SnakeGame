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

    void KeyBoard();
    void MoveSnake();
    void AddTail();
    bool Ate();
    void MoveTail();
    void Collision();
};
//player input check

void Snake::KeyBoard()
{

    //kbhit - It will not wait for a key to be pressed
    if (kbhit())
    {
        char input = getch();

        if (input == 'w' || input == 'W')
        {
            direction = 1;
        }
        else if (input == 'a' || input == 'A')
        {
            direction = 2;
        }
        else if (input == 'd' || input == 'D')
        {
            direction = 3;
        }
        else if (input == 's' || input == 'S')
        {
            direction = 4;
        }
    }
}

void Snake::MoveSnake()
{
    //Saves last known location
    x_old = x;
    y_old = y;

    switch(direction)
    {
    case 1:
    {
        y--;
        break;
    }
    case 2:
    {
        x--;
        break;
    }
    case 3:
    {
        x++;
        break;
    }
    case 4:
    {
        y++;
        break;
    }
    }

    //Puts the snake's hean in field
    Map[y_old][x_old] = EMPTY;
    Map[y][x] = SNAKE_HEAD;
}


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
        /*
        1                up
        2       3     left        right
        4               down
        */
    }
    else if(Starter=='Q' || Starter=='q')
    {

        cout<<"QQQ"<<endl;
    }
    return 0;
}
