class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push(i);
            }
            else{
                while(st.empty()==false && abs(asteroids[i])>0){
                    int x=st.top(); //index
                    if(asteroids[x]>abs(asteroids[i])){
                        //+ve wala jeet gya
                        asteroids[i]=0;
                    }
                    else if(asteroids[x]<abs(asteroids[i])){
                        //-ve wala jeet gya
                        asteroids[x]=0;
                        st.pop();
                    }
                    else{
                        asteroids[x]=0;
                        asteroids[i]=0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(asteroids[i]!=0){
                res.push_back(asteroids[i]);
            }
        }
        return res;
    }
};