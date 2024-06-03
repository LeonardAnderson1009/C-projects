#include <iostream>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <string>

using namespace std;

string man = " | ( ) | /|J |  ^ / L";
string actword ,word;

void StringStart(string s){

    ifstream FileIn("wordlist.txt");

    if (FileIn.is_open())
    {
        srand(time(0));
        int randomnom = (rand() % 69903) + 1;
        string b;
        int count = 0;
        while (getline(FileIn,b))
        {
            ++count ;
            if (count == randomnom)
            {
                actword = b;
                for (unsigned short i = 0; i < actword.size(); i++)
                    {
                        word += "_";
                    }
                exit;
            }   
        }
    }
    else
    {
        cout << "Trouble reading file" << endl;
    }
}

void display(int num){
    for (unsigned short i = 0; i < num; i++)
    {
        cout << man[(i)*3] << man[(i)*3+1] << man[(i)*3+2] << endl;
    }
    cout << "---------" << endl;
}

int main()
{
    string nameoffile;
    cout << "Give the name of your wordlist(include '.txt'): " << endl;
    cin >> nameoffile;
    StringStart(nameoffile);

    bool dead = false,gameover=false;
    int numberofunderscores = actword.size();
    int nomverkeerd = 0;
    char letter ;
    while ( (!dead) || (!gameover) )
    {
        bool letterfound = false;
        system("cls");
        cout << numberofunderscores;
        display(nomverkeerd);
        cout << word << endl;
        cout << "Choose letter: " ;
        cin >> letter;
        for (unsigned short i = 0; i < actword.size(); i++)
        {
            if (actword[i] == letter)
            {
                word[i] = letter;
                letterfound = true;
                --numberofunderscores;
            }
        }
        if (!letterfound)
        {
            ++nomverkeerd;
        }
        if (nomverkeerd >= 6)
        {
            dead = true;
        }
        if (numberofunderscores <= 0)
        {
            gameover = true;
        }
        
    }
   if (dead)
   {
    cout << "You lost";
   }
   else
   {
    cout << "You won";
   }
    

}