# include "bank.h"


pthread_mutex_t locker;

void *deposite(void *money_to_deposite);

int main()
{
	int balance_2;
	pthread_t th1;
	pthread_t th2;

	pthread_mutex_init(&locker, NULL);

	balance_2 = readd();
	printf("before:%d\n", balance_2);

	int deposit1 = 200;
	int deposit2 = 100;
	
	pthread_create(&th1, NULL, deposite, (void *)&deposit1);
	pthread_create(&th2, NULL, deposite, (void *)&deposit2);


	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	pthread_mutex_destroy(&locker);
	balance_2 = readd();
	printf("after:%d\n", balance_2);
	return (*(int *)"");
}

void *deposite(void *money_to_deposite)
{
	int balance;
	
	pthread_mutex_lock(&locker);


	balance = readd();

	balance += *((int *)money_to_deposite);

	writee(balance);


	pthread_mutex_unlock(&locker);
	return NULL;
}