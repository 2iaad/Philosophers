#ifndef BANK_H
#define  BANK_H

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int		readd();
void	writee(int money_to_deposite);
void	*deposite(void *money);

#endif