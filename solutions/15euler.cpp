#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int main()
{
    vector<unsigned long long int> arr20;
    arr20.push_back(1);
    int a;
    do{
        cin>>a;
        arr20.push_back(a);
    }while(a!=1);
    for(int i=21;i>1;--i)
    {
        vector<unsigned long long int> temp;
        unsigned long long int num;
        for(int j=0;j<i;++j)
        {
            num = arr20[j] + arr20[j+1];
            temp.push_back(num);
        }
        arr20.clear();
        for(int q=0;q<temp.size();++q)
            arr20.push_back(temp[q]);
    }
    for(int q=0;q<arr20.size();++q)
            cout << arr20[q] << endl;
    system("pause");
    return 0;
}
