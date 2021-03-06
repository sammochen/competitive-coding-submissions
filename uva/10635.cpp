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
	ll bs(VLL & A, ll x) {
		ll L = 0, R = A.size() - 1;
		while (L < R) {
			ll M = (L + R) / 2;
			if (A[M] > x) {
				R = M;
			} else {
				L = M + 1;
			}
		}
		return L;
	}

	ll lis(VLL & A) {
		VLL tails;
		for (ll a : A) {
			if (tails.size() == 0) {
				tails.push_back(a);
			} else if (a < tails[0]) {
				tails[0] = a;
			} else if (a > tails[tails.size() - 1]) {
				tails.push_back(a);
			} else {
				ll i = bs(tails, a);
				tails[i] = a;
			}
		}
		
		return tails.size();
	}
	
	ll test = 1;
	void main() {
		ll k, n, m;
		cin >> k >> n >> m;
		n++; m++;

		map<ll,ll> ind;
		REP(i,0,n) {
			ll x;
			cin >> x;
			ind[x] = i+1;
		}

		VLL A;
		REP(i,0,m) {
			ll x;
			cin >> x;
			if (ind[x]) A.push_back(ind[x]);
		}

		printf("Case %lld: %lld\n", test++, lis(A));

	}
}


signed main() {
	ll t;
	t = 1;
	cin >> t;
	REP(i,0,t) {
		SOLVE::main();
	}
	return 0;
}
