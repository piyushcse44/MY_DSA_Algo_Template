------------------------------- Police and Thiev ------------------------------

Problem Statement:-
    Given an array of size n such that each element contains either 
    a 'P' for policeman or a 'T' for thief. Find the maximum number 
    of thieves that can be caught by the police. 
	Keep in mind the following conditions :

	Each policeman can catch only one thief.
	A policeman cannot catch a thief who is more than K units away from him.
	Example 1:

	Input:
	N = 5, K = 1
	arr[] = {P, T, T, P, T}
	Output: 2
	Explanation: Maximum 2 thieves can be 
	caught. First policeman catches first thief 
	and second police man can catch either second 
	or third thief.
	Example 2:

	Input:
	N = 6, K = 2
	arr[] = {T, T, P, P, T, P}
	Output: 3
	Explanation: Maximum 3 thieves can be caught.
	Your Task:  
	You dont need to read input or print anything. 
	Complete the function catchThieves() that 
	takes n, k and arr[ ] as input parameters 
	and returns the maximum number of thieves 
	that can be caught by the police. 

	Expected Time Complexity: O(N)
	Expected Auxiliary Space: O(N)

	Constraints:
	1 ≤ n ≤ 105
	1 ≤ k ≤ 100
	arr[i] = 'P' or 'T'



Intution:-
        1) store all the theif postion in a list in descending order.	
        2) loop throgh the original array and in each index i just pop
           the theif postion which become less then i-k because  no 
           police can caught a theif if the distance b/w them is more
           than k and now every police are present in a distance more
           or equal to i.
        3) if ith index contain a police then just arrest  the last theif
           store in the theif list if the distance of thief is less than
           or equal to i+k because the last thief is actually the thief 
           whose distance is just more than i-k which is most favourable 
           distance for current police i.


CODE:-
     int catchThieves(char arr[], int n, int k) 
    {
        vector<int>pos_thief;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]=='T') pos_thief.push_back(i);
        }
        int ct =0;
        for(int i =0;i<n;i++)
        {
            if(pos_thief.size()==0) break;
            if(pos_thief[pos_thief.size()-1] < i-k)
            {
                pos_thief.pop_back();
            }
            if(arr[i]=='P')
            {
                if(pos_thief[pos_thief.size()-1] <= i+k)
                {
                    ct++;
                    pos_thief.pop_back();
                }
            }
            
            
        }
        return (ct);
        
        
    }