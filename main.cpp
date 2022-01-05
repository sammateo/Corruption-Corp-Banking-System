#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Person {
public:
	string name;
	float balance;
	int accountnumber;
	int pin;

	Person() {
		balance = 0;
	}
};

void checkBalance(float *balance) {
	cout << "Your balance is: $" <<* balance << endl;
}

void deposit( float *balance) {
	float amount; 
	cout << "Enter Deposit amount: ";
	cin >> amount;
	while (amount < 0) {
		cout << "You are trying to deposit money that doesn't exist, please use a positive amount: ";
		cin >> amount;
	}
	
	*balance += amount;
	cout << "Deposit complete\nNew balance: $" << *balance<<endl;
}

void withdraw(float *balance) {
	float amount;

	cout << "Enter Withdrawal amount: ";
	cin >> amount;
	while (amount > *balance || amount < 0) {
		cout << "You are trying to withdraw more than you have, please select a balance less than $" <<*balance<<": ";
		cin >> amount;
	}

	*balance -= amount;
	cout << "Withdrawal complete\nNew balance: $" << *balance << endl;

}

void signIn(&Person person) {
	cout << "Enter your account number: ";
	cin >> person.accountnumber;
	cout << "Enter your pin: ";
	cin >> person.pin;
	string info;
	ifstream readC("corruption.txt");
	while (getline(readC, info)) {
		cout << info;
	}
}


int main() {
	Person customer;
	float* balance = &customer.balance;
	cout << "Hello World, welcome to Corruption Corp\n" << endl;
	int option;

	cout << "1. Sign In\n2. Register\n";
	cin >> option;
	if (option == 1)
		signIn(customer);
	

	do {
		cout << "Options: \n";
		cout << "1. Check Balance\n2. Deposit\n3. Withdraw\n4. Quit\n\n";
		cin >> option;
		if (option == 1) {
			checkBalance(balance);
		}
		else if (option == 2) {
			deposit(balance);
		}
		else if (option == 3) {
			withdraw(balance);
		}
		else if (option > 4) {
			cout << "Not a valid option, try again or be fined\n";
		}

		cout << endl;


	} while (option != 4);

	cout << "Balance: $" << customer.balance << endl;
	cout << "Thank you for banking with Corruption Corp\n";
}