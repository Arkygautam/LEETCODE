class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int se = s.top();
                s.pop();
                int f = s.top();
                s.pop();

                if(tokens[i] == "+"){
                    s.push(f+se);
                }
                else if(tokens[i] == "-"){
                    s.push(f-se);
                }
                else if(tokens[i] == "*"){
                    s.push(f*se);
                }
                else{
                    s.push(f/se);
                }
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();

        
    }
};