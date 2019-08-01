/*
Original problem: https://www.hackerrank.com/challenges/insertionsort2
Author: sammochen
*/

#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)

#define PII pair<int,int>
#define PLL pair<ll,ll>

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef vector<ll> VLL;
typedef vector<int> VI;

const int inf = 1e9 + 7;

namespace SOLVE {
	void print(VI x) {
		for (int xx : x) {
			cout << xx << ' ';
		}
		cout << endl;
	}

	VI once(VI A, int n) {
		int hold = A[n - 1];
		for (int i = n - 1; i >= 0; i--) {
			if (i != 0 && hold < A[i - 1]) {
				A[i] = A[i - 1];
			}
			else {
				A[i] = hold;
				hold = inf;
			}
			if (hold == inf) {
				break;
			}
		}
		return A;
	}

	void main() {
		// i will use code written from insertionsort1, and adapt it so it is a function
		int n;
		cin >> n;
		VI A(n);
		REP(i, 0, n) {
			cin >> A[i];
		}

		// sort it O(n) times, from size 2 to size n
		// the array will be sorted from the front in each step
		REP(i, 2, n + 1) {
			A = once(A, i);
			print(A);
		}

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