# -*- encode:utf-8 -*-
# pip install sklearn numpy Theano Tensorflow pandas seaborn pillow matplotlib plot 
from sklearn import metrics
from sklearn.datasets import load_iris
from sklearn.cross_validation import train_test_split

iris = load_iris()
X = iris.data
y = iris.target
X_new = [[3, 5,4,2],[5,4,3,2]]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4, random_state=4)

# KNeighborsClassifier
from sklearn.neighbors import KNeighborsClassifier
knn = KNeighborsClassifier(n_neighbors=1)
knn.fit(X, y)
ans = knn.predict(X_new)
y_pred = knn.predict(X)
print("knn 1 ", ans, metrics.accuracy_score(y, y_pred))

knn = KNeighborsClassifier(n_neighbors=1)
knn.fit(X_train, y_train)
y_pred = knn.predict(X_test)
print("knn 1 ", ans, metrics.accuracy_score(y_test, y_pred))

knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(X, y)
ans = knn.predict(X_new)
y_pred = knn.predict(X)
print("knn 5 ", ans, metrics.accuracy_score(y, y_pred))

knn = KNeighborsClassifier(n_neighbors=5)
knn.fit(X_train, y_train)
y_pred = knn.predict(X_test)
print("knn 5 ", ans, metrics.accuracy_score(y_test, y_pred))

k_range = list(range(1, 26))
scores = []
for k in k_range:
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(X_train, y_train)
    y_pred = knn.predict(X_test)
    scores.append(metrics.accuracy_score(y_test, y_pred))

# LogisticRegression
from sklearn.linear_model import LogisticRegression
logreg = LogisticRegression()
logreg.fit(X, y)
ans = logreg.predict(X_new)
y_pred = logreg.predict(X)
print("logreg", ans, metrics.accuracy_score(y, y_pred))

logreg = LogisticRegression()
logreg.fit(X_train, y_train)
y_pred = logreg.predict(X_test)
print("logreg", ans, metrics.accuracy_score(y_test, y_pred))

# draw
import matplotlib as mpl
# mpl.use("qt5agg") # Use TKAgg to show figures
import matplotlib.pyplot as plt

plt.plot(k_range, scores)
plt.xlabel('Value of K for KNN')
plt.ylabel('Testing Accuracy')
plt.tight_layout()
plt.show()
import pandas as pd
csv_url = 'http://www-bcf.usc.edu/~gareth/ISL/Advertising.csv'
data = pd.read_csv(csv_url, index_col=0)
# display the first 5 rows
print(data.head())
print(data.shape)

import seaborn as sns
sns.pairplot(data, x_vars=['TV','Radio','Newspaper'], y_vars='Sales', size=7, aspect=0.7, kind='reg')












