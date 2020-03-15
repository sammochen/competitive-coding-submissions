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

typedef long long ll;
typedef double db;
typedef vector<ll> VLL;
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;

const ll inf = (ll)1e18 + 5;

ll sq(ll x) {
    ll s = sqrt(x);
    if (s*s == x) return s;
    return s+1;
}

PLL get(ll n) {
    ll r = sq(n); // which layer
    ll d = r*r - r + 1;
    if (r % 2) {
        if (n >= d) {
            return {r*r-n+1,r};
        } else {
            return {r,n-(r-1)*(r-1)};
        }
        
    } else {
        if (n >= d) {
            return {r,r*r-n+1};
        } else {
            return {n-(r-1)*(r-1),r};
        }
    }
    return {-1,-1};
}

void solve() {
    ll n;
    while (cin >> n, n) {
        PLL ans = get(n);
        cout << ans.first << ' ' << ans.second << endl;
    }
}

signed main() {
	ll t = 1;
	REP(i,0,t) solve();
	return 0;
}