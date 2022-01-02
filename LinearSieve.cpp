// Har Har Mahadev
/**
* Program to print prime-factorization of any number in form: a*a*...*b*b*b...c*c*c...*1
* It uses Linear Sieve for creating vector lp that store least prime-factor of a number i at index i
*/ 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long           ll;
typedef unsigned long long  ull;
 
#define el                  '\n' 
#define take(i)             int i; cin>>i
#define pb                  push_back
#define mp                  make_pair
#define ub                  upper_bound
#define lb                  lower_bound
#define ff                  first
#define ss                  second
#define iter                iterator
#define huge                10e9+7

vector<int> lp(1e5+1, 0);
vector<int> p;

int factor(int n){
    if(n==1) {
        cout<<"1";
        return 0;
    }
    cout<<lp[n]<<"*";
    n/=lp[n];
    factor(n);
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);

    lp[0]=-1,lp[1]=-1;

    for (int i = 2; i < 1e5+1; ++i)
    {
        if(lp[i]==0){
            p.push_back(i);
            lp[i]=i;
        }

        for (int j = 0; j < p.size() && p[j]<=lp[i] && p[j]*i<=1e5; ++j)
        {
            lp[p[j]*i]=p[j];
        }
    }
    
    factor(144);
    
    return 0;
}
