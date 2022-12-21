import matplotlib.pyplot as plt

data = []
with open("./data_small_final.txt") as fd:
    header = next(fd).split()
    for line in fd:
        data.append(list(map(int, line.split())))

data = list(zip(*data))
xs = data[0]

for lab, ys in zip(header[1:], data[1:]):
    plt.plot(xs, ys, label=lab)

plt.legend()
#plt.show()
plt.savefig("data_small_final.png")