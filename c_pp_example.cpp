#include <iostream>

using namespace std;

//Simple C++ example from a school course
int main()
{
    string given_string = "";
    string str_to_look_for = "";

    //Ask and get the longer string
    cout << "Enter a (longer) string: ";
    getline(cin, given_string);

    //Ask and get the shorter string
    cout << "Enter a (shorter) string to be found: ";
    getline(cin, str_to_look_for);

    //Find out what is the length of the given string and assign it to variable
    string::size_type longer_len = 0;
    longer_len = given_string.find(str_to_look_for);

    //Check if the shorter string is found or not
    if(longer_len == string::npos){
        cout << "Not found" << endl;
    }else{
        cout << "Found at " << longer_len;

        //List all found positions
        while((longer_len = given_string.find(str_to_look_for, longer_len + 1)) != string::npos){
            cout << ", " << longer_len;
        }

        //End line
        cout << endl;
    }

    return 0;
}
