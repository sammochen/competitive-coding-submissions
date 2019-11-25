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
template <typename A, typename B> string to_string(pair<A,B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
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
typedef vector<VLL> VVLL;

namespace SOLVE {	
	VLL p; 

	ll getp(ll x) {
		if (p[x] == x) return x;
		p[x] = getp(p[x]);
		return p[x];
	}

	void merge(ll a, ll b) {
		p[getp(a)] = getp(b);
	}

	ll same(ll a, ll b) {
		return getp(a) == getp(b);
	}

	struct edge {
		ll a, b, d;
	};

	bool operator<(const edge & a, const edge & b) {
		return a.d < b.d;
	}

	void main() {
		while (1) {
			ll n, m;
			cin >> n >> m;
			if (n == 0 && m == 0) return;

			p.resize(n);
			REP(i,0,n) p[i] = i;

			vector<edge> E(m);

			REP(i,0,m) {
				ll a, b, d;
				cin >> a >> b >> d;
				E[i] = {a,b,d};
			}

			sort(E.begin(), E.end());

			ll ans = 0;
			for (edge e : E) {
				if (same(e.a, e.b)) ans += e.d;
				else merge(e.a, e.b);
			}

			cout << ans << endl;

		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	t = 1;
	// cin >> t;
	while (t--) {
		SOLVE::main();
	}

	return 0;
}
