#ifndef DROID_H
#define DROID_H

#include <iostream>
#include <thread>  // For sleep.
using namespace std::this_thread;  // sleep_for, sleep_until
using namespace std::chrono_literals;  // ns, us, ms, s, h
using std::string;


class Vitals;  // Forward declaration.
class Droid  // Object.
{
    private:  // Set once.
        string owner{};
        string name{};
        string gender{};
        string model{};
        int age{0};
    public:
        Droid(void);  // Constructor with getter and setter.
        void SetOwner(string owner_name);
        string GetOwner(void);

        void SetName(string pet_name);
        string GetName(void);

        void SetGender(string pet_gender);
        string GetGender(void);

        void SetModel(string pet_model);
        string GetModel(void);

        void SetAge(int pet_age);
        int GetAge(void);

};

Droid::Droid(void)
{
    string pp{};  // Personal pronoun.
    string Pp{};
    string pop{};  // Possessive pronoun.
    string Pop{};
    string pd{};  // Him / Her.
    string Pd{};

    std::cout << "Welcome to Gothie's virtual pet robot! You will have the opportunity to raise a robot.\n";
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
            std::cout << " Are you okay with " << ida << "?\nPress \"Y\" for yes or \"N\" for no.";
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
            std::cout << " Are you okay with " << idn << "?\nPress \"Y\" for yes or \"N\" for no.";
            string nanswer1{};
            std::getline(std::cin, nanswer1);
            answer1 = nanswer1;
        }
    }
    SetName(idn);
    sleep_for(1s);

    std::cout << "\n";
    std::cout << "Please enter your pet's gender(Choose between \"Male\" or \"Female\"): \n";
    string idg{};
    std::getline(std::cin, idg);
    while (true)
    {
        if (idg == "Male" || idg == "male")
        {
            idg = "male";
            break;
        }

        else if (idg == "Female" || idg == "female")
        {
            idg = "female";
            break;
        }

        else
        {
            std::cout << "Please enter your pet's gender(Choose between \"Male\" or \"Female\"): \n";
            string nidg{};
            std::getline(std::cin, nidg);
            idg = nidg;
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
            if (idg == "Male" || idg == "male")
        {
            idg = "male";
            pp = "he";
            Pp = "He";
            pop = "his";
            Pop = "His";
            pd = "him";
            Pd = "Him";
        }

        else if (idg == "Female" || idg == "female")
        {
            idg = "female";
            pp = "she";
            Pp = "She";
            pop = "her";
            Pop = "Her";
            pd = "her";
            Pd = "Her";
        }
            break;
        }

        else
        {
            std::cout << "Please enter your pet's gender(Choose between \"Male\" or \"Female\"): \n";
            string nidg{};
            std::getline(std::cin, nidg);
            idg = nidg;
            std::cout << "Are you okay with " << idg << "?\nPress \"Y\" for yes or \"N\" for no.";
            string nanswer2{};
            std::getline(std::cin, nanswer2);
            answer2 = nanswer2;
        }
    }

    SetGender(idg);
    sleep_for(1s);

    std::cout << "\n";
    std::cout << "Please enter your pet's model(Choose between \"electric\", \"coal\" or \"steam\"): \n";
    string idm{};
    std::getline(std::cin, idm);
    while (true)
    {
        if (idm == "Electric" || idm == "electric")
        {
            idm = "electric";
            break;
        }
        else if  (idm == "Coal" || idm == "coal")
        {
            idm = "coal";
            break;
        }
        else if (idm == "Steam" || idm == "steam")
        {
            idm = "steam";
            break;
        }
        else
        {
            std::cout << "Please enter your pet's model(Choose between \"electric\", \"coal\" or \"steam\"): \n";
            string nidm{};
            std::getline(std::cin, nidm);
            idm = nidm;
        }
    }
    std::cout << "Are you okay with " << idm << "?\nPress \"Y\" for yes or \"N\" for no.";
    string answer3{};
    std::getline(std::cin, answer3);
    while (true)
    {
        if (answer3 == "Y" || answer3 == "y")
        {
            SetModel(idm);
            break;
        }

        else
        {
            std::cout << "Please enter your pet's model(Choose between \"electric\", \"coal\" or \"steam\"): \n";
            string nidm{};
            std::getline(std::cin, nidm);
            idm = nidm;
            std::cout << "Are you okay with " << idm << "?\nPress \"Y\" for yes or \"N\" for no.";
            string nanswer3{};
            std::getline(std::cin, nanswer3);
            answer3 = nanswer3;
        }
    }


    SetModel(idm);
    sleep_for(1s);

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "#-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-#\n";
    std::cout << " Dear " << GetOwner() << ", you have created " << GetName() << ".\n";
    std::cout << " " << Pp << " is a " << GetAge() << " day(s) old " << GetGender() << " " << GetModel() << " robot! \n";
    std::cout << " Please take a good care of " << pd << "\n";
    std::cout << "#-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-#\n";
    std::cout << "\n";
    std::cout << "\n";
    sleep_for(5s);

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "#-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-#\n";
    std::cout << " ["<< GetName() << "]: Greetings " << GetOwner() << ".\n";
    std::cout << " I am happy to see you!\n";
    std::cout << " I am excited to live so many adventures with you!\n";
    std::cout << "#-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-#\n";
    std::cout << "\n";
    std::cout << "\n";
    sleep_for(5s);
}

void Droid::Droid::SetOwner(string owner_name)
{
    owner = owner_name;
}
string Droid::Droid::GetOwner(void)
{
    return owner;
}

void Droid::Droid::SetName(string pet_name)
{
    name = pet_name;
}
string Droid::Droid::GetName(void)
{
    return name;
}

void Droid::Droid::SetGender(string pet_gender)
{
    gender = pet_gender;
}
string Droid::Droid::GetGender(void)
{
    return gender;
}

void Droid::Droid::SetModel(string pet_model)
{
    model = pet_model;
}
string Droid::Droid::GetModel(void)
{
    return model;
}

void Droid::Droid::SetAge(int pet_age)
{
    age = pet_age;
}
int Droid::Droid::GetAge(void)
{
    return age;
}

#endif // DROID_H
