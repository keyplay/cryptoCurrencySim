#pragma once
#include <iostream>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>

enum class Unit { USD, CNH, JPY, EUR };
enum class Owner_status { Individual, Institute };

class Currency {
private:
	int cent;
	std::string hash_owner;
	Unit unit;

public:
	Currency(int cent, Unit unit);
	int get_cent() const;

	bool operator< (const Currency& cur);
	bool operator> (const Currency& cur);
	bool operator>= (const Currency& cur);
	bool operator<= (const Currency& cur);
	bool operator== (const Currency& cur);
	bool operator!= (const Currency& cur);

	void assign_owner(const Owner_status ownst, const std::string id);
	void display_owner();

};
