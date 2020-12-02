def complement(c_DNA):
    result=[]
    for i in range(len(c_DNA)):
        result.append(c_DNA[i])
    for i in range(len(result)):
      if result[i] == 'A':
          result[i] = 'T'
      elif result[i] == 'T':
          result[i] = 'A'
      elif result[i] == 'G':
          result[i] = 'C'
      elif result[i] == 'C':
          result[i] = 'G'
    return result

print("----------input your DNA----------")
DNA=input()

print("----------Complemented DNA----------")
print("".join(complement(DNA)))