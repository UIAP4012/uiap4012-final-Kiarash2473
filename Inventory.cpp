#include <iostream>
#include <string>
#include<sstream>
using namespace std;

#define ar auto &

class product
{
private:
	int id;
	string name;
	int quantity;
	double price;

public:
	product(const int& k_id, const string& k_name, const int& k_quantity, const double& k_price)
	{
		id = k_id;
		name = k_name;
		quantity = k_quantity;
		price = k_price;
	}

	void set_id(int k_id)
	{
		this->id = k_id;
	}
	void set_name(string k_name)
	{
		this->name = k_name;
	}
	void set_quantity(int k_quantity)
	{
		this->quantity = k_quantity;
	}
	void set_price(double k_price)
	{
		this->price = k_price;
	}
	int get_id()
	{
		return this->id;
	}
	string get_name()
	{
		return this->name;
	}
	int get_quantity()
	{
		return this->quantity;
	}
	double get_price()
	{
		return this->price;
	}
};

int main()
{
	
	return 0;
}
