// C library
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// Containers
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Input/Output
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>

// Other
#include <algorithm>
#include <bitset>
#include <chrono>
#include <iterator>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

// ==================================================

using namespace std;

// constants
const double EPS = 1e-9;
const int MOD = 1000000007;

// type alias
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vb = vector<bool>;
using vc = vector<char>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using mii = map<int, int>;
using mci = map<char, int>;
using si = set<int>;
using spii = set<pair<int, int>>;
using umii = unordered_map<int, int>;
using umci = unordered_map<char, int>;
using umsi = unordered_map<string, int>;
using usi = unordered_set<int>;
using vpii = vector<pair<int, int>>;

typedef struct TreeNode TreeNode;
using ptn = TreeNode *;
using tn = TreeNode;

// ==================================================

// fast IO
static auto __2333__ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

// ==================================================

// some macro for less typing
#define fori(n) for (int i = 0; i <= int(n); ++i)            // [0, n)
#define each(i, n) for (int i = 0; i <= int(n); ++i)         // [0, n)
#define eachv(i, n) for (int i = int(n); i >= 0; --i)        // reverse [0, n)
#define up(i, a, b) for (int i = int(a); i <= int(b); ++i)   // [a, b)
#define down(i, b, a) for (int i = int(b); i >= int(a); --i) // reverse [a, b)
#define unfold(i, arr) for (auto &i : arr)

#define INF 0x3f3f3f3f
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
#define ef emplace_front
#define eb emplace_back
#define dall(v) v.begin(), v.end()
#define dsize(v) (int)v.size()
#define dsort(v) sort(v.begin(), v.end())
#define rdsort(v) sort(v.rbegin(), v.rend())
#define dreverse(v) reverse(v.begin(), v.end())

inline string itos(int n) { return to_string(n); }
inline string upper(string s) {
  string t(s);
  transform(t.begin(), t.end(), t.begin(), ::toupper);
  return t;
}
inline string lower(string s) {
  string t(s);
  transform(t.begin(), t.end(), t.begin(), ::tolower);
  return t;
}

int direction[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                       {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

// ==================================================
// math
bool is_prime(ll x) {
  if (x == 1 || x <= 0)
    return false;
  if (x == 2)
    return true;
  assert(x > 1);
  long long m = ceil(sqrt(x));
  up(i, 2, m) {
    if (!(x % i))
      return false;
  }
  return true;
}

// prime table
const int PRIME_MAX = 10;
vi prime_table;
vector<bool> prime_table_bool(PRIME_MAX, true);

void get_prime() {
  up(i, 2, PRIME_MAX) {
    if (prime_table_bool[i]) {
      prime_table.push_back(i);
      for (int j = i << 1; j <= PRIME_MAX; j += i)
        prime_table_bool[j] = false;
    }
  }
}

// double equals
bool eq(double a, double b) { return fabs(a - b) < EPS; }

double random_() {
  // generate random number in [0, 1]
  return double(rand()) / RAND_MAX;
}

int random_(int m) {
  // generate random int between [0, m - 1]
  return int(random_() * (m - 1) + 0.5);
}

// ======================================================
// CONVENIENT FUNCTIONS
// whether s is substring of t
bool is_sub(string s, string t) {
  if (s.size() > t.size())
    return false;

  int i = 0, j = 0;
  while (i < s.size() && j < t.size())
    if (s[i] == t[j++])
      i++;

  return (i == s.size());
}

bool isPalindrome(string str) {
  int i = 0, j = str.size() - 1;
  while (i < j)
    if (str[i++] != str[j--])
      return false;
  return true;
}

string join(vs &arr, string del = " ") {
  string res;
  for (auto &s : arr)
    res += s + del;
  return res.substr(0, res.size() - 1);
}

// sort vector of vector<int> by first element
void sort_by_last(vvi &a) {
  sort(a.begin(), a.end(),
       [](const vi &p, const vi &q) { return p.back() < q.back(); });
}

// quick sum, product, max, min elemnt of a vector<int>
int sum_(vi &a) { return accumulate(a.begin(), a.end(), 0); }

template <class T> void reverse_(const vector<T> &vect) {
  reverse(vect.begin(), vect.end());
}

void reverseStr(string &s) { reverse(s.begin(), s.end()); }

unsigned long long product(vector<int> &a) {
  unsigned long long res = 1;
  for (auto &i : a)
    res *= i;
  return res;
}

int vec_max(vi &a) {
  int r = INT_MIN;
  for (auto &i : a)
    r = max(r, i);
  return r;
}
int vec_min(vi &a) {
  int r = INT_MAX;
  for (auto &i : a)
    r = min(r, i);
  return r;
}
umii counter(vi &a) {
  umii c = {};
  for (auto &x : a)
    ++c[x];
  return c;
}

bool isodd(int &n) { return n % 2 == 1; }
bool iseven(int &n) { return n % 2 == 0; }

// whether two rectangles a = {x1,x2,y1,y2} and b = {s1,s2,t1,t2} overlap
bool isRectangleOverlap(vector<int> &a, vector<int> &b) {
  if (a[0] > b[0])
    return isRectangleOverlap(b, a);
  return !(a[2] <= b[0] || a[3] <= b[1] || a[1] >= b[3]);
}

// whether a key in a map
template <class K, class V> bool exist(unordered_map<K, V> &m, K key) {
  return m.find(key) != m.end();
}

string lcs(string s, string t) {
  int m = s.size(), n = t.size(), L[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      if (i == 0 || j == 0)
        L[i][j] = 0;
      else if (s[i - 1] == t[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;
      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);

  string res(L[m][n], '#');
  int i = m, j = n, index = L[m][n];

  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1])
      res[index - 1] = s[i - 1], index--, i--, j--;
    else if (L[i - 1][j] > L[i][j - 1])
      i--;
    else
      j--;
  }
  return res;
}

// shortest common supersequence, e.e., scs("abcde", "pkqcze") = "abpkqcdze"
string scs(string s, string t) {
  int m = s.size(), n = t.size(), L[m + 1][n + 1];
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= n; j++)
      if (i == 0 || j == 0)
        L[i][j] = 0;
      else if (s[i - 1] == t[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;
      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);

  string res(m + n - L[m][n], '#');
  int i = m, j = n, index = m + n - L[m][n];

  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1])
      res[--index] = s[--i], j--;
    else if (L[i - 1][j] > L[i][j - 1])
      res[--index] = s[--i];
    else
      res[--index] = t[--j];
  }

  if (i + j == 0)
    return res;
  else if (j > 0)
    while (j > 0)
      res[--index] = t[--j];
  else
    while (i > 0)
      res[--index] = s[--i];
  return res;
}

// =========================================================================
// This class represents a directed graph using adjacency list representation
class Graph {
  int V;          // No. of vertices
  list<pii> *adj; // In a weighted graph, we need to store vertex and weight
                  // pair for every edge

public:
  Graph(int V); // Constructor
  void addEdge(int u, int v, int w);
  vi shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V) {
  this->V = V;
  adj = new list<pii>[V];
}

void Graph::addEdge(int u, int v, int w) {
  adj[u].push_back(make_pair(v, w));
  adj[v].push_back(make_pair(u, w));
}

// Get shortest paths from src to all other vertices using Dijkstra's algorithm
vector<int> Graph::shortestPath(int src) {
  // Create a priority queue to store vertices that
  // are being preprocessed. This is weird syntax in C++.
  // Refer below link for details of this syntax
  // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  vi dist(V, INF);

  pq.push(make_pair(0, src));
  dist[src] = 0;

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto &i : adj[u]) {
      int v = i.first;
      int weight = i.second;

      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  // Print shortest distances stored in dist[]
  // printf("Vertex   Distance from Source\n");
  // for (int i = 0; i < V; ++i)
  //   printf("%d \t\t %d\n", i, dist[i]);

  return dist;
}

template <typename T1, typename T2> void printMap(unordered_map<T1, T2> &m) {
  for (auto iter = m.begin(); iter != m.end(); iter++)
    cout << iter->first << ", " << iter->second << endl;
}

// ==================================================

#ifdef DEBUG
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

TreeNode *growTreeFromList(vector<int> &arr) {
  if (arr.empty())
    return nullptr;
  TreeNode *root = new TreeNode(arr[0]);
  vector<TreeNode *> stack = {root};
  int i = 0, j = 1;

  while (j < arr.size()) {
    TreeNode *cur_node = stack[i];
    i += 1;
    if (cur_node == nullptr)
      j += 1;
    else {
      int value = arr[j];
      if (value == INT_MIN)
        cur_node->left = nullptr;
      else
        cur_node->left = new TreeNode(value);
      stack.emplace_back(cur_node->left);

      if (j + 1 >= arr.size())
        break;

      value = arr[j + 1];
      if (value == INT_MIN)
        cur_node->right = nullptr;
      else
        cur_node->right = new TreeNode(value);
      stack.emplace_back(cur_node->right);

      j += 2;
    }
  }
  return root;
}

// Find the index of the first number in sorted nums, that is larger than target
int bisect_right(vector<int> &nums, int target) {
  int i = 0, j = nums.size() - 1, mid = 0;
  while (i < j) {
    mid = ceil((i + j) * 1.0 / 2);
    if (nums[mid] > target)
      j = mid - 1;
    else
      i = mid;
  }
  return nums[j] > target ? j : j + 1;
}

bool in(string str1, string str2) { return str1.find(str2) != string::npos; }

// lowest common ancestor of two nodes(values are distinct)
TreeNode *lca(TreeNode *r, int pv, int qv) {
  if (r == NULL || r->val == pv || r->val == qv)
    return r;
  TreeNode *left = lca(r->left, pv, qv);
  TreeNode *right = lca(r->right, pv, qv);
  return left == NULL ? right : (right == NULL ? left : r);
};

/* Travel through a tree and return a list of list, lis[i] is the values of all
 * nodes with depth i
 */
vector<vector<int>> valuesOfTree(TreeNode *r) {
  vector<vector<int>> res;
  stack<pair<int, TreeNode *>> stack;
  stack.push(make_pair(0, r));

  while (!stack.empty()) {
    pair<int, TreeNode *> cur = stack.top();
    stack.pop();
    TreeNode *tn = cur.second;
    if (tn == NULL)
      continue;

    int depth = cur.first;
    if (res.size() <= depth)
      res.push_back({});
    res[depth].emplace_back(tn->val);
    stack.push(make_pair(depth + 1, tn->right));
    stack.push(make_pair(depth + 1, tn->left));
  }
  return res;
}

ListNode *reverseList(ListNode *head) {
  if (!head)
    return head;
  ListNode *pre, *cur;
  pre = NULL;
  while (head) {
    cur = head->next;
    head->next = pre;
    pre = head;
    head = cur;
  }
  return pre;
}

int getListLen(ListNode *head) {
  int len = 0;
  ListNode *dummy = head;
  while (dummy) {
    len++;
    dummy = dummy->next;
  }
  return len;
}

int getLastListValue(ListNode *head) {
  int value = -1;
  ListNode *dummy = head;
  while (dummy) {
    value = dummy->val;
    dummy = dummy->next;
  }
  return value;
}

bool isSortedList(ListNode *head) {
  if (!head)
    return true;
  ListNode *dummy = head;
  while (head->next) {
    if (head->val > head->next->val)
      return false;
    head = head->next;
  }
  return true;
}

/* Translate an array of int to ListNode */
ListNode *arrayToListNode(vector<int> &arr) {
  ListNode *head, *pre;
  if (arr.size() == 0)
    return head;
  head = new ListNode(-0x3f3f3f3f);
  pre = head;
  for (auto &i : arr) {
    ListNode *tmp = new ListNode(i);
    pre->next = tmp;
    pre = tmp;
  }
  return head->next;
}

/* Transfer a lowercase string to a vector of int,
each element counting the char in the string */
vector<int> char_counter(string chars) {
  vector<int> cc(26, 0);
  for (auto &c : chars)
    cc[c - 'a'] += 1;
  return cc;
}

/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 *
 * https://leetcode.com/problems/regions-cut-by-slashes/description/
 *
 * algorithms
 * Medium (64.23%)
 * Total Accepted:    11.7K
 * Total Submissions: 18.2K
 * Testcase Example:  '[" /","/ "]'
 *
 * In a N x N grid composed of 1 x 1 squares, each 1 x 1 square consists of a
 * /, \, or blank space.  These characters divide the square into contiguous
 * regions.
 *
 * (Note that backslash characters are escaped, so a \ is represented as
 * "\\".)
 *
 * Return the number of regions.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input:
 * [
 * " /",
 * "/ "
 * ]
 * Output: 2
 * Explanation: The 2x2 grid is as follows:
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input:
 * [
 * " /",
 * "  "
 * ]
 * Output: 1
 * Explanation: The 2x2 grid is as follows:
 *
 *
 *
 *
 * Example 3:
 *
 *
 * Input:
 * [
 * "\\/",
 * "/\\"
 * ]
 * Output: 4
 * Explanation: (Recall that because \ characters are escaped, "\\/" refers to
 * \/, and "/\\" refers to /\.)
 * The 2x2 grid is as follows:
 *
 *
 *
 *
 * Example 4:
 *
 *
 * Input:
 * [
 * "/\\",
 * "\\/"
 * ]
 * Output: 5
 * Explanation: (Recall that because \ characters are escaped, "/\\" refers to
 * /\, and "\\/" refers to \/.)
 * The 2x2 grid is as follows:
 *
 *
 *
 *
 * Example 5:
 *
 *
 * Input:
 * [
 * "//",
 * "/ "
 * ]
 * Output: 3
 * Explanation: The 2x2 grid is as follows:
 *
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= grid.length == grid[0].length <= 30
 * grid[i][j] is either '/', '\', or ' '.
 *
 *
 *
 *
 *
 *
 */
class Solution {
  vi p;

public:
  int find(int x) {
    if (x != p[x])
      p[x] = find(p[x]);
    return p[x];
  }

  int merge(int x, int y) {
    int p1 = find(x), p2 = find(y);
    p[p1] = p2;
    return p1 == p2 ? 1 : 0;
  }

  int regionsBySlashes(vector<string> &grid) {
    size_t n = grid.size();
    int res = 1;
    for (size_t i = 0; i <= n; ++i)
      for (size_t j = 0; j <= n; ++j)
        p.push_back(i == 0 || j == 0 || i == n || j == n ? 0 : i * (n + 1) + j);

    for (size_t i = 0; i < n; i++)
      for (size_t j = 0; j < n; j++)
        if (grid[i][j] == '/')
          res += merge(i * (n + 1) + j + 1, (i + 1) * (n + 1) + j);
        else if (grid[i][j] == '\\')
          res += merge(i * (n + 1) + j, (i + 1) * (n + 1) + j + 1);

    return res;
  }
};

static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
