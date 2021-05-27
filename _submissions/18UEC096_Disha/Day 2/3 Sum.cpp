//This can be solved using 2 pointer approach, one element can be fixed at every iteration and then rest of the array can be searched for the remaining pair, 2 pointers are 
//fixed for 2 elements and then everytime we get a lesser difference, our difference is updated. If A[low]+A[high] is greater than target, we decrease high to reduce our sum
//and if it is lesser, then we increase low pointer to increase our sum.
int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    long long int ans=1000000000,diff=1000000000; 
    for(int i=0;i<A.size()-2;i++)
    {
        long long int target=B-A[i];
        long long int low=i+1,high=A.size()-1; 
        while(low<high)
        {
            int mid=low+ (high-low)/2;
            if(abs(diff)>abs(target-(A[low]+A[high])))
            {
                ans=A[low]+A[high]+A[i];     
                diff=abs(target-(A[low]+A[high]));
            }
            if(A[low]+A[high]==target)
            {
               ans=A[low]+A[high]+A[i];
                break;
            }
            else if(A[low]+A[high]<target)
                low++;
            else if(A[low]+A[high]>target)
                high--;
        } 
    }
    return ans;
}
