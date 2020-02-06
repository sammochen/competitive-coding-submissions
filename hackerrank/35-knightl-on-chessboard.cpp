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
	ll get(ll a, ll b, ll n) {
		VLL di = {a,a,b,b,-a,-a,-b,-b};
		VLL dj = {b,-b,a,-a,b,-b,a,-a};

		queue<PLL> Q;
		Q.push({0,0});
		VVLL dist(n, VLL(n, inf));
		dist[0][0] = 0;

		while (Q.size()) {
			PLL at = Q.front(); Q.pop();
			ll x = at.first, y = at.second;
			REP(i,0,8) {
				ll xx = x + di[i];
				ll yy = y + dj[i];
				if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
				if (dist[xx][yy] != inf) continue;

				Q.push({xx,yy});
				dist[xx][yy] = dist[x][y] + 1;
				if (xx == n-1 && yy == n-1) return dist[xx][yy];
			}
		}
		return -1;
	}

	void main() {
		ll n;
		cin >> n;
		//
		REP(i,1,n) {
			REP(j,1,n) {
				cout << get(i,j,n);
				if (j == n-1) cout << endl;
				else cout << ' ';
			}
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
