#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

    int CS = 0;
    string * secuencias;
    // Read file part
    ifstream file;
    file.open("Saltrina.in");
    if(file.is_open())
    {
        bool exit = true;
        while(exit)
        {
            string str;
            exit = std::getline(file, str);
            std::cout << str << std::endl;
        }
    }

}
