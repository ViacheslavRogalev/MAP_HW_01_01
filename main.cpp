#include <iostream>
#include <thread>
#include <chrono>


using namespace std::chrono_literals;//1 sec

int queue = 0;
int max_client = 10;

void client() 
{
	while (queue < max_client)
	{
		++queue;
		std::cout << "client " << queue << "\n";
		std::this_thread::sleep_for(1s);
	}
}

void operationist() 
{
	while (queue != 0)
	{
		--queue;
		std::cout << "operationist " << queue << "\n";
		std::this_thread::sleep_for(2s);
	}
}

int main()
{
	std::thread c1(client);
	std::thread o1(operationist);

	if (c1.joinable()) 
	{
		c1.join();
	}

	if (o1.joinable()) 
	{
		o1.join();
	}

	return 0;
}