# 处理数据

## 整形

整形：没有小数部分的数字。整数有很多，但如果将无限大的整数看作很大，则不可能用有限的计算机内存来表示所有的整数。因此，需要根据程序的需求选择最合适的整形。

不同的C++整形使用不同的 *内存量* 来存储整数。使用的内存量越大，可以表示的整数的范围也越大。使用内存越大，范围越宽。

### 分类

计算机内存由一些叫做位(bit)的单元组成。*字节(byte)* 通常指的是8位的内存单元。

1byte = 8bit
1kb = 1024byte
1mb = 1024kb

c++的基本整整按宽度递增的顺序排列是：
*char*、*short*、*int*、*long*、*long long*

由于char类型有些特征，它最常用来表示字符，而不是数字，故先不做介绍。对于其它的基本整型来说，有一些基本的要求：  
short : 至少16位  
int : 至少和short一样长  
long : 至少32位，且至少和int一样长  
long long : 至少64位，且至少与long一样长。  

在我的OS X 10.9中，是8位的内存单元。short占2kb，int占4kb，long占8kb，long long占8kb，即对应的：16位、32位、64位、64位。

头文件climits定义了符号常量来表示类型的限制，

### 初始化方式

```
int uncles = 5;  
int owls = 101;  
int wrens(432);  //c++语言特有的初始化方式
```

#### c++11的初始化方式

还有一种初始化方式，这种方式用于数组和结构。但在c++98中，也可以用于单值。
```
int hamburgers = {26}
```
在c++11中，采用这种方式时，可以使用 **=** 号，也只可以不使用。
```
int emnus{7};
int rheas = {12};
```
其次，大括号内可以不包含任何东西，在这种情况下，变量将初始为零。
```
int rocs = {};
int psychis{};
```

### 无符号类型 unsigned

### char类型

char类型，顾名思义，char类型是专为存储字符而设计的。

### bool类型

布尔变量的值可以是true或者false，c++将非零值解释为true，将零解释为false。
```
bool is_ready = true;
```
字面值true和false都可以通过提升转换为int类型,true被转换为1，而false被转换成0.
```
int ans = true;
int promiss = false;
```

### const限定符

符号的名称指出了常量要表示的内容，如果程序中在多个地方使用同一个常量，则需要修改该常量时，只需要修改一个符号的定义即可。

```
const int MONTHS = 12;
```  

关键字const叫做限定符，因为它限定了声明的定义。创建常量的通用格式为：

```
const type name = value;
```

**注意** ：需要在声明中对const进行初始化！

## 浮点数

浮点数可以表示带小数部分的数字了。

c++提供3种浮点类型：float 、 double 、 long double

对于三种浮点类型的要求是：  
float : 至少32位.  
double : 至少48位，且不小于float。  
long double : 至少和long double一样多。  

>通常float为32位，double为64位，long double为80，96或者128位。


### c++11中的auto声明

c++11中新增了一个工具，让编译器能够根据初始值的类型推断变量的变量.

```
auto n = 100; // n is int
auto x = 1.5; // x is double
auto y = 1.3e12L; // y is long double.
```

## 总结

c++的基本类型分为两组：一组由存储整数的值组成，另一组由存储浮点格式的值组成。整型之间通过存储值时使用的内存量及有无符号来区分。整型从最小到最大依次是：bool、char、signed char、unsigned char、short、unsigned short、int 、unsiged int 、long 、unsiged long以及c++11新增的long long和unsiged long long。

### char和bool在内存上的占用怎么区分呢?

bool类型内存的长度为8位，即（1bytes），只能进行异或操作。
char类型内在的长度也是8位，但可以进行+-*/%和字符操作。

c/c++的编译器中有一个变量表，表的字符字段有（数据类型、变量名、首地址、值），每声明一个变量，就把这个变量的相关信息填进表中，以此来区分char和bool类型。






