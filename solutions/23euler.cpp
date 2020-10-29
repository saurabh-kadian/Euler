#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    unsigned long long int sum = 0;
    long long int check[28123],sum_fact[28123];
    for(int i=0;i<28123;++i)
        check[i]=sum_fact[i]=0;
    for(int i=2;i<28123;++i)
    {
        for(int j=1;j<i;++j)
        {
            if(i%j==0)
                sum_fact[i]+=j;
        }
        if(sum_fact[i]>i)
            check[i]=1;
    }
    for(int i=1;i<=28123;++i)
    {
        bool is = true;
        for(int j=4;(j<i)&&(is==true);++j)
        {
            int a = i-j;
            if(check[a]==1&&check[j]==1)
                is=false;
        }
        if(is==true)
          sum+=i;
    }
    cout << "ProjectEuler 23 : " << sum << endl;
    return 0;
}
