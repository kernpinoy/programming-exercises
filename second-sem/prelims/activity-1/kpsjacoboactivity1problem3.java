import java.util.Scanner;

public class kpsjacoboactivity1problem3 
{
    public static void main(String[] args)
    {
        int num_input = 0, sum = 0;
        Scanner input = new Scanner(System.in);

        for (int i = 0; i < 5; i++)
        {   
            System.out.printf("Number #%d: ", i + 1);
            num_input = input.nextInt();
            sum += num_input;
        }
        input.close();

        System.out.printf("\nAverage: %d\n", sum / 5);
    }
}
