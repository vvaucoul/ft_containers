/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsVector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:00:24 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/25 19:52:04 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Tests.hpp"

static void constructor()
{
	{
		ft::vector<int> v1;
		std::vector<int> v2;
		ft::vector<int> v3(v1);
		std::vector<int> v4(v2);

		//displayInfo("DEFAULT CONSTRUCTOR");
		displayTest("v1 == v2", v1 == v2);
		//displayInfo("COPY CONSTRUCTOR");
		displayTest("v3 == v4", v3 == v4);
		//displayInfo("ADD DATA");
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		displayTest("v1 == v2", v1 == v2);
		displayTest("v3 == v4", v3 == v4);
	}
	{
		ft::vector<std::string> v1;
		std::vector<std::string> v2;
		ft::vector<std::string> v3(v1);
		std::vector<std::string> v4(v2);

		//displayInfo("Init 2 string vector");
		displayTest("Empty constructor", v1 == v2);
		displayTest("Copy constructor", v3 == v4);
		//displayInfo("push back strings");
		v1.push_back("1");
		v1.push_back("2");
		v1.push_back("3");
		v2.push_back("1");
		v2.push_back("2");
		v2.push_back("3");
		displayTest("Check after Push_Back", v1 == v2);
		displayTest("Check after Push_Back", v3 == v4);
	}
	{
		ft::vector<int> v1;
		std::vector<int> v2;
		ft::vector<int> v3(v1);
		std::vector<int> v4(v2);

		//displayInfo("COPY CONSTRUCTOR");
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		displayTest("v1 == v2 [1]", v1 == v2);
		displayTest("v3 == v4 [2]", v3 == v4);
		displayTest("v1 != v3 [3]", v1 != v3);
		displayTest("v2 != v4 [4]", v2 != v4);
	}
	{
		ft::vector<std::string> v1;
		std::vector<std::string> v2;
		ft::vector<std::string> v3(v1);
		std::vector<std::string> v4(v2);

		//displayInfo("COPY CONSTRUCTOR");
		displayTest("Check after Push_Back", v1 == v2);
		displayTest("Check after Push_Back", v3 == v4);
		v1.push_back("1");
		v1.push_back("2");
		v1.push_back("3");
		v2.push_back("1");
		v2.push_back("2");
		v2.push_back("3");
		displayTest("Copy constructor [1]", v1 == v2);
		displayTest("Copy constructor [2]", v3 == v4);
		displayTest("Copy constructor [3]", v1 != v3);
		displayTest("Copy constructor [4]", v2 != v4);
	}
}

static void maxSize()
{
	{
		ft::vector<std::string> v1;
		std::vector<std::string> v2;

		//displayInfo("MAX SIZE (string)");
		displayTest("v1.max_size() == v2.max_size()", v1.max_size() == v2.max_size());
		v1.push_back("42born2code");
		v2.push_back("42born2code");
		//displayInfo("ADD DATA / MAX SIZE");
		displayTest("v1.max_size() == v2.max_size()", v1.max_size() == v2.max_size());
	}
	{
		ft::vector<int> v1;
		std::vector<int> v2;

		//displayInfo("MAX SIZE (int)");
		displayTest("v1.max_size() == v2.max_size()", v1.max_size() == v2.max_size());
		v1.push_back(42);
		v2.push_back(42);
		//displayInfo("ADD DATA / MAX SIZE");
		displayTest("v1.max_size() == v2.max_size()", v1.max_size() == v2.max_size());
	}
	{
		ft::vector<int> v1;
		std::vector<int> v2;
		displayTest("v1.size() == v2.size()", v1.size() == v2.size());
		for (size_t i = 0; i < 24; i++) {
			v1.push_back(i);
			v2.push_back(i);
		}
		displayTest("v1.size() == v2.size()", v1.size() == v2.size());
	}
	{
		ft::vector<std::string> v1;
		std::vector<std::string> v2;
		displayTest("v1.size() == v2.size()", v1.size() == v2.size());
		for (size_t i = 0; i < 24; i++) {
			v1.push_back("test");
			v2.push_back("test");
		}
		displayTest("v1.size() == v2.size()", v1.size() == v2.size());
	}
}

static void assign()
{
	{
		ft::vector<std::string> v1;
		std::vector<std::string> v2;

		std::string test[] = {"42", "born", "to", "code"};

		//displayInfo("ASSIGN ITERATORS [STRING]");
		v1.assign(test, test + 4);
		v2.assign(test, test + 4);
		displayTest("v1 == v2", v1 == v2);
		//displayInfo("ASSIGN VALUES");
		v1.assign(10, "42born2code");
		v2.assign(10, "42born2code");
		displayTest("v1 == v2", v1 == v2);
		//displayInfo("ASSIGN VALUES WITH ELEMENTS [0]");
		v1.assign(0, "42born2code");
		v2.assign(0, "42born2code");
		displayTest("v1 == v2", v1 == v2);
		//displayInfo("ASSIGN VALUES WITH ELEMENTS [-5]");
		try
		{
			v1.assign(-5, "42born2code");
		}
		catch (std::exception &error)
		{
			std::cout << RED;
			std::cerr << "ft::vector : ";
			std::cerr << error.what();
			std::cout << GREEN << "               " GOOD << '\n';
			std::cout << RESET;
		}

		try
		{
			v2.assign(-5, "42born2code");
		}
		catch (std::exception &error)
		{
			std::cout << RED;
			std::cerr << "std::vector : ";
			std::cerr << error.what();
			std::cout << GREEN << "              " GOOD << '\n';
			std::cout << RESET;
		}
	}
	{
		ft::vector<size_t> v1;
		std::vector<size_t> v2;

		size_t test[] = {42, 22, 11, 5, 2, 1};

		//displayInfo("ASSIGN ITERATORS [INT]");
		v1.assign(test, test + 6);
		v2.assign(test, test + 6);
		displayTest("v1 == v2", v1 == v2);
		//displayInfo("ASSIGN VALUES");
		v1.assign(10, (size_t)2);
		v2.assign(10, (size_t)2);
		displayTest("v1 == v2", v1 == v2);
		//displayInfo("ASSIGN VALUES WITH ELEMENTS [0]");
		v1.assign(0, (size_t)42);
		v2.assign(0, (size_t)42);
		displayTest("v1 == v2", v1 == v2);
		//displayInfo("ASSIGN VALUES WITH ELEMENTS [-5]");
		try
		{
			v1.assign(-5, (size_t)42);
		}
		catch (std::exception &error)
		{
			std::cout << RED;
			std::cerr << "ft::vector : ";
			std::cerr << error.what();
			std::cout << GREEN << "               " GOOD << '\n';
			std::cout << RESET;
		}

		try
		{
			v2.assign(-5, (size_t)42);
		}
		catch (std::exception &error)
		{
			std::cout << RED;
			std::cerr << "std::vector : ";
			std::cerr << error.what();
			std::cout << GREEN << "              " GOOD << '\n';
			std::cout << RESET;
		}
	}
}

static void accessOperator()
{
	{
		ft::vector<size_t> v1;
		std::vector<size_t> v2;

		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);

		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);

		displayTest("v1 == v2", v1 == v2);
		displayTest("v1[0] == v2[0]", v1[0] == v2[0]);
		displayTest("v1[1] == v2[1]", v1[1] == v2[1]);
		displayTest("v1[2] == v2[2]", v1[2] == v2[2]);

		try
		{
			std::cout << CYAN;
			std::cout << "v1.at(100) : " << v1.at(100) << "\n";
		}
		catch (std::exception &error)
		{
			std::cout << RED;
			std::cerr << "ft::vector : ";
			std::cerr << error.what() << '\n';
			std::cout << RESET;
		}
		try
		{
			std::cout << CYAN;
			std::cout << "v2.at(100) : " << v2.at(100) << "\n";
		}
		catch (std::exception &error)
		{
			std::cout << RED;
			std::cerr << "vector : ";
			std::cerr << error.what() << '\n';
			std::cout << RESET;
		}

		try
		{
			std::cout << CYAN;
			std::cout << "v1.at(-1) : " << v1.at(-1) << "\n";
		}
		catch (std::exception &error)
		{
			std::cout << RED;
			std::cerr << "ft::vector : ";
			std::cerr << error.what() << '\n';
			std::cout << RESET;
		}
		try
		{
			std::cout << CYAN;
			std::cout << "v2.at(-1) : " << v2.at(-1) << "\n";
		}
		catch (std::exception &error)
		{
			std::cout << RED;
			std::cerr << "vector : ";
			std::cerr << error.what() << '\n';
			std::cout << RESET;
		}
	}
}

static void resize()
{
	{
		ft::vector<int> v1;
		std::vector<int> v2;

		for (size_t i = 0; i < 10; i++) {
			v1.push_back(i);
			v2.push_back(i);
		}
		displayTest("v1 == v2", v1 == v2);
		v1.resize(10, 4);
		v2.resize(10, 4);
		displayTest("v1 == v2", v1 == v2);
		v1.resize(0, 4);
		v2.resize(0, 4);
		displayTest("v1 == v2", v1 == v2);
		v1.resize(0, 0);
		v2.resize(0, 0);
		displayTest("v1 == v2", v1 == v2);
		v1.resize(100, 100);
		v2.resize(100, 100);
		displayTest("v1 == v2", v1 == v2);
	}
}

static void frontBack()
{
	{
		ft::vector<int> v1;
		std::vector<int> v2;

		for (size_t i = 0; i < 100; i++) {
			v1.push_back(i);
			v2.push_back(i);
		}
		displayTest("v1 == v2", v1 == v2);
		displayTest("v1.front() == v2.front()", v1.front() == v2.front());
		displayTest("v1.back() == v2.back()", v1.back() == v2.back());
		for (size_t i = 0; i < 100; i++) {
			v1.push_back(i);
			v2.push_back(i);
		}
		displayTest("v1 == v2", v1 == v2);
		displayTest("v1.front() == v2.front()", v1.front() == v2.front());
		displayTest("v1.back() == v2.back()", v1.back() == v2.back());
	}
}

static void insert()
{
	{

		ft::vector<size_t> v1;
		std::vector<size_t> v2;

		for (size_t i = 0; i < 42; i++) {
			v1.insert(v1.begin(), i);
			v2.insert(v2.begin(), i);
		}
		displayTest("v1 == v2", v1 == v2);




		for (size_t i = 0; i < 42; i++) {
			v1.insert(v1.end(), i);
			v2.insert(v2.end(), i);
		}
		displayTest("v1 == v2", v1 == v2);

		v1.clear();
		v2.clear();

		for (size_t i = 0; i < 42; i++) {
			v1.insert(v1.end(), i);
			v2.insert(v2.end(), i);
		}
		displayTest("v1 == v2", v1 == v2);
	}
	{
		size_t test[] = {42, 22, 11, 5, 2, 1};

		ft::vector<size_t> v1;
		std::vector<size_t> v2;

		v1.insert(v1.begin(), test, test + 6);
		v2.insert(v2.begin(), test, test + 6);
		displayTest("v1 == v2", v1 == v2);
	}
	{
		size_t test[] = {42, 22, 11, 5, 2, 1};

		ft::vector<size_t> v1;
		std::vector<size_t> v2;

		v1.insert(v1.end(), test, test + 6);
		v2.insert(v2.end(), test, test + 6);
		displayTest("v1 == v2", v1 == v2);
	}
	{
		size_t test[] = {42, 22, 11, 5, 2, 1};

		ft::vector<size_t> v1;
		std::vector<size_t> v2;

		v1.insert(v1.end(), test, test + 1);
		v2.insert(v2.end(), test, test + 1);
		displayTest("v1 == v2", v1 == v2);
	}
	{
		ft::vector<size_t> v1;
		std::vector<size_t> v2;

		v1.insert(v1.begin(), (size_t)10, (size_t)4);
		v2.insert(v2.begin(), (size_t)10, (size_t)4);
		displayTest("v1 == v2", v1 == v2);
	}
	{
		ft::vector<size_t> v1;
		std::vector<size_t> v2;

		v1.insert(v1.end(), (size_t)10, (size_t)4);
		v2.insert(v2.end(), (size_t)10, (size_t)4);
		displayTest("v1 == v2", v1 == v2);
	}
}

static void erase()
{
	{
		size_t test[] = {42, 22, 11, 5, 2, 1};

		ft::vector<size_t> v1;
		std::vector<size_t> v2;

		for (size_t i = 0; i < 42; i++) {
			v1.push_back(i);
			v2.push_back(i);
		}
		v1.erase(v1.begin(), v1.end());
		v2.erase(v2.begin(), v2.end());
		displayTest("v1 == v2", v1 == v2);

		v1.insert(v1.begin(), test, test + 6);
		v2.insert(v2.begin(), test, test + 6);

		v1.erase(v1.begin());
		v2.erase(v2.begin());
		displayTest("v1 == v2", v1 == v2);

		v1.insert(v1.end(), test, test + 6);
		v2.insert(v2.end(), test, test + 6);

		try
		{
			v1.erase(v1.end());
			std::cout << RED << "                               " FAIL << '\n';
		}
		catch (std::exception &error)
		{
			std::cout << RED;
			std::cout << error.what();
			std::cout << GREEN << "                               " GOOD << '\n';
		}
		try
		{
			std::cout << RED << "Real std::vector : segfault";
			std::cout << GREEN << "               " GOOD << '\n';
		}
		catch (std::exception &error)
		{
			std::cout << error.what() << '\n';
		}
		displayTest("v1 == v2", v1 == v2);

	}
}

static void swap()
{
	{
		ft::vector<size_t> v1;
		std::vector<size_t> v2;
		ft::vector<size_t> v3;
		std::vector<size_t> v4;

		for (size_t i = 0; i < 42; i++) {
			v1.push_back(i);
			v2.push_back(i);
		}
		v1.swap(v3);
		v2.swap(v4);
		displayTest("v1 == v2", v1 == v2);
		displayTest("v3 == v4", v3 == v4);
	}
	{
		ft::vector<size_t> v1;
		std::vector<size_t> v2;
		ft::vector<size_t> v3;
		std::vector<size_t> v4;

		for (size_t i = 0; i < 42; i++) {
			v3.push_back(i);
			v4.push_back(i);
		}
		v3.swap(v1);
		v4.swap(v2);
		displayTest("v1 == v2", v1 == v2);
		displayTest("v3 == v4", v3 == v4);
	}
}

static void operators()
{
	{
		ft::vector<size_t> v1;
		std::vector<size_t> v2;
		ft::vector<size_t> v3;
		std::vector<size_t> v4;


		for (size_t i = 0; i < 42; i++) {
			v1.push_back(i);
			v2.push_back(i);
		}

		displayTest("v1 == v2", (v1 == v3), (v2 == v4));
		displayTest("v1 != v2", (v1 != v3), (v2 != v4));
		displayTest("v1 >= v2", (v1 >= v3), (v2 >= v4));
		displayTest("v1 > v2", (v1 > v3), (v2 > v4));
		displayTest("v1 <= v2", (v1 <= v3), (v2 <= v4));
		displayTest("v1 < v2", (v1 < v3), (v2 < v4));

		v3 = v1;
		v4 = v2;


		displayTest("v1 == v2", (v1 == v3), (v2 == v4));
		displayTest("v1 != v2", (v1 != v3), (v2 != v4));
		displayTest("v1 >= v2", (v1 >= v3), (v2 >= v4));
		displayTest("v1 > v2", (v1 > v3), (v2 > v4));
		displayTest("v1 <= v2", (v1 <= v3), (v2 <= v4));
		displayTest("v1 < v2", (v1 < v3), (v2 < v4));

		for (size_t i = 0; i < 42; i++) {
			v1.push_back(i);
			v2.push_back(i);
		}

		displayTest("v1 == v2", (v1 == v3), (v2 == v4));
		displayTest("v1 != v2", (v1 != v3), (v2 != v4));
		displayTest("v1 >= v2", (v1 >= v3), (v2 >= v4));
		displayTest("v1 > v2", (v1 > v3), (v2 > v4));
		displayTest("v1 <= v2", (v1 <= v3), (v2 <= v4));
		displayTest("v1 < v2", (v1 < v3), (v2 < v4));

	}
}

int TestsVector()
{
	displayHeader("VECTOR");

	displayLittleHeader("Constructor");
	constructor();

	displayLittleHeader("Size / Max Size");
	maxSize();

	displayLittleHeader("Assign");
	assign();

	displayLittleHeader("Access Operator");
	accessOperator();

	displayLittleHeader("Resize");
	resize();

	displayLittleHeader("Front / Back");
	frontBack();

	displayLittleHeader("Insert");
	insert();

	displayLittleHeader("Erase");
	erase();

	displayLittleHeader("Swap");
	swap();

	displayLittleHeader("Operators");
	operators();

	return (0);
}
