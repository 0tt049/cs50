#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for int btw 1-8 inclusive
    int userImput;
    do
    {
    userImput = get_int("Height: ");
    } while (userImput < 1 || userImput > 8);

    int steps = userImput;
    while (steps >= 1)
    {
        int i;
        for (i = 1; i < ((userImput + 1) * 2) - (steps - 1); i++)
        {
            if (i < steps)
            {
                printf(" ");
            }
            else if (i > userImput && i <= userImput + 2)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("#\n");
        steps--;
    }
}