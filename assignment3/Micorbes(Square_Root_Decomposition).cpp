// compile (for debugging): g++ -Wall -Wextra -fsanitize=undefined,address -D_GLIBCXX_DEBUG -g <file>
// compile (as on judge): g++ -x c++ -Wall -O2 -static -pipe <file>
// Output file will be a.out in both cases
#include <bits/stdc++.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;


typedef long long ll;

#define debug(x) \
    (cerr << #x << ": " << (x) << endl)

int main() {
//input n q , data into vectorA, query into vectorqa
  long n,q;
  char c;
     while((c=cin.get())!='\n')
  {
      cin.unget();
      cin>>n>>q;
  }

  long len=0;
  long length=ceil(sqrt(n));
  vector <long> A(length*length,0);
  while(len!=n){
  	cin>>A[len];
  	len++;
  }
  vector <long> qa;
  len=0;
  char qn;
  long a,b;
  while(len!=q){
  	cin>>qn;
  	if(qn=='U'){
  		cin>>a>>b;
  		qa.push_back(-1);
	  }
	else{
		cin>>a>>b;	
		qa.push_back(0);
	}
	qa.push_back(a);
	qa.push_back(b);
	len++;
  }

 //calculate sum of odds for subarray(sqrtn)  
    
    vector <long> B(length,0);
    long tmp=0;
    for(long i=0;i<length;i++){
    	tmp=0;
    	for(long j=i*length;j<(i+1)*length;j++){
    		if(A[j]%2!=0)
    		tmp++;
		}
		B[i]=tmp;
	}
//traverse qa to get query and peform
    for(unsigned long i=2;i<qa.size();i+=3){
    	if(qa[i-2]==-1){
     		a=qa[i-1];
     		a--;
	        //previous A[a] is odd then correspondent B--
	        if(A[a]%2!=0){
		      B[(a)/length]--;
	        }
	        //b is odd then correspondent B++
	        b=qa[i];
			A[a]=b;
	        if(b%2!=0){
		      B[(a)/length]++;
	        }
		}
	    if(qa[i-2]==0){
			a=qa[i-1];
			b=qa[i];
			a--;
	        b--;
	        long sum=0;
	        //1.a==b
	        if(a==b){
		      if(A[a]%2!=0) cout<<"1"<<endl;
		      else cout<<"0"<<endl;
	        }
	        //2.in same range
	        else if(a/length==b/length){
		      for(long i=a;i<=b;i++){
			    if(A[i]%2!=0) sum++;
		      }
		      cout<<sum<<endl;
	        } 
	        //3.not in same range 
	        else{
			 for(long i=a;i<(a/length+1)*length;i++){
		      if(A[i]%2!=0) sum++;
	         }
	         if((a/length)+1!=(b/length)){
		      for(long i=(a/length)+1;i<(b/length);i++){
		        sum+=B[i];
	          }
	         }
	         for(long i=(b/length)*length;i<=b;i++){
		      if(A[i]%2!=0) sum++;
	         }
			 cout<<sum<<endl;
			}
	        
		}
	}
   return 0;
  	} 
