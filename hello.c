#include <stdio.h>
#include <cs50.h>

int main(void) //main program
{
    string name = get_string("What is your name? "); //asks for user's name
    printf("hello, %s\n", name); //prints "hello" + user's name
}