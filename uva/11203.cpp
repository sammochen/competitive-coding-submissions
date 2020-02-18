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
	void main() {
		string s;
		cin >> s;
		VLL cnt(3);
		ll ptr = 0;
		for (char c : s) {
			if (c != 'M' && c != 'E' && c != '?') {
				cout << "no-theorem" << endl;
				return;
			}

			if (c == 'M' && ptr != 0) {
				cout << "no-theorem" << endl;
				return;
			}
			if (c == 'E' && ptr != 1) {
				cout << "no-theorem" << endl;
				return;
			}
			if (c == 'M' || c == 'E') ptr++;
			else cnt[ptr]++;
		}
		if (cnt[1] > 1) {
			cnt[2] -= (cnt[1] - 1);
			cnt[1] = 1;
		}
		
		if (cnt[0] >= 1 && cnt[1] == 1 && cnt[2] == cnt[0] + 1) {
			cout << "theorem" << endl;
		} else {
			cout << "no-theorem" << endl;
		}
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
