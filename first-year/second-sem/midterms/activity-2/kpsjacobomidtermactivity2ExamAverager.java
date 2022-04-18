import java.util.Scanner;

public class kpsjacobomidtermactivity2ExamAverager 
{
    public static void main(String[] args) 
    {   
        Scanner stdin = new Scanner(System.in);

        String choice;
        int instance = 0;

        do
        {   
            double sum = 0.0;
            int divisor = 0;
            
            if (instance == 0)
                System.out.printf("To exit, enter a non-positive integer.\n\n");
            else
                System.out.printf("\n");
            
            while (true) 
            {
                double grade = 0.0;

                System.out.printf("Enter a number: ");
                grade = Double.parseDouble(stdin.nextLine().replace(" ", ""));

                if (grade < 0)
                    break;

                sum += grade;
                ++divisor;
            }

            if (divisor != 0 || sum != 0)
                System.out.printf("\nAverage: %.1f\n", (sum / divisor));

            if (instance == 0)    
                System.out.printf("Try again? (yes/no/y/n/YES/NO) ");
            else
                System.out.printf("Try again? ");
                
            choice = stdin.nextLine().replace(" ", "");
            ++instance;
        }
        while (choice.compareToIgnoreCase("yes") == 0 || choice.compareToIgnoreCase("y") == 0);

        // Close the app
        stdin.close();
        System.exit(0);
    }
}