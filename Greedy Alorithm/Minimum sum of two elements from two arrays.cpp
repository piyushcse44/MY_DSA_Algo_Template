-------------- Minimum sum of two elements from two arrays ------------------
Problem Statement :-
	 Given two arrays a[] and b[] of same size.Your task is 
	 to find minimum sum of two elements such that they 
	 belong to different arrays and are not at same 
	 index in their arrays.


	Example 1:

	Input : 
	a[] = {5, 4, 13, 2, 1}
	b[] = {2, 3, 4, 6, 5}
	Output : 
	3
	Explanation :
	We take 1 from a[] and 2 from b[]
	Sum is 1 + 2 = 3.
	 
	Example 2:
	Input : 
	a[] = {5, 4, 13, 1}
	b[] = {3, 2, 6, 1}
	Output : 
	3
	Explanation :
	We take 1 from a[] and 2 from b[].
	Note that we can't take 1 from b[]
	as the elements can not be at same
	index. 
	 


	 

	Expected Time Complexity: O(N)
	Expected Auxiliary Space: O(1)


	Constraints:
	1<=N<=105
	1<=a[i]<=105
	1<=b[i]<=105


Approch :-
         1) we just have to find the minimum value index in a and b.
            case 1:
                if(ind_a != ind_b ) or (number of minimum index in any array is more tan 1)
                	then ans = sum of both.
            case 2: 
                 here (ind_a == ind_b) and the ct of both smallest element is 1.
                 now 
                    the ans = minimum of ( (a[ind_a] + value of second smallest in b)
                                            (b[ind_b]+ value of second smallest in a)).


CODE:-
      void smallest(int *b,int n,int &ind,int &ct,int &sc_mn)
    {
        
         int mn =b[0];ct =1,ind =0;
        for(int i=1;i<n;i++)
        {
            if(b[i]==mn) ct++;
            else if(b[i]<mn)
            {
                ct=1;
                ind =i;
                mn = b[i];
            }
        }
        sc_mn = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(b[i]!=mn && b[i]<sc_mn)
            sc_mn = b[i];
        }
        
    }
    int minSum(int a[], int b[], int n) 
    {
       
       int ind_b,ct_b,sc_b;
       smallest(b,n,ind_b,ct_b,sc_b);
       int ind_a,ct_a,sc_a;
       smallest(a,n,ind_a,ct_a,sc_a);
   
       
       if((ct_a >1 || ct_b > 1) || (ind_a != ind_b))
       {
           return (a[ind_a]+b[ind_b]);
       }
       
       int ans = min(a[ind_a]+sc_b , b[ind_b]+sc_a);
       return ans;
       
       
       
    } 


    Time Complexity :- O(N)
    Space Complexity :- O(1)
