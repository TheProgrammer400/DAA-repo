#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Point{
    public:
        int x;
        int y;
};

int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y)*(r.x - q.x) - (q.x - p.x)*(r.y - q.y);

    if(val == 0){
        return 0; // colinear
    }

    if(val > 0){
        return 1; // clockwise
    }

    return 2; // counterclockwise
}

vector<Point> jarvisMarch(vector<Point> &points){
    int n = points.size();

    if(n < 3){
        return {}; // Convex hull not possible
    }

    vector<Point> hull;

    int leftMost = 0;

    for(int i = 1; i < n; i++){
        if(points[i].x < points[leftMost].x){
            leftMost = i;
        }
    }

    int p = leftMost;

    while(true){
        hull.push_back(points[p]);
        int q = (p + 1) % n;

        for(int i = 0; i < n; i++){
            if(orientation(points[p], points[i], points[q]) == 2){
                q = i;
            }
        }

        p = q;

        if(p == leftMost){
            break; // completed the hull
        }
    }

    return hull;
}

int main(){
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    vector<Point> hull = jarvisMarch(points);

    cout << "Convex Hull:\n";

    for(int i = 0; i < hull.size(); i++){
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
    }

    return 0;
}
