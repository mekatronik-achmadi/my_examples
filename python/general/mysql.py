#!/usr/bin/python

import mysql.connector as mysql

# connecting to the database using 'connect()' method
# it takes 3 required parameters 'host', 'user', 'passwd'
db = mysql.connect(host = "localhost",user = "sqluser",passwd = "")

# creating an instance of 'cursor' class which is used to execute the 'SQL' statements in 'Python'
dbcsr = db.cursor()

# creating a databse called 'datacamp'
# 'execute()' method is used to compile a 'SQL' statement
# below statement is used to create the 'sensor' database
dbcsr.execute("CREATE DATABASE sensor")

# Get all databases into buffer
dbcsr.execute("SHOW DATABASES")

## 'fetchall()' method fetches all the rows from the last executed statement
dbases = dbcsr.fetchall()
print(dbases)
