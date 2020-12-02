"""
Problem #1
"""

def complement(string):
    result=[]
    for i in range(len(string)):
        result.append(string[i])
    for i in range(len(result)):
      if result[i] == 'a':
          result[i] = 't'
      elif result[i] == 't':
          result[i] = 'a'
      elif result[i] == 'g':
          result[i] = 'c'
      elif result[i] == 'c':
          result[i] = 'g'
    return result

print("----------input your DNA----------")
DNA=input()

DNA=complement(DNA)
print("----------Complemented DNA----------")
for i in range(len(DNA)):
    print(DNA[i],end='')



    