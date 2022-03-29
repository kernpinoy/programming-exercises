import java.util.Scanner;

public class Test 
{
        static int BinarySearch(int array[], int Search, int left, int right) 
        {
            // base case
            if (left > right)
                return -1;

            // calculate the midpoint of the array
            int mid = left + (right - left);

            if (array[mid] == Search)
                return mid;
            else if (array[mid] > Search)
                return BinarySearch(array, Search, left, mid - 1);
            else
                return BinarySearch(array, Search, mid + 1, right);
        }
    public static void main(String[] args) 
    {   
        // create object for terminal input 
        Scanner stdin = new Scanner(System.in);
        
        System.out.print("Element to find: ");
        int toSearch = Integer.parseInt(stdin.next());

        int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
        int arraySize = array.length;
        int locationInIndex = Test.BinarySearch(array, toSearch, 0, arraySize - 1);

        if (locationInIndex == -1)
            System.out.printf("Element %d is not in index.\n", toSearch);
        else
            System.out.printf("Array size: %d\nElement to be located: %d\nIndex location: %d\n", arraySize, toSearch, locationInIndex);

        stdin.close();
        System.exit(0);
    }
}