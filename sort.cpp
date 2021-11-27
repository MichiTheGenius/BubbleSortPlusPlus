#include <iostream>
#include <string>
#include <random>
#include <chrono>
using namespace std;

void printArray(int arr[], int size)
{
	for(int i = 0; i<size; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	cout << "Enter how many numbers do you want to sort: ";
	int size;
	cin >> size;

	int myArr[size];


	for(int i = 0; i<size; i++)
	{
		myArr[i] = rand();
	}

	printArray(myArr, size);

	bool switchedSomething = true;

	auto start = chrono::steady_clock::now();

	while(switchedSomething)
	{
		switchedSomething = false;
		for(int i = 0; i<size-1; i++)
		{
			if(myArr[i] > myArr[i+1])
			{
				int temp = myArr[i];
				myArr[i] = myArr[i+1];
				myArr[i+1] = temp;
				switchedSomething = true;
			}
		}
	}

	auto end = chrono::steady_clock::now();
	auto durationMs = chrono::duration_cast<chrono::milliseconds>(end-start).count();
	auto durationSec = chrono::duration_cast<chrono::seconds>(end-start).count();

	cout << "-----------------------------------------" << endl;
	printArray(myArr, size);

	
	cout << "The program finished in: " << durationMs << " ms / " << durationSec << " secs!" << endl;

	return 0;
}
