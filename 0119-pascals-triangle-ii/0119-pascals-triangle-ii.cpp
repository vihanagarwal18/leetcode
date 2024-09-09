class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex<=1){
            vector<int> temp(rowIndex+1,1);
            return temp;
        }
        vector<int> result(2,1);
        for(int i=2;i<=rowIndex;i++){
            vector<int> temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j]=result[j-1]+result[j];
            }
            result=temp;
        }
        return result;
    }
};