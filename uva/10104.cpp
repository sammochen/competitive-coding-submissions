#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l; x < u; x++)
#define RREP(x,l,u) for(ll x = l; x >= u; x--)

string to_string(string s) {return s;}
string to_string(char c) {string s = string(1, c);return s;}
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A> string to_string(set<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << to_string(H); debug_out(T...); }

#ifndef ONLINE_JUDGE
#define debug(...) do { cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__); } while (false)
#else
#define debug(...) do { } while (false)
#endif

typedef  long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

// Function for extended Euclidean Algorithm  
ll extendedgcd(ll a, ll b, ll & x, ll & y) {
    // Base Case  
    if (a == 0) {  
        x = 0;
        y = 1;  
        return b;  
    }
  
    ll x1, y1; // To store results of recursive call  
    ll gcd = extendedgcd(b%a, a, x1, y1);  
  
    // Update x and y using results of  
    // recursive call  
    x = y1 - (b/a) * x1;  
    y = x1;  
  
    return gcd;  
}  

void solve() {
    ll a, b;
    while (cin >> a >> b) {
        if (a == b) {
            cout << 0 << ' ' << 1 << ' ' << a << endl;
            continue;
        }
        ll x, y;
        ll g = extendedgcd(a, b, x, y);
        cout << x << ' ' << y << ' ' << g << endl;
    }
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}