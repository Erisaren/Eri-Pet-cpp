#include <iostream>
#include <thread>  // For sleep.
#include <random>  // For Mersenne Twist.
using namespace std::this_thread;  // For sleep.
using namespace std::chrono_literals;  // For time.
using std::string;


class Pet
{
    private:  // Private values.
        // ID.
        string owner{};
        string name{};
        string gender{};
        string model{};
        int age{0};
        // Stats.
        int hunger{};
        int thirst{};
        int smell{};
        int energy{};
        int poop{0};
        int happy{};
        int healthy{};
        int happiness{};
        int health{};
    public:
        Pet(void);  // Constructor with getters and setters. Or so.
        void SetOwner(string owner_name);
        string GetOwner(void);

        void SetName(string pet_name);
        string GetName(void);

        void SetGender(string pet_gender);
        string GetGender(void);

        void SetAge(int pet_age);
        int GetAge(void);


        // Ahem... Getters for stats.
        int GetHunger(void);
        int GetThirst(void);
        int GetSmell(void);
        int GetEnergy(void);
        int GetPoop(void);
        int GetHappiness(void);
        int GetHealth(void);

        // Double ahem... Functions to care for pet.
        void GetIntro();
        void GetCare();
        void GetEnd();
        void GetStats();
        void GetStatus();
        void GetFeed();
        void GetDrink();
        void GetClean();
        void GetBath();
        void GetSleep();
        void GetHeal();
};


Pet::Pet(void)  // Random stats using Mersenne Twist.
{
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_int_distribution<int> distribution(25,75);

    hunger = distribution(device);

    thirst = distribution(device);

    smell = distribution(device);

    energy = distribution(device);

    happy = (hunger + thirst + smell) / 3;

    healthy = (energy + hunger + thirst) / 3;

    happiness = round(happy);  // Rounding so that 0.5 = 0.

    health = round(healthy);



    // Kind of intro message.
    std::cout << "Welcome to Erisaren's virtual pet game!\n";
    sleep_for(1s);
    std::cout << "Let's head to the pet creation process!\n";
    sleep_for(1s);

    std::cout << "\n";
    std::cout << "Please enter your name: \n";
    string ida{};
    std::getline(std::cin, ida);
    if (!ida.empty())
    {
        ida[0] = std::toupper(ida[0]);
        for (std::size_t i = 1; i < ida.length(); ++i)
            ida[i] = std::tolower(ida[i]);
    }  // Capitalise name.
    std::cout << "Are you okay with " << ida << "?\nPress \"Y\" for yes or \"N\" for no.";
    string answer{};
    std::getline(std::cin, answer);
    while (true)
    {
        if (answer == "Y" || answer == "y")
        {
            SetOwner(ida);
            break;
        }

        else
        {
            std::cout << "Please enter your name: \n";
            string nida{};
            std::getline(std::cin, nida);
            if (!nida.empty())
            {
                nida[0] = std::toupper(nida[0]);
                for (std::size_t i = 1; i < nida.length(); ++i)
                    nida[i] = std::tolower(nida[i]);
            }
            ida = nida;
            std::cout << "Are you okay with " << ida << "?\nPress \"Y\" for yes or \"N\" for no.";
            string nanswer{};
            std::getline(std::cin, nanswer);
            answer = nanswer;
        }
    }
    SetOwner(ida);
    sleep_for(1s);

    std::cout << "\n";
    std::cout << "Please enter your pet's name: \n";
    string idn{};
    std::getline(std::cin, idn);
    if (!idn.empty())
    {
        idn[0] = std::toupper(idn[0]);
        for (std::size_t i = 1; i < idn.length(); ++i)
            idn[i] = std::tolower(idn[i]);
    }  // Capitalise name.
    std::cout << "Are you okay with " << idn << "?\nPress \"Y\" for yes or \"N\" for no.";
    string answer1{};
    std::getline(std::cin, answer1);
    while (true)
    {
        if (answer1 == "Y" || answer1 == "y")
        {
            SetName(idn);
            break;
        }

        else
        {
            std::cout << "Please enter your pet's name: \n";
            string nidn{};
            std::getline(std::cin, nidn);
            if (!nidn.empty())
            {
                nidn[0] = std::toupper(nidn[0]);
                for (std::size_t i = 1; i < nidn.length(); ++i)
                    nidn[i] = std::tolower(nidn[i]);
            }
            idn = nidn;
            std::cout << "Are you okay with " << idn << "?\nPress \"Y\" for yes or \"N\" for no.";
            string nanswer1{};
            std::getline(std::cin, nanswer1);
            answer1 = nanswer1;
        }
    }
    SetName(idn);
    sleep_for(1s);

    std::cout << "\n";
    std::cout << "Please enter your pet's gender?\nPress \"M\" for male or \"F\" for female: \n";
    string idg{};
    std::getline(std::cin, idg);
    while (true)
    {
        if (idg == "M" || idg == "m")
        {
            idg = "male";
            break;
        }

        else if (idg == "F" || idg == "f")
        {
            idg = "female";
            break;
        }

        else
        {
            std::cout << "Please enter your pet's gender: \n";
            string nidg{};
            std::getline(std::cin, nidg);
            idg = nidg;
            while (true)
            {
                if (idg == "M" || idg == "m")
                {
                    idg = "male";
                    break;
                }

                else if (idg == "F" || idg == "f")
                {
                    idg = "female";
                    break;
                }
            }
        }
    }

    std::cout << "Are you okay with " << idg << "?\nPress \"Y\" for yes or \"N\" for no.";
    string answer2{};
    std::getline(std::cin, answer2);
    while (true)
    {
        if (answer2 == "Y" || answer2 == "y")
        {
            SetGender(idg);
            if (idg == "M" || idg == "m")
            {
                idg = "male";
            }

            else if (idg == "F" || idg == "f")
            {
                idg = "female";
            }
            break;
        }

        else
        {
            std::cout << "Please enter your pet's gender?\nPress \"M\" for male or \"F\" for female: \n";
            string nidg{};
            std::getline(std::cin, nidg);
            idg = nidg;
            while (true)
            {
                if (idg == "M" || idg == "m")
                {
                    idg = "male";
                    break;
                }

                else if (idg == "F" || idg == "f")
                {
                    idg = "female";
                    break;
                }
            }

            std::cout << "Are you okay with " << idg << "?\nPress \"Y\" for yes or \"N\" for no.";
            string nanswer2{};
            std::getline(std::cin, nanswer2);
            answer2 = nanswer2;
        }
    }

    SetGender(idg);
    sleep_for(1s);

    std::cout << "\n";
    std::cout << "Dear " << GetOwner() << ", you have created " << GetName() << ".\n";
    std::cout << "It is a " << GetAge() << " day(s) old " << GetGender() << " pet! \n";
    std::cout << "Please take a good care of it.\n";
    std::cout << "\n";
    sleep_for(3s);

    std::cout << "\n";
    std::cout << "["<< GetName() << "]: Greetings " << GetOwner() << ".\n";
    std::cout << "I am happy to see you!\n";
    std::cout << "I am excited to live so many adventures with you!\n";
    sleep_for(3s);

}

// Setters and getters for ID.
void Pet::Pet::SetOwner(string owner_name)
{
    owner = owner_name;
}
string Pet::Pet::GetOwner(void)
{
    return owner;
}

void Pet::Pet::SetName(string pet_name)
{
    name = pet_name;
}
string Pet::Pet::GetName(void)
{
    return name;
}

void Pet::Pet::SetGender(string pet_gender)
{
    gender = pet_gender;
}
string Pet::Pet::GetGender(void)
{
    return gender;
}

void Pet::Pet::SetAge(int pet_age)
{
    age = pet_age;
}
int Pet::Pet::GetAge(void)
{
    return age;
}

// Functions.
void Pet::Pet::GetIntro()
{
    std::cout << "\n";
    std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    std::cout << " I can eat, drink, shower\n";
    std::cout << " sleep...\n";
    std::cout << " if you enter each of the \n";
    std::cout << " following commands:      \n";
    std::cout << "_-_-_-_-_-_-_-_-_-_-_-_-_\n";
    sleep_for(1s);
    std::cout << "\n";
}

void Pet::Pet::GetCare()
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
            std::cout << " |\"Z\" for [sleep]   \"X\" for [heal] |\n";
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

            else if (prompt == "X" || prompt == "x")
            {
                GetHeal();
            }

            else if (prompt == "H" || prompt == "h")
            {
                GetStatus();
            }


        } while ((prompt != "Q" || prompt != "q") && (prompt == "F" || prompt == "f" || prompt == "D" || prompt == "d" || prompt == "C" || prompt == "c" || prompt == "B" || prompt == "b" || prompt == "Z" || prompt == "z" || prompt == "P" || prompt == "p" || prompt == "X" || prompt == "x" || prompt == "H" || prompt == "h"));

        if (prompt == "Q" || prompt == "q")
        {
            GetEnd();
        }

        std::cout << "Press \"E\" to exit...\n";
        std::getline(std::cin, answer);
    } while (prompt == "E" || prompt == "e");
}

void Pet::Pet::GetEnd()
{
    std::cout << R"(
        #-_-_-_-_-_-_-_-_-_-_-_-_-_#
        # Bye!!! See you next time!#
        #-_-_-_-_-_-_-_-_-_-_-_-_-_#)";
        std::cout << "\n";
        sleep_for(2s);
}

void Pet::Pet::GetStats()
{
    std::cout << "\n";
    std::cout << "###################\n";
    std::cout << "#  Satiety: " << hunger << "    #\n";
    std::cout << "#  Quench: " << thirst << "     #\n";
    std::cout << "#  Hygiene: " << smell << "    #\n";
    std::cout << "#  Energy: " << energy << "     #\n";
    std::cout << "#  Poop: " << poop << "        #\n";
    std::cout << "#  Happiness: " << happiness << "  #\n";
    std::cout << "#  Health: " << health << "     #\n";
    std::cout << "###################\n";
}

void Pet::Pet::GetStatus()
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

// Playing Setters and Getters again.
inline int Pet::Pet::GetHunger(void)
{
    return hunger;
}
void Pet::Pet::GetFeed()
{
    std::cout << "You feed your pet.\n";
    hunger += 15;
    poop += 5;
    if (hunger > 100 && poop > 100)
    {
        hunger = 100;
        poop = 100;
    }

    else if (poop > 100)
    {
        poop = 100;
    }

    else if (hunger > 100)
    {
        hunger = 100;
    }
}

inline int Pet::Pet::GetThirst(void)
{
    return thirst;
}
void Pet::Pet::GetDrink()
{
    std::cout << "You give water to your pet.\n";
    thirst += 15;
    poop += 2;
    if (thirst > 100 && poop > 100)
    {
        thirst = 100;
        poop = 100;
    }

    else if (poop > 100)
    {
        poop = 100;
    }

    else if (thirst > 100)
    {
        thirst = 100;
    }
}

inline int Pet::Pet::GetSmell(void)
{
    return smell;
}
void Pet::Pet::GetClean()
{
    std::cout << "You clean up your pet.\n";
    smell += 45;
    poop -= 15;
    if (smell > 100 && poop < 0)
    {
        smell = 100;
        poop = 0;
    }
    else if (poop < 0)
    {
        poop = 0;
    }
    else if (smell > 100)
    {
        smell = 100;
    }
}
void Pet::Pet::GetBath()
{
    std::cout << "You bath your pet.\n";
    smell = 100;
    poop = 0;
}

inline int Pet::Pet::GetEnergy(void)
{
    return energy;
}
void Pet::Pet::GetSleep()
{
    std::cout << "You tuck your pet.\n";
    while (true)
    {
        if (energy >= 0 && energy < 100)
        {
            std::cout << "You pet is sleeping.\n";
            energy += 25;
            sleep_for(1s);
            if (energy > 100)
            {
                energy = 100;
            }
        }

        else if (energy == 100)
        {
            std::cout << "Your pet is feeling energetic!\n";
            break;
        }
    }


}

inline int Pet::Pet::GetPoop(void)
{
    return poop;
}

inline int Pet::Pet::GetHappiness(void)
{
    return happiness;
}

inline int Pet::Pet::GetHealth(void)
{
    return health;
}
void Pet::Pet::GetHeal()
{
    if (health < 100)
        {
            std::cout << "You heal up your pet.\n";
            health += 30;
            if (health >= 100)
            {
            health = 100;
            }

            else if (health == 100)
            {
                std::cout << "Your pet is not sick.\n";
            }
        }
}

//  Remote of all of the above.
int main()
{
    Pet cutie;  // Instantiation.

    cutie.GetIntro();
    cutie.GetCare();

    return 0;
}
