def count_values1(some_dict):

    value_set = set()
   
    for val in some_dict.values():
        value_set.add(val)
   
    return len(value_set)
   

def count_values2(some_dict):
    return len(set(some_dict.values()))

some_dict = {'red':1, 'green':1, 'blue':2}
print ("Unique Values in Dictionary : %d" % count_values1(some_dict))
print ("Unique Values in Dictionary : %d" % count_values2(some_dict))