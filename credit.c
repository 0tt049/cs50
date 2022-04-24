#include <cs50.h>
#include <math.h>
#include <stdio.h>

void checksum(long);
void which_card(long);
void firstCheck(long);

int main(void)
{
    long user_number = get_long("Number: \n");
    firstCheck(user_number);
}

void checksum(long card_number)
{
    long y = 0;
    long z = 0;
    int odd_digit = 0;
    int even_digit = 0;
    for (int i = 15; i >= 0; i--)
    {
        long x = (card_number / pow(10, i));
        z = x - y;
        y = x * 10;
        if (i % 2 != 0)
        {
            if (z >= 5)
            {
                odd_digit = (((z * 2) % 10) + 1) + odd_digit;
            }
            else
            {
                odd_digit = (z * 2) + odd_digit;
            }
        }
        else if (i % 2 == 0)
        {
            even_digit = z + even_digit;
        }
    }
    int sum = even_digit + odd_digit;
    bool is_valid = false;
    if (sum % 10 == 0)
    {
        which_card(card_number);
    }
    else
    {
        printf("INVALID\n");
    }
}

void which_card(long card_number)
{
    for (int i = 15; i >= 0; i--)
    {
        long x = (card_number / pow(10, i));
        if ((i == 15 || i == 12) && (x == 4))
        {
            printf("VISA\n");
        }
        else if ((i == 13) && (x == 34 || x == 37))
        {
            printf("AMEX\n");
        }
        else if ((i == 14) && (x > 50 && x < 56))
        {
            printf("MASTERCARD\n");
        }
    }
}

void firstCheck(long cardnumber)
{
    if ((cardnumber >= (56 * (pow(10, 14)))) || cardnumber < (4 * (pow(10, 12))))
    {
        printf("INVALID\n");
    }
    else if (35 * (pow(10, 13)) <= cardnumber < (37 * (pow(10, 13))))
    {
        printf("INVALID\n");
    }
    else
    {
        checksum(cardnumber);
    }
}