# rows = int(input("Enter the number of rows:"))
# columns = int(input("Enter the number of columns:"))
#   
# Initialize matrix
# island = []
# print("Enter the entries of Island matrix :")
  
# # For user input
# for i in range(R):          # A for loop for row entries
#     a =[]
#     for j in range(C):      # A for loop for column entries
#          a.append(int(input()))
#     island.append(a)

island= [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

# [
#   ["1","1","1","1","0"],
#   ["1","1","0","1","0"],
#   ["1","1","0","0","0"],
#   ["0","0","0","0","0"]
# ]
columns=5
rows=4
flag=True
counta=0

traversed_rows=[[]]
traversed_rows= [[0 for i in range(columns)] for j in range(rows)]

for i in range(rows):
    for j in range(columns):
        if j+1<columns:
            if traversed_rows[i][j]==0 or traversed_rows[i][j+1]==0:
                if island[i][j+1]==island[i][j] :
                    flag=True
                    traversed_rows[i][j]=1
                    traversed_rows[i][j+1]=1
            else:
                flag=False
        elif i+1<rows: 
            if traversed_rows[i][j]==0 or traversed_rows[i+1][j]==0:
                if island[i+1][j]==island[i][j] :
                    flag=True
                    traversed_rows[i][j]=1
                    traversed_rows[i+1][j]=1
            else:
                flag=False

        # elif j-1>=0 and island[i][j-1]=="1" and traversed_rows[i][j-1]==0:
        #     flag=True
        #     traversed_rows[i][j]=1
        if flag==False:
            counta+=1
            print("Island found ")
print(counta)
        


# print(traversed_rows)