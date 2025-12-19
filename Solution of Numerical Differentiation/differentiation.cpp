#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open())
    {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }

    int n;
    double x, h, u, v, dy_dx;

    fin >> n;

    vector<double> X(n), Y(n);
    for (int i = 0; i < n; i++)
        fin >> X[i];
    for (int i = 0; i < n; i++)
        fin >> Y[i];

    fin >> x;

    h = X[1] - X[0];

    vector<vector<double>> diff(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        diff[i][0] = Y[i];

    for (int j = 1; j < n; j++)
        for (int i = 0; i < n - j; i++)
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];

    if (x <= X[n / 2]) 
    {
        u = (x - X[0]) / h;

        dy_dx = diff[0][1];
        dy_dx += (2 * u - 1) * diff[0][2] / 2.0;
        dy_dx += (3 * u * u - 6 * u + 2) * diff[0][3] / 6.0;

        dy_dx /= h;

        fout << "\nUsing Newton's Forward Differentiation:\n";
    }
    else
    {
        v = (x - X[n - 1]) / h;

        dy_dx = diff[n - 2][1];
        dy_dx += (2 * v + 1) * diff[n - 3][2] / 2.0;
        dy_dx += (3 * v * v + 6 * v + 2) * diff[n - 4][3] / 6.0;

        dy_dx /= h;

        fout << "\nUsing Newton's Backward Differentiation:\n";
    }

    fout << "First derivative at x = " << x << " is " << dy_dx << endl;

    fin.close();
    fout.close();

    return 0;
}
