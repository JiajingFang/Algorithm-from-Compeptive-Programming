// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;
/*
Sample Input 3 Sample Output 3
5 4
1 0 0 1
1 1 0 0
1 0 0 0
1 0 0 0
1 1 1 1
3
				2 3 4 4
Sample Input 4 Sample Output 4
6 5
0 0 0 0 0
1 0 0 0 1
0 0 0 0 0
0 0 0 0 0
0 1 0 0 0
0 0 0 0 0
3
				1 2 3 4
Sample Input 5 Sample Output 5
4 4
1 1 1 1
1 0 0 1
1 0 0 1
1 1 1 1
3
				-1 -1 -1 -1
*/

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
    

int main() {
	ios::sync_with_stdio(false);
	ll h,w,H;
	cin>>h>>w;
	int tmp;
	vector<vector<int>> hist(1,vector<int>(w,1));
	for(ll i=0;i<w;i++){
		cin>>tmp;
		hist[0][i]-=tmp;
	} 
	for(ll i=1;i<h;i++){
		vector<int> tmpv;
		for(ll j=0;j<w;j++){
			cin>>tmp;
			if(tmp) tmp=0;
			else tmp=hist[i-1][j]+1;
			tmpv.emplace_back(tmp);
		}
		tmpv.emplace_back(-1);
		hist.emplace_back(tmpv);
		
	}
	/*
	Sample Input 1
	0 1 1 0
	0 0 2 1 -1
	0 1 3 2 -1
	0 2 4 3 -1
	0 0 0 0 -1
	*/
	cin>>H;
	ll bri,brj,W=0; // bottom right 
	for(ll i=0;i<h;i++){
		for(ll j=0,len=0;j<w+1;j++){
			if(hist[i][j]<H){
				if(len>W){
					W=len; bri=i;brj=j-1;
				}
				len=0;
			}
			else len++;
			
		}
	}
	if(W>0){
		cout<<bri-H+2<<" "<<brj-W+2<<" "<<bri+1<<" "<<brj+1<<endl;
	}
	else{
		cout<<"-1 -1 -1 -1"<<endl;
	}
	
   return 0;
  	} 
