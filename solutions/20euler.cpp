#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int arr[200],carry[200];
    for(int i=0;i<200;++i)
    {
        arr[i] = -1;
        carry[i] = 0;
    }
    arr[199]=1;
    for(int i=2;i<=100;++i)
    {
        int index = 199;
        while(arr[index]!=(-1))
        {
            int temp = arr[index] * i;
            arr[index] = temp%10;
            temp/=10;
            carry[index-1] += temp;
            index--;
        }
        index = 199;
        while(arr[index]!=(-1))
        {
                arr[index]+=carry[index];
                if(arr[index]>9)
                {
                    int x = arr[index];
                    arr[index]=arr[index]%10;
                    carry[index-1] += (x/10);
                }
            index--;
        }
        int temper = index;
        if(carry[index]!=0)
        {
            int temp_index = index;
            while(carry[index]!=0)
            {
                arr[temp_index]=carry[index]%10;
                carry[index]/=10;
                temp_index--;
            }
        }
        for(int i=0;i<200;++i)
            carry[i]=0;
    }
    int index = 199;
    unsigned long long int sum = 0;
    while(arr[index]!=(-1))
        {sum+=arr[index];
        index--;}
        cout << sum << endl;
    system("pause");
    return 0;
}
