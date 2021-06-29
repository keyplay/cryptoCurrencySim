// CryptoCurrency.cpp : Defines the entry point for the application.
//

#include "CryptoCurrency.h"
#include "Currency.h"


using namespace std;

int main()
{
	Currency cur(10, Unit::CNH);
	std::string owner = "bank";
	cur.assign_owner(Owner_status::Institute, owner);
	cur.display_owner();

	return 0;
}
