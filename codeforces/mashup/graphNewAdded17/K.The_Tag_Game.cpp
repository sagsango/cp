#Bfs

#The Explaination Given By hrushikesht Is Much Better And Simple than The one given in the editorial , it took me some time to come upto this logic
Thanks to rajat1603_ and _Reborn_ .
All We Have To Do Is Create 2 Distance Arrays
_- 1. Distance1[i]: distance of ith node from alice
_- 2. Distance2[i]: distance of the ith node from bob
Both of this can be done by DFS And just One Function

After Which All We Need is To Check if Distance1[i] > Distance2[i]
(**distance of ith node from alice > distance of ith node from bob**)
If So Ans=max(Ans,2*distance1[i])
This is Because We Can See That
The Total Number Of Moves Is always equal to the number of moves by alice * 2

Here is My Code : 27611356

PS : It Is only my second comment ever on a codeforces post , sorry if i am not able to clear your doubts :)




#And I was going to use LCA 
   To check evry leaf is reachable by Bob or not to update result.

