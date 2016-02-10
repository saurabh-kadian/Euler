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
	//freopen("input.txt","r",stdin);
	int arr[12] = {0};
	arr[11] = 2;
	for(long long int i=2;i<=7830457;++i){
        long long int carry = 0;
        for(int j=11;j>=0;--j){
            arr[j] *= 2;
            arr[j] += carry;
            carry = arr[j]/10;
            arr[j] %= 10;
        }
	}
	string number = "";
	for(long long int i=0;i<12;++i)
        number += (char)arr[i]+48;
    stringstream ss(number);
    long long int yes;
    ss >> yes;
    yes *= 28433;
    yes++;
    cout << yes%10000000000 << endl;
	return 0;
}
