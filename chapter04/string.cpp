#include "iostream"
#include "cstring"

int main(int argc, char const *argv[])
{
	
	using namespace std;

	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	cout << "Howdy! I'm " << name2 << "! What's your name ?" << endl;
	cin >> name1;
	cout << "Well, " << name1 << ",your name has ";
	cout << strlen(name1)  << " letters and is stored.\n"; // strlen 只计算可见的字符
	cout << "in an array of " << sizeof(name1) << " bytes.\n"; //sizeof 指出数组的长度
	cout << "Your initial is " << name1[0] << ".\n";
	name2[3] = '\0';
	cout << "Here are the first 3 character of my name: ";
	cout << name2 << endl;

	return 0;
}