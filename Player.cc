#include "Player.h"
#include <algorithm>

#include "Improvable.h"

Player::Player (const std::string &name, char playerChar, int money): name{name}, playerChar{playerChar}, money{money}, netWorth{money} {}

char Player::getPlayerChar() const {
	return playerChar;
}

std::string Player::getPlayerName() const {
	return name;
}

int Player::getMoney() const {
	return money;
}

//"Perhaps this should return a shared pointer instead?"
std::vector<std::shared_ptr<Property>> Player::getProperties() const{
	return owned;
}

void Player::updateNetWorth() {
	int worth = 0;

	for (int i = 0; i < owned.size(); i++) {
		worth += owned[i]->getValue();
	}
	netWorth = worth + money;
}

int Player::getNetWorth () const {
	return netWorth;
}

void Player::buy(std::shared_ptr<Property> p) {
	owned.push_back(p);
}

void Player::pay(std::shared_ptr<Player> other, int amount) {
	if (amount > money) {
		//"Throw some exception to disallow this transaction"
	} else {
		money -= amount;
		other->money += amount;
	}
}

void Player::trade(std::shared_ptr<Player> other, int money, std::shared_ptr<Property> others) {

	auto it = find(other->owned.begin(), other->owned.end(), others);

	if (money > this->money) { // "Checking if the current player has enough money for the trade"
		//"Throw some exception to disallow this trade"
	} else if (it == other->owned.end()) {// "Checking if other play owns this property"
		// "Throw some exception since other person does not own this property"
	} else {
		pay(other, money);
		owned.push_back(*it);
		other->owned.erase(it);
	}
}

void Player::trade(std::shared_ptr<Player> other, std::shared_ptr<Property> mine, int money) {
	auto it = find(owned.begin(), owned.end(), mine);

	if (money > other->money) { // "Checking if the current player has enough money for the trade"
		//"Throw some exception to disallow this trade"
	} else if (it == owned.end()) {// "Checking if other play owns this property"
		// "Throw some exception since other person does not own this property"
	} else {
		other->money -= money;
		this->money += money;
		other->owned.push_back(*it);
		owned.erase(it);
	}
}

void Player::trade(std::shared_ptr<Player> other, std::shared_ptr<Property> mine, std::shared_ptr<Property> others) {
	
	auto first = find(owned.begin(), owned.end(), mine);
	auto second = find(other->owned.begin(), other->owned.end(), others);

	if (first == owned.end()) {
		//"Throw some exception, since this player does not have the property to trade"
	} else if (second == other->owned.end()) {
		//"Throw some exception, since other player does own its property ro trade"
	} else {
		
		owned.push_back(*second);
		other->owned.push_back(*first);

		owned.erase(first);
		other->owned.erase(second);

	}

}






