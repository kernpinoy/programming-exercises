public class kpsjacoboactivityno2methods 
{
    public static void main(String[] args)
    {
        // Variables
        int bulkQuantitiy = 12;
        double costPerItem = 6.50;
        double bulkDiscountPercentage = 3.0;
        int itemSold = 13;

        // Create objects
        kpsjacoboactivity2class Eggs =  new kpsjacoboactivity2class();

        // Object configuration
        Eggs.setBulkQuantity(bulkQuantitiy);
        Eggs.setCostPerItem(costPerItem);
        Eggs.setBulkDiscountPercentage(bulkDiscountPercentage);

        // Testing 
        System.out.printf("bulkQuantitiy == Eggs.getBulkQuantity(): %b%n", (bulkQuantitiy == Eggs.getBulkQuantity()));
        System.out.printf("costPerItem == Eggs.getCostPerItem(): %b%n", (costPerItem = Eggs.getCostPerItem()));
        System.out.printf("bulkDiscountPercentage == Eggs.getBulkDiscountPercentage: %b%n", (bulkDiscountPercentage == Eggs.getBulkDiscountPercentage()));
        Eggs.registerSale(itemSold);
        Eggs.displaySales();

        // App exit
        System.exit(0);
    }
}
