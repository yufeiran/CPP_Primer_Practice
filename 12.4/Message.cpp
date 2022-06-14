#include"Message.h"
#include<iostream>
using namespace std;

Message::Message(Message&& m)noexcept:rawContent(std::move(m.rawContent))
{
	move_Folders(&m);
	
}

Message& Message::operator=(const Message& m)
{
	removeFromAllFolders();
	rawContent = m.rawContent;
	folders = m.folders;
	addToAllFolders();
	return *this;


}

Message& Message::operator=(Message&& m)noexcept
{
	if (&m != this) {
		removeFromAllFolders();
		move_Folders(&m);
		m.folders.clear();
	}
	return *this;
}

Message::Message(const Message& m)
{
	rawContent = m.rawContent;
	folders = m.folders;
	addToAllFolders();
}

void Message::addFolder(Folder& f)
{
	folders.insert(&f);
	f.addMessage(*this);
}

void Message::removeFolder(Folder& f)
{
	folders.erase(&f);
	f.removeMessage(*this);

}

void Message::move_Folders(Message* m)
{
	folders = std::move(m->folders);
	for (auto& f : folders) {
		f->removeMessage(*m);
		f->addMessage(*this);
	}
	m->folders.clear();
}

void Message::removeFromAllFolders()
{
	for (auto f : folders) {
		f->removeMessage(*this);
	}
}

void Message::addToAllFolders()
{
	for (auto f : folders) {
		f->addMessage(*this);
	}
}

void swap(Message& lhs, Message& rhs)
{
	using std::swap;
	for (auto f : lhs.folders) {
		f->removeMessage(lhs);
	}
	for (auto f : rhs.folders) {
		f->removeMessage(rhs);
	}

	swap(lhs.rawContent, rhs.rawContent);
	swap(lhs.folders, rhs.folders);

	lhs.addToAllFolders();
	rhs.addToAllFolders();
}


void Folder::addMessage(Message& m)
{
	messages.insert(&m);

}

void Folder::removeMessage(Message& m)
{
	messages.erase(&m);
}

void Folder::show()
{
	cout << "[" << folderName << "]" << endl;
	for (auto s : messages) {
		cout << "\t- " << s->rawContent << endl;
	}
}