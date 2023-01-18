using namespace std;
#include <string>
#include <map>
#include <vector>


vector<int> generateRandom()
{
    // generate 4 random numbers in a vector
    vector<int> res{0, 0, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        res[i] = rand() % 14;
    }

    return res;
}

int find(vector<string> cards)
{
    
}