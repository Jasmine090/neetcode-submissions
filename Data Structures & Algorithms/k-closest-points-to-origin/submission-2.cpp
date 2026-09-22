class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickselect(points, 0, points.size()-1, k);
        return vector<vector<int>>(points.begin(), points.begin()+k);
        
    }
    int distSq(vector<int> &p){
        return p[0]*p[0] + p[1]*p[1];
    }
    int partition(vector<vector<int>> &points, int left, int right){
        int pivot = distSq(points[right]);
        int i = left-1;
        for(int j=left;j<right;j++){
            if(distSq(points[j])<pivot){
                i++;
                swap(points[i], points[j]);
            }
        }
        swap(points[i+1], points[right]);
        return i+1;
    }
    void quickselect(vector<vector<int>> &points, int left, int right, int k){
        if(left>=right) return;
        int pivotIdx = partition(points, left, right);
        if(pivotIdx==k) return;
        else if(pivotIdx<k){
            quickselect(points, pivotIdx+1, right, k);
        }
        else{
            quickselect(points, left, pivotIdx-1, k);
        }
    }
};
