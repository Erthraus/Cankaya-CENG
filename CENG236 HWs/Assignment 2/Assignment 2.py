#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import matplotlib.pyplot as plt
import math

def bisection(f, a, b, tol, max_iter = 100):
    x = np.arange(a, b, 0.01)
    fig, ax = plt.subplots()
    ax.plot(x, f(x))
    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_title('y = f')
    
    if f(a) * f(b) > 0:
        raise Exception("Error: f(a) and f(b) must have opposite signs")
    
    else:
        for i in range(max_iter):
            p = (a + b)/2
            print(f"a = {a}, b = {b}, p{i+1} = {p}, f(p{i+1}) = {f(p)}")
            ax.scatter(p, f(p), c='red')
            
            if abs(f(p)) < tol:
                print(f"Solution found after {i+1} iterations:\np = {p}, f(p) = {f(p)}")
                break
            
            elif f(p)*f(a) < 0:
                b = p
            
            else:
                a = p
        else:
            print("Maximum number of iterations exceeded.")
            print(f"p = {p}, f(p) = {f(p)}")
            
    plt.show()
    
def secant(f, x0, x1, e, N = 100):
    step = 1
    condition = True
    while condition:
        if f(x0) == f(x1):
            print('Divide by zero error!')
            return
        
        x2 = x0 - (x1-x0)*f(x0)/( f(x1) - f(x0) ) 
        print('Iteration-%d, x2 = %0.6f and f(x2) = %0.6f' % (step, x2, f(x2)))
        x0 = x1
        x1 = x2
        step = step + 1
        
        if step > N:
            print('Not Convergent!')
            return
        
        condition = abs(f(x2)) > e
    print('\n Required root is: %0.8f' % x2)
    
def regulaFalsi(f, x0, x1, e, N = 100):
    step = 1
    
    condition = True
    while condition:
        x2 = x0 - (x1-x0) * f(x0)/( f(x1) - f(x0) )
        print('Iteration-%d, x2 = %0.6f and f(x2) = %0.6f' % (step, x2, f(x2)))

        if f(x0) * f(x2) < 0:
            x1 = x2
        else:
            x0 = x2

        step = step + 1
        
        if step > N:
            print('Not Convergent!')
            return
        
        condition = abs(f(x2)) > e

    print('\nRequired root is: %0.8f' % x2)
    
def fixedPoint(f, g, x0, e, N = 100):
    print('*** FIXED POINT ITERATION ***')
    step = 1
    condition = True
    while condition:
        x1 = g(x0)
        print('Iteration-%d, x1 = %0.6f and f(x1) = %0.6f' % (step, x1, f(x1)))
        x0 = x1

        step = step + 1
        
        if step > N:
            print('Not Convergent!')
            return
        condition = abs(f(x1)) > e
    print('\n Required root is: %0.8f' % x1)
    
def newtonRaphson(f, g, x0, e , N = 100):
    print('*** NEWTON RAPHSON METHOD IMPLEMENTATION ***')
    step = 1
    condition = True
    while condition:
        if g(x0) == 0.0:
            print('Divide by zero error!')
            return
        
        x1 = x0 - f(x0)/g(x0)
        print('Iteration-%d, x1 = %0.6f and f(x1) = %0.6f' % (step, x1, f(x1)))
        x0 = x1
        step = step + 1
        
        if step > N:
            print('Not Convergent!')
            return
        
        condition = abs(f(x1)) > e
    print('\n Required root is: %0.8f' % x1)


# In[2]:


#Question 1

f = lambda x: x**2 - 2

bisection(f, 1.0, 2.0, 10**-4)


# In[3]:


#Question 2

secant(f, 1.0, 2.0, 10**-4)


# In[4]:


regulaFalsi(f, 1.0, 2.0, 10**-4)


# In[5]:


#Question 3

# Re-writing f(x)=0 to x = g(x)
g = lambda x: (𝑥 + 2/𝑥) / 2

fixedPoint(f, g, 1.0, 10**-4)


# In[6]:


#Question 4

g = lambda x: (f(x + f(x)) - f(x)) / f(x)
newtonRaphson(f, g, 1.0, 10**-4)


# In[7]:


#Question 5

# Defining derivative of function
g = lambda x: 2 * x

newtonRaphson(f, g, 1.0, 10**-4)


# # Conclusion
# The fastest one is the Newton Method
