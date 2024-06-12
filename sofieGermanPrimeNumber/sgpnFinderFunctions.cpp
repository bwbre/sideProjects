/*
Brendan Womer

Sophie Germain Prime Number Finder

explanation: find n number of Sophie Germain Prime Numbers (SGPN)

steps: get value n from user, then find n number SGPNs

-get value from user
-starting from 1 increment currNum by 1 until n number SGPN are found
    -check if current number being looked at is a prime number
        -if prime number is found, check whether it is a SGPN
-when n number SGPN are found, print out the numbers
*/

#include <iostream>
#include <cmath>

using namespace std; 

int main() {
    int num = 0; // n number of SGPN numbers to be found.
    int tempSGPN = 0; // will temp store the value of any prime numbers that are found to be used in cheching whether is is a SGPN
    int counter = 0; // counter for the number of SGPN found
    bool isprime = true; // bool storing isprime -- defaults to true and will be neg when a non prime is found.
    int currNum = 0; // number currently being tested if is a SGPN. default 0, incremented at start of program loop.

    cout << "How many Sophie Germain Prime Numbers: ";
    cin >> num; // user enter's the number of SGPN they want to find

    /*
     REFERENCE --  FIRST 5 SGPN: 2,3,5,11,13
    */

    // PARENT LOOP - will loop until the desired number of SGPN found.
    while (counter < num) { 
        currNum++; // increment currNum being looked at
        isprime = true; // reset to true, the default value - will be neg when a even # is found

        isprime = checkPrime(currNum);

        // if isprime is true here, the the currNum is prime
        if (isprime == true) {
            int tempSGPN = currNum; // set to the 2*(currNum+1) value
            isprime = checkPrime(tempSGPN); 
        }

        //if isprime is true here, then both the original currNum, and it's 2*(currNum+1) counterpart are both prime -- i.e SGPN found at currNum.
        if (isprime == true) {
            cout << counter+1 << ") " << currNum << " is SFPN" << endl;
            counter++;
        }
    }

    return 0;
}

//checks whether integer value provided is prime
bool checkPrime(int currNum) {
    int isprime = true;

    // checks if currNum is prime -- returns isprime is false if currNum is even.
    for (int i = 2; i < currNum && isprime == true || i == 1; i++) { // checks all factors for the number currently being looked at.

        if (currNum % i == 0) { // if i is a factor of currNum - if currNum has a factor, then not prime number

            isprime = false; // isprime = false - even number found.
        }
    }

    return isprime; // returns true if prime number is found
}