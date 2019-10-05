#ifndef VITALS_H
#define VITALS_H

#include <iostream>
#include <thread>  // For sleep.
#include <random>  // For mt19937.
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

    happiness = (hunger + thirst + smell) / 3;

    health = (energy + hunger + thirst) / 3;

}

void Vitals::Vitals::GetIntro()
{
    std::cout << "\n";
    std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    std::cout << " I can eat, drink, shower\n";
    std::cout << " sleep, or play with you  \n";
    std::cout << " if you enter each of the \n";
    std::cout << " following commands:      \n";
    std::cout << "_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    sleep_for(1s);
    std::cout << "\n";
    std::cout << "\n";
}


void Vitals::Vitals::GetCare()
{
    string answer{};
    string prompt{};

do{
        do{
            GetStats();
            std::cout << "\n";
            std::cout << "#----------------MENU-----------------#\n";
            std::cout << " |\"F\" for [feed]   \"D\" for [drink] |\n";
            std::cout << " |\"C\" for [clean]  \"B\" for [bath]  |\n";
            std::cout << " |\"Z\" for [sleep]  \"P\" for [play]  |\n";
            std::cout << " |\"X\" for [heal]   \"O\" for [chat]  |\n";
            std::cout << " |\"H\" for [status] \"Q\" to  [quit]  |\n";
            std::cout << "#-------------------------------------#\n";
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
                GetSleep();
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
            }*/

            else if (prompt == "H" || prompt == "h")
            {
                GetStatus();
            }


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
    std::cout << R"(
                    #-_-_-_-_-_-_-_-_-_-_-_-_-_#
                    # Bye!!! See you next time!#
                    #-_-_-_-_-_-_-_-_-_-_-_-_-_#)";
    std::cout << "\n";
    sleep_for(2s);
}

void Vitals::Vitals::GetStats()
{
    std::cout << "\n";
    std::cout << "###################\n";
    std::cout << "#  Satiety: " << hunger << "    #\n";
    std::cout << "#  Quench: " << thirst << "     #\n";
    std::cout << "#  Hygiene: " << smell << "    #\n";
    std::cout << "#  Company: " << loneliness << "    #\n";
    std::cout << "#  Energy: " << energy << "     #\n";
    std::cout << "#  Poop: " << poop << "        #\n";
    std::cout << "#  Happiness: " << happiness << "  #\n";
    std::cout << "#  Health: " << health << "     #\n";
    std::cout << "###################\n";
}

void Vitals::Vitals::GetStatus()
{
    std::cout << "Satiety:\n";
        if (hunger == 100)
            {
                std::cout << "I am not hungry.\n";
            }
        else if (hunger >= 80 && hunger < 100)
            {
                std::cout << "I am a little peckish.\n";
            }
        else if (hunger >= 50 && hunger < 80)
            {
                std::cout << "I am hungry.\n";
            }
        else if (hunger >= 25 && hunger < 50)
            {
                std::cout << "I am very hungry.\n";
            }
        else
            {
                std::cout << "I am starving.\n";
            }

        std::cout << "Quench:\n";
        if (thirst == 100)
            {
                std::cout << "I am not thirsty.\n";
            }
        else if (thirst >= 80 && thirst < 100)
            {
                std::cout << "I am a little parched.\n";
            }
        else if (thirst >= 50 && thirst < 80)
            {
                std::cout << "I am thirsty.\n";
            }
        else if (thirst >= 25 && thirst < 50)
            {
                std::cout << "I am very thirsty.\n";
            }
        else
            {
                std::cout << "I am drained.\n";
            }

        std::cout <<"Hygiene:\n";
        if (smell == 100)
            {
                std::cout << "I am squeaky clean.\n";
            }
        else if (smell >= 80 && smell < 100)
            {
                std::cout << "I am a little dirty.\n";
            }
        else if (smell >= 50 && smell < 80)
            {
                std::cout << "I am dirty.\n";
            }
        else if (smell >= 25 && smell < 50)
            {
                std::cout << "I am very dirty.\n";
            }
        else
            {
                std::cout << "I am stinking.\n";
            }

        std::cout << "Energy:\n";
        if (energy == 100)
            {
                std::cout << "I am energetic.\n";
            }
        else if (energy >= 80 && energy < 100)
            {
                std::cout << "I am awake.\n";
            }
        else if (energy >= 50 && energy < 80)
            {
                std::cout << "I am somewhat drowsy.\n";
            }
        else if (energy >= 25 && energy < 50)
            {
                std::cout << "I am very drowsy.\n";
            }
        else
            {
                std::cout << "I am sleepy.\n";
            }

        std::cout << "Happiness:\n";
        if (happiness >= 80 && happiness <= 100)
            {
                std::cout << "I am ecstatic.\n";
            }
        else if (happiness >= 30 && happiness < 80)
            {
                std::cout << "I am in high spirits.\n";
            }
        else if (happiness >= 25 && happiness < 30)
            {
                std::cout << "I am kind of down.\n";
            }
        else
            {
                std::cout << "I am mad and depressed.\n";
            }

        std::cout << "Health:\n";
        if (health >= 80 && health <= 100)
            {
                std::cout << "I am healthy.\n";
            }
        else if (health >= 50 && health < 80)
            {
                std::cout << "I am under the weather.\n";
            }
        else if (health >= 25 && health < 50)
            {
                std::cout << "I am kind of sick.\n";
            }
        else if (health >= 5 && health < 25)
            {std::cout << "I am sick.\n";}
        else if (health >= 1 && health < 5)
            {
                std::cout << "I am dying.\n";
            }
        else
            {
                if (health <= 0)
                {
                    health = 0;
                }
                std::cout << "Good-bye...\n";
            }
}

inline int Vitals::Vitals::GetHunger(void)
{
    return hunger;
}

void Vitals::Vitals::GetFeed()
{
    std::cout << "You feed your pet.\n";
    hunger += 15;
    poop += 5;
    if (hunger > 100)
    {
        hunger = 100;
    }
}

inline int Vitals::Vitals::GetThirst(void)
{
    return thirst;
}
void Vitals::Vitals::GetDrink()
{
    std::cout << "You give water to your pet.\n";
    thirst += 15;
    poop += 2;
    if (thirst > 100)
    {
        thirst = 100;
    }
}

inline int Vitals::Vitals::GetSmell(void)
{
    return smell;
}
void Vitals::Vitals::GetClean()
{
    std::cout << "You clean your pet.\n";
    smell += 25;
    poop -= 15;
    if (smell > 100)
    {
        smell = 100;
    }
    else if (poop < 0)
    {
        poop = 0;
    }
}
void Vitals::Vitals::GetBath()
{
    std::cout << "You bath your pet.\n";
    smell = 100;
    poop = 0;
}

inline int Vitals::Vitals::GetLoneliness(void)
{
    return loneliness;
}
void Vitals::Vitals::GetPlay()
{
    if (loneliness == 0)
    {
        std::cout << "I don't want to play.\n";
    }
    else if (hunger < 60)
    {
        std::cout << "I am too hungry  to play.\n";
    }
    else if (thirst < 60)
    {
        std::cout << "I am too thirsty  to play.\n";
    }
    else
    {
        std::cout << "Wee!!!\n";
        smell -= 15;
        hunger -= 15;
        thirst -= 15;
        energy -= 15;
        loneliness += 35;
        if (loneliness > 100)
        {
        loneliness = 100;
        }
        else if (smell < 0)
        {
            smell = 0;
        }
        else if (hunger < 0)
        {
            hunger = 0;
        }
        else if (thirst < 0)
        {
            thirst = 0;
        }
        else if (energy < 0)
        {
            energy = 0;
        }
    }
}

inline int Vitals::Vitals::GetEnergy(void)
{
    return energy;
}
void Vitals::Vitals::GetSleep()
{
    std::cout << "You tuck your pet.\n";
    if (energy >= 0 && energy < 100)
    {
        energy += 25;
        if (energy > 100)
        {
        energy = 100;
        }
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
    health += 25;
    if (health > 100)
    {
        health = 100;
    }
}

#endif // VITALS_H
