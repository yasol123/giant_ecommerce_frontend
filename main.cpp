#include <iostream>
#include <cctype>
#include <iomanip>
#include "Account.h"
using namespace std;

void showMenu();
void makeDeposit(Account &);
void withdraw(Account &);

int main() {
	Account savings;
	char choice;
	cout << fixed << showpoint << setprecision(2);
	do {
		showMenu();
		cin >> choice;
		while (toupper(choice < 'A' || toupper(choice) >'G')) {
			cout << "Please make a valid choice in the range " << "of A through G: ";
			cin >> choice;
		}
		switch (choice) {
		case 'a':
		case 'A':cout << "The current balance is $";
			cout << savings.getBalance() << endl;
			break;
		case 'b':
		case 'B':cout << "There have been ";
			cout << savings.getTransactions() << " transactions." << endl;
			break;
		case 'c':
		case 'C': cout << "Interest earned for this period: $";
			cout << savings.getInterest() << endl;
			break;
		case 'd':
		case 'D':makeDeposit(savings);
			break;
		case 'e':
		case 'E': withdraw(savings);
			break;
		case 'f':
		case 'F':savings.calculationInterest();
		}
	} while (toupper(choice) != 'G');
	return 0;
}

void showMenu() {
	cout << "\n			Menu\n";
	cout << "-----------------------------------------------" << endl;
	cout << "A. Display the balance amount" << endl;
	cout << "B. Display the number of transactions << endl";
	cout << "C. Display the interest earned for this period" << endl;
	cout << "D. Make a Deposit" << endl;
	cout << "E. Make a Withdrawal" << endl;
	cout << "F. Add interest for this period" << endl;
	cout << "G. Exit the program" << endl;
	cout << endl;
	cout << "Make your choice: ";
}
void makeDeposit(Account &acct) {
	double dollars;
	cout << "Enter the amount of the deposit: $";
	cin >> dollars;
	cin.ignore();
	acct.makeDeposit(dollars);
}
void withdraw(Account &acct) {
	double dollars;
	cout << "Please enter the amount of withdrawl: $";
	cin >> dollars;
	cin.ignore();
	if (!acct.withdraw(dollars)) 
		cout << "ERROR: Not Enough Money or Witdrawal Amount too Large. \n\n";
}
