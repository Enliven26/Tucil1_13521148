using namespace std;
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <map>
#include <iostream>
#include <regex>

vector<string> split(string s, char delimeter = ' ')
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

    int l = nums.size();

    for(int i = 0; i < l; i++)
    {
        res.push_back(cardMap[nums[i]]);
    }

    return res;

}

// void printVector(vector<string> outputs)
// {
//     int l = outputs.size();
 
//     for(int i = 0; i < l-1; i++)
//     {
//         cout << outputs[i] + " ";
//     }

//     cout << outputs[l-1];
// }

// void printVector(vector<int> outputs)
// {
//     int l = outputs.size();

//     for(int i = 0; i < l-1; i++)
//     {
//         cout << to_string(outputs[i]) + " ";
//     }

//     cout << outputs[l-1];
// }

// void nl()
// {
//     cout << "\n";
// }

// string removeExtraSpace(string s)
// {
//     return regex_replace(s, regex("^ +| +$|( ) +"), "$1");
// }

// int main()
// {
//     string s = " A Q J  9";
//     vector<string> splittedStr = split(removeExtraSpace(s), ' ');
//     printVector(splittedStr);
//     nl();

//     bool isCardStrValid = isCardString(s);

//     if (isCardStrValid)
//     {
//         vector<int> nums = cardToNum(splittedStr);
//         printVector(nums);
//         nl();

//         if (isNumCardsValid(nums))
//         {
//             vector<string> cards = numToCard(nums);
//             printVector(cards);
//             nl();
//         }
//     }
//     return 0;
// }

