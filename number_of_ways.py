#problem statement :
#The Amazon Kindle Store is an online e-book store where readers can choose a book from
#a wide range of categories. It also provides the ability to bookmark pages the user wishes to return to later.
#A book is represented as a binary string having two types of pages:
  
#'0': an ordinary page
#'1': a bookmarked page


#Find the number of ways to select 3 pages in ascending index order such that no two adjacent selected pages are of the same type.

 
#Example
#book = '10111'
#Output : 3


class Solution :
    
    def findLeftSide(self, s, size) :
        
        self.cnt0 , self.cnt1 = 0 , 0  # Total 0's and Total 1's in string
        self.cntLeft0 = [0 for _ in range(size)] # 0's on left of given index
        self.cntLeft1 = [0 for _ in range(size)] # 1's on left of given index
        
        for ind in range(size) :
            
            self.cntLeft0[ind] = self.cnt0
            self.cntLeft1[ind] = self.cnt1
            
            if s[ind] == "1" :
                self.cnt1 += 1
                
            else :
                self.cnt0 += 1

    def waysToSelect(self, s) :
        
        length = len(s)
        self.findLeftSide(s,length)
        ways = 0
        
        for ind in range(1,length) :
            
            if s[ind] == "1" :
                
                onLeft = self.cntLeft0[ind]
                onRight = self.cnt0 - onLeft
            
            else :
                
                onLeft = self.cntLeft1[ind]
                onRight = self.cnt1 - onLeft
        
            # Number of subsets formed in given ways with arr[ind]=1 as 2nd page out of 3 is
            # (Number of 0's in left) * (Number of 0's in right) and vice-versa
            ways += (onLeft*onRight)
        
        return ways

# TAKING INPUT
s = input()
print(Solution().waysToSelect(s))
