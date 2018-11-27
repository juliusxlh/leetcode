class Solution {
public:
    bool search(int x,int y,int deep,string& word,vector<vector<char>>& board)
    {
        if (deep == word.size()) 
            return true;
        
        if (x<0 || x>=board.size() || y<0 || y>=board[0].size())
            return false;
        if (f[x*board[0].size()+y]) return false;
        if (board[x][y]!=word[deep])
            return false;
        f[x*board[0].size()+y]=true;
        bool ret = search(x+1,y,deep+1,word,board) || 
            search(x,y+1,deep+1,word,board) ||
            search(x,y-1,deep+1,word,board) ||
            search(x-1,y,deep+1,word,board);
        f[x*board[0].size()+y]=false;
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size()==0){
            return true;
        }
        if (board.size()==0) {
            return false;
        }
        f = new bool[board.size()*board[0].size()];
        memset(f,0,sizeof(bool)*board.size()*board[0].size());
        for (int i=0;i!=board.size();i++){
            for (int j=0;j!=board[0].size();j++){
                if (search(i,j,0,word,board)) return true;
            }
        }
        return false;
    }
    bool* f;
};
