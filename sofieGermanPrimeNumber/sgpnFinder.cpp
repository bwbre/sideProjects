#include <iostream>
#include <cmath>

using namespace std; 

int main() {
    int num; // n number of SGPN numbers to be found.
    int tempSGPN = 0; // will temp store the value of any prime numbers that are found to be used in cheching whether is is a SGPN
    int counter = 0; // counter for the number of SGPN found
    bool isprime = true; // bool storing isprime -- defaults to true and will be neg when a non prime is found.
    int currNum = 0; // number currently being looked at. default 0, incremented at start of program loop.
    cout << "How many Sofie German Prime Numbers: ";
    cin >> num; // user enter's the number of SGPN they want to find

    // REFERENCE --  FIRST 5 SGPN: 2,3,5,11,13

    // PARENT LOOP - will loop until the desired number of SGPN found.
    while (counter < num) { 
        currNum++;
        isprime = true; // reset to true, the default value - will be neg when a even # is found

        // checks if currNum is prime -- returns isprime is false if currNum is even.
        for (int i = 2; i < currNum && isprime == true || i == 1; i++) { // checks all factors for the number currently being looked at.

            if (currNum % i == 0) { // if i is a factor of currNum
                isprime = false; // return isprime = false - i.e even number found.
            }
        }

        int tempSGPN = currNum;
        // if isprime is true here, the the currNum is prime
        if (isprime == true) {

            // cout << "\ntesting whether " << counter << " is SFPN\n" << endl;
            for (int i = 2; i < tempSGPN && isprime == true; i++) { // check all numbers up to 2*(tempSGPN+1) if they are a factor

                // cout << num+1 << " % " << i << " = " << (num+1)%2 << endl;
                if (tempSGPN % i == 0) { //check whether factor
                    isprime = false;
                }
            }    
        }

        //if isprime is true here, then both the original currNum, and it's 2*(currNum+1) counterpart are both prime -- i.e SGPN found.
        if (isprime == true) {
            cout << counter+1 << ") " << currNum << " is SFPN" << endl;
            counter++;
        }
    }

    return 0;
}