#pragma once
#include<iostream>
#include<string>
using namespace std;

class Player {
private:
	string pl_choice;
	int v, l, d;
	double winrate;
	const string names[3] = { "Rock", "Paper", "Scissors" };
public:
	Player() {
		pl_choice = "";
		v = 0;
		l = 0;
		d = 0;
	}
	~Player() {
		cout << "Destructor called" << endl;
	}

	void setc(string s);

	void setwr();

	void incrv();

	void incrl();

	void incrd();

	string getc();

	int getv();

	int getl();

	int getd();

	double getwr();

};

void Player::setc(string s) {
	pl_choice = s;
}

void Player::setwr() {
	winrate = (v / (v + l + d)) * 100;
}

void Player::incrv() {
	++v;
	setwr();
}

void Player::incrl() {
	++l;
	setwr();
}

void Player::incrd() {
	++d;
	setwr();
}

string Player::getc() {
	return pl_choice;
}

int Player::getv() {
	return v;
}

int Player::getl() {
	return l;
}

int Player::getd() {
	return d;
}

double Player::getwr() {
	return winrate;
}


