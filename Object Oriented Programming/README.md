
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
2. Data abstraction
3. Polymorphism 
4. Inheritance 
5. Dynamic binding 
6. Message passing


### Benefits of Object Oriented Programming
- Reusability 
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
    - **Identifiers :** name given to the various elements such as variable function and arrays.
    - **Variables :** A named memory location is called variable.
    - K**eywords :** reserved words for the language and have the predefined meaning in that particular language and cannot be used as an identifier.
    - **Constants :** value that do not change during the execution of program.  
    - **Operators :** symbol which represents a particular operation that can be performed on the data. An _operand_ is the object on which an operation is performed. An _expression_ is a sequence of operands and operators that reduces to a single value.
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
2. Academic Information system management - grouping of all the properties of the teacher/student ( entity ) . 
syntax:

``` cpp
class ClassName{
  //properties
  //method function
};
```
### Access Modifiers 
Access specifier or access modifiers are the labels that specify type of access given to members of a class. These are used for _data hiding _and are also called as _visibility modes_.

- **private :** data and methods cannot be accessed from other functions outside the class. It can only be accessed by the functions declared within the class. 
> By default all the attributes and methods are private by default.

- **Public :** data and methods can be accessed from other functions out side the class.
- **Protected :** data and methods accessible inside class and to its derived class. 


```cpp
class ClassName{
  
  Access specifiers:
    // data members and member function
  Access Specifiers:
    //data mebers and member functions
};
```
> **Dot Operator** It is used to access members of the class 

```cpp
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

### Getter function :
function used to get the private data from the class.



## 4 pillars of OOPs 

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

```cpp
data_type class_name::function_name(arguement1,arguement2){}
```


## Inline Functions
- An inline function is a function that is expanded in line when it is invoked.
- It is defined by using key word `inline`.
- It reduces the cost of calling a function whose objective is to save space and time.
>  One solution to this problem is to use **macro definitions**, known as macros. Preprocessor macros are popular in C. The major drawback with macros is that they are not really functions and therefore, the usual error checking does not occur during compilation.

```cpp
inline data_type function_name{
  function body;
}
```
- It is sent as a request to the compiler and not as commands so compiler may ignore the request when the function has too many lines of code or there is a return value with switch, loop or no return statement and is treated as normal function.


## Static Class Members
It is the property of the class and not the object property.

Characteristic of static data members :

- `Initialized to zero` when the first object of its class is created. 
- `Only one copy`of that member is created for the entire class and is shared by all the objects of that class.
- Visible only within class but lifetime is the entire program
## Static Member Function
Properties of static member function

- Can only access to only other static members declared in the same class.
- A static member is to be called using the class name as 
`class_name :: static_function_name;` 


> Defined by keyword _**static**_

```cpp
class employee{
  int employeeId;
  static int count; 
  public:
    void setter(int id){
      this->employeeId = id;
      count++;
    }
    
    void getter(){
      cout<<"The employee Id is :"<<employeeId <<" and the employee count is :"<<count<<endl;
    }
    
    static void showCount(void){
      cout<<"The count is :"<<count<<endl;
      //It cannot access the employeeId
    }
}

int employee :: count = 100 //we can only intialise to a number other than here 
// the declaration should be done inside the class 

int main(){
  employee employee1;
  employee::showCount();
}
```
> Use case : to number class objects



## Objects as Function Argument
1. Pass by value
2. Pass by reference 
### Pass by value
- A copy of the object is sent to the function and assigned to the object of called function. Both formal and actual copies are stored in different memory location. 
### Pass by Address
-  Address of the object is sent as argument to function. Here ampersand(&) is used as address operator and arrow (->) is used as de referencing operator. 
- If any change made to formal arguments then there is a change to actual arguments.
### Pass by reference
- A reference of object is sent as argument to function. 
- Reference to a variable provides alternate name for previously defined variable. If any change made to reference variable then there is a change to original variable. 
> todo: passing objects as a parameter : complex number example



## Friend Function
The private members cannot be accessed outside the class, but a non member function can be made to access private members of class by making the function friend to the class.

- It is declared within a class and is defined outside the class.
- It does not require scope resolution operator for defining. 
- It can access private members of a class. 
- It is declared by using keyword `friend` 
- It is not in the scope of the class to which it has been declared as friend.  Since it is not in the scope of the class, it cannot be called using the object of that class. It can be invoked like a normal function without the help of any object. 
- Unlike member functions, it cannot access the member names directly and has to use an object name and dot membership operator with each member name. 
- It can be declared either in the public or private part of a class without affecting its meaning. 
-  Usually, it has the objects as arguments.


## Friend Class
- A function in the other class can also be made a friend of the given class. There could be also a situation where we require more than one method to be the friend in such a case we can make a entire class friend of another class. 
- When we create a friend class then all the members of the friend class also became the friend of the other class. 
> This requires the condition that the friend becoming class must be first declared or defined **( forward declaration )**.


```cpp
#include <iostream.h>
class calcuation; //forward declaration
class complex{
  friend class calculation;
  int a,b;
  public:
    void setData(int x,int y){
      this->a = x;
      this->b = y;
    }
    void getData(){
      cout<<a<<" + "<<b<<" i"<<endl;
    }
};

//a friend class
class calculation{
  int sum;
  public:
    int ComplexRealSum(complex obj1,complex obj2){
      return (obj1.a + obj2.a);
    }
    int ComplexSum(complex obj1,complex obj2){
      return (obj1.b + obj2.b);
    }
  
};
```
## Constructor 
- It is a special member function which enables an object to initialize itself when it is created
- It basically removes the need of setter which requires calling after creating the class.
> Definition : A constructor is a special member function whose task is to initialize the objects of its class.



Some special things about constructor

-  It is special because its `name is the same name as the class name` 
-  They should be `declared in the public section.` 
- They are `invoked automatically` when the objects are created. 
- They `do not have return type`, not even void.
- they can have default arguments.
- They `cannot be inherited`, though a derived class can call the base class constructor.
- We cannot _refer to their addresses_.
> It is called constructor because it constructs the values of data members of the class.

```cpp
class car{
  int price;
  char model;
  
  //constructor
  car(int price,char model = 'A){
    this->price = price;
    this->model = model;
  }
};
```
### Types of constructor
1. **Default Constructor** 
-  A constructor that accepts no parameters is called the default constructor. 
```cpp
class item{
  int m,n;
  public:
    item(){
      m = 10;
      n = 5;
    }
};
```
2.**Parameterized Constructor** 

- The constructors that take parameters are called parameterized constructors. 
* When a constructor has been parameterized, the object declaration statement such as `item t` may not work. We must pass the initial values as arguments to the constructor function when an object is declared.

* It can be done in two case : 

  *  Implicit call : item t(20,30)

  *  explicit call : item t = item(20,30)



2. **Copy Constructor**

- A copy constructor is used to declare and initialize an object from another object.
- The process of initializing through a copy constructor is known as copy initialization.
  

> `obj2=obj1` will not invoke copy constructor. obj1 and obj2 are objects, assigns the values of obj1 to obj2. But `class_name obj1 = obj2` invokes the copy constructor. 

- When there is no copy constructor is found `compiler gives its own copy constructor`.

```cpp
class item{
  int a;
  public:
    item(){} //default constructor
  
    item(int x){ //paramterized constructor
      this->a = x; 
    }
    
    item(item &obj){ //this is copy constructor
      a = obj.a;
    }
};

int main(){
  item i1 = item(5),i2;
  item i3 = item(i1); //does the intialisation with i1
  i2 = i1 //however copy constructor is not called here 
}
```
4. **Multiple constructor or constructor overloading**

- Multiple constructors can be declared in a class.
- It is called based on the parameters.

```cpp
class account{
  int principle;
  int year;
  float interest; //interest in percentage
  float returnvalue; //interest 
  
  public:
    account(){} //default constructor;
    account(int principle,int year,int r);
    account(int principle,int year,float r);
    void show();
};

account:: account(int principle,int year,int r){
  this->principle = principle;
  this->year = year;
  this->interest = float(r)/100;
  returnvalue = principle;
  for(int i = 0;i<year;i++){
    returnvalue = returnvalue * (1 + r);
  }
}

account:: account(int principle,int year,float r){
  this->principle = principle;
  this->year = year;
  this->interest = r;
  returnvalue = principle;
  for(int i = 0;i<year;i++){
    returnvalue = returnvalue * (1 + r);
  }
  
  void account ::show(){
    cout<<"The retunr after "<<year<<" is ₹"<<returnvalue<<endl;
  }
  
}
```
## Destructor
- Destructor is a special member function whose name is same as the class name but it is proceeded by a tilde ( ~ ).
- Its main function is used to destroy the objects created by a constructor. 
- It does not take any argument nor does it return any value.
- It is invoked implicitly by the compiler upon exit from the program.
- Should be defined in the public section only.

```cpp
class marksSheet{
  int science;
  int maths;
  public:
    marksSheet(int s,int m){
      this->science = s;
      this->maths = m;
    }
    
    void show(){
      cout<<"Science marks is "<<science<<" Math marks is "<<maths<<endl;
    }
    
    ~marks(){
      cout<<"Destructor called"<endl;
    }
};

int main(){
  cout<<"In main block"<<endl;
  marksSheet stud1(20,20);
  {
    cout<<"In the new block"<<endl;
    marksSheet stud2(3,10);
    cout<<"Leaving the block"<<endl;
  }
  cout<<"Leaving main block"<<endl;
}
```
## Inheritance
- The mechanism of deriving a new class from an old one is called inheritance or derivation.
- It emphasis the feature of `Reusability` in OOPs,  reusing tested and debugged class will help to save time and money.
- The existing class is called as `Base Class` .
- The new class which is inherited is called `Derived Class.` 
### Types of Inheritance 
![Types of inheritance pictures](https://www.careerride.com/images/Solved-Paper/different-types-of-inheritance.png)

1. **Single inheritance**
    1. one derived class inherits from only one base class. It is the most simplest form of Inheritance.
   
```cpp
class base_class{
  public:
     int a;
     int b;
};

class derived_class:public base_class{
  public:
    int c;
    void add(){
      c = a+b;
    }
  
};
```
> Example : A car (child class) inherits general features from a vehicle (parent class), such as wheels, engine, and steering.



2. **Multilevel inheritance**

-  In this type of inheritance the derived class inherits from a class, which in turn inherits from some other class. The Super class for one, is sub class for the other.
  


```cpp
class animal{
  
};

class mammal : public animal{
  
};

class cow: public mammal{
  
};
```
3. **Multiple Inheritance**

- In this type of inheritance a single derived class may inherit from two or more than two base classes.
  
```cpp
class animal{
  
};

class isFly{
  
};

class bird : public animal, public isFly{
  
};

```
4. **Hierarchical Inheritance**

- Multiple sub classes are derived from the same base class
```cpp
class animal{
  
};

class mammal: public animal{};
class bird:public animal{};
class insects : public animal{};
```
4. **Hybrid Inheritance**

- Hybrid inheritance is combination of two or more inheritances such as single, multiple, multilevel or Hierarchical inheritances. 


### Visibility modes in Inheritance 
![](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSvG3ergQ2etjVoJVJKi-nnng6A6RxtJ3RPrQ&s)



- When a base class is `privately inherited` by a derived class, _public members of the base class can only be accessed by the member functions of the derived class_. 
- When a base class is `protected inherited` by a derived class, public members of the base class can only be accessed by the member functions of the derived class. If private members of base class are to be inherited to derived class then declare them as protected.
- When the base class is n`publicly inherited`, public members of the base class is publicly inherited, public members of the base class become public members of the derived class and therefore they are accessible to the objects of the derived class
> **Note :** private members of base class are inaccessible to the objects of the derived class



### Ambiguity resolution in Inheritance
- Consider the case when there is a class `derived-class`  which has inherited from the two base class `base-class1`  and `base-class2` , let us suppose we have 2 public  in base classes defined with the same name as `display_function` .When `display_function` is called in the derived-class there exist a ambiguity so as to call which function? 
- In that case the compiler throws an error. 
- In such a case you need to use scope resolution operator to resolve the ambiguity. 
> But when the derived class has its own definition of the class which it has also inherited from the base class then that particular function is  _**override**_ and the derived class function is run. 



## Virtual Base Class
A **Virtual Base Class** in C++ is used to prevent multiple instances of a base class from being inherited when using multiple inheritance.

When a class inherits from two or more classes, and these classes have a common base class, it can lead to an ambiguity problem and displays ambiguity error.

```cpp
class A {
public:
    void show() { 
        std::cout << "Class A" << std::endl; 
    }
};

class B : virutal public A { };
class C : virtual public A { };

class D : public B, public C { };
```
By making the base class a **virtual base class**, you ensure that only one instance of the base class is inherited, no matter how many derived classes are inheriting from it.

- This technique is commonly used in **diamond inheritance** problems.
#### A bigger example 
```cpp
#include <bits/stdc++.h>
using namespace std;

//object oriented programming 
class Student{
    protected:
        int roll;
    public:
        void setr(int);
        void display(void);
};

void Student:: setr(int roll){
    this->roll = roll;
}

void Student:: display(){
    cout<<"student roll number is : "<<roll<<endl;
}

class Theory: virtual public Student{
    public:
    int math;
    int science;
    public:
        void set(int,int);
        void display(void);
};

void Theory:: set(int m,int s){
    this->math = m;
    this->science = s;
}

void Theory::display(){
    cout<<"The marks is : "<<math<<" "<<science<<endl;
}

class Practical: virtual public Student{
    public: 
    int mathp;
    int sciencep;
    public:
        void setp(int,int);
        void display(void);
};

void Practical:: setp(int m,int s){
    this->mathp = m;
    this->sciencep = s;
}

void Practical::display(){
    cout<<"The marks is : "<<mathp<<" "<<sciencep<<endl;
}

class Result : public Theory, public Practical{
    int show;
    public:
        void showMarks(){
            cout<<mathp+math<<" "<<sciencep+science<<endl;
        }
};

int main() {
	Result p1;
	p1.setr(4); //throws an error. 
	p1.set(10,10);
	p1.setp(10,10);
	p1.showMarks();
	
}
```
## Memory Management
An object is created using new operator and delete performs the task of deallocating the memory.

> A data object created inside a block with new, will remain in existence until it is explicitly destroyed by using delete



```cpp
pointer-variable = new data-type;

eg. int *p = new int(value);
eg. int *p = new int[5]; //allocate memeory of 5 integer size 
```
```cpp
delete pointer-variable;

eg. delete[] pointer-variable;
```
### Pointer to the object
```cpp
#include<iostream>
using namespace std;

class Complex{
  public:
   int c1,c2;
   void setData(int);
};

int main(){
  //different way of creating the objects
  Complex obj1;
  obj1.setData(5);
  
  //second way -> through the pointer
  Complex obj2;
  Complext* ptr = &obj2;
  (*ptr).setData(5);
  
  //third way -> using new keyword
  Complex* ptr2 = new Complex;
  ptr2->setData(5); //using ARRAY OPERATOR
  
  
  //similarly we can use array of the objects 
  Complex *ptr3 = new Complex[5];
  
  //to read the input by iterating through the ptr3 pointed at the first block
  for(int i=0;i<5;i++){
    ptr3->setData(i);
    ptr3++;
  }
}
```
### This operator 
`this`  is a keyword which is a pointer which points to the object which invokes the member function. 

- It is also used when you need to return the object. 


### Constructor in derived classes 
- We can use constructors in derived classes in C++
-  In case class constructor does not have any arguments, there is no need of
any constructor in derived class.
- But if there are one or more arguments in the base class constructor,
derived class need to pass arguments to the base class constructor
-  If both base and derived classes have constructors, base class constructor
is executed first.
- multiple inheritance, base classes are constructed in the order in which
they appear in the class declaration
-  multilevel inheritance, the constructors are executed in the order of
inheritance
• `The constructors for virtual base classes are invoked before an
nonvirtual base class` 

- If there are multiple virtual base classes, they are invoked in the order
declared.
- Any non-virtual base class are then constructed before the derived
class constructor is executed.
### Example for multiple inheritance 
```cpp
#include<iostream>
using namespace std;

class A{
  int a1,a2;
  public:
    A(){} //if there is default constructor then no worries, it will be called
    A(int a1,int a2){
      this->a1 = a1;
      this->a2 = a2;
      cout<<"class A constructor"<<endl;
    }
};

class B: public A{
  int b1,b2;
  public:
    B(int a1,int a2,int b1,int b2):A(a1,a2){
      this->b1 = b1;
      this->b2 = b2;
      cout<<"Class B constructor"<<endl;
    }
};

class C: public B{
  int c;
  public:
    C(int a1,int a2,int b1,int b2,int c):B(a1,a2,b1,b2){
      this->c = c;
      cout<<"Class C constructor"<<endl;
    }
};

int main(){
  //when calling the object we need to pass all the arguements for the a,b as well as c
  //even tho a has default constructor so it does not matter even if we dont pass any arguemnt for a
  //but we need to pass for b
  //first A is caled then B nd then C
  C objC(1,2,3,4,5);
}

```

Example for the multiple inheritance
```cpp

#include<iostream>
using namespace std;

class A{
  int a1,a2;
  public:
    A(){} //if there is default constructor then no worries, it will be called
    A(int a1,int a2){
      this->a1 = a1;
      this->a2 = a2;
      cout<<"class A constructor"<<endl;
    }
};

class B{
  int b1,b2;
  public:
    B(int b1,int b2){
      this->b1 = b1;
      this->b2 = b2;
      cout<<"Class B constructor"<<endl;
    }
};

//if public B is defined before public A, then B is called then A is called
class C: public A,public B{
  int c;
  public:
    C(int a1,int a2,int b1,int b2,int c):B(b1,b2),A(a1,a2){
      this->c = c;
      cout<<"Class C constructor"<<endl;
    }
};

int main(){
  //when calling the object we need to pass all the arguements for the a,b as well as c
  //even tho a has default constructor so it does not matter even if we dont pass any arguemnt for a
  //but we need to pass for b
  //first A is caled then B nd then C
  C objC(1,2,3,4,5);
}
```
 
## Intialisation List 
- An **initializer list** is a special syntax used in constructors to initialize member variables of a class before the constructor's body executes. 
- It provides a way to directly initialize class members using a colon (`:`) followed by the list of initializations. This is particularly useful for initializing const members, reference members, or base class constructors that require parameters.


```cpp
ClassName::ClassName(parameters) : member1(value1), member2(value2) {
    // Constructor body (optional)
}
```
> The variable declared first is initialized first.



```cpp
class Test{
  int a;
  int b;
  
  public:
    Test(int i,int j):a(i),b(a+j){ //this works perfectly well
      cout<<"Constructor is called"<<endl;
    }
    
    /*
    Test(int i,int j):b(i),a(b+j){ //this doesn't works perfectly well
      cout<<"Constructor is called"<<endl;
    }
    because first a is assigned and then b even though we write b before a 
    */
  
};
```

# Polymorphism
**Polymorphism** is the ability of a function, object, or operator to _**behave in different ways**_ based on the context. It allows the same entity (like a function or an operator) to act differently for different types of inputs or objects. Polymorphism plays a key role in making the code more modular, flexible, and reusable, as it allows defining one interface and having multiple implementations.

### Types of Polymorphism in C++
1. **Compile-time Polymorphism (Static Polymorphism):**
    - This type of polymorphism is resolved at compile time.
    - It is typically achieved through **function overloading** and **operator overloading**.
    - Function overloading allows functions to have the same name but differ in **the number or types of parameters.**
    - Operator overloading allows the same operator to behave differently with different data types.
2. **Run-time Polymorphism (Dynamic Polymorphism):**
    - This type of polymorphism is resolved at runtime.
    - It is mainly achieved through **inheritance** and **virtual functions**.
    - When a function is declared as `virtual`  in the base class, C++ will decide at runtime which function to call based on the type of the object, even if the object is referenced through a base class pointer.


## Compile time polymorphism
- The information is known to the compiler at the compile time and compiler is able to select the appropriate function for a particular call at the compile time itself. This is called **Early Binding** or **Static Binding** or **Static Linking**. Also known as compile time polymorphism. Early binding means that an object is bound to its function call at the compile time.
### How does it work?
1. Source Code Analysis (Parsing & Semantic Analysis).
2. **Function Table Construction:** As part of the compilation, the compiler builds a table of all functions, resolving names, types, and function signatures for each class.
3. **Function Call Resolution:** When a function is invoked on an object, the compiler looks at the type of the object, and using the function signature, determines the address of the function to call.
4. **Binary Code Generation:** After resolving function calls and other references, the compiler generates the actual machine code. In the case of static binding, the machine code contains direct calls to the memory addresses of the functions.


Multiple ways to implement this : 

1. **Changing the number of argument**
```cpp
int add(int a,int b,int c);
int add(int a,int b);
```
2. **Changing the type of argument.**

```cpp
int add(int a,int b);
double add(double a,double b);
```
3. **Changing the order of the argument.**

```cpp
void display(int a,char b,float c);
void display(char a,int b,float c);
```


### Operator Overloading
- C++ allows to specify more than one definition for an operator in the
same scope, which is called operator overloading
- Almost any operator can be overloaded in C++. However there are few
operator which can not be overloaded. Operator that are not overloaded are
follows-
    1. scope resolution operator.
    2. sizeof operator
    3. member selector - (.)
    4. ternary operator (?:)
    5. member pointer selector.


### Binary operator and unary operator overloading 
```cpp
class Complex{
  int real,img;
  public:
     Complex(){
       real = 0;
       img = 0;
     }
     
     Complex(int r,int i){
       this->real = r;
       this->img = i;
     }
     
     void print(){
      cout<<real<<" + "<<img<<"i"<<endl;
    }
    
    //overloading the operator
    //it is preceded by the keyword operator and the operator to overload and 1 arguement for the binary operator and  for the unary operator has 0 arg
    Compelx operator +(Complex c){
      Complex temp;
      temp.real = real + c.real;
      temp.img = img + c.img;
      return temp;
    }
    
    //preincrement
    void operator ++(){
      real++;
      img++;
    }
    
    //post increment
    void operator ++(int){
      ++real;
      ++img;
    }
  
};

int main(){
  Complex c1(4,5);
  Complex c2(5,7);
  
  Complex c3;
  c3 = c1 + c2; //it is same as the c1.add(c2);
  c3.print()
}
```


### Base pointer to the derived object 
```cpp
#include <bits/stdc++.h>
using namespace std;

class Base{
    private:
        int var_base_pri;
    public:
        int var_base_pub;
        virtual void display(){
            cout<<"The base class display which displays the value : "<<var_base_pri<<" "<<var_base_pub<<endl;
        }
};


class Derived : public Base{
    int var_derived_pri;
    public:
        int var_derived_pub;
        void display() override {
            cout<<"The derived class display which displays the values "<<var_derived_pri<<" "<<var_derived_pub<<endl;
        }
};

int main() {
	Base obj_base;
	Derived obj_der;
	
	Base *ptr_base;
	Derived *ptr_der;
	
	//binding the derived pointer with the derived class and base pointer with the base class is the usual way.
	//what is that we are now supposed to observes what happens when we bind base pointer with the derived object;
	ptr_base = &obj_der; 
	//ptr_base->var_base_pri = 5; //i cannot access the private members of the base class even though i have the base class pointer.
	ptr_base->var_base_pub = 10; //i can access this
	
	//i cannot even access the members of the derived class even though i have pointed to the derived class object with the base class pointer
	//ptr_base->var_derived_pub = 5;
	//ptr_base->var_derived_pri = 6;
	ptr_base->display(); //displays the base class display. 
	//when virtual function is used the derived class functions are used.
	
	//this is not even possible as i cannot convert the bse to the derived
	//ptr_der = &obj_base;


} 
```
#### Extra Material 
- A **pointer to a base class** can point to a derived class object (this is known as **upcasting**), but in such cases, it will only have access to the base class members, not the derived class-specific members.
- A **pointer to a derived class** can only point to a derived class object (or its subclasses). It will have access to both the base class members and the derived class members.
- **Pointer Type Matters**:
When you create a base class pointer and assign it the address of a derived class object, the pointer itself still thinks it's pointing to an object of type `Base` . Even though it's physically pointing to a `Derived`  object, the compiler resolves function calls based on the pointer type, which is `Base` , not `Derived` .
- When the compiler sees `basePtr->display();` , it notices that `basePtr`  is a pointer to a `Base`  object. The compiler then binds the `show()`  function to the `Base::show()`  function because the pointer type is `Base*` . The derived class's `show()`  function is completely ignored, even though the actual object is of type `Derived` .
- But WHY ? 
- When you create an object of a derived class, the memory for that object is organized in such a way that the base class portion comes first, followed by the additional members of the derived class. Think of the derived class object as containing a **base class sub-object** plus the additional members of the derived class.
```
[Base portion] [Derived portion]
[baseMember]   [derivedMember]
```
### Base Class Pointer Only References the Base Part
When you have a **base class pointer** pointing to a derived class object, it only references the **base class part** of the object. Even though the memory layout contains the additional members of the derived class, the **base class pointer** is unaware of those extra members.

The key reason for this is **type information**. The base class pointer knows only about the structure of the base class, not the derived class. So, when you access members through the base class pointer, it only knows how to interpret the memory in terms of the base class.

```
Memory layout of a Derived object:
+-----------------+-------------------+
|  Base portion   |  Derived portion   |
| [baseMember]    | [derivedMember]    |
+-----------------+-------------------+

Pointer to Base class:
Base* basePtr = &d;
+-----------------+-------------------+
|  Base portion   |  Derived portion   |
| [baseMember]    | [derivedMember]    |
+-----------------+-------------------+
   ^
   |
  basePtr only knows about this part.
```


Some worthy point to note :

- The virtual functions must be members of some class.
- They cannot be static members.
- They are accessed by using object pointers.
- A virtual function can be a friend of another class. 
- A virtual function in a base class must be defined, even though it may not be used
- We cannot have virtual constructors, but we can have virtual destructors.
- If a virtual function is defined in the base class, it need not be necessarily redefined in the derived class. In such cases, calls will invoke the base function.


****