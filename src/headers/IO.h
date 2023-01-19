#ifndef IO_H
#define IO_H

using namespace std;
#include <string>
#include <vector>

string fixExtension(string fileName);

string removeExtraSpace(string s);

void printVector(vector<string> outputs);

void printVector(vector<int> outputs);

void nl();

tuple<bool, vector<int>> isInputValid(string input);

vector<int> getCards();

vector<int> getInputFile();

void printResult(vector<string> outputs, float time);

void writeFile(vector<string> outputs, float time);

void welcome();

void welcomeMenu();

void inputMenu();

void outputMenu();

int inputChoice(int lowerBound, int upperBound);

#endif