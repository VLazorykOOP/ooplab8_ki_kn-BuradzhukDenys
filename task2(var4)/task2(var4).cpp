#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
void SelectionSort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[i])
			{
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template<>
void SelectionSort<char*>(char* arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(arr[j], arr[i]) < 0)
			{
				char* temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template <typename T>
void PrintArray(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand(time(nullptr));
	int n;
	cout << "Enter size of massive: ";
	cin >> n;

	double* arr = new double[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 101;
	}

	cout << "Massive: ";
	PrintArray(arr, n);

	SelectionSort<double>(arr, n);

	cout << "Massive after selection sort: ";
	PrintArray(arr, n);

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

	cout << "Strings:\n";
	PrintArray<char*>(strings, 3);

	SelectionSort<char*>(strings, 3);

	cout << "Strings after selection sort:\n";
	PrintArray<char*>(strings, 3);

	delete[] arr;
}
