#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {
private:
	T* data;          // указатель на динамический массив элементов
	int capacity;     // максимальная вместимость стека
	int size;         // текущий размер стека

public:
	Stack(int capacity) : capacity(capacity), size(0)
	{
		data = new T[capacity];  // выделение памяти для массива
	}

	~Stack() 
	{
		delete[] data;  // освобождение памяти при уничтожении объекта
	}

	int getSize() const 
	{
		
		return size;
	}

	bool isEmpty() const 
	{
		return size == 0;
	}

	void push(const T& item) 
	{
		if (size == capacity) 
		{
			throw std::overflow_error("Stack is full. Cannot push more elements.");
		}
		data[size++] = item;
		std::cout << size << std::endl;
	}

	T pop() 
	{
		if (isEmpty()) 
		{
			throw std::out_of_range("Stack is empty. Cannot pop an element.");
		}
		return data[--size];
	}

	T top() const 
	{
		if (isEmpty()) 
		{
			throw std::logic_error("Stack is empty. Cannot retrieve the top element.");
		}
		return data[size - 1];
	}
};

int main()
{
	try
	{
		Stack<int> stack(5);  // Создаем стек для хранения целых чисел с максимальной вместимостью 5 элементов

		std::cout << "Stack size: " << stack.getSize() << std::endl;
		std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;



		std::cout << "Stack size: " << stack.getSize() << std::endl;
		std::cout << "Top element: " << stack.top() << std::endl;

		std::cout << "Top element after pop: " << stack.top() << std::endl;

		stack.pop();
		stack.pop();


		std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl;

		

	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Failed to allocate memory: " << e.what() << std::endl;
	}
	catch (const std::overflow_error& e)
	{
		std::cerr << "Stack overflow: " << e.what() << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Stack underflow: " << e.what() << std::endl;
	}
	catch (const std::logic_error& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}