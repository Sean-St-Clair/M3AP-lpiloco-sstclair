import matplotlib.pyplot as plt

file = open("../data/bubbleData.txt", 'r')
ax = plt.subplot(111)
reads = []
writes = []
for line in file:
    line = line.split(" ")
    line[3] = line[3].strip('\n')
    print(line)

file.close()