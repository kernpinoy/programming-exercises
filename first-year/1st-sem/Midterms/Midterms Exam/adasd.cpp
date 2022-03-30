#include <iostream>

using namespace std;

int main()
{
    int lb = 1000;
    int bal;
    int aload;
    int personc;
    int tload = 0;
    int loadbal;

    cout << "Enter number of person to be loaded: ";
    cin >> personc;

    for (int i = 1; i <= personc; ++i)
    {
        cout << "\nLoad Transaction No." << i;
        cout << "\nAmount Load Php:";
        cin >> aload;
        tload = tload + aload;
        lb = lb - aload;
        loadbal = lb;
        cout << "Balance of load: " << lb;
        cout << "\n========================";
        cout << "\n========================";
    }
    cout << "\nAll load request processed.";

    if (loadbal <= 0)
    {
        cout << "\n!========Alert=========!";
        cout << "\nPlease Check your Loading Transaction";
    }
    else
    {
        cout << "\n!========Great=========!";
        cout << "\nNo Problem";
    }

    cout << "\nPaula Ma";
    cout << "\n!======================!";
    cout << "\nTotal Number of Transaction: " << personc;
    cout << "\nTotal Load request is PHP" << tload;
    cout << "\nTotal Load Balance is PHP" << lb;
}