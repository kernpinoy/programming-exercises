import javax.swing.JOptionPane;

public class kpsjacoboactivity3activity1_3 
{
    public static void main(String[] args) 
    {
        
        double sum = 0;

        for (int i = 0; i < 5; i++)
        {
            String numString = JOptionPane.showInputDialog(null, String.format("Number %d", i + 1));
            sum += Double.parseDouble(numString);
        }

        JOptionPane.showMessageDialog(null,  String.format("Sum: %.2f\nAverage: %.2f\n", sum, sum / 5));

        System.exit(0);
    }
}
