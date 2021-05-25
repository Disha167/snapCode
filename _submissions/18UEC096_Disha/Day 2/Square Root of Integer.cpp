//The square root is always greater than 0 and less than the number itself so we can do binary search in the given range checking for each number, and if mid*mid<=num, move to 
//greater half and if lesser, move to smaller half.
int Solution::sqrt(int A) {
    if(A==0)
        return 0;
    long long int l=0,h=A;
    long long int mid,ans;
    while(l<=h)
    {
        mid=l+(h-l)/2;
       
        if(mid*mid<=A)
        {
            ans=mid;
            l=mid+1;
        }
        else
            h=mid-1;
    }
    return ans;
}
