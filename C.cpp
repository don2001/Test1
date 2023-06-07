//
//  C.cpp
//  Code
//
//  Created by Thammadol Tansrivorarat on 28/6/2565 BE.
//

#include <stdio.h>
#include<iostream>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <stack>
#define fast ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
using ll=long long;
const ll mod=998244353;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//#include "A.hpp"
long long inv(long long a, long long b){
     return 1<a ? b - inv(b%a,a)*b/a : 1;
}
long long power(long long x, long long y, long long p)
{
    long long res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
struct FenwickTreeMax {
    vector<int> bit; vector<int>a;
    int n;
    const int INF = (int)-2e9;

    FenwickTreeMax(int n) {
        this->n = n;
        bit.assign(n, INF);
        a.assign(n,INF);
    }

    FenwickTreeMax(vector<int> a) : FenwickTreeMax(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmax(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        a[idx]=val;
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};

ll choose(ll a, ll b){
    ll ans=1;
    for(int i=1;i<=a;i++){
        ans=(ans*i)%mod;
    }
    for(int i=1;i<=b;i++){
        ans=(ans*inv(i,mod))%mod;
    }
    for(int i=1;i<=a-b;i++){
        ans=(ans*inv(i,mod))%mod;
    }
    return ans;
}
const double pi = 2*acos(0.0);
template <typename T>
struct segtreemin {
    vector<T>seg; int n;
    segtreemin(int n): n(n),seg(2*n,2e9){}
    void update(int p, int value) {  // set value at position p
       for (seg[p += n] = value; p > 1; p >>= 1) seg[p>>1] = min(seg[p] , seg[p^1]);
    }
    int query(int l, int r) {// sum on interval [l, r)
        r++;
      int res = 2e9;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res,seg[l++]);
        if (r&1) res = min(res,seg[--r]);
      }
      return res;
    }
    
};
template <typename T>
struct segtreemax {
    vector<T>seg; int n;
    segtreemax(int n): n(n),seg(2*n,-2e9){}
    void update(int p, int value) {  // set value at position p
       for (seg[p += n] = value; p > 1; p >>= 1) seg[p>>1] = max(seg[p] , seg[p^1]);
    }
    int query(int l, int r) {// sum on interval [l, r)
        r++;
      int res = -2e9;
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(res,seg[l++]);
        if (r&1) res = max(res,seg[--r]);
      }
      return res;
    }
    
};

int main(){
    int n; cin>>n; string s; cin>>s;
    int l=0,r=0;
    int lsum=0,rsum=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            lsum+=(1<<i);
            l++;
        }
        else{
            rsum+=(1<<i);
            r++;
        }
    }
    debug(1);
    for(int i=lsum+1;i<=(1<<n)-rsum+1;i++){
        cout<<i<<" ";
    }
    cout<<"\n";
}
