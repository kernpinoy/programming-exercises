import javax.swing.JOptionPane;
import java.lang.Math;

public class kpsjacoboprelimexamlecture
{
    public static void main(String[] args)
    {   
        // BarCalorie is constant since it doesn't need to be changed
        final int BarCalorie = 230;
        double bmr = 0;


        // ask for name and sex
        String name =  JOptionPane.showInputDialog(null, "Enter name");
        String sex  = JOptionPane.showInputDialog(null, "Enter sex (Male / Female)");
        
        // ask user for height, weight and age
        String heightStr = JOptionPane.showInputDialog(null, "Enter height (in inches)");
        String weightStr = JOptionPane.showInputDialog(null, "Enter weight (in pounds)");
        String ageStr = JOptionPane.showInputDialog(null, "Enter age (in years)");
        double height = Double.parseDouble(heightStr);
        double weight = Double.parseDouble(weightStr);
        int age = Integer.parseInt(ageStr);

        // check for sex then compute
        if (sex.compareTo("Female") == 0)
            bmr = 665 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
        else if (sex.compareTo("Male") == 0)
            bmr = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
        else 
        {
            JOptionPane.showMessageDialog(null, "Male and Female are case-sensitive. Try again.");
            System.exit(1);
        }

        // compute how many chocolate bars are needed
        double numOfBars = bmr / BarCalorie;

        String out = String.format("Name: %s\nSex: %s\nHeight: %.2f\nWeight: %.2f\nAge: %d\nBMR: %.2f\nChocolate bars needed: %d"
        , name, sex, height, weight, age, bmr, (int)Math.round(numOfBars));

        JOptionPane.showMessageDialog(null, out);

        System.exit(0);
    }
}   