n, h, l, r = map(int, input().split())
ais = list(map(int, input().split()))
memo = {}

def bestSleep(dia, hora, goodDays=0):
    if (dia, hora) in memo:
        return memo[(dia, hora)]
    
    
    if dia >= n:
        result = goodDays + 1 if l <= hora <= r else goodDays
        memo[(dia, hora)] = result
        return result
    
    
    newHour1 = (hora + ais[dia]) % h
    newHour2 = (hora + ais[dia] - 1) % h
    
    
    if newHour1 == newHour2:
        best = bestSleep(dia + 1, newHour1, goodDays + 1 if l <= newHour1 <= r else goodDays)
    else:
        best1 = bestSleep(dia + 1, newHour1, goodDays + 1 if l <= newHour1 <= r else goodDays)
        best2 = bestSleep(dia + 1, newHour2, goodDays + 1 if l <= newHour2 <= r else goodDays)
        best = max(best1, best2)
    
    memo[(dia, hora)] = best
    return best

print(bestSleep(0, 0, 0))
