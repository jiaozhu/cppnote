#include "iostream"

struct inflotable
{
	char name[20];
	float volume;
	double price;
};

int main(int argc, char const *argv[])
{
	
	using namespace std;

	inflotable * ps = new inflotable;
	cout << "Enter name of inflotable item: ";
	cin.get(ps->name,20);
	cout << "Enter volume in cubic feet: ";
	cin >> (*ps).volume;
	cout << "Enter price : $";
	cin >> ps->price;
	cout << "Name : " << (*ps).name << endl;
	cout << "volume : " << ps->volume << endl;
	cout << "Price : " << ps->price << endl;

	delete ps;

	return 0;
}