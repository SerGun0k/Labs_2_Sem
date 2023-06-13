#include <iostream>
	template <typename T>
static void COPYARRAY(T* source, T* destination, int size, size_t CAPac)
	{
    std::cout<< CAPac;
		const long long* src1 = (const long long*)source;
		long long* t_src1 = (long long*)destination;
		int m = sizeof(CAPac) * size / sizeof(long long);
		for (int i = 0; i < m; i++)
        {
			*(t_src1++) = *(src1++);
		}
		char* src2 = (char*)src1;
		char* t_src2 = (char*)t_src1;
		m = (sizeof(CAPac) * size) % sizeof(long long);
		for (int i = 0; i < m; i++)
		{
			*(t_src1++) = *(src2++);
		}
	}
int main()
{
	const int N = 20;
	unsigned short int mas_a[N] = { 1,1,1,1,5, 6, 7, 8 };
    unsigned short int mas_b[N] = { 0 };
	std::cout << "mas_a: ";
	for (int i = 0; i < N; i++)
	{
		std::cout << mas_a[i] << " ";
	}
	std::cout << std::endl;
    COPYARRAY(mas_a, mas_b, N,sizeof(mas_a[N]));
	std::cout << "mas_b: ";
	for (int i = 0; i < N; i++)
	{
		std::cout << mas_b[i] << " ";
	}
	std::cout << std::endl;


    delete[] mas_a;
    delete[] mas_b;
	return 0;
}
