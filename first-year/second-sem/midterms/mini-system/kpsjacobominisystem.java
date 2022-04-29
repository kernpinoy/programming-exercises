import java.util.Scanner;

public class kpsjacobominisystem 
{
    // Max voters and candidate
    static final int MAX_CANDIDATE = 9;
    static final int MAX_VOTER = 100;

    // preferences[i][j] is jth preferences for voter i
    static int[][] preferences = new int[MAX_VOTER][MAX_CANDIDATE];
    static int candidateCount;
    static int voterCount;

    // Scanner object
    static Scanner stdin = new Scanner(System.in);

    // checks if the string only contains the alphabet
    static boolean isAlphabetic(String text) 
    {
        return (text.matches("[a-zA-Z]+"));
    }

    // checks whether our command line arguements are correct
    static void isCommandArgCorrect(String[] args, int[] votes, boolean[] eliminated)
    {   
        /* Check for invalid usage */
        if (args.length > MAX_CANDIDATE || args.length == 0)
        {   
            System.out.printf("Usage: java kpsjacobominisystem [candidates...]\n");
            System.exit(-1);
        }
        
        // check if candidates are alphabetic
        for (int i = 0; i < args.length; ++i) 
        {
            String name = args[i];
            
            if (!isAlphabetic(name))
            {   
                System.out.printf("Names of the candidate must be alphabetic.\n");
                System.exit(-2);
            } 
        }

        // check if voters are greater than 100
        candidateCount = args.length;
        System.out.printf("Enter number of voters: ");
        voterCount = Integer.parseInt(stdin.nextLine());
        if (voterCount > MAX_VOTER)
        {
            System.out.printf("Maximum amount of voters is %d", MAX_VOTER);
            System.exit(-3);
        }

        // fill up candidate details
        for (int i = 0; i < candidateCount; ++i)
        {
            votes[i] = 0;
            eliminated[i] = false;
        }
    }    

    // records preference if vote is valid
    static boolean vote(int voter, int rank, String[] candidateName,String name)
    {
        for (int i = 0; i < candidateCount; ++i) 
        {
            if (candidateName[i].compareTo(name) == 0) 
            {
                preferences[voter][rank] = i;
                return true;
            }
        }

        return false;
    }

    // tabulates votes for non eliminated candidates
    static void tabulate(int[] votes, boolean[] eliminated)
    {
        for (int i = 0; i < voterCount; ++i)
        {
            for (int j = 0;  j < candidateCount; ++j)
            {
                int index = preferences[i][j];
                if (eliminated[index] == false)
                {
                    votes[index]++;
                }
            }
        }
    }

    // print the winner of the election, if there is one
    static boolean printWinner(int[] votes, String[] names)
    {   
        for (int i = 0; i < candidateCount; ++i) 
        {
            if (votes[i] > (voterCount / 2)) 
            {   
                System.out.printf("Winner: %s\n", names[i]);
                return true;
            }
        }

        return false;
    }

    // return the the smallest vote by checking every candidate, which is the last place candidate
    static int findMin(int[] voters, boolean[] eliminated)
    {
        int n = voterCount;

        for (int i = 0; i < candidateCount; ++i) 
        {
            if (voters[i] < n && eliminated[i] == false) 
            {
                n = voters[i];
            }
        }

        return n;
    }

    static boolean isTie(int min, int[] votes, boolean[] eliminated)
    {
        int tie = 0, stillRun = 0;

        for (int i = 0; i < candidateCount; ++i) 
        {
            if (votes[i] == min && eliminated[i] == false)
            {
                tie++;
                stillRun++;
            }
            else if (eliminated[i] == false)
            {
                stillRun++;
            }
        }

        return (tie == stillRun);
    }

    // eliminate the candidate in the last place
    static void eliminate(int min, int[] votes, boolean[] eliminated)
    {
        for (int i = 0; i < candidateCount; ++i) 
        {
            if (votes[i] == min) 
            {
                eliminated[i] = true;
            }
        }
    }

    public static void main(String[] args) 
    {
        // candidate details
        int[] votes = new int[MAX_CANDIDATE];
        boolean[] eliminated = new boolean[MAX_CANDIDATE];
        String[] names = args.clone();

        // check if supplied argument is correct
        isCommandArgCorrect(names, votes, eliminated);

        // Keep querying for votes
        for (int i = 0; i < voterCount; ++i)
        {
            // Query for each rank
            for (int j = 0; j < candidateCount; ++j)
            {
                System.out.printf("Rank %d: ", j + 1);
                String name = stdin.nextLine();

                // Record vote, unless invalid
                if (!vote(i, j, names, name))
                {
                    System.out.printf("Invalid vote\n");
                    System.exit(-4);
                }
            }
            System.out.println();       
        }

        // Keep holding runoffs, until winner exists
        while (true)
        {
            // Calculate votes given remaining candidates
            tabulate(votes, eliminated);

            boolean won = printWinner(votes, names);
            if (won)
                break;

            // eliminate last place candidates
            int min = findMin(votes, eliminated);
            boolean tie = isTie(min, votes, eliminated);

            // if tie, everybody wins
            if (tie)
            {
                for (int i = 0; i < candidateCount; ++i)
                {
                    if (!eliminated[i])
                        System.out.printf("%s\n", names[i]);
                }
                break;
            }

            // Eliminate anyonw with minimum number of votes
            eliminate(min, votes, eliminated);

            // Reset vote counts back to zero
            for (int i = 0; i < candidateCount; ++i)
                votes[i] = 0;
        }

        stdin.close();
        System.exit(0);
    }
}