# 复合类型

复合类型是基于基本的整型和浮点类型创建的，影响最为深远的复合类型是类。

**数组**：可以存储多个同类型的值。  
**结构**：可以存储多个不同类型的值。  
**指针**：将数据所处位置告诉计算机的变量。  

## 4.1 数组

数组是一种数据格式，能够存储多个同类型的值。创建数组，可使用声明语句，数据声明指出以下三点：

* 存储在每个元素中的值的类型
* 数组名
* 数组中的元素个数

声明数组的通用格式：

```
typeName arrayName[arraySize];
```

*arraySize*不可以是变量，这个值需要在编译时就已经明确。

c++数组的下标由0开始。

### 数组的初始化规则

```
int cards[4] = {3,5,8,10}; // okay
int hands[4];	// okay
hands[4] = {5,6,7,9};	// not allowed.
hands = cards;	//not allowed.
```

初始化数据时，可以只对数组的一部分进行初始化，编译器会将其他的元素设置为0，因此如果想将数组中所有的元素都初始化为0则非常简单，只需要显式的将第一个元素初始化为0就可以了。

```
int hotelTips[5] = {5.0,2.5};
int totals[500] = {0};
```

### c++11数组初始化方法

c++11将使用大括号的初始化（列表初始化）作为一种通用的初始化方式。

* 初始化数据时，可省略等号（=）

```
double earnings[4] {1.2e4,1.6e4,1.1e4,1.7e4};
```

* 在大括号中不包含任何东西，默认将所有的元素设置为零

```
unsiged int counts[10] = {};
float balances[100] {};
```

* 列表初始化禁止缩窄转换

```
long plife[] = {25,92,3,0}; // not allowed
char slife[4] = {'h','i',1122011,'\0'} // not allowed
char tlife[4] {'h','i',112,'\0'}; // allowed
```


## 4.2 字符串

字符串是存储在内在的连续字节中的一系统字符。c++处理字符串的方式有两种。一种基于数组，一种基于string类库。

存储在连续字节中的一系列字符意味着可以将字符串存储在char数组中，其中每个字符都位于自己的数组元素中。这种风格的字符串具有一种特殊性：以空字符(null character)结尾，空字符被写作：\0,用来标记字符串的结尾。

```
char dog[8] = {'b','e','a','u','x','','I','I'}; // not a string
char cat[8] = {'f','a','t','e','s','s','a','\0'}; // a string
```

这两个都是char数组，但只有第2个是字符串.

但上面的字符串看上去冗长乏味，使用了大量的单引号，且必须加上空字符。还有另外一种称为字符串常量或者字符串字面值的表示方式：

```
char bird[11] = "Mr. Cheeps";
char fish[] = "Bubbles";
```

**注意**

使用字符串常量（使用双引号）不能与字符常量互换

```
char shirt_size = 'S'; // this is fine.
char shart_size = "S"; // illegal type mismatch.
```

在使用cin获取字符串数组中，cin使用了空白（空格、制表符、换行符）来确定字符串的结束位置。

### 每次输入一行字符串

#### 1、面向行的输入: getline()

getline()函数可以读取整行，它使用通过回车键输入的换行符来确定输入的结尾。使用方法是：*cin.getline()* ,该函数有两个参数，第一个参数用来存储输入行的数组的名称，第二个参数是要读取的字符数，如果这个参数是20，那函数最多读取19个字符。

```
cin.getline(name,20);
```

#### 2、面向行的输入：get()

istream类的另一个名为get()的成员函数，该函数有几种变体，其中一种与getline()的工作方式类似。解释参数的方式也相同，并且都读取到行尾。但是get()并不再读取并丢弃换行符，而是将其留在输入队列中。

get()还有一种不带任何参数的变体，调用可读取下一个字符，即使是换行符。

```
cin.get(name,ArSize); // read first line
cin.get();	// read newline
cin.get(dessert,Arsize) // read second line
```

### string 类简介

与使用数组相比，使用string对象更方便，也更安全。从理论上说，可以将char数组视为一组用于存储一个字符串的char存储单元，而string类变量是一个表示字符串的实体。

#### 字符串初始化

c++11允许将列表初始化用于c风格字符串和string对象

```
char first_date[] = {"Le Chapon Dodu"};
char second_date[] {"The Elegant Plate"};
string third_date = {"The Bread Bowl"};
string fourth_date {"Hank's Fine Eats"};
```

#### string类的其它操作

```
strcpy(name1,name2); //copy name2 to name1
strcat(name1,name2); // append contents of name2 to name1
```


## 结构简介

结构是一种比数组更灵活的数据格式，属于用户的自定义类型，而结构的声明定义了这种类型的数据属性，关键字struct

### 结构初始化

与数组一样，c++11也支持将列表初始化用于结构.

```
inflatable duck {"Daphne",0.12,9.98};
```

可以同时完成定义结构和创建结构变量的工作

```
struct perks{
	int key_number;
	char car[12];
} mr_smith,ms_jones;
```

甚至可以初始化以这种方式创建变量

```
struct perks{
	int key_number;
	char car[12];
} mr_glitz = {
	7,
	"Packard"
}
```

但是，将结构定义和变量的声明分开，可以使程序更易于阅读和理解。

## 共用体

共用体（union）是一种数据格式，它能够存储不同的数据类型，但只能同时存储其中的一种类型。

```
union one4all{
	int int_val;
	long long_val;
	double double_val;
};

one4all pail;
pail.int_val = 15; //store an int
cout << pail.int_val;
pail.double_val = 1.38; // store a double,int value is lost
cout << pail.double_val;
```

## 枚举

c++的enum工具提供了另一种创建符号常量的方式 ，这种方式可以代替const，它还允许定义新的类型，但必须严格的限制进行。

```
enum spectrum {red,orange,yellow,gren,blue,violet,indigo,ultraviolet};
```

完成的工作是：让spectrum成为新的类型名称，spectrum被称为枚举，就像struck被称为结构一样;将red,orange,yellow等作为符号常量，它们对应的整数值0~7，这些常量叫做枚举量。

枚举量是常量，可以补提升为int类型，但是int类型不能自动转换为枚举类型。

```
int color = blue; // valid
brand = 3 ; // invalid
color = 3 + red; //valid
```

如果int值是有效的，则可以通过强制类型转换，将它赋值给枚举变量

```
brand = spectrum(3);
```

### 设置枚举量的值

可以使用赋值运算符显式的设置枚举量的值

```
enum bits {one = 1, two = 2, four = 4, eight = 8};
```

指定的值必须是整数，也可以只显式的定义其中一些枚举量的值，第一个枚举量默认为0，后面没有被赋值的枚举量将比其前面的枚举量大1.

## 指针和自由存储空间

& ： 地址运算符，可用于变量。   
* : 间接值或者解除引用运算符，可用于指针。

### 指针的声明和初始化

必须指明指针指向的值的类型。

可以在声明语句中初始化指针。在这种情况下，被初始化的是指针，而不是它指向的值。

```
int higgens = 5;
int * pt = &higgens;
```

这条语句是将pt的值设置为：&higgens。

**在c++中创建指针时，计算机将分配用于存储地址的内存，但不会分配用来存储指针批向的数据的内存。为数据提供空间是一个独立的步骤。**

```
long * fellow;
*fellow = 223323;
```

fellow确实是一个指针，但它指向哪里？ 上述代码没有将地址赋给fellow，那么223323也将不知道存储在哪里，由于fellow没有补初始化，它可能是任何的值。因此一定要在对指针应用解除引用运算符（*）之前，将指针初始化为一个确定的，适当的地址。

### 使用new来分配内存

前面都将指针初始化为变量的地址：变量在编译时分配有名称的内存，而指针只是为可以通过名称直接访问的内存提供了一个别名。

指针的真正用武之地在于，在运行阶段分配未命名的内存以存储值，在这种情况下，只能通过指针来访问内存。

```
int * pn = new int;
```

new int告诉程序，需要适合存储int的内存。new运算符根据类型来确定需要多少字节的内存。然后是找到这样的内存，并返回其地址，接下来是将地址赋值给pn,pn是被声明为指向int的指针。而pn是地址。

```
int higgens;
int * pt = &higgens;
```

在这两种情况下（pn,pt），都是将一个int变量的地址赋给了指针。第二种情况下，可以通过名称higgens来访问该int，第一种情况下只能通过该指针进行访问。

为一个数据对象（结构或者基本类型）获得并指定分配内存的通用格式如下：

```
typeName * pointer_name = new typeName;
```

关于指针，需要指出的一点是：new分配的内存块和通常与常规变量申明分配的内存块不同。变量nights和pd的值都存储在称为栈（stack）的内存区域中，而new从被称为堆（heap）或者自由存储区（free store）的内存区域中。

### 使用delete释放内存

```
itn * ps = new int;
...
delete ps;
```

delete之后将会释放ps指向的内存，但不会删除指针ps本身,之后可以将ps重新指向另一个新分配的内存块。

```
int * ps = new int;
delete ps;
int jugs = 5;
int * pi = &jugs;
delete pi; // not allowed,memory not allowed by new
```

delete关键字只能用于用new分配的内存。

### 使用new来创建动态数组


```
int * psome = new int [10];
delete [] psome;
```

**注意：** 不需要delete来释放不是new分配的内存、不要使用delete来释放同一块内存两次、需要使用new[]来为数组分配内存，则应使用delete[]来释放，对空指针应用delete是安全的。

new返回的是第一个数组元素的地址，c++将数组名解释为地址。

### 使用new创建动态结构

运行时创建数组优于在编译时创建数组，对于结构也是如此。需要在程序运行时为结构分配所需的空间，也可以使用new运算符来实现。

```
inflatable * ps = new inflatable;
```

比较棘手的是访问成员。创建动态结构时，不能将成员运算符句点用于结构名，因为这种结构没有名称，只是知道它的地址。c++专门为这种情况提供了一个运算符：箭头成员运算符（->）.

```
stuct thins{
	int good;
	int bad;
}

tings grubnose = {3,453};
tings * pt = &grubnose;
cout << pt->good;
```

### 自动存储、静态存储和动态存储

根据用于分配内存的方法，c++有3种管理数据内存的方式：自动存储、静态存储和动态存储。

* 自动存储    

在函数内部定义的常规变量使用自动存储空间，被称为自动变量（automatic variable），通常存储在栈中。

* 静态存储

静态存储是整个程序执行期间都存在的存储方式。使变量成为静态的方式有两种：一种是在函数外面定义它 ;另一种是在声明变量时使用关键字static.

* 动态存储

使用new和delete运算符提供了一种比自动变量和静态变量更灵活的方法。该部分存储在自由存储空间（free store）或者堆（heap）中。

## 数组的替代品

模板类：vector，也是一种动态数组，也是使用new和delete来管理内存的，但这种工作是自动完成的。

vector类的功能比数组强大，但付出的代价是效率稍低。如果需要固定长度的数组，使用数组更佳，但代价是不那么方便和安全。c++11新增了模板类：array.