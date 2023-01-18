using namespace std;
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <map>

vector<string> split(string s, char delimeter)
{
    // split string into vector of strings by certain delimeter
    vector<string> res;     
    string substr;     
    istringstream stream(s);

    while (getline(stream, substr, delimeter)) {      
        res.push_back(substr);     
    }

    return res;  
}

bool isCardString(string s)
{
    int idx = strspn(s.c_str(), "0123456789AJQK");

    return idx == s.length();
}

bool isNumCardsValid(vector<int> input)
{
    // return true if input is 4 cards with valid value range

    int l = input.size();

    if (l != 4)
    {
        return false;
    }

    for (int i = 0; i < l; i++)
    {
        if(input[i] <= 0 || input[i] >= 14)
        {
            return false;
        }
    }

    return true;

}


vector<int> cardToNum(vector<string> cards)
{   
    map<string, int> cardMap;
    vector<int> res;

    for(int i = 2; i <= 10; i++)
    {
    
        cardMap[to_string(i)] = i;
    }

    cardMap["A"] = 1;
    cardMap["J"] = 11;
    cardMap["Q"] = 12;
    cardMap["K"] = 13;

    for(int i = 0; i < 4; i++)
    {
        res.push_back(cardMap[cards[i]]);
    }

    return res;

}

vector<string> numToCard(vector<int> nums)
{
    map<int, string> cardMap;
    vector<string> res;

    for(int i = 2; i <= 10; i++)
    {
    
        cardMap[i] = to_string(i);
    }

    cardMap[1] = "A";
    cardMap[11] = "J";
    cardMap[12] = "Q";
    cardMap[13] = "K";

    for(int i = 0; i < 4; i++)
    {
        res.push_back(cardMap[nums[i]]);
    }

    return res;

}


