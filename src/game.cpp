using namespace std;
#include <string>
#include <map>
#include <vector>
#include <set>

// from src
#include "IO.cpp"


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

set<vector<string>> permute(vector<string> cards, int offset, int idx = 0)
{
    // return all permutation of cards

    set<vector<string>> res {};

    if (idx >= offset)
    {
        return res;
    }

    if (idx == offset - 1)
    {
        res.insert(cards);
        
        return res;
    }

    for (int i = idx; i < offset; i++)
    {
        swap(cards[idx], cards[i]);

        set<vector<string>> temp = permute(cards, offset, idx+1);

        merge(res.begin(), res.end(), temp.begin(), temp.end(), inserter(res, res.begin()));      

        swap(cards[idx], cards[i]);
    }
    
    return res;
}

vector<string> repeatingCombination(string symbols, int symbolNum, int length)
{
    // return repeating combination from distinct symbols
    
    vector<string> res {};

    if (length == 0)
    {
        return res;
    }

    if (length == 1)
    {
        for (int i = 0; i < symbolNum; i++)
        {
            res.push_back(symbols.substr(i, 1));
        }

        return res;
    }

    for (int i = 0; i < symbolNum; i++)
    {
        vector<string> temp = repeatingCombination(symbols, symbolNum, length-1);
        
        int l = temp.size();

        for (int j = 0; j < l; j++)
        {
            temp[j] = symbols.substr(i, 1) + temp[j];
        }

        res.insert(res.end(), temp.begin(), temp.end());
    }

    return res;
}

int evaluator(vector<int>nums, vector<string>operators,  int parenthesisMode)
{
    
}
int find(vector<string> cards)
{
    
}

int main()
{

    vector<string> v {"a", "b", "b"}; 
    set<vector<string>> temp = permute(v, v.size());
    vector<vector<string>> a {temp.begin(), temp.end()};
    for (int i = 0; i < a.size(); i++)
    {
        printVector(a[i]);
        nl();
    }

    printVector(repeatingCombination("aB3", 3, 3));

    

    return 0;
}