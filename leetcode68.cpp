class Solution {
public:
    string makeLine(vector<string>& pre, int space)
    {
        string ret="";
        if (pre.size()==1){
            ret+=pre[0];
            ret+=string(space,' ');
            return ret;
        }
        int even = space/(pre.size()-1);
        int num = space%(pre.size()-1);
        
        for (auto i:pre)
        {
            if (space==0){
                ret+=i;
                break;
            }
            ret+=(i+string(even+(num>0?1:0),' '));
            space-=(even+(num>0?1:0));
            num--;
        }
        return ret;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        vector<string> prepare;
        int linelen=0;
        for (auto word:words)
        {
            if (linelen==0) linelen+=word.size();
            else {
                cout << word.size()+linelen+1 << endl;
                if (maxWidth>=word.size()+linelen+1)
                    linelen+=(word.size()+1);
                else{
                    int space = maxWidth - linelen + prepare.size()-1;
                    ret.push_back(makeLine(prepare,space));
                    prepare.clear();
                    linelen = word.size();
                }
            }
            prepare.push_back(word);
            
        }
        string tmp;
        for (auto i=0;i!=prepare.size();i++)
        {
            if (i!=prepare.size()-1) tmp+=prepare[i]+' ';
            else tmp+=prepare[i];
        }
        tmp+=string(maxWidth-tmp.size(),' ');
        ret.push_back(tmp);
        return ret;
    }
};
