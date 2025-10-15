#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    if (numRows == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);
    int** triangle = (int**)malloc(sizeof(int*) * numRows);

    for (int i = 0; i < numRows; i++) {
        int currentRowLength = i + 1;
        (*returnColumnSizes)[i] = currentRowLength;
        triangle[i] = (int*)malloc(sizeof(int) * currentRowLength);
        
        triangle[i][0] = 1;
        if (currentRowLength > 1) {
            triangle[i][currentRowLength - 1] = 1;
        }

        if (i >= 2) {
            int* prevRow = triangle[i - 1];
            for (int j = 1; j < currentRowLength - 1; j++) {
                triangle[i][j] = prevRow[j - 1] + prevRow[j];
            }
        }
    }

    return triangle;
}
