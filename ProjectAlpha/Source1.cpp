#pragma warning(disable:4996)
#pragma comment(lib,"ws2_32.lib")
#include<iostream>
#include<WinSock2.h>
#include<iostream>
#include<string>
#include<cstdio>
#include"PlayerClass.h"
#include"resource.h"
#include"resource1.h"
using namespace std;

string get_name();
bool win(string, string);
bool draw(string, string);

void print(Player pl, int i) {
	cout << "Total: " << endl;
	cout << "\tvictories - " << pl.getv() << endl;
	cout << "\tdefeats - " << pl.getl() << endl;
	cout <<	"\tdraws - " << pl.getd() << endl;
	double var = (pl.getv() != 0) ? (pl.getv() / i) * 100 : 0;
	cout << "Winrate(%): " << var << endl;
	cout << endl << "#####################################################" << endl << endl;
}

int main() {
	char mode = ' ';
	cout << "Select the mode [s - server, c - client]: ";
	cin >> mode;
	if (mode == 's') {
		setlocale(0, "rus");
		char* IP_addr = new char[1];
		std::string ip;
		std::cout << "Enter server's IP: ";
		std::cin >> ip;
		strcpy(IP_addr, ip.c_str());
		WSAData wsaData;
		WORD DLLVersion = MAKEWORD(2, 1);
		if (WSAStartup(DLLVersion, &wsaData) != 0) {
			std::cout << "ERROR" << std::endl;
			exit(1);
		}

		SOCKADDR_IN addr;
		int sizeofaddr = sizeof(addr);
		addr.sin_addr.s_addr = inet_addr(IP_addr);
		addr.sin_port = htons(1010);
		addr.sin_family = AF_INET;

		SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
		bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
		listen(sListen, SOMAXCONN);
		SOCKET newConnection;
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
		if (newConnection == 0) {
			std::cout << "ERROR#2";
		}
		else {
			std::cout << "CLIENT CONNECTED!" << std::endl;
			system("cls");
			Player pl1;
			std::string msg;
			std::string your_s, another_s;
			char msg2[256];
			int i = 1; int a = 0;
			while(1) {
				cout << "ROUND " << to_string(i) << endl;
				pl1.setc(get_name());
				msg = pl1.getc();
				std::cout << "You've chosen: " << msg << endl;
				strncpy(msg2, msg.c_str(), msg.length() + 1);
				//std::cout << "You: " << msg;
				//std::getline(std::cin, msg);
				//strncpy(msg2, msg.c_str(), msg.length() + 1);
				your_s = msg2;
				send(newConnection, msg2, sizeof(msg2), NULL);
				recv(newConnection, msg2, sizeof(msg2), NULL);
				std::cout << "Another player: " << " " << msg2 << std::endl;
				another_s = msg2;
				
				if (draw(your_s, another_s)) {
					cout << "DRAW!" << endl;
					pl1.incrd();
				}
				else {
					if (win(your_s, another_s)) {
						cout << "YOU WIN!" << endl;
						pl1.incrv();
						++a;
					}
					else {
						cout << "YOU LOSE!" << endl;
						pl1.incrl();
					}
				}
				/*cout << "Total: " << 
					"\n\tvictories - " << pl1.getv() <<
					"\n\tdefeats - " << pl1.getl() <<
					"\n\tdraws - " << pl1.getd() << endl;
				double var = (pl1.getv() != 0) ? (pl1.getv() / i) * 100 : 0;
				cout << "Winrate(%): " << var << endl;
				cout << endl << "#####################################################" << endl << endl;*/
				cout << "Total: " << endl;
				cout << "\tvictories - " << to_string(pl1.getv()) << endl;
				cout << "\tdefeats - " << to_string(pl1.getl()) << endl;
				cout << "\tdraws - " << to_string(pl1.getd()) << endl;
				/*double var = (pl1.getv() != 0) ? (pl1.getv() / (pl1.getv() + pl1.getd() + pl1.getl())) * 100 : 0;
				cout << "Winrate(%): " << to_string(var) << endl;*/
				cout << endl << "#####################################################" << endl << endl;
				++i;
			}
		}
		delete[]IP_addr;
	}
	else if (mode == 'c') {
		setlocale(0, "rus");
		char* IP_addr = new char[1];
		std::string ip;
		std::cout << "Enter server's IP: ";
		std::cin >> ip;
		strcpy(IP_addr, ip.c_str());
		WSAData wsaData;
		WORD DLLVersion = MAKEWORD(2, 1);
		if (WSAStartup(DLLVersion, &wsaData) != 0) {
			std::cout << "ERROR" << std::endl;
			exit(1);
		}

		SOCKADDR_IN addr;
		int sizeofaddr = sizeof(addr);
		addr.sin_addr.s_addr = inet_addr(IP_addr);
		addr.sin_port = htons(1010);
		addr.sin_family = AF_INET;

		SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
		if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
			std::cout << "CONNECTION FAILED!" << std::endl;
			return 1;
		}
		std::cout << "CONNECTED TO THE SERVER!" << std::endl;
		system("cls");
		Player pl2;
		std::string msg;
		std::string your_s, another_s;
		char msg2[256];
		int i = 1; int a = 0;
		while(1) {
			cout << "ROUND " << to_string(i) << endl;
			pl2.setc(get_name());
			msg = pl2.getc();
			std::cout << "You've chosen: " << msg << endl;
			recv(Connection, msg2, sizeof(msg2), NULL);
			std::cout << "Another player: " << msg2 << std::endl;
			another_s = msg2;
			//std::cout << "You: ";
			//std::getline(std::cin, msg);
			strncpy(msg2, msg.c_str(), msg.length() + 1);
			send(Connection, msg2, sizeof(msg2), NULL);
			your_s = msg2;
			if (draw(your_s, another_s)) {
				cout << "DRAW!" << endl;
				pl2.incrd();
			}
			else {
				if (win(your_s, another_s)) {
					cout << "YOU WIN!" << endl;
					pl2.incrv();
					++a;
				}
				else {
					cout << "YOU LOSE!" << endl;
					pl2.incrl();
				}
			}
			/*cout << "Total: " <<
				"\n\tvictories - " << pl2.getv() <<
				"\n\tdefeats - " << pl2.getl() <<
				"\n\tdraws - " << pl2.getd() << endl;
			double var = (pl2.getv() != 0) ? (pl2.getv() / i) * 100 : 0;
			cout << "Winrate(%): " << var << endl;
			cout << endl << "#####################################################" << endl << endl;*/
			cout << "Total: " << endl;
			cout << "\tvictories - " << to_string(pl2.getv()) << endl;
			cout << "\tdefeats - " << to_string(pl2.getl()) << endl;
			cout << "\tdraws - " << to_string(pl2.getd()) << endl;
			/*double var = (pl2.getv() != 0) ? (pl2.getv() / (pl2.getv()+pl2.getd()+pl2.getl())) * 100 : 0;
			cout << "Winrate(%): " << to_string(var) << endl;*/
			cout << endl << "#####################################################" << endl << endl;
			++i;
		}
		delete[]IP_addr;
	}
	else {
		cout << "ERROR" << endl;
	}
	return 0;
}