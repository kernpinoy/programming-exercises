import java.util.Scanner;

public class kpsjacoboactivity1class 
{
    /* objects */
    Scanner stdin = new Scanner(System.in);

    /* members */
    private int minVal;
    private int maxVal;
    private String textPrompt;
    
    // Constructor
    public kpsjacoboactivity1class()
    {
        minVal = 0;
        maxVal = 0;
        textPrompt = "";
    }

    public kpsjacoboactivity1class(int minVal, int maxVal, String textPrompt)
    {
        this.minVal = minVal;
        this.maxVal = maxVal;
        this.textPrompt = textPrompt;
    }
    
    /* Setters */
    
    // Sets the minimum value
    public void setMinVal(int minVal)
    {
        this.minVal = minVal;
    }

    // Sets the max value
    public void setMaxVal(int maxVal)
    {
        this.maxVal = maxVal;
    }
    
    // Sets the text prompt
    public void setTextPrompt(String textPrompt)
    {
        this.textPrompt = textPrompt;
    }

    /* Getters */

    // returns the minimum value
    public int getMinVal()
    {
        return minVal;
    }

    // returns the maximum value
    public int getMaxVal()
    {
        return maxVal;
    }
  
    public String getTextPrompt()
    {
        return textPrompt;
    }

    /* Methods */

    // Displays a prompt and returns an input
    public int getValue()
    {
        int value = 0;

        while(true)
        {
            int tmp = 0;  

            System.out.printf("%s", textPrompt);
            String tmpString = stdin.nextLine();


            // check whether an input is a string or not
            try
            {
                tmp = Integer.parseInt(tmpString);
            }
            catch (NumberFormatException e)
            {
                continue;
            }
            
            // if input is less than minimum or greater than maximum, try again 
            if (tmp < minVal || tmp > maxVal)
            {
                continue;
            }

            value = tmp;
            break;
        }

        return value;
    }
}
