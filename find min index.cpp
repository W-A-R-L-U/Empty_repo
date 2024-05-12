
// finding the smallest element index
int findpivot(vector<int>& nums,int n)
    {
        int low=0,high=n-1;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high]) // if it is high then it exist in right side
                low=mid+1;
            else // it will in left side
                high=mid;
        }
        return low;
    }


// using checking sorted
int findKRotation(int nums[], int n) {
	    // code here
	    int low=0,high=n-1;
	    int in=n,ans=INT_MAX;
	    while(low<=high)
	    {
	        int mid=low+(high-low)/2;
	        if(nums[low]<=nums[mid])
	        {
	            if(nums[low]<ans)
	            {
	                ans=nums[low];
	                in=low;
	            }
	            low=mid+1;
	        }else{
	            if(nums[mid]<ans)
	            {
	                ans=nums[mid];
	                in=mid;
	            }
	            high=mid-1;
	        }
	    }
	    return in;
	}
