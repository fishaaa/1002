#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

//int rand_fish(int m,int n)
//{
//	srand((unsigned)time(NULL));
//	return m+(rand()%(n-m+1));
//}

//void Quicksort(vector<string> &s,int p,int n)//随机快速排序法
//{
//	if(p>=n)
//		return;
//	int u=rand_fish(p,n);
//	string t1=s[u];s[u]=s[n];s[n]=t1;
//	string key=s[n];
//	int i=p-1;
//	for(int j=p;j<=n-1;++j){
//		if(s[j]<=key){
//			++i;
//			string temp=s[j];
//			s[j]=s[i];
//			s[i]=temp;
//		}
//	}
//	string temp2=s[n];s[n]=s[i+1];s[i+1]=temp2;
//	int q=i+1;
//	Quicksort(s,p,q-1);
//	Quicksort(s,q+1,n);
//}

//void Quicksort(vector<string> &s,int p,int n)//快速排序法
//{
//	if(p>=n)
//		return;
//	string key=s[n];
//	int i=p-1;
//	for(int j=p;j<=n-1;++j){
//		if(s[j]<=key){
//			++i;
//			string temp=s[j];
//			s[j]=s[i];
//			s[i]=temp;
//		}
//	}
//	string temp2=s[n];s[n]=s[i+1];s[i+1]=temp2;
//	int q=i+1;
//	Quicksort(s,p,q-1);
//	Quicksort(s,q+1,n);
//}
vector<string> remain_num(string s[],int n)
{
	vector <string> ss(n);
		for(int i=0;i<n;++i){
 			for(string::iterator it=s[i].begin();it!=s[i].end();++it){
				if((*it)=='-'||(*it)=='Q'||(*it)=='Z')
						continue;
				else{
					if((*it)=='A'||(*it)=='B'||(*it)=='C')
						(*it)='2';
					else if((*it)=='D'||(*it)=='E'||(*it)=='F')
						(*it)='3';
					else if((*it)=='G'||(*it)=='H'||(*it)=='I')
						(*it)='4';
					else if((*it)=='J'||(*it)=='K'||(*it)=='L')
						(*it)='5';
					else if((*it)=='M'||(*it)=='N'||(*it)=='O')
						(*it)='6';
					else if((*it)=='P'||(*it)=='R'||(*it)=='S')
						(*it)='7';
					else if((*it)=='T'||(*it)=='U'||(*it)=='V')
						(*it)='8';
					else if((*it)=='W'||(*it)=='X'||(*it)=='Y')
						(*it)='9';
					ss[i].push_back(*it);
				}		
			}
		}
	return ss; 
}

vector<string> compare(vector<string>sm,int n,vector <int>&num)
{	
	vector <string> s_new;
	if(n==1){
		s_new=sm;
		num.push_back(1);
		return s_new;
	}
	//Quicksort(sm,0,n-1); //随机快速排序 复杂度O(nlgn)
	sort(sm.begin(),sm.end());  
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
			if(sm[i]==sm[i+1])
				++k;
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
		vector <string> sm=remain_num(s,n);//除去输入里面的字母与‘-’ 复杂度 O(n)
		vector <int>  num;
		vector<string> result=compare(sm,n,num);//O(nlgn+n)
		int q=0;
		for(int i=0;i<num.size();++i){//O(n)
			if(num[i]>=2){
				result[i].insert(3,"-");
				cout<<result[i]<<" "<<num[i]<<endl;
			}
			else{
				++q;
				continue;
			}
		}
		if(q==num.size())
			cout<<"No duplicates."<<endl;
		delete []s;
	}
	system("pause");
	return 0;
}
