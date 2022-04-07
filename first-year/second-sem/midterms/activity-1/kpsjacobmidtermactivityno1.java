import java.util.Scanner;

public class kpsjacobmidtermactivityno1 
{
    public static void main(String[] argc)
    {   
        Scanner stdin =  new Scanner(System.in);

        // Take user input for month
        System.out.printf("Enter the number of the month: ");
        int month = Integer.parseInt(stdin.nextLine());

        int[] days = new int[] {28, 29, 30, 31};
        int leap = 0, not = 0;

        // if there's a case, go execute the methods inside
        switch (month) 
        {
            case 1: // January, 31
                System.out.printf("\nJanuary has %d days.\n", days[3]);
                break;

            case 2: // Febuary, 28 / 29
                leap = days[1] + days[3];
                not = days[0] + days[3];

                System.out.printf("\nIn a leap year, January to Febuary has %d day. If not, it has %d days.\n", 
                leap, not);
                break;

            case 3: // March, 31
                leap = days[1] + (days[3] * 2);
                not = days[0] + (days[3] * 2);

                System.out.printf("\nIn a leap year, January to March has %d day. If not, it has %d days.\n", 
                leap, not);
                break;

            case 4: // April, 30
                leap = days[1] + (days[3] * 2) + days[2];
                not = days[0] + (days[3] * 2)  + days[2];

                System.out.printf("\nIn a leap year, January to April has %d day. If not, it has %d days.\n", 
                leap, not);
                break;

            case 5: // May, 31
                leap = days[1] + (days[3] * 3) + days[2];
                not = days[0] + (days[3] * 3)  + days[2];

                System.out.printf("\nIn a leap year, January to May has %d day. If not, it has %d days.\n", 
                leap, not);
                break;
            
            case 6: // June, 30
                leap = days[1] + (days[3] * 3) + (days[2] * 2);
                not = days[0] + (days[3] * 3)  + (days[2] * 2);

                System.out.printf("\nIn a leap year, January to June has %d day. If not, it has %d days.\n", 
                leap, not);
                break;
            
            case 7: // July, 31
                leap = days[1] + (days[3] * 4) + (days[2] * 2);
                not = days[0] + (days[3] * 4)  + (days[2] * 2);

                System.out.printf("\nIn a leap year, January to July has %d day. If not, it has %d days.\n", 
                leap, not);
                break;
            
            case 8: // August, 31
                leap = days[1] + (days[3] * 5) + (days[2] * 2);
                not = days[0] + (days[3] * 5)  + (days[2] * 2);

                System.out.printf("\nIn a leap year, January to August has %d day. If not, it has %d days.\n", 
                leap, not);
                break;
            
            case 9: // September, 30
                leap = days[1] + (days[3] * 5) + (days[2] * 3);
                not = days[0] + (days[3] * 5)  + (days[2] * 3);

                System.out.printf("\nIn a leap year, January to September has %d day. If not, it has %d days.\n", 
                leap, not);
                break;
            
            case 10: // October, 31
                leap = days[1] + (days[3] * 6) + (days[2] * 3);
                not = days[0] + (days[3] * 6)  + (days[2] * 3);

                System.out.printf("\nIn a leap year, January to October has %d day. If not, it has %d days.\n", 
                leap, not);
                break;
            
            case 11: // November, 30
                leap = days[1] + (days[3] * 6) + (days[2] * 4);
                not = days[0] + (days[3] * 6)  + (days[2] * 4);

                System.out.printf("\nIn a leap year, January to November has %d day. If not, it has %d days.\n", 
                leap, not);
                break;
            
            case 12: // December, 31
                leap = days[1] + (days[3] * 7) + (days[2] * 4);2
                not = days[0] + (days[3] * 7)  + (days[2] * 4);

                System.out.printf("\nIn a leap year, January to December has %d day. If not, it has %d days.\n", 
                leap, not);
                break;

            default:
                System.out.printf("Invalid input. Nothing corresponds to %d.\n", month);
                break;
        }

        stdin.close();
        System.exit(0);
    }
}