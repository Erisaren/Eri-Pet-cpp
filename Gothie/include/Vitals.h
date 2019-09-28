#ifndef VITALS_H
#define VITALS_H

#include <iostream>
#include <thread>
#include <random>  // For mt19937.
#include <cmath>
#include <cstdlib>
using namespace std::this_thread;  // sleep_for, sleep_until
using namespace std::chrono_literals;  // ns, us, ms, s, h


class Droid;  // Forward declaration.
class Vitals  // Object.
{
    private:  // Set multiple times.
        int hunger{};
        int thirst{};
        int smell{};
        int loneliness{};
        int energy{};
        int poop{0};
        int happiness{};
        int health{};
    public:
        Vitals(void);  // Constructor with getter and setter.
        int GetHunger(void);  // Getters.
        int GetThirst(void);
        int GetSmell(void);
        int GetLoneliness(void);
        int GetEnergy(void);
        int GetPoop(void);
        int GetHappiness(void);
        int GetHealth(void);

        // Setters. Functions.
        void GetIntro();
        void GetCare();
        void GetEnd();
        void GetStats();
        void GetStatus();
        void GetFeed();
        void GetDrink();
        void GetClean();
        void GetBath();
        void GetPlay();
        void GetChichat();  // Not implemented.
        void GetSleep();
        void GetHeal();

        void TimeLapse();  // Not implemented.
        //bool isDead();
};


Vitals::Vitals(void)
{
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(25,75);

    hunger = distribution(device);

    thirst = distribution(device);

    smell = distribution(device);

    loneliness = distribution(device);

    energy = distribution(device);

}

void Vitals::Vitals::GetIntro()
{
    std::cout << "I am happy to see you!\n";
    sleep_for(2s);

}

void Vitals::Vitals::GetCare()
{
    string answer{};
    string prompt{};

do{
        do{
            GetStats();
            std::cout << "I can eat, drink, shower, sleep, or play with you if you enter each of the following commands:\n";
            std::cout << "   --------------MENU--------------- \n";
            std::cout << "  |\"F\" for [feed]   \"D\" for [drink] |\n";
            std::cout << "  |\"C\" for [clean]  \"B\" for [bath]  |\n";
            std::cout << "  |\"Z\" for [sleep]  \"P\" for [play]  |\n";
            std::cout << "  |\"X\" for [heal]   \"O\" for [chat]  |\n";
            std::cout << "  |\"H\" for [status] \"Q\" to  [quit]  |\n";
            std::cout << "   --------------------------------- \n";

            std::getline(std::cin, prompt);

            if (prompt == "F" || prompt == "f")
            {
                GetFeed();
            }

            else if (prompt == "D" || prompt == "d")
            {
                GetDrink();
            }

            else if (prompt == "C" || prompt == "c")
            {
                GetClean();
            }

            else if (prompt == "B" || prompt == "b")
            {
                GetBath();
            }

            else if (prompt == "Z" || prompt == "z")
            {
                GetHeal();
            }

            else if (prompt == "P" || prompt == "p")
            {
                GetPlay();
            }

            else if (prompt == "X" || prompt == "x")
            {
                GetHeal();
            }

            /*else if (prompt == "O" || prompt == "o")
            {
                GetChichat();
            }

            else if (prompt == "H" || prompt == "h")
            {
                GetStatus();
            }*/


        } while ((prompt != "Q" || prompt != "q") && (prompt == "F" || prompt == "f" || prompt == "D" || prompt == "d" || prompt == "C" || prompt == "c" || prompt == "B" || prompt == "b" || prompt == "Z" || prompt == "z" || prompt == "P" || prompt == "p" || prompt == "X" || prompt == "x" || prompt == "O" || prompt == "o" || prompt == "H" || prompt == "h"));

        if (prompt == "Q" || prompt == "q")
            {
                GetEnd();
            }

        std::cout << "Press \"E\" to exit...\n";
        std::getline(std::cin, answer);
    } while (prompt == "E" || prompt == "e");
}

void Vitals::Vitals::GetEnd()
{
    std::cout << "Bye!!! See you next time!" << "\n";
}

void Vitals::Vitals::GetStats()
{
    happiness = 300 - (hunger + thirst + smell);  // Happiness = 300.

    health = round(200 - ((energy * 2) - ((hunger + thirst) / 2)));

    std::cout << "Hunger: " << hunger << "\n";
    std::cout << "Thirst: " << thirst << "\n";
    std::cout << "Hygiene: " << smell << "\n";
    std::cout << "Loneliness: " << loneliness << "\n";
    std::cout << "Energy: " << energy << "\n";
    std::cout << "Poop: " << poop << "\n";
    std::cout << "Happiness: " << happiness << "\n";
    std::cout << "Health: " << health << "\n";
}

inline int Vitals::Vitals::GetHunger(void)
{
    return hunger;
}

void Vitals::Vitals::GetFeed()
{
    std::cout << "You feed your pet.\n";
    hunger += 40;
    poop += 5;
    if (hunger < 0)
    {
        hunger = 0;
    }
}

inline int Vitals::Vitals::GetThirst(void)
{
    return thirst;
}
void Vitals::Vitals::GetDrink()
{
    std::cout << "You give water to your pet.\n";
    thirst += 40;
    poop += 1;
    if (thirst < 0)
    {
        thirst = 0;
    }
}

inline int Vitals::Vitals::GetSmell(void)
{
    return smell;
}
void Vitals::Vitals::GetClean()
{
    std::cout << "You clean your pet.\n";
    smell -= 40;
    poop -= 2;
    if (smell < 0)
    {
        smell = 0;
    }
}
void Vitals::Vitals::GetBath()
{
    std::cout << "You bath your pet.\n";
    smell = 0;
    poop = 0;
    if (smell < 0)
    {
        smell = 0;
    }
}

inline int Vitals::Vitals::GetLoneliness(void)
{
    return loneliness;
}
void Vitals::Vitals::GetPlay()
{
    std::cout << "You play with your pet.\n";
    loneliness -= 40;
    if (loneliness < 0)
    {
        loneliness = 0;
    }
}

inline int Vitals::Vitals::GetEnergy(void)
{
    return energy;
}
void Vitals::Vitals::GetSleep()
{
    std::cout << "You tuck your pet.\n";
    energy += 40;
    if (energy > 100)
    {
        energy = 100;
    }
}

inline int Vitals::Vitals::GetPoop(void)
{
    return poop;
}

inline int Vitals::Vitals::GetHappiness(void)
{
    return happiness;
}

inline int Vitals::Vitals::GetHealth(void)
{
    return health;
}
void Vitals::Vitals::GetHeal()
{
    std::cout << "You give medicine  to your pet.\n";
    health -= 40;
    if (health > 100)
    {
        health = 100;
    }
}

#endif // VITALS_H
