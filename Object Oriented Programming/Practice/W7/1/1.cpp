#include <iostream>
#include "Engine.h"
#include "GamblerCollection.h"

using namespace std;

int main()
{
    Engine engine;
    GamblerCollection collection;
    collection.addGambler("Georgi", "1234", 19, 1000);
    char password[50];
    cin.getline(password, 50);
    
    while (true)
    {
        int index = collection.isValidPassword(password);
        if (index != -1)
        {
            Gambler gambler = collection.getGamblerByIndex(index);
            engine.play(gambler);
        }
        else
        {
            //enter again
        }
    }
}
