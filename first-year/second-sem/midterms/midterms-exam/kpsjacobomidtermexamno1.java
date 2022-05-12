import java.util.Locale;
import java.util.Scanner;
import java.text.NumberFormat;

class Bank
{   
    // details
    private double balance;
    private double interestRate;

    // take the balance
    public void setBalance(double newBalance)
    {
        this.balance = newBalance;
    }

    // take the interest rate (as a decimal)
    public void setInterestRate(double newRate)
    {
        this.interestRate = newRate;
    }

    // computes the daily compounded
    private double computeDailyCompounded()
    {
        double newBalance = this.balance;

        // Divide the interest rate by  365 for daily interest rate

        for (int i = 0; i < 3650; ++i)
        {
            newBalance += (interestRate / 365.0) * (newBalance / 100.0);
        }

        return newBalance;
    }

    // computes the monthly compounded
    private double computeMonthlyCompounded()
    {
        double newBalance = this.balance;

        // divide the interest rate by 12 for a monthly

        for (int i = 0; i < 120; ++i)
        {
            newBalance += (interestRate / 12.0) * (newBalance / 100.0);
        }

        return newBalance;
    }

    // computes the annual compounded
    private double computeAnnualCompounded()
    {
        double newBalance = this.balance;

        // divide bt 100 since interest rate is a percentage

        for (int i = 0; i < 10; ++i)
        {
            newBalance += (this.interestRate / 100) * (newBalance);
        }

        return newBalance;
    }

    // return the balance
    public double getBalance()
    {
        return this.balance;
    }

    // return the interest rate
    public double getInterestRate()
    {
        return this.interestRate;
    }

    // returns the daily compounded
    public double getDailyCompounded()
    {
        return computeDailyCompounded();
    }

    // returns the monthly compounded
    public double getMonthlyCompounded()
    {
        return computeMonthlyCompounded();
    }

    // returns the annual compounded
    public double getAnnualCompounded()
    {
        return computeAnnualCompounded();
    }
}

public class kpsjacobomidtermexamno1 
{   
    // will be used for taking user input
    static Scanner stdin = new Scanner(System.in);

    // will be used for formatting currency
    static NumberFormat currency = NumberFormat.getCurrencyInstance(Locale.US);

    // checks if a string is parsable
    static boolean isNumeric(String input)
    {
        try 
        {   
            Double.parseDouble(input);
            return true;
        } 
        catch (NumberFormatException e) 
        {
            return false;
        }
    }

    // prompts the user for an input
    static double inputPrompt(final String textPrompt)
    {   
        while (true)
        {
            // print the prompt
            System.out.print(textPrompt);
            String tempVal = stdin.nextLine(); // Ask the user for input

            // if string is null, try again
            if (tempVal == null)
            {
                continue;
            }

            // if string is not numeric, try again
            if (!isNumeric(tempVal))
            {
                continue;
            }

            // if double is less than or equal to zero, try again
            double value = Double.parseDouble(tempVal);

            if (value <= 0.0)
            {
                continue;
            }

            return value;
        }
    }

    // print out the results 
    static void printResults(Bank banks)
    {
        System.out.printf("%nResults (compounded in 10 years)%n%n");
        System.out.printf("Annual: %s%n", currency.format(banks.getAnnualCompounded()));
        System.out.printf("Monthly: %s%n", currency.format(banks.getMonthlyCompounded()));
        System.out.printf("Daily: %s%n%n", currency.format(banks.getDailyCompounded()));
    }

    // prompts the user if wants to try again                                                                                                               
    static String tryAgainPrompt()
    {   
        // print the prompt
        System.out.printf("Try again? (Y/N)? ");
        return stdin.nextLine(); // return the answer
    }
    public static void main(String[] args)
    {
        // encapsulating the data because, why not?
        Bank bdo = new Bank();

        String choice = "";

        do
        {   
            // Ask the user for the balance
            bdo.setBalance(inputPrompt("Enter balance: $"));

            // ask the user for the interest rare
            bdo.setInterestRate(inputPrompt("Enter interest rate: "));

            // Print out the result
            printResults(bdo);

            // ask the user to try again
            choice = tryAgainPrompt();
        }
        while (choice.equalsIgnoreCase("y"));

        // App closure
        stdin.close();
        System.exit(0);
    }
}