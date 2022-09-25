
#include <stdio.h>
#include "../Terminal module/Terminal.h"
#include "../CardModule/card.h"

ST_terminalData_t term;
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){
    termData = &term;
    char flag,chk;
    int i,j;
    do{
             i =0 ;
             flag=0;
             chk=0;
    puts("Please enter the transaction date in DD/MM/YYYY format");
    gets(termData->transactionDate);
    while((termData->transactionDate)[i]!= '\0'){
        i++ ;
    }
    for(j=i-1;j>=0;j--){
   if (j !=2 && j!=5){
        if ((((termData->transactionDate)[j])>='0' )&& (((termData->transactionDate)[j])<= '9') ){
                flag++;
               continue;
        }
        //else {
          //      printf("wrong format\n");}
    }
        else if(j==2 || j==5) {
                if (((termData->transactionDate)[j]) == '/'){
                        flag++;
                    continue;
                }

     //   else {printf("wrong xxxxxx\n");}
        }

    }

    if(flag ==10){
            chk=1;

    }
}
    while (i!=10 || (chk==0)  );


    printf("Valid format");
    return OK;

}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData){
  //  printf("carddd%s",term)
  short card_m = (cardData.cardExpirationDate[0] ) * 10 + cardData.cardExpirationDate[1];
	short card_y = (cardData.cardExpirationDate[3] ) * 10 + cardData.cardExpirationDate[4] ;
	short transaction_m = (termData.transactionDate[3]) * 10 + termData.transactionDate[4] ;
	short transaction_y =  (termData.transactionDate[8] ) * 10+ +termData.transactionDate[9];
	if (transaction_y > card_y) {
            printf("TRANS YEAR kbera");
		return EXPIRED_CARD;
	}
	if (transaction_y == card_y && transaction_m > card_m) {
	    printf("TRANS month kbera");
		return EXPIRED_CARD;
	}
	else{
            printf("Card is up to date");
            return Ok;
    }
/*
if((cardData.cardExpirationDate[3])>(termData.transactionDate[8])){
            //printf("sana TM nkhosh ala elshahr");
           printf("Bassant year first tmam");
                    return Ok;
            }

     else if((cardData.cardExpirationDate[3])==(termData.transactionDate[8])){
            if((cardData.cardExpirationDate[4])>(termData.transactionDate[9])){

                printf("Bassant year second");
                return Ok;
            }
            else if ((cardData.cardExpirationDate[4])==(termData.transactionDate[9])){
                    if((cardData.cardExpirationDate[0])>(termData.transactionDate[3])){

                          printf("Loay first month");
                    return Ok;
                    }

                     else if((cardData.cardExpirationDate[0])==(termData.transactionDate[3])){
                         if((cardData.cardExpirationDate[1])>(termData.transactionDate[4])){
                            printf("loay 2nd month");
                            return Ok ;
                         }
                         else{
                            printf("ALI BAYZZ");
                            return EXPIRED_CARD;
                         }
                     }
            }
            else{
                printf("ALIII  BAYZ AWII");
            }



     }
            else {


            printf("\nAli");
    return EXPIRED_CARD;}
*/
}
/*{
	short card_m = (cardData.cardExpirationDate[0] - '0') * 10 + cardData.cardExpirationDate[1]-'0';
	short card_y = (cardData.cardExpirationDate[3] - '0') * 10 + cardData.cardExpirationDate[4] - '0'+2000;
	short transaction_m = (termData.transactionDate[3] - '0') * 10 + termData.transactionDate[4] - '0';
	short transaction_y = (termData.transactionDate[6] - '0') * 1000 + (termData.transactionDate[7] - '0') * 100 + (termData.transactionDate[8] - '0') * 10+ +termData.transactionDate[9] - '0';
	if (transaction_y > card_y) {
		return EXPIRED_CARD;
	}
	if (transaction_y == card_y && transaction_m > card_m) {
		return EXPIRED_CARD;
	}
	else{
            printf("Card is up to date");
            return Ok;
    }
}*/


EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData){
 termData = &term ;

    do{
    puts("Please enter the transaction amount");
    scanf("%f",&(termData->transAmount));
    }
    while ((termData->transAmount)<=0);

    return Ok;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData){
termData = &term ;
(termData->maxTransAmount)= 40000;
//printf("%f\n",(termData->maxTransAmount));
if ((termData->maxTransAmount)<=0){
    return INVALID_MAX_AMOUNT;
}
else{ return Ok;}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData){
    if((termData->maxTransAmount)>=(termData->transAmount)){
        return Ok ;
    }
else{
        printf("You exceeded the max. amount\n %d",EXCEED_MAX_AMOUNT);
    return EXCEED_MAX_AMOUNT ;
}
}



