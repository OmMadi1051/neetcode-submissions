class Solution {
public:
    bool ckSudoku(vector<vector<char>>& board,vector<int>& vis,int i,int j){
        for(int k=i;k<i+3;k++){
            for(int l=j;l<j+3;l++){
                if(isdigit(board[k][l])){
                    if(vis[board[k][l]-'0']!=0){
                    return false;
                    }
                vis[board[k][l]-'0']=1;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> visCk(10,0);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(isdigit(board[i][j])){
                    if(visCk[board[i][j]-'0']!=0){
                        //cout<<1<<endl;
                        return false;
                }
                visCk[board[i][j]-'0']=1;
                }
            }
            fill(visCk.begin(),visCk.end(),0);
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(isdigit(board[j][i])){
                    if(visCk[board[j][i]-'0']!=0){
                        //cout<<2<<endl;
                        return false;
                }
                visCk[board[j][i]-'0']=1;
                }
            }
            fill(visCk.begin(),visCk.end(),0);
        }
    
    // fill(visCk.begin(),visCk.end(),0);
    for(int i_indx=0;i_indx<9;i_indx+=3){
        for(int j_indx=0;j_indx<9;j_indx+=3){
            fill(visCk.begin(),visCk.end(),0);
            if(!ckSudoku(board,visCk,i_indx,j_indx)){
                //cout<<3<<endl;
                return false;
            }
        }
    }
    return true;
    }
};
