using namespace std;

#include <regex>
#include <float.h>

// from src
#include "./headers/game.h"
#include "./headers/card.h"

vector<string> opCombination;
bool isConfigured = false;

float float_abs(float a)
{
    if (a < 0)
    {
        return -a;
    }

    return a;
}

vector<int> generateRandom()
{
    // generate 4 random numbers in a vector
    vector<int> res{0, 0, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        res[i] = (rand() % 13) + 1;
    }

    return res;
}

set<vector<int>> permute(vector<int> nums, int offset, int idx)
{
    // return all permutation of nums

    set<vector<int>> res {};

    if (idx >= offset)
    {
        return res;
    }

    if (idx == offset - 1)
    {
        res.insert(nums);
        
        return res;
    }

    for (int i = idx; i < offset; i++)
    {
        swap(nums[idx], nums[i]);

        set<vector<int>> temp = permute(nums, offset, idx+1);
    
        set_union(res.begin(), res.end(), temp.begin(), temp.end(), inserter(res, res.begin()));      

        swap(nums[idx], nums[i]);
    }

    return res;
}

vector<string> repeatingCombination(string symbols, int symbolNum, int length)
{
    // return repeating combination (and their permutations) from distinct symbols
    
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

    vector<string> rec = repeatingCombination(symbols, symbolNum, length-1);

    for (int i = 0; i < symbolNum; i++)
    {
        vector<string> temp = rec;
        int l = temp.size();

        for (int j = 0; j < l; j++)
        {
            temp[j] = symbols.substr(i, 1) + temp[j];
        }

        res.insert(res.end(), temp.begin(), temp.end());
    }

    return res;
}

float calculate(float a, float b, char op)
{
    // menghitung hasil operasi a dan b dengan operator op

    if (op == '+')
    {
        return a + b;
    }

    else if (op == '-')
    {
        return a - b;
    }

    else if (op == '*')
    {
        return a * b;
    }

    else if (op == '/')
    {
        return a / b;
    }

    return 0;
}

float evaluator(vector<int>nums, string ops,  int parenthesisMode)
{
    // mengevaluasi hasil ekspresi matematika dengan 4 bilangan dan 3 operator
    // parenthesisMode == 0 -> ((a b) c) d
    // parenthesisMode == 1 -> (a b) (c d)
    // parenthesisMode == 2 -> (a (b c)) d
    // parenthesisMode == 3 -> a ((b c) d)
    // parenthesisMode == 4 -> a (b (c d))

    float res;

    if (parenthesisMode == 0)
    {
        float temp1 = calculate(nums[0], nums[1], ops[0]);
        float temp2 = calculate(temp1, nums[2], ops[1]);
        
        res = calculate(temp2, nums[3], ops[2]);
    }

    else if (parenthesisMode == 1)
    {
        float temp1 = calculate(nums[0], nums[1], ops[0]);
        float temp2 = calculate(nums[2], nums[3], ops[2]);
        
        res = calculate(temp1, temp2, ops[1]);
    }

    else if (parenthesisMode == 2)
    {
        float temp1 = calculate(nums[1], nums[2], ops[1]);
        float temp2 = calculate(nums[0], temp1, ops[0]);
        
        res = calculate(temp2, nums[3], ops[2]);
    }

    else if (parenthesisMode == 3)
    {
        float temp1 = calculate(nums[1], nums[2], ops[1]);
        float temp2 = calculate(temp1, nums[3], ops[2]);
        
        res = calculate(nums[0], temp2, ops[0]);
    }

    else
    {
        float temp1 = calculate(nums[2], nums[3], ops[2]);
        float temp2 = calculate(nums[1], temp1, ops[1]);
        
        res = calculate(nums[0], temp2, ops[0]);
    }

    return res;

}

string splitOp(string op)
{
    return " " + op + " ";
}

string generateString (vector<int>nums, string ops,  int parenthesisMode)
{
    // mengevaluasi hasil ekspresi matematika dengan 4 bilangan dan 3 operator
    // parenthesisMode == 0 -> ((a b) c) d
    // parenthesisMode == 1 -> (a b) (c d)
    // parenthesisMode == 2 -> (a (b c)) d
    // parenthesisMode == 3 -> a ((b c) d)
    // parenthesisMode == 4 -> a (b (c d))

    vector<string> cards = numToCard(nums);

    string res = "";

    if (parenthesisMode == 0)
    {
        res = "((" + cards[0] + splitOp(ops.substr(0, 1)) + cards[1] + ")" + splitOp(ops.substr(1, 1)) + cards[2] + ")" + splitOp(ops.substr(2, 1)) + cards[3];
    }

    else if (parenthesisMode == 1)
    {
        res = "(" + cards[0] + splitOp(ops.substr(0, 1)) + cards[1] + ")" + splitOp(ops.substr(1, 1)) + "(" + cards[2] + splitOp(ops.substr(2, 1)) + cards[3] + ")";
    }

    else if (parenthesisMode == 2)
    {
        res = "(" + cards[0] + splitOp(ops.substr(0, 1)) + "(" + cards[1] + splitOp(ops.substr(1, 1)) + cards[2] + "))" + splitOp(ops.substr(2, 1)) + cards[3];
    }

    else if (parenthesisMode == 3)
    {
        res = cards[0] + splitOp(ops.substr(0, 1)) + "((" + cards[1]  + splitOp(ops.substr(1, 1)) + cards[2] + ")" + splitOp(ops.substr(2, 1)) + cards[3] + ")";
    }

    else
    {
        res = cards[0] + splitOp(ops.substr(0, 1)) + "(" + cards[1] + splitOp(ops.substr(1, 1)) + "(" + cards[2] + splitOp(ops.substr(2, 1)) + cards[3] + "))";
    }

    return res;
    
}

void config()
{
    // membuat konfigurasi kombinasi operator yang mungkin
    string symbols = "+-*/";

    srand((unsigned int)time(NULL));
    opCombination = repeatingCombination(symbols, symbols.length(), 3);
}

vector<string> find(vector<int> nums)
{
    // mengembalikan semua solusi game 24 untuk nilai-nilai kartu tertentu

    set<vector<int>> permutation = permute(nums, nums.size());
    vector<string> res;

    if (!isConfigured)
    {
        config();
    }

    for (auto elmt : permutation)
    {
        for (auto ops : opCombination)
        {
            for (int i = 0; i < 5; i++)
            {
                if (float_abs(evaluator(elmt, ops, i) - 24) < FLT_EPSILON)
                {
                    res.push_back(generateString(elmt, ops, i));
                }
            }
        }
    }

    return res;
}