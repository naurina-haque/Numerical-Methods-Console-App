#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t=1;
    while(t)
    {
        int n;
        cout<<"Enter number of Equations: ";
        cin>>n;
        cout<<"Enter the augmented matrix:"<<endl;
        vector<vector<double>>a(n,vector<double>(n+1));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n+1; j++)
                cin>>a[i][j];
        }

        for(int i=0; i<n; i++)
        {
            if(fabs(a[i][i])<1e-6)
            {
                bool swapped=false;
                for(int j=i+1; j<n; j++)
                {
                    if(fabs(a[j][i])>1e-6)
                    {
                        swap(a[i],a[j]);
                        swapped=true;
                        break;
                    }
                }
                if(!swapped)
                {
                    cout<<"Matrix is singular"<<endl;
                    break;
                }
            }

            for(int j=i+1; j<n; j++)
            {
                double f=a[j][i]/a[i][i];
                for(int k=i; k<n+1; k++)
                {
                    a[j][k]=a[j][k]-a[i][k]*f;
                }
            }

        }
         cout<<"Upper Triangular Matrix:"<<endl;
        for(int i=0; i<n; i++)
            {
                for(int j=0; j<n+1; j++)
                    if(fabs(a[i][j])<1e-6)
                        cout<<"0"<<" ";
                    else
                        cout<<setprecision(3)<<a[i][j]<<" ";
                cout<<endl;
            }

        bool allzero;
        int x=1;
        for(int i=0; i<n; i++)
        {
            allzero=true;
            for(int j=0; j<n; j++)
            {
                if(fabs(a[i][j])>1e-6)
                {
                    allzero=false;
                    break;
                }
            }
            if(allzero && fabs(a[i][n])>1e-6)
            {
                cout<<"No solution"<<endl;
                x=0;
                break;
            }
            else if(allzero && fabs(a[i][n])<1e-6)
            {
                cout<<"Infinite solution"<<endl;
                x=0;
                break;
            }
        }
        if(x==0)
        {
            cout<<"Solve another system?(y/n)"<<endl;
            char a;
            cin>>a;
            if(a=='y')
                t=1;
            else
                t=0;
        }

        else
        {
            vector<double>x(n);
            double sum;
           for(int i=n-1;i>=0;i--)
           {
               sum=a[i][n];
               for(int j=i+1;j<n;j++)
               {
                   sum-=a[i][j]*x[j];
               }
               x[i]=sum/a[i][i];
           }
            cout<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<"x"<<i+1<<"= "<<x[i]<<endl;
            }

            cout<<"Solve another system?(y/n)"<<endl;
            char a;
            cin>>a;
            if(a=='y')
                t=1;
            else
                t=0;
        }

    }

    return 0;
}

