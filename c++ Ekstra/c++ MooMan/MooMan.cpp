#include <iostream>
#include <string.h>

using namespace std;

void ShowMooMan(string &str1,int strlen){

    string horiline = "----";

    for (int i = 0; i < strlen; i++)
    {
        horiline += '-';
    }
        
    cout << horiline << endl;
    cout << "| " << str1 << " |" << endl;
    cout << horiline << endl;
    cout << "  \\  ^__^" << endl;
    cout << "   \\ (oo)\\_______" << endl;
    cout << "     (__)\\       )\\/\\ " << endl;
    cout << "         ||----W||" << endl;
    cout << "         ||     ||" << endl;

}

int main()
{
    int verthight = 1;
    string Lines = "";
    string text = "";

    cout << "Input text: ";
    getline(cin,text);

    int strslen = size(text);

    ShowMooMan(text,strslen);

    return 0;
}
