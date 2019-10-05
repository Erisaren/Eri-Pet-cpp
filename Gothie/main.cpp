#include "Droid.h"  // Holds the ID.
#include "Vitals.h"  //Holds the vitals.

int main()
{
    Droid bot;  // Instantiate the robot's id
    Vitals ht;  // Instantiate the robot's vitals.

    ht.GetIntro();
    ht.GetCare();

    return 0;
}
