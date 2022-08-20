# This below equation can rotate 90_degree clockwise any n*n matrix

```
#define vvi vector<vector<int>>
class Solution {
int row[8]={0,1,0,-1};
int col[8]={1,0,-1,0};
private:
    void rotate(vvi &array,int start,int len){
//         len -1 will work fine as 0 indexed and rotation = len-1
        len --;
        int rowA[4] = {0,0,len,len};
        int colA[4] = {0,len,len,0};
        // printf("start: %d\n",start);
        for(int i=0;i<len;i++){
//             first rotate
            
            int lastVal=array[start+rowA[3]][start+colA[3]];
            for(int j=3;j>0;j--){
                int x1=start+rowA[j],y1=start+colA[j];
                int x2 = start+rowA[j-1],y2 = start+colA[j-1];
                // printf("x1: %d, y1: %d\nx2: %d, y2: %d\n\n",x1,y1,x2,y2);
                array[x1][y1] = array[x2][y2];
            }
            array[start+rowA[0]][start+colA[0]] = lastVal;
//             update the rotation
            for(int j=0;j<4;j++){
                rowA[j]+=row[j];
                colA[j]+=col[j];
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int half_corner = matrix.size()/2;
        for(int i=0;i<half_corner;i++){
            rotate(matrix,i,matrix.size()-i*2);
        }
        // for(auto vals: matrix){
        //     for(auto val: vals) cout<<val<<' ';
        //     cout<<endl;
        // }
    }
};
```