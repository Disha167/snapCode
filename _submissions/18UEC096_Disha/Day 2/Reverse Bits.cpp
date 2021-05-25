//O(32) solution can be used simply i.e. every time storing the last bit of given number A in a variable and updating the last bit of answer B and then right shifting A & left
//shifting B on every iteration. 
unsigned int Solution::reverse(unsigned int A) {
    unsigned long long int B=0;
    for(int i=0;i<32;i++)
    {
        int last_bit=A&1;
        A=A>>1;
        B=B<<1;//just the right shifting should occur before oring with last bit as if it will occur afterwards then the number would not be desired, it would shift 1 bit
      //extra after making the last bit .Eg.100 instead of 110 
        B=B|last_bit;
        
    }
    return B;
}
