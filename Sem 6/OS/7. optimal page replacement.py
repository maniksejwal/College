
print('enter string')
s = list(str(input()))
print(s)
print('enter size of the frame')
fsize = int(input())

print('enter lookahead length')
lookahead = int(input())
frames = []

for i in range(len(s)):
    for j in range(fsize):
        if j == len(frames): break
        if frames[j][0] == s[i]:
            del frames[j]
            break

    for j in range(len(frames)):
        frames[j][1] = 0
        for k in range(lookahead):
            if i+k == len(s): break
            if s[i+k] == frames[j][0]:
                frames[j][1] += 1

    min = 0
    for j in range(1, len(frames)):
        if frames[min][1] > frames[j][1]:
            min = j

    if fsize == len(frames): del frames[min]

    frames.append([s[i], 0])
    print(frames)
