/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:58:22 by vvaucoul          #+#    #+#             */
/*   Updated: 2021/03/03 20:31:15 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Tests.hpp"

void displayHeader()
{
	std::cout << RED << BOLD << '\n';
	std::cout << " ______  _______  _____  ____   _   _  _______         _____  _   _  ______  _____  " << std::endl;
	std::cout << "|  ____||__   __|/ ____|/ __ \\ | \\ | ||__   __| /\\    |_   _|| \\ | ||  ____||  __ \\ " << std::endl;
	std::cout << "| |__      | |  | |    | |  | ||  \\| |   | |   /  \\     | |  |  \\| || |__   | |__) |" << std::endl;
	std::cout << "|  __|     | |  | |    | |  | || . ` |   | |  / /\\ \\    | |  | . ` ||  __|  |  _  / " << std::endl;
	std::cout << "| |        | |  | |____| |__| || |\\  |   | | / ____ \\  _| |_ | |\\  || |____ | | \\ \\ " << std::endl;
	std::cout << "|_|        |_|   \\_____|\\____/ |_| \\_|   |_|/_/    \\_\\|_____||_| \\_||______||_|  \\_\\" << std::endl;
	std::cout << "		   ______                                                                   " << std::endl;
	std::cout << "		  |______|                                                                  " << std::endl;
	std::cout << "                                            Made by Vintz - vvaucoul@student.42.fr © " << std::endl;
	std::cout << "\n\n\n";
	std::cout << RESET << '\n';
}

int main(int argc, char const *argv[])
{
	std::string choice;

	if (argc != 2)
	{
		std::cout << "Not enough arguments" << '\n';
		return 0;
	}
	system("clear");
	displayHeader();
	choice = argv[1];
	if (choice == "all")
		return (TestsVector() | TestsList() | TestStack() | TestsQueue() | TestsMap());
	if (choice == "bonus")
		return (testsDeque() | TestsSet() | TestsMultiset() | TestsMultiMap());
	if (choice == "vector")
		return (TestsVector());
	if (choice == "list")
		return (TestsList());
	if (choice == "stack")
		return (TestStack());
	if (choice == "queue")
		return (TestsQueue());
	if (choice == "map")
		return (TestsMap());
	if (choice == "deque")
		return (testsDeque());
	if (choice == "set")
		return (TestsSet());
	if (choice == "multiset")
		return (TestsMultiset());
	if (choice == "multimap")
		return (TestsMultiMap());
	return 0;
}
