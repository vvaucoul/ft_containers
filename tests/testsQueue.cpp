/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsQueue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:21:51 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/02/24 19:22:42 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Tests.hpp"


static void constructors(void)
{
	displayLittleHeader("Constructor");
	ft::queue<int> q1;
	std::queue<int> q2;
	displayTest("q1.size() == q2.size()", q1.size() == q2.size());
	displayTest("q1.empty() == q2.empty()", q1.empty() == q2.empty());
}

static void front_back(void)
{
	displayLittleHeader("Front / Back / Push / Pop");
	ft::queue<int> q1;
	std::queue<int> q2;
	q1.push(0);
	q1.push(1);
	q1.push(2);
	q2.push(0);
	q2.push(1);
	q2.push(2);
	displayTest("q1.size() == q2.size()", q1.size() == q2.size());
	displayTest("q1.empty() == q2.empty()", q1.empty() == q2.empty());
	displayTest("q1.front() == q2.front()", q1.front(), q2.front());
	displayTest("q1.back() == q2.back()", q1.back(), q2.back());
	q1.pop();
	q2.pop();
	displayTest("q1.size() == q2.size()", q1.size() == q2.size());
	displayTest("q1.front() == q2.front()", q1.front(), q2.front());
	displayTest("q1.back() == q2.back()", q1.back(), q2.back());
}

int TestsQueue(void)
{
	displayHeader("Queue");
	constructors();
	front_back();
	return (0);
}
