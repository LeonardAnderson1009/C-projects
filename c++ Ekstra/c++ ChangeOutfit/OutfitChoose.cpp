#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void Changeoutfit(int outfitNum){

    fstream MyOutfit;
    MyOutfit.open("Outfits.txt");


    if (!MyOutfit.is_open())
    {
        cout << "Missing file 'Outfits.txt'" << endl;
    }
    
    int counter = 0;
    bool flag = false;
    string body = "";
    string tempBody = "";

    while (!MyOutfit.eof())
    {
        ++counter;
        getline(MyOutfit,tempBody);

        if (( (outfitNum-1)*12  <= counter && counter <= outfitNum*12 ))
        {
            flag = true;
            body.append(tempBody);
            body.append("\n");
        }
        
    }

    if (flag)
    {
        cout<< body;
    }
    else
    {
        cout << "Outfit Not Found";
    }
    
    MyOutfit.close();
}

int main(){
    try
    {
        Changeoutfit(2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}