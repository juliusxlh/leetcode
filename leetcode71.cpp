class Solution {
public:
    void splitString(vector<string>& to, string& from)
    {
        int st=0;

        while (st<from.size()){
            int pos = from.find('/',st);
            if (pos==-1){
                string tmp=std::move(from.substr(st,from.size()-st+1));
                if (tmp=="."){
                
                } else if (tmp==".."){
                    if (to.size()!=0) to.pop_back();
                } else{
                    to.push_back(std::move(tmp));
                }
                break;
            }
            if (pos-st!=0) {
                string tmp=std::move(from.substr(st,pos-st));
                if (tmp=="."){
                
                } else if (tmp==".."){
                    if (to.size()!=0) to.pop_back();
                } else{
                    to.push_back(std::move(tmp));
                }
            }
            st=pos+1;
        }
    }
    
    string simplifyPath(string path) {
        ret.clear();
        splitString(ret,path);
        string ans="";
        for (auto i:ret) {
            ans+=("/"+i);
        }
        if (ret.size()==0) return "/";
            else{
                return ans;
            }
    }
    vector<string> ret;
};
