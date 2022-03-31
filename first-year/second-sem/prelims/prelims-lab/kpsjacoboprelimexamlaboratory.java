import javax.swing.JOptionPane;

public class kpsjacoboprelimexamlaboratory
{   
    public static void main(String[] args)
    {   
        // pi constant value
        final double PI = 3.1415926535897932384626433;
        
        // variables
        double radius = 0, height = 0;

        // check if array has value or not
        if (args.length == 0) 
        {
            JOptionPane.showMessageDialog(null, "Run java kpsjacoboprelimexamlaboratory [NAME]");
            System.exit(1);
        }

        //greet user
        JOptionPane.showMessageDialog(null, String.format("Welcome, %s!", args[0]));
        
         // ask user for radius
        do
        {
            String radString = JOptionPane.showInputDialog(null, "Enter radius (in inches)");
            radius = Double.parseDouble(radString) / 12; // converts radius into feet
        }
        while (radius == 0); // repeat if radius is still 0

        // ask user for height
        do
        {
            String hString = JOptionPane.showInputDialog(null, "Enter height (in feet)");
            height = Double.parseDouble(hString);
        }
        while (height == 0); // repeat if height is still 0
        
        // formula
        double volume = PI * (radius * radius) * height;
        double gallon = volume * 7.48;

        // display the results
        String out = String.format("Name: %s\nRadius: %.2f inches\nHeight: %.2f feet\nVolume: %.2f\n\nYou need about %.2f gallons of water.\n", 
        args[0], radius * 12, height, volume, gallon);

        JOptionPane.showMessageDialog(null, out);

        System.exit(0);
    }
}