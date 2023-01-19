using namespace std;
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <istream>
#include <regex>

// from src
#include "card.cpp"

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

string removeExtraSpace(string s)
{
    // menghilangkan extra space pada suatu string 

    return regex_replace(s, regex("^ +| +$|( ) +"), "$1");
}

void printVector(vector<string> outputs)
{
    // mencetak vektor string

    int l = outputs.size();
 
    for(int i = 0; i < l-1; i++)
    {
        cout << outputs[i] + " ";
    }

    cout << outputs[l-1];
}

void printVector(vector<int> outputs)
{
    // mencetak vektor angka 

    int l = outputs.size();

    for(int i = 0; i < l-1; i++)
    {
        cout << to_string(outputs[i]) + " ";
    }

    cout << outputs[l-1];
}

void nl()
{
    cout << "\n";
}


tuple<bool, vector<int>> isInputValid(string input)
{
    // memeriksa apakah input 4 simbol kartu valid
    
    bool isValid = false;
    vector<string> inputVector;
    vector<int> inputNums;
    
    if (!isCardString(input))
    {
        cout << "Input kartu hanya dapat berupa angka [2, 10] atau karakter A, J, Q, dan K (huruf kapital)!\n";
    }

    else{

        inputVector = split(input);
        inputNums = cardToNum(inputVector);

        if (isNumCardsValid(inputNums))
        {
            cout << "Input kartu berhasil!\n";
            isValid = true;
        }
    }
    
    tuple<bool, vector<int>> res (isValid, inputNums);
    
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
        getline(cin >> ws, input);

        if (input == "exit")
        {
            stop = true;
        }

        else {
            
            res = isInputValid(removeExtraSpace(input));
            stop = get<0>(res);
        }
    }

    return get<1>(res);

}

vector<int> getInputFile()
{
    // menerima input file berupa angka-angka kartu

    bool stop = false;
    string input, fileName;
    vector<string> inputVector;
    tuple<bool, vector<int>> res {};
    
    string dist = "../test/input/";

    while (!stop)
    {
        cout << "Masukkan nama file: " + dist;
        getline(cin >> ws, fileName);

        ifstream fileStream(dist + fixExtension(fileName));

        if (fileStream.is_open())
        {
            getline(fileStream, input);
                
            res = isInputValid(removeExtraSpace(input));
            stop = get<0>(res);

            fileStream.close();
        }

        else
        {
            cout << "Gagal membuka file!\n[Pastikan nama file benar]\n";
        }
    
    }

    return get<1>(res);
}

void writeFile(vector<string> outputs, string fileName)
{
    // write outputs to a file

    string dist = "../test/output/";

    ofstream fileStream(dist + fixExtension(fileName));

    if (fileStream.is_open())
    {
        int l = outputs.size();
    
        for(int i = 0; i < l; i++)
        {
            fileStream << outputs[i] + "\n";
        }

        fileStream.close();
    }
    
    else
    {
        cout << "Gagal membuka file!\n";
    }
}

// int main()
// {
//     vector<string> outputs {"a", "ba", "c"};
//     writeFile(outputs, "aaaaaa.t3");
//     return 0;
// }