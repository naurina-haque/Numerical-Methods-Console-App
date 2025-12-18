#include <bits/stdc++.h>
using namespace std;

double determinant(vector<vector<double>> &matrix, int n)
{
    double det = 0;

    if (n == 1)
        return matrix[0][0];

    if (n == 2)
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    vector<vector<double>> temp(n, vector<double>(n));
    int sign = 1;

    for (int f = 0; f < n; f++)
    {
        int subI = 0;
        for (int i = 1; i < n; i++)
        {
            int subJ = 0;
            for (int j = 0; j < n; j++)
            {
                if (j != f)
                {
                    temp[subI][subJ] = matrix[i][j];
                    subJ++;
                }
            }
            subI++;
        }

        det += sign * matrix[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    return det;
}

void getCofactor(vector<vector<double>> &matrix, vector<vector<double>> &temp, int p, int q, int n)
{
    int i = 0, j = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = matrix[row][col];

                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

void adjoint(vector<vector<double>> &matrix, vector<vector<double>> &adj, int n)
{
    if (n == 1)
    {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    vector<vector<double>> temp(n, vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getCofactor(matrix, temp, i, j, n);

            sign = ((i + j) % 2 == 0) ? 1 : -1;

            adj[j][i] = sign * determinant(temp, n - 1);
        }
    }
}

bool inverse(vector<vector<double>> &matrix, vector<vector<double>> &inv, int n)
{
    double det = determinant(matrix, n);

    if (abs(det) < 1e-10)
    {
        cout << "Singular matrix, can't find its inverse" << endl;
        return false;
    }

    vector<vector<double>> adj(n, vector<double>(n));
    adjoint(matrix, adj, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inv[i][j] = adj[i][j] / det;
        }
    }

    return true;
}

void printMatrix(vector<vector<double>> &matrix, int n, ostream &out)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            out << setw(12) << fixed << setprecision(2) << matrix[i][j];
        }
        out << endl;
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open())
    {
        cerr << "Error: Unable to open input.txt" << endl;
        return 1;
    }

    if (!fout.is_open())
    {
        cerr << "Error: Unable to open output.txt" << endl;
        return 1;
    }

    int n;
    fin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));
    vector<vector<double>> inv(n, vector<double>(n));

    // Read matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fin >> matrix[i][j];
        }
    }

    fout << "=== Matrix inversion using adjoint method ===" << endl;
    fout << endl;

    fout << "Original Matrix:" << endl;
    printMatrix(matrix, n, fout);
    fout << endl;

    double det = determinant(matrix, n);
    fout << "Determinant: " << fixed << setprecision(2) << det << endl
         << endl;
    cout << "Determinant: " << fixed << setprecision(2) << det << endl
         << endl;

    vector<vector<double>> adj(n, vector<double>(n));
    adjoint(matrix, adj, n);
    fout << "Adjoint Matrix:" << endl;
    printMatrix(adj, n, fout);
    fout << endl;

    if (inverse(matrix, inv, n))
    {
        fout << "Inverse Matrix:" << endl;
        printMatrix(inv, n, fout);
        fout << endl;
        fout << "Verification (A * A^-1):" << endl;

        vector<vector<double>> identity(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    identity[i][j] += matrix[i][k] * inv[k][j];
                }
            }
        }
        printMatrix(identity, n, fout);
    }
    else
    {
        fout << "Matrix is singular, inverse does not exist." << endl;
    }


    fin.close();
    fout.close();

    return 0;
}
