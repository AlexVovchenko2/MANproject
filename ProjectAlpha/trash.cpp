#include<iostream>
#include<string>
using namespace std;



string get_name() {
init:
	cout << "Write your choose: " << "\t1) Rock \t2) Paper \t3) Scissors" << endl;
	string str;
	cin >> str;
	if (str == "Rock" || str == "Paper" || str == "Scissors") {
		return str;
	}
	else { 
		cout << "Incorrect value. Try again." << endl;
		goto init; 
	}
}

bool draw(string s1, string s2) { return s1 == s2; }

bool win(string s1, string s2) {
	if (s1 == "Rock") {
		return (s2 == "Scissors");
	}
	else if (s1 == "Paper") {
		return (s2 == "Rock");
	}
	else if (s1 == "Scissors") {
		return (s2 == "Paper");
	}
}