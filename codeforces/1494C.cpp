#ifdef SAM
#include "stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

typedef long long ll;
typedef double db;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL; 
typedef vector<VLL> VVLL;
typedef vector<VVLL> VVVLL;
typedef pair<ll,ll> PLL;
typedef map<ll,ll> MLL;
typedef set<ll> SLL;
typedef queue<ll> QLL;

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
	string f(db x) { return to_string(x); }
	string f(const char* a) { return a; }
	template <typename A, typename B> string f(pair<A,B> p) { return open + f(p.first) + sep + f(p.second) + close; }
	template <typename A> string f(A v) { string s = open; for (auto a : v) { if (s != open) { s += sep; } s += f(a); } s += close; return s; } 

	void show() {cout << endl;}
	template <typename Head, typename... Tail> void show(Head H, Tail... T) { cout << " " << f(H); show(T...); }
};

#ifdef SAM
#define debug(...) do { DEBUG deb; cout << "[" << #__VA_ARGS__ << "]:", deb.show(__VA_ARGS__); } while (false)
#else
#define debug(...) do {} while (false)
#endif

VLL di = {0,0,1,-1,1,-1,1,-1};
VLL dj = {1,-1,0,0,-1,-1,1,1};

void readstr(string & s, const ll len=400005) { char buf[len]; ll a = scanf("%s", buf); a++; s = buf; }
ll ob(ll i, ll n) { return i < 0 || i >= n; } // out of bounds
ll tp(ll x) { return (1LL<<x); }
ll roundup(ll a, ll b) { return a % b ? a/b + 1 : a/b; }
vector<string> ssplit(string s) { vector<string> ans; stringstream ss; ss << s; while (ss >> s) ans.pb(s); return ans; }
void makemod(ll & x, ll m) { x %= m; x += m; x %= m; }
ll powmod(ll a, ll b, ll m) { if (b == 0) return 1;	ll h = powmod(a, b/2, m); ll ans = h*h%m; return b%2 ? ans*a%m : ans; }
bool isvowel(char ch) { return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'); }
ll sign(ll x) {	return x > 0 ? 1 : x < 0 ? -1 : 0; }

template<typename A, typename B> void upmin(A & x, B v) { x = min(x, (A)v); }
template<typename A, typename B> void upmax(A & x, B v) { x = max(x, (A)v); }

const VLL mods = {(ll)1e9 + 7, 998244353, (ll)1e6 + 3, (ll)1e18 + 5};
const ll mod = mods[0];
const ll inf = mods[3];
const db eps = 1e-10;
const db pi = acos(0) * 2;
const string nl = "\n";

ll half(VLL & boxes, VLL & positions) {
	ll n = sz(boxes), m = sz(positions);
	uset<ll> hasbox;
	fe(box, boxes) hasbox.insert(box);
	VLL suf(m+1);
	rrep(i,m-1,0) {
		suf[i] = suf[i+1] + (hasbox.find(positions[i]) != hasbox.end());
	}

	ll ans = 0;
	// for each position, see how many boxes are before it including it
	rep(i,0,m) {
		// count how many boxes are before it
		ll num = upper_bound(all(boxes), positions[i]) - boxes.begin();
		// count how many positions there are from positions[i] - ind + 1 to positions[i]
		ll count = positions.begin() + i - upper_bound(all(positions), positions[i] - num) + 1;
		upmax(ans, count + suf[i+1]);
	}
	return ans;
}

void split(VLL & og, VLL & pos, VLL & neg) {
	pos.clear(); neg.clear();
	fe(o, og) {
		if (o > 0) pos.pb(o);
		else neg.pb(-o);
	}
	sort(all(pos));
	sort(all(neg));
}

void solve() {
	ll n, m;
	cin >> n >> m;
	VLL box(n), pos(m), negbox, posbox, negpos, pospos;
	rep(i,0,n) cin >> box[i];
	rep(j,0,m) cin >> pos[j];

	split(box, posbox, negbox);
	split(pos, pospos, negpos);

	ll ans = half(posbox, pospos) + half(negbox, negpos);
	cout << ans << endl;
}

signed main() {
	ll t = 1;
	cin >> t;
	rep(i,0,t) solve();
	return 0;
}