# 1.Prepare data
import numpy as np
## 1D
x = np.linspace(0,10,100)
y = np.cos(x)
z = np.sin(x)
## 2D (also image)
data = 2*np.random.random([10,10])
data2= 3*np.random.random([10,10])

Y,X = np.mgrid[-3:3:100j, -3:3:100j]

U = -1 - X**2 + Y
V =  1 + X    - Y**2

from matplotlib.cbook import get_sample_data
img = np.load(get_sample_data('file.npy'))

# 2.Creat plot
import matplotlib.pyplot as plt
fig = plt.figure()
fig2= plt.figure(figsize=plt.figaspect(2.0))
fig.add_axes()
ax1 = fig.add_subplot(221) # row-col-num
ax2 = fig.add_subplot(212)
fig3,axes = plt.subplot(nrows=2, ncols=2)
fig4,axes2= plt.subplot(ncols=2)

# 3.Plotting
## 1D
fig,ax = plt.subplots()
lines = ax.plot(x,y)
ax.scatter(x,y)
axes[0,0].bar([1,2,3],[4,5,6])
axes[1,0].barh([0.5,1,2.5],[0,1,2])
axes[1,1].axhline(0.45)
axes[0,1].axvline(0.65)
ax.fill(x,y,color='blue')
ax.fill_between(x,y,color='yellow')
### vector fields
axes[0,1].arrow(0,0,0.5,0.5)
axes[1,1].quiver(y,z)
axes[0,1].streamplot(X,Y,U,V)
## data distributions
ax1.hist(y)
ax3.boxplot(y)
ax3.violinplot(z)
## 2D
fig,ax = plot.subplots()
im = ax.imshow(img,
			   cmap='gist_earth',
			   interpolation='nearest',
			   vmin=-2,
			   vmax= 2)

axes2[0].pcolor(data2)
axes2[0].pcolormesh(data)

CS = plt.contour(Y,X,U)
axes2[2].contour(data1)
axes2[2] = ax.clabel(CS)

# 4.Customize
## color
plt.plot(x,x, x,x**2, x,x**3)
ax.plot(x,y,alpha = 0.4)
ax.plot(x,y,c='k')
fig.colorbar(im, orientation='horizontal')
im = ax.imshow(img, camp='seismic')
## marks
fig,ax = plt.subplots()
ax.scatter(x,y,marker='.')
ax.plot(x,y,marker='o')
## linestyle
plt.plot(x,y,linewidth=4.0)
plt.plot(x,y,ls='solid')
plt.plot(x,y,ls='==')
plt.plot(x,y,'==', x**2,y**2,'=.')
plt.plot(lines,color='r',linewidth=4.0)
## text
ax.text(1,-2.1, 'exampleGraph',style='italic')
ax.annotate('Sine', 
			xy=(8,0),
		    xycoords='data',
		    xytext=(10.5,0),
		    textcoords='data',
		    arrowprops=dict(arrowstyle="->",connectionstyle="arc3"))
plt.title(r'$sigma_i=15$',fontsize=20)
## limits
### limits & autoscaling
ax.margins(x=0.0,y=0.1)
ax.axis('equal')
ax.set(xlim=[0,10.5],ylim=[-1.5,1.5])
ax.set_xlim(0,10.5)
### legends
ax.set(title="title",
	   ylabel="Y-Axis",
	   xlabel="X-Axis")
ax.legend(loc='best')
### ticks
ax.xaxis.set(ticks=range(1,5), ticklabels=[3,100,-12,'foo'])
ax.tick_params(axis='y', diraction='inout', length=10)
### subplot spacing
fig3.subplots_adjust(wspace = 0.5, hspace = 0.3,
					 left = 0.125, right = 0.9,
					 top = 0.9,    bottom = 0.1)
fig.tight_layout()
### axis spines
ax1.spines['top'].set_visible(False)
ax1.spines['bottom'].set_position(('outward',10))


# 5.Save
plt.savefig('file.png')
plt.savefig('file.png', transparent=True)

# 6.Show
plt.show()

# 7.Close
plt.cla()
plt.clf()
plt.close()