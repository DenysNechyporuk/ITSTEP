#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

void printVector(const vector<int>& v, const string& name)
{
    cout << name << " :: ";
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void main()
{
    srand((unsigned int)time(0));

    // 1
    vector<int> v1;
    int n;
    cout << "Enter count for v1 :: ";
    cin >> n;
    cout << "Enter elements :: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v1.push_back(x);
    }

    vector<int> v2(10, 0);

    int m;
    cout << "Enter count for v3 :: ";
    cin >> m;
    vector<int> v3(m);
    for (int i = 0; i < m; i++)
        v3[i] = rand() % 100;

    vector<int> v4(v1);

    vector<int> v5(v3.begin() + 1, v3.end() - 1);

    // 2
    printVector(v3, "v3");
    cout << "v1 reversed :: ";
    for (int i = (int)v1.size() - 1; i >= 0; i--)
        cout << v1[i] << " ";
    cout << endl;

    // 3
    for (int i = 0; i < 10; i++)
        v2[i] = i + 1;
    mt19937 rng((unsigned int)time(0));
    shuffle(v2.begin(), v2.end(), rng);
    v2.erase(v2.begin() + 1);
    v2.erase(v2.end() - 1);
    printVector(v2, "v2 after shuffle and erase");

    // 4
    for (int i = (int)v4.size() - 1; i >= 0; i--)
        v4.insert(v4.begin() + i + 1, v4[i]);
    printVector(v4, "v4 doubled");

    // 5
    v5.clear();
    for (int i = 0; i < (int)v4.size(); i++)
        if (v4[i] % 2 == 0)
            v5.push_back(v4[i] / 2);
    printVector(v5, "v5 even halved");

    // 6
    int target;
    cout << "Enter target value :: ";
    cin >> target;

    cout << "Positions of " << target << " in v5 :: ";
    for (auto it = v5.begin(); it != v5.end(); it++)
        if (*it == target)
            cout << (it - v5.begin()) << " ";
    cout << endl;

    cout << "Count of " << target << " in v5 :: " << count(v5.begin(), v5.end(), target) << endl;

    // 7
    swap(v4, v5);
    printVector(v4, "v4 after swap");
    printVector(v5, "v5 after swap");
}