#include "decode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

/*
  Constructors and Destructors
*/

Decrypt::Decrypt() : input(""), text("") {}

Decrypt::~Decrypt() {
    clear();
}

/*
  This function reads the file, looks for the encryption key, and sends that information for assignment.
*/
bool Decrypt::getline(const string& filename) {
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
            string key = line.substr(grabKey + 16);
            if (key.size() != 26) {
                cerr << "Key must be a 26-letter alphabetical string." << endl;
                return false;
            }

            if (!code_assign(filename, key)) {
                cerr << "Could not assign encryption key for: " << filename << endl;
                return false;
            }

            return true;
        }
    }

    cerr << "Encryption key not found in: " << filename << endl;
    return false;
}

/*  
  Code_assign takes the key, creates an unordered map, and decodes the message.
*/
bool Decrypt::code_assign(const string& filename, const string& Key) {
    if (Key.size() != 26) {
        cerr << "Key must be a 26-letter alphabetical string." << endl;
        return false;
    }

    // Create decryption mapping (e.g., A->Key[0], B->Key[1], ...)
    unordered_map<char, char> decryption_mapping;
    for (char c = 'A'; c <= 'Z'; ++c) {
        decryption_mapping[c] = Key[c - 'A'];
    }

    // Read the entire message from the file
    ifstream file(filename);
    if (!file) {
        cerr << "File not found: " << filename << endl;
        return false;
    }

    string message((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    // Decode the message
    string decoded_message = decode(decryption_mapping, message);
    cout << "Decoded Message:\n" << decoded_message << endl;

    return true;
}

/*
  Decode function: applies decryption mapping to the message and returns the decoded string.
*/
string Decrypt::decode(const unordered_map<char, char>& decryption_mapping, const string& message) {
    string new_message;
    new_message.reserve(message.size());

    for (char c : message) {
        if (isalpha(c)) {
            char uppercase_char = toupper(c);  // Convert to uppercase if needed
            if (decryption_mapping.find(uppercase_char) != decryption_mapping.end()) {
                new_message += decryption_mapping.at(uppercase_char);
            } else {
                new_message += c;  // Fallback for alphabetic but unmapped characters
            }
        } else {
            new_message += c;  // Preserve punctuation and spaces
        }
    }
    return new_message;
}

