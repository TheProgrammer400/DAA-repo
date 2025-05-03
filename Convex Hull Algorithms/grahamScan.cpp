#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Point{
    public:
        int x;
        int y;
};

Point pivot;

int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if(val == 0){
        return 0; // colinear
    }

    if(val > 0){
        return 1; // clockwise
    }

    return 2; // counterclockwise
}

bool polarCompare(Point a, Point b){
    int orient = orientation(pivot, a, b);

    if(orient == 0){
        int distA = (pivot.x - a.x) * (pivot.x - a.x) + (pivot.y - a.y) * (pivot.y - a.y);
        int distB = (pivot.x - b.x) * (pivot.x - b.x) + (pivot.y - b.y) * (pivot.y - b.y);

        return distA < distB;
    }

    if(orient == 2){
        return true;
    }

    return false;
}

vector<Point> grahamScan(vector<Point> &points){
    int n = points.size();

    int minIndex = 0;

    for(int i = 1; i < n; i++){
        if(points[i].y < points[minIndex].y){
            minIndex = i;
        } else if(points[i].y == points[minIndex].y && points[i].x < points[minIndex].x){
            minIndex = i;
        }
    }

    swap(points[0], points[minIndex]);
    pivot = points[0];

    sort(points.begin() + 1, points.end(), polarCompare);

    stack<Point> st;
    st.push(points[0]);
    st.push(points[1]);
    st.push(points[2]);

    for(int i = 3; i < n; i++){
        while(st.size() >= 2){
            Point top = st.top();
            st.pop();
            Point nextToTop = st.top();

            if(orientation(nextToTop, top, points[i]) == 2){
                st.push(top);
                break;
            }
        }

        st.push(points[i]);
    }

    vector<Point> hull;

    while(!st.empty()){
        hull.push_back(st.top());
        st.pop();
    }

    reverse(hull.begin(), hull.end());
    return hull;
}

int main(){
    vector<Point> points = {{1,1}, {2,5}, {3,3}, {5,3}, {3,2}, {2,2}};
    vector<Point> hull = grahamScan(points);

    cout << "Convex Hull:\n";

    for(int i = 0; i < hull.size(); i++){
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
    }

    return 0;
}