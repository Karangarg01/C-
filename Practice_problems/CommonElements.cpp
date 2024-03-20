class Solution
{
    public:    
     vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3) {
    vector<int> ans;
    vector<int> v;

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (A[i] < B[j])
            i++;
        else if (A[i] > B[j])
            j++;
        else { // A[i] == B[j]
            if (v.empty() || v.back() != A[i])
                v.push_back(A[i]);
            i++;
            j++;
        }
    }

    int l = 0, m = 0;
    while (l < n3 && m < v.size()) {
        if (C[l] < v[m])
            l++;
        else if (C[l] > v[m])
            m++;
        else { // C[l] == v[m]
            ans.push_back(v[m]);
            l++;
            m++;
        }
    }

    return ans;
}

};
