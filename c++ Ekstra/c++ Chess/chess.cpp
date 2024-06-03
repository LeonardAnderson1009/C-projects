// #include <iostream>
// using namespace std;

// /* result type   function name       input variables*/
//     int             sum(        int eerste,     int tweede)
//     {
//         return eerste + tweede;
//     }


// int main()
// {
//     int jan = 10;
//     int san {10};
//     //Same thing written differently

//     cout << sum(jan,san);
//     return 0;
// }

#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

char arr[8][8];

void clearScreen() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

void pregame()
{
    for (size_t i = 0; i < 2; i++)
    {
        arr[i*7][0] = 'R';
        arr[i*7][1] = 'N';
        arr[i*7][2] = 'B';
        arr[i*7][3] = 'Q';
        arr[i*7][4] = 'K';
        arr[i*7][5] = 'B';
        arr[i*7][6] = 'N';
        arr[i*7][7] = 'R';

        for (size_t j = 0; j < 8; j++)
        {
            arr[i*5+1][j] = 'P';
        }
        
    }
    

    for (size_t i = 2; i < 6; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            arr[i][j] = (i + j) % 2 == 0 ? 'O' : '#';
        }
    } 
    
}

void draw()
{
    for (size_t i = 7; i >= 0; i--)
    {
        for (size_t j = 0; j < 8; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;   
    }
}

void change(int x,int y,int xna,int yna)
{
        char temp = arr[x][y];
        arr[x][y] = (x + y) % 2 == 0 ? 'O' : '#';
        arr[xna][yna] = temp;
}

int main()
{   

    pregame();
    draw();

    string s,t;
    bool b = true;
    int xna,yna,x,y;

    while (b)
    {
        cout << "Choose a piece. " << endl;
        cin >> s;
        cout << "Move to ... " << endl;
        cin >> t;

        if (s.length() != 2)
        {
            cout << "Not a valid input" << endl;
        }
        else if ((s == "xx") || (t == "xx"))
        {
            b = false;
        }
        else
        {
            clearScreen();
            x = s[0] - 97;
            y = s[1] - 49;
            xna = t[0] - 97;
            yna = t[1] - 49;

            cout << x << y << endl;
            cout << xna << yna << endl;

            change(y,x,yna,xna);
            draw();
        }
        
    }

}