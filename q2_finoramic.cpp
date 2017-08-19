int Solution::pow(int x, int n, int d) {
    long long temp,mul;

    if(n==1) {
        if(x<0)
        return (x%d)+d;
        return x;
    }
    if(n==0 && x==0)  return 0;
    if(n==0) return 1%d;

    temp = pow(x,n/2,d)%d;
    mul = (temp * temp)%d;

    if(mul<0) mul = mul + d;
    if(n%2==0) return mul;
    return (mul*x)%d;
}