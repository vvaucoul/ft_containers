/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsList.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:14:57 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/24 19:18:35 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"

template <class T>
static void print_list(T &list)
{
	typename T::iterator it = list.begin();
	typename T::iterator it2;
	std::cout << "Size " << list.size() << " : ";
	while (it != list.end())
	{
		std::cout << *it;
		it2 = it;
		it2++;
		if (it2 != list.end())
			std::cout << " - ";
		it++;
	}
	std::cout << std::endl;
}

struct Greater {
    bool operator()(const int &a, const int &b) {return a < b;}
};

static void constructors(void)
{
	int test[] = {0, 1, 2, 3};
	ft::list<int> l1;
	std::list<int> l2;
	displayTest("(default) l1 == l2", l1 == l2);
	ft::list<int> l3((size_t)10);
	std::list<int> l4((size_t)10);
	displayTest("(fill with default value) l3 == l4", l3 == l4);
	ft::list<int> l5((size_t)10, 42);
	std::list<int> l6((size_t)10, 42);
	displayTest("(fill) l5 == l6", l5 == l6);
	ft::list<int> l7(test, test + 4);
	std::list<int> l8(test, test + 4);
	displayTest("(iterator) l7 == l8", l7 == l8);
	ft::list<int> l9(l7);
	std::list<int> l10(l8);
	displayTest("(copy) l9 == l10", l9 == l10);
}

static void copy_operator(void)
{
	int test[] = {0, 1, 2, 3};
	ft::list<int> l1(test, test + 4);
	std::list<int> l2(test, test + 4);
	ft::list<int> l3;
	std::list<int> l4;
	l3 = l1;
	l4 = l2;
	displayTest("l1 == l3", l1 == l3);
	displayTest("l2 == l4", l2 == l4);
	l1.push_back(1);
	l2.push_back(1);
	displayTest("l1 != l3", l1 != l3);
	displayTest("l2 != l4", l2 != l4);
}

static void max_size(void)
{
	ft::list<int> l1;
	std::list<int> l2;
	ft::list<std::string> l3;
	std::list<std::string> l4;
	displayTest("l1.max_size() == l2.max_size()", l1.max_size(), l2.max_size());
	displayTest("l3.max_size() == l4.max_size()", l3.max_size(), l4.max_size());
}

static void front_back(void)
{
	ft::list<int> l1;
	std::list<int> l2;
	displayTest("front == back", l1.front() == l1.back());
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	displayTest("l1.front() == l2.front()", l1.front(), l2.front());
	displayTest("l1.back() == l2.back()", l1.back(), l2.back());
}

static void assign(void)
{
	int test[4] = {0, 1, 2, 3};
	ft::list<int> l1;
	std::list<int> l2;
	l1.assign(test, (test + 4));
	l2.assign(test, test + 4);
	displayTest("l1 == l2", l1 == l2);
	l1.assign((size_t)10, 42);
	l2.assign((size_t)10, 42);
	displayTest("l1 == l2", l1 == l2);
}

static void push(void)
{
	ft::list<int> l1;
	std::list<int> l2;
	for (int _ = 0; _ < 100; _++)
	{
		if (rand() % 2)
		{
			int n = rand() % 100;
			l1.push_front(n);
			l2.push_front(n);
		}
		else
		{
			int n = rand() % 100;
			l1.push_back(n);
			l2.push_back(n);
		}
	}
	displayTest("l1 == l2", l1 == l2);
}

static void swap(void)
{
	ft::list<int> l1;
	std::list<int> l2;
	ft::list<int> l3;
	std::list<int> l4;
	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);
	l2.push_front(1);
	l2.push_front(2);
	l2.push_front(3);
	l3.push_front(42);
	l4.push_front(42);
	l1.swap(l3);
	l2.swap(l4);
	displayTest("l1 == l2", l1 == l2);
	displayTest("l3 == l4", l3 == l4);
}

static void resize(void)
{
	ft::list<int> l1;
	std::list<int> l2;
	l1.resize(10, 42);
	l2.resize(10, 42);
	displayTest("l1 == l2", l1 == l2);
	l1.resize(2, 42);
	l2.resize(2, 42);
	displayTest("l1 == l2", l1 == l2);
	l1.resize(0, 0);
	l2.resize(0, 0);
	displayTest("l1 == l2", l1 == l2);
	l1.resize(2, 42);
	l1.clear();
	l2.resize(2, 42);
	l2.clear();
	displayTest("l1 == l2", l1 == l2);
}

static void splice(void)
{
	ft::list<int> l1((size_t)10, 5);
	std::list<int> l2((size_t)10, 5);
	ft::list<int> l3((size_t)3, 0);
	std::list<int> l4((size_t)3, 0);
	l1.splice(++l1.begin(), l3);
	l2.splice(++l2.begin(), l4);
	displayTest("l1 == l2", l1 == l2);
	displayTest("l3 == l4", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin());
	l2.splice(l2.begin(), l4, ++l4.begin());
	displayTest("l1 == l2", l1 == l2);
	displayTest("l3 == l4", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin(), --l3.end());
	l2.splice(l2.begin(), l4, ++l4.begin(), --l4.end());
	displayTest("l1 == l2", l1 == l2);
	displayTest("l3 == l4", l3 == l4);
}

static bool even(const int& value) { return (value % 2) == 0; }

static void remove(void)
{
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.remove(0);
	l1.remove(5);
	l2.remove(0);
	l2.remove(5);
	displayTest("l1 == l2", l1 == l2);
	l1.remove_if(even);
	l2.remove_if(even);
	displayTest("l1 == l2", l1 == l2);
}

static void erase(void)
{
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.erase(l1.begin());
	l1.erase(--l1.end());
	l1.erase(--l1.end());
	l2.erase(l2.begin());
	l2.erase(--l2.end());
	l2.erase(--l2.end());
	displayTest("l1 == l2", l1 == l2);
	l1.erase(++l1.begin(), --l1.end());
	l2.erase(++l2.begin(), --l2.end());
	displayTest("l1 == l2", l1 == l2);
}

static bool compare(int a, int b)
{
    return (a >= b);
}

static void unique()
{
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.unique();
	l2.unique();
	displayTest("l1 == l2", l1 == l2);
	l1.assign(test, test + 14);
	l2.assign(test, test + 14);
	l1.unique(compare);
	l2.unique(compare);
	displayTest("l1 == l2", l1 == l2);
}

static bool compare2(int a, int b)
{
    return (a == b);
}

static void merge(void)
{
	int test[] = {1, 2, 3};
	int test2[] = {42, 43, 44};
	ft::list<int> l1(test, test + 3);
	std::list<int> l2(test, test + 3);
	ft::list<int> l3(test2, test2 + 3);
	std::list<int> l4(test2, test2 + 3);
	l1.merge(l3);
	l2.merge(l4);
	displayTest("l1 == l2", l1 == l2);
	displayTest("l3 == l4", l3 == l4);
	l1.assign(test, test + 3);
	l2.assign(test, test + 3);
	l3.assign(test2, test2 + 3);
	l4.assign(test2, test2 + 3);
	l1.merge(l3, compare2);
	l2.merge(l4, compare2);
	displayTest("l1 == l2", l1 == l2);
	displayTest("l3 == l4", l3 == l4);
}

static void reverse(void)
{
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.reverse();
	l2.reverse();
	displayTest("l1 == l2", l1 == l2);
}

static void operators(void)
{
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	ft::list<int> l3(l1);
	std::list<int> l4(l2);
	displayTest("l1 == l2", (l1 == l3), (l2 == l4));
	displayTest("l1 != l2", (l1 != l3), (l2 != l4));
	displayTest("l1 > l2", (l1 > l3), (l2 > l4));
	displayTest("l1 < l2", (l1 < l3), (l2 < l4));
	displayTest("l1 >= l2", (l1 >= l3), (l2 >= l4));
	displayTest("l1 <= l2", (l1 <= l3), (l2 <= l4));
	l1.push_back(42);
	l2.push_back(42);
	displayTest("l1 == l2", (l1 == l3), (l2 == l4));
	displayTest("l1 != l2", (l1 != l3), (l2 != l4));
	displayTest("l1 > l2", (l1 > l3), (l2 > l4));
	displayTest("l1 < l2", (l1 < l3), (l2 < l4));
	displayTest("l1 >= l2", (l1 >= l3), (l2 >= l4));
	displayTest("l1 <= l2", (l1 <= l3), (l2 <= l4));
	l3.push_back(42);
	l4.push_back(42);
	displayTest("l1 == l2", (l1 == l3), (l2 == l4));
	displayTest("l1 != l2", (l1 != l3), (l2 != l4));
	displayTest("l1 > l2", (l1 > l3), (l2 > l4));
	displayTest("l1 < l2", (l1 < l3), (l2 < l4));
	displayTest("l1 >= l2", (l1 >= l3), (l2 >= l4));
	displayTest("l1 <= l2", (l1 <= l3), (l2 <= l4));
}

int TestsList()
{

	displayHeader("LIST");
	std::srand(time(0));

	displayLittleHeader("Constructors");
	constructors();

	displayLittleHeader("Copy operators");
	copy_operator();

	displayLittleHeader("Max Size");
	max_size();

	displayLittleHeader("Front Back");
	front_back();

	displayLittleHeader("Assign");
	assign();

	displayLittleHeader("Push");
	push();

	displayLittleHeader("Swap");
	swap();

	displayLittleHeader("Resize");
	resize();

	displayLittleHeader("Splice");
	splice();

	displayLittleHeader("Remove");
	remove();

	displayLittleHeader("Erase");
	erase();

	displayLittleHeader("Unique");
	unique();

	displayLittleHeader("Merge");
	merge();

	displayLittleHeader("Reverse");
	reverse();

	displayLittleHeader("Operators");
	operators();
	return (0);
}
