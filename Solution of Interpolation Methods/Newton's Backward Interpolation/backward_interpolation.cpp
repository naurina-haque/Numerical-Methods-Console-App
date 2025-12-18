#include <bits/stdc++.h>
#include <fstream>
#include <iomanip>

using namespace std;

long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

vector<vector<double>> buildBackwardTable(const vector<double> &y)
{
    int n = y.size();
    vector<vector<double>> diff(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++)
    {
        for (int i = n - 1; i >= j; i--)
        {
            diff[i][j] = diff[i][j - 1] - diff[i - 1][j - 1];
        }
    }
    return diff;
}

void printBackwardTable(const vector<double> &x, const vector<double> &y, const vector<vector<double>> &diff, ostream &out)
{
    int n = x.size();
    out << "Backward Difference Table:" << endl;

    for (int i = 0; i < n; i++)
    {
        out << setw(8) << fixed << setprecision(2) << x[i];
        out << setw(8) << fixed << setprecision(2) << diff[i][0];

        for (int j = 1; j < n && i >= j; j++)
        {
            out << setw(8) << fixed << setprecision(2) << diff[i][j];
        }
        out << endl;
    }
}

double newtonBackward(const vector<double> &x, const vector<double> &y, double value)
{
    int n = x.size();
    double h = x[1] - x[0];
    double u = (value - x[n - 1]) / h;

    vector<vector<double>> diff = buildBackwardTable(y);

    double result = diff[n - 1][0];
    double term = 1.0;

    for (int i = 1; i < n; i++)
    {
        term *= (u + (i - 1));
        result += (term * diff[n - 1][i]) / factorial(i);
    }

    return result;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    vector<double> x(n), y(n);

    for (int i = 0; i < n; i++)
    {
        fin >> x[i];
    }

    for (int i = 0; i < n; i++)
    {
        fin >> y[i];
    }

    double value;
    fin >> value;

    fout << "=== Newton's backward interpolation method ===" << endl;
    fout << "Number of data points: " << n << endl;
    fout << "Value to interpolate: x = " << value << endl
         << endl;

    vector<vector<double>> diff = buildBackwardTable(y);
    printBackwardTable(x, y, diff, cout);
    printBackwardTable(x, y, diff, fout);

    double result = newtonBackward(x, y, value);
    fout << endl;
    fout << "Interpolated value at x = " << fixed << setprecision(2) << value
         << " is y = " << fixed << setprecision(2) << result << endl;

    fin.close();
    fout.close();

    return 0;
}