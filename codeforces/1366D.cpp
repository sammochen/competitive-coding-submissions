#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL; 
typedef vector<VLL> VVLL;
typedef pair<ll,ll> PLL;
typedef map<ll,ll> MLL;
typedef set<ll> SLL;

#define rep(x,l,u) for(ll x = l; x < u; x++)
#define rrep(x,l,u) for(ll x = l; x >= u; x--)
#define fe(x,a) for (auto x : a)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mst(x,v) memset(x, v, sizeof(x))
#define sz(x) (ll)x.size()
#define lg(x) (ll)x.length()
#define fi first
#define se second
#define pb push_back

#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define pqueue priority_queue

struct DEBUG {
	string open = "[", close = "]", sep = ", ";

	string f(string s) { return s; }
	string f(char c) { return string(1, c); }
	string f(int x) { return to_string(x); }
	string f(ll x) { return to_string(x); }
	template <typename A, typename B> string f(pair<A,B> p) { return open + f(p.first) + sep + f(p.second) + close; }
	template <typename A> string f(A v) { string s = open; for (auto a : v) { if (s != open) { s += sep; } s += f(a); } s += close; return s; } 

	void show() {cout << endl;}
	template <typename Head, typename... Tail> void show(Head H, Tail... T) { cout << " " << f(H); show(T...); }
};

#define debug(...) do { DEBUG deb; cout << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)

struct FASTINPUT {
	void f(string & s) { char buf[100005]; ll a = scanf("%s", buf); a++; s = buf; }
	void f(ll & x) { ll a = scanf("%lld", &x); a++; }
	void f(int & x) { ll a = scanf("%d", &x); a++; }
	template <typename A, typename B> void f(pair<A,B> p) { f(p.first); f(p.second); }
	template <typename A> void f(vector<A> & x) { for (auto & y : x) f(y); }
	
	void read() {}
	template <typename Head, typename... Tail> void read(Head & H, Tail & ... T) { f(H); read(T...); }
};

#define in(...) do { FASTINPUT inp; inp.read(__VA_ARGS__); } while (false)

const ll inf = (ll)1e18 + 5;
const ll mod = 1e9+7;

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
template <typename A, typename B> ll exist(A a, B b) { return a.find(b) != a.end(); }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }

void upmin(ll & x, ll v) { x = min(x, v); }
void upmax(ll & x, ll v) { x = max(x, v); }

ll nax = 3200;
VLL p(nax*nax, 1);
VLL par(nax*nax, -1);

void init() {
	p[0] = 0;
	p[1] = 0;

	for (ll x = 2; x < nax*nax; x++) {
		if (p[x] == 0) {
			continue;
		}
		par[x] = x;
		
		for (ll f = x; x * f < nax * nax; f++) {
			p[x*f] = 0;
			par[x*f] = x;
		}
	}
}

VLL fac(ll x) {
	VLL ans;
	while (x != 1) {
		ll a = par[x];
		while (x % a == 0) x /= a;
		ans.pb(a);
	}
	return ans;
}

void solve() {
	init();

	ll n;
	in(n);
	VLL A(n);
	in(A);

	VLL a(n, -1), b(n, -1);
	rep(i,0,n) {
		VLL factors = fac(A[i]);
		if (factors.size() > 1) {
			a[i] = factors[0];
			b[i] = 1;
			rep(j,1,sz(factors)) b[i] *= factors[j];
		}
	}

	rep(i,0,n) printf("%lld ", a[i]);
	printf("\n");
	rep(i,0,n) printf("%lld ", b[i]);
	printf("\n");
}

signed main() {
	ll t = 1;
	rep(i,0,t) solve();
	return 0;
}