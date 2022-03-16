import javax.swing.JOptionPane;

public class average 
{
    public static void main(String[] args) 
    {
        
        int sum = 0;

        for (int i = 0; i < 5; i++)
        {
            String numString = JOptionPane.showInputDialog(null, String.format("Number %d", i + 1));
            sum += Integer.parseInt(numString);
        }

        JOptionPane.showMessageDialog(null,  String.format("Sum: %d\nAverage: %d\n", sum, sum / 5));

        System.exit(0);
    }
}
