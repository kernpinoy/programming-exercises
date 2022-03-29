import javax.swing.JOptionPane;

public class kpsjacoboquizno2
{
    public static void main(String[] args)
    {   
        // ask for employee name
        String name = JOptionPane.showInputDialog(null, "Employee name");
        
        // ask for the year joined
        String joined = JOptionPane.showInputDialog(null, "Year joined");
        int joinedInt = Integer.parseInt(joined);
        
        // ask for the year left
        String left = JOptionPane.showInputDialog(null, "Year left");
        int leftInt = Integer.parseInt(left);
        
        // formula
        int service = leftInt - joinedInt;
        
        // output answers
        String out = String.format("Name: %s\nYear joined: %d\nYear left: %d\nYears of service: %d", name, joinedInt, leftInt, service);

        JOptionPane.showMessageDialog(null, out);

        System.exit(0);
    }
}
