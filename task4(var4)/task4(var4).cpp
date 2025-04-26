#include <iostream>

using namespace std;

template <typename T>
class Massive
{
private:
    T* arr;
    int size;
public:
    Massive(int newSize) : size(newSize)
    {
        arr = new T[size];
    }

    Massive(const Massive& other) : size(other.size)
    {
        arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    ~Massive()
    {
        delete[] arr;
    }

    Massive& operator=(const Massive& other)
    {
        if (this != &other)
        {
            delete[] arr;
            size = other.size;
            arr = new T[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = other.arr[i];
            }
        }

        return *this;
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index must be between 0 and " << size << endl;
            return arr[0];
        }

        return arr[index];
    }

    void insert(int index, T value)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index must be between 0 and " << size << endl;
            return;
        }

        arr[index] = value;
    }

    void show() const
    {
        cout << "Massive: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int Size() const
    {
        return size;
    }

    class Iterator
    {
    private:
        T* ptr;
    public:
        Iterator(T* newPtr) : ptr(newPtr) {}

        Iterator& operator++()
        {
            ++ptr;
            return *this;
        }

        Iterator& operator++(int)
        {
            Iterator temp = *this;
            ++ptr;
            return temp;
        }

        bool operator==(const Iterator& other) const
        {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const
        {
            return !(*this == other);
        }

        T& operator*() const
        {
            return *ptr;
        }

        T& operator->()
        {
            return ptr;
        }
    };

    Iterator begin()
    {
        Iterator iter(arr);
        return iter;
    }

    Iterator end()
    {
        Iterator iter(arr + size);
        return iter;
    }
};

int main()
{
    srand(time(nullptr));
    Massive<float> m1(8);
    
    for (int i = 0; i < m1.Size(); i++)
    {
        m1[i] = rand() % 51;
    }

    cout << "Massive: ";
    m1.show();

    cout << "Massive with iterator: ";
    for (auto it = m1.begin(); it != m1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}