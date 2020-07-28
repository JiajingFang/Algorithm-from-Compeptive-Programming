#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
/*

*/
string s;
int p;

struct tree{
	char op;
	int val;
	vector<tree*> children;
	
	int calc(){
		if(children.size()==0) return val;
		int res=op=='*'?1:0;
		for(tree*t:children){
			if(op=='*') res*=t->calc();
			else res+=t->calc();
		}
		return res;
	}
}; 

int parseNat(){
	string t;
	for(;s[p]>='0'&&s[p]<='9';p++){
		t+=s[p];
	}
	return stoi(t);
}

tree* parseTree(){
	tree* t=new tree;
	t->op=s[p];
	p+=2;
	
	for(int i=0;;i++){
		if(s[p]==')'){
			p++;
			break;
		}else if(i>0) p++;
		
		if(s[p]>='0'&&s[p]<='9'){
			tree *c=new tree;
			c->val=parseNat();
			t->children.push_back(c);
		}else{
			t->children.push_back(parseTree());
		}
	}
	return t;
}

int32_t main(){
	ll sum=0;
	ll sum1;
	while(true){
		getline(cin,s);
		if(s=="") break;
		
		p=0;
		tree *t=parseTree();
		
		if(s[0]=='+') sum1=0;
		else sum1=1;
		for(tree*k:t->children){
			if(s[0]=='+'){ 
				sum1+=k->calc();
			}
			
			else 
				sum1*=k->calc();
			
			
		}
		sum+=sum1;
	}
	cout<<sum<<endl;
}
