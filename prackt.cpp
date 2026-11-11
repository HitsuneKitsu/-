#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    int x, y ;
    x = rand() % 101;
    do {
        cout << "input y(0..100)= ";
        cin >> y;
        if (y > x){
            cout << "mnogo";

        }
        if (y < x){
            cout << "malo" << endl;
        }
    }   while (y!=x);
    cout << "ugadal" << endl;
    /*
    int m, n,x , iter;
    cout << "input m= ";
    cin >> m;
    cout << "input n= ";
    cin >> n;
    cin >> x;
    iter = 0;
    */
    //сам цмкл while

    /*
    while (m!=n) {
        iter++;
        if (m > n)
        {
            m = m - n;
        }
        else {
            n = n - m;
        }
    }
     */

    /*
    do {
        cout << "input x (from 0 to 5)= ";
        if (x < 0){
            cout << "errror" << endl;
        }
        else { 
            if (x > 5){
                cout << "errror" << endl;
            
            }
            else {
                cout << "comtinue" << endl;
            }
        }
    }

    */

    return 0;
}