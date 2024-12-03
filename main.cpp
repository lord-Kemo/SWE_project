#include <bits/stdc++.h>
#define el "\n"
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
#define pb push_back
#define YES cout << "YES" << el;
#define NO cout << "NO" << el;
#include <iostream>
#include<limits>
#include<algorithm>

using namespace std;

int main() {
    string unit;
    long double value;
    string unit2;
    cout << "Enter the unit you have(m, km, cm, mm, nm, Mm): " << el;
    cin >> unit;
    cout << "Enter the value you have: " << el;
    cin >> value;
    cout << "Enter the unit you want to convert to(m, km, cm, mm, nm, Mm): " << el;
    cin >> unit2;
    bool system = true;
    while(system){
        if(unit == "m" && unit2 == "km"){
            cout << value / 1000 << " km" << el;
        }
        if(unit == "m" && unit2 == "cm"){
            cout << value * 100 << " cm" << el;
        }
        if(unit == "m" && unit2 == "mm"){
            cout << value * 1000 << " mm" << el;
        }
        if(unit == "m" && unit2 == "nm"){
            cout << value * 1000000000 << " nm" << el;
        }
        if(unit == "m" && unit2 == "Mm"){
            cout << value / 1000000 << " Mm" << el;
        }
        if(unit == "km" && unit2 == "m"){
            cout << value * 1000 << " m" << el;
        }
        if(unit == "km" && unit2 == "cm"){
            cout << value * 100000 << " cm" << el;
        }
        if(unit == "km" && unit2 == "mm"){
            cout << value * 1000000 << " mm" << el;
        }
        if(unit == "km" && unit2 == "nm"){
            cout << value * 1000000000000 << " nm" << el;
        }
        if(unit == "km" && unit2 == "Mm"){
            cout << value << " Mm" << el;
        }
        if(unit == "cm" && unit2 == "m"){
            cout << value / 100 << " m" << el;
        }
        if(unit == "cm" && unit2 == "km"){
            cout << value / 100000 << " km" << el;
        }
        if(unit == "cm" && unit2 == "mm"){
            cout << value * 10 << " mm" << el;
        }
        if(unit == "cm" && unit2 == "nm"){
            cout << value * 10000000 << " nm" << el;
        }
        if(unit == "cm" && unit2 == "Mm"){
            cout << value / 10000000 << " Mm" << el;
        }
        if(unit == "mm" && unit2 == "m"){
            cout << value / 1000 << " m" << el;
        }
        if(unit == "mm" && unit2 == "km"){
            cout << value / 1000000 << " km" << el;
        }
        if(unit == "mm" && unit2 == "cm"){
            cout << value / 10 << " cm" << el;
        }
        if(unit == "mm" && unit2 == "nm"){
            cout << value * 1000000 << " nm" << el;
        }
        if(unit == "mm" && unit2 == "Mm"){
            cout << value / 1000000 << " Mm" << el;
        }
        if(unit == "nm" && unit2 == "m"){
            cout << value / 1000000000 << " m" << el;
        }
        if(unit == "nm" && unit2 == "km"){
            cout << value / 1000000000000 << " km" << el;
        }
        if(unit == "nm" && unit2 == "cm"){
            cout << value / 10000000 << " cm" << el;
        }
        if(unit == "nm" && unit2 == "mm"){
            cout << value / 1000000 << " mm" << el;
        }
        if(unit == "nm" && unit2 == "Mm"){
            cout << value / 1000000000 << " Mm" << el;
        }
        if(unit == "Mm" && unit2 == "m"){
            cout << value * 1000000 << " m" << el;
        }
        if(unit == "Mm" && unit2 == "km"){
            cout << value * 1000 << " km" << el;
        }
        if(unit == "Mm" && unit2 == "cm"){
            cout << value * 10000000 << " cm" << el;
        }
        if(unit == "Mm" && unit2 == "mm"){
            cout << value * 1000000 << " mm" << el;
        }
        if(unit == "Mm" && unit2 == "nm"){
            cout << value * 1000000000 << " nm" << el;
        }
        cout << "Do you want to convert another value? (yes/no)" << el;
        string answer;
        cin >> answer;
        if(answer == "yes"){
            cout << "Enter the unit you have(m, km, cm, mm, nm, Mm): " << el;
            cin >> unit;
            cout << "Enter the value you have: " << el;
            cin >> value;
            cout << "Enter the unit you want to convert to(m, km, cm, mm, nm, Mm): " << el;
            cin >> unit2;
        }
        else{
            system = false;
        }
    }// new comment
    return 0;
}


