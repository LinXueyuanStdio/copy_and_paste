# -*- encoding:utf-8 -*-
import numpy as np

# data type
'''
np.int64  np.float32  np.complex  np.bool np.object  np.string_ np.unicode_
'''

# creating array
a = np.array([1,2,3])
b = np.array([[1.5,2,3],
			  [4,  5,6]])
c = np.array([[[1.5,2,3],
			  [4,  5,6]],
			[[1.5,2,3],
			  [4,  5,6]]], dtype=float)
e = np.full((2,2),7)
f = np.eye(2)
np.zeros((3,4))
np.ones((2,3,4), dtype=np.int16)
d = np.arange(10,25,5)
np.linspace(0,2,9)
np.logspace(0,2,9)
np.random.random((2,2))
np.empty((3,2))
np.fromstring(s, dtype=np.int16) # scaii code

# save & load array object
np.save('file_name', a) # default is 'file_name.npy'
np.savez('file_name.npz', a, b)
np.load('file_name.npy')
# save & load text files
np.savetxt('file_name.txt', a, delimiter=',') # default is 'file_name.npy'
np.genfromtxt('file_name.csv', delimiter=',')
np.load('file_name.txt')

# array feature
len(a)
a.shape
b.ndim
e.size
b.dtype
b.dtype.name
b.astype(int) # convert type to int

# array math
g = a - b
np.subtract(a,b)
b + a
np.add(b,a)
a / b
np.divide(a,b)
a * b
np.multiply(a,b)

np.exp(b)
np.sqrt(b)
np.sin(b)
np.cos(b)
np.log(b)

e.dot(f)

a == b
a < 2
np.array_equal(a,b)

a.sum()
a.min()
b.max(axis=0)
b.cumsum(axis=1)
a.mean()
b.median()
a.corrcoef()
np.std(b)

# manage array
h = a.view() # a view with same data
np.copy(a)
h = a.copy() # deep copy

a.sort()
c.sort(axis=0)

# array sub
a[2]
b[1,2]

a[0:2]
b[0:2,1]
b[:1] # == b[0:1, :]
c[1, ...] # == c[1, :, :]
a[ : :-1] # reverse
a[a<2]
b[[1,0,1,0],
  [0,1,2,0]] # [b[1,0], b[0,1], b[1,2], b[0,0]]
b[[1,0,1,0]][ : , [0,1,2,0]] 
'''
[[b[1,0],b[1,1],b[1,2],b[1,0]],
 [b[0,0],b[0,1],b[0,2],b[0,0]],
 [b[1,0],b[1,1],b[1,2],b[1,0]],
 [b[0,0],b[0,1],b[0,2],b[0,0]]]
'''

# array manipulation
i = np.transpose(b)
i.T

b.ravel() # change b to dim=1

g.reshape(3,-2) # dont change data
h.resize((2,6)) # change data
np.append(h,g)
np.insert(a,1,5) # a[1]=5,a[i+1]=a[i]
np.delete(a,[1])

np.concatenate((a,d),axis=0) # a = [1,2,3,10,15,20]
np.vstack((a,b))
np.r_[e,f] # r_ for row
np.hstack((e,f))
np.c_[a,d] # c_ for col
np.column_stack((a,d))

np.hsplit(a,3) 
'''
[[1],
 [2],
 [3]]
'''
np.vsplit(c,2)
'''
[
[[[1.5,2,3],
  [4,  5,6]]],
[[[1.5,2,3],
  [4,  5,6]]]
]
'''


# help
np.info(np.ndarray.dtype)