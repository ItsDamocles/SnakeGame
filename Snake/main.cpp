#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h>
#include <iomanip>

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
const int map_x = 40;
const int map_y = 10;

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
    int x = 19; //snake's default spawn location
    int y = 4; //by x and y coordinates
    int x_old, y_old; //old coordinates
    int direction = 3; //default snake moving direction on start
    int tailsize = 0; //snake tail size

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

//
//Function to increase tail size
//Adds default tail size at the start
//

void Snake::AddTail()
{
    if (tailsize == 0)
    {
        for (int i=0; i<2; i++)
        {
            tails.push_back(Tail());
            tails[i].x = 19 - i; //adds tail after default spawn position
            tails[i].y = 4;

            Map[tails[i].y][tails[i].x] = SNAKE_TAIL;
            tailsize++;
        }
    }

    if (Ate())
    {
        tails.push_back(Tail());

        //New tail coordinate creation
        switch(direction)
        {
        case 1:
        {
            tails[tailsize].x = tails[tailsize - 1].x;
            tails[tailsize].y = tails[tailsize - 1].y - 1;
            break;
        }
        case 2:
        {
            tails[tailsize].x = tails[tailsize - 1].x + 1;
            tails[tailsize].y = tails[tailsize - 1].y;
            break;
        }
        case 3:
        {
            tails[tailsize].x = tails[tailsize - 1].x - 1;
            tails[tailsize].y = tails[tailsize - 1].y;
            break;
        }
        case 4:
        {
            tails[tailsize].x = tails[tailsize - 1].x;
            tails[tailsize].y = tails[tailsize - 1].y + 1;
            break;
        }
        }
        tailsize++;
    }
}

//check if snake ate
bool Snake::Ate()
{
    //check if snake's head is in the same coordinate as fruit
    if (direction == 1 && Map[y - 1][x] == FRUIT)
    {
        return true;
    }
    else if (direction == 2 && Map[y][x - 1] == FRUIT)
    {
        return true;
    }
    else if (direction == 3 && Map[y][x + 1] == FRUIT)
    {
        return true;
    }
    else if (direction == 4 && Map[y + 1][x] == FRUIT)
    {
        return true;
    }

    return false;
}

void Snake::MoveTail()
{
    //Back tail removal when moving
    Map[tails[tailsize - 1].y][tails[tailsize - 1].x] = EMPTY;

    //replace old tail with new tail to create a movement effect
    for (int i=tailsize - 1; i!=0; i--)
    {
        tails[i].x = tails[i-1].x;
        tails[i].y = tails[i-1].y;
    }
    tails[0].x = x_old;
    tails[0].y = y_old;
    Map[y_old][x_old] = SNAKE_TAIL;
}


void Snake::Collision()
{
    //function to check if snake hit the wall
    if (x == 0 || x == 39)
    {
        cout << "GAME OVER";
        system("pause");
        exit(0);
    }

    if (direction == 1 && Map[y - 1][x] == WALL || direction == 4 && Map[y + 1][x] == WALL)
    {
        cout << "GAME OVER";
        system("pause");
        exit(0);
    }
    if (direction == 1 && Map[y - 1][x] == SNAKE_TAIL)
    {
        cout << "GAME OVER";
        system("pause");
        exit(0);
    }
    else if (direction == 2 && Map[y][x - 1] == SNAKE_TAIL)
    {
        cout << "GAME OVER";
        system("pause");
        exit(0);
    }
    else if (direction == 3 && Map[y][x + 1] == SNAKE_TAIL)
    {
        cout << "GAME OVER";
        system("pause");
        exit(0);
    }
    else if (direction == 4 && Map[y + 1][x] == SNAKE_TAIL)
    {
        cout << "GAME OVER";
        system("pause");
        exit(0);
    }
}

void Snake::update()
{
    KeyBoard();
    AddTail();
    Collision();
    MoveSnake();
    MoveTail();
}

//new class inherits GameObject class
class Fruit:public GameObject
{
public:

   void update();

private:
    int x;
    int y;

    //Helper methods
    void spawnFruit();
    bool checkFruit();
};

void Fruit::spawnFruit() //spawns a fruit randomly
{
    int x,y;
    x = 1 + rand() % 38;
    y = 1 + rand() % 8;

    Map[y][x] = FRUIT;
}

bool Fruit::checkFruit()
{
    for (int i=1;i<map_y - 1;i++)
    {
        for (int j=1;j<map_x - 1;j++)
        {
            if (Map[i][j] == FRUIT)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    system("color A");
    char Starter=GameMenu(Starter);
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
