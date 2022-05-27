import java.util.Scanner;

public class kpsjacoboactivity4class 
{   
    static Scanner stdin = new Scanner(System.in);

    /* members */
    private String firstName, lastName, email, phoneNumber;

    /* Constructor */

    public kpsjacoboactivity4class()
    {

    }

    public kpsjacoboactivity4class(String fname, String lName, String mail, String number)
    {
        firstName = fname;
        lastName = lName;
        email = mail;
        phoneNumber = number;
    }

    /* setter */

    // sets the first name
    public void setFirstName(String firstName)
    {
        this.firstName = firstName;
    }

    // sets the last name
    public void setLastName(String lastName)
    {
        this.lastName = lastName;
    }

    // sets the last name
    public void setMail(String email)
    {
        this.email = email;
    }

    public void setPhoneNum(String phoneNumber)
    {
        this.phoneNumber = phoneNumber;
    }

    /* getters */

    // gets the first name
    public String getFirstName()
    {
        return firstName;
    }

    // gets the last name
    public String getLastName()
    {
        return lastName;
    }

    // gets the email
    public String getMail()
    {
        return email;
    }

    // gets the phone number
    public String gettPhoneNum()
    {
        return phoneNumber;
    }

    // checks the other object for equality
    public boolean nameEquality(Object other)
    {
        if (other instanceof kpsjacoboactivity4class)
        {
            kpsjacoboactivity4class that = (kpsjacoboactivity4class) other;

            boolean fiName = (this.firstName == null && that.firstName == null);
            boolean laName = (this.lastName == null && that.lastName == null);
            boolean fullname1 = (this.firstName.equals(that.firstName));
            boolean fullname2 = (this.lastName.equals(that.lastName));
            
            return ((fiName && laName) || (fullname1 && fullname2));
        }

        return false;
    }

    // starts the app
    public void start()
    {
        firstName = userInput("Enter first name: ", firstName);
        lastName = userInput("Enter last name: ", lastName);
        email = userInput("Enter e-mail: ", email);
        phoneNumber = userInput("Enter phone number: ", phoneNumber);
    }

    // returns the input
    private String userInput(String text, String reference)
    {   
        String temp = "";

        while(true)
        {   
            System.out.print(text);
            temp = stdin.nextLine();

            if(text == temp)
            {
                continue;
            }

            break;
        }

        return temp;
    }

    // Display details
    public void displayDetails()
    {
        System.out.printf("%nFirst name: %s%n", firstName);
        System.out.printf("Last name: %s%n", lastName);
        System.out.printf("E-mail: %s%n", email);
        System.out.printf("Phone number: %s%n", phoneNumber);
    }
}