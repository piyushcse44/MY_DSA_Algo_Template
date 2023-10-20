#include<bits/stdc++.h>
#define loop(o,n) for(int i=o;i<n;i++)
using namespace std;
bool is_prime(long long n)
{
    if(n==1) return false;
	for(int i =2;i*1LL*i<=n;i++)
	{
		if(n%i ==0) return false;
	}
	return true;
}




int main()
{
	int n=0;
	

	vector<int>a;
   
   string s;
  while(cin>>s)
  {
    
     a.push_back(stoi(s));
    n++;
  }

	sort(a.begin(),a.end());

	if(n==1)
	{
		printf("%d",a[0]);
		return 0;
	}
	
	

	long long hcf = a[1],gcd=a[0];

	for(int i=2;i<n;i++){

		gcd = __gcd(hcf,a[i]*1LL);
		hcf*=a[i];
		hcf/=gcd;
	}
    
	

	cout<<hcf<<endl;
	if(__gcd(hcf,1LL*a[0]) !=1)
	{
		printf("None");
		return 0;
	}
    long long lmt = 1e10;
	for(int i=0;true;i++)
	{
		if((hcf*i+a[i])>=lmt){
			printf("None");
		    return 0;
		}
		if(is_prime(hcf*i+a[0]))
		{
			printf("%lld",(hcf*i+a[0]));
			break;
		}
	}


	return 0;

}