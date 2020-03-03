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
	void main() {
		ll n;
		cin >> n;
		vector<double> A(n);
		REP(i,0,n) cin >> A[i];

		sort(A.rbegin(), A.rend());

		double ans = 0;

		// try what happens when you choose some subset
		REP(i,0,n) {
			// let i be the end
			// brute force - O(n^3)
			double probi = 0;

			REP(j,0,i + 1) { // choose some j that is the 'on'
				double probj = 1;
				REP(k,0,i + 1) {
					if (j == k) probj *= A[k];
					else probj *= (1.0 - A[k]);
				}

				probi += probj;
			}
			ans = max(ans, probi);
		}

		cout << setprecision(20) << ans << endl;
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
