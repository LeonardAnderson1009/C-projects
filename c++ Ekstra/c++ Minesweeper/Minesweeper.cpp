#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int arr[10][10];

void predarray()
{   
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int randomnom = (rand() % 5);

            if (randomnom == 0)
            {
                arr[i][j] = -1;
            }
        }
    }
}

int checkNum(int x,int y)
{
    int nomm = 0;
    if (arr[x][y] != -1)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (  (( (x+1-i) >= 0 ) && ( (y+1-j) >= 0 )) && (( (x+1-i) < 10 ) && ( (y+1-j) < 10 )))
                {
                    if (arr[x+1-i][y+1-j] == -1)
                    {
                        ++nomm;
                    }
                }
            }
        }
        return nomm;
    }
    else
    {
        return -1;
    }
}

void MaakNoms()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = checkNum(i,j);

            if (arr[i][j] == -1)
            {
                cout << arr[i][j];
            }
            else
            {
                cout << ' ' << arr[i][j];
            }
        }
         cout << endl;
    }
}

int main()
{
    predarray();
    MaakNoms();
}