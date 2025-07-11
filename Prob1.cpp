#include<iostream>
#include <queue>
using namespace std;


int FindMinTiles(int fx, int fy, int fa, priority_queue<pair<int, pair<int, int>>>& pq) {
    int mintilesused = 0;
    int reqToCover = fa;

    while (reqToCover > 0 && !pq.empty()) {
        auto p = pq.top(); 
        pq.pop();

        int A = p.first;    
        int x = p.second.first;
        int y = p.second.second;

       
        if (A <= reqToCover && x <= fx && y <= fy) {
            reqToCover -= A;  
            mintilesused++;   
        }
    }


    if (reqToCover == 0) return mintilesused;
    return -1; 
}

int main() {
    int floorX, floorY;
    cout<<"enter the floor Dimension X,Y";
    cin >> floorX >> floorY;
    int floorA = floorX * floorY;  

    priority_queue<pair<int, pair<int, int>>> pq;
    cout<<"Enter the number of tiles";
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout<< "Enter the Dimension of tiles "<<i;
        int x, y;
        cin >> x >> y;
        pq.push({x * y, {x, y}}); 
    }

    int ans;
    ans = FindMinTiles(floorX, floorY, floorA, pq); 

 
    if (ans == -1) {
        cout << "Tiles are not sufficient to fill the floor" << endl;
    }
    else {
        cout << "Required Tiles are: " << ans << endl;
    }
    
    return 0;
}
