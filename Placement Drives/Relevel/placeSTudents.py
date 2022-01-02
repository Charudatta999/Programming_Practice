t = int(input())
for i in range(t):
    n, boys, girls = map(int, input().split())
    list_of_seats = list(input())
    sitting = list_of_seats.copy()
    count=0
    if boys >= girls and list_of_seats[0] != "#":
        sitting[i] = "b"
        boys -= 1
        prev = "b"
        count+=1
    elif boys<=girls and list_of_seats[0] != "#":
        sitting[i] = "g"
        girls -= 1
        prev = "g"
        count+=1
    for i in range(1, len(list_of_seats)):
        if boys == 0 and girls == 0:
            break
        if list_of_seats[i] == "#":
            prev="#"
            continue
        if i > 1:
            if list_of_seats[i-1]=="#" :
                sitting[i]=sitting[i-2]
                count+=1
                continue
        if sitting[i-1]=="g" or sitting[i-1]=="#" :
            if boys > 0:
                sitting[i]="b"
                boys-=1
                count+=1
        elif sitting[i-1]=="b" or sitting[i-1]=="#" :
            if girls > 0:
                sitting[i]="g"
                girls-=1
                count+=1

    print(count)
