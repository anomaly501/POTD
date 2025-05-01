//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        if(n==1){
            return {1};
        }
        if(n==2){
            return {1,1};
        }
        vector<int>ans{1,1};
        vector<int>res;
        n=n-2;
        while(n--){
            res.push_back(1);
            for(int i=0;i<ans.size()-1;i++){
                res.push_back(ans[i]+ans[i+1]);
            }
            res.push_back(1);
            ans=vector<int>(res.begin(),res.end());
            res.clear();
        }
        return ans;
    }
};



//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends