#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
using namespace std;

int main()
{
    ifstream ifs;
    ifs.open("C:/Users/thebe/Desktop/Terraforming-carta/data/Title_AA.txt");
    string str;
    while (std::getline(ifs, str))
    {
        std::cout << str << std::endl;
    }
}