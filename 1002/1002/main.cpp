#include <iostream>
#include <string>
#include <vector>
using namespace std;
void Quicksort(vector<string> &s,int p,int n)//快速排序法
{
	if(p>n)
		return;
	string key=s[n];
	int i=p-1;
	for(int j=p;j<=n-1;++j){
		if(s[j]<=key){
			++i;
			string temp=s[j];
			s[j]=s[i];
			s[i]=temp;
		}
	}
	string temp2=s[n];s[n]=s[i+1];s[i+1]=temp2;
	int q=i+1;
	Quicksort(s,p,q-1);
	Quicksort(s,q+1,n);
}

vector<string> remain_num(string s[],int n)
{
	vector <string> ss(n);
	for(int i=0;i<n;++i){
		for(string::iterator it=s[i].begin();it!=s[i].end();++it){
			if((*it)!='-')
				ss[i].push_back(*it);
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<ss[i].size();++j){
			if(ss[i][j]=='A'||ss[i][j]=='B'||ss[i][j]=='C')
				ss[i][j]='2';
			else if(ss[i][j]=='D'||ss[i][j]=='E'||ss[i][j]=='F')
				ss[i][j]='3';
			else if(ss[i][j]=='G'||ss[i][j]=='H'||ss[i][j]=='I')
				ss[i][j]='4';
			else if(ss[i][j]=='J'||ss[i][j]=='K'||ss[i][j]=='L')
				ss[i][j]='5';
			else if(ss[i][j]=='M'||ss[i][j]=='N'||ss[i][j]=='O')
				ss[i][j]='6';
			else if(ss[i][j]=='P'||ss[i][j]=='R'||ss[i][j]=='S')
				ss[i][j]='7';
			else if(ss[i][j]=='T'||ss[i][j]=='U'||ss[i][j]=='V')
				ss[i][j]='8';
			else if(ss[i][j]=='W'||ss[i][j]=='X'||ss[i][j]=='Y')
				ss[i][j]='9';
			}
	
	}
	return ss; 
}
vector<string> remain_size(vector<string>ss,int n)
{
	int m=0;//record the num that satisfied size 7;
	for(int i=0;i<n;++i){
		if(ss[i].size()==7)
			++m;
	}
	vector<string>s_m(m);//用来记录剔除不满size7的电话号码
	int l=0; //记录符合条件的次数
	for(int i=0;i<n;++i){
		if(ss[i].size()!=7)
			continue;
		else{
			s_m[l]=ss[i];
			++l;
		}
	}
	return s_m;
}
vector<string> compare(vector<string>sm,int n,vector <int>&num)
{
	Quicksort(sm,0,n-1);
	vector <string> s_new;
	int k=1;//记录出现次数
	for(int i=0;i<n;++i){
			if(i==n-1)
			{
				if(sm[i]!=sm[i-1]){
					s_new.push_back(sm[i]);
					k=1;
					num.push_back(k);
					break;
				}
				else{
					num.push_back(k);
					s_new.push_back(sm[i]);
					break;
				}
			}
			if(sm[i]==sm[i+1]){
				++k;
			}
			else{
				num.push_back(k);
				k=1;
				s_new.push_back(sm[i]);
			}
			
	}
	return s_new;
}
int main()
{
	int n=0;
	while(cin>>n){
		string *s=new string[n];
		for(int i=0;i<n;++i){
			cin>>s[i];
		}
		vector <string> ss=remain_num(s,n);//除去输入里面的字母与‘-’
		vector <string> sm=remain_size(ss,n);//除去不满size7后 剩下的string 数组
		if(sm.size()==0)
			cout<<"No duplicates."<<endl;
		else{
			vector <int>  num;
			vector<string> result=compare(sm,n,num);
			for(int i=0;i<num.size();++i){
				if(num[i]>=2){
					for(int j=0;j<3;++j)
						cout<<result[i][j];
					cout<<"-";
					for(int j=3;j<result[i].size();++j)
						cout<<result[i][j];
					cout<<" "<<num[i]<<endl;	
				}
				else
					continue;
			}
		}
	}
	system("pause");
	return 0;
}