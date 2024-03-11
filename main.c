#include "matrix.h"
#include <assert.h>

int countZeroRows(matrix *m);

void test_countZeroRows() 
{
    const int arr[] = 
    {
        1, 1, 0,
        0, 0, 0,
        0, 0, 1,
        0, 0, 0,
        0, 1, 1,
    };

    matrix m = createMatrixFromArray(arr, 5, 3);
    assert(countZeroRows(&m) == 2);

    outputMatrix(&m);
}

int countZeroRows(matrix *m)
{
    int *row, count = 0;
    bool answ;

    for(int i = 0; i < m->nRows; i++)
    {
        row = m->values[i];

        answ = true;

        for(int j = 0; j < m->nCols; j++)
        {
            if(row[j] != 0)
            {
                answ = false;
                break;
            }
        }

        if(answ)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    test_countZeroRows();

    return 0;
}