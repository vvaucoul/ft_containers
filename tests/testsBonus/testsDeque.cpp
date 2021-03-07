/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsDeque.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:58:18 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/01 17:55:06 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Tests.hpp"

static void constructors()
{
    {
        ft::deque<int> d1;
        std::deque<int> d2;

        displayTest("Empty constructor (d1 == d2)", d1 == d2);

        d1.push_back(1);
        d1.push_back(2);
        d1.push_back(3);
        d2.push_back(1);
        d2.push_back(2);
        d2.push_back(3);

        displayTest("Check after push_back (d1 == d2)", d1 == d2);
    }
    {
        ft::deque<int> d1;
        std::deque<int> d2;

        ft::deque<int> d3(d1);
        std::deque<int> d4(d2);

        displayTest("Empty constructor (d1 == d2)", d1 == d2);
        displayTest("Copy constructor (d3 == d4)", d3 == d4);

        d1.push_back(1);
        d1.push_back(2);
        d1.push_back(3);
        d2.push_back(1);
        d2.push_back(2);
        d2.push_back(3);

        d3.push_back(1);
        d3.push_back(2);
        d3.push_back(3);
        d4.push_back(1);
        d4.push_back(2);
        d4.push_back(3);
        displayTest("Check after push (d1 == d2)", d1 == d2);
        displayTest("Copy after push (d3 == d4)", d3 == d4);
    }
    {
        ft::deque<std::string> d1;
        std::deque<std::string> d2;

        displayTest("str | Empty constructor (d1 == d2)", d1 == d2);

        d1.push_back("1");
        d1.push_back("2");
        d1.push_back("3");
        d2.push_back("1");
        d2.push_back("2");
        d2.push_back("3");

        displayTest("str | Check after push_back (d1 == d2)", d1 == d2);
    }
    {
        ft::deque<std::string> d1;
        std::deque<std::string> d2;

        ft::deque<std::string> d3(d1);
        std::deque<std::string> d4(d2);

        displayTest("str | Empty constructor (d1 == d2)", d1 == d2);
        displayTest("str | Copy constructor (d3 == d4)", d3 == d4);

        d1.push_back("1");
        d1.push_back("2");
        d1.push_back("3");
        d2.push_back("1");
        d2.push_back("2");
        d2.push_back("3");

        displayTest("str | check after push (d1 == d2)", d1 == d2);
        displayTest("str | Copy check after push (d3 == d4)", d3 == d4);
        d3.push_back("1");
        d3.push_back("2");
        d3.push_back("3");
        d4.push_back("1");
        d4.push_back("2");
        d4.push_back("3");
        displayTest("str | Check after repush (d1 == d2)", d1 == d2);
        displayTest("str | Copy after repush (d3 == d4)", d3 == d4);
    }
}

static void sizeMaxSize()
{
    {
        {
            ft::deque<std::string> d1;
            std::deque<std::string> d2;

            displayTest("d1.max_size() == d2.max_size()", d1.max_size() == d2.max_size());
            d1.push_back("42born2code");
            d2.push_back("42born2code");
            displayTest("d1.max_size() == d2.max_size()", d1.max_size() == d2.max_size());
        }
        {
            ft::deque<size_t> d1;
            std::deque<size_t> d2;

            displayTest("d1.max_size() == d2.max_size()", d1.max_size() == d2.max_size());
            d1.push_back(42);
            d2.push_back(42);
            displayTest("d1.max_size() == d2.max_size()", d1.max_size() == d2.max_size());
        }
        {
            ft::deque<size_t> d1;
            std::deque<size_t> d2;
            displayTest("d1.size() == d2.size()", d1.size() == d2.size());
            for (size_t i = 0; i < 24; i++) {
                d1.push_back(i);
                d2.push_back(i);
            }
            displayTest("d1.size() == d2.size()", d1.size() == d2.size());
        }
        {
            ft::deque<std::string> d1;
            std::deque<std::string> d2;
            displayTest("d1.size() == d2.size()", d1.size() == d2.size());
            for (size_t i = 0; i < 24; i++) {
                d1.push_back("test");
                d2.push_back("test");
            }
            displayTest("d1.size() == d2.size()", d1.size() == d2.size());
        }
    }
}

static void assign()
{
    {
        ft::deque<std::string> d1;
        std::deque<std::string> d2;

        std::string test[] = {"42", "born", "to", "code"};

        d1.assign(test, test + 4);
        d2.assign(test, test + 4);
        displayTest("d1 == d2", d1 == d2);
        d1.assign(10, "42born2code");
        d2.assign(10, "42born2code");
        displayTest("d1 == d2", d1 == d2);
        d1.assign(0, "42born2code");
        d2.assign(0, "42born2code");
        displayTest("d1 == d2", d1 == d2);
        try
        {
            d1.assign(-5, "42born2code");
        }
        catch (std::exception &error)
        {
            std::cout << RED;
            std::cerr << "ft::deque : ";
            std::cerr << error.what();
            std::cout << GREEN << "               " GOOD << '\n';
            std::cout << RESET;
        }

        try
        {
            d2.assign(-5, "42born2code");
        }
        catch (std::exception &error)
        {
            std::cout << RED;
            std::cerr << "std::deque : ";
            std::cerr << error.what();
            std::cout << GREEN << "              " GOOD << '\n';
            std::cout << RESET;
        }
    }
    {
        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        size_t test[] = {42, 22, 11, 5, 2, 1};

        d1.assign(test, test + 6);
        d2.assign(test, test + 6);
        displayTest("d1 == d2", d1 == d2);
        d1.assign(10, (size_t)2);
        d2.assign(10, (size_t)2);
        displayTest("d1 == d2", d1 == d2);
        d1.assign(0, (size_t)42);
        d2.assign(0, (size_t)42);
        displayTest("d1 == d2", d1 == d2);
        try
        {
            d1.assign(-5, (size_t)42);
        }
        catch (std::exception &error)
        {
            std::cout << RED;
            std::cerr << "ft::deque : ";
            std::cerr << error.what();
            std::cout << GREEN << "               " GOOD << '\n';
            std::cout << RESET;
        }

        try
        {
            d2.assign(-5, (size_t)42);
        }
        catch (std::exception &error)
        {
            std::cout << RED;
            std::cerr << "std::deque : ";
            std::cerr << error.what();
            std::cout << GREEN << "              " GOOD << '\n';
            std::cout << RESET;
        }
    }
}

static void accessOperator()
{
    {
        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        d1.push_back(1);
        d1.push_back(2);
        d1.push_back(3);

        d2.push_back(1);
        d2.push_back(2);
        d2.push_back(3);

        displayTest("d1 == d2", d1 == d2);
        displayTest("d1[0] == d2[0]", d1[0] == d2[0]);
        displayTest("d1[1] == d2[1]", d1[1] == d2[1]);
        displayTest("d1[2] == d2[2]", d1[2] == d2[2]);

        try
        {
            std::cout << CYAN;
            std::cout << "d1.at(100) : " << d1.at(100) << "\n";
        }
        catch (std::exception &error)
        {
            std::cout << RED;
            std::cerr << "ft::deque : ";
            std::cerr << error.what() << '\n';
            std::cout << RESET;
        }
        try
        {
            std::cout << CYAN;
            std::cout << "d2.at(100) : " << d2.at(100) << "\n";
        }
        catch (std::exception &error)
        {
            std::cout << RED;
            std::cerr << "deque : ";
            std::cerr << error.what() << '\n';
            std::cout << RESET;
        }

        try
        {
            std::cout << CYAN;
            std::cout << "d1.at(-1) : " << d1.at(-1) << "\n";
        }
        catch (std::exception &error)
        {
            std::cout << RED;
            std::cerr << "ft::deque : ";
            std::cerr << error.what() << '\n';
            std::cout << RESET;
        }
        try
        {
            std::cout << CYAN;
            std::cout << "d2.at(-1) : " << d2.at(-1) << "\n";
        }
        catch (std::exception &error)
        {
            std::cout << RED;
            std::cerr << "deque : ";
            std::cerr << error.what() << '\n';
            std::cout << RESET;
        }
    }
}

static void resize()
{
    {
        ft::deque<int> d1;
        std::deque<int> d2;

        for (size_t i = 0; i < 10; i++) {
            d1.push_back(i);
            d2.push_back(i);
        }
        displayTest("d1 == d2", d1 == d2);
        d1.resize(10, 4);
        d2.resize(10, 4);
        displayTest("d1 == d2", d1 == d2);
        d1.resize(0, 4);
        d2.resize(0, 4);
        displayTest("d1 == d2", d1 == d2);
        d1.resize(0, 0);
        d2.resize(0, 0);
        displayTest("d1 == d2", d1 == d2);
        d1.resize(100, 100);
        d2.resize(100, 100);
        displayTest("d1 == d2", d1 == d2);
    }
}

static void frontBack()
{
    {
        ft::deque<int> d1;
        std::deque<int> d2;

        for (size_t i = 0; i < 100; i++) {
            d1.push_back(i);
            d2.push_back(i);
        }
        displayTest("d1 == d2", d1 == d2);
        displayTest("d1.front() == d2.front()", d1.front() == d2.front());
        displayTest("d1.back() == d2.back()", d1.back() == d2.back());
        for (size_t i = 0; i < 100; i++) {
            d1.push_back(i);
            d2.push_back(i);
        }
        displayTest("d1 == d2", d1 == d2);
        displayTest("d1.front() == d2.front()", d1.front() == d2.front());
        displayTest("d1.back() == d2.back()", d1.back() == d2.back());
    }
}

static void insert()
{
    {

        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        for (size_t i = 0; i < 42; i++) {
            d1.insert(d1.begin(), i);
            d2.insert(d2.begin(), i);
        }
        displayTest("d1 == d2", d1 == d2);



        for (size_t i = 0; i < 42; i++) {
            d1.insert(d1.end(), i);
            d2.insert(d2.end(), i);
        }
        displayTest("d1 == d2", d1 == d2);

        d1.clear();
        d2.clear();

        for (size_t i = 0; i < 42; i++) {
            d1.insert(d1.end(), i);
            d2.insert(d2.end(), i);
        }
        displayTest("d1 == d2", d1 == d2);
    }
    {
        size_t test[] = {42, 22, 11, 5, 2, 1};

        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        d1.insert(d1.begin(), test, test + 6);
        d2.insert(d2.begin(), test, test + 6);
        displayTest("d1 == d2", d1 == d2);
    }
    {
        size_t test[] = {42, 22, 11, 5, 2, 1};

        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        d1.insert(d1.end(), test, test + 6);
        d2.insert(d2.end(), test, test + 6);
        displayTest("d1 == d2", d1 == d2);
    }
    {
        size_t test[] = {42, 22, 11, 5, 2, 1};

        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        d1.insert(d1.end(), test, test + 1);
        d2.insert(d2.end(), test, test + 1);
        displayTest("d1 == d2", d1 == d2);
    }
    {
        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        d1.insert(d1.begin(), (size_t)10, (size_t)4);
        d2.insert(d2.begin(), (size_t)10, (size_t)4);
        displayTest("d1 == d2", d1 == d2);
    }
    {
        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        d1.insert(d1.end(), (size_t)10, (size_t)4);
        d2.insert(d2.end(), (size_t)10, (size_t)4);
        displayTest("d1 == d2", d1 == d2);
    }
}

static void erase()
{
    {
        size_t test[] = {42, 22, 11, 5, 2, 1};

        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        for (size_t i = 0; i < 42; i++) {
            d1.push_back(i);
            d2.push_back(i);
        }
        d1.erase(d1.begin(), d1.end());
        d2.erase(d2.begin(), d2.end());
        displayTest("d1 == d2", d1 == d2);

        d1.insert(d1.begin(), test, test + 6);
        d2.insert(d2.begin(), test, test + 6);

        d1.erase(d1.begin());
        d2.erase(d2.begin());
        displayTest("d1 == d2", d1 == d2);

        d1.insert(d1.end(), test, test + 6);
        d2.insert(d2.end(), test, test + 6);

        try
        {
            d1.erase(d1.end());
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
            std::cout << RED << "Real std::deque : segfault";
            std::cout << GREEN << "                " GOOD << '\n';
        }
        catch (std::exception &error)
        {
            std::cout << error.what() << '\n';
        }
        displayTest("d1 == d2", d1 == d2);

    }
}

static void swap()
{
    {
        ft::deque<size_t> d1;
        std::deque<size_t> d2;
        ft::deque<size_t> d3;
        std::deque<size_t> d4;

        for (size_t i = 0; i < 42; i++) {
            d1.push_back(i);
            d2.push_back(i);
        }
        d1.swap(d3);
        d2.swap(d4);
        displayTest("d1 == d2", d1 == d2);
        displayTest("d3 == d4", d3 == d4);
    }
    {
        ft::deque<size_t> d1;
        std::deque<size_t> d2;
        ft::deque<size_t> d3;
        std::deque<size_t> d4;

        for (size_t i = 0; i < 42; i++) {
            d3.push_back(i);
            d4.push_back(i);
        }
        d3.swap(d1);
        d4.swap(d2);
        displayTest("d1 == d2", d1 == d2);
        displayTest("d3 == d4", d3 == d4);
    }
}

static void operators()
{
    {
        ft::deque<size_t> d1;
        std::deque<size_t> d2;
        ft::deque<size_t> d3;
        std::deque<size_t> d4;


        for (size_t i = 0; i < 42; i++) {
            d1.push_back(i);
            d2.push_back(i);
        }

        displayTest("d1 == d2", (d1 == d3), (d2 == d4));
        displayTest("d1 != d2", (d1 != d3), (d2 != d4));
        displayTest("d1 >= d2", (d1 >= d3), (d2 >= d4));
        displayTest("d1 > d2", (d1 > d3), (d2 > d4));
        displayTest("d1 <= d2", (d1 <= d3), (d2 <= d4));
        displayTest("d1 < d2", (d1 < d3), (d2 < d4));

        d3 = d1;
        d4 = d2;


        displayTest("d1 == d2", (d1 == d3), (d2 == d4));
        displayTest("d1 != d2", (d1 != d3), (d2 != d4));
        displayTest("d1 >= d2", (d1 >= d3), (d2 >= d4));
        displayTest("d1 > d2", (d1 > d3), (d2 > d4));
        displayTest("d1 <= d2", (d1 <= d3), (d2 <= d4));
        displayTest("d1 < d2", (d1 < d3), (d2 < d4));

        for (size_t i = 0; i < 42; i++) {
            d1.push_back(i);
            d2.push_back(i);
        }

        displayTest("d1 == d2", (d1 == d3), (d2 == d4));
        displayTest("d1 != d2", (d1 != d3), (d2 != d4));
        displayTest("d1 >= d2", (d1 >= d3), (d2 >= d4));
        displayTest("d1 > d2", (d1 > d3), (d2 > d4));
        displayTest("d1 <= d2", (d1 <= d3), (d2 <= d4));
        displayTest("d1 < d2", (d1 < d3), (d2 < d4));

    }
}

static int clear()
{
    {
        ft::deque<std::string> d1;
        std::deque<std::string> d2;

        d1.push_back("toto");
        d2.push_back("toto");

        displayTest("d1 == d2", d1 == d2);
        d1.clear();
        d2.clear();

        displayTest("d1 == d2", d1 == d2);

    }
    {
        size_t tmp[] = {0, 2, 34, 42, 144};
        ft::deque<size_t> d1;
        std::deque<size_t> d2;
        ft::deque<size_t> d3;
        std::deque<size_t> d4;

        d1.assign(tmp, tmp + 5);
        d2.assign(tmp, tmp + 5);

        d3 = d1;
        d4 = d2;

        displayTest("d1 == d2", d1 == d2);
        displayTest("d3 == d1", d3 == d1);
        displayTest("d4 == d2", d4 == d2);

        d4.clear();
        d3.clear();
        d2.clear();
        d1.clear();

        displayTest("d1 == d2", d1 == d2);
        displayTest("d3 == d1", d3 == d1);
        displayTest("d4 == d2", d4 == d2);

        d4.clear();
        d3.clear();
        d2.clear();
        d1.clear();

        displayTest("d1 == d2", d1 == d2);
        displayTest("d3 == d1", d3 == d1);
        displayTest("d4 == d2", d4 == d2);

    }
    return (0);
}

static int push_front()
{
    {
        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        d1.push_front(42);
        d2.push_front(42);

        displayTest("d1 == d2", d1 == d2);

        for (size_t i = 0; i < 42; i++) {
            d1.push_front(i);
            d2.push_front(i);
        }
        displayTest("d1 == d2", d1 == d2);
    }
    {
        ft::deque<std::string> d1;
        std::deque<std::string> d2;

        d1.push_front("42");
        d2.push_front("42");
        displayTest("d1 == d2", d1 == d2);

        d1.push_front("42");
        d2.push_front("42");
        displayTest("d1 == d2", d1 == d2);

        d1.push_front("42born2code");
        d2.push_front("42born2code");
        displayTest("d1 == d2", d1 == d2);
    }
    return (0);
}

static int push_back()
{
    {
        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        d1.push_back(42);
        d2.push_back(42);

        displayTest("d1 == d2", d1 == d2);

        for (size_t i = 0; i < 42; i++) {
            d1.push_back(i);
            d2.push_back(i);
        }
        displayTest("d1 == d2", d1 == d2);
    }
    {
        ft::deque<std::string> d1;
        std::deque<std::string> d2;

        d1.push_back("42");
        d2.push_back("42");
        displayTest("d1 == d2", d1 == d2);

        d1.push_back("42");
        d2.push_back("42");
        displayTest("d1 == d2", d1 == d2);

        d1.push_back("42born2code");
        d2.push_back("42born2code");
        displayTest("d1 == d2", d1 == d2);
    }
    return (0);
}

static int pop_front()
{
    {
        size_t tmp[] = {0, 2, 34, 42, 144};
        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        d1.assign(tmp, tmp + 5);
        d2.assign(tmp, tmp + 5);

        displayTest("d1 == d2", d1 == d2);

        d1.pop_front();
        d2.pop_front();
        displayTest("d1 == d2", d1 == d2);

        for (size_t i = 0; i < 4; i++) {

            d1.pop_front();
            d2.pop_front();
        }
        displayTest("d1 == d2", d1 == d2);

        try
        {
            d1.pop_front();
            d2.pop_front();
        }
        catch (std::exception &e)
        {
            std::cout << "Error : " << e.what();
            std::cout << GREEN << "                    " GOOD << '\n';
        }
        displayTest("d1 == d2", d1 == d2);
    }
    return (0);
}

static int pop_back()
{
    {
        size_t tmp[] = {0, 2, 34, 42, 144};
        ft::deque<size_t> d1;
        std::deque<size_t> d2;

        d1.assign(tmp, tmp + 5);
        d2.assign(tmp, tmp + 5);

        displayTest("d1 == d2", d1 == d2);

        d1.pop_back();
        d2.pop_back();
        displayTest("d1 == d2", d1 == d2);

        for (size_t i = 0; i < 4; i++) {

            d1.pop_back();
            d2.pop_back();
        }
        displayTest("d1 == d2", d1 == d2);

        try
        {
            d1.pop_back();
            d2.pop_back();
        }
        catch (std::exception &e)
        {
            std::cout << "Error : " << e.what();
            std::cout << GREEN << "                    " GOOD << '\n';
        }
        displayTest("d1 == d2", d1 == d2);
    }
    return (0);
}

int testsDeque()
{
    displayHeader("DEQUE");
    displayLittleHeader("Constructors");
    constructors();
    displayLittleHeader("Size / Max SIze");
    sizeMaxSize();
    displayLittleHeader("Assign");
    assign();
    displayLittleHeader("Access operator");
    accessOperator();
    displayLittleHeader("Resize");
    resize();
    displayLittleHeader("Front / Back");
    frontBack();
    displayLittleHeader("Push Front");
    push_front();
    displayLittleHeader("Push Back");
    push_back();
    displayLittleHeader("Pop Front");
    pop_front();
    displayLittleHeader("Pop Back");
    pop_back();
    displayLittleHeader("Insert");
    insert();
    displayLittleHeader("Erase");
    erase();
    displayLittleHeader("Swap");
    swap();
    displayLittleHeader("Clear");
    clear();
    displayLittleHeader("Operators");
    operators();
    return (0);
}
