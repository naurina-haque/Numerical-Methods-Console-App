#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> buildDividedTable(const vector<double> &x, const vector<double> &y)
{
    int n = x.size();
    vector<vector<double>> table(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        table[i][0] = y[i];

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
    return table;
}
void printDividedTable(const vector<double> &x, const vector<double> &y, const vector<vector<double>> &table, ostream &out)
{
    int n = x.size();

    for (int i = 0; i < n; i++)
    {
        out << setw(8) << fixed << setprecision(2) << x[i];
        out << setw(8) << fixed << setprecision(2) << table[i][0];

        for (int j = 1; j < n - i; j++)
        {
            out << setw(8) << fixed << setprecision(2) << table[i][j];
        }
        out << endl;
    }
}

double newtonDivided(const vector<double> &x, const vector<double> &y, double value)
{
    int n = x.size();

    vector<vector<double>> table = buildDividedTable(x, y);

    double result = table[0][0];
    double term = 1.0;

    for (int i = 1; i < n; i++)
    {
        term *= (value - x[i - 1]);
        result += table[0][i] * term;
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

    double x_extra, y_actual;
    fin >> x_extra >> y_actual;

    fout << "=== Newton's Divided Difference Interpolation Method ===" << endl;
    fout << endl;
    fout << "Number of data points: " << n << endl;
    fout << "Value to interpolate: x = " << value << endl
         << endl;

    vector<vector<double>> table = buildDividedTable(x, y);

    printDividedTable(x, y, table, cout);
    printDividedTable(x, y, table, fout);

    double result = newtonDivided(x, y, value);

    fout << "Interpolated value at x = " << fixed << setprecision(2) << value
         << " is y = " << result << endl;

    double y_interpolated = newtonDivided(x, y, x_extra);
    double absolute_error = fabs(y_actual - y_interpolated);

    double relative_error;
    if (fabs(y_actual) > 1e-10)
    {
        relative_error = (absolute_error / fabs(y_actual)) * 100;
    }
    else
    {
        relative_error = 0;
    }

    fout << "\n=== Error calculation ===" << endl;
    fout << "Extra data point: x = " << fixed << setprecision(2) << x_extra << endl;
    fout << "Actual value: f(" << x_extra << ") = " << setprecision(2) << y_actual << endl;
    fout << "Interpolated value: f(" << x_extra << ") = " << setprecision(2) << y_interpolated << endl;
    fout << "Absolute Error: " << setprecision(2) << absolute_error << endl;
    fout << "Relative Error: " << fixed << setprecision(2) << relative_error << "%" << endl;

    fin.close();
    fout.close();

    return 0;
}