import java.util.Scanner;
import java.lang.Math;

public class kpsjacobomidtermexamno2 
{   
    // computes the percent of X in Y
    static double toPercent(int x, int y)
    {   
        return ((double) x / y) * 100.0;
    }
    public static void main(String[] args) 
    {
        // create object of the Scanner class
        java.util.Scanner stdin = new Scanner(System.in);

        // variables
        int tossNum = 0, headCount = 0, tailsCount = 0;

        // if cannot be convert or zero, prompt again
        while (true) 
        {
            System.out.printf("Enter number of toss: ");
            String tossString = stdin.nextLine().replaceAll(" ", "");
            
            if (tossString.isEmpty())
            {
                continue;
            }

            tossNum = Integer.parseInt(tossString);

            if (tossNum == 0)
            {
                continue;
            }

            // exit if OK
            break;
        }
        
        // print whitespaces
        System.out.printf("%n");

        // head and tails
        for (int i = 0; i < tossNum; ++i)
        {
            if (Math.random() < 0.5)
            {
                System.out.printf("Toss #%d: Heads\n", i + 1);
                ++headCount;
            }
            else
            {
                System.out.printf("Toss #%d: Tails\n", i + 1);
                ++tailsCount;
            }
        }

        // print whitespaces
        System.out.printf("%n");

        // Print results
        System.out.printf("Results:%n");
        System.out.printf("Heads: %d%n", headCount);
        System.out.printf("Tails: %d%n", tailsCount);
        System.out.printf("Heads percentage: %.1f%%%n", toPercent(headCount, tossNum));
        System.out.printf("Tails percentage: %.1f%%%n", toPercent(tailsCount, tossNum));
        

        // close the app
        stdin.close();
        System.exit(0);
    }
}
