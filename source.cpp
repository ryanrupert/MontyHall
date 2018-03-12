/**
* Created by Ryan Rupert
* Date: 2018-03-10
* Source: None
* This a cpp implementation of the Monty hall problem
*/

#include <iostream>
#include <cstdint>
#include <chrono>
#include <random>
#include <time.h>
#include <string.h>


/************************************
* Copied
* Title: Simple Portable C++ Seed Entropy
* Author: M.E. O'Neill
* Date: 20150503
* Code Version: No version given
* Availability: http://www.pcg-random.org/posts/simple-portable-cpp-seed-entropy.html
************************************/
uint32_t seedseq_random_using_clock()
{
	uint64_t seed = std::chrono::high_resolution_clock::
					now().time_since_epoch().count();
	std::seed_seq seeder{uint32_t(seed),uint32_t(seed >> 32)};
	++seed;
	int out;
	seeder.generate(&out,&out+1);
	return out;
}

void help()
{
	std::cout << "usage: a [arguments]" << std::endl;
	std::cout << std::endl;
	std::cout << "arguments:" << std::endl;
	std::cout << "-s [number]		Run in simulation mode. Non-zero number required." << std::endl;
	std::cout << "-h, --help		Display help screen." << std::endl;
}

void error()
{
	std::cout << "argument not recognized." << std::endl;
	help();
}

void error(std::string msg)
{
	std::cout << msg << std::endl;
	help();
}

int main(int argc, char **argv)
{
	srand(seedseq_random_using_clock());

	int door = 0;
	int player = 0;
	int switched = 0;
	int choice = 0;
	bool sim = false;
	int simCount = 0;
	int win = 0;
	int loss = 0;
	int count = 0;
	char rerun = 'n';

	//this is the section that will get the command line arguments
	for (int i = 1; i < argc; i++) 
	{
		if (!strcmp(argv[i], "-s")) 
		{
			sim = true;
			simCount = atoi(argv[i + 1]);
			if (simCount <= 0) 
			{
				error("the number must be non-zero");
				return 3;
			}
		}
		else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
		{
			help();
			return 0;
		}
		else
		{
			error();
			return 3;
		}
	}

	do
	{
		door = rand() % 3 + 1;

		(sim) ? std::cout << "." : std::cout << "Enter a door?(1-3)" << std::endl;
		if (sim) 
		{
			player = rand() % 3 + 1;
		}
		else
		{
			std::cin >> player;
		}

		switch (door)
		{
			case 1:
				switch (player)
				{
					case 1:
						(sim) ? std::cout << "." : std::cout << "Door 2 was removed" << std::endl;
						switched = 3;
						break;
					case 2:
						(sim) ? std::cout << "." : std::cout << "Door 3 was removed" << std::endl;
						switched = 1;
						break;
					case 3:
						(sim) ? std::cout << "." : std::cout << "Door 2 was removed" << std::endl;
						switched = 1;
						break;
					default:
						std::cout << "Please try again" << std::endl;
						return 1;
						break;
				}
				break;
			case 2:
				switch (player)
				{
					case 1:
						(sim) ? std::cout << "." : std::cout << "Door 3 was removed" << std::endl;
						switched = 2;
						break;
					case 2:
						(sim) ? std::cout << "." : std::cout << "Door 1 was removed" << std::endl;
						switched = 3;
						break;
					case 3:
						(sim) ? std::cout << "." : std::cout << "Door 1 was removed" << std::endl;
						switched = 2;
						break;
					default:
						std::cout << "Please try again" << std::endl;
						return 1;
						break;
				}
				break;
			case 3:
				switch (player)
				{
					case 1:
						(sim) ? std::cout << "." : std::cout << "Door 2 was removed" << std::endl;
						switched = 3;
						break;
					case 2:
						(sim) ? std::cout << "." : std::cout << "Door 1 was removed" << std::endl;
						switched = 3;
						break;
					case 3:
						(sim) ? std::cout << "." : std::cout << "Door 1 was removed" << std::endl;
						switched = 2;
						break;
					default:
						std::cout << "Please try again" << std::endl;
						return 1;
						break;
				}
				break;
			default:
				std::cout << "Random Generator Error" << std::endl;
				return 2;
				break;
		}

		(sim) ? std::cout << "." : std::cout << "Would you like to stay or switch" << std::endl;
		if (sim) 
		{
			choice = rand() % 2 + 1;
		}
		else
		{
			std::cin >> choice;
		}

		switch (choice)
		{
			case 1:
				player = switched;
				break;
			case 2:
				break;
			default:
				break;
		}

		if (door == player) 
		{
			(sim) ? std::cout << "." : std::cout << "You win" << std::endl;
			win++;
		}
		else
		{
			(sim) ? std::cout << "." : std::cout << "You lose" << std::endl;
			loss++;
		}

		(sim) ? std::cout << "." : std::cout << "Would you like to run the program again?(y or n)" << std::endl;
		if (sim) 
		{
			count++;
		}
		else
		{
			std::cin >> rerun;
		}
	}while(count < simCount || tolower(rerun) == 'y');

	if (sim) 
	{
		std::cout << "\nWins: " << win << std::endl;
		std::cout << "Loss: " << loss << std::endl;
		std::cout << "Rounds: " << simCount << std::endl;
		std::cin.get();
	}
	
	return 0;
}
