#include <stdio.h>
#include <stdlib.h>


void depostSlipGenerator(char accountName[30], long int accountNum, float tmpDepost, float accountBalance)
{

	printf("\t\t================ Py Bank. =================\n\n");
	printf("\t\t\t\tDepost slip.\n\n");
	printf("\t\tDate: %s  Time: %s.\n\n",  __DATE__, __TIME__);
	printf("\t\tAccount Name: %s      \n\n",  accountName);
	printf("\t\tAcount Number: %ld\n\n", accountNum);
	printf("\t\t                 Depost Amount: %.2f\n", tmpDepost);
	printf("\t\t\t\t           --------------\n");
	printf("\t\t\t\tAccount Balance: %.2f\n\n\n", accountBalance);
	printf("\t\t ----------Thankyou for choosing Py bank.---------\n\n");



}
