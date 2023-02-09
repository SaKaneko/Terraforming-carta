#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
#include <Windows.h>
#include <Params.hpp>
#include <Read_csv.hpp>
#include <string2speak.hpp>
namespace fs = std::filesystem;

namespace TC
{
    struct card
    {
        std::string id;
        std::string name;
        std::string flavor;

        void print()
        {
            std::cout << id << " " << name << " " << flavor << std::endl;
        }
    };

    struct Deck
    {
        std::vector<card> cv;

        void shufle()
        {
            std::random_device get_rand_dev;
            std::mt19937 get_rand_mt(get_rand_dev());
            std::shuffle(cv.begin(), cv.end(), get_rand_mt);
        }

        void Init_cards()
        {
            auto get = csv::Read_csv(TC::CardDataP);
            for (auto &x : get)
            {
                card c = {x[0], x[1], x[2]};
                cv.push_back(c);
            }
            this->shufle();
        }

        void Extract_cards(fs::path &p)
        {
            std::map<std::string, int> mp;
            for (int i = 0; i < cv.size(); i++)
            {
                mp[cv[i].id] = i;
            }

            auto get = csv::Read_csv(p);
            std::vector<card> newcv;
            for (auto &x : get)
            {
                if (mp.count(x[0]))
                {
                    newcv.push_back(cv[mp[x[0]]]);
                }
                else
                {
                    std::cout << "[Warning] card list doesn't contain card id : " << x[0] << std::endl;
                }
            }
            cv = newcv;
            this->shufle();
        }

        void print_all()
        {
            for (auto &x : cv)
            {
                x.print();
            }
        }
        void Read_standard()
        {
            for (int i = 0; i < cv.size(); i++)
            {
                std::cout << "Remain " << cv.size() - i << " Cards. Press Enter ..." << std::endl;
                std::cin.ignore();
                Sleep(1000 * TC::Init_wait);
                TC::str2speak(cv[i].flavor);
                Sleep(1000 * TC::Init_wait);
                TC::str2speak(cv[i].flavor);
                Sleep(1000 * TC::interval_sec);
                TC::str2speak(cv[i].name);
                std::cout << cv[i].name << std::endl;
            }
        }
    };
}