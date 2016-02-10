#include <iostream>
using namespace std;
long long int triangle[101][101] = {0};
void tri(){
	triangle[1][1] = 1;
	triangle[1][0] = 1;
	long long int counter = 0;
	for(long int i=2;i<=100;++i){
		for(long int j=0;j<=i;++j){
			if(j == 0)
				triangle[i][0] = 1;
			else if(j == i)
				triangle[i][i] = 1;
			else{
				if(triangle[i-1][j-1] > 1000000)
					triangle[i][j] = triangle[i-1][j-1];
				else if(triangle[i-1][j] > 1000000 )
					triangle[i][j] = triangle[i-1][j];
				else
					triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
				if(triangle[i][j] > 1000000)
					counter++;
			}
		}
	}
	cout << counter << endl;
}
int main() {
	tri();
	return 0;
}