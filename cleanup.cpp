#include <iostream> // 
#include <string>   //standard library string class
#include <vector>  
#include <cstdlib>  //Random function
#include <ctime>    //time for random 
#include <unistd.h> // * usleep - suspend execution for microsecond intervals 
//? not sure unistd.h is exclusive to linux based machines? 

struct Card
{
    char storage;
    Card(char cardType) : storage(cardType) {}
};

void displayCard(char x)
{
    std::cout << "[" << x << "]"
              << " ";
}

int main()
{
    //Data declaration/initalization
    char deckOfCards[13] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K', 'A'}; // missing 10.
    int randomIndex[13] = {};
    int quantity, rotation;
    std::vector<Card> CardsOnTable;
    std::vector<Card>::iterator iteration;

    //Random Index Generator
    srand(time(0));
    for (int i = 0; i < sizeof(deckOfCards); i++)
    {
        randomIndex[i] = rand() % sizeof(deckOfCards);
    }

    //Prompt user to choose Number of Cards
    std::cout << "Number of Cards: ";
    std::cin >> quantity;

    //Cards Stored in a Vector with type Card
    for (int i = 0; i < quantity; i++)
    {
        CardsOnTable.push_back(Card(deckOfCards[randomIndex[i]]));
    }

    //Prompt User to choose Rotation amount
    std::cout << "Number of Rotations: ";
    std::cin >> rotation;

    //Using Multiple Arrangements
    for (int i = 0; i < rotation; i++)
    {
        //Printing "Cards" "on the table"
        for (iteration = CardsOnTable.begin(); iteration < CardsOnTable.end(); iteration++)
        {
            displayCard(iteration->storage);
        }

        //Switch cards based using random generation tool two at a time
        int star = rand() % quantity, tar = rand() % quantity;

        //If Duplicate
        while (star == tar)
        {
            star = rand() % quantity;
            tar = rand() % quantity;
        }

        char swapIndexOne = CardsOnTable[star].storage, swapIndexTwo = CardsOnTable[tar].storage; //Numbers will be stored in between 0 - number of cards

        //Display Swap Cards
        std::cout << "\n";
        for (int i = 0; i < CardsOnTable.size(); i++)
        {
            if (i == star || i == tar)
            {
                displayCard(CardsOnTable[i].storage);
            }
            else
            {
                displayCard('X');
            }
        }
        

        //Swap the Cards
        CardsOnTable[star].storage = swapIndexTwo;
        CardsOnTable[tar].storage = swapIndexOne;
        std::cout << "\n";
    }

            //Printing "Cards" "on the table"
        for (iteration = CardsOnTable.begin(); iteration < CardsOnTable.end(); iteration++)
        {
            displayCard(iteration->storage);
        }

    std::cout << "\n";
    return 0;
}
