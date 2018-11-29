class Solution {
    struct bar{
        int height;
        int ord;
        bar(int h, int o)
        {
            height = h;
            ord = o;
        }
        bool operator <(const bar& tmp) const
        {
            return this->height<tmp.height;
        }
    };
    struct TreeNode{
        int l;
        int r;
        int h;
        int val;
        TreeNode *lt,*rt;
        TreeNode(int tl,int tr,int tval,int th){
            l = tl;
            r = tr;
            val = tval;
            h = th;
            lt = nullptr;
            rt = nullptr;
        }
    };
    
    void InsertNode(TreeNode* p, bar& x)
    {
        if (p->val==-1){
            p->h= x.height;
            p->val = x.ord;
            p->lt = new TreeNode(p->l,p->val-1,-1,-1);
            p->rt = new TreeNode(p->val+1,p->r,-1,-1);
            if (ans<(p->r-p->l+1)*p->h) ans = (p->r-p->l+1)*p->h;
        } else {
            if (x.ord<p->val) InsertNode(p->lt,x);
            else
                InsertNode(p->rt,x);
        }
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size()==0) return 0;
        for (int i=0;i!=heights.size();i++)
        {
            sorth.push_back(bar(heights[i],i));
        }
        sort(sorth.begin(),sorth.end(),[](bar a,bar b)->bool{return a<b;});
        TreeNode* head = new TreeNode(0,heights.size()-1,-1,-1);
        for (int i=0;i!=sorth.size();i++)
        {
            InsertNode(head,sorth[i]);
        }
        return ans;
    }
    vector<bar> sorth;
    int ans=0;
};
