/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:59:01 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/03 20:31:22 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include <vector>
# include <list>
# include <map>
# include <set>
# include <stack>
# include <queue>
# include <deque>
# include <iostream>

# include <unistd.h>
# include <stdlib.h>

#include "../srcs/vector/vector.hpp"
#include "../srcs/stack/stack.hpp"
#include "../srcs/queue/queue.hpp"
#include "../srcs/list/list.hpp"
#include "../srcs/map/map.hpp"
#include "../srcsBonus/set/Set.hpp"
#include "../srcsBonus/multiset/Multiset.hpp"
#include "../srcsBonus/multimap/Multimap.hpp"
#include "../srcsBonus/deque/Deque.hpp"

// COLORS
# define RESET       "\033[0m"
# define BOLD        "\033[1m"
# define UNDERLINE   "\033[4m"
# define BLACK       "\033[1;30m"
# define RED         "\033[1;31m"
# define GREEN       "\033[1;32m"
# define YELLOW      "\033[1;33m"
# define BLUE        "\033[1;34m"
# define VIOLET      "\033[1;35m"
# define CYAN        "\033[1;36m"
# define WHITE       "\033[1;37m"

# define GOOD "✓"
# define FAIL "❌"

# define DEFAULT_TTS 100000 /// 100

inline void displayHeader(const std::string &name)
{
	size_t defaultWidth = 40;

	std::cout << CYAN << BOLD;
	for (size_t i = 0; i <= defaultWidth; i++)
		std::cout << "#";
	std::cout << "\n\n";
	for (size_t i = 0; i < (defaultWidth / 2) - (name.size() / 2); i++)
		std::cout << " ";
	std::cout << name << "\n\n";
	for (size_t i = 0; i <= defaultWidth; i++)
		std::cout << "#";
	std::cout << RESET;
	std::cout << "\n\n";
}

inline void displayLittleHeader(const std::string &name)
{
	size_t defaultWidth = 40;

	std::cout << VIOLET << BOLD ;
	std::cout << "\n####";
	for (size_t i = 0; i < (defaultWidth / 2) - (name.size() / 2) - 4; i++) {
		std::cout << " ";
	}

	std::cerr <<  UNDERLINE << name << RESET;
	std::cout << VIOLET << BOLD ;

	for (size_t i = 0; i < (defaultWidth / 2) - (name.size() / 2) - 4; i++) {
		std::cout << " ";
	}
	std::cout << "####\n\n";
	std::cout << RESET;
}

inline void displayInfo(std::string const &info)
{
	std::cout <<  YELLOW  << "\n# " << info << "\n";
	usleep(DEFAULT_TTS);
}

inline void displayTest(const std::string &name, bool valid)
{
	size_t defaultWidth = 40;
	std::cout << CYAN << name << ": ";
	for (size_t i = 0; i < defaultWidth - name.size(); i++) {
		if (name.size() > defaultWidth)
			break;
		std::cout << " ";
	}
	std::cout << (valid ? GREEN : RED) << (valid ? GOOD : FAIL) << '\n';
	usleep(DEFAULT_TTS);
}

inline void displayTest(const std::string &name, bool valid, bool valid2)
{
	size_t defaultWidth = 40;
	std::cout << CYAN << name << ": ";
	for (size_t i = 0; i < defaultWidth - name.size(); i++) {
		if (name.size() > defaultWidth)
			break;
		std::cout << " ";
	}
	std::cout << ((valid == valid2) ? GREEN : RED) << ((valid == valid2) ? GOOD : FAIL) << '\n';
	usleep(DEFAULT_TTS);
}

template <typename T>
inline void displayTest(const std::string &name, T a, T b)
{
	size_t defaultWidth = 40;

	std::cout << CYAN << name << ": ";
	for (size_t i = 0; i < defaultWidth - name.size(); i++) {
		if (name.size() > defaultWidth)
			break;
		std::cout << " ";
	}
	std::cout << ((a == b) ? GREEN : RED) << ((a == b) ? GOOD : FAIL) << '\n';
	usleep(DEFAULT_TTS);
}

// Tests
int TestsVector();
int TestsList();
int TestStack();
int TestsQueue();
int TestsMap();

// Bonus Tests
int testsDeque();
int TestsSet();
int TestsMultiset();
int TestsMultiMap();


// Operator test

template <typename T>
bool operator==(ft::vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
};

template <typename T>
bool operator==(ft::list<T> &a, std::list<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::list<T>::iterator it = a.begin();
	typename std::list<T>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (*it != *it2)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

template <typename T, typename S>
bool operator==(ft::map<T, S> &a, std::map<T, S> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::map<T, S>::iterator it = a.begin();
	typename std::map<T, S>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (it->first != it2->first || it->second != it2->second)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

// Bonus operator

template <typename T, typename S>
bool operator==(ft::deque<T, S> &a, std::deque<T, S> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a.at(i) != b.at(i))
			return (false);
	}
	return (true);
};

template <typename T>
bool operator==(ft::set<T> &a, std::set<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
    typename ft::set<T>::iterator it = a.begin();
    typename std::set<T>::iterator it2 = b.begin();
	while (it != a.end())
    {
        if (*it != *it2)
            return (false);
        ++it;
        ++it2;
    }
	return (true);
};

template <typename T>
bool operator==(ft::multiset<T> &a, std::multiset<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
    typename ft::multiset<T>::iterator it = a.begin();
    typename std::multiset<T>::iterator it2 = b.begin();
	while (it != a.end())
    {
        if (*it != *it2)
            return (false);
        ++it;
        ++it2;
    }
	return (true);
};

template <typename T, typename S>
bool operator==(ft::multimap<T, S> &a, std::multimap<T, S> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
    typename ft::multimap<T, S>::iterator it = a.begin();
    typename std::multimap<T, S>::iterator it2 = b.begin();
	while (it != a.end())
    {
        if ((it->first != it2->first) || (it->second != it2->second))
			return (false);
		++it;
		++it2;
    }
	return (true);
};

template <typename T, typename B, typename C>
bool operator==(ft::multiset<T, B, C> &a, std::multiset<T, B, C> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
    typename ft::multiset<T>::iterator it = a.begin();
    typename std::multiset<T>::iterator it2 = b.begin();
	while (it != a.end())
    {
        if (*it != *it2)
            return (false);
        ++it;
        ++it2;
    }
	return (true);
};

template <typename T, typename S, typename B, typename C>
bool operator==(ft::multimap<T, S, B, C> &a, std::multimap<T, S, B, C> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
    typename ft::multimap<T, S>::iterator it = a.begin();
    typename std::multimap<T, S>::iterator it2 = b.begin();
	while (it != a.end())
    {
        if (it->first != it2->first || it->second != it2->second)
            return (false);
        ++it;
        ++it2;
    }
	return (true);
};

// lst == lst

template <typename T>
bool operator==(ft::list<T> &a, ft::list<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::list<T>::iterator it = a.begin();
	typename ft::list<T>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (*it != *it2)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

// Print debug

template <typename T>
void printDeque(ft::deque<T> &a, std::deque<T> &b)
{
    std::cout << "PRINT INSERT" << '\n';
    typename ft::deque<T>::iterator it = a.begin();
    typename std::deque<T>::iterator it2 = b.begin();

    while (it != a.end())
    {
        std::cout << "FT = " << *it << '\n';
        std::cout << "STD = " << *it2 << '\n';
        ++it;
        ++it2;
    }
}

#endif
