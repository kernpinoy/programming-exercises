import java.text.NumberFormat;
import java.util.Locale;
import javax.swing.JOptionPane;

public class mortgage 
{   
    // initialize global variable
    public static final double annualInterestRate = 0.0749;
    public static void main(String[] args) 
    {   
        // create object for currency instance
        NumberFormat currency = NumberFormat.getCurrencyInstance(new Locale("en", "ph"));
        
        // outs a welcome message
        JOptionPane.showMessageDialog(null, "Welcome to the mortgage calculator!");

        // ask user for input (balance)
        String balString = JOptionPane.showInputDialog(null, "Enter outstanding balance");
        double balance = Double.parseDouble(balString);
        
        // ask user for input (mortgage)
        String mortgageString = JOptionPane.showInputDialog(null, "Enter monthly mortgage payment");
        double mortgage = Double.parseDouble(mortgageString);

        // compute for monthly interest and principle
        double monthlyInterest = (balance *annualInterestRate) / 12;
        double monthlyPrinciple = mortgage - monthlyInterest;
        
        // output results
        String txtOutput = ("Payment Amount: " + currency.format(mortgage) + "\n");
        txtOutput += ("Monthly Interest: " + currency.format(monthlyInterest) + "\n");
        txtOutput += ("Principle Amount: " + currency.format(monthlyPrinciple) + "\n");
       
        JOptionPane.showMessageDialog(null, txtOutput);
        
        System.exit(0);
    }
}
