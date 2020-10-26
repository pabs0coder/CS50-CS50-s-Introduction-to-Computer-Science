#include <stdio.h>
#include <math.h>
#include <cs50.h>


int main(void)
{
    int change;
    do
    {
    float dollar_change = get_float("Change owed: \n");
    change = round(dollar_change * 100);
    }
    while (change <= 0);

    int quarters = change / 25;
    int dimes = (change % 25) / 10;
    int nickels = ((change % 25) % 10) / 5;
    int pennies = ((change % 25) % 10) % 5;
    
    printf("%d coins\n", quarters + dimes + nickels + pennies);


}
