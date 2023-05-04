
def pow(base, exp):
    if(exp <= 0):
        return 1
    if(exp%2):
        return base*pow(base, exp-1)
    else:
        val = pow(base, exp//2)
        return val*val

base = int(input("Enter base: "))
exp = int(input("Enter exponent: "))
print("Result: ", pow(base, exp))