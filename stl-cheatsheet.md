# Tổng hợp STL C++ hay dùng (viết gọn như Python)

## 1. Container hay dùng

| STL | Tương đương Python | Header |
|---|---|---|
| `vector<T>` | `list` | `<vector>` |
| `pair<T1,T2>` | `tuple` 2 phần tử | `<utility>` |
| `tuple<...>` | `tuple` | `<tuple>` |
| `map<K,V>` | `dict` (có sắp xếp key) | `<map>` |
| `unordered_map<K,V>` | `dict` (không sắp xếp) | `<unordered_map>` |
| `set<T>` | `set` (có sắp xếp) | `<set>` |
| `unordered_set<T>` | `set` (không sắp xếp) | `<unordered_set>` |
| `stack<T>` | dùng list làm stack | `<stack>` |
| `queue<T>` | `collections.deque` | `<queue>` |
| `priority_queue<T>` | `heapq` | `<queue>` |
| `deque<T>` | `collections.deque` | `<deque>` |
| `string` | `str` | `<string>` |

```cpp
#include <bits/stdc++.h> // gộp gần hết STL, thi/luyện tập dùng cái này cho gọn
using namespace std;
```

## 2. Khai báo & khởi tạo nhanh

```cpp
vector<int> v = {1, 2, 3};
vector<int> v2(10, 0);        // 10 phần tử giá trị 0
vector<vector<int>> grid(5, vector<int>(5, 0)); // ma trận 5x5

map<string, int> m = {{"a", 1}, {"b", 2}};
set<int> s = {3, 1, 2};       // tự động sort: 1 2 3

pair<int, int> p = {1, 2};
auto [x, y] = p;              // structured binding (C++17) ~ tuple unpacking Python
```

## 3. Duyệt kiểu Python (`for x in list`)

```cpp
for (auto& x : v) cout << x << " ";        // đọc/ghi trực tiếp phần tử
for (auto& [k, val] : m) cout << k << "=" << val << "\n"; // như .items() trong Python
```

## 4. `<algorithm>` — thay cho list comprehension, sort, filter...

```cpp
#include <algorithm>
#include <numeric>   // accumulate, iota

sort(v.begin(), v.end());                     // v.sort()
sort(v.begin(), v.end(), greater<int>());     // sort giảm dần
sort(v.begin(), v.end(), [](int a, int b){    // sort với lambda, như key=
    return a > b;
});

reverse(v.begin(), v.end());                  // v.reverse() / v[::-1]

int s = accumulate(v.begin(), v.end(), 0);    // sum(v)

auto mx = max_element(v.begin(), v.end());    // max(v), trả về iterator
auto mn = min_element(v.begin(), v.end());    // min(v)
cout << *mx;                                  // nhớ dereference (*)

bool found = find(v.begin(), v.end(), 5) != v.end();  // 5 in v
int cnt = count(v.begin(), v.end(), 5);       // v.count(5)

auto last = unique(v.begin(), v.end());       // xóa trùng liền kề (cần sort trước)
v.erase(last, v.end());                       // giống list(dict.fromkeys(v)) sau khi sort

iota(v.begin(), v.end(), 0);                  // v = [0,1,2,...] ~ range(n)

bool ok = binary_search(v.begin(), v.end(), 5); // cần v đã sort

// lọc/biến đổi kiểu filter() và map()
vector<int> out;
copy_if(v.begin(), v.end(), back_inserter(out), [](int x){ return x % 2 == 0; }); // filter
transform(v.begin(), v.end(), v.begin(), [](int x){ return x * 2; });             // map
```

## 5. `string` xử lý như Python

```cpp
string s = "hello world";
s.substr(0, 5);            // s[0:5]
s.find("world");           // s.find("world"), trả về npos nếu không thấy
s + " again";              // nối chuỗi trực tiếp
to_string(123);             // str(123)
stoi("123"); stod("1.5");   // int("123"), float("1.5")

stringstream ss(s);
string word;
while (ss >> word) cout << word << "\n"; // s.split()
```

## 6. Cấu trúc dữ liệu hay dùng trong bài tập

```cpp
// Stack
stack<int> st;
st.push(1); st.top(); st.pop();

// Queue
queue<int> q;
q.push(1); q.front(); q.pop();

// Priority queue (mặc định max-heap)
priority_queue<int> pq;              // lấy phần tử lớn nhất
priority_queue<int, vector<int>, greater<int>> minPq; // min-heap
```

## 7. Vòng lặp/hàm gọn kiểu Python

```cpp
auto sq = [](int x) { return x * x; };   // lambda ~ def / lambda Python
cout << sq(5);

// range-based với index khi cần
for (int i = 0; i < (int)v.size(); i++) ...

// ternary ~ x if cond else y
int r = (a > b) ? a : b;
```

## 8. Mẹo viết gọn cho code C++ như Python

- Dùng `auto` thay vì khai báo kiểu tường minh khi kiểu dài (iterator, pair...).
- `#include <bits/stdc++.h>` + `using namespace std;` để code ngắn khi luyện tập (không dùng trong project lớn).
- Dùng `{}` để khởi tạo nhanh container thay vì loop push_back từng phần tử.
- Dùng structured binding `auto [a, b] = ...` thay vì `.first`, `.second`.
- Với ma trận/2D dùng `vector<vector<int>>` thay mảng tĩnh để linh hoạt như list-of-list Python.


---

## 9. Cú pháp chi tiết từng cái

### `vector<T>`

```cpp
vector<int> v;                    // rỗng
vector<int> v(n);                 // n phần tử mặc định = 0
vector<int> v(n, val);            // n phần tử giá trị val
vector<int> v = {1, 2, 3};        // khởi tạo list

v.push_back(x);        // thêm cuối
v.pop_back();           // xóa cuối
v.size();               // số phần tử (kiểu size_t)
v.empty();              // true nếu rỗng
v.clear();              // xóa hết
v.front(); v.back();    // phần tử đầu / cuối
v[i];                   // truy cập (không kiểm tra biên)
v.at(i);                // truy cập (có kiểm tra biên, throw nếu sai)
v.insert(v.begin() + i, x);   // chèn x vào vị trí i
v.erase(v.begin() + i);       // xóa phần tử vị trí i
v.erase(v.begin() + i, v.begin() + j); // xóa đoạn [i, j)
v.resize(n);            // đổi kích thước
v.begin(); v.end();     // iterator đầu / sau cuối
v.rbegin(); v.rend();   // iterator duyệt ngược
```

### `map<K,V>` / `unordered_map<K,V>`

```cpp
map<string, int> m;

m["key"] = 5;                 // gán (tự tạo nếu chưa có, giống dict Python)
m.insert({"key", 5});         // chèn, không ghi đè nếu đã tồn tại
m.count("key");                // 1 nếu có, 0 nếu không (thay cho "in")
m.find("key");                  // trả về iterator, == m.end() nếu không có
m.erase("key");                 // xóa theo key
m.size();
for (auto& [k, v] : m) ...      // duyệt như .items()

// map (không phải unordered_map) tự sắp xếp theo key
```

### `set<T>` / `unordered_set<T>`

```cpp
set<int> s;

s.insert(x);         // thêm phần tử (tự bỏ qua nếu trùng)
s.erase(x);          // xóa phần tử theo giá trị
s.count(x);           // 1 nếu có, 0 nếu không (thay cho "in")
s.find(x);             // iterator, == s.end() nếu không có
s.size();
*s.begin();            // phần tử nhỏ nhất (set có sắp xếp)
*s.rbegin();           // phần tử lớn nhất
```

### `stack<T>`

```cpp
stack<int> st;
st.push(x);   st.pop();   // pop() không trả giá trị
st.top();     st.empty();  st.size();
```

### `queue<T>`

```cpp
queue<int> q;
q.push(x);    q.pop();
q.front();    q.back();    q.empty();   q.size();
```

### `priority_queue<T>`

```cpp
priority_queue<int> pq;                              // max-heap mặc định
priority_queue<int, vector<int>, greater<int>> pq2;   // min-heap

pq.push(x);   pq.pop();
pq.top();     pq.empty();   pq.size();
```

### `pair<T1,T2>` / `tuple<...>`

```cpp
pair<int, string> p = {1, "a"};
p.first;  p.second;

tuple<int, string, double> t = {1, "a", 2.5};
get<0>(t); get<1>(t); get<2>(t);      // lấy phần tử theo vị trí
auto [a, b, c] = t;                    // unpack (C++17)
```

### `string`

```cpp
string s = "hello";

s.length(); s.size();       // độ dài
s.substr(pos, len);          // cắt chuỗi từ pos, dài len
s.find("lo");                 // vị trí xuất hiện, string::npos nếu không thấy
s.replace(pos, len, "xx");    // thay thế đoạn
s.append("world");             // s += "world"
s.insert(pos, "x");             // chèn tại pos
s.erase(pos, len);               // xóa đoạn
s.compare(other);                 // so sánh như strcmp
s + s2;                            // nối chuỗi
s == s2;                            // so sánh bằng
sort(s.begin(), s.end());            // sort ký tự trong chuỗi
```

### `<algorithm>` — cú pháp đầy đủ

```cpp
sort(first, last);                    // sort(v.begin(), v.end())
sort(first, last, cmp);               // cmp(a,b) trả true nếu a đứng trước b

reverse(first, last);

find(first, last, value);             // trả iterator, so sánh với last để biết có/không

count(first, last, value);            // đếm số lần xuất hiện

max_element(first, last);             // trả iterator tới phần tử lớn nhất
min_element(first, last);

accumulate(first, last, init);        // tổng, cần <numeric>
accumulate(first, last, init, op);    // op(acc, x) tùy biến (vd nhân dồn)

unique(first, last);                  // gộp phần tử trùng liền kề, trả iterator "biên mới"

binary_search(first, last, value);    // cần dãy đã sort, trả bool

lower_bound(first, last, value);      // iterator tới phần tử >= value đầu tiên
upper_bound(first, last, value);      // iterator tới phần tử > value đầu tiên

next_permutation(first, last);        // sinh hoán vị kế tiếp, trả false nếu hết

copy_if(first, last, dest, pred);     // pred(x) trả true thì giữ lại — như filter()
transform(first, last, dest, func);   // func(x) áp lên từng phần tử — như map()
```

