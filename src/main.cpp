#include <iostream>
#include <CardDealer.hpp>
#include <string2speak.hpp>

int main()
{
    std::ifstream ifs;
    ifs.open("C:/Users/thebe/Desktop/Terraforming-carta/data/Title_AA.txt");
    std::string str;
    while (std::getline(ifs, str))
    {
        std::cout << TC::UTF8toSjis(str) << std::endl;
    }
    TC::Deck D;
    D.Init_cards();
    D.Extract_cards(TC::TestcaseP);
    D.Read_standard();
    return 0;
}