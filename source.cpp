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

int main(int argc, char* argv[])
{
	srand(time(NULL));

	int door = 0;
	int player = 0;
	int switched = 0;
	int choice = 0;
	bool sim = true;
	int simCount = 0;
	int win = 0;
	int loss = 0;
	int count = 0;
	char rerun = ' ';

	//place the argument code here

	do
	{
		door = seedseq_random_using_clock() % 3 + 1;

		std::cout << "Enter a door?(1-3)" << std::endl;
		if (!sim) 
		{
			player = (rand() + seedseq_random_using_clock()) % 3 + 1;
		}
		else
		{
			std::cin >> player;
		}
	}while(count < simCount || tolower(rerun) == 'y');
	
	return 0;
}
