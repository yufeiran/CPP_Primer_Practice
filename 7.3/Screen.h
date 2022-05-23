#pragma once
#include<string>
#include<iostream>
#include<vector>

class Window_mgr;

class Screen
{
public:
	friend Window_mgr;
	using pos = std::string::size_type;
	Screen() = default;
	Screen(int Width, int Height, char c) :width(Width), height(Height), _data(std::string(Width*Height,c)) {};
	Screen(int Width, int Height) :Screen(Width, Height, ' ') {};
	char get()const { getCount++; return _data[curPos]; }
	char get(pos x, pos y)const { getCount++; return _data[y * width + x]; }

	Screen& set(char c);
	Screen& set(pos x, pos y, char c);
	Screen& move(pos x, pos y) { curPos = y * width + x; return *this; }

	Screen& display(std::ostream &os) { do_display(os); return *this; }
	const Screen& display(std::ostream& os)const { do_display(os); return *this; }

	int getGetCount()const { return getCount; }
private:
	void do_display(std::ostream& os) const;
	std::string _data;
	mutable int getCount = 0;
	pos curPos = 0;
	pos width = 0;
	pos height = 0;
};

class Window_mgr
{
public:
	using index = std::vector<Screen>::size_type;
	void clear(index);
private:
	std::vector<Screen>Screens = { Screen(40, 30, ' ') };
};