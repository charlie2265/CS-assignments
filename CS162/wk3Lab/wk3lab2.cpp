

/******************************************************************************

Week  3 Lab2
SSn input validation

*******************************************************************************/
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    cout<<"SSN Database ;) \n\n";
    
    bool right_length {}, all_digits {};
    
    
    
    string ssn;        // store social sec num entered by user
    
    // Prompt user and get input.
    
    do {
        
        cout << "Please enter a social security number (9 digits, no hyphens): ";
        
        cin >> ssn;
        
        //validate length.(right_length)
        right_length = (ssn.length() ==9);
        
        //validate for only digits. (all_digits)
        all_digits = true;
        for (int idx = 0; idx < ssn.length(); ++idx)
            if (!isdigit(ssn[idx]))
                all_digits = false;
        //output error message.
        if (!right_length)
            cout << "Oops! Wrong lenght..." << endl;
        if (!all_digits)
            cout << "Oops! Please enter only digits. " << endl;
        
    }while(!right_length || !all_digits);         
    
    // Display ssn
    cout << "You entered " << ssn << endl;
    // Display ssn with hyphens
    cout << ssn[0] << ssn[1] << ssn[2] << "-" << ssn[3] << ssn[4] << "-" << ssn[5] << ssn[6] << ssn[7] << ssn[8] << endl;
    // housekeeping
    ssn = "\0\0\0\0\0\0\0\0\0";

    return 0;
}
