import java.util.Scanner;

public class kpsjacoboactivityno2B
{
    public static void main(String[] args)
    {   
        Scanner stdin = new Scanner(System.in);

        System.out.print("Temperature (in fahrenheit): ");
        double temp_f = Double.parseDouble(stdin.nextLine());

        double temp_c = ((temp_f - 32) * 5) / 9;

        System.out.printf("Temperature (in celcius): %.2f\n", temp_c);

        stdin.close();
    }
}