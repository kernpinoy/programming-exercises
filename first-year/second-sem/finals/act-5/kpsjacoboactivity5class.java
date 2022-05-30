public class kpsjacoboactivity5class
{
    // Members
    private String description, subjectName;
    private int rating, maxRating = 5;

    // Setters
    public void setDescription(String description)
    {
        this.description = description;
    }

    public void setSubjectName(String subjectName)
    {
        this.subjectName = subjectName;
    }

    public void setRating(int rating)
    {
        this.rating = rating;
    }

    // Getters
    public String getDescription()
    {
        return description;
    }

    public String getSubjectName()
    {
        return subjectName;
    }

    public int getRating()
    {
        return rating;
    }

    public int getMaxRating()
    {
        return maxRating;
    }

    // Display the data 
    public void displayData()
    {
        System.out.printf("Title: %s%n", subjectName);
        System.out.printf("Description: %s%n", description);
        System.out.printf("Rating: %d out of %d%n", rating, maxRating);
    }
}
