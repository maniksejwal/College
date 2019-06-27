"""wap to implement page replacement policy using
(A) least recently used (LRU)
(B) FIFO
(C) Optimal

maintain a capacity 
insert page one by one until the size of the frame reaches the max
simultaneously maintain the queue to maintain the 

whoen the next page is not available and replacement is needed"""

# input - 11212312341234512345665432154321321211

print('enter string')
s = list(str(input()))
print(s)
print('enter size of the frame')
fsize = int(input())
frames = []

print('LRU')

for i in range(len(s)):
    for j in range(fsize):
        if j == len(frames): break
        if frames[j] == s[i]:
            del frames[j]
            break
    if fsize == len(frames): del frames[0]
    frames.append(s[i])
    print(frames)
