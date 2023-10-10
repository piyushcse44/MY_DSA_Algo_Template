//----------------------------- Minimum Spanning Tree Algorithm -----------------------------

    #include<bits/stdc++.h>
    #include<vector>
    using namespace std;
   

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


    int32_t main()
    {
        int node,vertics;
        cin>>node>>vertics;
        vector<pair<int,pair<int,int>>>g;
        for(int i=0;i<vertics;i++)
        {
            int node1,node2,cost;
            cin>>node1>>node2>>cost;
            pair<int,int>p1 ={node1,node2};
            pair<int,pair<int,int>> p2 = {cost,p1};
            g.push_back(p2);
           
        }
        sort(g.begin(),g.end());
        
        for(int i=0;i<node;i++)
            make(i);

        int  Minimum_Cost=0;
        for(int i=0;i<g.size();i++)
        {

           
            if(find(g[i].second.first)!=find(g[i].second.second)){
               
                Union(g[i].second.first,g[i].second.second);
                Minimum_Cost+=g[i].first;
            }
        }
        cout<<Minimum_Cost<<endl;
 
    }

