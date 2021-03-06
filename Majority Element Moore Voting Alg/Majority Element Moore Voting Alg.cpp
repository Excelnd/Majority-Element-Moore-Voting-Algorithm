// Majority Element Moore Voting Alg.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int findCandidate(int a[], int size) {
	int majIndex = 0, count = 1;
	for (int i = 1; i < size; i++) {
		if (a[majIndex] == a[i])
			count++;
		else
			count--;
		if (count == 0) {
			majIndex = i;
			count = 1;
		}
	}
	return a[majIndex];
}

bool isMajority(int a[], int size, int cand) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] == cand)
			count++;

		if (count > size / 2)
			return 1;
		else
			return 0;
	}
}

void printMajority(int a[], int size)
{
	int cand = findCandidate(a, size);

	if (isMajority(a, size, cand))
		cout << " " << cand << " ";
	else
		cout << "No Majority Element";
}



int main()
{
	int a[] = { 1, 3, 3, 1, 2 };
	int size = (sizeof(a)) / sizeof(a[0]);

	printMajority(a, size);

	return 0;
}

