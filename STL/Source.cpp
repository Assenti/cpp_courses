#define _CRT_SECURE_NO_WARNINGS
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include "Bus.h"
#include "Child.h"
using namespace std;
void update(int &i)
{
	i += 2;
}

//bool compare(Bus & bus1, Bus & bus2)
//{
//	return bus1.getX() > bus2.getX() && bus2.getY() > bus2.getY();
//}

bool compare(Child & child1, Child & child2)
{
	if (child1.age < child2.age)
		return true;
	else if (child1.age == child2.age)
		if (child1.height < child2.height)
			return true;
		else
			return false;
	else
		return false;
}

int calculate(const int & a, const int & b, int(*operation)(const int&, const int&))
{ 
	return operation(a, b); 
}

int main()
{
	std::map<std::string, int> data{
		{"Bob", 30},
		{"Jim", 25},
		{"Ken", 27},
		{"Ben", 20},
		{"Kelly", 21}
	};
	/*for (auto i : data)
		if (i.second > 25)
			std::cout << i.first << std::endl;

	vector<int> numbers = { 1,5,3,4,77,6,7,8,9,99 };
	sort(numbers.begin(), numbers.end());
	for (auto i : numbers)
		cout << i << ' ';
	cout << endl;
	for_each(numbers.begin(), numbers.end(), update);
	for (auto i : numbers)
		cout << i << ' ';
	cout << endl;*/
	
	/*vector<Bus> buses;
	buses.push_back(Bus(5, 5));
	buses.push_back(Bus(7, 4));
	buses.push_back(Bus(10, 8));
	buses.push_back(Bus(3, 4));
	buses.push_back(Bus(7, 12));

	sort(buses.begin(), buses.end(), compare);
	for (auto bus : buses)
		if (bus.getX() < 5 && bus.getY() < 5)
			cout << "BINGO!" << bus.getX() << " and " << bus.getY() << endl;*/

	/*vector<Child> children;
	children.push_back(Child("Benny", 5, 120, 40));
	children.push_back(Child("Jimmy", 5, 115, 43.5));
	children.push_back(Child("Johny", 9, 138.8, 55));
	children.push_back(Child("Katy", 3, 110.5, 35));
	children.push_back(Child("Larry", 7, 130, 50));
	children.push_back(Child("Peter", 4, 118, 53));
	

	//Sort
	sort(children.begin(), children.end(), compare);
	for (auto i : children)
		cout << i.name << ' ' << i.height << ' ' << i.weight << ' ' << i.age << endl;
	
	//Min_element
	auto minny = min_element(children.begin(), children.end(), compare);
	cout << minny->name << endl;
	
	//Max_element
	auto maxy = max_element(children.begin(), children.end(), compare);
	cout << maxy->name << endl;

	double wanted_height = 115;

	//Find_if
	auto wanted = find_if(children.begin(), children.end(), [wanted_height](Child & c)
	{
		return c.height == wanted_height;
	});

	cout << wanted->name << endl;
	
	//Count_if
	cout << count_if(children.begin(), children.end(), [wanted_height](Child c)
	{
		int cnt = 0;
		if (c.height >= wanted_height)
				cnt++;
		return cnt;
	});
	cout << endl;

	cout << "------------------------------" << endl;

	//Reverse
	reverse(children.begin(), children.end());
	for (auto i : children)
		cout << i.name << ' ' << i.height << ' ' << i.weight << ' ' << i.age << endl;


	cout << "------------------------------" << endl;

	//Random_shuffle
	random_shuffle(children.begin(), children.end());
	for (auto i : children)
		cout << i.name << ' ' << i.height << ' ' << i.weight << ' ' << i.age << endl;

	cout << "------------------------------" << endl;

	//Partition
	int wanted_age = 5;
	vector<Child>::iterator bound = partition(children.begin(), children.end(), [wanted_age](Child & c) 
	{
		return c.age < wanted_age;
	});

	for (auto it = children.begin(); it != bound; ++it)
		cout << it->age << endl;

	//Is_sorted
	cout << is_sorted(children.begin(), children.end(), compare) << endl;
	sort(children.begin(), children.end(), compare);
	cout << is_sorted(children.begin(), children.end(), compare) << endl;*/

	int a, b;
	char o;
	std::unordered_map<char, int(*)(const int &, const int&)>operations;
	operations.insert(std::make_pair('+', [](const int& a, const int& b) { return a + b; }));
	operations.insert(std::make_pair('-', [](const int& a, const int& b) { return a - b; }));
	
	std::string s;
	std::getline(std::cin, s);
	char * symbols = new char[s.length()];
	for (int i = 0; i < s.length(); i++) symbols[i] = s[i];
	std::queue<int> operands;
	std::queue<char> operators;
	const char * c = strtok(symbols, " ");
	while (c != NULL)
	{
		if (isdigit(*c))
		{
			std::cout << "int: " << *c << std::endl;
			operands.push((int)(*c - 48));
		}
		else
		{
			std::cout << "char: " << *c << std::endl;
			operators.push(*c);
		}
		c = strtok(NULL, " ");
	}
	/*std::cin >> a >> o;
	std::cout << calculate(a, b, operations[0]) << std::endl;
	while (o != '=')
	{
		std::cin >> b;
		a = calculate(a, b, operations[o]);
		std::cin >> o;
	}
	
	std::cout << a << std::endl;*/
	
	a = operands.front();
	operands.pop();
	while (!operands.empty() && !operators.empty())
	{
		b = operands.front();
		o = operators.front();
		a = calculate(a, b, operations[o]);
		operands.pop();
		operators.pop();
	}
	std::cout << a << std::endl;
	

	delete[] symbols;
	system("pause");
	return 0;
}