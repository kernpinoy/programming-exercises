public class kpsjacoboactivityno4methods 
{
    public static void main(String[] args) 
    {
        kpsjacoboactivity4class person1 = new kpsjacoboactivity4class();
        kpsjacoboactivity4class person2 = new kpsjacoboactivity4class("Kern", "Jacobo", "inoy@yopmail.com", "09262057206");

        // App startup
        person1.start();
        person1.displayDetails();

        // Name equality testing
        System.out.printf("%n%s == %s: %b%n", "person1", "person2", person1.nameEquality(person2));

        // Change email and phone number
        person1.setMail("kern@jacobo.com");
        person1.setPhoneNum("09262057205");
        person1.displayDetails();

        // App closure
        kpsjacoboactivity4class.stdin.close();
        System.exit(0);
    }
}