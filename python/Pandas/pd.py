# -*- encoding:utf-8 -*-
import pandas as pd

# creating dataframe
s = pd.Series([3,-5,7,4], index=['a','b','c','d'])
s3= pd.Series([7,-2,3], index=['a','c','d'])
data = {'Country': ['df','gf','Bf'],
	    'Capital': ['sd','df','gn'],
	    'Population': [516161,416161,16166]}
df = pd.DataFrame(data, columns=['Country','Capital','Population'])

# save & read files
pd.read_csv('file.csv', header=None, nrows=5)
pd.read_excel('file.xlsx')
from sqlalchemy import creat_engine
engine = creat_engine('sqlite:///:memory:')
pd.read_sql('SELECT * FROM my_table;', engine)
pd.read_sql_table('my_table;', engine)
pd.read_sql_query('SELECT * FROM my_table;', engine)

xlsx = pd.ExcelFile('file.xls')
df = pd.read_excel(xlsx, 'Sheet1')

pd.to_csv('file.csv')
pd.to_excel('file.xlsx', sheet_name='Sheet1')
pd.to_sql('file', engine)

# frame feature
df.shape
df.index
df.columns
df.info()
df.count()

df.sum()
df.cumsum()
df.min()   / df.max()
df.idmin() / df.idmax()
df.describe()
df.mean()
df.median()

# math
s + s3
s.add(s3, fill_value=0)
s.sub(s3, fill_value=0)
s.div(s3, fill_value=0)
s.mul(s3, fill_value=0)

# manage frame
s.drop(['a','c'])
df.drop('Country', axis=1)

df.sort_index(by='Country')
s.order()
df.rank()

# frame sub
s['b']
df[1:]

df.iloc([0],[0])
df.iat([0],[0])

df.loc([0],['Country'])
df.at([0],['Country'])

df.ix[2]
df.ix[:,'Capital']
df.ix[1,'Capital']

s[ ~(s>1) ]
s[ (s<-1) | (s>2) ]
df[ df['Population']>121616 ]

s['a']=6

# apply function
f = lambda x: x*2
df.apply(f)
df.applymap(f)

# help
help(pd.Series.loc)