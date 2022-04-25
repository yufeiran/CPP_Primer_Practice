#include<iostream>
#include"Sales_item.h"

int main()
{
	Sales_item current_item, item;

	if (std::cin >> current_item) {
		Sales_item total = current_item;
		while (std::cin >> item) {
			if (item.isbn() == current_item.isbn()) {
				total += item;
			}
			else {
				std::cout << total << std::endl;
				current_item = item;
				total = item;
			}
		}
		std::cout << total << std::endl;
	}
	else { //没有输入，警告读者
		std::cerr << "No data?!" << std::endl;
		return -1;

	}


	return 0;
}