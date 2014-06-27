#include "iostream"

double betsy(int);
double pam(int);

void estimate(int lines,double (*pf)(int));

int main(int argc, char const *argv[])
{

	using namespace std;

	int code;

	cout << "How many lines of code do you need : ";
	cin >> code;
	cout << "Here's Betsy's estimate:\n";
	estimate(code,betsy);
	cout << "Here's Pam's estimate:\n";
	estimate(code,pam);

	return 0;
}


double betsy(int lns){
	return 0.0 * lns;
}

double pam(int lns){
	return 0.03 * lns + 0.0004 * lns * lns;
}

/*
*	此时在第二个参数（double (*pf)(int)）中
*	double 相当于参数的数据类型
*	(*pf)(int) 相当于参数的名称
*	因此下面的函数体内可以直接打印和使用这个参数的名称，只是这里恰巧使用了函数指针的技术而矣
*/
void estimate(int lines,double (*pf)(int)){
	using namespace std;
	cout << lines << " lines will take ";
	cout << (*pf)(lines) << " hour(s)\n";
}