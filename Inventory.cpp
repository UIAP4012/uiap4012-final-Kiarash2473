#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include <vector>
#include <chrono>
#include <ctime> 
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

class inventory
{
private:
	vector <product> products;
public:
	string invent_curr = "usd";
	double eur_to_usd = 1.09;
	double gbp_to_usd = 1.27;
	void update_currency(string new_currency)
	{
		for (ar x : new_currency)
			x = tolower(x);

		if (new_currency == "usd")
		{
			if (this->invent_curr == "usd")
				cout << "the currency was successfully exchanged." << endl;
			else if (this->invent_curr == "eur")
			{
				for (ar p : products)
				{
					p.set_price(p.get_price() * eur_to_usd);
				}
				cout << "the currency was successfully exchanged." << endl;
			}
			else if (this->invent_curr == "gbp")
			{
				for (ar p : products)
				{
					p.set_price(p.get_price() * gbp_to_usd);
				}
				cout << "the currency was successfully exchanged." << endl;
			}
			this->invent_curr = "usd";
		}
		else if (new_currency == "eur")
		{
			if (this->invent_curr == "eur")
				cout << "the currency was successfully exchanged." << endl;
			else if (this->invent_curr == "usd")
			{
				for (ar p : products)
				{
					p.set_price(p.get_price() / eur_to_usd);
				}
				cout << "the currency was successfully exchanged." << endl;
			}
			else if (this->invent_curr == "gbp")
			{
				for (ar p : products)
				{
					p.set_price(p.get_price() * gbp_to_usd / eur_to_usd);
				}
				cout << "the currency was successfully exchanged." << endl;
			}
			this->invent_curr = "eur";
		}
		else if (new_currency == "gbp")
		{
			if (this->invent_curr == "gbp")
				cout << "the currency was successfully exchanged." << endl;
			else if (this->invent_curr == "eur")
			{
				for (ar p : products)
				{
					p.set_price(p.get_price() / gbp_to_usd * eur_to_usd);
				}
				cout << "the currency was successfully exchanged." << endl;
			}
			else if (this->invent_curr == "usd")
			{
				for (ar p : products)
				{
					p.set_price(p.get_price() / gbp_to_usd);
				}
				cout << "the currency was successfully exchanged." << endl;
			}
			this->invent_curr = "gbp";
		}
		else
			cout << "No currency was found with this name." << endl;
	}

	void update_curr_ratio(string from, string to, double ratio)
	{
		for (ar x : from)
			x = tolower(x);
		for (ar x : to)
			x = tolower(x);

		if (from == "usd")
		{
			if (to == "usd")
				cout << "the source and destination currencies are the same." << endl;
			else if (to == "eur")
			{
				this->eur_to_usd = 1 / ratio;
				cout << "successfully updated." << endl;
			}
			else if (to == "gbp")
			{
				this->gbp_to_usd = 1 / ratio;
				cout << "successfully updated." << endl;
			}
			else
				cout << "invalid destination currency to update ratio." << endl;
		}
		else if (from == "eur")
		{
			if (to == "eur")
				cout << "the source and destination currencies are the same." << endl;
			else if (to == "usd")
			{
				this->eur_to_usd = ratio;
				cout << "successfully updated." << endl;
			}
			else
				cout << "invalid destination currency to update ratio." << endl;
		}
		else if (from == "gbp")
		{
			if (to == "gbp")
				cout << "the source and destination currencies are the same." << endl;
			else if (to == "usd")
			{
				this->gbp_to_usd = ratio;
				cout << "successfully updated." << endl;
			}
			else
				cout << "invalid destination currency to update ratio." << endl;
		}
		else
			cout << "invalid source currency to update ratio." << endl;
	}

	void add_product(product product)
	{
		bool found = false;
		for (ar p : products)
		{
			if (p.get_id() == product.get_id())
			{
				cout << "id is already exist." << endl;
				found = true;
				break;
			}
		}
		if (found == false)
		{
			products.push_back(product);
			cout << "Product added successfully." << endl;
			cout << "-----------------------------------------------------------" << endl;
		}
	}

	void remove_product(int id)
	{
		bool found = false;
		for (auto p = products.begin(); p != products.end(); p++)
		{
			if (p->get_id() == id)
			{
				products.erase(p);
				found = true;
				cout << "Product removed successfully." << endl;
				cout << "-----------------------------------------------------------" << endl;
				break;
			}
		}
		if (found == false)
		{
			cout << "id is not exist" << endl;
		}
	}

	product* find_product(int id)
	{
		for (ar p : products)
		{
			if (p.get_id() == id)
			{
				return &p;
			}
		}
		return nullptr;
	}

	bool update_product(int id, string name, int quantity, double price)
	{
		bool found = false;
		for (ar p : products)
		{
			if (p.get_id() == id)
			{
				p.set_name(name);
				p.set_quantity(quantity);
				p.set_price(price);
				found = true;
				//cout << "the product has been updated successfully." << endl;
				break;
			}
		}
		if (found == false)
		{
			cout << "Id does not exist." << endl;
		}
		return found;
	}

	void print_products()
	{
		for (ar p : products)
		{
			cout << "id : " << p.get_id() << "\t";
			cout << "name : " << p.get_name() << "\t";
			cout << "quantity : " << p.get_quantity() << "\t";
			if (this->invent_curr == "usd")
				cout << "price in dollar : " << p.get_price() << "\t";
			else if (this->invent_curr == "eur")
				cout << "price in euro : " << p.get_price() << "\t";
			else
				cout << "price in pound : " << p.get_price() << "\t";
			cout << endl;
		}
	}

	void save_inventory_in_file(string filename)
	{
		ofstream file;
		file.open(filename, ios::out | ios::app);
		for (int i = 0; i < products.size(); i++)
		{
			product p = products[i];
			file << p.get_id() << "," << p.get_name() << "," << p.get_quantity() << "," << p.get_price() << endl;
		}
		file.close();
	}

	void load_inventory_from_file(string filename)
	{
		ifstream file;
		file.open(filename, ios::in);

		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				stringstream ss(line);
				string id_str, name, price_str, quantity_str;
				getline(ss, id_str, ',');
				getline(ss, name, ',');
				getline(ss, quantity_str, ',');
				getline(ss, price_str, ',');

				int id = stoi(id_str);
				int quantity = stoi(quantity_str);
				double price = stod(price_str);

				product p(id, name, quantity, price);
				this->add_product(p);
			}

			file.close();
			cout << "Inventory loaded from file." << endl;
			cout << "-----------------------------------------------------------" << endl;
		}
		else
		{
			cout << "Can not open file " << filename << "." << endl;
			cout << "-----------------------------------------------------------" << endl;
		}
	}
};

class user_info
{
public:
	string username;
	string password;
};
class users_record
{
public:
	bool is_logged = false;

	void registration()
	{
		user_info k_user;
		cout << "Enter username : ";
		cin >> k_user.username;
		cout << "Enter password : ";
		cin >> k_user.password;

		ofstream file;
		file.open("registration.txt", ios::out | ios::app);
		if (!file)
		{
			cout << "registration.txt can not open." << endl;
		}
		else
		{
			file << k_user.username << "," << k_user.password << endl;
			file.close();
			is_logged = true;
			cout << "You are registered." << endl;
		}
	}

	void login(string current_username, string current_password)
	{
		int success = 0;
		ifstream file;
		file.open("registration.txt", ios::in);
		if (!file)
		{
			cout << "Unable to open registration.txt file for database. Try register." << endl;
		}
		else
		{
			string line;
			while (getline(file, line))
			{
				stringstream ss(line);
				string username, password;
				getline(ss, username, ',');
				getline(ss, password, ',');
				if (current_username == username && current_password == password) {
					success = 1;
					break;
				}
			}
			if (success == 1)
			{
				cout << "Login was successful." << endl;
				is_logged = true;
			}
			else
				cout << "Login was failed. Username or password was incorrect." << endl;

			file.close();
		}
	}
};

class factor
{
public:
	uint64_t factor_id;
	int products_num;
	int* products_id;
	int* products_quantity;

	factor(int* ps_id, int* ps_quantity, int ps_num)
	{
		const auto p1 = chrono::system_clock::now();
		this->factor_id = chrono::duration_cast<chrono::seconds>(p1.time_since_epoch()).count();
		products_num = ps_num;
		products_id = new int[products_num];
		products_quantity = new int[products_num];
		for (int i = 0; i < ps_num; i++)
		{
			this->products_id[i] = ps_id[i];
			this->products_quantity[i] = ps_quantity[i];
		}
	}

	void issue_factor(inventory& invent)
	{
		for (int i = 0; i < this->products_num; i++)
		{
			product* k_product = invent.find_product(this->products_id[i]);
			if (k_product == nullptr)
				cout << "Product with id " << this->products_id[i] << " does not found for issuing factor. Therefore, it was not included in the factor." << endl;
			else
			{
				invent.update_product(this->products_id[i], k_product->get_name(), k_product->get_quantity() - this->products_quantity[i], k_product->get_price());
				string filename = to_string(this->factor_id);
				filename.append(".csv");
				ofstream file;
				file.open(filename);
				if (i == 0)
					file << "factor id,product id,product name,factor quantity,product price\n";
				file << this->factor_id << "," << this->products_id[i] << "," << k_product->get_name() << "," << this->products_quantity[i] << "," << k_product->get_price() << "\n";
				file.close();

				ofstream k_file;
				k_file.open("all factor issued history.txt", ios::out | ios::app);
				k_file << "factor id : " << this->factor_id << "\tproduct id : " << this->products_id[i] << "\tproduct name : " << k_product->get_name() << "\tfactor quantity : " << this->products_quantity[i] << "\tproduct price : " << k_product->get_price() << endl;
			}
		}
		cout << "your factor has been issued successfully." << endl;
	}
};

int main()
{
	cout << "Welcome to Inventory Management program written by Kiarash Gilanian" << endl;
	cout << "___________________________________________________________________" << endl << endl;

	inventory invent;
	users_record current_user;

	cout << "Choose one of the following options by entering its number ( Some options require login or registration before doing. ) :" << endl;
	cout << "0 : Exit . " << endl;
	cout << "1 : Add a product to inventory. ( Requires login or registration )" << endl;
	cout << "2 : Remove a product from inventory. ( Requires login or registration )" << endl;
	cout << "3 : Find a product." << endl;
	cout << "4 : Update a product. ( Requires login or registration )" << endl;
	cout << "5 : View all products." << endl;
	cout << "6 : Save inventory to file." << endl;
	cout << "7 : Load Inventory from file. ( Requires login or registration )" << endl;
	cout << "8 : Issue a factor. ( Requires login or registration )" << endl;
	cout << "9 : Login." << endl;
	cout << "10 : Register." << endl;
	cout << "11 : Update base currency of inventory." << endl;
	cout << "12 : Update exchange rate of currencies. ( Requires login or registration )" << endl;
	cout << "13 : Logout." << endl;

	int order_num;
	cin >> order_num;

	return 0;
}
