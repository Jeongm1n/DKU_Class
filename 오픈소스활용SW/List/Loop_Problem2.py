from random import randint

upper_limit = 21
not_finished = True
sum = 0
while not_finished:
    next_number = randint(0, 10)
    print ("You got: ", next_number)
    sum += next_number
    if sum > upper_limit:
        print ("Game over, you passed 21 (with your %d points)!"\
                % sum)
        not_finished = False
    else:
        print ("Your score is now: %d points!" % (sum))
        answer = input('Another draw (y/n)? ')
        if answer != 'y':
            not_finished = False
print ("Finished!")