#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    string fileName;
    cout << "Enter the name of the file: ";
    cin >> fileName;

    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    vector<char> code;
    char ch;
    while (inputFile.get(ch)) {
        if (ch == '+' || ch == ';' || ch == '-' || ch == '<' || ch == '>' || ch == ':' || ch == '!' || ch == '/') {
            code.push_back(ch);
        }
        else if (ch != ' ' && ch != '\n' && ch != '\r' && ch != '\t') {
            cout << "Warning: Ignoring unknown character '" << ch << "'." << endl;
        }
    }

    inputFile.close();

    vector<char> memory(10); 
    int ip = 0;

    for (int i = 0; i < code.size(); i++) {
        switch (code[i]) {
        case '+':
            memory[ip]++;
            break;
        case ';':
            cout << memory[ip];
            ip++;
            break;
        case '-':
            memory[ip]--;
            break;
        case '<':
            ip--;
            break;
        case '>':
            ip++;
            break;
        case ':':
            memory[ip] = 110;
            break;
        case '!':
            memory[ip] = 40;
            break;
        case '/':
            for (int i = 1; i < memory.size(); i++) {
                memory[i] = memory[0];
            }
            break;
        default:
            cout << "Error: Unknown instruction '" << code[i] << "'." << endl;
            break;
        }
    }

    return 0;
}