import java.util.Scanner;

public class kpsjacobomidtermactivity2bugtrouble
{   
    /* global variables */

    public static final double GROWTH_RATE = 0.95;
    public static final double ONE_BUG_VOLUME = 0.002;

    public static void main(String[] args) 
    {   
        Scanner stdin = new Scanner(System.in);
        
        // ask for the house volume
        System.out.printf("Enter house volume (in cubic feet): ");
        double houseVolume = Double.parseDouble(stdin.nextLine());
        
        // ask for estimated roach population
        System.out.printf("Enter estimated roach population: ");
        double population = Double.parseDouble(stdin.nextLine().replace(" ", ""));

        // formula
        double totalBugVolume  = population * ONE_BUG_VOLUME;
        int countWeeks = 0;
        while (totalBugVolume < houseVolume) 
        {   
            population += (GROWTH_RATE * population);
            totalBugVolume = population * ONE_BUG_VOLUME;
            ++countWeeks;
        }

        // print out results
        System.out.printf("\nResults after %d weeks\n", countWeeks);
        System.out.printf("Roaches: %d\n", (int)population);
        System.out.printf("Volume filled by roaches (in cubic feet): %.2f\n", totalBugVolume);

        // Quit the app
        stdin.close();
        System.exit(0);
    }
}