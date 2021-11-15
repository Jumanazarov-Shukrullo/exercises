def fib(n):
  vec = [0, 1]
  for i in range(2, n + 1):
    vec[i].append(vec[i - 1] + vec[i - 2])
    
  return vec[n]

a = int(input())
print(fib(a))
  
