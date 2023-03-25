#include <iostream>
#include <cstring>

#pragma warning( disable : 4996 )

class String
{
public:

	// Базовый конструктор
	String()
	{
		length_ = 0;
		str_ = new char[1];
		str_[0] = '\0';
	}

	// Конструктор копирования (правило 3-х)
	String(const String& other)
	{
		length_ = other.length_;
		str_ = new char[length_ + 1];
		std::strcpy(str_, other.str_);
	}

	// Оператор присваивания копированием (правило 3-х)
	String& operator=(const String& other)
	{
		if (this != &other)
		{
			delete[] str_;
			length_ = other.length_;
			str_ = new char[length_ + 1];
			std::strcpy(str_, other.str_);
		}
		return *this;
	}

	// Деструктор (правило 3-х)
	~String()
	{
		delete[] str_;
	}

	// Операторы + и +=
	String operator+(const String& other) const
	{
		String result;
		result.length_ = length_ + other.length_;
		delete[] result.str_;
		result.str_ = new char[result.length_ + 1];
		std::strcpy(result.str_, str_);
		std::strcat(result.str_, other.str_);
		return result;
	}

	String& operator+=(const String& other)
	{
		length_ += other.length_;
		char* temp = new char[length_ + 1];
		std::strcpy(temp, str_);
		std::strcat(temp, other.str_);
		delete[] str_;
		str_ = temp;
		return *this;
	}

	// Оператор [] – чтение и изменение элемента
	char& operator[](int index)
	{
		return str_[index];
	}

	const char& operator[](int index) const
	{
		return str_[index];
	}

	// Операторы <, >, ==
	bool operator<(const String& other) const
	{
		return std::strcmp(str_, other.str_) < 0;
	}

	bool operator>(const String& other) const
	{
		return std::strcmp(str_, other.str_) > 0;
	}

	bool operator==(const String& other) const
	{
		return std::strcmp(str_, other.str_) == 0;
	}

	friend std::istream& operator >> (std::istream& in, const String& p)
	{
		in >> p.str_;
		return in;
	}
	friend std::ostream& operator<<(std::ostream& os, const String& s)
	{
		os << s.str_;
		return os;
	}

	// Метод find – поиск первого вхождения символа в строку слева
	int find(char ch) const
	{
		for (int i = 0; i < length_; i++)
		{
			if (str_[i] == ch)
			{
				return i;
			}
		}
		return -1;
	}

	// Метод length – длина строки
	int length() const
	{
		return length_;
	}
	// метод c_str
	const char* c_str() const
	{
		return str_;
	}
	char& at(int index) const
	{
		if (index < 0 || index >= length_)
		{
			throw std::out_of_range("String::at()");
		}
		return str_[index];
	}



private:
	int length_;
	char* str_;

};

int main()
{
	return 0;
}