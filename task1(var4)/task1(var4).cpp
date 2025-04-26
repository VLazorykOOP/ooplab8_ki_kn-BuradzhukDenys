#include <iostream>
#include <ctime>
#include <string>

using namespace std;

template <typename T>
double averageMean(T arr[], int size)
{
	if (size == 0) return 0.0;
	T sum = T(0);
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum / size;
}

template<>
double averageMean<char*>(char* arr[], int size)
{
	if (size == 0) return 0.0;
	double totalLenght = 0.0;
	for (int i = 0; i < size; i++)
	{
		totalLenght += strlen(arr[i]);
	}
	return totalLenght / size;
}

int main()
{
	srand(time(nullptr));
	int n;
	cout << "Enter size of massive: ";
	cin >> n;

	if (n <= 0)
	{
		cerr << "Error: Size of massive must be greater than 0" << endl;
		return 1;
	}

	double* arr = new double[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 21;
	}

	cout << "Array:\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	cout << "Average mean of massive: " << averageMean<double>(arr, n) << endl;
	cin.ignore();

	char* strings[3];

	cout << "Enter 3 strings:\n";

	for (int i = 0; i < 3; i++)
	{
		char buffer[100];

		cout << "Enter " << i + 1 << " string: ";
		cin.getline(buffer, 100);

		strings[i] = new char[strlen(buffer) + 1];
		strcpy_s(strings[i], strlen(buffer) + 1, buffer);
	}

	cout << "Average mean of string massive: " << averageMean(strings, 3) << endl;

	for (int i = 0; i < 3; i++)
	{
		delete[] strings[i];
	}
	delete[] arr;
}