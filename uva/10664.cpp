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
	ll pos(ll x, ll ind, VLL & A, VVLL & dp) {
		if (x < 0) return 0;
		if (x == 0) return 1;
		if (ind == A.size()) return 0;
		if (dp[x][ind] != -1) return dp[x][ind];
		ll ans = 0;
		if (pos(x, ind+1, A, dp)) ans = 1;
		else if (pos(x - A[ind], ind+1, A, dp)) ans = 1;

		dp[x][ind] = ans;
		return ans;
	}

	void main() {
		string s;
		getline(cin, s);
		stringstream ss;
		ss << s;
		VLL A;
		ll x;
		ll total = 0;
		while (ss >> x) {
			A.push_back(x);
			total += x;
		}

		if (total % 2 == 1) {
			cout << "NO" << endl;
			return;
		}

		VVLL dp(201, VLL(A.size(), -1));
		ll ans = pos(total / 2, 0, A, dp);
		if (ans) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		
	}
}


signed main() {
	ll t;
	t = 1;
	in(t);
	string s;
	getline(cin, s);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
