/*算是比较经典的题了。模拟入栈，看出栈的栈顶判定是否出值。*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int cnt = 0;
        for(int i=0;i<pushed.size();i++) {
            st.push(pushed[i]);

            while(st.size()&&cnt<popped.size()&&popped[cnt]==st.top()) {
                st.pop();
                cnt++;
            }
        }

        return st.size()==0;
    }
};