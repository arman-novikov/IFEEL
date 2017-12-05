def factorize(num):
    factor = 2 # this is the smallest possible multiple

    '''
    this procedure is gonna try to divide by module of factor (num%factor==0)
    every iteration it can reduce the num in factor times
    if it can (else it gonna to increment the factor)
    '''
    while factor <= num:
        if num % factor == 0:
            print (factor, end = '')
            num = num /factor
            if num > 1:
                print ('*', end = '')
        else:
            factor = factor + 1
    return

i  = 1
ls = []
t = 0

'''
if I need to keep results in memory
i'd probably use [[], [], [], ... ,]
and push results into
'''

while (t != 'q'):
    t = input("input the el #" + str(i) + "  or 'q' to end: ")
    i = i + 1
    try:
        ls.append(int(t))
    except ValueError:
        t = 'q'

if ls:
    print("the reuslts: ")
    for t in ls:
        print ("\nfor %s :" %str(t), end = ' ')
        factorize(t)

print('\n')
