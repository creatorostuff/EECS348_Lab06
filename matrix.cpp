#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


//lil function to print matrices
void matrix_print(vector<vector<int>>&matrix)
{
    int N = matrix.size();

    cout << endl;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            printf("%-3i ", matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

//This function asks for the filename to read from, and loads ints into the two matrices
void matrix_read_from_file(vector<vector<int>>&matrix1,vector<vector<int>>&matrix2)
{
    int N;
    int temp;
    string filename;

    cout << "Please enter the text filename to load matrices from:";
    cin >> filename;

    ifstream inputFile(filename);

    inputFile >> N;
    cout << "Size: " << N << " \n";

    cout << "Loading Matrix 1...";
    for(int i=0; i<N; i++)
    {
        matrix1.push_back(vector<int>());
        for(int j=0; j<N; j++)
        {
            inputFile >> temp;
            matrix1[i].push_back(temp);
        }
    }
    cout << "Matrix 1 Loaded.";
    matrix_print(matrix1);

    cout << "Loading Matrix 2...";
    for(int i=0; i<N; i++)
    {
        matrix2.push_back(vector<int>());
        for(int j=0; j<N; j++)
        {
            inputFile >> temp;
            matrix2[i].push_back(temp);
        }
    }
    cout << "Matrix 2 Loaded.";
    matrix_print(matrix2);

    inputFile.close();
}

//This function takes three matrices, adds the first two and saves their result in the third
void matrix_add(vector<vector<int>>&matrix1, vector<vector<int>>&matrix2, vector<vector<int>>&sum)
{
    int N = matrix1.size();
    int temp;

    //add the values at [i,j] of first two matrices and store in sum
    for (int i=0; i<N; i++)
    {
        sum.push_back(vector<int>());
        for (int j=0; j<N; j++)
        {
            temp = matrix1[i][j] + matrix2[i][j];
            sum[i].push_back(temp);
        }
    }

}

/*This function calculates and returns the dot product of two vectors
int dot_product(vector<int> &vector1, vector<int> &vector2)
{
    int N = vector1.size();
    int sum = 0;

    for (int k=0; k<N; k++)
    {
        sum += (vector1[k]*vector2[k]);
    }

    return sum;
}*/ //this ended up not being used

//This function takes three matrices, multiplies the first two and saves the result in the third
void matrix_multiply(vector<vector<int>>&matrix1, vector<vector<int>>&matrix2, vector<vector<int>>&product)
{
    int N = matrix1.size();
    int temp;

    //add the values at [i,j] of first two matrices and store in sum
    for (int i=0; i<N; i++)
    {
        product.push_back(vector<int>());
        for (int j=0; j<N; j++)
        {
            temp = 0;
            for (int k=0; k<N; k++)
            {
                temp += (matrix1[i][k]*matrix2[k][j]);
            }
            product[i].push_back(temp);
        }
    }
}

//This function subtracts the second matrix from the first and stores the difference in the third
//td;lr peforms matrix1 - matrix2 = difference
void matrix_subtract(vector<vector<int>>&matrix1, vector<vector<int>>&matrix2, vector<vector<int>>&difference)
{
    int N = matrix1.size();
    int temp;

    //add the values at [i,j] of first two matrices and store in sum
    for (int i=0; i<N; i++)
    {
        difference.push_back(vector<int>());
        for (int j=0; j<N; j++)
        {
            temp = matrix1[i][j] - matrix2[i][j];
            difference[i].push_back(temp);
        }
    }

}

//This function updates an element of a matrix, given the matrix, and i and j indices
//Does nothing if the row or col are out of bounds
void matrix_update_element(vector<vector<int>>&matrix, int row, int col, int new_val)
{
    int N = matrix.size();

    if((row>=N) || (col>=N))
    {
        cout << "Row or Column out of bounds. Matrix not updated." << endl;
        return;
    }

    matrix[row][col] = new_val;
}

//This function finds and returns the maxium value stored in the matrix
int matrix_get_max(vector<vector<int>>&matrix)
{
    int N = matrix.size();
    int max = matrix[0][0];

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            if(matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
    }

    return max;
}

void matrix_transpose(vector<vector<int>>&matrix)
{
    int N = matrix.size();
    int temp;

    for (int i=0; i<N; i++)
    {
        for(int j=i; j<N; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main()
{
    //we are always going to have 2 NxN matrices, N is the size stored in the first line of the input file
    //int N;

    //initialize variables
    int row;
    int col;
    int val;
    int max;

    //initialize matrices
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    vector<vector<int>> sum;
    vector<vector<int>> product;
    vector<vector<int>> difference;

    //1&2 read data in from file; reading the data also prints the matrices to make sure that they loaded correctly
    matrix_read_from_file(matrix1, matrix2);

    //3 add matrices
    matrix_add(matrix1, matrix2, sum);
    cout << "SUM";
    matrix_print(sum);

    //4 multiply matrices
    matrix_multiply(matrix1, matrix2, product);
    cout << "PRODUCT";
    matrix_print(product);

    //5 subtract matrices. In this case subtract the second matrix from the first
    matrix_subtract(matrix1, matrix2, difference);
    cout << "DIFFERENCE";
    matrix_print(difference);

    //6 update matrix element given row and column. check row/column validity
    cout << "Please enter the row index of the first matrix you wish to update: ";
    cin >> row;

    cout << "Please enter the column index of the first matrix you wish to update: ";
    cin >> col;

    cout << "Please enter the value you wish to update the matrix at [" << row << "][" << col << "] to: ";
    cin >> val;

    matrix_update_element(matrix1, row, col, val);
    cout << "UPDATED MATRIX";
    matrix_print(matrix1);

    //7 find max value of the first matrix
    max = matrix_get_max(matrix1);
    cout << "The max value of the first matrix is: " << max << "." << endl;

    //8 transpose first matrix
    matrix_transpose(matrix1);
    cout<< "\nTRANSPOSED MATRIX";
    matrix_print(matrix1);

    return 0;
}