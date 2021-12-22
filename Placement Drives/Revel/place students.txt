Place Students

Problem Statement :

There are N consecutive seats in the classroom. Each seat is either defective or not.

In the classroom, there are X boys and Y girls students present. And you want to place them in such a way that there are no two consecutive (adjacent) seats where two boys or two girls are sitting.

Your task is to find the maximum number of students you can place.

Note: You can't place a student where the seat is defective.



Constraints :

1 <= T <= 10
1 <= N<= 10^5
0 <= X, Y <=10^5



Input Format :



The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, X, and Y.
The second line contains a string with length N, consisting of characters “.” and “#”. The dot means that the corresponding place is not defective. The hash (“#”) means that the corresponding place is defective.


Output Format :



For each test case, print the maximum number of students you can place.


Sample Input :



3
7 1 4
.#....#
11 3 10
.#....#.#..
2 1 4
##




Sample Output :



4
8
0





Explanation of Sample :



Sample case 1: you can put 1 boy and 3 girls in the following way: “G#GBG.#”
Sample case 2: you can put 3 boys and 5 girls in the following way: “G#GBGB#G#BG”
Here B means boy student, G means girl student.