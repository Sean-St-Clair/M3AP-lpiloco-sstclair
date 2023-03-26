import matplotlib.pyplot as plt

file = open("../data/bubbleData.txt", 'r')
reads = []
writes = []
for line in file:
    line = line.split(" ")
    line[2] = line[2].strip('\n')
    if line[1] == 'reads':
        reads.append(int(line[2]))
    else:
        writes.append(int(line[2]))

file.close()

ax = plt.subplot(111)
sizes = range(85, 1001, 100)
reads.reverse()
ax.bar(sizes, reads, width=30, color='r', align='center')

plt.title('BubbleSort Reads and Writes (by vector size)')
plt.xlabel('Vector Size')
plt.ylabel('Number of Operations')
ax.legend()
plt.show()