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

ll nax = 55;
VLL pp(nax*nax, -1);

void init() {
	for (ll x = 2; x < nax*nax; x++) {
		if (pp[x] != -1) {
			continue;
		}
        pp[x] = x;
		
		for (ll f = x; x * f < nax * nax; f++) {
			pp[x*f] = x;
		}
	}
}

MLL pf(ll x) {
    MLL ans;
    while (x > 1) {
        ans[pp[x]]++;
        x /= pp[x];
    }
    return ans;
}

ll universal_flip = 0;

ll query(VLL args) {
    assert(sz(args) == 6);

    if (universal_flip) {
        for (ll i = 0; i < args.size(); i += 2) {
            swap(args[i], args[i+1]);
        }
    }

    cout << "?";
    fe(a, args) cout << ' ' << a;
    cout << endl;
    cout.flush();
    ll res;
    cin >> res;
    return res;
}

ll can_divide(ll lo_n, ll hi_n, ll m, ll chunks) {
    if (chunks == 1) return 1;

    // e.g. 1-9 divide into 3 -> 1 to 6 and 4 to 9
    // e.g. 1-10 divide into 5 -> 1 to
    ll one_size = (hi_n - lo_n + 1) / chunks;
    ll part_size = one_size * (chunks / 2);
    PLL part1 = {lo_n, lo_n + part_size - 1};
    PLL part2 = {hi_n - part_size + 1, hi_n};

    if (query({part_size, m, part1.first, 1, part2.first, 1})) {

    } else {
        return 0;
    }

    if (chunks % 2 == 0) return can_divide(part1.first, part1.second, m, chunks / 2);


    ll bigger_part_size = one_size * roundup(chunks, 2);
    return can_divide(lo_n, lo_n + bigger_part_size - 1, m, roundup(chunks, 2));
}

ll half(ll n, ll m) {
    // if i get all the prime factors, e.g. 12 is 2 2 3
    MLL factors = pf(n);

    ll ans = 1;
    fe(p, factors) {
        ll prime = p.first;
        ll cnt = p.second;
        ll tempn = n;

        ll good = 0;
        rep(i,0,cnt) {
            if (can_divide(1, tempn, m, prime)) { // can i divide 1-tempn into another prime chunks
                good++;
                tempn /= prime;
            } else {
                break;
            }
        }
        ans *= (good + 1);
    }
    return ans;
}

void solve() {
    init();

	ll n, m;
    cin >> n >> m;

    ll ans = half(n, m);
    universal_flip = 1;
    ans *= half(m, n);

    cout << "! " << ans << endl;
    cout.flush();
}

signed main() {
	ll t = 1;
	// cin >> t;
	rep(i,0,t) solve();
	return 0;
}