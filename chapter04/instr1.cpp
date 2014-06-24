#include "iostream"

int main(int argc, char const *argv[])
{
	
	using namespace std;

	const int ArSize = 20;
	char name[ArSize]; 	//字符串数组
	char dessert[ArSize];

	cout << "Enter your name :\n";
	cin >> name; //cin 使用空白（空格、制表符和换行符）来确定字符串的结束位置
	cout << "Enter your favorite dessert:\n";
	cin >> dessert;
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << endl;

	return 0;
}