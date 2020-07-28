// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
/*
Sample Input 1    Sample Output1
5 3
1 2 3 4 -1
                   4
Sample Input 2
40 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Sample Output 2
1099511627776
*/

typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)

int main() {
//input n x and ni to 2 vectors
  int n;
  long x;
  char c;
     while((c=cin.get())!='\n')
  {
      cin.unget();
      cin>>n>>x;
  }
  int len1=(n/2);
  int len2=n-len1;
  
  vector<long> a(len1),b(len2);
  int len=0;

  while(len!=n){
  	if(len<len1){cin>>a[len];}
  	else{cin>>b[len-len1];}
    len++;
  }
//cal sum of subsets for 2 vectors and save in suma sumb
  vector<long long>suma,sumb;
  long long numofsubs=0;
  for(int i = 0;i < (1<<len1);i++){
	    long long tmp=0;
		for(int j = 0;j < len1;j++){
		   if(i&(1<<j))	tmp+=a[j];
	    }
	    suma.push_back(tmp);
	}
	

	
   for(int i = 0;i < (1<<len2);i++){
	    long long tmp=0;
		for(int j = 0;j < len2;j++){
		   if(i&(1<<j))	tmp+=b[j];
	    }
	    sumb.push_back(tmp);

	}
//sort sumb,then use enqual_range to get number of same value and accumulate to numofsubs
    sort(sumb.begin(),sumb.end());
    pair<vector<long long>::iterator,vector<long long>::iterator> ip;
    
    for(long long s:suma){
    //	cout<<s<<endl;
    //equal_range can return the vector<ll> which sum==x-s
    		ip=equal_range(sumb.begin(),sumb.end(),x-s);
    		if(ip.first!=ip.second){
    		//	cout<<*ip.second<<" "<<*ip.first<<endl;
    			numofsubs+=ip.second-ip.first;
			}
		
    	
	}
    
	cout<<numofsubs<<endl;
   return 0;
  	} 
