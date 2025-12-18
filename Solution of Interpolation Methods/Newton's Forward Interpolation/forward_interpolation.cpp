#include <bits/stdc++.h>
using namespace std;

long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

vector<vector<double>> buildForwardTable(const vector<double> &y)
{
    int n = y.size();
    vector<vector<double>> diff(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        diff[i][0] = y[i];

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            diff[i][j] = diff[i + 1][j - 1] - diff[i][j - 1];
        }
    }
    return diff;
}

void printForwardTable(const vector<double> &x, const vector<double> &y, const vector<vector<double>> &diff, ostream &out)
{
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        out << setw(8) << fixed << setprecision(2) << x[i];
        out << setw(8) << fixed << setprecision(2) << diff[i][0];

        for (int j = 1; j < n - i; j++)
        {
            out << setw(8) << fixed << setprecision(2) << diff[i][j];
        }
        out << endl;
    }
}

double newtonForward(const vector<double> &x, const vector<double> &y, double value)
{
    int n = x.size();
    double h = x[1] - x[0];
    double u = (value - x[0]) / h;

    vector<vector<double>> diff = buildForwardTable(y);

    double result = diff[0][0];
    double term = 1.0;

    for (int i = 1; i < n; i++)
    {
        term *= (u - (i - 1));
        result += (term * diff[0][i]) / factorial(i);
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

    fout << "=== Newton's forward interpolation method ===" << endl;
    fout << "Number of data points: " << n << endl;
    fout << "Value to interpolate: x = " << value << endl
         << endl;

    vector<vector<double>> diff = buildForwardTable(y);

    printForwardTable(x, y, diff, cout);
    printForwardTable(x, y, diff, fout);

    double result = newtonForward(x, y, value);

    fout << endl << "Interpolated value at x = " << fixed << setprecision(2) << value
         << " is y = " << result << endl;

    fin.close();
    fout.close();

    return 0;
}