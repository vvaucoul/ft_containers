/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsMultiset.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:22:57 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/03 20:27:00 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Tests.hpp"

bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};

static void constructor()
{
    {
        ft::multiset<int> m1;
        std::multiset<int> m2;

        displayTest("m1 == m2", m1 == m2);

    }
    {
        int myints[]= {10,20,30,20,20};
        ft::multiset<int> m1(myints, myints + 5);
        std::multiset<int> m2(myints, myints + 5);

        displayTest("m1 == m2", m1 == m2);


        ft::multiset<int> m3(m1);
        std::multiset<int> m4(m2);

        displayTest("m1 == m2", m1 == m2);
        displayTest("m3 == m4", m3 == m4);



        ft::multiset<int> m5 (m3.begin(), m3.end());
        std::multiset<int> m6 (m4.begin(), m4.end());
        displayTest("m5 == m6", m5 == m6);

        bool(*fn_pt)(int,int) = fncomp;
        ft::multiset<int,bool(*)(int,int)> m7 (fn_pt);
        std::multiset<int,bool(*)(int,int)> m8 (fn_pt);
        displayTest("FNC m7 == m8", m7 == m8);

    }
}

static void insert()
{
    {
        std::cout << YELLOW << BOLD;
        std::cout << "Default Insert" << '\n';
        int myints[]= {10,20,30,20,20};
        ft::multiset<int> m1;
        std::multiset<int> m2;

        m1.insert(myints, myints + 5);
        m2.insert(myints, myints + 5);

        displayTest("m1 == m2", m1 == m2);

        m1.clear();
        m2.clear();

        displayTest("m1 == m2", m1 == m2);
    }
    {
        std::cout << YELLOW << BOLD;
        std::cout << "Duplicated Elements Insert" << '\n';
        int myints[]= {10,10,10,20,20};
        ft::multiset<int> m1;
        std::multiset<int> m2;

        m1.insert(myints, myints + 5);
        m2.insert(myints, myints + 5);

        std::cout << YELLOW << BOLD << "\n[FT]\n" << '\n';
        for (ft::multiset<int>::iterator it = m1.begin(); it != m1.end(); it++) {
            std::cout << "Value : " << *it << '\n';
        }

        std::cout << YELLOW << BOLD << "\n[STD]\n" << '\n';
        for (std::multiset<int>::iterator it = m2.begin(); it != m2.end(); it++) {
            std::cout << "Value : " << *it << '\n';
        }

        displayTest("m1 == m2", m1 == m2);

        m1.clear();
        m2.clear();

        displayTest("m1 == m2", m1 == m2);

        m1.insert(10);
        m2.insert(10);
        displayTest("m1 == m2", m1 == m2);

        m1.insert(42);
        m2.insert(42);
        displayTest("m1 == m2", m1 == m2);

        m1.insert(10);
        m2.insert(10);
        displayTest("m1 == m2", m1 == m2);

        std::cout << YELLOW << BOLD << "\n[FT]\n" << '\n';
        for (ft::multiset<int>::iterator it = m1.begin(); it != m1.end(); it++) {
            std::cout << "Value : " << *it << '\n';
        }

        std::cout << YELLOW << BOLD << "\n[STD]\n" << '\n';
        for (std::multiset<int>::iterator it = m2.begin(); it != m2.end(); it++) {
            std::cout << "Value : " << *it << '\n';
        }
    }
    {
        std::cout << YELLOW << BOLD << "\n\n[COMPARAISON WITH SET]\n\n" << '\n';

        std::cout << YELLOW << BOLD;
        std::cout << "Duplicated Elements Insert" << '\n';
        int myints[]= {10,10,10,20,20};
        ft::set<int> m1;
        std::set<int> m2;

        m1.insert(myints, myints + 5);
        m2.insert(myints, myints + 5);


        std::cout << YELLOW << BOLD << "\n[FT]\n" << '\n';
        for (ft::set<int>::iterator it = m1.begin(); it != m1.end(); it++) {
            std::cout << "Value : " << *it << '\n';
        }

        std::cout << YELLOW << BOLD << "\n[STD]\n" << '\n';
        for (std::set<int>::iterator it = m2.begin(); it != m2.end(); it++) {
            std::cout << "Value : " << *it << '\n';
        }

        displayTest("m1 == m2", m1 == m2);

        m1.clear();
        m2.clear();

        displayTest("m1 == m2", m1 == m2);

        m1.insert(10);
        m2.insert(10);
        displayTest("m1 == m2", m1 == m2);

        m1.insert(42);
        m2.insert(42);
        displayTest("m1 == m2", m1 == m2);

        m1.insert(10);
        m2.insert(10);
        displayTest("m1 == m2", m1 == m2);

        std::cout << YELLOW << BOLD << "\n[FT]\n" << '\n';
        for (ft::set<int>::iterator it = m1.begin(); it != m1.end(); it++) {
            std::cout << "Value : " << *it << '\n';
        }

        std::cout << YELLOW << BOLD << "\n[STD]\n" << '\n';
        for (std::set<int>::iterator it = m2.begin(); it != m2.end(); it++) {
            std::cout << "Value : " << *it << '\n';
        }
    }
}


static void swap()
{
    {
        ft::set<std::string> m1;
        std::set<std::string> m2;
        ft::set<std::string> m3;
        std::set<std::string> m4;

        std::string a[] = {"42", "born2code", "Norminet"};

        displayTest("m1 == m2", m1 == m2);

        m1.insert(a, a + 3);
        m2.insert(a, a + 3);

        displayTest("m1 == m2", m1 == m2);

        m1.swap(m3);
        m2.swap(m4);

        displayTest("m1 == m2", m1 == m2);
        displayTest("m3 == m4", m3 == m4);
    }
}

int TestsMultiset()
{
    displayHeader("MultiSet");
    displayLittleHeader("Constructor");
    constructor();
    displayLittleHeader("Insert");
    insert();
    displayLittleHeader("Swap");
    swap();
    return (0);
}
