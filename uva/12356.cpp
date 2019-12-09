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

namespace SOLVE {	
	VLL up, down;	

	void main() {
		ll n, k;
		in(n,k);
		if (n == 0 && k == 0) exit(0);
		up.resize(n+2);
		down.resize(n+2);

		REP(i,1,n+1) {
			up[i] = i+1;
			down[i] = i-1;
		}

		REP(i,0,k) {
			ll a, b;
			in(a,b);
			up[down[a]] = up[b];
			down[up[b]] = down[a];

			if (down[a] == 0) cout << "*";
			else cout << down[a];
			cout << ' ';
			if (up[b] == n+1) cout << "*";
			else cout << up[b];
			cout << endl;
		}
		cout << "-" << endl;

	}
}


signed main() {
	ll t;
	t = 1;
	while (1) {
		SOLVE::main();
	}

	return 0;
}
