import java.util.Scanner;

public class kpsjacobomidtermactivity2SpendingSpree 
{   
    /* global variables */

    public static final double MAX_PURCHASING_POWER = 100.00;
    public static final int MAX_ITEM = 3;

    public static void main(String[] args) 
    {   
        Scanner stdin = new Scanner(System.in);

        boolean haveMoney = true;
        double moneyLeft = MAX_PURCHASING_POWER, totalSpent = 0;

        for (int i = 0; haveMoney && (i < MAX_ITEM);)
        {   
            // print status
            System.out.printf("Money left: $%.2f | Tries: %d\n"
            , moneyLeft, (MAX_ITEM - i));

            // ask user for the price 
            System.out.printf("Enter price: $");
            double itemPrice = Double.parseDouble(stdin.nextLine().replace(" ", ""));

            // check if we have enough money
            if (itemPrice <= moneyLeft) 
            {
                System.out.printf("Transaction succeeded.");

                moneyLeft -= itemPrice;
                totalSpent += itemPrice;

                // check if we still have money after the transaction
                if (moneyLeft > 0) 
                {
                    ++i;
                    System.out.printf("\n\n");
                }
                else
                {   
                    System.out.printf("\nYou're out of money.\n\n");
                    haveMoney = false;
                }
            }
            else // will execute if itemPrice is greater than the money left
            {   
                System.out.printf("You can't buy that item.\n\n");
            }
        }

        System.out.printf("You spent $%.2f. Thanks for shopping!\n", totalSpent);

        // Exit the app
        stdin.close();
        System.exit(0);
    }
}