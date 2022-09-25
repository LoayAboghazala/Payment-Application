#include <stdio.h>
#include "app.h"
void appStart(void){
    ST_cardData_t st;
    ST_transaction_t *transData;
    getCardHolderName(&st);
    getCardExpiryDate(&st);
   getCardPAN(&st);
ST_terminalData_t test;
getTransactionDate(&test);
isCardExpired(cust_1,test);
 setMaxAmount(&test);
 getTransactionAmount(&test);
isBelowMaxAmount(&test);
isValidAccount(&st);
isAmountAvailable(&test);
saveTransaction(transData);
recieveTransactionData(transData);

}
