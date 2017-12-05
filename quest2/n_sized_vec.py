def delimer(v_size):
    if v_size <= 2: return 1;
    if v_size == 3: return 2;

    denumerator     = int(v_size/2)

    while denumerator > 1:
        remainder = v_size % denumerator
        if (remainder == 0): return denumerator
        else:
            denumerator -= 1
    return 2

def main():
    N = 0
    N = input("input vector's size: ")
    N = int(N)
    if N<=2:
        print ("incorrect values")
        return -1
    delim = delimer(N)
    print (delim, end=': ')

    n = 0
    res = ""
    while n != int(N/delim) - 1:
        res  += '(' + str(n*delim) + ',' + str((n+1)*delim-1) + '), '
        n += 1

    rem  = N%delim
    tail = N-delim
    if rem == 0:
        res += '(' + str(tail) + ',' + str(N-1) + ') '
    else:
        res += '(' + str(tail-1) + ',' + str(N - 2) + '), ' + '(' + str(N-1) + ')'
    print (res)
    return 0

main()