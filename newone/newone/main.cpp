//#include <iostream>
//#include <string>
//#include <vector>
//#include <time.h>
//#include <algorithm>
//using namespace std;
//
//char map[26]={'2', '2', '2', '3', '3', '3', '4', '4', '4',  
//                '5', '5', '5', '6', '6', '6', '7', 0, '7', '7', '8', '8', '8', '9', '9', '9', 0}; 
//vector<string> remain_num(string s[],int n)
//{
//	vector <string> ss(n);
//		for(int i=0;i<n;++i){
//			int x=0;
// 			for(string::iterator it=s[i].begin();it!=s[i].end();++it){
//				if((*it)=='-'||(*it)=='Q'||(*it)=='Z')
//						continue;
//				++x;
//				if((*it)>='A'&&(*it)<='Z') (*it)=map[(*it)-'A'];
//				if(x==4) ss[i].push_back('-');
//				ss[i].push_back(*it);		
//			}
//		}
//	return ss; 
//}
//
////vector<string> compare(vector<string>sm,int n,vector <int>&num)
////{	
////	vector <string> s_new;
////	if(n==1){
////		s_new=sm;
////		num.push_back(1);
////		return s_new;
////	}
////	//Quicksort(sm,0,n-1); //随机快速排序 复杂度O(nlgn)
////	sort(sm.begin(),sm.end());  
////	int k=1;//记录出现次数
////	for(int i=0;i<n;++i){   
////			if(i==n-1){
////				if(sm[i]!=sm[i-1]){
////					s_new.push_back(sm[i]);
////					k=1;
////					num.push_back(k);
////					break;
////				}
////				else{
////					num.push_back(k);
////					s_new.push_back(sm[i]);
////					break;
////				}
////			}
////			if(sm[i]==sm[i+1])
////				++k;
////			else{
////				num.push_back(k);
////				k=1;
////				s_new.push_back(sm[i]);
////			}
////			
////	}
////	return s_new;
////}
//int main()
//{
//	int n=0;
//	while( cin >> n ){
//		string *s=new string[n];
//		for(int i=0;i<n;++i){
//			cin>>s[i];
//		}
//		vector <string> sm=remain_num(s,n);//除去输入里面的字母与‘-’ 复杂度 O(n)
//		sort(sm.begin(),sm.end());  //                         Memory: 7932K		Time: 1172MS
//		int k=1;int z=0;
//		for(int i=1;i<n;++i){
//			if(sm[i]!=sm[i-1]){
//				if(k>1){
//					cout<<sm[i-1]<<" "<<k<<endl;
//					z=1;
//				}
//				k=1;
//			}else {
//				++k;
//			}
//		}
//		if( k > 1 ) {  
//			cout<<sm[n-1]<<" "<<k<<endl;
//			z = 1;  
//		}  
//		if( !z ) cout<<"No duplicates.\n"; 
//		
//
//
//		//vector <int>  num;
//		//vector<string> result=compare(sm,n,num);//O(nlgn+n)
//		//int q=0;
//		//for(int i=0;i<num.size();++i){//O(n)
//		//	if(num[i]>=2){
//		//		cout<<result[i]<<" "<<num[i]<<endl;
//		//	}
//		//	else{
//		//		++q;
//		//		continue;
//		//	}
//		//}
//		//if(q==num.size())
//		//	cout<<"No duplicates."<<endl;
//	}
//	system("pause");
//	return 0;
//}



  
char map[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4',  
                '5', '5', '5', '6', '6', '6', '7', 0, '7', '7', '8', '8', '8', '9', '9', '9', 0};  
  
char ph[100000][9];  
int nph;  
  
char buf[1000];  
#include<iostream>
#include<stdlib.h>
using namespace std;
main() {  
    int i, j, k, x, y, z, n;  
    char ch;  
  
    memset( ph, 0, sizeof(ph) );  
    scanf( " %d", &nph );  
    for( i = 0; i < nph; i++ ) {  
        scanf( " %s", buf );  
        x = 0;  
        for( j = 0; buf[j]; j++ ) {  
            if( buf[j] == '-' ) continue;  
            if( buf[j] >= 'A' && buf[j] <= 'Z' ) buf[j] = map[buf[j]-'A'];  
            ph[i][x++] = buf[j];  
            if( x == 3 ) ph[i][x++] = '-';  
        }  
    }  
    qsort( ph, nph, 9, strcmp );  
    x = 1; z = 0;  
    for( i = 1; i < nph; i++ ) {  
        if( strcmp( ph[i-1], ph[i] ) ) {  
            if( x > 1 ) {  
                printf( "%s %d\n", ph[i-1], x );  
                z = 1;  
            }  
            x = 1;  
        } else {  
            x++;  
        }  
    }  
    if( x > 1 ) {  
        printf( "%s %d\n", ph[i-1], x );  
        z = 1;  
    }  
    if( !z ) printf( "No duplicates.\n" );  
} 