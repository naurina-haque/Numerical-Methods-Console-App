#include <bits/stdc++.h>

using namespace std;

int deg;
vector<int>ax;

double f(double x)
{
    double y=0;
    for(int i=0; i<=deg; i++)
    {
        y+=pow(x,deg-i)*ax[i];
    }
    return y;
}
double exact_integral(double a, double b)
{
    double result=0;
    for(int i=0; i<=deg; i++)
    {
        int power=deg-i+1;
        result+=ax[i]*(pow(b,power)-pow(a,power))/power;
    }
    return result;
}

void print_function_in_file(ofstream &fout)
{
    fout<<"f(x)=";
    for (int i=0; i<=deg; i++)
    {
        if (ax[i]==0)continue;

        if(i!=0 && ax[i]>0)
            fout<<"+";

        fout<<ax[i];

        if(deg-i>0)
            fout<<"x";
        if (deg-i>1)
            fout<<"^"<<(deg-i);
    }
    fout<<endl;
}

int main()
{
    ifstream fin("input.txt");
    if(!fin)
    {
        cout<<"File not found"<<endl;
        return 0;
    }

    ofstream fout("output.txt");
    if(!fout)
    {
        cout<<"File not found"<<endl;
        return 0;
    }

    double b,a;
    int n;
    if (!(fin>>deg))
    {
        fin.clear();
        fin.seekg(0, ios::beg);
        fin>>deg;
    }

    ax.resize(deg+1);
    for(int i=0; i<=deg; i++)
    {
        fin>>ax[i];
    }
    fin>>b;
    fin>>a;
    fin>>n;






    double h=(b-a)/n;
    vector<double>x(n+1),y(n+1);
    x[0]=a;
    for(int i=1; i<=n; i++)
    {
        x[i]=x[i-1]+h;
    }
    for(int i=0; i<=n; i++)
    {
        y[i]=f(x[i]);
    }
    double y1=y[0]+y[n];
    double y2=0,y3=0;
    for(int i=1; i<n; i+=2)
    {
        y2+=y[i];
    }
    for(int i=2; i<n; i+=2)
    {
        y3+=y[i];
    }
    y2=4*y2;
    y3=2*y3;
    double simpson=(h/3)*(y1+y2+y3);
    double exact=exact_integral(a,b);
    double relative_error=fabs((exact-simpson)/exact);



    print_function_in_file(fout);
    fout<<fixed<<setprecision(5);
    fout<<"Simpson's 1/3 Result: "<<simpson<< endl;
    fout<<"Exact Integral: "<<exact<< endl;
    fout<<"Relative Error: "<<relative_error<< endl;
    fout<<endl;



    fin.close();
    fout.close();
    return 0;
}
