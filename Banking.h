#include <string>
using namespace std;

typedef
class Banking { 
private:
	// Variables
	float initialInvestment;
	float monthlyDeposit;
	float annualInterest;
	int months;
	int years;

public:
	// Constructor
	Banking();

	Banking(float investment, float deposit, float interest, int years);

	// Accessors
	float GetInvestment();
	float GetDeposit();
	float GetInterest();
	int GetYears();
	int GetMonths();

	// Print functions
	void DisplayMenu();

	void DisplayBalanceNoDeposit();

	void DisplayBalanceWithDeposit();
};

