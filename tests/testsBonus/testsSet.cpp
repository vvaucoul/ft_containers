/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsSet.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:34:50 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/03 15:10:33 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Tests.hpp"
#include <utility>

template <class T>
static void print_set(T &set)
{
    typename T::iterator it = set.begin();
    std::cout << " --- Set of size " << set.size() << " ---" << std::endl;
    while (it != set.end())
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << " --- " << std::endl;
}

static void constructors(void)
{
    {
        ft::set<int> s1;
        std::set<int> s2;
        displayTest("s1 == s2", s1 == s2);
    }
    {
        int a[] = {0, 42, 128, 256};
        ft::set<int> s1(a, a + 4);
        std::set<int> s2(a, a + 4);
        displayTest("INT | s1 == s2", s1 == s2);
    }
    {
        std::string a[] = {"0", "42", "128", "256"};
        ft::set<std::string> s1(a, a + 4);
        std::set<std::string> s2(a, a + 4);
        displayTest("STRING | s1 == s2", s1 == s2);
    }
    {
        std::string a[] = {"0", "42", "128", "256"};
        ft::set<std::string> s1(a, a + 4);
        std::set<std::string> s2(a, a + 4);
        ft::set<std::string> s3(s1);
        std::set<std::string> s4(s2);
        displayTest("COPY | s1 == s2", s1 == s2);
        displayTest("COPY | s3 == s4", s3 == s4);
    }
}


static void capacity(void)
{
    {
        ft::set<int> s1;
        std::set<int> s2;
        displayTest("EMPTY : s1 == s2", s1.empty() == s2.empty());

        s1.insert(10);
        s2.insert(10);

        displayTest("s1 == s2", s1 == s2);
        displayTest("EMPTY : s1 == s2", s1.empty() == s2.empty());
    }
    {
        ft::set<int> s1;
        std::set<int> s2;
        displayTest("SIZE : s1 == s2", s1.size() == s2.size());

        s1.insert(42);
        s2.insert(42);
        displayTest("s1 == s2", s1 == s2);

        displayTest("SIZE : s1 == s2", s1.size() == s2.size());
    }
    {
        ft::set<int> s1;
        std::set<int> s2;
        ft::set<std::string> s3;
        std::set<std::string> s4;
        displayTest("INT SIZE : s1 == s2", s1.max_size() == s2.max_size());
        displayTest("STD::STRING SIZE : s3 == s4", s3.max_size() == s4.max_size());

        s1.insert(42);
        s2.insert(42);
        displayTest("s1 == s2", s1 == s2);

        displayTest("INT SIZE : s1 == s2", s1.max_size() == s2.max_size());
        displayTest("STD::STRING SIZE : s3 == s4", s3.max_size() == s4.max_size());
    }
}

static void insert(void)
{
    {
        ft::set<int> s1;
        std::set<int> s2;

        s1.insert(10);
        s2.insert(10);
        displayTest("s1 == s2", s1 == s2);
    }
    {
        int a[] = {0, 42, 128, 256};
        ft::set<int> s1;
        std::set<int> s2;

        s1.insert(a, a + 4);
        s2.insert(a, a + 4);
        displayTest("s1 == s2", s1 == s2);
    }
    {
        std::string a[] = {"0", "42", "128", "256"};
        ft::set<std::string> s1;
        std::set<std::string> s2;

        s1.insert(a, a + 2);
        s2.insert(a, a + 2);
        displayTest("s1 == s2", s1 == s2);

        s1.insert(a, a + 2);
        s2.insert(a, a + 2);
        displayTest("s1 == s2", s1 == s2);

        s1.insert(a, a + 4);
        s2.insert(a, a + 4);
        displayTest("s1 == s2", s1 == s2);
    }
}

static void erase(void)
{
    {
        int a[] = {0, 42, 128, 256};
        ft::set<int> s1;
        std::set<int> s2;

        s1.insert(a, a + 4);
        s2.insert(a, a + 4);
        displayTest("s1 == s2", s1 == s2);
        s1.erase(42);
        s2.erase(42);
        displayTest("s1 == s2", s1 == s2);
    }
    {
        std::string a[] = {"0", "42", "128", "256"};
        ft::set<std::string> s1;
        std::set<std::string> s2;

        s1.insert(a, a + 4);
        s2.insert(a, a + 4);
        displayTest("s1 == s2", s1 == s2);
        s1.erase("42");
        s2.erase("42");
        displayTest("s1 == s2", s1 == s2);
    }
}

static void swap(void)
{
    {
        int a[] = {0, 42, 128, 256};
        ft::set<int> s1;
        ft::set<int> s3;
        std::set<int> s2;
        std::set<int> s4;

        displayTest("s1 == s2", s1 == s2);
        s1.swap(s3);
        s2.swap(s4);
        displayTest("s1 == s2", s1 == s2);
        s1.insert(a, a + 4);
        s2.insert(a, a + 4);
        displayTest("s1 == s2", s1 == s2);
        s1.swap(s3);
        s2.swap(s4);
        displayTest("s1 == s2", s1 == s2);
    }
}

static void clear(void)
{
    {
        ft::set<int> s1;
        std::set<int> s2;

        s1.insert(42);
        s2.insert(42);
        displayTest("s1 == s2", s1 == s2);
        s1.clear();
        s2.clear();
        displayTest("s1 == s2", s1 == s2);
    }
    {
        ft::set<std::string> s1;
        std::set<std::string> s2;

        s1.insert("42");
        s2.insert("42");
        displayTest("s1 == s2", s1 == s2);
        s1.clear();
        s2.clear();
        displayTest("s1 == s2", s1 == s2);
    }
}

static void observers(void)
{
    {
        std::set<int> myset;
        ft::set<int> ftmyset;
        int highest;
        int fthighest;

        std::set<int>::key_compare mycomp = myset.key_comp();
        ft::set<int>::key_compare ftmycomp = ftmyset.key_comp();

        for (int i = 0; i <= 5; i++) myset.insert(i);
        for (int i = 0; i <= 5; i++) ftmyset.insert(i);

        std::cout << GREEN << BOLD;
        std::cout << "Key Compare : " << '\n';
        std::cout << "myset contains:\t\t";

        highest = *myset.rbegin();
        std::set<int>::iterator it=myset.begin();
        do {
            std::cout << ' ' << *it;
        } while ( mycomp(*(++it),highest) );

        std::cout << '\n';

        std::cout << "ftmyset contains:\t";

        fthighest = *myset.rbegin();
        ft::set<int>::iterator ftit=ftmyset.begin();
        do {
            std::cout << ' ' << *ftit;
        } while ( ftmycomp(*(++ftit),fthighest) );

        std::cout << '\n';
        std::cout << RESET;
        displayTest("s1 == s2", ftmyset == myset);
    }
    {

        std::set<int> myset;
        ft::set<int> ftmyset;

        std::set<int>::value_compare mycomp = myset.value_comp();
        ft::set<int>::value_compare ftmycomp = ftmyset.value_comp();

        for (int i=0; i<=5; i++) myset.insert(i);
        for (int i=0; i<=5; i++) ftmyset.insert(i);

        std::cout << GREEN << BOLD;
        std::cout << "\nValue Compare : " << '\n';

        std::cout << "myset contains:\t\t";

        int highest=*myset.rbegin();
        std::set<int>::iterator it=myset.begin();
        do {
            std::cout << ' ' << *it;
        } while ( mycomp(*(++it),highest) );

        std::cout << '\n';

        std::cout << "ftmyset contains:\t";

        int highest2=*ftmyset.rbegin();
        ft::set<int>::iterator it2=ftmyset.begin();
        do {
            std::cout << ' ' << *it2;
        } while ( ftmycomp(*(++it2),highest2) );

        std::cout << '\n';
        std::cout << RESET;
        displayTest("s1 == s2", ftmyset == myset);
    }
}

static void find(void)
{
    {
        ft::set<int> s1;
        std::set<int> s2;
        ft::set<int>::iterator ft_it;
        std::set<int>::iterator it;

        // set some initial values:
        for (int i=1; i<=5; i++) s1.insert(i*10);    // set: 10 20 30 40 50
        for (int i=1; i<=5; i++) s2.insert(i*10);    // set: 10 20 30 40 50

        displayTest("s1 == s2", s1 == s2);
        ft_it=s1.find(20);
        it=s2.find(20);
        displayTest("s1 == s2", s1 == s2);
        s1.erase (ft_it);
        s2.erase (it);
        displayTest("s1 == s2", s1 == s2);
        s1.erase (s1.find(40));
        s2.erase (s2.find(40));

        displayTest("s1 == s2", s1 == s2);

        std::cout << "s1 contains:";
        for (ft_it=s1.begin(); ft_it!=s1.end(); ++ft_it)
        std::cout << ' ' << *ft_it;
        std::cout << '\n';

        std::cout << "s2 contains:";
        for (it=s2.begin(); it!=s2.end(); ++it)
        std::cout << ' ' << *it;
        std::cout << '\n';

        displayTest("s1 == s2", s1 == s2);
    }
}

static void count(void)
{
    {
        std::set<int> s2;
        ft::set<int> s1;

        // set some initial values:
        for (int i=1; i<5; ++i) s2.insert(i*3);    // set: 3 6 9 12
        for (int i=1; i<5; ++i) s1.insert(i*3);    // set: 3 6 9 12

        displayTest("s1 == s2", s1 == s2);
        std::cout << YELLOW << BOLD;
        for (int i=0; i<10; ++i)
        {
            std::cout << i;
            if (s2.count(i)!=0)
            std::cout << " is an element of s2.\n";
            else
            std::cout << " is not an element of s2.\n";
        }

        std::cout << GREEN << BOLD;
        for (int i=0; i<10; ++i)
        {
            std::cout << i;
            if (s1.count(i)!=0)
            std::cout << " is an element of s1.\n";
            else
            std::cout << " is not an element of s1.\n";
        }
        displayTest("s1 == s2", s1 == s2);
    }
}

static void bounds(void)
{
    {
        std::cout << YELLOW << BOLD << "\nlower_bounds\n\n";
        ft::set<int> s1;
        ft::set<int>::iterator ftitlow,ftitup;
        std::set<int> s2;
        std::set<int>::iterator itlow,itup;

        displayTest("s1 == s2", s1 == s2);
        for (int i=1; i<10; i++) s1.insert(i*10); // 10 20 30 40 50 60 70 80 90
        for (int i=1; i<10; i++) s2.insert(i*10); // 10 20 30 40 50 60 70 80 90
        displayTest("s1 == s2", s1 == s2);

        ftitlow=s1.lower_bound (30);                //       ^
        ftitup=s1.upper_bound (60);
        itlow=s2.lower_bound (30);                //       ^
        itup=s2.upper_bound (60);                 //                   ^
                    //                   ^
        displayTest("s1 == s2", s1 == s2);

        s1.erase(ftitlow,ftitup);                     // 10 20 70 80 90
        s2.erase(itlow,itup);                     // 10 20 70 80 90
        displayTest("s1 == s2", s1 == s2);

        std::cout << "s1 contains:";
        for (ft::set<int>::iterator it=s1.begin(); it!=s1.end(); ++it)
        std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "s2 contains:";
        for (std::set<int>::iterator it=s2.begin(); it!=s2.end(); ++it)
        std::cout << ' ' << *it;
        std::cout << '\n';
        displayTest("s1 == s2", s1 == s2);



    }
    {
        std::cout << YELLOW << BOLD << "\nupper_bounds\n\n";


        ft::set<int> s1;
        std::set<int> s2;
        ft::set<int>::iterator ftitlow,ftitup;
        std::set<int>::iterator itlow,itup;

        displayTest("s1 == s2", s1 == s2);
        for (int i=1; i<10; i++) s1.insert(i*10); // 10 20 30 40 50 60 70 80 90
        for (int i=1; i<10; i++) s2.insert(i*10); // 10 20 30 40 50 60 70 80 90
        displayTest("s1 == s2", s1 == s2);

        ftitlow=s1.lower_bound (30);                //       ^
        itlow=s2.lower_bound (30);                //       ^
        ftitup=s1.upper_bound (60);                 //                   ^
        itup=s2.upper_bound (60);                 //                   ^
        displayTest("s1 == s2", s1 == s2);

        s1.erase(ftitlow,ftitup);                     // 10 20 70 80 90
        s2.erase(itlow,itup);                     // 10 20 70 80 90
        displayTest("s1 == s2", s1 == s2);

        std::cout << "s1 contains:";
        for (ft::set<int>::iterator it=s1.begin(); it!=s1.end(); ++it)
        std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout << "s2 contains:";
        for (std::set<int>::iterator it=s2.begin(); it!=s2.end(); ++it)
        std::cout << ' ' << *it;
        std::cout << '\n';
        displayTest("s1 == s2", s1 == s2);
    }
}

static void equalrange(void)
{
    {
        std::cout << YELLOW << BOLD << "\nequal_range\n\n";
        ft::set<int> s1;
        std::set<int> s2;

        for (int i=1; i<=5; i++) s1.insert(i*10);   // myset: 10 20 30 40 50
        for (int i=1; i<=5; i++) s2.insert(i*10);   // myset: 10 20 30 40 50
        displayTest("s1 == s2", s1 == s2);

        std::pair<ft::set<int>::const_iterator,ft::set<int>::const_iterator> ftret;
        std::pair<std::set<int>::const_iterator,std::set<int>::const_iterator> ret;
        displayTest("s1 == s2", s1 == s2);
        ftret = s1.equal_range(30);
        ret = s2.equal_range(30);
        displayTest("s1 == s2", s1 == s2);

        std::cout << YELLOW << BOLD;
        std::cout << "[FT] the lower bound points to: " << *ftret.first << '\n';
        std::cout << "[FT] the upper bound points to: " << *ftret.second << '\n';
        std::cout << "[STD] the lower bound points to: " << *ret.first << '\n';
        std::cout << "[STD] the upper bound points to: " << *ret.second << '\n';
        displayTest("s1 == s2", s1 == s2);
    }
}

static void operators(void)
{
    {
        ft::set<int> s1;
        std::set<int> s2;
        ft::set<int> s3;
        std::set<int> s4;

        std::set<int> foo,bar;


        displayTest("s1 == s2", (s1 == s3), (s2 == s4));
        displayTest("s1 != s2", (s1 != s3), (s2 != s4));
        displayTest("s1 >= s2", (s1 >= s3), (s2 >= s4));
        displayTest("s1 > s2", (s1 > s3), (s2 > s4));
        displayTest("s1 <= s2", (s1 <= s3), (s2 <= s4));
        displayTest("s1 < s2", (s1 < s3), (s2 < s4));

        s1.insert(10);
        s2.insert(10);
        s1.insert(20);
        s2.insert(20);

        displayTest("s1 == s2", (s1 == s3), (s2 == s4));
        displayTest("s1 != s2", (s1 != s3), (s2 != s4));
        displayTest("s1 >= s2", (s1 >= s3), (s2 >= s4));
        displayTest("s1 > s2", (s1 > s3), (s2 > s4));
        displayTest("s1 <= s2", (s1 <= s3), (s2 <= s4));
        displayTest("s1 < s2", (s1 < s3), (s2 < s4));

        s3 = s1;
        s4 = s2;

        s1.insert(10);
        s2.insert(10);
        s1.insert(30);
        s2.insert(30);

        displayTest("s1 == s2", (s1 == s3), (s2 == s4));
        displayTest("s1 != s2", (s1 != s3), (s2 != s4));
        displayTest("s1 >= s2", (s1 >= s3), (s2 >= s4));
        displayTest("s1 > s2", (s1 > s3), (s2 > s4));
        displayTest("s1 <= s2", (s1 <= s3), (s2 <= s4));
        displayTest("s1 < s2", (s1 < s3), (s2 < s4));
    }
}


int TestsSet(void)
{
    displayHeader("SET");
    displayLittleHeader("Constructors");
    constructors();
    displayLittleHeader("Capacity (empty / Size / MaxSize)");
    capacity();
    displayLittleHeader("Insert");
    insert();
    displayLittleHeader("Erase");
    erase();
    displayLittleHeader("Swap");
    swap();
    displayLittleHeader("Clear");
    clear();
    displayLittleHeader("Observers (key/value compare)");
    observers();
    displayLittleHeader("Find");
    find();
    displayLittleHeader("Count");
    count();
    displayLittleHeader("Bounds");
    bounds();
    displayLittleHeader("Equal Range");
    equalrange();
    displayLittleHeader("Operators");
    operators();
    return (0);
}
