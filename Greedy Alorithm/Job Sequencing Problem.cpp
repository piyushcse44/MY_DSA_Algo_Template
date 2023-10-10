----------------------- Job Sequencing Problem -----------------------
Problem Statement :
        Given a set of N jobs where each jobi has a deadline and profit associated with it.
		Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
		We earn the profit associated with job if and only if the job is completed by its deadline.
		Find the number of jobs done and the maximum profit.
		Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

Test Case:-
        N = 5
		Jobs = {(1,2,100),(2,1,19),(3,2,27),
		        (4,1,25),(5,1,15)}
		Output:
		2 127
		Explanation:
		2 jobs can be done with
		maximum profit of 127 (100+27).


Approch :-
        1) First Find out max value of deadline.
        2) decalre a set and insert all value form
           1 to max;
        3) sort jobs w.r.t profit in descending order.
        4) we must execute the task with maximum profit
           but in a time which is nearer to its deadline
           i.e (equal or just smaller than deadline) and
           we can find that value with the help of upper
           bound in set and just erase that element.

code:
         
    #include<bits/stdc++.h>
    #include<vector>
    using namespace std;
   

    bool fn(pair<int,int> &a,pair<int,int> &b)
    {
        return a.first>b.first;
    }


    int32_t main()
    {
        int n;
        cin>>n;
        vector<pair<int,int>>job_details(n);
        int Max_Time =0;
        for(int i=0;i<n;i++)
        {
            int job_id,job_deadline,job_profit;
            cin>>job_id>>job_deadline>>job_profit;
            job_details[i]={job_profit,job_deadline};
            Max_Time = max(Max_Time,job_details[i].second);
            
        }
        
        sort(job_details.begin(),job_details.end(),fn);
    
        set<int>Rem_Time;
        for(int i=1;i<=Max_Time;i++)
        {
            Rem_Time.insert(i);
        }
        
        int num_task=0,Max_Profit=0;
        for(int i=0;i<n;i++)
        {
            if(Rem_Time.size()== 0) break;
            auto it = Rem_Time.upper_bound(job_details[i].second);
            if(it == Rem_Time.begin()) continue;
            it--;
            num_task++;
            Max_Profit += job_details[i].first;
            Rem_Time.erase(it);
        }
        cout<<num_task<<" "<<Max_Profit<<endl;
        
    }              

