#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define fastc ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

void sortX(vector<pair<float,float>>&points){
    sort(points.begin(), points.end(),[](const pair<float,float>& p1, const pair<float,float>& p2){
        return p1.first < p2.first ;
    });
}

void sortY(vector<pair<float,float>>&points){
    sort(points.begin(), points.end(),[](const pair<float,float>& p1, const pair<float,float>& p2){
        return p1.second < p2.second ;
    });
}

//to compute distance between points, we can avoid using sqrt because if d1 < d2 then sqrt(d1) < sqrt(d2), so we can just compare squared distances
float squaredDistance(pair<float,float>& p1, pair<float,float>& p2){
    float x1 = p1.first, x2 = p2.first, y1 = p1.second, y2 = p2.second;
    float x1x2 = x1-x2, y1y2 = y1-y2;
    return x1x2*x1x2 + y1y2*y1y2;
}

float bruteForceMinOfThreePoins(pair<float,float>& p1, pair<float,float>& p2, pair<float,float>& p3){
    return min( squaredDistance(p1,p2), min(squaredDistance(p2,p3), squaredDistance(p1,p3)) );
}

float absoluteVerticalDistance(pair<float,float>& p1, pair<float,float>& p2){
    return abs(p1.second - p2.second);
}
float middleStripCandidate(vector<pair<float,float>>&points, int mid, float d){

    float midX = points[mid].first;
    vector<pair<float,float>> strip;

    //get all points whose x coordinate is within d distance from midX
    //this is because points further away than d cannot have a distance less than d with any point on the left side
    //so we only need to consider points within this vertical strip of width 2d centered at midX
    //this is because we are looking for points across the dividing line that could have a smaller distance than d
    //we only need to check points within this strip because points outside this strip will have a distance greater than d

    for(int i = 0; i < points.size(); i++){
        if( abs(points[i].first - midX) < d ){
            strip.push_back(points[i]);
        }
    }

    //sort points in strip according to y coordinate, because we will only check points within d distance in y direction
    //this is because points further away than d in y direction cannot have a distance less than d with any point in the strip
    //so we only need to consider points within this horizontal strip of height 2d centered at mid line
    sortY(strip);

    //for each point in strip, find distance to next points in strip whose y coordinate is within d distance
    //we only need to check next points in strip because points before this point have already been checked
    //thats why we start j from i+1

    //it is mathematically proven that we only need to check at most 7 points ahead in the sorted strip
    //because in a rectangle of dimension 2d x d, we can fit at most 8 points such that no two points are within distance d of each other
    //because if there was another point, it would already have been computed in either left or right half
    
    for(int i = 0; i < strip.size(); i++){
        for(int j = i + 1; j < strip.size() && absoluteVerticalDistance(strip[i], strip[j]) < d; j++){
            d = min(d, squaredDistance(strip[i], strip[j]));
        }
    }
    return d;
}

float closestPair(vector<pair<float,float>>&points,int low, int high){

    if(high -low ==2){
        return bruteForceMinOfThreePoins(points[low], points[low+1], points[high]);
    }
    if(high - low == 1){ //if original array has only two elements
        return squaredDistance(points[low], points[high]);
    }

    int mid = low + (high - low)/2;
    float d = 0;
    if(low < high){
        float leftMin = closestPair(points,low, mid);
        float rightMin = closestPair(points, mid + 1, high);
        d = min(leftMin, rightMin);
    }
    return min(d, middleStripCandidate(points, mid, d));
}


string x = R"(
d1 is min in left half
|    .<-d1->.   |
|               |
|               |   .<--d2-->.   d2 is min in right half
|               | 
|            p4.|
|               |.p3
|          <-d1-|-d1->
|               |
--------------------------------------
low          mid            high
d1 is smaller
d1<d2 -> min = d = d1
add all points that are less than d1 distance from midx
aka p4,p3
dist(p4,p3) < d1
d = min(d, dist(p4,p3))
d3 is the min distance across the mid line
final min = min(d1,d2,d3) = d3
)";



int main(){
    fastc;


    vector<pair<float,float>> points = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    sortX(points);

    float minDist = closestPair(points, 0, points.size() - 1);
    cout<<"Minimum Distance Squared: "<<sqrt(minDist)<<endl;
    return 0;
}