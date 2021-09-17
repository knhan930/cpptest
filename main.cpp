//
//  main.cpp
//  CTest
//
//  Created by Kyung-Nam Han on 1/14/21.
//  Copyright © 2019 Kyung-Nam Han. All rights reserved.
//

#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <cmath>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

template <typename T>
void disp_v(const T &v) {
    if (!v.size()) return;
    for (auto e: v) {cout << e << " ";}
    cout << endl;
}

template <typename T>
class Distance {
    T _a = 0;
    T _b = 0;
public:
    Distance() {}
    Distance(T a, T b): _a(a), _b(b) {}
    T operator() (T a, T b) const {
        return sqrt(a*a + b*b);
    }
};

float get_random()
{
    //static default_random_engine e;
    static random_device rd;
    static mt19937 mt(rd());
    static uniform_real_distribution<> dis(0, 1); // rage 0 - 1
    return dis(mt);
}

int main() {
    
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<> dis(0, 10); // rage 0 - 1
    
    const int SIZE = 10000000;
    
    vector<float> v1;
    vector<float> v2;
    for (int i=0; i != SIZE; ++i) {
        v1.emplace_back(dis(mt));
        v2.emplace_back(dis(mt));
    }
    
    cout << v1.size() << endl;
    cout << v2.size() << endl;
    
    //disp_v(v1);

    //vector<float> v2 = {0.1, 0.2, 0.3, 0.4, 0.5};
    vector<float> v3 (v1.size());
    vector<float> v4 (v1.size());
    vector<float> v5 (v1.size());

    Distance<float> dist;
    //float d;
    

/*
    auto tic = system_clock::now();
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), dist);
    auto toc = system_clock::now();
    
    duration<double> t1 = toc - tic;
    
    //disp_v(v3);
    tic = system_clock::now();
    transform(v1.begin(), v1.end(), v2.begin(), v4.begin(),
              [](auto a, auto b) -> float {return sqrt(a*a + b*b);}
              );
    toc = system_clock::now();
    duration<double> t2 = toc - tic;
*/
    auto tic = system_clock::now();
    for (int i = 0; i < SIZE; ++i) {
        v5[i] = sqrt( v1[i] * v1[i] + v2[i] * v2[i] );
    }
    auto toc = system_clock::now();
    duration<double> t3 = toc - tic;

    
    //disp_v(v3);
    cout << v1.size() << endl;
    cout << v2.size() << endl;
    cout << v3.size() << endl;
    cout << v4.size() << endl;
    cout << v5.size() << endl;
    //cout << "v3 Time: " << t1.count() * 1000 << " ms" << endl;
    //cout << "v4 Time: " << t2.count() * 1000 << " ms" << endl;
    cout << "v5 Time: " << t3.count() * 1000 << " ms" << endl;

    //cout << d << endl;
}
