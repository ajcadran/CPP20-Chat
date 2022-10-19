#include <iostream>
#include <string>


class MessageElement
{
	friend std::ostream& operator<<(std::ostream&, const MessageElement&);
	friend std::istream& operator>>(std::istream&, MessageElement&);

private:
	std::string msg;
	std::string user_name;
	int user_id;

	// Command Line Testing
	int msg_int;
	bool msg_is_int;


public:
	MessageElement();
	MessageElement(std::string, std::string, int);

	void setMsg(std::string);
	std::string getMsg() const;
	void setUserName(std::string);
	std::string getUserName() const;

	// Command Line Testing
	void setMsgInt(int);
	int getMsgInt() const;
	bool isMsgInt() const;
	std::string msgUpper() const;
};