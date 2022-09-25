#include "card.h"
#include <stdio.h>

ST_cardData_t  cust_1 ;

//implementing getCardHolderName function
EN_cardError_t getCardHolderName(ST_cardData_t *cardData){
    cardData = & cust_1 ;
    int i;
    do{
             i =0 ;
    puts("Please enter your name");
    gets(cardData->cardHolderName);
    while((cardData->cardHolderName)[i]!= '\0'){
        i++ ;
    }

    }
    while (i<20 || i>24 || i == 0 );
    printf("ok");
    return OK;
    }


//implementing getCardExpiryDate function
EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData){
    cardData = &cust_1;
    char flag,chk;
    int i,j;
    do{
             i =0 ;
             flag=0;
             chk=0;
    puts("Please enter your card expiry date in MM/YY format");
    gets(cardData->cardExpirationDate);
    while((cardData->cardExpirationDate)[i]!= '\0'){
        i++ ;
    }
    for(j=i-1;j>=0;j--){
   if (j !=2){
        if ((((cardData->cardExpirationDate)[j])>='0') && (((cardData->cardExpirationDate)[j])<= '9' )){
                flag++;
               continue;
        }
       /* else {
                printf("wrong format\n");}*/
    }
        else if(j==2) {
                if ((cardData->cardExpirationDate)[j] == '/'){
                        flag++;
                    continue;
                }

        /*else {
                printf("wrong symbol\n");
            }*/
        }

    }
    if(flag ==5){
            chk=1;

    }
    }
    while (i!=5 || (chk==0)  );


    printf("Valid format");
    return OK;
}

//implementing getCardPAN function
EN_cardError_t getCardPAN(ST_cardData_t *cardData){

cardData = & cust_1 ;
    int i;
    do{
             i =0 ;
    puts("Please enter your card's pan.");
    gets(cardData->cardHolderName);
    while((cardData->cardHolderName)[i]!= '\0'){
        i++ ;
    }

    }
    while (i<16 || i>19 || i==0);
    printf("ok");
    return OK;
    }

