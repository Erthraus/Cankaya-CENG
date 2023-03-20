#!/usr/bin/env python
# coding: utf-8

# In[70]:


import numpy as np
import matplotlib.pyplot as plt

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


# In[71]:


#Question 2
f1 = lambda x: 3 * (x + 1) * (x - 1/2) * (x - 1)

bisection(f1, -2, 1.5, 10**-4, 4)


# In[72]:


#Question 3
f2 = lambda x: x**2 - 3

bisection(f2, 1, 2, 10**-4)


# In[ ]:




