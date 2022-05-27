public class kpsjacoboactivity2class 
{
    // Members
    private int numSold, bulkQuantity;
    private double totalSales, totalDiscount, costPerItem, bulkDiscountPercent;

    // Constructors
    public kpsjacoboactivity2class() // blank constructor
    {
        numSold = 0;
        bulkQuantity = 0;
        totalSales = 0;
        totalDiscount = 0;
        costPerItem = 0;
        bulkDiscountPercent = 0;
    }
  
    public kpsjacoboactivity2class(int numSold, int bulkQuantity, double totalSales, double totalDiscount, double costPerItem, double bulkDiscountPercent)
    {
        this.numSold = numSold;
        this.bulkQuantity = bulkQuantity;
        this.totalSales = totalSales;
        this.totalDiscount = totalDiscount;
        this.costPerItem = costPerItem;
        this.bulkDiscountPercent = bulkDiscountPercent;
    }

    // Setters 

    // Sets the bulk quantity
    public void setBulkQuantity(int bulkQuantity)
    {
        this.bulkQuantity = bulkQuantity;
    }

    // Sets the cost of the item
    public void setCostPerItem(double costPerItem)
    {
        this.costPerItem = costPerItem;
    }

    // Sets the bulk discount percentage
    public void setBulkDiscountPercentage(double bulkDiscountPercent)
    {
        this.bulkDiscountPercent = bulkDiscountPercent;
    }
    
    // Getters

    // returns the bulkQuantity
    public int getBulkQuantity()
    {
        return bulkQuantity;
    }
    
    // returns costPerItem
    public double getCostPerItem()
    {
        return costPerItem;
    }

    // returns bulkDiscountPercent
    public double getBulkDiscountPercentage()
    {
        return bulkDiscountPercent;
    }

    // Required methods
    
    // Records the sale of x items
    public void registerSale(int itemSold)
    {
        numSold = itemSold;

        if (itemSold > bulkQuantity)
        {
            totalDiscount += ((double)itemSold * costPerItem) * (bulkDiscountPercent / 100);
            totalSales += ((double)itemSold * costPerItem) - (totalDiscount); 
        }
        else
        {
            totalSales += (double)(itemSold * costPerItem);
        }
    }

    // prints out the number sold
    public void displaySales()
    {
        System.out.printf("Number sold: %d%n", numSold);
        System.out.printf("Total sale: $%.1f%n", totalSales);
        System.out.printf("Total discount: %.1f%%\n", totalDiscount);
    }
}
