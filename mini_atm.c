#include <stdio.h>
#include <stdlib.h>

#include "main.h"

int main(void)

	/* change color of window */
{

	char accountName[30];
	long int accountNum = 85004030212;
	int pin;
	float depositeAmount;
	float accountBalance = 0;
	int choice;
	float minimumDeposite = 5;
	int continueTransaction = 1;

	FILE *fp = NULL;
	char saveSlip = 'y';
	

	printf("\n\n");

	printf("\t\t============= Py Bank. ============\n");

	printf("\tWelcome to Py Bank.\n");
	printf("\tWhat is your account name. ");
	fgets(accountName, 30, stdin);
	//getchar();
	printf("\tEnter your pin: ");
	scanf("\t%d", &pin);
	printf("\tEnter the amount to deposit. ");
	scanf("\t%f", &depositeAmount);
	printf("\t\n");
	printf("\tYou have successfully created your account.\n");

	accountBalance = accountBalance + depositeAmount;
	depositeAmount = 0;
	printf("\t\n");

	printf("\tAccount balance is %.2f\n\n", accountBalance);

	do {
	printf("\tWhat else do you what to do?\n\n");
	printf("\tEnter 1 for check balance.\n");
	printf("\tEnter 2 for deposit.\n");
	printf("\tEnter 3 for withdraw.\n");
	printf("\tEnter 4 for transfer.\n");

	scanf("\t%d", &choice);

	if (choice == 1)
	{
		system("clear");
		system("clear");
		int account1;

		printf("\tselect account:\n");
		printf("\t1. account: %ld\n", accountNum);
		scanf("%d: \t", &account1);
		
		if (account1 == 1)
		{
			printf("\t\tBalance:  %.2f\n", accountBalance);

		}
		else
		{
			printf("\tInvalid input.\n");
		}

	}
	else if (choice == 2)
	{
		system("clear");
		float tmpDepost;

		printf("\t\t\tEnter amount to deposit. \n");
		scanf("%f: \t", &depositeAmount);
		
		if (depositeAmount > 5)
		{
			accountBalance = accountBalance + depositeAmount;
			tmpDepost = depositeAmount;
			depositeAmount = 0;

			printf("\t\tNew Balance is %.2f\n\n\n", accountBalance);

			//printf("\t\t================ Py Bank. =================\n\n");
			//printf("\t\t\t\tDepost slip.\n\n");
			//printf("\t\tDate: %s  Time: %s.\n\n",  __DATE__, __TIME__);
			//printf("\t\tAccount Name: %s      \n\n",  accountName);
			//printf("\t\tAcount Number: %ld\n\n", accountNum);
			//printf("\t\t                 Depost Amount: %.2f\n", tmpDepost);
			//printf("\t\t\t\t           --------------\n");
			//printf("\t\t\t\tAccount Balance: %.2f\n\n\n", accountBalance);
			//printf("\t\t ----------Thankyou for choosing Py bank.---------\n\n");
			//tmpDepost = 0;

			depostSlipGenerator(accountName, accountNum, tmpDepost, accountBalance);
			tmpDepost = 0;

			fp = fopen("bank_statement.dat", "a+");

			if (fp == NULL)
			{
				printf("error");
				exit(1);
			}

			//fputs(&statement, fp);
			fwrite(&accountName,sizeof(accountName),1,fp);
			fwrite(&accountNum,sizeof(accountNum),1,fp);
			fwrite(&accountBalance,sizeof(accountBalance),1,fp);
			

			fclose(fp);

		}

		else if (depositeAmount < 5)
		{
			printf("\t\tMinimum deposit amount is %.2f\n", minimumDeposite);
		}

	}
	else if (choice == 3)
	{
		system("clear");
		float withdrawAmount;

		printf("\t\tEnter the amount to withraw: ");
		scanf("%f", &withdrawAmount);
		if (withdrawAmount >= accountBalance)
		{
			printf("\t\tInsuficent funds.\n");
			printf("\t\tAccount balance is %.2f.\n", accountBalance);
			printf("\t\tAvailable balanbe is %.2f\n.", accountBalance - 100);
		}
		else if (withdrawAmount <= (accountBalance - 100))
		{
			/*printf("\t\tYou have withdrown %.2f\n\n", withdrawAmount);*/
			accountBalance = accountBalance - withdrawAmount;

			printf("\t\t================ Py Bank. =================\n\n");
			printf("\t\t\t\tWithdraw slip.\n\n");
			printf("\t\tDate: %s  Time: %s.\n\n",  __DATE__, __TIME__);
			printf("\t\tAccount Name: %s      \n\n",  accountName);
			printf("\t\tAcount Number: %ld\n\n", accountNum);
			printf("\t\t                 Withdraw Amount: %.2f\n", withdrawAmount);
			printf("\t\t\t\t           --------------\n");
			printf("\t\t\t\tAccount Balance: %.2f\n\n\n", accountBalance);
			printf("\t\t ----------Thankyou for choosing Py bank.---------\n\n");
		}
	}
	else if (choice == 4)
	{
		system("clear");
		float transfarAmount;
		long int transfarAccount;

		printf("\tTransfiring money.\n");

		printf("\tEnter amount to transfar.  ");
		scanf("\t%f", &transfarAmount);
		printf("\tEnter account to transfar to. ");
		scanf("\t%ld", &transfarAccount);
		if (transfarAmount >= (accountBalance - 100))
		{
			printf("\t\tInsuficent funds.\n");
			printf("\t\tAccount balance is %.2f.\n", accountBalance);
			printf("\t\tAvailable balanbe is %.2f\n.", accountBalance - 100);

		}
		else if (transfarAmount <= (accountBalance - 100))
		{
			/*printf("\t\tYou have transfared %.2f to account number %ld.\n\n",
			  transfarAmount, transfarAccount);*/

			accountBalance = accountBalance - transfarAmount;

			printf("\t\t================ Py Bank. =================\n\n");
			printf("\t\t\t\tWithdraw slip.\n\n");
			printf("\t\tDate: %s  Time: %s.\n\n",  __DATE__, __TIME__);
			printf("\t\tAccount Name: %s      \n\n",  accountName);
			printf("\t\tFrom Acount Number: %ld\n\n", accountNum);
			printf("\t\tTo Acount Number: %ld\n\n", transfarAccount);
			printf("\t\t                 Transfar Amount: %.2f\n", transfarAmount);
			printf("\t\t\t\t           --------------\n");
			printf("\t\t\t\tAccount Balance: %.2f\n\n\n", accountBalance);
			printf("\t\t ----------Thankyou for choosing Py bank.---------\n\n");

		}

	}
	else
	{
		printf("invalid input.");

	}
	printf("\n\n\t\tDo you wish to perform another transaction?\n");
	printf("\t\tPress [1], 0[No]\n");
	scanf("%d", &continueTransaction);

	} while(continueTransaction != 0);
		return (0);
}
