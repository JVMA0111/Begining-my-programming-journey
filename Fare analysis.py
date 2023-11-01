
# Online Python - IDE, Editor, Compiler, Interpreter

xh=input("Enter hours:")
xr=input("Enter rate per hour:")
n=float(xh)
y=float(xr)

if n>40:
    print("Overtime")
    reg=40.0*y
    otp=(n-40.0)*(y*1.5)
    pay=reg+otp
    print(pay)
else:
    reg=n*y
    print("Regular:")
    print(pay)