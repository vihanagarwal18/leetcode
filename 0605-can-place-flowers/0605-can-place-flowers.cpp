class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0) { 
                bool leftcheck=(i==0 || flowerbed[i-1]==0);
                bool rightcheck=(i==flowerbed.size()-1 || flowerbed[i+1]==0);
                if( leftcheck && rightcheck){
                    n--;
                    flowerbed[i]=1;
                }
            }
        }
        if(n<=0) return true;
        return false;
    }
};