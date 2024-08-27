def response(size, word):
    initial = 0
    end = int(size)-1
    counter = {}
    for i in range(end,len(word)):
        passw = word[initial:i+1]
        initial+=1
        if(passw not in counter):
            counter[passw] = 0
        counter[passw]+=1
    print(max(counter, key=counter.get))  

while True:
    try:
        text = input()
        text = text.split(" ")
        text = [i for i in text if i!= '']
        while(len(text)<2):
            temp = input()
            temp = temp.split(" ")
            temp = [i for i in temp if i!= '']
            text = text+temp
        response(text[0], text[1])
    except:
        break
