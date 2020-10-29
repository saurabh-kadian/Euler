#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int count_ten[10]={0,3,3,5,4,4,3,5,5,4};
    int count_teen[10]={3,6,6,8,8,7,7,9,8,8};
    int count_ties[10]={0,0,6,6,5,5,5,7,6,6};
    long int total = 0;
    for(int i=1;i<100;++i)
    {
        int j;
        if(i>=1 && i<=9)
            total+=count_ten[i];
        else if(i>=10 && i<=19)
        {
            j=i%10;
            total+=count_teen[j];
        }
        else if(i>=20 && i<100)
        {
            int ten=i/10,ones=i%10;
            total+=count_ties[ten];
            total+=count_ten[ones];
        }
    }
    for(int i=1;i<10;++i)
        total+=(count_ten[i]+7);
    total+=11;
    for(int i=101;i<1000;++i)
    {
        if(i%100==0)
            continue;
        int j;
        int var = i/100;
        int i_var = i%100;
        if(i_var>=1 && i_var<=9)
            total+=count_ten[i_var];
        else if(i_var>=10 && i_var<=19)
        {
            j=i_var%10;
            total+=count_teen[j];
        }
        else if(i_var>=20 && i_var<100)
        {
            int ten=i_var/10,ones=i_var%10;
            total+=count_ties[ten];
            total+=count_ten[ones];
        }
        total += (count_ten[var]+10);
    }
    cout << total << endl;
    system("pause");
    return 0;
}
