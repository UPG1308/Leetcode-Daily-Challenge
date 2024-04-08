class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int n = students.length;
        int sqsandwich = 0, cirsandwich = 0;
        for(int sandwich: students){
            if(sandwich == 0) cirsandwich++;
            else sqsandwich++;
        }
        for(int sandwich: sandwiches){
            if(sandwich == 0){
                if(cirsandwich > 0) cirsandwich--;
                else return sqsandwich;
            }
            else{
                if(sqsandwich > 0) sqsandwich--;
                else return cirsandwich;
            }
        }
        return 0;

    }
}
