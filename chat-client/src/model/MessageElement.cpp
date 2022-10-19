#include <model/header/MessageElement.h>
#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;


// Constructors -------------------------------------------------------------------
// Client's current username should not be reachable from this scope
// Fake username for now
MessageElement::MessageElement() {
	this->user_name = "Unmanned";
	this->msg_is_int = false;
}
MessageElement::MessageElement(string msg, string user_name, int user_id) {
	this->msg = msg;
	this->user_name = user_name;
	this->user_id = user_id;
	this->msg_is_int = false;
}


// Operators ----------------------------------------------------------------------
// Print Message to Command Line
ostream& operator<<(ostream& os, const MessageElement& messageElement) {
	return os << messageElement.user_name << ": " << messageElement.msg<<std::endl;
}
// Set Message from Command Line
istream& operator>>(istream& is, MessageElement& messageElement) {
	is >> messageElement.msg;

	// Command Line Testing
	try { messageElement.msg_int = stoi(messageElement.msg); messageElement.msg_is_int = true; } // Check if input is int
	catch (std::exception& e) {}

	return is;
}


// --------------------------------------------------------------------------------
void MessageElement::setMsg(string msg) { this->msg = msg; }
string MessageElement::getMsg() const { return msg; }

void MessageElement::setUserName(string user_name) { this->user_name = user_name; }
string MessageElement::getUserName() const { return user_name; }

// Command Line Testing
void MessageElement::setMsgInt(int msg_int) { this->msg_int = msg_int; }
int MessageElement::getMsgInt() const { return this->msg_int; }
bool MessageElement::isMsgInt() const { return this->msg_is_int; }
string MessageElement::msgUpper() const { 
	string upper;
	for (auto c : this->msg) upper += toupper(c); 
	return upper;
}