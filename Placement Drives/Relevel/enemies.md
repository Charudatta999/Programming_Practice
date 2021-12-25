Enemies
Problem Statement

Amy teaches a class of N student numbered from 1 to N.
Friendship value of student numbered i is Fi.
A pair of students numbered i and j (i < j) is said to be “enemy pair” if ·
 j – i is not equal to Fj - Fi Find number of enemy pairs in the class.
 You are given T independent test cases.

Constraints · 1 <= T <= 10 · 1 <= N <= 10^5 · 1 <= Fi <= N All input values are integers.

Input Format ·
 First-line contains T.
 · First line of each test case contains a single integer n.
 · Second line of each test case contains N space separated integers F1, F2, …, FN

Output Format
· Print in a newline for each test case a single integer denoting number of enemy pairs in the class.

Sample Input
1
3
1 3 3

Sample Output 2

Explanation of Sample

Enemy pairs <1, 2> and <2, 3>.
 For i=1, j = 2 we have,
 A1 = 1, A2 = 3 and A2 - A1 = 3 -1 = 2 which is not equal to j - i,
  i.e, 1 here. For i=2, j = 3 we have, A2 = 3, A3 = 3 and A3 - A2 = 3 - 3 = 0 which is not equal
  to j - i, i.e, 1 here.