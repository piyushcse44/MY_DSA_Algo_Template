------------------- Sorting array with reverse around middle ------------------------
Problem Statement:-
    Consider the given array arr[], we need to find if we can sort
    array with the given operation. The operation is :-
 1. We have to select a subarray from the given array
	such that the middle element(or elements (in case of even 
	number of elements)) of subarray is also the middle
	element(or elements (in case of even number of elements)) of 
	the given array. 
 2.	Then we have to reverse the selected subarray and 
	place this reversed subarray in the array. 
	We can do the above operation as many times as we want.
	The task is to find if we can sort array with the given operation. 

TestCase:-
	Input : arr[] = {1, 6, 3, 4, 5, 2, 7}
	Output : Yes
	We can choose sub-array[3, 4, 5] on 
	reversing this we get [1, 6, 5, 4, 3, 2, 7]
	again on selecting [6, 5, 4, 3, 2] and 
	reversing this one we get [1, 2, 3, 4, 5, 6, 7] 
	which is sorted at last thus it is possible
	to sort on multiple reverse operation.

	Input : arr[] = {1, 6, 3, 4, 5, 7, 2}
	Output : No


Approch:-
   1. if we can only select that subarry whose middle is same as 
      original array then reversing that subarry means placing
      ith element to (n-1-i)th element.
   2. now if we want to sort it then it is only possible if
      ith element is equal to (ith or (n-1-i)th element if array
      is sorted).
   3. So first create a copy and sort it and check wheter every 
      ith element is equal to either (n-1-i)th or (ith) of sorted
      array or not.


CODE:
    #include<bits/stdc++.h>
	using namespace std;

	int main()
	{
		int n;
		cin>>n;
		vector<int>a(n),b(n);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b.begin(),b.end());
		bool flag = true;
		for(int i=0;i<n;i++)
		{
			if(a[i]!= b[i] && a[i] != b[n-1-i])
			{
				flag = false;
				break;
			}
		}
		if(flag) 
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

		return 0;

	}

