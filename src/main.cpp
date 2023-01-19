using namespace std;

#include <iostream>
#include <chrono>

// from src
#include "./headers/card.h"
#include "./headers/game.h"
#include "./headers/IO.h"

int main()
{
    int input;
    vector<int> nums;
    vector<string> res;

    config();

    welcome();
    welcomeMenu();

    input = inputChoice(1, 2);

    if (input == 1)
    {
        do {

            inputMenu();

            input = inputChoice(1, 4);

            if (input != 4)
            {
                if (input == 1)
                {
                    nums = generateRandom();
                    
                    nl();
                    cout << "Kartu acak yang diperoleh : ";
                    printVector(numToCard(nums));
                    nl();
                }

                if (input == 2)
                {
                    nums = getCards();
                }

                else if (input == 3)
                {
                    nums = getInputFile();
                }

                auto start = chrono::high_resolution_clock::now();

                res = find(nums);

                auto end = chrono::high_resolution_clock::now();

                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                
                float time = duration.count();

                printResult(res, time);

                outputMenu();

                input = inputChoice(1, 2);

                if (input == 1)
                {
                    writeFile(res, time);
                }
            }

        } while (input != 4);
    }

    return 0;

}