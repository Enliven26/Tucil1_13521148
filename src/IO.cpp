using namespace std;
#include <iostream>
#include <fstream>
#include <istream>
#include <regex>

// from src
#include "./headers/IO.h"
#include "./headers/card.h"

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
        cout << "\nInput kartu hanya dapat berupa angka [2, 10] atau karakter A, J, Q, dan K (huruf kapital)!\n";
        nl();
    }

    else{

        inputVector = split(input);
        inputNums = cardToNum(inputVector);

        if (isNumCardsValid(inputNums))
        {
            cout << "\nInput kartu berhasil!\n";
            nl();
            
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
        cout << "\nMasukkan 4 simbol kartu : ";
        getline(cin >> ws, input);
            
        res = isInputValid(removeExtraSpace(input));
        stop = get<0>(res);

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
            cout << "\nGagal membuka file!\n[Pastikan nama file benar]\n";
            nl();
        }
    
    }

    return get<1>(res);
}

void printResult(vector<string> outputs, float time)
{
    int l = outputs.size();

    cout << "\nBanyak solusi ditemukan : " + to_string(l) + "\n";

    nl();

    for(int i = 0; i < l; i++)
    {
        cout << outputs[i] + "\n";
    }

    nl();

    cout << "Waktu eksekusi : " + to_string(time / 1000) + "ms\n";

    nl();
}

void writeFile(vector<string> outputs, float time)
{
    // write outputs to a file

    string dist = "../test/output/", fileName;

    cout << "Masukkan nama file: " + dist;
    getline(cin >> ws, fileName);

    ofstream fileStream(dist + fixExtension(fileName));

    if (fileStream.is_open())
    {
        int l = outputs.size();

        fileStream << "Banyak solusi ditemukan : " + to_string(l) + "\n\n";

        for(int i = 0; i < l; i++)
        {
            fileStream << outputs[i] + "\n";
        }

        fileStream << "\nWaktu eksekusi : " + to_string(time / 1000) + "ms\n";
        
        fileStream.close();
    }
    
    else
    {
        cout << "Gagal membuat file!\n[Masukkan ulang nama file]\n";
    }

    nl();

    

}

void welcome()
{
    cout << "    __  ___    ___     __ __    ______           ____  ______          ___    __ __ \n";
    cout << "   /  |/  /   /   |   / //_/   / ____/          /  _/ /_  __/         |__ \\  / // /\n";
    cout << "  / /|_/ /   / /| |  /   /    / __/             / /    / /            __/ / / // /_ \n";
    cout << " / /  / /   / ___ | / /| |   / /___           _/ /    / /            / __/ /__  __/ \n";
    cout << "/_/  /_/   /_/  |_|/_/ |_|  /_____/          /___/   /_/            /____/   /_/    \n";
                                                              
}

void welcomeMenu()
{
    nl();
    cout << "[1] Start\n";
    cout << "[2] Exit\n";
    nl();
}

void inputMenu()
{
    nl();
    cout << "==== PILIHAN MASUKAN ====\n";
    nl();
    cout << "[1] Kartu Acak\n";
    cout << "[2] Input Konsol\n";
    cout << "[3] Input File\n";
    cout << "[4] Exit\n";
    nl(); 
}

void outputMenu()
{
    nl();
    cout << "==== PILIHAN KELUARAN ====\n";
    cout << "[1] Tampilkan ke Konsol\n";
    cout << "[2] Tulis ke File\n";
    nl();
}

int inputChoice(int lowerBound, int upperBound)
{
    int input;

    while (true)
    {
        cout << "Pilihan : ";
        cin >> input;
        
        nl();

        if (input < lowerBound || input > upperBound)
        {
            cout << "Input pilihan hanya dapat berada pada rentang [" + to_string(lowerBound) + "," + to_string(upperBound) + "]!\n";
            nl();
        }

        else {
            break;
        }
    }

    return input;
}

// int main()
// {
//     vector<string> outputs {"a", "ba", "c"};
//     writeFile(outputs, "aaaaaa.t3");
//     return 0;
// }