#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    int arr[]={0,1,2,3,4,5,6,7,8,9};
    int i=0;
    do{
        i++;
        if(i==1000000)
            break;
    }while(next_permutation(arr,arr+10));
    for(int i=0;i<10;++i)
        cout << arr[i];
    cout << "\n";
    system("pause");
    return 0;
}
