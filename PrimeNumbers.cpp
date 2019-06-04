#include <bits/stdc++.h>
using namespace std;
 
#define vi vector<int>
#define vlli vector<long long int>
#define pb push_back
#define ll long long
void seive(ll limit, vlli &prime)
{
	bool m[limit+1];
	memset(m,true,sizeof(m));
	
	for(ll i=2;i*i<=limit;++i)
	{
		if(m[i]==true)
		{
			for(ll j=i*i;j<=limit;j+=i)
				m[j]=false;
		}
	}
	
	for(ll i=2;i<=limit;++i)
	{
		if(m[i]==true)
			prime.pb(i);
	}
}
 
void segmentedseive(ll n)
{
	int limit = floor(sqrt(n));
	vlli prime;
	prime.reserve(limit);
	seive(limit,prime);
	
	ll low=limit;
	ll high=2*limit;
	
	ll con=0;
	for(long long i=0;i<prime.size();++i)
  	{
  		++con;
  		if(con%100==1)
  			printf("%lld\n", prime[i]);
  	}
		
	while(low<n)
	{
		if(high>n)
			high=n;
		
		bool m[limit+1];
		memset(m,true,sizeof(m));
		
		for(long long i=0;i<prime.size();++i)
		{
			long long lidx=floor(low/prime[i]) * prime[i];
			if(lidx<low)
				lidx+=prime[i];
			
			for(long long j=lidx;j<high;j+=prime[i])
				m[j-low]=false;
		}
		
		for(long long i=low;i<high;++i)
		{
			if(m[i-low]==true)
			{	
				++con;
				if(con%100==1)
					printf("%lld\n",i);
			}
		}
		low+=limit;
		high+=limit;
	}
}
 
int main() {
	segmentedseive(100000000);
	return 0;
} 
