#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PLL pair<ll,ll>
#define MP make_pair

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

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	ll n;
	ll dp[1005][6005];
	ll get(ll ind, ll maxload, VLL & weight, VLL & load) {
		if (ind == n) return 0;
		if (dp[ind][maxload] != -1) return dp[ind][maxload];
		
		// either you ignore it
		ll ans = get(ind + 1, maxload, weight, load);
		// or you can try to load it - only if it fits
		if (weight[ind] <= maxload) ans = max(ans, 1 + get(ind + 1, min(maxload - weight[ind], load[ind]), weight, load));

		dp[ind][maxload] = ans;
		return ans;
	}
	void main() {
		while (cin >> n, n) {
			memset(dp, -1, sizeof(dp));
			VLL weight(n), load(n);
			REP(i,0,n) {
				cin >> weight[i] >> load[i];
			}

			cout << get(0, 6004, weight, load) << endl;


		}
	}
}


signed main() {
	ll t;
	t = 1;
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
