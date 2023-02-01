import random

class Frame:
    def __init__(self, seqNo, data=None):
        self.seqNo=seqNo
        self.data=data

n = int(input("Enter no. of frames: "))

seqList = []
for _ in range(n):
    x = random.randint(1,n*100)
    while x in seqList:
        x = random.randint(1,n*100)
    seqList.append(x)

frames = []
for i in seqList:
    frames.append(Frame(i))

for frame in frames:
    frame.data = int(input(f"{frame.seqNo} Frame data : "))

frames.sort(key= lambda x: x.seqNo)


for frame in frames:
    print(f"Frame {frame.seqNo} : {frame.data}")