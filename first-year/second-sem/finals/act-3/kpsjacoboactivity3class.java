import java.util.Scanner;

public class kpsjacoboactivity3class 
{   
    static Scanner stdin = new Scanner(System.in);

    // Members
    private double tankCapacity;
    private double tankFuelAmount;
    private double boatMaxSpeed;
    private double currentSpeed;
    private double motorEfficiency;
    private double distanceCovered;
    private double time;

    // methods

    // starts the boat
    public void start()
    {
        initSetup();
        primeBoat();
        boatRun();
    }

    // sets up the maximums of boats
    private void initSetup()
    {   
        tankCapacity = input("Enter tank's max capacity (liters): ", 1, Integer.MAX_VALUE);
        boatMaxSpeed = input("Enter boat's max speed (km/s): ", 1, Integer.MAX_VALUE);
        motorEfficiency = input("Enter motor's efficiency (250 - 700): ", 250, 700);
    }

    // priming your boat
    private void primeBoat()
    {    
        tankFuelAmount = input(String.format("Enter fuel (your fuel = %.2f): ", tankFuelAmount), 1, (int)tankCapacity);
        time = input("Enter time (1-24 hours): ", 1, 24);
        currentSpeed = input("Enter speed of boat to run (km/s): ", 1, (int)boatMaxSpeed);
    }

    // run the boat
    private void boatRun()
    {   
        // compute for the fuel and  distance covered
        double fuelLeft = (motorEfficiency * (currentSpeed * currentSpeed) * time) % tankFuelAmount;
        distanceCovered = currentSpeed * time;

        // if fuel gone
        if(fuelLeft > tankFuelAmount)
        {
            System.out.println("Fuel gone!");
        }

        System.out.printf("Speed: %.1f km/s | Gas: %.1f liters | Distance: %.1f KM %n", currentSpeed, fuelLeft, distanceCovered);
    }

    // Quality of life method

    // text prompt
    private double input(String textPrompt,int minValue, int maxValue)
    {   
        double val = 0.0;

        while(true)
        {
            System.out.print(textPrompt);
            String temp = stdin.nextLine();
            
            // check if string is convertible to double
            try
            {
                val = Double.parseDouble(temp);
            }
            catch (NumberFormatException e)
            {
                continue;
            }

            // check if the value is less(or greater) than the minimum(or maximum) value
            if(val < minValue || val > maxValue)
            {
                continue;
            }

            break;
        }

        return val;
    } 
}