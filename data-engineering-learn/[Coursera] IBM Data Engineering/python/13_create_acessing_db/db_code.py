# Scenario

"""
Consider a dataset of employee records that is available with an HR team in a CSV file. As a Data Engineer, you are
required to create the database called STAFF and load the contents of the CSV file as a table called INSTRUCTORS.

The headers of the available data are :
Header : Description
ID     : Employee ID
FNAME  : First Name
LNAME  : Last Name
CITY   : City of residence
CCODE  : Country code (2 letters)
"""

import pandas as pd
import sqlite3
from IPython.display import display

table_name = 'INSTRUCTOR'
attribute_list = ['ID', 'FNAME', 'LNAME', 'CITY', 'CCODE']

csv_path = "./INSTRUCTOR.csv"
df = pd.read_csv(csv_path, names = attribute_list)

# print(df)

conn = sqlite3.connect('STAFF.db')
df.to_sql(table_name, conn, if_exists = 'replace', index=False)

# queries

query_statement = f"SELECT * FROM {table_name}"
query_output = pd.read_sql(query_statement, conn)

print(query_statement)
print("---")
print(query_output)

query_statement = f"SELECT FNAME FROM {table_name}"
query_output = pd.read_sql(query_statement, conn)

print("\n")
print(query_statement)
print("---")
print(query_output)

query_statement = f"SELECT COUNT(*) FROM {table_name}"
query_output = pd.read_sql(query_statement, conn)

print("\n")
print(query_statement)
print("---")
print(query_output)

# Append data
data_dict = {'ID' : [100],
             'FNAME' : ['John'],
             'LNAME' : ['Doe'],
             'CITY' : ['Paris'],
             'CCODE' : ['FR']}
data_append = pd.DataFrame(data_dict)
data_append.to_sql(table_name, conn, if_exists='append', index=False)

query_statement = f"SELECT COUNT(*) FROM {table_name}"
query_output = pd.read_sql(query_statement, conn)

print("\n")
print(query_statement)
print("---")
print(query_output)

conn.close()



# print(data_append)