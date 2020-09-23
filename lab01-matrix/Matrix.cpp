#include <string.h>
#include <stdio.h>

struct Matrix
{
private:
    int m; // number of rows
    int n; // number of columns
public:
    float *data;
    void replace(int m, int n, float value);
    int getRows();
    int getColumns();

    Matrix(int m, int n);
    ~Matrix();
};

Matrix::Matrix(int rows, int columns)
{
    this->m = rows;
    this->n = columns;
    this->data = new float[rows * columns];

    for (int i = 0; i < 6; i++)
    {
        float number = i + 0.5;
        this->data[i] = number;
    }
};

Matrix::~Matrix()
{
    delete[] data;
}

int Matrix::getRows()
{
    return this->m;
}

int Matrix::getColumns()
{
    return this->n;
}

void Matrix::replace(int row, int column, float value)
{
    this->data[((row - 1) * this->n) + column - 1] = value;
}

int main()
{
    Matrix TestMatrix = Matrix(2, 3);

    printf("Rows: %i, columns %i\n", TestMatrix.getRows(), TestMatrix.getColumns());

    printf("Test replace before: %f\n", TestMatrix.data[4]);
    TestMatrix.replace(2, 2, 1.3);
    printf("Test replace after: %f\n", TestMatrix.data[4]);

    return 0;
}
