class Solution {
public:
    string getPermutation(int n, int k) {
        bool p[10];
        string ret="";
        k-=1;
        for (int i=0;i!=10;i++) p[i]=true;
        for (int i=n-1;i>=0;i--)
        {
            int res = k/jie[i];
            k = k%factorial[i];;
            int sum=0;
            for (int j=1;j<=n;j++)
            {
                if (p[j]) sum++;
                if (sum == res+1) {
                    ret+=to_string(j);
                    p[j]=false;
                    break;
                }
            }
        }
        return ret;
    }
    
    const int factorial[10] = {1,1,2,6,24,120,720,5040,40320,362880};
};
