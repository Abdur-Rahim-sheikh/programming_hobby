import numpy as np
file_name = 'josephus_problem.txt'
with open(file_name,'w') as f:
        f.write("")
for i in range(1,6):
    for j in range(1,100):
        array = np.arange(0,j)
        k = 0
        while len(array)>1:
            k = (i+k)%len(array)
            array = np.delete(array,k)
            # print(len(array))

        with open(file_name,'a') as f:
            f.write(f"for {i} skip in {j} people survivor is {array}{' <<==' if array[0]==1 else ''}\n")


    with open(file_name,'a') as f:
        f.write('\n\n')