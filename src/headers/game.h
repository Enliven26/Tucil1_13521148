#ifndef GAME_H
#define GAME_H

using namespace std;
#include <string>
#include <vector>
#include <set>

extern vector<string> opCombination;
extern bool isConfigured;

vector<int> generateRandom();

set<vector<int>> permute(vector<int> nums, int offset, int idx = 0);

vector<string> repeatingCombination(string symbols, int symbolNum, int length);

float calculate(float a, float b, char op);

float evaluator(vector<int>nums, string ops,  int parenthesisMode);

string splitOp(string op);

string generateString (vector<int>nums, string ops,  int parenthesisMode);

void config();

vector<string> find(vector<int> nums);

#endif