#include "decode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

/*
  Constructors and Destructors
*/

Decrypt::Decrypt() : input(""), key(""), message("") {}

/*
  Helper function to read the file and find the encryption key
*/
bool Decrypt::readFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "File not found" << endl;
        return false;
    }

    string line;
    while (getline(inFile, line)) {
        size_t grabKey = line.find("Encryption Key: ");
        if (grabKey != string::npos) {
            // Extract the key from the line
            key = line.substr(grabKey + 16);
            if (key.size() != 26) {
                cerr << "Key must be a 26-letter alphabetical string." << endl;
                return false;
            }

            // Assign the decryption key
            if (!code_assign(key)) {
                cerr << "Could not assign encryption key for: " << filename << endl;
                return false;
            }

            message = string((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
            return true;
        }
    }

    cerr << "Encryption key not found in: " << filename << endl;
    return false;
}

/*
  Function to assign the key and create the decryption mapping
*/
bool Decrypt::code_assign(const string& key) {
    if (key.size() != 26) {
        cerr << "Key must be a 26-letter alphabetical string." << endl;
        return false;
    }

    // Create decryption mapping (e.g., A->key[0], B->key[1], ...)
    decryption_mapping.clear();
    for (char c = 'A'; c <= 'Z'; ++c) {
        decryption_mapping[c] = key[c - 'A'];
    }

    return true;
}

/*
  Decode function: applies decryption mapping to the message and returns the decoded string.
*/
string Decrypt::decode(const unordered_map<char, char>& decryption_mapping, const string& message) {
    string decoded_message;
    decoded_message.reserve(message.size());

    for (char c : message) {
        if (isalpha(c)) {
            char uppercase_char = toupper(c);  // Convert to uppercase if needed
            decoded_message += decryption_mapping.count(uppercase_char) ? decryption_mapping.at(uppercase_char) : c;
        } else {
            decoded_message += c;  // Preserve punctuation and spaces
        }
    }
    return decoded_message;
}

/*
    Other utility functions
*/

void Decrypt::clear() {
    input.clear();
    key.clear();
    message.clear();
    decryption_mapping.clear();
}
