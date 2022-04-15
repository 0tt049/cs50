#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt user for int btw 1-8 inclusive
    int userImput;
    do
    {
        userImput = get_int("Height: ");
    }\n
    while (userImput < 1 || userImput > 8);

    int steps = userImput;
    while (steps >= 1) //1 loop for each step
    {
        int i;
        for (i = 1; i < ((userImput + 1) * 2) - (steps - 1); i++) //1 loop for each charecter
        {
            if (i < steps)
            {
                printf(" "); //left white spaces
            }
            else if (i > userImput && i <= userImput + 2)
            {
                printf(" "); //white spaces gutter
            }
            else //hash characters
            {
                printf("#");
            }
        }
        printf("#\n");
        steps--;
    }
}