from fractions import Fraction
from collections import deque, defaultdict

def gdc(a,b):
    return b if a%b ==0 else gdc(b,a%b)

adj = defaultdict(dict)
def addRate(a, b, u, v):
    rate = Fraction(u, v)
    adj[a][b] = rate  
    adj[b][a] = 1 / rate  

while True:
    inp = input()
    if(inp =="."):
        break
    inp = inp.split()
    
    def bfs(a,b):

        if( a not in adj or b not in adj): 
            return None
        
        queue = deque([(a,Fraction(1))])
        visited = set()
        #print(adj)
        while queue:
            currentItem,currentRate = queue.popleft()
            if currentItem == b:
                return currentRate
            
            
            for neighbor,rate in adj[currentItem].items():
                if(neighbor not in visited):
                    visited.add(neighbor)
                    queue.append((neighbor, currentRate * rate))
                    
        return None

    if(inp[0]=="!"):
        a,b = inp[2], inp[5]
        addRate(a,b,int(inp[1]),int(inp[4]))
        #print(adj)
        

    if(inp[0]=="?"):
        #print(adj)
        a = inp[1]
        b = inp[3]
        res = bfs(a,b)

        if(res == None):
            print(f"? {a} = ? {b}")
            continue
        mdc = gdc(res.numerator,res.denominator)

        print(f'{res.numerator//mdc} {a} = {res.denominator//mdc} {b}')
        
    

    
