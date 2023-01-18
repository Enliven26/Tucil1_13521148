using namespace std;
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>

// from src
#include "card.cpp"

tuple<bool, vector<int>> isInputValid(string s)
{
    bool isValid = false;
    tuple<bool, vector<int>> res;
    vector<string> inputVector;
    vector<int> inputNums;

    if (!isCardString(input))
    {
        cout << "Input kartu hanya dapat berupa angka [2, 10] atau karakter A, J, Q, dan K!\n";
    }

    inputVector = split(input);
    inputNums = cardToNum(inputVector);

    if (isNumCardsValid(inputNums))
    {
        cout << "Input kartu berhasil!";
        isValid = true;
    }

    else
    {
        cout << "Input harus berupa 4 karakter kartu valid yang dipisahi spasi!";
    }      

    res = (isValid, inputNums);
    
    return res;
}

vector<int> getCards()
{
    // menerima input kartu melalui konsol hingga input valid

    bool stop = false;
    string input;
    vector<string> inputVector;
    tuple<bool, vector<int>> res {};

    while (!stop)
    {
        cin << input;

        if (input == "exit")
        {
            stop = true;
        }

        else {
            
            res = isInputValid(input);
            stop = get<0>(res);
        }
    }

    return get<1>res;

}

vector<int> getInputFile()
{
    // menerima input file berupa angka-angka kartu
    
    string myText;

    // Read from the text file
    ifstream MyReadFile("filename.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
    // Output the text from the file
    cout << myText;
    }

    // Close the file
    MyReadFile.close();

    bool stop = false;
    string input, fileName;
    vector<string> inputVector;
    tuple<bool, vector<int>> res {};

    while (!stop)
    {
        cin << fileName;

        ifstream fileStream(fixExtension(fileName));

        getline(fileStream, input);
    
            
        res = isInputValid(input);
        stop = get<0>(res);
    }

    return get<1>res;
}

string fixExtension(string fileName)
{
    // make sure file extension is txt
    int idx = fileName.find('.');

    if (idx == string::npos)
    {
        return fileName + ".txt";
    }

    return fileName.substr(0, idx) + ".txt";
}
void writeFile(vector<string> outputs, string fileName)
{
    // write outputs to a file

    ofstream fileStream(fixExtension(fileName));

    int l = outputs.size();
    
    for(int i = 0; i < l; i++)
    {
        fileStream << outputs[i] + "\n";
    }

    MyFile.close();
}