"""
Color minion

Problem Statement

Gru, the criminal mastermind, wants to perform a heist at the Deshute Bank.
For the task, he hired N minions.
But these many minions were not sufficient and he required more minions for the job.

The N minions are arranged in a line and each minion has some color Ci.

To form more minions for the job Gru will magically duplicate all these minions one by one except those minions which are colored ‘1’.

Like if the minions were of colors : [2,1,3,1,4].
He will duplicate all the minions except the 2nd and the 4th minion as they are colored with the color ‘1’.
So the new set of minions will be [2,3,4] and the final army will be [2,1,3,1,4,2,3,4].

Given the final army, you have to tell a possible initial army.
If there are many possible initial armies you have to print the one which is lexicographically minimum.
 If there is no possible initial army print “-1”.

An army X is lexicographically smaller than army Y, if the first index i in which army X and Y differ, Ai< Bi must hold.

Input Format

•  First-line contains a single integer L, denoting the length of the final army.
•  The next line contains L space-separated integers denoting the colors of the minions.

Output Format
•  Print a possible initial army.
 If there are many possible initial armies you have to print the one which is lexicographically minimum.
 If there is no possible initial army print “-1”.

Constraints
•  1<=L<=10^5
•  1<=Color of minions<=10^5

Sample Input
12
1 2 1 2 1 3 1 3 2 2 3 3

Sample Output
1 2 1 2 1 3 1 3

Explanation of Sample

If Initial set = [1 2 1 2 1 3 1 3]
New minions added are : [2 2 3 3]

Thus the final set becomes : [1 2 1 2 1 3 1 3 2 2 3 3]
It can be proved that this is lexicographically minimum among all possible initial armies.
"""
n = int(input())
final_arr = list(map(int, input().split()))
intialLen=0
checked_elements=[]
index_of_last_1=0
count_of_checked_elemnts={}

for i in range(n):
    if final_arr[i]==1:
        index_of_last_1=i
    elif final_arr[i] not  in checked_elements:
        checked_elements.append(final_arr[i])
for i in checked_elements:
    count_of_checked_elemnts.update({i:final_arr.count(i)})


def checking(checked_elements,final_arr,index_of_last_1,n):
    flag=0
    for i in checked_elements:
        if count_of_checked_elemnts[i]== final_arr[index_of_last_1:n-1].count(i):
            flag=1
            break
    return index_of_last_1
index=checking(checked_elements,final_arr,index_of_last_1,n)
print(final_arr[0:index])