import java.util.Scanner;

public class kpsjacoboactivityno2A
{
    public static final double annualInterestRate = 0.079;

    public static void main(String[] args)
    {   
        Scanner stdin = new Scanner(System.in);
        
        System.out.print("Outstanding balance: $");
        double outstandingBal = Double.parseDouble(stdin.nextLine());
        
        System.out.print("Monthly mortgage payment: $");
        double mortgagePayment = Double.parseDouble(stdin.nextLine());

        double monthlyInterest = ((outstandingBal * annualInterestRate) / 12);
        double monthlyPrinciple = mortgagePayment - monthlyInterest;

        System.out.printf("\nPayable amount for this month\n");
        System.out.printf("Monthly Principle: $%.2f\n", monthlyPrinciple);
        System.out.printf("Monthly Interest: $%.2f\n", monthlyInterest);
        System.out.printf("Payment amount: $%.2f\n", mortgagePayment);

        stdin.close();
    }
}