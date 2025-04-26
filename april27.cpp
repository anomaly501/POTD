//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

const long long len = 500;
const long long osn = 100000000;

class Solution{
  public:
      
      
    long long A[len] = {0};
    long long B[len] = {0};
    long long C[len] = {0};
    long long tmp[len] = {0};
    long long tmp1[len] = {0};
      
    void SumLong(long long *A, long long *B, long long *C)
    {
        for (int i = 0; i < len; i++) C[i] = 0;
        
        int k = (A[0] > B[0]) ? A[0] : B[0];
        for (int i = 1; i <= k; i++) {
            C[i+1] = (A[i] + B[i] + C[i]) / osn;
            C[i]   = (A[i] + B[i] + C[i]) % osn;
        }
        C[0] = k;
        if (C[k+1] > 0) C[0]++;
        return;
    }

    void MultLongShort(long long *A, long long k, long long *C, int shift)
    {
        for (int i = 0; i < len; i++) C[i] = 0;
                
        for (int i = 1; i <= A[0]; i++) {
            int j = i + shift;
            C[j+1] = (A[i] * k + C[j]) / osn;
            C[j]   = (A[i] * k + C[j]) % osn;
        }
        C[0] = A[0]+shift;
        if (C[C[0]+1] > 0) C[0]++;
        return;
    }
    
    void CopyLong(long long *A, long long *B)
    {
        for (int i = 0; i < len; i++) B[i] = A[i];
        return;
    }

    void ReadLong(string a, long long *A)
    {
        int n = a.size();   
        int i = n-8;
        int k = 0;
        while (i > 0) {
            k++;
            long long v = 0;
            for (int j = 0; j < 8; j++) {
                v = v*10 + (int)(a[i+j] - '0');
            }
            A[k] = v;
            i -= 8;
        }
        long long v = 0;
        for (int i = 0; i < n - k*8; i++) {
            v = v*10 + (int)(a[i] - '0');
        }
        k++;
        A[k] = v;
        A[0] = k;
        return;
    }
    
      
    /*You are required to complete below function */
    string multiplyStrings(string &s1, string &s2) {
        
        if (s1 == "0" || s2 == "0") return "0";

        int neg1 = 0;
        if (s1[0] == '-') {
            neg1 = 1;
            ReadLong(s1.substr(1), A);
        } else {
            ReadLong(s1, A);
        }

        int neg2 = 0;
        if (s2[0] == '-') {
            neg2 = 1;
            ReadLong(s2.substr(1), B);
        } else {
            ReadLong(s2, B);
        }

        C[0] = 1; C[1] = 0;
        for (int i = 1; i <= B[0]; i++) {
            MultLongShort(A, B[i], tmp, i-1);            
            SumLong(C, tmp, tmp1);
            CopyLong(tmp1, C);
        }
        
        char s[20];
        sprintf(s, "%lld", C[C[0]]);
        string res(s);
        for (int i = C[0]-1; i > 0; i--) {
            sprintf(s, "%08lld", C[i]);
            string t(s);
            res += t;
        }
        //cout << res << endl;
        if (res.size() == 1 && res[0] == '0') {
            return "0";
        }

        if ((neg1 + neg2) % 2 == 0) {
            return res;
        } else {
            return "-" + res;
        }
    }

};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends