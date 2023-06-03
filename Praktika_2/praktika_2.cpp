#include <iostream>
#include <cstdint>


void copyArray(void* source, void* destination, size_t cnt)
{
	uint64_t* ps = (uint64_t*)source;
	uint64_t* pd = (uint64_t*)destination;
	for (int i = 0; i < cnt; i++) {
		*(pd++) = *(ps++);
	}
	if (((cnt * sizeof(int)) % 8) == 4) 
	{
		uint32_t* ps32res = (uint32_t*)((uintptr_t)source + sizeof(uint64_t) );
		uint32_t* pd32res = (uint32_t*)((uintptr_t)destination + sizeof(uint64_t) );
		*(pd32res) = *(ps32res);
	}

	if ((cnt * sizeof(int)) % 8 == 0)
	{
		uint64_t* psres = (uint64_t*)((uintptr_t)source + sizeof(uint64_t) );
		uint64_t* pdres = (uint64_t*)((uintptr_t)destination + sizeof(uint64_t) );
		*(pdres) = *(psres);
	}

	if ((((cnt * sizeof(int)) % 8) >= 1) && (((cnt * sizeof(int)) % 8) < 3))
	{
		char* ps8res = (char*)((uintptr_t)source + sizeof(uint64_t) );
		char* pd8res = (char*)((uintptr_t)destination + sizeof(uint64_t) );
		*(pd8res) = *(ps8res);
	}
}

int main() {
	setlocale(LC_ALL, "russian");
	const int N = 13;
	int* A = new int[N];
	int* B = new int[N];

	// Инициализация исходного массива
	for (int i = 0; i < N; i++) {
		A[i] = i;
	}

	// Копирование массива
	copyArray(A, B, N);
	// вывод результата копирования
	for (int i = 0; i < N; i++)
	{
		std::cout << B[i] << " ";
	}

	// Освобождение памяти
	delete[] A;
	delete[] B;

	return 0;
}
