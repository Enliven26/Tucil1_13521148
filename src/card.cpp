using namespace std;
#include <sstream>
#include <cstring>
#include <iostream>
#include <regex>

#include "./headers/card.h"

map<string, int> cardMap {{"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10}, {"J", 11}, {"Q", 12}, {"K", 13}};
map<int, string> numMap {{1, "A"}, {2, "2"}, {3, "3"}, {4, "4"}, {5, "5"}, {6, "6"}, {7, "7"}, {8, "8"}, {9, "9"}, {10, "10"}, {11, "J"}, {12, "Q"}, {13, "K"}};

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
    // mengecek apakah karakater-karakter yang digunakan valid

    int idx = strspn(s.c_str(), "0123456789AJQK ");

    return idx == s.length();
}

bool isNumCardsValid(vector<int> input)
{
    // return true if input is 4 cards with valid value range

    int l = input.size();

    if (l != 4)
    {
        cout << "Input harus berupa 4 karakter kartu valid yang dipisahi spasi!\n";
        return false;
    }

    for (int i = 0; i < l; i++)
    {
        if(input[i] <= 0 || input[i] >= 14)
        {
            cout << "Input kartu hanya dapat berupa angka [2, 10] atau karakter A, J, Q, dan K (huruf kapital)!\n";
            return false;
        }
    }

    return true;

}

vector<int> cardToNum(vector<string> cards)
{   
    // mengubah vektor string kartu menjadi vektor nilai kartu tersebut

    vector<int> res;

    int l = cards.size();

    for(int i = 0; i < l; i++)
    {
        res.push_back(cardMap[cards[i]]);
    }

    return res;

}

vector<string> numToCard(vector<int> nums)
{
    // mengubah vektor nilai kartu menjadi vektor string kartu

    vector<string> res;

    int l = nums.size();

    for(int i = 0; i < l; i++)
    {
        res.push_back(numMap[nums[i]]);
    }

    return res;

}
