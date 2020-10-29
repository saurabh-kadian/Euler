#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main()
{
    freopen("triangle.txt","r",stdin);
    unsigned long long int arr[100][100],score[100][100];
    for(int i=0;i<100;++i)
        for(int j=0;j<=i;++j)
            cin >> arr[i][j];
    for(int i=0;i<100;++i)
        for(int j=0;j<100;++j)
            score[i][j]=0;
    score[0][0]=arr[0][0];
    for(int i=1;i<100;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(j==0)
                {score[i][j]=arr[i][j]+score[i-1][j];
                continue;}
            if(j==i)
                {score[i][j]=arr[i][j]+score[i-1][j-1];continue;}
            if((arr[i][j]+score[i-1][j])>(arr[i][j]+score[i-1][j-1]))
                score[i][j]=arr[i][j]+score[i-1][j];
            else
                score[i][j]=arr[i][j]+score[i-1][j-1];
        }
    }
    unsigned long long int maxx = 0;
    for(int i=0;i<100;++i)
        if(score[99][i]>maxx)
            maxx=score[99][i];
    cout << maxx << endl;
    system("pause");
    return 0;
}
