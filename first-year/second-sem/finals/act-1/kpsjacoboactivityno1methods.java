public class kpsjacoboactivityno1methods 
{
    public static void main(String[] args) 
    {
        // vars
        int minVal = 0;
        int maxVal = 10;
        String textPrompt = "Enter number: ";


        /* object */
        kpsjacoboactivity1class t1 = new kpsjacoboactivity1class();

        // setting up the object
        t1.setMinVal(minVal);
        System.out.printf("t1's minVal: %d%n", t1.getMinVal());
        
        t1.setMaxVal(maxVal);
        System.out.printf("t1's maxVal: %d%n", t1.getMaxVal());

        t1.setTextPrompt(textPrompt);
        System.out.printf("t1's textPrompt: '%s'%n", t1.getTextPrompt());
        
        int number = t1.getValue();
        System.out.printf("%nt1's getValue output: %d%n", number);

        // Application exit
        t1.stdin.close();
        System.exit(0);
    }
}
