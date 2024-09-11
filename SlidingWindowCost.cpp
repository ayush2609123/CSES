#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
#include <set>
#include <limits>
#include <cstdlib>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define sz(a) int((a).size())

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
void solve() {
   ll n,k;
   cin>>n>>k;
   vll v(n);
   for0(i,n){
    cin>>v[i];
   }
   multiset<ll> low,hi;
   vector<ll> ans;
   ll lsum=0;
   ll rsum=0; 
   for(int i=0;i<n;i++){
         low.insert(v[i]);
         lsum+=v[i];
         hi.insert(*low.rbegin());
         rsum+=*low.rbegin();
         lsum-=*low.rbegin();
         low.erase(low.find(*low.rbegin()));
        

         if(low.size()<hi.size()){
            low.insert(*hi.begin());
            lsum+=*hi.begin();
            rsum-=(*hi.begin());
            hi.erase(hi.find(*hi.begin()));
            
         }
         if(i>=k-1){
            if(k%2==0){
                ll median_high = *hi.begin();
                ll median_low = *low.rbegin();
                ll median = (median_low + median_high) / 2;  
                
                ll val = (rsum - (ll)hi.size() * median) + ((ll)low.size() * median - lsum);
                ans.push_back(val);
            }
            else{
                ll val=((low.size())*(*low.rbegin())-lsum) + ((rsum)-(hi.size())*(*low.rbegin()));
                ans.push_back(val);
            }

            if(v[i-k+1]<=*low.rbegin()){
                lsum-=v[i-k+1];
                low.erase(low.find(v[i-k+1]));

            }
            else{
                rsum-=v[i-k+1];
                hi.erase(hi.find(v[i-k+1]));
            }
         }
         
   }
      for(int i=0;i<ans.size();i++){
          cout<<ans[i]<<" ";
         }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    solve();
    return 0;
}

