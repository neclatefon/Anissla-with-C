#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

void CleanBuffer(){
    int n;
    while((n = getchar()) != EOF && n != '\n' );
}

int billing()
{
    //METHOD PAYMENT
    char c;
    do {
          printf("Your order is almost ready. Please Choose a method of payment: Credit (C) or Debit (D)\n");
          scanf (" %c", &c);
          c = toupper(c); // here letter become uppercase
          CleanBuffer();
    } while( (c != 'C' && c != 'D')?printf("That is not a valid option, try again! "):0 );
    printf("You have entered: %c\n", c);

    //CVV
    int cvv;
    int countcvv;
    do {
          printf ("Please input the CVV at the back of the credit card:\n");
          scanf ("%d", &cvv);
          countcvv = (cvv == 0) ? 1 : log10 (cvv) + 1;

    } while( (countcvv != 3)?printf("That is not a valid CVV, try again! "):0 );
    printf("You have entered: %d\n", cvv);

    //MONTH
    int month;
    do {
        printf ("Please input the month of the expiry date as a digit (1-12):\n");
        scanf ("%d", &month);
    } while((month > 12 || month < 1 )?printf("That is not a valid month, try again! "):0 );
    printf("You have entered: %d\n", month);

    //YEAR
    int year;
    do {
        printf ("Please input the last two digits of the expiry date year:\n");
        scanf ("%d", &year);
    } while((year < 23 || year > 99)?printf("That is not a valid year, try again! "):0 );
    printf("You have entered: %d\n", year);

    //TIME VALIDATOR
    time_t t = time(NULL);
    struct tm date = *localtime(&t);
    int yearvalidator = (date.tm_year + 1900) % 100;
    int monthvalidator = date.tm_mon + 1;
    int dateinvalid = 0; 

    if (year > yearvalidator){
      dateinvalid = 0;
      printf("Your card was accepted!");
    }
    else if (year == yearvalidator && month < monthvalidator){
      dateinvalid = 0;
      printf("Your card was accepted!");
    }
    else{
      dateinvalid = 1;
      printf("Unfortunately, your card has expired and cannot be accepted. Please try again with another payment method");
    }

    // Check if date is invalid and exit the program if so
    if (dateinvalid) {
        return 1;
    }

    //now run order confirmation page

    return 0;
}
int confirmation()
{
    char product_name[10] = "product";
    time_t now_time;
    now_time = time(NULL);
    struct tm *current_time = localtime(&now_time);
    current_time->tm_mday += 14; 
    mktime(current_time); 
    printf("Your order is placed! Expect to see the %s at your address by %d-%02d-%02d. "
    "Feel free to contact us at anissla_support@gmail.com if you have any questions. Thanks for choosing Anissla!\n", 
    product_name, current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday);
}
