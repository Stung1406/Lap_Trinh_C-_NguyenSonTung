#include<iostream>
#include<vector>

using namespace std;

// v.size()	Trả về số phần tử hiện có	cout << v.size();
// v.empty()	Kiểm tra vector rỗng (true/false)	if(v.empty())
// v.clear()	Xóa toàn bộ phần tử	v.clear();
// v.resize(n)	Thay đổi kích thước vector	v.resize(10);
// v.resize(n, x)	Mở rộng và gán phần tử mới bằng x	v.resize(10, 99);
// v.capacity()	Dung lượng hiện tại được cấp phát	cout << v.capacity();
// v.shrink_to_fit()	Thu nhỏ dung lượng cho vừa size()	v.shrink_to_fit();
// v.push_back(x)	Thêm phần tử x vào cuối	v.push_back(10);
// v.pop_back()	Xóa phần tử cuối	v.pop_back();
// v.insert(v.begin()+k, x)	Chèn phần tử x vào vị trí thứ k	v.insert(v.begin()+2, 100);
// v.insert(v.begin()+k, n, x)	Chèn n phần tử x tại vị trí k	v.insert(v.begin(), 3, 7);
// v.erase(v.begin()+k)	Xóa phần tử tại vị trí k	v.erase(v.begin()+1);
// v.erase(v.begin()+l, v.begin()+r)	Xóa đoạn [l, r)	v.erase(v.begin()+1, v.begin()+4);
// v.emplace(v.begin()+k, x)	Chèn hiệu quả hơn insert	v.emplace(v.begin(), 99);
// v.emplace_back(x)	Thêm phần tử cuối (nhanh hơn push_back)	v.emplace_back(5);
// v.assign(n, x)	Gán lại vector gồm n phần tử = x	v.assign(5, 9);
// v.assign({a,b,c})	Gán bằng danh sách	v.assign({1,2,3});

int main()
{
    vector<int> v = {1,2,3,4};
    cout<<
}