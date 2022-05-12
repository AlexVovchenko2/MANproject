#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Player {
private:
	vector<string> cards;
public:
	Player(vector<string> cards) {
		this->cards = cards;
	}

	void print() {
		//нумерация при выводе начинается с 1, но индексация в массиве с 0
		for (int i = 0; i < cards.size(); ++i) {
			cout << i + 1 << ". " << cards[i] << endl;	
		}
	}

	void take(vector<string> cr) {
		for (int i = 0; i < cr.size(); ++i) {
			cards.push_back(cr[i]);
		}
	}

	string push(int a, string available) {
		if (0 < a < cards.size()) {
			exit(0);
		}
		/*
		if (find(available.begin(), available.end(), cards[a]) != available.end()) {
			
		}*/
		string b;
		b = cards[a-1];
		swap(cards[a-1], cards.back());
		cards.pop_back();
		return b;
	}

};

