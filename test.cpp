
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

// Thong tin mot chuyen bay
struct Flight {
    map<string, string> attributes;
    string delayClass;
};

// Nut cua cay quyet dinh
struct Node {
    string attribute;
    string classLabel;
    bool isLeaf;
    map<string, Node*> children;

    Node() : isLeaf(true) {}

    ~Node() {
        for (auto& child : children) {
            delete child.second;
        }
    }
};

// Tao mot mau du lieu chuyen bay
Flight taoChuyenBay(
    const string& airline,
    const string& day,
    const string& timeGroup,
    const string& lengthGroup,
    const string& airportFrom,
    const string& airportTo,
    const string& label
) {
    Flight f;

    f.attributes["Airline"] = airline;
    f.attributes["DayOfWeek"] = day;
    f.attributes["TimeGroup"] = timeGroup;
    f.attributes["LengthGroup"] = lengthGroup;
    f.attributes["AirportFrom"] = airportFrom;
    f.attributes["AirportTo"] = airportTo;

    f.delayClass = label;

    return f;
}

// Tinh Entropy cua tap du lieu
double entropy(const vector<Flight>& data) {
    if (data.empty()) return 0.0;

    map<string, int> counts;

    for (const Flight& f : data) {
        counts[f.delayClass]++;
    }

    double result = 0.0;

    for (const auto& item : counts) {
        double p = (double)item.second / data.size();

        if (p > 0.0) {
            result -= p * log2(p);
        }
    }

    return result;
}

// Tim nhan lop pho bien nhat
string majorityClass(const vector<Flight>& data) {
    map<string, int> counts;

    for (const Flight& f : data) {
        counts[f.delayClass]++;
    }

    string bestClass = "";
    int maxCount = -1;

    for (const auto& item : counts) {
        if (item.second > maxCount) {
            maxCount = item.second;
            bestClass = item.first;
        }
    }

    return bestClass;
}

// Kiem tra cac mau co cung nhan lop hay khong
bool sameClass(const vector<Flight>& data) {
    if (data.size() <= 1) return true;

    string firstClass = data[0].delayClass;

    for (const Flight& f : data) {
        if (f.delayClass != firstClass) {
            return false;
        }
    }

    return true;
}

// Chia tap du lieu theo gia tri thuoc tinh
map<string, vector<Flight>> splitData(
    const vector<Flight>& data,
    const string& attribute
) {
    map<string, vector<Flight>> partitions;

    for (const Flight& f : data) {
        auto it = f.attributes.find(attribute);

        if (it != f.attributes.end()) {
            partitions[it->second].push_back(f);
        }
    }

    return partitions;
}

// Tinh Information Gain
double informationGain(
    const vector<Flight>& data,
    const string& attribute
) {
    if (data.empty()) return 0.0;

    double parentEntropy = entropy(data);
    auto partitions = splitData(data, attribute);

    double weightedEntropy = 0.0;

    for (const auto& part : partitions) {
        double weight =
            (double)part.second.size() / data.size();

        weightedEntropy +=
            weight * entropy(part.second);
    }

    return parentEntropy - weightedEntropy;
}

// Tinh Split Information
double splitInfo(
    const vector<Flight>& data,
    const string& attribute
) {
    if (data.empty()) return 0.0;

    auto partitions = splitData(data, attribute);
    double result = 0.0;

    for (const auto& part : partitions) {
        double p =
            (double)part.second.size() / data.size();

        if (p > 0.0) {
            result -= p * log2(p);
        }
    }

    return result;
}

// Tinh Gain Ratio
double gainRatio(
    const vector<Flight>& data,
    const string& attribute
) {
    double split = splitInfo(data, attribute);

    if (split <= 1e-12) {
        return -1.0;
    }

    return informationGain(data, attribute) / split;
}

// Chon thuoc tinh phan chia tot nhat
string chooseBestAttribute(
    const vector<Flight>& data,
    const vector<string>& attributes
) {
    double totalGain = 0.0;
    int validCount = 0;

    // Tinh Information Gain trung binh
    for (const string& attr : attributes) {
        if (splitInfo(data, attr) > 1e-12) {
            totalGain += informationGain(data, attr);
            validCount++;
        }
    }

    if (validCount == 0) return "";

    double averageGain = totalGain / validCount;

    string bestAttribute = "";
    double bestRatio = -1.0;

    // Chon Gain Ratio lon nhat trong nhom dat nguong Gain
    for (const string& attr : attributes) {
        double gain = informationGain(data, attr);
        double ratio = gainRatio(data, attr);

        if (ratio >= 0.0 &&
            gain + 1e-12 >= averageGain) {

            if (ratio > bestRatio) {
                bestRatio = ratio;
                bestAttribute = attr;
            }
        }
    }

    // Phuong an du phong
    if (bestAttribute == "") {
        for (const string& attr : attributes) {
            double ratio = gainRatio(data, attr);

            if (ratio > bestRatio) {
                bestRatio = ratio;
                bestAttribute = attr;
            }
        }
    }

    return bestAttribute;
}

// Xay dung cay quyet dinh theo huong J48/C4.5
Node* J48(
    const vector<Flight>& data,
    const vector<string>& attributes
) {
    Node* node = new Node();
    node->classLabel = majorityClass(data);
    // Dung neu tap rong hoac cac mau cung nhan lop
    if (data.empty() || sameClass(data)) return node;
    // Dung neu khong con thuoc tinh
    if (attributes.empty()) return node;
    // Chon thuoc tinh tot nhat
    string bestAttribute = chooseBestAttribute(data, attributes);
    if (bestAttribute == "") return node;
    // Chia tap du lieu theo thuoc tinh da chon
    auto partitions = splitData(data, bestAttribute);
    if (partitions.size() < 2) return node;
    node->isLeaf = false;
    node->attribute = bestAttribute;
    // Tu tao danh sach thuoc tinh con lai
    vector<string> remainingAttributes;
    for (const string& attr : attributes) {
        if (attr != bestAttribute) {
            remainingAttributes.push_back(attr);
        }
    }
    // De quy xay dung cac cay con
    for (const auto& part : partitions) {
        node->children[part.first] =
            J48(part.second, remainingAttributes);
    }
    return node;
}

// In cay quyet dinh
void printTree(Node* node, int level = 0) {
    if (node == nullptr) return;

    for (int i = 0; i < level; i++) {
        cout << "    ";
    }

    if (node->isLeaf) {
        cout << "[Nhan lop du doan: "
             << node->classLabel << "]\n";
        return;
    }

    cout << "[Thuoc tinh: "
         << node->attribute << "]\n";

    for (const auto& child : node->children) {
        for (int i = 0; i < level + 1; i++) {
            cout << "    ";
        }

        cout << "|-- Gia tri: "
             << child.first << "\n";

        printTree(child.second, level + 2);
    }
}

// Du doan nhan lop cho chuyen bay moi
string predict(
    Node* node,
    const map<string, string>& attributes
) {
    if (node == nullptr) {
        return "Khong xac dinh";
    }

    // Neu la nut la, tra ve nhan lop
    if (node->isLeaf) {
        return node->classLabel;
    }

    // Tim gia tri cua thuoc tinh tai nut hien tai
    auto it = attributes.find(node->attribute);

    if (it == attributes.end()) {
        return node->classLabel;
    }

    // Tim nhanh tuong ung
    auto child = node->children.find(it->second);

    if (child == node->children.end()) {
        return node->classLabel;
    }

    // Tiep tuc di xuong cay
    return predict(child->second, attributes);
}

int main() {
    vector<Flight> trainData;

    // DU LIEU MINH HOA, KHONG PHAI DU LIEU THUC NGHIEM
    // Nhan lop "0" va "1" can khop voi file du lieu cua ban.

    trainData.push_back(taoChuyenBay(
        "AA", "1", "Sang", "Ngan", "JFK", "LAX", "0"));

    trainData.push_back(taoChuyenBay(
        "AA", "1", "Sang", "Dai", "JFK", "ORD", "1"));

    trainData.push_back(taoChuyenBay(
        "AA", "5", "Toi", "Dai", "ORD", "LAX", "1"));

    trainData.push_back(taoChuyenBay(
        "AA", "3", "Chieu", "Ngan", "LAX", "JFK", "0"));

    trainData.push_back(taoChuyenBay(
        "UA", "1", "Sang", "Dai", "JFK", "ORD", "1"));

    trainData.push_back(taoChuyenBay(
        "UA", "3", "Chieu", "Ngan", "ORD", "LAX", "0"));

    trainData.push_back(taoChuyenBay(
        "UA", "5", "Toi", "Dai", "LAX", "JFK", "1"));

    trainData.push_back(taoChuyenBay(
        "UA", "2", "Sang", "Ngan", "JFK", "LAX", "0"));

    trainData.push_back(taoChuyenBay(
        "DL", "5", "Toi", "Dai", "ORD", "JFK", "1"));

    trainData.push_back(taoChuyenBay(
        "DL", "3", "Chieu", "Ngan", "LAX", "ORD", "0"));

    trainData.push_back(taoChuyenBay(
        "DL", "2", "Toi", "Ngan", "JFK", "ORD", "0"));

    trainData.push_back(taoChuyenBay(
        "DL", "5", "Sang", "Dai", "ORD", "LAX", "1"));

    trainData.push_back(taoChuyenBay(
        "WN", "2", "Sang", "Dai", "JFK", "ORD", "1"));

    trainData.push_back(taoChuyenBay(
        "WN", "3", "Chieu", "Ngan", "ORD", "JFK", "0"));

    trainData.push_back(taoChuyenBay(
        "WN", "4", "Chieu", "Dai", "LAX", "ORD", "1"));

    trainData.push_back(taoChuyenBay(
        "WN", "4", "Toi", "Ngan", "LAX", "JFK", "0"));

    // Danh sach thuoc tinh dau vao
    vector<string> attributes = {
        "Airline",
        "DayOfWeek",
        "TimeGroup",
        "LengthGroup",
        "AirportFrom",
        "AirportTo"
    };

    // Xay dung cay
    Node* root = J48(trainData, attributes);

    cout << "===== CAY QUYET DINH J48 =====\n";
    printTree(root);

    // Du doan mot chuyen bay moi
    map<string, string> newFlight;

    newFlight["Airline"] = "AA";
    newFlight["DayOfWeek"] = "1";
    newFlight["TimeGroup"] = "Sang";
    newFlight["LengthGroup"] = "Dai";
    newFlight["AirportFrom"] = "JFK";
    newFlight["AirportTo"] = "ORD";

    cout << "\nNhan lop du doan: "
         << predict(root, newFlight) << "\n";

    delete root;

    return 0;
}
