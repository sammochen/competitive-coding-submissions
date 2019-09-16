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

string to_string(char c) {return "" + c;}
string to_string(bool b) {return b ? "true" : "false";}
template <typename A> string to_string(vector<A> v) { string s = "("; int first = 1; for (A a : v) { if (!first) { s += ", "; } first = 0; s += to_string(a); } s += ")"; return s; }

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

namespace SOLVE {
	ll trip(ll a, ll b, ll c) {
		if (a < 0 || b < 0 || c < 0) {
			return 0;
		}
		return a*a + b*b == c*c;
	}
	
	ll t(ll a, ll b, ll c) {
		return trip(a,b,c) || trip(b,c,a) || trip(c,a,b);
	}
	
	void main() {
		ll n = 1000, ans = -1;
		REP(i,1,n+1) {
			REP(j,1,n+1) {
				ll k = n - i - j;
				if (1 <= k && k <= n) {
					if (t(i,j,k)) {
						ans = i*j*k;
					}
				}
				
			}
		}
		
		cout << ans << endl;
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
