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

void in(string & s) {
	char buf[100]; // note the 100 limit
	ll a = scanf("%99s", buf);
	s = buf;
}

void in(ll & x) {
	ll a = scanf("%lld", &x);
}

template <typename A, typename B> void in(A & a, B & b) { in(a); in(b); }
template <typename A, typename B, typename C> void in(A & a, B & b, C & c) { in(a); in(b); in(c); }

const ll inf = (ll)1e18 + 5;

namespace SOLVE {	
	// returns the minimum for 8 queens
	ll get(VLL & A, ll ind, ll r, ll d1, ll d2) {
		if (ind == A.size()) return 0;

		ll ans = inf;
		REP(i,0,8) {
			if ((1LL << i) & r) continue;
			if ((1LL << i) & d1) continue;
			if ((1LL << i) & d2) continue;

			ll next = get(A, ind+1, r | (1LL << i), (d1 | (1LL << i)) << 1, (d2 | (1LL << i)) >> 1);
			if (i != A[ind] - 1) ans = min(ans, next + 1);
			else ans = min(ans, next);
		}
		return ans;
	}

	ll test = 1;
	void main() {
		string s;
		while (getline(cin, s), !s.empty()) {
			stringstream ss;
			ss << s;
			VLL A(8);
			REP(i,0,8) ss >> A[i];
			ll ans = get(A, 0, 0, 0, 0);
			printf("Case %lld: %lld\n", test++, ans);
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
