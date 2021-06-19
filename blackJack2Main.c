#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

bool CheckBust(int cardSum, int dealerSum)
{
    if (cardSum > 21)
    {
        printf("Your card total is %d: ... bust (returning to terminal).\n", cardSum);
        printf("Dealer Total: %D", dealerSum);
        return true;
    }
    else 
    {
        return false;
    }
}

bool Check21(int cardSum, int dealerSum)
{
    if (cardSum == 21)
    {
        printf("You've won. Your card total is 21...\n");
        printf("Dealer Total: %d", dealerSum);
        return true;
    }
    else
    {
        return false;
    }
}


int main (void)
{
    srand(time(NULL));
    int cardSum = 0, dealerSum = 0;
    char userChar = 'h';
    bool isBust = false, isTwentyOne = false;
    for (int i = 0; i < 3; i++)
    {
        dealerSum = dealerSum + rand() % (10 + 1 - 1) + 1;
    }


    while (userChar == 'h')
    {
        cardSum = cardSum + rand() % (10 + 1 - 1) + 1;
        //generating a random number between a certain n number
        //rand() % (max_number + 1 - minimum_number) + minimum_number

        //check for bust
        // if (cardSum > 21)
        // {
        //     printf("Your card total is %d: ... bust (returning to terminal).\n");
        //     break;
        // }
        isBust = CheckBust(cardSum, dealerSum);
        if (isBust == true)
        {
            return 0;
        }

        isTwentyOne = Check21(cardSum, dealerSum);
        if (isTwentyOne == true)
        {
            return 0;
        }

        printf("Your card total is: %d (h - hit, s - stay)", cardSum);
        scanf(" %c", &userChar);
    }

    if (cardSum > dealerSum)
    {
        printf("You've won and you've beat the dealers hand with a card total of %d!\n", cardSum);
        printf("Player's hand: %d\n", cardSum);
        printf("Dealer's hand: %d\n", dealerSum);
    }

    else if (cardSum < dealerSum)
    {
        if (dealerSum <= 21)
        {
            printf("You've lost, the dealers hand was closer to 21\n");
            printf("Player's hand: %d\n", cardSum);
            printf("Dealer's hand: %d\n", dealerSum);
        }
        else
        {
            printf("You've won!\n");
            printf("Player's hand: %d\n", cardSum);
            printf("Dealer's hand: %d\n", dealerSum);
        }
    }

    else if (cardSum == dealerSum)
    {
        printf("Tie Game... no one has won..\n");
        printf("Player's hand: %d\n", cardSum);
        printf("Dealer's hand: %d\n", dealerSum);
    }

    else if (cardSum > dealerSum)
    {
        printf("You've won!\n");
        printf("Player's hand: %d\n", cardSum);
        printf("Dealer's hand: %d\n", dealerSum);
    }
    return 0;
}