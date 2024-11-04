#include "decode.h"

#include <iostream>
#include <ifstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex> // to look for a pattern

using namespace std;

string loadingMessgae(cosnt string& filename){
    ifstream file(filename);

    if(!file.isOpen()){
        cerr << "There's a problem with opening the file..." << endl;
        exit(1);
    }
    return string((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
}

void displayMessage(const string& encryptedMessage, const string& decryptedMessage) {
    cout << "\nEncrypted Message:\n" << encryptedMessage << endl;
    cout << "Decrypted Message:\n" << decryptedMessage << endl;
}


int main() {
string filename = "encrypted.txt";
    string encryptedMessage = loadEncryptedMessage(filename);

    unordered_map<char, char> decryptionMapping;
    string decryptedMessage;

    while (true) {
        decryptedMessage = decrypt(encryptedMessage, decryptionMapping);
        displayMessage(encryptedMessage, decryptedMessage);

        cout << "\nEnter a substitution (e.g., 'a=b', 'x=y') or type 'exit' to finish: ";
        string userInput;
        getline(cin, userInput);

        if (userInput == "exit") {
            break;
        }

        try {
            size_t equalsPos = userInput.find('=');
            if (equalsPos == string::npos || equalsPos == 0 || equalsPos == userInput.size() - 1) {
                throw invalid_argument("Invalid input format.");
            }

            char encryptedChar = userInput[0];
            char decryptedChar = userInput[2];
            decryptionMapping[encryptedChar] = decryptedChar;
        }
        catch (const invalid_argument& e) {
            cerr << "Invalid input. Please provide a valid substitution pair." << endl;
        }
    }

    // Save the final decrypted message to a file
    saveDecryptedMessage(decryptedMessage, "decrypted.txt");

    return 0;
}