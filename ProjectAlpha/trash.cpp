#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;



string get_name() {
init:
	cout << "Write your choose: " << "\t1) Rock \t2) Paper \t3) Scissors" << endl;
	string str;
	cin >> str;
	transform(str.begin(), str.end(), str.begin(), tolower);
	if (str == "rock" || str == "paper" || str == "scissors") {
		return str;
	}
	else { 
		cout << "Incorrect value. Try again." << endl;
		goto init; 
	}
}

bool draw(string s1, string s2) { return s1 == s2; }

bool win(string s1, string s2) {
	if (s1 == "rock") {
		return (s2 == "scissors");
	}
	else if (s1 == "paper") {
		return (s2 == "rock");
	}
	else if (s1 == "scissors") {
		return (s2 == "paper");
	}
}

