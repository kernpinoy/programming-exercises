import java.text.NumberFormat;
import javax.swing.JOptionPane;

public class test {
    public static final double INTEREST_RATE = 0.079;

    public static void main(String[] args) {

        // Create moneyformatter
        NumberFormat moneyFormatter = NumberFormat.getCurrencyInstance();

        // Greet user
        JOptionPane.showMessageDialog(null, "Welcome to the Mortgage Payment Calculator.");

        // Get remaining loan balance
        String balanceAmountTxt = JOptionPane.showInputDialog(null, "Please enter your remaining loan balance:");
        double balanceAmount = Double.parseDouble(balanceAmountTxt);

        // Calculate monthly interest
        double monthlyInterest = ((balanceAmount * INTEREST_RATE) / 12);

        // Display monthly interest
        JOptionPane.showMessageDialog(null,
                "Your current monthly interest is: " + moneyFormatter.format(monthlyInterest));

        // Get monthly payment
        String monthlyPaymentAmountTxt = JOptionPane.showInputDialog(null,
                "Please enter the amount of your monthly mortgage payment");
        double monthlyPaymentAmount = Double.parseDouble(monthlyPaymentAmountTxt);

        // Calculate monthly principle
        double monthlyPrincipleAmount = (monthlyPaymentAmount - monthlyInterest);

        // Display monthly interest
        String txtOutput = ("Payment Amount: " + moneyFormatter.format(monthlyPaymentAmount) + "\n");
        txtOutput = txtOutput + ("Monthly Interest:" + moneyFormatter.format(monthlyInterest) + "\n");
        txtOutput = txtOutput + ("Principle Amount:" + moneyFormatter.format(monthlyPrincipleAmount) + "\n");
        JOptionPane.showMessageDialog(null, txtOutput);
    }
}