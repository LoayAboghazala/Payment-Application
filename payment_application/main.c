#include <stdio.h>
#include <stdlib.h>
#include "CardModule/card.h"
#include "Terminal module/Terminal.h"
#include "Server module/Server.h"

extern ST_cardData_t cust_1;
extern ST_terminalData_t term;
int main()
{
    ST_cardData_t st;
    getCardExpiryDate(&st);
    //printf("%d",   getCardExpiryDate(&st) );
   // getCardHolderName(&st);
   //getCardPAN(&st);
ST_terminalData_t termm;
getTransactionDate(&termm);
isCardExpired(cust_1,term);
//getTransactionDate(&term);
 //setMaxAmount(&termm);
 //getTransactionAmount(&termm);

//isBelowMaxAmount(&termm);


   // printf("Hello world!\n");
    return 0;
}
