#include"Screen.h"

Screen& Screen::set(char c) 
{ 
	_data[curPos] = c; 
	return *this; 
}
Screen& Screen::set(pos x, pos y, char c) 
{ 
	_data[y * width + x] = c; 
	return *this; 
}

void Screen::do_display(std::ostream& os) const 
{ 
	for (pos i = 0; i < height; i++) {
		os << "|";
		for (pos j = 0; j < width; j++) {
			os << _data[i * width + j];
		}
		os << "|";
		os << std::endl;
	}
}

void Window_mgr::clear(index i)
{
	auto& ScreenNow = Screens[i];
	ScreenNow._data = std::string(ScreenNow.width * ScreenNow.height, ' ');
}