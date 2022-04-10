#include <iostream>
#include <string>
#include <random>
#include <chrono>
using namespace std;

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int main()
{
	cout << "Enter how many numbers do you want to sort: ";
	int size;
	cin >> size;

	int myArr[size];

	for (int i = 0; i < size; i++)
	{
		myArr[i] = rand();
	}

	printArray(myArr, size);

	bool switchedSomething = true;

	auto start = chrono::steady_clock::now(); // get start time with chrono module

	while (switchedSomething) // as long as there are numbers to sort we continue
	{
		switchedSomething = false; // exit condition
		for (int i = 0; i < size - 1; i++)
		{
			if (myArr[i] > myArr[i + 1])
			{
				swap(&myArr[i], &myArr[i+1]);
				switchedSomething = true;
			}
		}
	}

	auto end = chrono::steady_clock::now();												// get end time with chrono module
	auto durationMs = chrono::duration_cast<chrono::milliseconds>(end - start).count(); // get the duration of the program (how quick it was)
	auto durationSec = chrono::duration_cast<chrono::seconds>(end - start).count();

	cout << "-----------------------------------------" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "-----------------------------------------" << endl;
	printArray(myArr, size);

	cout << "The program finished in: " << durationMs << " ms / " << durationSec << " secs!" << endl;

	return 0;
}
