#include<iostream>
#include <vector>
#include "Players.h"
#include "Random.h"
using namespace std;

int main() {
	string deck_default[36] = {
	"six\3", "seven\3", "eight\3", "nine\3", "ten\3" , "jack\3", "queen\3", "king\3", "ace\3",
	"six\4", "seven\4", "eight\4", "nine\4", "ten\4" , "jack\4", "queen\4", "king\4", "ace\4",
	"six\5", "seven\5", "eight\5", "nine\5", "ten\5" , "jack\5", "queen\5", "king\5", "ace\5",
	"six\6", "seven\6", "eight\6", "nine\6", "ten\6" , "jack\6", "queen\6", "king\6", "ace\6",
	};

	vector<string> deck_support;
	for (int i = 0; i < 36; ++i) {
		deck_support.push_back(deck_default[i]);     //колода ещё не перемешана
	}

	vector<string> deck_shuffled;
	deck_shuffled = shuffle(deck_support);
	for (int i = 0; i < deck_shuffled.size(); ++i) {
		cout << deck_shuffled[i] << endl;
	}

	deck_support.clear();
	return 0;
}