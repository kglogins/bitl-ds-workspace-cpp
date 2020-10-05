#ifndef DS_MATRIX_H
#define DS_MATRIX_H

#include "Ratio.h"
#include <iostream>
#include <string>

namespace ds_course
{
    template <class T>
    class Matrix
    {
    private:
        int rows;
        int cols;

    public:
        T **a;
        Matrix(int rr, int cc);
        int getRows();
        int getCols();
        Matrix<T> operator+(Matrix<T> rhs);
        Matrix<T> operator-(Matrix<T> rhs);
        Matrix<T> operator*(Matrix<T> rhs);

        bool operator==(const ds_course::Matrix<T> &rhs);

        friend std::istream &operator>>(std::istream &input, ds_course::Matrix<T> &m)
        {
            for (int i = 0; i < m.getRows(); i++)
                for (int j = 0; j < m.getCols(); j++)
                    input >> m.a[i][j];
            return input;
        }

        friend std::ostream &operator<<(std::ostream &oStream, ds_course::Matrix<T> &m)
        {
            for (int i = 0; i < m.getRows(); i++)
            {
                for (int j = 0; j < m.getCols(); j++)
                {
                    oStream << m.a[i][j] << " ";
                }
                oStream << std::endl;
            }

            return oStream;
        }
    };
} // namespace ds_course

template <class T>
ds_course::Matrix<T>::Matrix(int rr, int cc) : rows(rr), cols(cc)
{
    a = new T *[rows];
    for (int i = 0; i < rows; i++)
        a[i] = new T[cols];
}

template <class T>
int ds_course::Matrix<T>::getRows() { return rows; }

template <class T>
int ds_course::Matrix<T>::getCols() { return cols; }

template <class T>
ds_course::Matrix<T> ds_course::Matrix<T>::operator+(ds_course::Matrix<T> rhs)
{
    if (rows != rhs.rows)
    {
        throw std::out_of_range("Row count differ");
    }
    if (cols != rhs.cols)
    {
        throw std::out_of_range("Col count differ");
    }

    Matrix<T> result(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.a[i][j] = a[i][j] + rhs.a[i][j];
        }
    }

    return result;
}

template <class T>
ds_course::Matrix<T> ds_course::Matrix<T>::operator-(ds_course::Matrix<T> rhs)
{
    if (rows != rhs.rows)
    {
        throw std::out_of_range("Row count differ");
    }
    if (cols != rhs.cols)
    {
        throw std::out_of_range("Col count differ");
    }

    Matrix<T> result(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result.a[i][j] = a[i][j] - rhs.a[i][j];
        }
    }

    return result;
}

template <class T>
ds_course::Matrix<T> ds_course::Matrix<T>::operator*(ds_course::Matrix<T> rhs)
{
    if (cols != rhs.rows)
    {
        throw std::out_of_range("Left hand side matrix column count differ from right hand side matrix row count\n");
    }

    Matrix<T> result(rows, rhs.cols);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < rhs.cols; ++j)
        {
            for (int k = 0; k < cols; ++k)
            {
                result.a[i][j] = result.a[i][j] + (a[i][k] * rhs.a[k][j]);
            }
        }
    }

    return result;
}

template <class T>
bool ds_course::Matrix<T>::operator==(const ds_course::Matrix<T> &rhs)
{
    if (rows != rhs.rows)
    {
        throw std::out_of_range("Row count differ");
    }
    if (cols != rhs.cols)
    {
        throw std::out_of_range("Col count differ");
    }
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (!(a[i][j] == rhs.a[i][j]))
                return false;
    return true;
}

#endif /* DS_MATRIX_H */
