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
	ll solve(VVLL grid, map<VVLL,ll> on, stack<VVLL> st) {
		if (on[grid]) {
			while (on[grid]) {
				on[st.top()] = 0;
				st.pop();
			}
			
			if (st.size() == 0) return -1;
			else return st.size() - 1;
		}

		on[grid] = 1;
		st.push(grid);

		VVLL next(3, VLL(3));
		REP(i,0,3) {
			REP(j,0,3) {
				VLL di = {0,0,1,-1};
				VLL dj = {1,-1,0,0};
				REP(x,0,4) {
					ll ii = i + di[x];
					ll jj = j + dj[x];
					if (ii >= 0 && ii < 3 && jj >= 0 && jj < 3) {
						next[i][j] ^= grid[ii][jj];
					}
				}
			}
		}

		return solve(next, on, st);
	}

	void main() {
		string s;
		VVLL A(3, VLL(3));
		REP(i,0,3) {
			cin >> s;
			REP(j,0,3) {
				A[i][j] = s[j] - '0';
			}
		}

		map<VVLL,ll> map;
		stack<VVLL> st;
		ll ans = solve(A, map, st);
		printf("%lld\n", ans);
	}
}


signed main() {
	ll t;
	t = 1;
	in(t);
	REP(i,0,t) {
		SOLVE::main();
	}

	return 0;
}
