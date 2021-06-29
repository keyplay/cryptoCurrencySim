#include "Currency.h"

Currency::Currency(int cent, Unit unit): cent(cent), unit(unit) {
}

int Currency::get_cent() const {
	return cent;
}

bool Currency::operator< (const Currency& cur) {
	return cent < cur.get_cent();
}

bool Currency::operator> (const Currency& cur) {
	return cent > cur.get_cent();
}

bool Currency::operator<= (const Currency& cur) {
	return cent <= cur.get_cent();
}

bool Currency::operator>= (const Currency& cur) {
	return cent >= cur.get_cent();
}

bool Currency::operator== (const Currency& cur) {
	return cent == cur.get_cent();
}

bool Currency::operator!= (const Currency& cur) {
	return cent != cur.get_cent();
}

void Currency::assign_owner(const Owner_status ownst, const std::string id) {
	CryptoPP::SHA256 hash;

	hash.Update((const CryptoPP::byte*)id.data(), id.size());
	hash.Update((const CryptoPP::byte*)&ownst, sizeof(ownst));
	hash_owner.resize(hash.DigestSize());
	hash.Final((CryptoPP::byte*) & hash_owner[0]);
}

void Currency::display_owner() {
	CryptoPP::HexEncoder encoder(new CryptoPP::FileSink(std::cout));
	CryptoPP::StringSource str_source(hash_owner, true, new CryptoPP::Redirector(encoder));
}

