#pragma warning(disable:4996)
#pragma comment(lib,"ws2_32.lib")
#include<iostream>
#include<WinSock2.h>
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

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
			std::string msg;
			char msg2[256];
			for (int t = 0; t < 256; ++t)
				msg2[t] = 0;
			int i = 0;
			for (;;) {
				std::cout << "You: ";
				std::getline(std::cin, msg);
				strncpy(msg2, msg.c_str(), msg.length() + 1);
				send(newConnection, msg2, sizeof(msg2), NULL);
				recv(newConnection, msg2, sizeof(msg2), NULL);
				std::cout << "Client: " << " " << msg2 << std::endl;
				if (i == 0) { system("cls"); std::cout << "#######################################" << std::endl; }
				i = 1;
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
		std::string msg;
		char msg2[256];
		//char msg_in[256];
		int i = 0;
		for (;;) {
			recv(Connection, msg2, sizeof(msg2), NULL);
			std::cout << "Server: " << msg2 << std::endl;
			std::cout << "You: ";
			std::getline(std::cin, msg);
			strncpy(msg2, msg.c_str(), msg.length() + 1);
			send(Connection, msg2, sizeof(msg2), NULL);
			if (i == 0) { system("cls"); std::cout << "#######################################" << std::endl; }
			i = 1;
		}
		delete[]IP_addr;
	}
	else {
		cout << "ERROR" << endl;
	}
	return 0;
}