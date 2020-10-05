#include <iomanip>
#include "Ratio.h"
#include "Matrix.h"

using namespace ds_course;
using namespace std;
int main()
{
    std::string leftMatrixType, rightMatrixType, matrixOperation;
    int rows;
    int columns;

    cin >> leftMatrixType >> rows >> columns;

    if (leftMatrixType[0] != 'M' || leftMatrixType.size() != 2)
    {
        cout << "Type defined wrong" << std::endl;
        ;
        return 0;
    }

    if (leftMatrixType[1] == 'Z')
    {
        Matrix<int> leftMatrix(rows, columns);
        cin >> leftMatrix;

        cin >> rightMatrixType >> rows >> columns;

        if (leftMatrixType.compare(rightMatrixType) != 0)
        {
            cout << "The matrice's types differ" << std::endl;
            return 0;
        }

        Matrix<int> rightMatrix(rows, columns);
        cin >> rightMatrix;

        cin >> matrixOperation;

        if (matrixOperation.compare("ADD") == 0)
        {
            try
            {
                Matrix<int> result = leftMatrix + rightMatrix;
                cout << leftMatrixType << " " << result.getRows() << " " << result.getCols() << std::endl;
                cout << result;
                return 1;
            }
            catch (const std::out_of_range &e)
            {
                cout << "out_of_range" << std::endl;
            }
        }
        else if (matrixOperation.compare("SUB") == 0)
        {
            try
            {
                Matrix<int> result = leftMatrix - rightMatrix;
                cout << leftMatrixType << " " << result.getRows() << " " << result.getCols() << std::endl;
                cout << result;
                return 1;
            }
            catch (const std::out_of_range &e)
            {
                cout << "out_of_range" << std::endl;
            }
        }
        else if (matrixOperation.compare("MUL") == 0)
        {
            try
            {
                Matrix<int> result = leftMatrix * rightMatrix;
                cout << leftMatrixType << " " << result.getRows() << " " << result.getCols() << std::endl;
                cout << result;
                return 1;
            }
            catch (const std::out_of_range &e)
            {
                cout << "out_of_range" << std::endl;
            }
        }
        else
        {
            cout << "Wrong matrix operation" << std::endl;
        }
    }
    else if (leftMatrixType[1] == 'Q')
    {
        Matrix<Ratio> leftMatrix(rows, columns);
        cin >> leftMatrix;

        cin >> rightMatrixType >> rows >> columns;

        if (leftMatrixType.compare(rightMatrixType) != 0)
        {
            cout << "The matrice's types differ" << std::endl;
            return 0;
        }

        Matrix<Ratio> rightMatrix(rows, columns);
        cin >> rightMatrix;

        cin >> matrixOperation;

        if (matrixOperation.compare("ADD") == 0)
        {
            try
            {
                Matrix<Ratio> result = leftMatrix + rightMatrix;
                cout << leftMatrixType << " " << result.getRows() << " " << result.getCols() << std::endl;
                cout << result;
                return 1;
            }
            catch (const std::out_of_range &e)
            {
                cout << "out_of_range" << std::endl;
            }
        }
        else if (matrixOperation.compare("SUB") == 0)
        {
            try
            {
                Matrix<Ratio> result = leftMatrix - rightMatrix;
                cout << leftMatrixType << " " << result.getRows() << " " << result.getCols() << std::endl;
                cout << result;
                return 1;
            }
            catch (const std::out_of_range &e)
            {
                cout << "out_of_range" << std::endl;
            }
        }
        else if (matrixOperation.compare("MUL") == 0)
        {
            try
            {
                Matrix<Ratio> result = leftMatrix * rightMatrix;
                cout << leftMatrixType << " " << result.getRows() << " " << result.getCols() << std::endl;
                cout << result;
                return 1;
            }
            catch (const std::out_of_range &e)
            {
                cout << "out_of_range" << std::endl;
            }
        }
        else
        {
            cout << "Wrong matrix operation" << std::endl;
        }
    }
    else if (leftMatrixType[1] == 'R')
    {
        Matrix<double> leftMatrix(rows, columns);
        cin >> leftMatrix;

        cin >> rightMatrixType >> rows >> columns;

        if (leftMatrixType.compare(rightMatrixType) != 0)
        {
            cout << "The matrice's types differ" << std::endl;
            return 0;
        }

        Matrix<double> rightMatrix(rows, columns);
        cin >> rightMatrix;

        cin >> matrixOperation;

        if (matrixOperation.compare("ADD") == 0)
        {
            try
            {
                Matrix<double> result = leftMatrix + rightMatrix;
                cout << leftMatrixType << " " << result.getRows() << " " << result.getCols() << std::endl;
                cout << std::fixed << std::setprecision(5) << result;
                return 1;
            }
            catch (const std::out_of_range &e)
            {
                cout << "out_of_range" << std::endl;
            }
        }
        else if (matrixOperation.compare("SUB") == 0)
        {
            try
            {
                Matrix<double> result = leftMatrix - rightMatrix;
                cout << leftMatrixType << " " << result.getRows() << " " << result.getCols() << std::endl;
                cout << std::fixed << std::setprecision(5) << result;
                return 1;
            }
            catch (const std::out_of_range &e)
            {
                cout << "out_of_range" << std::endl;
            }
        }
        else if (matrixOperation.compare("MUL") == 0)
        {
            try
            {
                Matrix<double> result = leftMatrix * rightMatrix;
                cout << leftMatrixType << " " << result.getRows() << " " << result.getCols() << std::endl;
                cout << std::fixed << std::setprecision(5) << result;
                return 1;
            }
            catch (const std::out_of_range &e)
            {
                cout << "out_of_range" << std::endl;
            }
        }
        else
        {
            cout << "Wrong matrix operation" << std::endl;
        }
    }
    else
    {
        cout << "Such matrix type is not supported\n";
    }

    // rational arithmetic
    // It is not quite right: fractions not simplified
    // Ratio r1(-17, -34);
    // Ratio r2(1, 3);
    // cout << (r1 + r2) << endl;

    // Matrix<Ratio> m1(2, 2);
    // Matrix<Ratio> m2(2, 2);
    // cin >> m1 >> m2;
    // cout << "(m1 == m2) is " << ((m1 == m2) ? "true" : "false") << endl;
    // cout << "m2.a[1][1] = " << m2.a[1][1] << endl;
}
