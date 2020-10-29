#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
    unsigned long long int sum =0 ;
    int sum_prop[10000];
    for(int i=0;i<10000;++i)
        sum_prop[i]=0;
    for(int i=2;i<10000;++i)
    {
        {for(int j=1;j<i;++j)
            {if(i%j==0)
                sum_prop[i]+=j;}}
    }
    for(int i=2;i<10000;++i)
    {
        int x = sum_prop[i];
        if(x>=10000)
            continue;
        if(x==i)
            continue;
        if(sum_prop[x]==i)
            sum+=i;
    }
    cout << sum << endl;
    system("pause");
    return 0;
}
