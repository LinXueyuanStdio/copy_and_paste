# -*- encoding:utf-8 -*-
# quick start
'''
from keras.models import Sequential
from keras.layers import Dense, Activation
from keras.optimizers import SGD

model = Sequential()
model.add(Dense(units=64, input_dim=100))
model.add(Activation("relu"))
model.add(Dense(units=64, input_dim=100))
model.add(Activation("softmax"))

model.compile(loss='categorical_crossentropy', optimizer='sgd', metrics=['accuracy'])

model.fit(x_train, y_train, epochs=5, batch_size=32)

loss_and_mertics = model.evaluate(x_test, y_test, batch_size=128)
'''
import numpy
from keras.models import Sequential
from keras.layers import Dense
from keras.layers import LSTM
from keras.utils import np_utils
from keras.preprocessing.sequence import pad_sequences
# fix random seed for reproducibility
numpy.random.seed(7)
# define the raw dataset
alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# create mapping of characters to integers (0-25) and the reverse
char_to_int = dict((c, i) for i, c in enumerate(alphabet))
int_to_char = dict((i, c) for i, c in enumerate(alphabet))

# prepare the dataset of input to output pairs encoded as integers
seq_length = 1
dataX = []
dataY = []
for i in range(0, len(alphabet) - seq_length, 1):
    seq_in  = alphabet[i:i + seq_length]
    seq_out = alphabet[i + seq_length]
    dataX.append([char_to_int[char] for char in seq_in])
    dataY.append(char_to_int[seq_out])
    print(seq_in, '->', seq_out)
# convert list of lists to array and pad sequences if needed
X = pad_sequences(dataX, maxlen=seq_length, dtype='float32')
# reshape X to be [samples, time steps, features]
X = numpy.reshape(dataX, (X.shape[0], seq_length, 1))
print(X)
# normalize
X = X / float(len(alphabet))
print(X,X.shape[1], X.shape[2])
# one hot encode the output variable
y = np_utils.to_categorical(dataY)
print(y,y.shape[1])
# create and fit the model
model = Sequential()
model.add(LSTM(32, input_shape=(X.shape[1], X.shape[2])))
model.add(Dense(y.shape[1], activation='softmax'))
model.compile(loss='categorical_crossentropy', 
              optimizer='adam', 
              metrics=['accuracy'])
model.fit(X, y, epochs=500, batch_size=1, verbose=1)

# summarize performance of the model
scores = model.evaluate(X, y, verbose=1)
print("Model Accuracy: %.2f%%" % (scores[1]*100))

# demonstrate some model predictions
for pattern in dataX:
    x = numpy.reshape(pattern, (1, len(pattern), 1)) 
    # print(x)
    x = x / float(len(alphabet)) 
    # print(x)
    prediction = model.predict(x, verbose=0)
    index = numpy.argmax(prediction)
    seq_in = [int_to_char[value] for value in pattern]
    result =  int_to_char[index]
    print(seq_in, "->", result)

# demonstrate predicting random patterns
print("Test a Random Pattern:")
for i in range(0,20):
	pattern_index = numpy.random.randint(len(dataX))
	pattern = dataX[pattern_index]
	x = numpy.reshape(pattern, (1, len(pattern), 1))
	x = x / float(len(alphabet))
	prediction = model.predict(x, verbose=0)
	index = numpy.argmax(prediction)
	result = int_to_char[index]
	seq_in = [int_to_char[value] for value in pattern]
	print(seq_in, "->", result)
    
    
    
    
    
    
    
    
    
    
    
    
    
    