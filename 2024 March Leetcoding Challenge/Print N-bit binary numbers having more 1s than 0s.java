class Solution {
     ArrayList<String> NBitBinary(int N) {
        // code here
        ArrayList<String> result = new ArrayList<>();
            validateAndAdd(1,"1",result,1,N);
            return result;
    }
    
    void validateAndAdd(int diff,String s, ArrayList<String> result,int length,int N){
        if(length==N){
            if(diff>=0){
                 result.add(s);
            }
               return;
        }
        
        validateAndAdd(diff+1,s+"1",result,length+1,N);
        if(diff-1>=0){
             validateAndAdd(diff-1,s+"0",result,length+1,N);
        }
    
    }
}
