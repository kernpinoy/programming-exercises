public class kpsjacoboactivityno1methods 
{
    public static void main(String[] args) 
    {
        /* object */
        kpsjacoboactivity1class t1 = new kpsjacoboactivity1class();

        // setting up the object
        t1.setMinVal(0);
        System.out.printf("t1's minVal: %d%n", t1.getMinVal());
        
        t1.setMaxVal(10);
        System.out.printf("t1's maxVal: %d%n", t1.getMaxVal());

        t1.setTextPrompt("Enter number: ");
        System.out.printf("t1's textPrompt: '%s'%n", t1.getTextPrompt());
        
        int number = t1.getValue();
        System.out.printf("%nt1's getValue output: %d%n", number);

        // Application exit
        t1.stdin.close();
        System.exit(0);
    }
}
