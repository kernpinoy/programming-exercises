#include<stdio.h>
#include<conio.h>

void main() {

   int cust_no, powerUsage;
   float amount;

   printf("Enter the customer number: ");
   scanf("%d", &cust_no);
   printf("Enter the power consumed: ");
   scanf("%d", &powerUsage);

   if (powerUsage >= 0 && powerUsage <= 200)
      amount = powerUsage * 1.0012;
   else if (powerUsage >=200 && powerUsage <=300)
      amount = ((powerUsage1.3183)+100);
   else if (powerUsage>= 301 && powerUsage <= 400)
      amount =  ((powerUsage1.6175)+250);
   else if (powerUsage <= 401 )
     amount = ((powerUsage * 2.1387) +400);

   printf("Amount to be paid by customer no. %d is php.:%5.2f.", cust_no, amount);

   getch();
}