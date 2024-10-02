# Object Oriented Programming in C++

## Difference between Object Oriented and Procedure Oriented programming


| Feature                           | Procedure-Oriented Programming (POP)                                  | Object-Oriented Programming (OOP)                                          |
|-----------------------------------|-----------------------------------------------------------------------|----------------------------------------------------------------------------|
| **Program Structure**             | Program is divided into small parts called functions                  | Program is divided into parts called objects                               |
| **Primary Focus**                 | Importance is given to functions and the sequence of actions          | Importance is given to the data rather than procedures or functions        |
| **Approach**                      | Follows a Top-Down approach                                           | Follows a Bottom-Up approach                                               |
| **Access Specifiers**             | Does not have access specifiers                                       | Supports access specifiers like Public, Private, Protected                 |
| **Data Flow**                     | Data can move freely from function to function                        | Objects can communicate with each other through member functions           |
| **Adding Data and Functions**     | Adding new data and functions is not easy                             | OOP provides an easy way to add new data and functions                     |
| **Global Data**                   | Most functions use global data for sharing, accessible freely         | Data cannot move easily; it can be kept public or private, allowing controlled access |
| **Data Security**                 | No proper way of hiding data, making it less secure                   | OOP provides data hiding, making it more secure                            |
| **Overloading**                   | Overloading is not possible                                           | Overloading is possible through Function Overloading and Operator Overloading |
| **Examples of Languages**         | Examples include C, VB, FORTRAN                                       | Examples include C++, Java, Python                                         |

> _Top Down Approach_ : Start with the high level design and then break it down into the smaller more manageable parts used in Procedure Oriented Programming.

> _Bottom Up Approach : _Starts by developing basic components and then combines to form the complete system._ _



### Principles of OOPs are 
1. Encapsulation 
2.  Data abstraction
3.  Polymorphism 
4.  Inheritance 
5.  Dynamic binding 
6.  Message passing


### Benefits of Object Oriented Programming
- Reusability :
- Reduced Complexity of the code and problem
- Easy to maintain and upgrade
- Modifiability
- Data hiding and protection


## Basics of C++
- Data types 
    - Divided into 3 types : 
        - Primary datatype
        - Derived datatype 
        - User defined datatype
- Tokens 
    - Identifiers : name given to the various elements such as variable function and arrays.
    - Variables : A named memory location is called variable.
    - Keywords : reserved words for the language and have the predefined meaning in that particular language and cannot be used as an identifier.
    - Constants : value that do not change during the execution of program.  
    - Operators : symbol which represents a particular operation that can be performed on the data. An _operand_ is the object on which an operation is performed. An _expression_ is a sequence of operands and operators that reduces to a single value.
        - Classification of operators in C++.
            - Arithmetic Operators
            - Relational Operators
            - Logical Operators
            - Assignment Operators
            - Increment and decrement Operators
            - Conditional Operators / Ternary Operators
            - Bitwise Operators
            - unary Operator
            - Special Operators - size of and comma ( , ) operator.
> Todo: special operators in cpp such as endl, setw, scope resolution operator etc.



## Classes and Objects
### Class : 
- It is a blueprint or the prototype that defines the variable and functions common to all the objects of certain kind. 
- It is a User defined datatype or Abstract Data Type ( ADT ).
- The data components of class are called as _**data members**_ and functions that manipulate the data are called as _**member functions**_ 
example : 

1. Car manufacturing factory making a car with having one blueprint defining the chassis, shape, size and produce all the cars ( objects ) which are objects.
2.  Academic Information system management - grouping of all the properties of the teacher/student ( entity ) . 
syntax:

```
class ClassName{
  //properties
  //method function
};
```
### Access Modifiers 
Access specifier or access modifiers are the labels that specify type of access given to members of a class. These are used for _data hiding _and are also called as _visibility modes_.

- private : data and methods cannot be accessed from other functions outside the class. It can only be accessed by the functions declared within the class. 
> By default all the attributes and methods are private by default.

- Public : data and methods can be accessed from other functions out side the class.
- Protected : data and methods accessible inside class and to its derived class. 


```
class ClassName{
  
  Access specifiers:
    // data members and member function
  Access Specifiers:
    //data mebers and member functions
};
```
> **Dot Operator : **It is used to access members of the class 

```
class Student{
  public: 
    int data;
    string name;
};

int main(){
  Student st;
  st.data = 5;
  st.name = "new name";
  return 0;
}
```
### Objects 
- Instance of a class is called as object.
### Setter : 
function used to modify the private data inside the class

### Getter function 
function used to get the private data from the class.



4 pillars of OOPs 

- Encapsulation
- Abstraction
- Inheritance
- Polymorphism
## Scope Resolution Operator
- Visibility or availability of a variable in a program is called as scope.
- There are 2 types of scope 
    - Local scope 
    - Global Scope
> Scope resolution operator is used :: to define the scope 

> Note : accessing a global variable inside the function ::variable_name

- Scope resolution operator(::) is used to define a function outside a class.
```
data_type class_name::function_name(arguement1,arguement2){}
```


### Inline Functions
- An inline function is a function that is expanded in line when it is invoked.
- It is defined by using key word `inline`.
- It reduces the cost of calling a function whose objective is to save space and time.
>  One solution to this problem is to use **macro definitions**, known as macros. Preprocessor macros are popular in C. The major drawback with macros is that they are not really functions and therefore, the usual error checking does not occur during compilation.

```
inline data_type function_name{
  function body;
}
```
- It is sent as a request to the compiler and not as commands so compiler may ignore the requrest when the function has too many lines of code or there is a return value with switch, loop or no return statement and is treated as normal function.
## Encapsulation 
Encapsulation is the wrapping up of data and members function in a single unit called class.

