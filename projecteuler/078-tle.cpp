/*
Original problem:
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair

string to_string(string s) {return s;}
string to_string(char c) {return "" + c;}
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

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

const ll mod = 1000000;
const ll nax = 10000;

namespace SOLVE {	
	VVLL dp(nax, VLL(nax, -1));

	// number of ways to partition n, in groups of maximum lim
	ll get(ll n, ll lim) {
		if (n < 0) return 0;
		if (n == 0) return 1;
		if (dp[n][lim] != -1) return dp[n][lim];
		
		ll ans = 0;
		REP(i,1,lim+1) {
			ans += get(n-i,i);
			ans = ans >= mod ? ans - mod : ans;
		}

		dp[n][lim] = ans;
		return ans;
	}
	void main() {
		REP(i,0,nax) {
			debug(i, get(i,i));
			if (get(i,i) == 0) {
				debug(i);
			}
		}
	}
}


signed main() {
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
