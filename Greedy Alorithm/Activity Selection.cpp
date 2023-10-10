------------------- Activity Selection -----------------------

(Question Statement):-
	Given N activities with their start and 
	finish day given in array start[ ] and 
	end[ ]. Select the maximum number of 
	activities that can be performed by 
	a single person, assuming that a person
	 can only work on a single activity at 
	 a given day.
	Note : Duration of the activity includes both starting and ending day.

	N = 4
	start[] = {1, 3, 2, 5}
	end[] = {2, 4, 3, 6}
	Output: 
	3
	Explanation:
	A person can perform activities 1, 2
	and 4.

Approch:-
       1) first we just think what task we select for first position.
       2) the task which have least end time must be first one because
          if we select any other task on first then the next task we
          must select whose start time is greater than cur task end time.
          Eg:-
              {start,end}={{10,20},{2,21},{3,15},{16,18}}
              here we have end[]={20,21,15,18}
              if we choose first task having ending 15 then next task 
              starting time lie b/w (16,infinity)
              but if we choose any other ending suppose 21 then
              then next task starting time lie b/w (22,infinity)
              which is greater and we may miss some task which perform
              b/2 (15,21).
        3) repeat the step 2 for reaming data.
        

 Algoritm:
         step 1: just put the data in a vector of pairs where firt is
                 end time and second is start time.
         step 2: just sort the above vector i.e sort w.r.t end time.
         step 3: Declare a variable for storing current_end_time and
                 initlize it with zero.
         step 4: start a loop from 0 to size_of_task and in each itertion
                 cheack if our start time is eligible
                 (if current_end_time<start time) for taking or not
                 if eligible just include it in answer and update current_end_time.


 CODE:-             
		
    #include<bits/stdc++.h>
    #include<vector>
    using namespace std;
   

   

    int32_t main()
    {
        int n;
        cin>>n;
        vector<pair<int,int>>task(n);
        for(int i=0;i<n;i++)
        {
            int cur_start,cur_end;
            cin>>cur_start>>cur_end;
            task[i]={cur_end,cur_start};
        }
        sort(task.begin(),task.end());
        int max_task=0;
        int cur_end_time =0;
        for(int i=0;i<n;i++)
        {
            if(task[i].second <= cur_end_time) continue;
            max_task++;
            cur_end_time = task[i].first;
        }
        cout<<max_task<<endl;
    }



