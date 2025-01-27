def solve():
    N = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    result = [0] * (N + 1)
    left, right = 0, 0
    matched_count = 0
    while right < N:
        
        if a[left] == b[right]:
            matched_count += 1
        right += 1

        if right - left > N:
            if a[left] == b[right - N]:
                matched_count -= 1
            left += 1

        result[matched_count] += 1

    for count in result:
        print(count)
