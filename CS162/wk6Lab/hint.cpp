/******************************************************************************

CS162
*******************************************************************************/
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

const string FILENAME = "customers.dat";
const int MAX = 3;

class Client {
    private:
        char id[10];
        char co_name[25];
    
    public:
        Client() { strcpy(id, ""); strcpy(co_name, ""); }
        Client(const char arg_id[], const char arg_co_name[]) { strcpy(id, arg_id), strcpy(co_name, arg_co_name); }
        void set_id(const char arg_id[]) { strcpy(id, arg_id); }
        void set_co_name(char arg_co_name[]) { strcpy(co_name, arg_co_name); }
        
};

void Initialize(Client arr[]);
void CreateFile();
bool Menu();
void WrapUp(Client arr[]);




int main()
{
    Client client[4]; 
    
    Initialize(client); // Read client data from file
    
    while (Menu());     // Menu returns false when user chooses 'q' or 'Q' to quit
    
    WrapUp(client);     // Erase sensitive data

    return 0;
}

void Initialize(Client arr[]) {
    
    fstream rafile;
    
    rafile.open(FILENAME, ios::in | ios::binary); // Just to see whether it exists
    
    if (!rafile) {
        CreateFile();
    }
    else
        rafile.close();
        
    rafile.open(FILENAME, ios::in | ios::binary);
    
    //rafile.read - figure this out
    
    rafile.close();

}

void CreateFile() {
    Client temp[MAX] {  { "123", "Fred Meyer" },
                        { "456", "Walmart"},
                        { "789", "Shane Co." }
    };
    
    fstream data_file;
    
    data_file.open(FILENAME, ios::out | ios::binary);
    
    data_file.write(reinterpret_cast<char*>(temp), 3 * sizeof(Client));
    
    data_file.close();
    
}

bool Menu() {bool result {}; return result;}
void WrapUp(Client arr[]){};