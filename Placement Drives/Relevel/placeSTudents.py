'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
C
Code, Compile, Run and Debug online from anywhere in world.

'''
t = int(input())
for i in range(t):
    n, boys, girls = map(int, input().split())
    list_of_seats = list(input())
    sitting = list_of_seats.copy()

    if boys >= girls and list_of_seats[0] != "#":
        sitting[i] = "b"
        boys -= 1
        prev = "b"
    else:
        sitting[i] = "g"
        girls -= 1
        prev = "g"
    for i in range(1, len(list_of_seats)):

           if boys == 0 and girls == 0:
                break
            if list_of_seats[i] == "#":
                sitting[i] = "#"
            elif prev == "g" or prev == "#" and sitting[i] == ".":
                if boys != 0:
                    sitting[i] = "b"
                    boys -= 1
            elif prev == "b" or prev == "#" and sitting[i] =="." :
                if girls != 0:
                    sitting[i] = "g"
                    girls -= 1
            prev = list_of_seats[i]

    print(sitting)
