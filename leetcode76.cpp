class Solution {
public:
    bool com(int a[256],int b[256])
    {
        for (int i=0;i!=256;i++){
            if (a[i]>b[i]) {
                return false;
            }
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        if (s.size()==0) return "";
        int st=0;
        int ed=0;
        int minst=0;
        int mined=s.size();
        memset(ori,0,sizeof(ori));
        memset(fid,0,sizeof(fid));
        for (int i=0;i!=t.size();i++) ++fid[t[i]];
        ++ori[s[st]];
        while (true){
            if (ed<st || ed>=s.size()) break;
            if (com(fid,ori))
            {
                if (ed-st<mined-minst)
                {
                    mined=ed;
                    minst=st;
                }
                --ori[s[st]];
                st++;
            } else {
                ed++;
                ++ori[s[ed]];
            }
        }
        if (mined==s.size()) return "";
        else 
            return s.substr(minst,mined-minst+1);
    }
    int ori[256],fid[256];
};
