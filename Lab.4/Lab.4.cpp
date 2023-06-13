#include <iostream>
#include <stdexcept>

template<typename T, int N, int M>
class Matrix 
{
public:
    // Конструкторы
    Matrix() 
    {
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < M; ++j)
            {
                data_[i][j] = T();
            }
        }
    }

    Matrix(const Matrix& other) 
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                data_[i][j] = other.data_[i][j];
            }
        }
    }

    // Оператор присваивания копированием
    Matrix& operator=(const Matrix& other) 
    {
        if (this != &other) 
        {
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < M; ++j) 
                {
                    data_[i][j] = other.data_[i][j];
                }
            }
        }
        return *this;
    }

    // Операторы ввода и вывода
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) 
    {
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < M; ++j) 
            {
                os << matrix.data_[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) 
    {
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < M; ++j) 
            {
                is >> matrix.data_[i][j];
            }
        }
        return is;
    }

    // Операторы +, +=, *, *=
    Matrix operator+(const Matrix& other) const
    {
        Matrix result;
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < M; ++j) 
            {
                result.data_[i][j] = data_[i][j] + other.data_[i][j];
            }
        }
        return result;
    }

    Matrix& operator+=(const Matrix& other) 
    {
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < M; ++j) 
            {
                data_[i][j] += other.data_[i][j];
            }
        }
        return *this;
    }

    Matrix operator*(const Matrix& other) const 
    {
        Matrix result;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j) 
            {
                T sum = T();
                for (int k = 0; k < M; ++k) 
                {
                    sum += data_[i][k] * other.data_[k][j];
                }
                result.data_[i][j] = sum;
            }
        }
        return result;
    }

    Matrix& operator*=(const Matrix& other) 
    {
        *this = *this * other;
        return *this;
    }

    // Оператор ++, который увеличивает все элементы матрицы на 1
    Matrix& operator++() 
    {
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < M; ++j)
            {
                ++data_[i][j];
            }
        }
        return *this;
    }

    // Метод вычисления определителя
    T determinant() const 
    {
        static_assert(N == M, "determinant can be calculated only for square matrices");
        if (N == 1) 
        {
            return data_[0][0];
        }
        if (N == 2) 
        {
            return data_[0][0] * data_[1][1] - data_[0][1] * data_[1][0];
        }
        if (N == 3) 
        {
            return data_[0][0] * data_[1][1] * data_[2][2] +
                data_[0][1] * data_[1][2] * data_[2][0] +
                data_[0][2] * data_[1][0] * data_[2][1] -
                data_[0][2] * data_[1][1] * data_[2][0] -
                data_[0][0] * data_[1][2] * data_[2][1] -
                data_[0][1] * data_[1][0] * data_[2][2];
        }
        throw std::logic_error("determinant can be calculated only for square matrices with size <= 3");
    }

    // Метод или оператор для получения и изменения элемента матрицы по индексу
    T& operator()(int i, int j) 
    {
        if (i < 0 || i >= N || j < 0 || j >= M) 
        {
            throw std::out_of_range("index out of range");
        }
        return data_[i][j];
    }

    const T& operator()(int i, int j) const 
    {
        if (i < 0 || i >= N || j < 0 || j >= M) 
        {
            throw std::out_of_range("index out of range");
        }
        return data_[i][j];
    }

private:
    T data_[N][M];
};

int main() 
{
    setlocale(LC_ALL, "russian");
    Matrix<int, 3, 3> m1;
    std::cin >> m1;
    std::cout << m1 << "##Исходная матрица##" << std::endl;

    Matrix<int, 3, 3> m2 = m1;
    std::cout << m2 << "##Скопированная матрица##" << std::endl;

    m1(1, 2) = 99;
    std::cout << m1 << "##матрица, у который по индексу, изменённый элемент##" << std::endl;

    std::cout << "Определитель = " << m1.determinant() << std::endl;

    ++m1;
    std::cout << m1 << "##Матрица, у которой все элементы +1##" << std::endl;

    m1 *= m2;
    std::cout << m1 << "##Матрица, полученная путем перемножения матриц##" << std::endl;

    return 0;
}

