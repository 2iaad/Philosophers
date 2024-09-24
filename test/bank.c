#include "bank.h"

int balance = 0;

int readd()
{
	usleep(250000);
	return (balance);
}

void	writee(int money_to_deposite)
{
	usleep(250000);
	balance = money_to_deposite;
}

