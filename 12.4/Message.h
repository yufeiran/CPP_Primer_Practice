#pragma once
#include<string>
#include<set>

class Folder;
class Message
{
	friend Folder;
	friend void swap(Message& lhs, Message& rhs);
public:
	Message() :rawContent(std::string()) {};
	Message(const std::string& s) :rawContent(s) {};
	Message(Message&& m)noexcept;
	Message& operator=(const Message& m);
	Message& operator=(Message&& m)noexcept;
	Message(const Message& m);
	void addFolder(Folder& f);
	void removeFolder(Folder& f);
private:
	void move_Folders(Message* m);
	void removeFromAllFolders();
	void addToAllFolders();
	std::string rawContent;
	std::set<Folder*>folders;
};

void swap(Message& lhs, Message& rhs);

class Folder
{
	friend Message;
public:
	Folder() {};
	Folder(const std::string& s) :folderName(s) {};
	void addMessage(Message& m);
	void removeMessage(Message& m);
	void show();
private:
	std::string folderName;
	std::set<Message*>messages;
};

