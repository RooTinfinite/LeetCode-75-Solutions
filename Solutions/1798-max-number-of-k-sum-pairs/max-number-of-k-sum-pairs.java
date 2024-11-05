
class Solution {
    public int maxOperations(int[] nums, int k) {
        HashMap<Integer,Integer> hm= new HashMap<>();
		//Initialized The Counter
        int count=0;
        for(int i=0; i<nums.length; i++){
		// Checking if the HashMap Contains the k-nums[i] (desired Integer)
            if(hm.containsKey(k-nums[i]) && hm.get(k-nums[i])>0){
                count +=1;
                hm.put((k-nums[i]),(hm.get(k-nums[i])-1));
            }
			// Otherwise we add the Integer to the HashMap
            else{
                hm.put(nums[i],hm.getOrDefault(nums[i],0)+1);
            }
        }
		// Return the Count
        return count;
	}
}	