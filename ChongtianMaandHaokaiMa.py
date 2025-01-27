def solve():
    N = int(input())  # Number of cows
    a = list(map(int, input().split()))  # Species of the cows
    b = list(map(int, input().split()))  # Required species for checkup
    checked_initial = [1 if a[i] == b[i] else 0 for i in range(N)]
    result = [0] * (N + 1)
    for l in range(N):
        current_checked = checked_initial[:]
        for r in range(l, N):
            
            current_checked[l:r+1] = reversed(current_checked[l:r+1])
            
            checked_count = sum(current_checked)
            result[checked_count] += 1
    
    for count in result:
        print(count)
