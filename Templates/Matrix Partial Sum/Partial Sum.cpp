#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

/* Returns the partial sum of a matrix */
Matrix Matrix_Partial_Sum(Matrix &mat)
{
    int row = mat.size();
    int col = mat[0].size();
    
    Matrix partial_sum(row, vector<int>(col,0));
    
    for(int i=0; i<row; i++)
    {
        int running_sum = 0;
        for(int j=0; j<col; j++)
        {
            if(i>0)
                partial_sum[i][j] = running_sum + mat[i][j] + partial_sum[i-1][j];
            else
                partial_sum[i][j] = running_sum + mat[i][j];
                
            running_sum += mat[i][j];
        }
    }
    
    return partial_sum;
}

void printMatrix(vector<vector<int>> &mat)
{
    cout << endl << "Printing the contents of the Matrix" << endl;

    for(auto &row : mat)
    {
        for(auto ele : row)
            cout << ele << " ";
            
        cout << endl;
    }
    
    cout << endl << "The Matrix has been printed" << endl;
}

void scanMatrix(vector<vector<int>> &mat)
{
    for(auto &row : mat)
        for(auto &ele : row)
            cin >> ele;
}

signed main()
{
    int row, col;
    cin >> row >> col;
    
    Matrix mat(row, vector<int>(col,0));
    scanMatrix(mat);
    
    Matrix  result = Matrix_Partial_Sum(mat);
    printMatrix(result);
    
	return 0;
}

/* Test case
5 6
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
*/

