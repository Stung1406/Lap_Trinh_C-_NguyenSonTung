#include <iostream>
#include <unordered_map>
using namespace std;


// HashMap trong C++ → dùng unordered_map (thư viện <unordered_map>).

// Là bản đồ (map) key → value.

// Key phải duy nhất, value có thể trùng nhau.

// Dựa trên hash table → tìm kiếm, thêm, xóa trung bình O(1).

// Không lưu thứ tự các phần tử.
int main() {
    unordered_map<int, string> mp;  // key=int, value=string
}


//khai bao
// unordered_map<int, string> mp;       // key=int, value=string
// unordered_map<string, int> mp2;     // key=string, value=int
// unordered_map<char, double> mp3;    // key=char, value=double

//them phan tu
// mp[1] = "Apple"; // tra ve value cua key 1                     // Cách 1: operator[]
// mp.insert({2, "Banana"});            // Cách 2: insert với pair
// mp.emplace(3, "Orange");             // Cách 3: emplace (tránh copy, nhanh hơn)

//kiem tra ton tai key
// if (mp.find(1) != mp.end()) {
//     cout << "Key 1 exists!" << endl;
// }

// if (mp.count(2)) {                   // count trả về 1 nếu tồn tại, 0 nếu không
//     cout << "Key 2 exists!" << endl;
// }


//xoa phan tu 
// mp.erase(1);                          // xóa theo key
// mp.erase(mp.begin());                  // xóa theo iterator
// mp.clear();                            // xóa tất cả


//kiem tra kich thuoc rong 
// mp.size();    // số phần tử
// mp.empty();   // true nếu rỗng

//duyet phan tu 
//for (auto it : mp) {
//     cout << it.first << " -> " << it.second << endl;   // key -> value
// }

// // Hoặc dùng iterator
// for (auto it = mp.begin(); it != mp.end(); ++it) {
//     cout << it->first << " -> " << it->second << endl;
// }


//cap nhat value 
// mp[1] = "Grape";     // key 1 đã tồn tại → cập nhật value
// mp[4] += " Pie";     // thêm chuỗi mới vào value


