#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string encryption_key = "";
    string str_to_encr = "";

    //Get the encryption key
    cout << "Enter the encryption key: ";
    getline(cin, encryption_key);

    //Check the validity of the key before continuing. If it's not okay, gives an error.
    string::size_type enc_str_length = 0;
    enc_str_length = encryption_key.length();

    //Check if the key is 26 characters long, if not, throw an error
    if(enc_str_length != 26){
        cout << "Error! The encryption key must contain 26 characters." << endl;
        return EXIT_FAILURE;
    }

    //Check if all the characters are lower case and from a-z. If not, throw an error.
    for(string::size_type i = 0; i < enc_str_length; ++i){
        if(!islower(static_cast<unsigned char>(encryption_key[i]))){
            cout << "Error! The encryption key must contain only lower case characters." << endl;
            return EXIT_FAILURE;
        }
    }

    //Define helping hand for checking the alphabet
    string::size_type handy_help = 0;
    string alphabets = "abcdefghijklmnopqrstuvwxyz";

    //Check if the key has all alphabets a-z. If not, throw an error. 97-122
    for(string::size_type i = 0; i < enc_str_length; ++i){
        handy_help = encryption_key.find(alphabets[i]);
        if(handy_help == string::npos){
            cout << "Error! The encryption key must contain all alphabets a-z." << endl;
            return EXIT_FAILURE;
        }
    }

    //Get the string to be encrypted
    cout << "Enter the text to be encrypted: ";
    getline(cin, str_to_encr);

    //Make a copy of the given string
    string encrypted = str_to_encr;

    //Replace the letter in given string copy with corresponding letter. Index gotten from alphabets.
    for(string::size_type i = 0; i < str_to_encr.length(); ++i){
        char current_letter = str_to_encr[i];
        string::size_type index = current_letter - 'a';
        encrypted[i] = encryption_key[index];
    }

    //Print the text
    cout << "Encrypted text: " << encrypted << endl;

    return 0;
}
