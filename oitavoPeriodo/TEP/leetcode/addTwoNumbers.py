class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
class Solution:
    def addTwoNumbers(self, l1: [ListNode], l2: [ListNode]) -> [ListNode]:
        i=0
        num1 =0
        num2 = 0
        while True:
            num1+= l1.value*10**i
            if(l1.next == None):
                break
            i+=1
            l1 = l1.next
        i=0
        while True:
            num2+= l2.value*10**i
            if(l2.next == None):
                break
            i+=1
            l2 = l2.next

        print(num1, num2)

s =  Solution()
arr1 = [2,4,3]
arr2 = [5,6,4]
l1 = ListNode()
l2 = ListNode()
l1.value = arr1[0]

for i in range(1,len(arr1)):
    temp = ListNode()
    temp.value = arr1[i]
    l1.next = temp
    l1 = temp

for i in range(1,len(arr2)):
    temp = ListNode()
    temp.value = arr2[i]
    l2.next = temp
    l2 = temp

s.addTwoNumbers(l1  , l2)