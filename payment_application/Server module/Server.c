#include <stdio.h>
#include "../Terminal module/Terminal.h"
#include "../CardModule/card.h"
#include "Server.h"
#include<String.h>

ST_transaction_t Trans_arr[255]= {0};
extern ST_cardData_t cust_1;
extern ST_terminalData_t term;
char index=-5 ;
short size=0 ;
void FILL(void){
    ST_accountsDB_t account_1 = {50000,"1234567890LLLLLLLL"};
    ST_accountsDB_t account_2 = {50000,"1234567891AAAAAAAA"};
    ST_accountsDB_t account_3 = {60000,"1234567892BBBBBBBB"};
    ST_accountsDB_t account_4 = {70000,"1234567893CCCCCCCC"};
    ST_accountsDB_t account_5 = {100000,"1234567894DDDDDDDD"};
    ST_accountsDB_t account_6 = {150000,"1234567895EEEEEEEE"};
    ST_accountsDB_t account_7 = {500000,"1234567896FFFFFFFF"};
    ST_accountsDB_t account_8 = {1000000,"1234567897GGGGGGGG"};
    ST_accountsDB_t account_9 = {10000000,"1234567898HHHHHHHH"};
    ST_accountsDB_t account_10 = {10000000,"1234567899IIIIIIII"};
    Data_arr[0] = account_1;
    Data_arr[1] = account_2;
    Data_arr[2] = account_3;
    Data_arr[3] = account_4;
    Data_arr[4] = account_5;
    Data_arr[5] = account_6;
    Data_arr[6] = account_7;
    Data_arr[7] = account_8;
    Data_arr[8] = account_9;
    Data_arr[9] = account_10;

}
EN_serverError_t isValidAccount(ST_cardData_t *cardData){
    FILL();
    cardData=&cust_1;
    char flag=0;
    for (int i=9; i>=0; i--){
    if((strcmp((cardData->primaryAccountNumber),Data_arr[i].primaryAccountNumber)==0)){
        printf("Account is available\n");
        index=i;
        flag=1;
        return ok;
    }
    else {
        flag=0;
    }
     if(i==9 && flag ==0){
        printf("Account is not found!\n");
        return ACCOUNT_NOT_FOUND;
     }

    }
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData){
    termData=&term;
    if(index!=-5){
        if((termData->transAmount)<=Data_arr[index].balance){
                printf("Your transaction will proceed\n");
            return ok;
        }
        else {
            printf("Your tansaction amount is more than your balance\n");
            return LOW_BALANCE;
        }
    }

}
EN_serverError_t saveTransaction(ST_transaction_t *transData){
   // ST_cardData_t cobj = &cardinf;
    //ST_terminalData_t tobj = &terminalinfo;
    transData = Trans_arr;
    if(((isValidAccount(&cust_1))==ok) && ((isAmountAvailable(&term))==ok)){
            if(size<255){
                strcpy((transData->cardHolderData.cardHolderName),(cust_1.cardHolderName));
                strcpy((transData->cardHolderData.primaryAccountNumber),(cust_1.primaryAccountNumber));
                strcpy((transData->cardHolderData.cardExpirationDate),(cust_1.cardExpirationDate));
                strcpy((transData->terminalData.transactionDate),(term.transactionDate));
                transData->terminalData.transAmount=term.transAmount;
                transData->terminalData.maxTransAmount= term.maxTransAmount;
                transData->transactionSequenceNumber ++;
                transData->transState = APPROVED;
                //na2es datamember mahtet-hush bta3 transState
                transData ++;
                size++;
                return ok;


            }
            else{
                return SAVING_FAILED;
            }

    }
    else if (((isValidAccount(&cust_1))==ok) && ((isAmountAvailable(&term))==LOW_BALANCE)){

        if(size<255){
                strcpy((transData->cardHolderData.cardHolderName),(cust_1.cardHolderName));
                strcpy((transData->cardHolderData.primaryAccountNumber),(cust_1.primaryAccountNumber));
                strcpy((transData->cardHolderData.cardExpirationDate),(cust_1.cardExpirationDate));
                strcpy((transData->terminalData.transactionDate),(term.transactionDate));
                transData->terminalData.transAmount=term.transAmount;
                transData->terminalData.maxTransAmount= term.maxTransAmount;
                transData->transactionSequenceNumber ++;
                transData->transState = DECLINED_INSUFFECIENT_FUND;
                //na2es datamember mahtet-hush bta3 transState
                transData ++;
                size++;
                return ok;

        }
        else{
            return SAVING_FAILED;
        }
    }
    else{
        return SAVING_FAILED;
    }

}
EN_transState_t recieveTransactionData(ST_transaction_t *transData){

    if((isAmountAvailable(&term))==LOW_BALANCE){
        return DECLINED_INSUFFECIENT_FUND;
    }
     if((isValidAccount(&cust_1))==ACCOUNT_NOT_FOUND){
        return DECLINED_STOLEN_CARD;
    }
    //3yza anadi el save w adeha pointer
    if((saveTransaction(transData)==SAVING_FAILED)){
            return INTERNAL_SERVER_ERROR;
    }
    else{
        ((Data_arr[index]).balance) = ((Data_arr[index]).balance) - term.transAmount; //not sure da bs wla mafrud a3ml haga tani
        return APPROVED;
    }

}
