"""
Python Programming Practical Sheet No.1

Name: Malhar Sanjay Pawar
Class: S.Y.B.Sc. Mathematics Major (SEM-3)
Roll no: 90
Student ID: 5743009
"""

import math

# Question 1:
# Write a Python program to display Information (Name, Age, College, City)
def Ques1():
    Name = "Malhar Sanjay Pawar"
    Age = 19
    Clg = "B.K. Birla College"
    City = "Mumbai"
    print(f"Name: {Name}\nAge: {Age}\nCollege: {Clg}\nCity: {City}\n")

#Question 2:
# Write a program to accept user name and age as input and display them
def Ques2():
    Name = input("Enter your Name: ")
    Age = input("Enter your Age: ")
    print(f"Name: {Name}\nAge: {Age}\n")

# Question 3:
# Write a program to accept 2 numbers and display their sum
def Ques3():
    a = int(input("Enter First Number: "))
    b = int(input("Enter Second Number: "))
    print("Sum = ", a+b)

# Question 4:
# Write a program to accept 2 numbers and perform Arithmetic Operations
def Ques4():
    a = int(input("Enter First Number: "))
    b = int(input("Enter Second Number: "))
    print(f"Addition: {a+b}\nSubtraction: {a-b}\nMultiplication: {a*b}\nDivision: {a/b}")
    print(f"Floor Division: {a//b}\nModulus: {a%b}\nExponentiation: {a**b}\n")

# Question 5:
# Calculate Area of Rectangle by accepting Length and Breadth
def Ques5():
    length = float(input("Enter the Length: "))
    breadth = float(input("Enter the Breadth: "))
    print(f"Area of Rectangle = {length*breadth}")

# Question 6:
# Calculate area and circumference of Circle by accepting Radius
def Ques6():
    Radius = float(input("Enter the Radius: "))
    Area = (math.pi)*Radius*Radius
    Circumference = (math.pi)*Radius*2
    print(f"Area: {Area:.2f}\nCircumference: {Circumference:.2f}")

# Question 7:
# Write a Program to swap 2 numbers using a Third Variable
def Ques7():
    a = 10
    b = 20
    print(f"Before Swap:\nA = {a}, B = {b}")
    temp = a
    a = b
    b = temp
    print(f"After Swap:\nA = {a}, B = {b}")

# Question 8:
# Write a Program to Calculate Simple Interest
def Ques8():
    P = 50000
    R = 5
    T = 10
    print(f"P = {P}, R = {R}, T = {T}")
    print(f"Simple Interest = {(P*R*T)/100}")

# Question 9:
# Conversion from Celsius to Fahrenheit
def Ques9():
    Celsius = float(input("Enter Temperature in Celsius: "))
    F = ((9/5)*Celsius)+32
    print(f"Temperature in Fahrenheit = {F:.2f}")

# Question 10:
# Write a program to input a Number and Display its Square and Cube
def Ques10():
    Num = float(input("Enter the Number: "))
    print(f"Square: {(Num**2):.2f}\nCube: {(Num**3):.2f}")

# Question 11:
# Display Various Datatypes using type()
def Ques11():
    a = "Malhar Pawar"
    b = 2007
    c = 3.14
    d = 5 + 10j
    e = [1,2,3,4,5]
    f = (1,2,3,4,5)
    g = {1,2,3,4,5}
    h = True
    i = None

    #Display
    print(f"A = {type(a)}")
    print(f"B = {type(b)}")
    print(f"C = {type(c)}")
    print(f"D = {type(d)}")
    print(f"E = {type(e)}")
    print(f"F = {type(f)}")
    print(f"G = {type(g)}")
    print(f"H = {type(h)}")
    print(f"I = {type(i)}")

# Question 12:
# Write a Python Program to demonstrate following assignment operators
def Ques12():
    a = 10      # (=) Operator
    print("Initial Value of A = ", a)
    a += 1      # (+=) Operator
    print(" After using += Operator, A = ", a)
    a -= 1      # (-=) Operator
    print(" After using -= Operator, A = ", a)
    a *= 2      # (*=) Operator
    print(" After using *= Operator, A = ", a)
    a /= 4      # (/=) Operator
    print(" After using /= Operator, A = ", a)

# Question 13:
# Write a program to demonstrate following Comparison Operators
def Ques13():
    a,b = 10,20
    print(f"A = {a}\tB = {b}")
    print("== Operator: ", a==b)
    print("!= Operator: ", a!=b)
    print("<= Operator: ", a<=b)
    print(">= Operator: ", a>=b)
    print("< Operator: ", a<b)
    print("> Operator: ", a>b)

# Question 14:
# Write a program to demonstrate following Boolean Operators
def Ques14():
    a,b = True,False
    print(f"A = {a}\tB = {b}")
    print("Using and Operator: ", a and b)
    print("Using or Operator: ", a or b)
    print("Using not Operator: ", not b)

# Question 15:
# Write a program to accept and Display Information of a Student
def Ques15():
    #Input
    Roll = int(input("Enter Your Roll Number: "))
    Name = input("Enter Your Name: ")
    Course = input("Enter Your Course Name: ")
    M1,M2,M3 = input("Enter Your Marks in Three Subjects: ").split()
    M1,M2,M3 = float(M1),float(M2),float(M3)

    #Display
    print(f"Roll Number: {Roll}\nName: {Name}\nCourse: {Course}")
    print(f"Marks in\nPhysics: {M1:.2f}\nChemistry: {M2:.2f}\nMaths: {M3:.2f}")
    print(f"Total Marks: {(M1+M2+M3):.2f}\nAverage Marks: {((M1+M2+M3)/3):.2f}")

#Main Function:
def main():
    Ques1()
    Ques2()
    Ques3()
    Ques4()
    Ques5()
    Ques6()
    Ques7()
    Ques8()
    Ques9()
    Ques10()
    Ques11()
    Ques12()
    Ques13()
    Ques14()
    Ques15()

if __name__ == "__main__":
    main()