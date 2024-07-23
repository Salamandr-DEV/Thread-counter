#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <atomic>
#include <mutex>

using namespace std;


int main()
{
	mutex m;
	int counter = 0;

	thread t1([&]()
	{
		for (int i = 0; i < 50000; i++)
		{
			m.lock();
			counter = counter + 1;
			m.unlock();
		}
	}
	);

	thread t2([&]()
	{
		for (int i = 0; i < 50000; i++)
		{
			m.lock();
			counter = counter + 1;
			m.unlock();
		}
	}
	);

	thread t3([&]()
	{
		for (int i = 0; i < 50000; i++)
		{
			m.lock();
			counter = counter + 1;
			m.unlock();
		}
	}
	);

	thread t4([&]()
	{
		for (int i = 0; i < 50000; i++)
		{
			m.lock();
			counter = counter + 1;
			m.unlock();
		}
	}
	);

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	cout << counter << endl;

	system("pause");
	return 0;
}