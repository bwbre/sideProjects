/*
Banking System

For practice, design a banking system that simulates basic banking operations such as account creation, 
    deposits, withdrawals, and balance inquiries.

-Bank
    -Employee
    -Customer

Account class (For each checking/saving account)
*/



#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Bank {
    private:
        //private data;
        int safecombo; //filler variable
    public:
        //public data
        string name; //Bank name
};

class Customer {
    private:
        static int ssn;
        static int dob;
        string address;
        // vector<BankAccount> accounts; // int array that will store all the customer's account #'s (IDs)
    public:
        static string name;

        Customer(const string& name, const int& ssn, const int& dob, string& address);
        /*
        getBalance(accountNumber);
        deposit(amount);
        withdraw(amount);
        getTransactionHistory; //get transaction history for a specified account.   
        */
};

class BankAccount {
    private:
        static int accountNumber; //account ID#
        int balance;
        //getTransactionHistory();
};

int main(int argc, char* argv[]) {
    string tmpname, tmpaddress;
    int tmpssn, tmpdob;
    
    cout << "This is the menu.\nCreate a new customer.. enter full name:";
    getline(cin, tmpname);
    cout << "\nEnter ssn:";
    cin >> tmpssn;
    cout << "\nEnter dob:";
    cin >> tmpdob;
    cout << "\nEnter Address:";
    cin >> tmpaddress;

    Customer* customer = new Customer(tmpname, tmpssn, tmpdob, tmpaddress);




}

// void Customer::createCustomer(string& name, int& ssn, int& dob, string& address) {
//     createCustomer(name, dob, address) : name(name), ssn(ssn), dob(dob), address(address) {} 

// }