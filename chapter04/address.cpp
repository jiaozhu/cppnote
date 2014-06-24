#include "iostream"

int main(int argc, char const *argv[])
{
	
	using namespace std;

	int donuts = 6;
	double cpus = 4.5;

	cout << "donuts value = " << donuts;
	cout << " and donuts address = " << &donuts << endl;

	cout << "cpus value = " << cpus << " and cpus address = " << &cpus << endl;

	return 0;
}