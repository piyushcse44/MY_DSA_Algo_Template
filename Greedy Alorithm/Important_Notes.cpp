((1) In task problem where we are given strt and end time we can 
   sort them according to end time.

2) We can take a set and insert some value in set and use lowerbound and erase.

3) use global approch and try to optimiz proof it .like itrate in  a vector 
   and try to solve any nearest index first.

4) Egyptian Fraction :- a/b = 1/x1 + 1/x2 +...... where b>a;
                      6/14 is 1/3 + 1/11 + 1/231
    (i) 14/6 = 2.333 means 6/14 = 1/2.333 nearest 1/x which is smaller than 1/2.333
       is 1/3.                     
    (ii) now (6/14 - 1/3) = 4/42 reamians then again repeat (i)

(5) we can solve a problem by starting with end also.

(6) we can also fisrt sort a array before using it.

(7) if we have to find multiply of every element in an arry we use
    log(a[0]*a[1]....*a[n-1]) = log(a[0])+log(a[1])+....+log(n-1)

(8) if(a>b) and you have option to add x to either a or b and find maximum
            multily just add to b.

            (a+x)*b = a*b + x*b
                                  <
            (b+x)*a = a*b + x*a   

 (9) Base Case if you want to add two number and store it into starting:
      i. if one number become empty.
      ii. add carry in last.
      iii. remove trail zero like 00066 but ans is 66 only
      iv.  add a zero if string become empty.   


 (10) we find all contineous j which statisfy condn:
       i<j and a[i]<=a[j] for all i
      eg:
                  10,11,12,13,11,9,14
         answer = 4,3,1,0,0,1,0 -> 10 -> 11,12,13,11 not 14 because 9 come first

      for this:-
         use  stack and store pair<element_value,when pushed>
         and when we just pop that element we know how many element
         is greater than or equal to that number.

         for eg:-
            current stack - {10,1},{11,2},{12,3},{13,3}
            now {11,4} is going to push but 11<13 so now
            13 is at its end and we just have to pop it
            so answer for 13 :  current_ind - ind_at_time_of_push
              
    
    
    


    
