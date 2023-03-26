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
readSizes = range(85, 1001, 100)
writeSizes = range(115, 1051, 100)
reads.reverse()
writes.reverse()
ax.bar(readSizes, reads, width=30, color='r', align='center')
ax.bar(writeSizes, writes, width=30, color='b', align='center')

plt.title('BubbleSort Reads and Writes (by vector size)')
plt.xlabel('Vector Size')
plt.ylabel('Number of Operations')
plt.legend(['Reads', 'Writes'])
plt.show()