/*
Sieve of Eratosthenes - finds all prime numbers up to N. works by iteratively marking multiples of each prime number as non-prime numbers-- I.E sieving them.



*/



#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void initarray(vector<vector<int>>&, int);
void printarray(vector<vector<int>>&, int);

int main() {
    int selection;
    cout << "sieve out non-prime numbers up to N\nN: ";
    cin >> selection;

    int n = selection; //declaure n as a constant

    vector<vector<int>> array(n, vector<int>(n));
    
    initarray(array, n); // fills all the empty elements from 2 -> N
    printarray(array, n);
    return 0;
}

void initarray(vector<vector<int>> &arr, int n) {
    int count=2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = count;
            count++;
        }
    } 
}

void printarray(vector<vector<int>> &arr, int n) {
    cout << fixed << left;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

                cout << setw(5) << arr[i][j];
        }
    cout << endl;
    }
}