

def multiply(x, y):
    # Base case: if x or y has only one digit, return the product of the digits
    if len(str(x)) == 1 or len(str(y)) == 1:
        return x * y
    
    # Split x and y into two halves of equal length
    n = max(len(str(x)), len(str(y)))
    m = n // 2
    a = x // 10**m
    b = x % 10**m
    c = y // 10**m
    d = y % 10**m
    
    # Recursively compute the products of the halves
    ac = multiply(a, c)
    bd = multiply(b, d)
    ad_bc = multiply(a + b, c + d) - ac - bd
    
    # Combine the products to compute the final result
    result = ac * 10*(2*m) + ad_bc * 10*m + bd
    
    return result

x = int(input("Enter first number: "))
y = int(input("Enter second number: "))
print("Product: ", multiply(x, y))