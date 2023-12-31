
  #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define int long long
    #define loop(o,n) for(int i=o;i<n;i++)
    #define sort(a) sort(a.begin(),a.end())
    #define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define print(a) for(auto &i : a)  
  
    #define lower_bound(v,x) lower_bound(v.begin(),v.end(),x)
    #define upper_bound(v,x) upper_bound(v.begin(),v.end(),x)
    #define pb push_back
    const int dx[] = { 0, 1, 0, -1 } ; 
    const int dy[] = { 1, 0, -1, 0 } ; 


    const int N = 1e5+10;
    int par[N];
    int sz[N];
    void make(int v)
    {
         par[v]=v;
         sz[v]=1;
    }
    int find(int v)
    {
         if(v==par[v]) return v;
         return(par[v]=find(par[v]));
    }
    void Union(int a,int b)
    {
      a=find(a);
      b=find(b);
      if(a!=b)
      {
        if(sz[a]<sz[b])
            swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
      }
    }

    
 

    // if probabilty of success is p then expeceted no. of operation is 1/p
 
    
  /*
      cout <<fixed;
         cout<<setprecision(9)<<double_variable_name<<endl;

           memset(dp,-1,sizeof(dp));

         */

     /* string s;
        if(j==0)
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
      getline(cin,s);*/


----------------*******  prime sieve *******--------------

    const int N = 1e5+10;

      vector<int>prime_factor[N];

    vector<int>prime,f_prime(N,0),l_prime(N,0);
    
    vector<int>A(N,1);
    void generate_p()
    {
        
         loop(2,N+1)
         {
     
            if(A[i])
            {
        
                prime.push_back(i);
                
                l_prime[i]=i;
                f_prime[i]=i;
                prime_factor[i].push_back(i);
                int x=2*i;
                while(x<N)
                {
             prime_factor[x].push_back(i);
     
                    if(f_prime[x]==0)
                        f_prime[x]=i;
                    l_prime[x]=i;
                      
                    A[x]=0;
                   x+=i;
                
                }
               
     
            }
         }
     
         
    } 

   --------------------------------********NCR************--------------------------- 
   
       int power(int x, int y, int p)
{
  int res = 1; 

  x = x % p; 

  while (y > 0) {

   
    if (y & 1)
      res = (res * x) % p;

   
    y = y >> 1; 
    x = (x * x) % p;
  }
  return res;
}


int modInverse(int n, int p)
{
  return power(n, p - 2, p);
}


int mul(int x,
          int y, int p)
{
  return x * 1ull * y % p;
}


int divide(int x,
            int y, int p)
{
  return mul(x, modInverse(y, p), p);
}


int ncr(int n,
                int r, int p)
{
  
  if (n < r)
    return 0;
 
  if (r == 0)
    return 1;
  
  if (n - r < r)
    return ncr(n, n - r, p);

 
 
  int res = 1;
  
  for (int i = r; i >= 1; i--)
    res = divide(mul(res, n - i + 1, p), i, p);
  return res;
}


  
                                     

   ********************************----------*************************************************
    
    
    

     int _log2(ll n)
    {
        int ans=0;
        while(n/2)
        {
            n/=2;
            ans++;
        }
        return(ans);
    }

    int count(ll x)
    {
        int ans =0;
        while(x)
        {
            ans++;
            x/=10;
        }
        return(x);
    }
 
    bool is_prime(ll n)
    {
        if(n==1)
            return(false);
        if(n==2||n==3)
            return(true);
        if(n%2==0||n%3==0)
            return(false);
        for(int i=5;i*i<=n;i+=6)
            if(n%i==0||n%(i+2)==0)
                return(false);
            return(true);
    }
    

     
    void s_rec(vector<int>&a,int x,int ans)
    {
        if(!a.size())
           cout<<ans<<endl;
       else{
        if(a[a.size()-1]==x)
            ans=a.size()-1;
        a.pop_back();
            s_rec(a,x,ans);
        }
    }
  
      
    *******************-------   frequency of bits in range x to y   --------**************

            
     void fn(int x,int y,vector<int>&a,int sum)
     {
         loop(x,y)
         {
            for(int j=(i);j>=0;j--)
            {

                if(j==i){
                    if(sum==1)
                    a[j]+=(1LL<<(i));
                else
                    a[j]-=(1LL<<(i));
                }
                else {
                    if(sum==1)
                    a[j]+=(1LL<<(i-1));
                else
                    a[j]-=(1LL<<(i-1));
                }
            }
         }
     }
    void difference(int dif,vector<int>&a,int x,int sum)
    {
         while(dif)
          {
             if(dif==1)
             {
                if(sum==0)
                a[x]--;
               else
                a[x]++;
                break;
             }
             if(sum==0)
             a[x]-=dif;
         else
            a[x]+=dif;
             dif--;
             x=log2(dif);
             fn(0,x,a,sum);
             dif=(dif-(1<<x)+1);

          }
    }
     void freq_bits(int l,int r,vector<int>&a)
     {
          int x=log2(l);
          int y=log2(r);    
           fn(x,y,a,1);
           int dif=(l-(1<<(x)));
            difference(dif,a,x,0);
           dif=(r-(1<<y)+1);
           difference(dif,a,y,1);

     
 }
   


****************************************-------------------*******************************



 Number of non-negative integral solutions of equation x1 + x2 + …… + xn = k is given by
     (n+k-1)! / (n-1)!*k!. 
Number of positive integral solutions of equation x1 + x2 +  + xn = k is given by
 (k-1)! / (n-1)! * (k-n)!. 


 *********************-------------------mergesort--------------****************************



    vector<int> merge(vector<int>&a,vector<int>&b)
    {
         int n = a.size();
         int m = b.size();
         int i=0,j=0;
         vector<int>rt;
         while(i<n&&j<m)
         {
             if(a[i]>b[j])
             {
                 rt.pb(b[j]);
                 j++;
                 
             }
             else
             {
                rt.pb(a[i]);
               
                i++;
             }
         }
         while(i<n)
         {
            rt.pb(a[i]);
            
            i++;
         }
         while(j<m)
         {
            rt.pb(b[j]);
            j++;
         }
         return(rt);
    }

   vector<int> mergesort(vector<int>&a,int i,int n)
   {
      vector<int>rt;

       if(n-i==1)
        {
           rt.pb(a[i]);
          
           return(rt);
        }

        vector<int>b,c;
        b = mergesort(a,i,(n+i)/2);
        c = mergesort(a,(n+i)/2,n);
        rt = merge(b,c);
        
        
        return(rt);

   }


   ----------------------****************n/1+n/2+.......+n/n******************************
   ll ans =0;
         ll val=0;
         for(int i=1;i<=n;i++){
            if(n/i==n/(i+1)) {
               val = n/i;
               break;
            }
           ans +=n/i;
         }
 
         for(int i=1;i<=val;i++)
         {
              ans +=((n/i)-(n/(i+1)))*1LL*i;
         }


   --------***********************************************************************--------

  

   IMPORTANT   int32_t


   -------************************************************-------------------------------


   
    int cahnge(string &s)
   {
     int ans =0;
      for(int i=0;i<s.size();i++)
        ans = ans*10+(s[i]-'0');
    return(ans);

   }
   int32_t main(){
    vector<int>ans;
    string st;
    while(cin>>st)
    {
       ans.pb(cahnge(st));
    }
    int n = ans.size();
    return 0;
}









