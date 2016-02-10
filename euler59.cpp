#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iterator>

using namespace std;

int main(){
    freopen("cipher.txt","r",stdin);
    int count = 1201;
    int arr[count];
    char ch;
    for(int i=0;i<count;++i)
        cin >> arr[i] >> ch;
    long long int total = 0;
    for(int i=103;i<104;++i){
        for(int j=111;j<112;++j){
            for(int k=100;k<101;++k){
                cout << i << " " << j << " " << k << endl;
                for(int q=0;q<count;++q){
                    if(q%3 == 0)
                        total += (arr[q]^i);
                    else if(q%3 == 1)
                        total += (arr[q]^j);
                    else
                        total += (arr[q]^k);
                }
                cout << total << endl;
            }
        }
    }

	return 0;
}
