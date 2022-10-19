#include <model/header/MessageElement.h>
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;


// Variables -----------------------------------------------
std::atomic<int> num;

// Functions -----------------------------------------------
void add(int n) { num += n; }
void printNum() { cout << "Num: " << num << endl; }


int main()
{
	cout << "Message Test" << endl;

	while (true) {
		cout << "~ ";

		// Get User Input
		MessageElement message;
		cin >> message;

		//
		if (message.msgUpper() == "EXIT") { exit(EXIT_SUCCESS); }
		else if (message.msgUpper() == "NUM") { printNum(); }
		else if (message.isMsgInt()) {
			add(message.getMsgInt());
			printNum();
		}
		else { cout << message; }
	}
}