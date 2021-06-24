#include "Banking.h"

#include<iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Initialize Banking
Banking::Banking() {
	initialInvestment = 0;
	monthlyDeposit = 0;
	annualInterest = 0;
	months = 0;
	years = 0;
}

// Constructor
Banking::Banking(float investment, float deposit, float interest, int year) {
	initialInvestment = investment;
	monthlyDeposit = deposit;
	annualInterest = interest;
	years = year;
	months = year * 12;
}

// Accessors
float Banking::GetInvestment() {
	return initialInvestment;
}

float Banking::GetDeposit() {
	return monthlyDeposit;
}

float Banking::GetInterest() {
	return annualInterest;
}

int Banking::GetYears() {
	return years;
}

int Banking::GetMonths() {
	months = years * 12;
	return months;
}

// Displays User Input
void Banking::DisplayMenu() {
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: $" << GetInvestment() << endl;
	cout << "Monthly Deposit: $" << GetDeposit() << endl;
	cout << "Annual Interest: " << GetInterest() << '%' << endl;
	cout << "Number of years: " << GetYears() << endl;
}

// Displays balance without deposits
void Banking::DisplayBalanceNoDeposit() {
	// Variables
	float interestAmount;
	float totalAmount = GetInvestment();

	cout << "	Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "========================================================================" << endl;
	cout << "Year		Year End Balance		Year End Earned Interest" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	// Calculates interest
	for (int i = 0; i < years; i++) {
		interestAmount = ((totalAmount) * (GetInterest() / 100));
		totalAmount += interestAmount;

		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestAmount << endl;
	}
	cout << "========================================================================" << endl;
	cout << "				End Report" << endl;
}

// Displays balance with deposits
	void Banking::DisplayBalanceWithDeposit() {
		// Variables
		float yearlyTotalInterest;
		float interestAmount;
		float totalAmount = GetInvestment();

		cout << "	Balance and Interest With Additional Monthly Deposits" << endl;
		cout << "========================================================================" << endl;
		cout << "Year		Year End Balance		Year End Earned Interest" << endl;
		cout << "------------------------------------------------------------------------" << endl;

		for (int i = 0; i < years; i++) {
			// Initialize yearly interest to 0
			yearlyTotalInterest = 0;
			// For loop that calculates monthly interest
			for (int j = 0; j < 12; j++) {
				interestAmount = (((totalAmount + GetDeposit()) * (GetInterest() / 100)) / 12);

				yearlyTotalInterest = yearlyTotalInterest + interestAmount;

				totalAmount = totalAmount + monthlyDeposit + interestAmount;
			}
			cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << yearlyTotalInterest << endl;
		}
		cout << "========================================================================" << endl;
		cout << "				End Report" << endl;
}