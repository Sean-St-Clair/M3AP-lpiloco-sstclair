import matplotlib.pyplot as plt

# Bubble sort graph
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
xAxisTicks = range(100, 1001, 100)
readSizes = range(80, 1001, 100)
writeSizes = range(100, 1021, 100)
overallSizes = range(120, 1041, 100)
reads.reverse()
writes.reverse()
overall = []
for i in range(0, len(reads)):
    overall.append(reads[i] + writes[i])

ax.bar(readSizes, reads, width=20, color='b', align='center')
ax.bar(writeSizes, writes, width=20, color='r', align='center')
ax.bar(overallSizes, overall, width=20, color='y', align='center')

plt.title('Bubble Sort Reads and Writes')
plt.xlabel('Vector Size')
plt.xticks(xAxisTicks)
plt.ylabel('Number of Operations (in Millions)')
plt.legend(['Reads', 'Writes', 'Overall'])
plt.savefig('../images/Bubble_Graph.png')
plt.cla()

# Selection sort graph
file = open("../data/selectionData.txt", 'r')
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
xAxisTicks = range(100, 1001, 100)
readSizes = range(80, 1001, 100)
writeSizes = range(100, 1021, 100)
overallSizes = range(120, 1041, 100)
reads.reverse()
writes.reverse()
overall = []
for i in range(0, len(reads)):
    overall.append(reads[i] + writes[i])

ax.bar(readSizes, reads, width=20, color='b', align='center')
ax.bar(writeSizes, writes, width=20, color='r', align='center')
ax.bar(overallSizes, overall, width=20, color='y', align='center')

plt.title('Selection Sort Reads and Writes')
plt.xlabel('Vector Size')
plt.xticks(xAxisTicks)
plt.ylabel('Number of Operations (in Millions)')
plt.legend(['Reads', 'Writes', 'Overall'])
plt.savefig('../images/Selection_Graph.png')
plt.cla()

# Unstable Quick sort graph
file = open("../data/quickData.txt", 'r')
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
xAxisTicks = range(100, 1001, 100)
readSizes = range(80, 1001, 100)
writeSizes = range(100, 1021, 100)
overallSizes = range(120, 1041, 100)
reads.reverse()
writes.reverse()
overall = []
for i in range(0, len(reads)):
    overall.append(reads[i] + writes[i])

ax.bar(readSizes, reads, width=20, color='b', align='center')
ax.bar(writeSizes, writes, width=20, color='r', align='center')
ax.bar(overallSizes, overall, width=20, color='y', align='center')

plt.title('Unstable Quick Sort Reads and Writes')
plt.xlabel('Vector Size')
plt.xticks(xAxisTicks)
plt.ylabel('Number of Operations')
plt.legend(['Reads', 'Writes', 'Overall'])
plt.savefig('../images/Unstable_Quick_Graph.png')
plt.cla()

# Heap sort graph
file = open("../data/heapData.txt", 'r')
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
xAxisTicks = range(100, 1001, 100)
readSizes = range(80, 1001, 100)
writeSizes = range(100, 1021, 100)
overallSizes = range(120, 1041, 100)
reads.reverse()
writes.reverse()
overall = []
for i in range(0, len(reads)):
    overall.append(reads[i] + writes[i])

ax.bar(readSizes, reads, width=20, color='b', align='center')
ax.bar(writeSizes, writes, width=20, color='r', align='center')
ax.bar(overallSizes, overall, width=20, color='y', align='center')

plt.title('Heap Sort Reads and Writes')
plt.xlabel('Vector Size')
plt.xticks(xAxisTicks)
plt.ylabel('Number of Operations (in Millions)')
plt.legend(['Reads', 'Writes', 'Overall'])
plt.savefig('../images/Heap_Graph.png')
plt.cla()

# Stable Quick sort graph (two-sort part 1)
file = open("../data/firstTwoSortData.txt", 'r')
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
xAxisTicks = range(100, 1001, 100)
readSizes = range(80, 1001, 100)
writeSizes = range(100, 1021, 100)
overallSizes = range(120, 1041, 100)
reads.reverse()
writes.reverse()
overall = []
for i in range(0, len(reads)):
    overall.append(reads[i] + writes[i])

ax.bar(readSizes, reads, width=20, color='b', align='center')
ax.bar(writeSizes, writes, width=20, color='r', align='center')
ax.bar(overallSizes, overall, width=20, color='y', align='center')

plt.title('Two Sort with first field: Stable Quick Sort Reads and Writes')
plt.xlabel('Vector Size')
plt.xticks(xAxisTicks)
plt.ylabel('Number of Operations')
plt.legend(['Reads', 'Writes', 'Overall'])
plt.savefig('../images/Stable_Quick_Graph.png')
plt.cla()

# Stable Quick sort graph (two-sort part 1)
file = open("../data/secondTwoSortData.txt", 'r')
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
xAxisTicks = range(100, 1001, 100)
readSizes = range(80, 1001, 100)
writeSizes = range(100, 1021, 100)
overallSizes = range(120, 1041, 100)
reads.reverse()
writes.reverse()
overall = []
for i in range(0, len(reads)):
    overall.append(reads[i] + writes[i])

ax.bar(readSizes, reads, width=20, color='b', align='center')
ax.bar(writeSizes, writes, width=20, color='r', align='center')
ax.bar(overallSizes, overall, width=20, color='y', align='center')

plt.title('Two Sort with second field: Stable Quick Sort Reads and Writes')
plt.xlabel('Vector Size')
plt.xticks(xAxisTicks)
plt.ylabel('Number of Operations (in Millions)')
plt.legend(['Reads', 'Writes', 'Overall'])
plt.savefig('../images/Two-Sort_Graph.png')
plt.cla()
