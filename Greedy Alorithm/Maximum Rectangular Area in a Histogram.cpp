---------------------- Maximum Rectangular Area in a Histogram ---------------------
Problem Statement:-
	Find the largest rectangular area possible in a given
	histogram where the largest rectangle can be made of a
	number of contiguous bars. For simplicity, assume that
	all bars have the same width and the width is 1 unit,
	there will be N bars height of each bar will be given
	by the array arr.

	Example 1:

	Input:
	N = 7
	arr[] = {6,2,5,4,5,1,6}
	Output: 12
	Explanation: In this example the largest area would be
	12 of height 4 and width 3. We can achieve this 
	area by choosing 3rd, 4th and 5th bars.


	Example 2:

	Input:
	N = 8
	arr[] = {7 2 8 9 1 3 6 5}
	Output: 16
	Explanation: Maximum size of the histogram 
	will be 8  and there will be 2 consecutive 
	histogram. And hence the area of the 
	histogram will be 8x2 = 16.
	Your Task:
	The task is to complete the function getMaxArea()
	which takes the array arr[] and its size N as 
	inputs and finds the largest rectangular area 
	possible and returns the answer.

	Expected Time Complxity : O(N)
	Expected Auxilliary Space : O(N)

	Constraints:
	1 ≤ N ≤ 10^6
	0 ≤ arr[i] ≤ 10^12


Approch :-
    1. For each i we have to find j and k where
       j<=i and a[j]>=a[i] && a[j+1]>=a[i] .... && a[i-1]>=a[i]
       and for k
       k>=i and a[k]>=a[i] && a[k-1]>=a[i].... &&a[i+1]>=a[i].

    2. use  stack and store pair<element_value,when pushed>
         and when we just pop that element we know how many element
         is greater than or equal to that number.

         for eg:-
            current stack - {10,1},{11,2},{12,3},{13,3}
            now {11,4} is going to push but 11<13 so now
            13 is at its end and we just have to pop it
            so answer for 13 :  current_ind - ind_at_time_of_push is 
            all k and for all j we just ** look previous element of
            stack if stack has only one element then we take 0.

CODE:-
      long long getMaxArea(long long arr[], int n)
    {
        long long mx =0;
        vector<pair<long long,long long>>a;
        for(int i=0;i<n;)
        {
           if(a.size()==0 || a[a.size()-1].first<=arr[i])
           {
               a.push_back({arr[i],i});
               i++;
           }
           else
           {
               long long pre = -1;
               if(a.size()>1) pre = a[a.size()-2].second;
               pre++;
               long long cur = i-1;
               long long w = cur-pre+1;
               
               mx = max(mx,a[a.size()-1].first*w);
               a.pop_back();
              
           }
            
        }
        while(a.size())
        {
             long long pre = -1;
               if(a.size()>1) pre = a[a.size()-2].second;
               pre++;
               long long cur = n-1;
               long long w = cur-pre+1;
               
            mx = max(mx,a[a.size()-1].first*1LL*w);
               a.pop_back();
        }
        return mx;
        }            


          

