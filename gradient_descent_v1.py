import os
import numpy as np
from matplotlib import cm
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import warnings

warnings.filterwarnings("ignore")

# Get data
cwd = os.path.dirname(os.path.realpath(__file__)) 
#if os.path.isfile(cwd + '/data.csv') == False:
#    print 'missing data'
#    exit()
try: km, price = np.loadtxt(cwd + '/data.csv', delimiter=',', skiprows=1, unpack=True)
except:
    print 'missing or incomplete data file'
    exit()
norm_km, norm_price = np.amax(km), np.amax(price)
km, price = km / norm_km, price / norm_price
data_len = np.shape(km)[0]

# cost_func
def J(W1, W2):
    return 1./ (2 * data_len) * sum((W1 + W2 * km - price)**2)

v_J = np.vectorize(J)

# dJ/dWi
def dJdW1(W1, W2):
    return 1./data_len * sum(W1 + W2 * km - price)

def dJdW2(W1, W2):
    return 1./data_len * sum((W1 + W2 * km - price) * km)

# gradient_descent
def batch_gradient_descent(Wlist, alpha):
    for i, j in ((i, j) for i in range(len(alpha)) for j in range(n_iter - 1)):
        a, b = Wlist[i][j][0:2]
        temp = a
        a = a - alpha[i] * dJdW1(a, b)
        b = b - alpha[i] * dJdW2(temp, b)
        Wlist[i, j + 1] = [a, b, J(a,b)]
    return Wlist

n_iter = 500
alpha = [0.01, 1, 1.69]
Wlist = np.empty((len(alpha), n_iter, 3))

weight_init = np.zeros(3)
weight_init[2] = J(weight_init[0], weight_init[1])

for i in range(len(alpha)):
    Wlist[i][0] = weight_init
Wlist = batch_gradient_descent(Wlist, alpha)

def fig_config(ax, title, x, y, z=None):
    ax.set_title(title)
    ax.set_xlabel(x)
    if z is not None:
        ax.set_zlabel(z)
    
def set_result(ax, nb_iter):
    fig_config(ax, 'After ' + str(nb_iter) + ' iterations', 'km', 'price')
    ax.plot(norm_km * km, norm_price * price, 'ro')
    ax.plot(norm_price * (Wlist[1, nb_iter, 0] * np.ones(norm_km) + Wlist[1, nb_iter, 1] * np.linspace(0, 1, num=norm_km)), 'b--')

def plot_graph():
    fig = plt.figure(figsize=((15, 10)))
    
    W1 = np.arange(0, 2, 0.1)
    W2 = np.arange(-1, 1, 0.1)
    W1, W2 = np.meshgrid(W1, W2)
    Z = np.zeros(np.shape(W1))
    Z = v_J(W1, W2)
    
    ax1 = plt.subplot2grid((3,3), (0,0), colspan=2, rowspan=2, projection='3d')
    fig_config(ax1, 'Cost function', 'W1', 'W2', 'J')
    ax1.plot_surface(W1, W2, Z, rstride=2, cstride=2, cmap=cm.coolwarm, alpha=0.3)
    for i, col in zip([0, 1], ['r','g']):
        x = [a for a, b in Wlist[i, :, 0:2]]
        y = [b for a, b in Wlist[i, :, 0:2]]
        ax1.plot(x , y, v_J(x, y), c=col)
    
    x = [a for a, b in Wlist[2, :10, 0:2]]
    y = [b for a, b in Wlist[2, :10, 0:2]]
    ax1.plot(x , y, v_J(x, y), c='b')
    
    ax2 = fig.add_subplot(3,3,3)
    fig_config(ax2, 'convergence', 'nb_iteration', 'J')
    ax2.set_ylim([0,0.5])
    ax2.plot(Wlist[0, :, 2], c='r', linewidth=2, label='0.01')
    ax2.plot(Wlist[1, :, 2], c='g', linewidth=2, label='1')
    ax2.plot(Wlist[2, :, 2], c='b', linewidth=2, label='1.69')
    ax2.legend(loc='upper right')
    
    x = np.linspace(0, 14, 50)
    y = np.linspace(0, 10, 50)
    x, y = np.meshgrid(x, y)
    
    ax3 = fig.add_subplot(3,3,7)
    set_result(ax3, 5)
    ax4 = fig.add_subplot(3,3,8)
    set_result(ax4, 50)
    ax5 = fig.add_subplot(3,3,9)
    set_result(ax5, 200)

W1 = Wlist[1, -1, 0]
W2 = Wlist[1, -1, 1]

while True:
    var = raw_input('how many km ?\n')
    if var.isdigit() and int(var) >= 0:
        guess = (norm_price * (W1 + float(var) / norm_km * W2))
        if guess < 0: print 'cost nothing\n'
        else: print 'should cost: ' + str(int(guess)) + ' $\n'
    elif var == 'exit': break
    elif var == 'graph':
        plot_graph()
        plt.show()
        print '\n'
    else: print 'expect positive integer or \'print\' or \'exit\'\n'
