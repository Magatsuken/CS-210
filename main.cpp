#include <iostream>
using namespace std;

#include "Banking.h"

int main() {
	// Variables
	float initialInvestment;
	float monthlyDeposit;
	float annualInterest;
	int months;
	int years;

	Banking* info;

	// Display menu to the user
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: ";
	cin >> initialInvestment;
	cout << "Monthly Deposit: ";
	cin >> monthlyDeposit;
	cout << "Annual Interest: ";
	cin >> annualInterest;
	cout << "Number of years: ";
	cin >> years;

	// Press any key to continue and clears screen
	system("PAUSE");
	system("CLS");

	// Create new Banking object
	info = new Banking(initialInvestment, monthlyDeposit, annualInterest, years);
	info->DisplayMenu();

	// Press any key to continue and clears screen
	system("PAUSE");
	system("CLS");

	// Displays report of Balance without monthly deposits
	info->DisplayBalanceNoDeposit();

	// Press any key to continue and clears screen
	system("PAUSE");
	system("CLS");

	// Displays report of Balance with monthly deposits
	info->DisplayBalanceWithDeposit();
}