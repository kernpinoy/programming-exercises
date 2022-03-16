import javax.swing.JOptionPane;

public class temp 
{
    public static void main(String[] args) 
    {
        // ask user for fahrenheit input
        String fahrenheitString = JOptionPane.showInputDialog(null, "Enter temperature (in fahrenheit)");
        double fahrenheit = Double.parseDouble(fahrenheitString);

        // convert fahrenheit to celcius
        double celcius = ((fahrenheit - 32) * 5) / 9;

        JOptionPane.showMessageDialog(null, String.format("Before: %.1f°F\nAfter: %.1f°C\n", fahrenheit, celcius));

        System.exit(0);
    }
}