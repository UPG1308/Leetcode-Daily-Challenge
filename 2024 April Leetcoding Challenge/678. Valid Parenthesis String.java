class Solution {
    public boolean checkValidString(String s) {
        int n = s.length();
        Stack<Integer> open = new Stack<>();
        Stack<Integer> asterik = new Stack<>();
        int i = 0;
        while(i < n){
            char c = s.charAt(i);
            if(c == '(') open.push(i);
            else if(c == '*') asterik.push(i);
            else{
                if(!open.isEmpty()) open.pop();
                else{
                    if(!asterik.isEmpty()) asterik.pop();
                    else return false;
                }
            }
            i++;
        }
        if(open.size() > asterik.size()) return false;
        while(!open.isEmpty() && !asterik.isEmpty()){
            int openInd = open.pop();
            int asterikInd = asterik.pop();
            if(openInd > asterikInd) return false;
        }
        return true;
    }
}
