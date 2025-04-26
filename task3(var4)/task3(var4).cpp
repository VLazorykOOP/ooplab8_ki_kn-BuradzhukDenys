#include <iostream>

using namespace std;

//Створюємо шаблон класу "Циклічна черга"
template <typename T>
class CircularQueue
{
private:
    T* arr;
    int first;
    int rear;
    int maxSize;
    int currentSize;
public:
    //Коструктор який приймає розмір черги
    CircularQueue(int size) : currentSize(0), maxSize(size), first(-1), rear(-1)
    {
        arr = new T[maxSize];
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    //Метод для додавання елементу в чергу
    void enqueue(const T& element)
    {
        //Якщо черга повна, то повідомляємо про це
        if (Full())
        {
            cout << "Queue is full" << endl;
            return;
        }

        //Якщо черга пуста, то встановлюємо індекс першого і останнього елементу на 0
        if (Empty())
        {
            first = 0;
            rear = 0;
        }
        //Інакше пересуваємо індекс останнього елемнту, якщо індекс доходить до кінця, то пересуваємо його на початок черги
        else
        {
            rear = (rear + 1) % maxSize;
        }

        arr[rear] = element;
        currentSize++;
    }

    T dequeue()
    {
        //Якщо черга пуста, то повідомляємо про це
        if (Empty())
        {
            cout << "Queue is empty" << endl;
            return T(-12312312312312);
        }

        T element = arr[first];
        //Якщо індекс першого і останнього елементу однаковий, тобто в черзі лишився один елемент, то встановлюємо індекси -1
        if (first == rear)
        {
            first = -1;
            rear = -1;
        }
        //Інакше пересуваємо індекс першого елемнту, якщо індекс доходить до кінця, то пересуваємо його на початок черги
        else
        {
            first = (first + 1) % maxSize;
        }

        currentSize--;
        return element;
    }

    bool Full() const
    {
        return currentSize == maxSize;
    }

    bool Empty() const
    {
        return currentSize == 0;
    }

    void print() const
    {
        if (Empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Circular queue: ";
        int i = first;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        } while (i != (rear + 1) % maxSize);
        cout << endl;
    }
};

int main()
{
    CircularQueue<double> q1(5);

    q1.enqueue(10);
    q1.enqueue(15);
    q1.enqueue(112);
    q1.enqueue(21);
    q1.enqueue(1);
    q1.enqueue(16);

    q1.print();

    cout << "Deleted element: " << q1.dequeue() << endl;
    cout << "Deleted element: " << q1.dequeue() << endl;

    q1.enqueue(80);
    q1.enqueue(5);

    q1.print();
}