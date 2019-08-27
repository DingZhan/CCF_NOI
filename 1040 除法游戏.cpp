#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(long long n)
{
    if(n==1)
        return false;
    else if(n==2)
        return true;
    if(n%2==0)
        return false;
    long long t = sqrt(n), i;
    for(i=3; i<=t; i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

long long gcd(long long a, long long b)
{
    long long c = a%b;
    while(c)
    {
        a = b;
        b = c;
        c = a%b;
    }
    return b;
}

int main()
{
    long long a, b, c, t, i;
    bool bSucc=true;
    cin>>a>>b;

    c = gcd(a, b);
//    a = a/c;
    b = b/c;

    t = sqrt(b);

	if(b%2==0 && a%2!=0)
	{
		bSucc=false;
	}
	else if(b==1)
    {
        bSucc=true;
    }
	else
	{
		for(i=3; i<=t; i+=2)
		{
			if((b%i==0) && (a%i!=0) && IsPrime(i))
			{
				bSucc=false;
				break;
			}
		}
		if(bSucc && IsPrime(b) && (a%b!=0))
			bSucc=false;
	}
    if(bSucc)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}
