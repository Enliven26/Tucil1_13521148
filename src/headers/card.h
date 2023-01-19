#ifndef CARD_H
#define CARD_H

using namespace std;
#include <string>
#include <vector>
#include <map>

extern map<string, int> cardMap;
extern map<int, string> numMap;

vector<string> split(string s, char delimeter = ' ');

bool isCardString(string s);

bool isNumCardsValid(vector<int> input);

vector<int> cardToNum(vector<string> cards);

vector<string> numToCard(vector<int> nums);

#endif