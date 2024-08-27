class Tree:
    value = None
    left = None
    right = None
def parserNode(text, pointer):
    stack = []
    mainNode = Tree()
    value = 0
    if(text[pointer]==")"):
        return mainNode
    pointer +=1
    originalPointer = pointer
    try:
        while True:
            int(text[pointer])
            pointer+=1
    except:
        value = text[originalPointer: pointer]
    mainNode.value = value
    print(mainNode.value)

    mainNode.left = parserNode(text,pointer)

    


textInput = input()
values = textInput.replace(" ", "")
for i in range(len(values)):
    if(values[i]=="("):
        node,i = parserNode(values,i)
