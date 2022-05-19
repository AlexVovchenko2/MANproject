#pragma once
#include<iostream>
#include<string>
using namespace std;

class Player {
private:
	string pl_choice;
	int v, l, d;
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

	void setc();

	void incrv();

	void incrl();

	void incrd();

	string getc();

	int getv();

	int getl();

	int getd();

};

void Player::setc() {
init:
	cout << "Choose: " << "\t1) Rock \t2) Paper \t3) Scissors" << endl;
	int a;
	cin >> a;
	a -= 1;
	try {
		pl_choice = names[a];
	}
	catch(...) {
		cout << "Incorect number. Try again." << endl;
		goto init;
	}
}

void Player::incrv() {
	++v;
}

void Player::incrl() {
	++l;
}

void Player::incrd() {
	++d;
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