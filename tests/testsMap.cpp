/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsMap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:19:16 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/24 19:21:03 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tests.hpp"
#include <utility>

template <class T>
static void print_map(T &map)
{
	typename T::iterator it = map.begin();
	std::cout << " --- Map of size " << map.size() << " ---" << std::endl;
	while (it != map.end())
	{
		std::cout << it->first << ": " << it->second << std::endl;
		++it;
	}
	std::cout << " --- " << std::endl;
}

static void constructors(void)
{
	displayLittleHeader("Constructors / Copy");
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::map<int, int> m1;
	std::map<int, int> m2;
	displayTest("(default) m1 == m2", (m1 == m2));
	ft::map<int, int> m3(a, a + 3);
	std::map<int, int> m4(a, a + 3);
	std::cout << "end" << '\n';
	displayTest("(range) m3 == m4", (m3 == m4));
	ft::map<int, int> m5(m3);
	std::map<int, int> m6(m4);
	displayTest("(copy) m5 == m6", (m3 == m4));
	ft::map<int, int> m7;
	std::map<int, int> m8;
	m7[0] = 1;
	m7[1] = 2;
	m7[2] = 3;
	m8[0] = 1;
	m8[1] = 2;
	m8[2] = 3;
	print_map(m7);
	print_map(m8);
	std::cout << (++m7.begin())->second << std::endl;
	ft::map<int, int>::iterator it = m7.begin();
	while (it != m7.end())
	{
		ft::map<int, int>::iterator it2 = m7.find(it->first);
		std::cout << it.node()->pair.second << std::endl;
		std::cout << it->first << "=" << it2->second << std::endl;
		++it;
	}
	displayTest("(copy) m7 == m8", (m7 == m8));
	ft::map<int, int> m9;
	std::map<int, int> m10;
	m9 = m7;
	m10 = m8;
	displayTest("(copy) m9 == m10", (m9 == m10));
}

static void max_size(void)
{
	displayLittleHeader("Size");
	ft::map<int, int> m1;
	std::map<int, int> m2;
	displayTest("m1.max_size() == m2.max_size()", m1.max_size(), m2.max_size());
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	displayTest("m3.max_size() == m4.max_size()", m3.max_size(), m4.max_size());
}

static void access_operator(void)
{
	displayLittleHeader("[] operator");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 0;
	m1["c"] = 42;
	m1["d"] = -5;
	m1["d"] = 11;
	m1["test"] = 100;
	m2["a"] = 1;
	m2["b"] = 0;
	m2["c"] = 42;
	m2["d"] = -5;
	m2["d"] = 11;
	m2["test"] = 100;
	displayTest("m1 == m2", m1 == m2);
	displayTest("m1['a'] == m2['a']", m1["a"], m2["a"]);
	displayTest("m1['d'] == m2['d']", m1["d"], m2["d"]);
	displayTest("m1['test'] == m2['test']", m1["test"], m2["test"]);
	displayTest("m1['z'] == m2['z']", m1["z"], m2["z"]);
}

static void insert(void)
{
	displayLittleHeader("Insert");
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::map<int, int> m1(a, a + 3);
	std::map<int, int> m2(a, a + 3);
	m1.insert(++m1.begin(), std::make_pair(5, 5));
	m2.insert(++m2.begin(), std::make_pair(5, 5));
	displayTest("m1 == m2", m1 == m2);
	m1.insert(std::make_pair(5, 0));
	m2.insert(std::make_pair(5, 0));
	m1.insert(std::make_pair(10, 54));
	m2.insert(std::make_pair(10, 54));
	displayTest("m1 == m2", m1 == m2);
}

static void erase(void)
{
	displayLittleHeader("Erase");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["test"] = 1;
	m1["a"] = 2;
	m1["b"] = 3;
	m1["c"] = 4;
	m1["d"] = 6;
	m1["e"] = 8;
	m2["test"] = 1;
	m2["a"] = 2;
	m2["b"] = 3;
	m2["c"] = 4;
	m2["d"] = 6;
	m2["e"] = 8;
	displayTest("m1 == m2", m1 == m2);
	m1.erase(++m1.begin());
	m2.erase(++m2.begin());
	displayTest("m1 == m2", m1 == m2);
	m1.erase(++m1.begin(), --m1.end());
	m2.erase(++m2.begin(), --m2.end());
	displayTest("m1 == m2", m1 == m2);
	m1.erase("a");
	m2.erase("a");
	displayTest("m1 == m2", m1 == m2);
}

static void swap(void)
{
	displayLittleHeader("Swap");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	m1["a"] = 1;
	m1["b"] = 2;
	m1["c"] = 3;
	m2["a"] = 1;
	m2["b"] = 2;
	m2["c"] = 3;
	m3["a"] = 42;
	m3["b"] = 21;
	m4["a"] = 42;
	m4["b"] = 21;
	m1.swap(m3);
	m2.swap(m4);
	displayTest("m1 == m2", m1 == m2);
	displayTest("m3 == m4", m3 == m4);
	/*
	*/
}

static void clear(void)
{
	displayLittleHeader("Clear");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m1.clear();
	m2.clear();
	displayTest("m1 == m2", m1 == m2);
}

static void find(void)
{
	displayLittleHeader("Find");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	displayTest("m1.find('a') == m2.find('a')", m1.find("a")->second, m2.find("a")->second);
	displayTest("m1.find('z') == m2.find('z')", m1.find("a")->second, m2.find("a")->second);
}

static void count(void)
{
	displayLittleHeader("Count");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["b"] = 21;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["b"] = 21;
	displayTest("m1.count('a') == m2.count('a')", m1.count("a"), m2.count("a"));
	displayTest("m1.count('b') == m2.count('b')", m1.count("b"), m2.count("b"));
	displayTest("m1.count('z') == m2.count('z')", m1.count("z"), m2.count("z"));
}

static void bounds()
{
	displayLittleHeader("Bounds");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	displayTest("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("a")->first, m2.lower_bound("a")->first);
	displayTest("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("c")->first, m2.lower_bound("c")->first);
	displayTest("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("a")->first, m2.upper_bound("a")->first);
	displayTest("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("c")->first, m2.upper_bound("c")->first);
}

static void range(void)
{
	displayLittleHeader("Equal range");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	std::pair<ft::map<std::string, int>::iterator, ft::map<std::string, int>::iterator> a = m1.equal_range("a");
	std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> b = m2.equal_range("a");
	displayTest("a.first->first == b.first->first", a.first->first, b.first->first);
	displayTest("a.first->second == b.first->second", a.first->second, b.first->second);
	displayTest("a.second->first == b.second->first", a.second->first, b.second->first);
	displayTest("a.second->second == b.second->second", a.second->second, b.second->second);
}

static void operators_comp(void)
{
	displayLittleHeader("Operators");
	ft::map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	ft::map<std::string, int> m3;
	std::map<std::string, int> m4;
	m3 = m1;
	m4 = m2;
	displayTest("m1 == m2", (m1 == m3), (m2 == m4));
	displayTest("m1 != m2", (m1 != m3), (m2 != m4));
	displayTest("m1 > m2", (m1 > m3), (m2 > m4));
	displayTest("m1 < m2", (m1 < m3), (m2 < m4));
	displayTest("m1 >= m2", (m1 >= m3), (m2 >= m4));
	displayTest("m1 <= m2", (m1 <= m3), (m2 <= m4));
	m1["e"] = 1;
	m2["e"] = 1;
	displayTest("m1 == m2", (m1 == m3), (m2 == m4));
	displayTest("m1 != m2", (m1 != m3), (m2 != m4));
	displayTest("m1 > m2", (m1 > m3), (m2 > m4));
	displayTest("m1 < m2", (m1 < m3), (m2 < m4));
	displayTest("m1 >= m2", (m1 >= m3), (m2 >= m4));
	displayTest("m1 <= m2", (m1 <= m3), (m2 <= m4));
	m3["e"] = 3;
	m4["e"] = 3;
	displayTest("m1 == m2", (m1 == m3), (m2 == m4));
	displayTest("m1 != m2", (m1 != m3), (m2 != m4));
	displayTest("m1 > m2", (m1 > m3), (m2 > m4));
	displayTest("m1 < m2", (m1 < m3), (m2 < m4));
	displayTest("m1 >= m2", (m1 >= m3), (m2 >= m4));
	displayTest("m1 <= m2", (m1 <= m3), (m2 <= m4));
}
int TestsMap(void)
{
	displayHeader("Map");
	constructors();
	max_size();
	access_operator();
	insert();
	erase();
	swap();
	clear();
	find();
	count();
	bounds();
	range();
	operators_comp();
	return (0);
}
