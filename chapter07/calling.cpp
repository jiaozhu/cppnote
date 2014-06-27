#include "iostream"

void simple();	//函数原型

int main(int argc, char const *argv[])
{
	

	using namespace std;

	cout << "main() will call the simple() function:\n";
	simple(); //函数调用

	return 0;
}

/*
* 函数定义
*/
void simple(){
	using namespace std;

	cout << "I'm but a simple function.\n";
}