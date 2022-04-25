#include<iostream>

int main()
{
	//1.9
	int index = 50, val = 0;
	while (index < 100)
	{
		val += index;
		++index;
	}
	std::cout << val << std::endl;

	//1.10
	 index = 10;
	while (index > 0)
	{
		--index;
		std::cout << index << std::endl;
	}

	//1.11
	int a, b;
	std::cout << "Enter two num:";
	std::cin >> a >> b;
	if (a <= b) 
	{
		index = a;
		while (index <= b)
		{
			std::cout << index << std::endl;
			index++;
		}
	}
	else
	{
		index = a;
		while (index >= b)
		{
			std::cout << index << std::endl;
			index--;
		}

	}

	//1.13
	val = 0;
	for (int index = 50; index < 100; index++)
	{
		val += index;
	}
	std::cout << val << std::endl;

	for (int index = 9; index >= 0; index--)
	{
		std::cout << index << std::endl;
	}
	std::cout << "Enter two num:";
	std::cin >> a >> b;
	for (int index = a; index <= b; index++)
	{
		std::cout << index << std::endl;
	}

	////1.16
	//val = 0;
	//int sum = 0;
	//while ((std::cin >> val))
	//{
	//	sum += val;
	//}
	//std::cout<<"Sum is " << sum << std::endl;

	//1.18
	int currVal = 0;
	val = 0;
	if (std::cin >> currVal) {
		int cnt = 1;
		while (std::cin >> val) {
			if (val == currVal) {
				cnt++;
			}
			else {
				std::cout << currVal << " occurs "
					<< cnt << " times" << std::endl;
				currVal = val;
				cnt = 1;
			}
		}
		std::cout << currVal << " occurs "
			<< cnt << " times" << std::endl;

	}
	
	

	return 0;
}