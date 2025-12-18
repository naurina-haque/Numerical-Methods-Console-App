#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    if(!fin)
    {
        cout<<"Input file not found"<<endl;
        return 0;
    }

    ofstream fout("output.txt",ios::app);
    if(!fout)
    {
        cout<<"Output file not found"<<endl;
        return 0;
    }

    int n;
    if(!(fin>>n))
    {
        cout<<"End of file"<<endl;
        return 0;
    }

    vector<vector<double>>a(n,vector<double>(n+1));
    vector<vector<double>>l(n,vector<double>(n,0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n+1; j++)
            fin>>a[i][j];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            l[i][i]=1;
    }

    vector<double>b(n);
    for(int j=0; j<n; j++)
        b[j]=a[j][n];

    for(int i=0; i<n-1; i++)
    {
        if(fabs(a[i][i])<1e-6)
        {
            bool swapp=false;
            for(int j=i+1; j<n; j++)
            {
                if(fabs(a[j][i])>1e-6)
                {
                    swap(a[i],a[j]);
                    swapp=true;
                    break;
                }
            }
            if(!swapp)
            {
                fout<<"Singular Matrix"<<endl;
                return 0;
            }
        }
        else
        {
            for(int j=i+1; j<n; j++)
            {
                double f=a[j][i]/a[i][i];
                l[j][i]=f;

                for(int k=i; k<n+1; k++)
                {
                    a[j][k]-=f*a[i][k];
                }
            }
        }
    }

    fout<<"Lower triangular Matrix"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            fout<<setprecision(3)<<l[i][j]<<" ";
        fout<<endl;
    }

    fout<<"Upper triangular Matrix"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            fout<<setprecision(3)<<a[i][j]<<" ";
        fout<<endl;
    }

    bool trap=false;
    for(int i=0; i<n; i++)
    {
        bool all=true;
        for(int j=0; j<n; j++)
        {
            if(fabs(a[i][j])>1e-6)
            {
                all=false;
                break;
            }
        }
        if(all && fabs(a[i][n])>1e-6)
        {
            fout<<"No Solution"<<endl;
            trap=true;
            break;
        }
        if(all && fabs(a[i][n])<1e-6)
        {
            fout<<"Infinite Solution"<<endl;
            trap=true;
            break;
        }
    }

    if(trap)
    {
        return 0;
    }

    vector<double>y(n);
    for(int i=0; i<n; i++)
    {
        double sum=0;
        for(int j=0; j<i; j++)
        {
            sum+=l[i][j]*y[j];
        }
        y[i]=b[i]-sum;
    }

    vector<double>x(n);
    for(int i=n-1; i>=0; i--)
    {
        double sum=0;
        for(int j=i+1; j<n; j++)
        {
            sum+=a[i][j]*x[j];
        }
        x[i]=(y[i]-sum)/a[i][i];
    }

    fout<<"System has Unique Solution"<<endl;
    fout<<"Value of y"<<endl;
    for(int i=0; i<n; i++)
    {
        fout<<setprecision(3)<<y[i]<<" ";
    }
    fout<<endl;

    fout<<"Value of x"<<endl;
    for(int i=0; i<n; i++)
    {
        fout<<setprecision(3)<<x[i]<<" ";
    }
    fout<<endl;

    return 0;
}
