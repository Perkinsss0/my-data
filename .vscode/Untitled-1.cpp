#include<iostream>
using namespace std;

int main() {
	//乘法口诀表
	//打印行数
	for (int i = 1; i <= 9;i++)
	{
		//cout << i << endl;
		for (int j = 1; j <= i; j++)
		{
			cout << j << "*" << i <<"="<< j * i << "  ";
		}
		cout << endl;
	}
	system("pause");

	return 0;
}