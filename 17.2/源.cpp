#include<bitset>
#include<iostream>
using namespace std;

const int ansSum = 10;
struct ans
{
	int oneAns[ansSum];
};

ans Ans;

void change(int index, bool ans)
{
	Ans.oneAns[index] = ans;
}



int main()
{
	bitset<22>sa;
	sa.set(1);
	sa.set(2);
	sa.set(3);
	sa.set(5);
	sa.set(8);
	sa.set(13);
	sa.set(21);
	bitset<23>sb;

	int now = 1000110;
	int nowIndex = 0;
	while (now != 0)
	{
		int temp = now % 10;
		if (temp == 1) {
			change(nowIndex, true);
		}
		else {
			change(nowIndex, false);
		}
		nowIndex++;
		now /= 10;
	}

	for (int i = 0; i < ansSum; i++)
	{
		cout << Ans.oneAns[i];
	}
	cout << endl;

	return 0;
}