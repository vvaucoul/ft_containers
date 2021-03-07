/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsMultimap.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:04:05 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/03 20:21:59 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Tests.hpp"

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
    bool operator() (const char& lhs, const char& rhs) const
    {return lhs<rhs;}
};

static void constructor()
{
    {
        ft::multimap<char, int> m1;
        std::multimap<char, int> m2;

        displayTest("m1 == m2", m1 == m2);
    }
    {
        ft::multimap<std::string,int> m1;
        std::multimap<std::string,int> m2;
        std::pair<std::string, int> a[] = {std::make_pair("0", 1), std::make_pair("1", 0), std::make_pair("2", 1)};

        m1.insert(a, a + 3);
        m2.insert(a, a + 3);

        m2.insert(std::pair<std::string,int>("a",10));
        m1.insert(std::pair<std::string,int>("a",10));
        displayTest("m1 == m2", m1 == m2);

        m2.insert(std::pair<std::string,int>("b",15));
        m1.insert(std::pair<std::string,int>("b",15));
        displayTest("m1 == m2", m1 == m2);

        m2.insert(std::pair<std::string,int>("b",20));
        m1.insert(std::pair<std::string,int>("b",20));
        displayTest("m1 == m2", m1 == m2);

        m2.insert(std::pair<std::string,int>("c",25));
        m1.insert(std::pair<std::string,int>("c",25));

        displayTest("m1 == m2", m1 == m2);


        ft::multimap<std::string,int> m3 (m1.begin(),m1.end());
        std::multimap<std::string,int> m4 (m2.begin(),m2.end());
        displayTest("m3 == m4", m3 == m4);

        ft::multimap<std::string,int> third (m3);
        std::multimap<std::string,int> fourth (m4);
        displayTest("Copy third == Copy fourth", third == fourth);

        ft::multimap<std::string,int,classcomp> m5;
        std::multimap<std::string,int,classcomp> m6;
        displayTest("m5 == m6", m5 == m6);

        bool(*fn_pt)(char,char) = fncomp;
        ft::multimap<char,int,bool(*)(char,char)> m7 (fn_pt);
        std::multimap<char,int,bool(*)(char,char)> m8 (fn_pt);
        displayTest("FUNC m7 == FUNC m8", m7 == m8);
    }
}

static void insert()
{
    {
        ft::multimap<std::string, std::string> m1;
        std::multimap<std::string, std::string> m2;
        std::pair<std::string, std::string> a[] =
        {std::make_pair("school", "42"),
        std::make_pair("city", "Paris 75"),
        std::make_pair("Country", "France")};

        m1.insert(a, a + 3);
        m2.insert(a, a + 3);
        displayTest("m1 == m2", m1 == m2);

        std::cout << YELLOW << BOLD << "[FT]" << '\n';

        for (ft::multimap<std::string, std::string>::iterator it = m1.begin(); it != m1.end(); it++) {
            std::cout << "Key : " << (*it).first << "\t|\tValue = " << (*it).second << '\n';
        }
        std::cout << YELLOW << BOLD << "[STD]" << '\n';

        for (std::multimap<std::string, std::string>::iterator it = m2.begin(); it != m2.end(); it++) {
            std::cout << "Key : " << (*it).first << "\t|\tValue = " << (*it).second << '\n';
        }
        displayTest("m1 == m2", m1 == m2);
    }
    {
        std::cout << YELLOW << BOLD << "\n\n[INSERT DOUBLON]\n\n" << '\n';
        ft::multimap<std::string, std::string> m1;
        std::multimap<std::string, std::string> m2;
        std::pair<std::string, std::string> a[] =
        {std::make_pair("school", "42"),
        std::make_pair("school", "42"),
        std::make_pair("school", "42")};

        m1.insert(a, a + 3);
        m2.insert(a, a + 3);
        displayTest("m1 == m2", m1 == m2);

        std::cout << YELLOW << BOLD << "[FT]" << '\n';

        for (ft::multimap<std::string, std::string>::iterator it = m1.begin(); it != m1.end(); it++) {
            std::cout << "Key : " << (*it).first << "\t|\tValue = " << (*it).second << '\n';
        }
        std::cout << YELLOW << BOLD << "[STD]" << '\n';

        for (std::multimap<std::string, std::string>::iterator it = m2.begin(); it != m2.end(); it++) {
            std::cout << "Key : " << (*it).first << "\t|\tValue = " << (*it).second << '\n';
        }
        displayTest("m1 == m2", m1 == m2);
    }
    {
        std::cout << YELLOW << BOLD << "\n\n[COMPARAISON WITH MAP]\n\n" << '\n';
        ft::map<std::string, std::string> m1;
        std::map<std::string, std::string> m2;
        std::pair<std::string, std::string> a[] =
        {std::make_pair("school", "42"),
        std::make_pair("school", "42"),
        std::make_pair("school", "42")};

        m1.insert(a, a + 3);
        m2.insert(a, a + 3);
        displayTest("m1 == m2", m1 == m2);

        std::cout << YELLOW << BOLD << "[FT]" << '\n';

        for (ft::map<std::string, std::string>::iterator it = m1.begin(); it != m1.end(); it++) {
            std::cout << "Key : " << (*it).first << "\t|\tValue = " << (*it).second << '\n';
        }
        std::cout << YELLOW << BOLD << "[STD]" << '\n';

        for (std::map<std::string, std::string>::iterator it = m2.begin(); it != m2.end(); it++) {
            std::cout << "Key : " << (*it).first << "\t|\tValue = " << (*it).second << '\n';
        }
        displayTest("m1 == m2", m1 == m2);
    }
}

static void swap()
{
    {
        ft::multimap<std::string, std::string> m1;
        std::multimap<std::string, std::string> m2;
        ft::multimap<std::string, std::string> m3;
        std::multimap<std::string, std::string> m4;

        std::pair<std::string, std::string> a[] =
        {std::make_pair("school", "42"),
        std::make_pair("city", "Paris 75"),
        std::make_pair("Country", "France")};

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

int TestsMultiMap()
{
    displayHeader("MultiMap");
    displayLittleHeader("Constructor");
    constructor();
    displayLittleHeader("Insert");
    insert();
    displayLittleHeader("Swap");
    swap();
    return (0);
}
