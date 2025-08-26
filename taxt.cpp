#include<iostream>
using namespace std;

int main() {
    int *p1 = new int;  // allocate memory for first integer
    int *p2 = new int;  // allocate memory for second integer
    int sum;

    cout << "Enter two numbers: ";
    cin >> *p1 >> *p2;  // read values into allocated memory

    sum = *p1 + *p2;
    cout << "Sum = " << sum << "\n";

    delete p1;  // free memory
    delete p2;

    // Optional: printing pointer addresses (not values)
    cout << "p1 address: " << p1 << "\n";
    cout << "p2 address: " << p2 << "\n";
    cout << "Sum again = " << sum << "\n";

    return 0;
}
