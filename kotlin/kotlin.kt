package com.runoob.main

import java.util.*

val a: Int = 1
val b = 1       // 系统自动推断变量类型为Int
val c: Int      // 如果不在声明时初始化则必须提供变量类型
c = 1           // 明确赋值

var a = 1
val s1 = "a is $a" // 模板中的简单名称：

a = 2
val s2 = "${s1.replace("is", "was")}, but now is $a" // 模板中的任意表达式：

fun sum(a: Int, b: Int): Int { return a + b }  // Int 参数，返回值 Int
fun sum(a: Int, b: Int) = a + b
fun sum(a: Int, b: Int): Int = a + b   // public 方法则必须明确写出返回类型
fun printSum(a: Int, b: Int): Unit { print(a + b) }
public fun printSum(a: Int, b: Int) { print(a + b) }  // 如果是返回 Unit类型，则可以省略(对于public方法也是这样)：

fun vars(vararg v:Int){ //可变长参数函数
    for(vt in v){
        print(vt)
    }
}

// 测试
fun main(args: Array<String>) {
    vars(1,2,3,4,5)  // 输出12345
    val sumLambda: (Int, Int) -> Int = {x,y -> x+y}//lambda(匿名函数)
    println(sumLambda(1,2))  // 输出 3
}

//***NULL检查机制
//类型后面加?表示可为空
var age: String? = "23" 
//抛出空指针异常
val ages = age!!.toInt()
//不做处理返回 null
val ages1 = age?.toInt()
//age为空返回-1
val ages2 = age?.toInt() ?: -1

fun parseInt(str: String): Int? {
  // 当 str 中的字符串内容不是一个整数时, 返回 null
}
val x = parseInt("ox100")
val y = parseInt("0x100")
// 直接使用 `x * y` 会导致错误, 因为它们可能为 null.
if (x != null && y != null) { 
	print(x * y) // 在进行过 null 值检查之后, x 和 y 的类型会被自动转换为非 null 变量
}

//***类型检测及自动类型转换
fun getStringLength(obj: Any): Int? {
  // 在 `&&` 运算符的右侧, `obj` 的类型会被自动转换为 `String`
  if (obj is String && obj.length > 0) //还使用!is
    return obj.length
  return null
}

//***区间
for (i in 1..4) print(i) // 输出“1234”
for (i in 4..1) print(i) // 什么都不输出
if (i in 1..10) println(i) // 等同于 1 <= i && i <= 10
for (i in 1..4 step 2) print(i) // 输出“13”,step 指定步长
for (i in 4 downTo 1 step 2) print(i) // 输出“42”
for (i in 1 until 10) println(i) // i in [1, 10) 排除了 10

//***基本数据类型
/*
基本数值类型
Double	64
Float	32
Long	64 123L
Int	    32
Short	16
Byte	8

16 进制以 0x 开头：0x0F
2 进制以 0b 开头：0b00001011
8进制不支持

数据类型
char必需是单引号''包含起来,特殊字符可以用反斜杠转义\t、 \b、\n、\r、\'、\"、\\ 和 \$
编码其他字符要用 Unicode 转义序列语法：'\uFF00'
*/
//可以使用下划线使数字常量更易读
val oneMillion = 1_000_000
val creditCardNumber = 1234_5678_9012_3456L
val socialSecurityNumber = 999_99_9999L
val hexBytes = 0xFF_EC_DE_5E
val bytes = 0b11010010_01101001_10010100_10010010

fun main(args: Array<String>) {
    val a: Int = 10000
    println(a === a) // true，值相等，对象地址相等

    //经过了装箱，创建了两个不同的对象
    val boxedA: Int? = a
    val anotherBoxedA: Int? = a

    //虽然经过了装箱，但是值是相等的，都是10000
    println(boxedA === anotherBoxedA) //  false，值相等，对象地址不一样
    println(boxedA == anotherBoxedA) // true，值相等
    //三个等号 === 表示比较对象地址，两个 == 表示比较两个值大小
}

val b: Byte = 1 // OK, 字面值是静态检测的
val i: Int = b // 错误
val i: Int = b.toInt() // OK
val long = 1L + 3 // Long + Int => Long

//位操作符
/*
shl(bits) – 左移位 (Java’s <<)
shr(bits) – 右移位 (Java’s >>)
ushr(bits) – 无符号右移位 (Java’s >>>)
and(bits) – 与
or(bits) – 或
xor(bits) – 异或
inv() – 反向
*/
// Boolean 类型
/*
|| – 短路逻辑或
&& – 短路逻辑与
! - 逻辑非
*/
fun decimalDigitValue(c: Char): Int {
    if (c !in '0'..'9')
        throw IllegalArgumentException("Out of range")
    return c.toInt() - '0'.toInt() // 显式转换为数字
}
//数组
val a = arrayOf(1, 2, 3) //[1,2,3]
val b = Array(3, { i -> (i * 2) }) //[0,2,4]
//[] 运算符代表调用成员函数 get() 和 set()
println(a[0])    // 输出结果：1
println(b[1])    // 输出结果：2

val x: IntArray = intArrayOf(1, 2, 3) //省去了装箱操作，因此效率更高
x[0] = x[1] + x[2]

val text = """
|多行字符串
|菜鸟教程
|多行字符串
|Runoob
""".trimMargin() // 前置空格删除了

val price = """
${'$'}9.99
""" // 求值结果为 $9.99

val s = "runoob"
val str = "$s.length is ${s.length}" // 求值结果为 "runoob.length is 6"

// 作为表达式
val max = if (a > b) a else b
val max = if (a > b) {
    print("Choose a")
    a
} else {
    print("Choose b")
    b
}
when (x) {
    0, 1 -> print("x == 0 or x == 1")
    in 1..10 -> print("x is in the range")
    in validNumbers -> print("x is valid")
    !in 10..20 -> print("x is outside the range")
    else -> print("none of the above")
}
when { //不提供参数x
    x.isOdd() -> print("x is odd")
    x.isEven() -> print("x is even")
    else -> print("x is funny")
}
val items = setOf("apple", "banana", "kiwi")
when {
    "orange" in items -> println("juicy")
    "apple" in items -> println("apple is fine too")
}
fun hasPrefix(x: Any) = when(x) {
    is String -> x.startsWith("prefix")
    else -> false
}

val items = listOf("apple", "banana", "kiwi")
for (item: Int in items) {
    // ……
}
for (i in items.indices) {
    print(items[i])
} //apple
for ((index, value) in items.withIndex()) {
    println("the element at $index is $value")
} //item at 0 is apple
for (index in items.indices) {
    println("item at $index is ${items[index]}")
} //item at 0 is apple

while (x > 0) {
    println(x--)
}
do {
    println(y--)
} while(y>0)

//任何表达式都可以用标签（label）来标记
loop@ for (i in 1..100) {
    for (j in 1..100) {
        if (……) break@loop
    }
}
//标签限制的 break 跳转到刚好位于该标签指定的循环后面的执行点
//continue 继续标签指定的循环的下一次迭代

fun foo() {
    ints.forEach {
        if (it == 0) return //返回foo
    }
}
fun foo() {
    ints.forEach lit@ {
        if (it == 0) return@lit //从 lambda 表达式中返回
    }
}
fun foo() {
    ints.forEach(fun(value: Int) {
        if (value == 0) return //匿名函数内部的 return 语句将从该匿名函数自身返回
    })
}
return@a 1


interface TestInterFace {
    fun test()
}
open class Person constructor(name: String){
//如果构造器有注解或可见度修饰符，constructor必须and注解和修饰符要放在它之前
    init {
        System.out.print("Name is $name")
    }
    // 次构造函数,用this调用主构造器
    constructor (name: String, age: Int) : this(name) {
        println("Age is $age")
    }
//var person: Person = Person()
    var lastName: String = "zhang"
        get() = field.toUpperCase()   // 将变量赋值后转换为大写
        set
//person.lastName = "wang"
//println("lastName:${person.lastName}")//lastName:WANG
    var no: Int = 100
        get() = field                // 后端变量
        set(value) {
            if (value < 10) {       // 如果传入的值小于 10 返回该值
                field = value
            } else {
                field = -1         // 如果传入的值大于等于 10 返回 -1
            }
        }
//person.no = 9
//println("no:${person.no}")//no:9
//person.no = 20
//println("no:${person.no}")//no:-1
    open var heiht: Float = 145.4f
        private set

    open class Nested {  // 嵌套类
        fun foo() = 2 //val demo = Person.Nested().foo() 
        fun innerTest() {
            var o = this@Person //获取外部类的成员变量
            //为了消除歧义，要访问来自外部作用域的 this，使用this@label
            println("内部类可以引用外部类的成员，例如：" + o.v)
        }
    }// 调用格式：外部类.嵌套类.嵌套类方法/属性
    fun setInterFace(test: TestInterFace) {
        test.test()
    }
    
    open fun study(){       // 允许子类重写
        println("我毕业了")
    }
    companion object { }  // 伴生对象,将被称为 "Companion"
}
fun Person.Companion.foo() {
    println("伴随对象的扩展函数")
}
val Person.Companion.no: Int
    get() = 10 //伴随对象的扩展属性

var test = Test()
//采用对象表达式来创建接口对象，即匿名内部类的实例。
test.setInterFace(object : TestInterFace {
    override fun test() = println("对象表达式创建匿名内部类的实例")
})
/*
abstract    // 抽象类  
final       // 类不可继承，默认属性
enum        // 枚举类
open        // 类可继承，类默认是final的
annotation  // 注解类

private    // 仅在同一个文件中可见
protected  // 同一个文件中或子类可见
public     // 所有调用的地方都可见
internal   // 同一个模块中可见
*/

class Student(name : String, 
              var no : String,
              var score : Int) : Person(name) {//
//子类有主构造函数， 则基类必须在主构造函数中立即初始化。
    //次级构造函数
    constructor(name:String,age:Int,no:String,score:Int):super(name,age){
        //初始化基类时，可以调用基类的不同构造方法
    }
    override fun study(){    // 重写方法
        println("我在读大学")
    }
}

open class A {
    open fun f () { print("A") }
    fun a() { print("a") }
}
interface B {
    fun f() { print("B") } //接口的成员变量默认是 open 的
    fun b() { print("b") }
}
class C() : A() , B{
    override fun f() {
        super<A>.f()//调用 A.f()
        super<B>.f()//调用 B.f()
    }
}
fun main(args: Array<String>) {
    val c =  C()
    c.f();
}

interface Foo { val count: Int }
class Bar1(override val count: Int) : Foo
class Bar2 : Foo { override var count: Int = 0 }

//扩展函数
fun Person.Print(){
    print("名 $name")
}
//扩展函数是静态解析的
open class C{
    fun foo() { println("成员函数") }
}
class D: C()
fun C.foo() { println("扩展函数") }   // 扩展函数 foo
fun D.foo() = "d"   // 扩展函数 foo
fun printFoo(c: C) {
    println(c.foo())  // 类型是 C 类
}
fun main(arg:Array<String>){
    printFoo(D())//输出:c
    var c = C()
    c.foo()//输出:成员函数
}
//若扩展函数和成员函数一致，则使用该函数时，会优先使用成员函数。
fun Any?.toString(): String {
    if (this == null) return "null"
    // 空检测之后，“this”会自动转换为非空类型，所以下面的 toString()
    // 解析为 Any 类的成员函数
    return toString()
}
fun main(arg:Array<String>){
    var t = null
    println(t.toString())//null
}

class D { //扩展接受者
    fun bar() { println("D bar") }
}
class C { //分发接受者
    fun baz() { println("C baz") }
    fun bar() { println("C bar") }
//在 C 类内，创建了 D 类的扩展
    fun D.foo() {
        bar()   // 调用 D.bar
        baz()   // 调用 C.baz
    }
    fun D.foo2() {
        bar()         // 调用 D.bar()，扩展接收者优先
        this@C.bar()  // 调用 C.bar()
    }
    fun caller(d: D) {
        d.foo()   // 调用扩展函数
    }
}
fun main(args: Array<String>) {
    val c: C = C()
    val d: D = D()
    c.caller(d) //D bar
                //C baz
}

open class D {
}
class D1 : D() {
}
open class C {
    open fun D.foo() {
        println("D.foo in C")
    }
    open fun D1.foo() {
        println("D1.foo in C")
    }
    fun caller(d: D) {
        d.foo()   // 调用扩展函数
    }
}
class C1 : C() {
    override fun D.foo() {
        println("D.foo in C1")
    }
    override fun D1.foo() {
        println("D1.foo in C1")
    }
}
fun main(args: Array<String>) {
    C().caller(D())   // 输出 "D.foo in C"
    C1().caller(D())  // 输出 "D.foo in C1" —— 分发接收者虚拟解析
    C().caller(D1())  // 输出 "D.foo in C" —— 扩展接收者静态解析
}

//数据类
data class User(val name: String, val age: Int)
fun copy(name: String = this.name, age: Int = this.age) = User(name, age)//使用该函数复制对象并修改部分属性
fun main(args: Array<String>) {
    val jack = User(name = "Jack", age = 1)
    val olderJack = jack.copy(age = 2)
    println(jack)      //User(name=Jack, age=1)
    println(olderJack) //User(name=Jack, age=2)
    val jane = User("Jane", 35)
    val (name, age) = jane
    println("$name, $age years of age") 
    // prints "Jane, 35 years of age"
}

//密封类
//sealed 不能修饰 interface ,abstract class(会报 warning,但是不会出现编译错误)
//密封类可有子类，但是所有的子类都必须要内嵌在密封类中
sealed class Expr //密封类
data class Const(val number: Double) : Expr()
data class Sum(val e1: Expr, val e2: Expr) : Expr()
object NotANumber : Expr()

fun eval(expr: Expr): Double = when (expr) {
    is Const -> expr.number
    is Sum -> eval(expr.e1) + eval(expr.e2)
    //NotANumber -> Double.NaN
    Expr.NotANumber -> Double.NaN
    // 不再需要 `else` 子句，因为我们已经覆盖了所有的情况
}

//泛型
class Box<T>(t : T) {
    var value = t
} //泛型类
fun <T> boxIn(value: T) = Box(value) //泛型函数
fun <T> doPrintln(content: T) {
    when (content) {
        is Int -> println("整型数字为 $content")
        is String -> println("字符串转换为大写：${content.toUpperCase()}")
        else -> println("T 不是整型，也不是字符串")
    }
} //泛型函数
fun <T : Comparable<T>> sort(list: List<T>) {
    //对泛型的的类型上限进行约束,只有Comparable 的子类型可以替代 T
    //默认的上界是 Any?
// sort(listOf(1, 2, 3)) // OK。Int 是 Comparable<Int> 的子类型
// sort(listOf(HashMap<Int, String>())) // 错误：HashMap<Int, String> 不是 Comparable<HashMap<Int, String>> 的子类型
}
fun <T> cloneWhenGreater(list: List<T>, threshold: T): List<T>{
    //对于多个上界约束条件，用 where 
    where T : Comparable, Cloneable {
      return list.filter(it > threshold).map(it.clone())
    }
}
fun main(args: Array<String>) {
    var boxInt = Box<Int>(10)
    var boxString = Box<String>("it's a string")

    println(boxInt.value) //10
    println(boxString.value) //it's a string
    
    val age = 23
    val name = "string"
    val bool = true

    doPrintln(age)    // 整型,23
    doPrintln(name)   // 字符串,STRING
    doPrintln(bool)   // 布尔型,T 不是整型，也不是字符串
}



型变
Kotlin 中没有通配符类型，它有两个其他的东西：声明处型变（declaration-site variance）与类型投影（type projections）。
声明处型变
声明处的类型变异使用协变注解修饰符：in、out，消费者 in, 生产者 out。
使用 out 使得一个类型参数协变，协变类型参数只能用作输出，可以作为返回值类型但是无法作为入参的类型：
// 定义一个支持协变的类
class Runoob<out A>(val a: A) {
    fun foo(): A {
        return a
    }
}

fun main(args: Array<String>) {
    var strCo: Runoob<String> = Runoob("a")
    var anyCo: Runoob<Any> = Runoob<Any>("b")
    anyCo = strCo
    println(anyCo.foo())   // 输出 a
}
in 使得一个类型参数逆变，逆变类型参数只能用作输入，可以作为入参的类型但是无法作为返回值的类型：
// 定义一个支持逆变的类
class Runoob<in A>(a: A) {
    fun foo(a: A) {
    }
}

fun main(args: Array<String>) {
    var strDCo = Runoob("a")
    var anyDCo = Runoob<Any>("b")
    strDCo = anyDCo
}
//星号投射
//ToDo

//枚举类
enum class Color{
    RED,BLACK,BLUE,GREEN,WHITE
}
enum class Color(val rgb: Int) {
	RED(0xFF0000),
	GREEN(0x00FF00),
	BLUE(0x0000FF)
}
enum class Shape(value:Int){
    ovel(100),
    rectangle(200)
}
enum class ProtocolState {
    WAITING {
        override fun signal() = TALKING
    },

    TALKING {
        override fun signal() = WAITING
    };

    abstract fun signal(): ProtocolState
}
EnumClass.valueOf(value: String): EnumClass  
// 转换指定 name 为枚举值，若未匹配成功，会抛出IllegalArgumentException
EnumClass.values(): Array<EnumClass>        
// 以数组的形式，返回枚举值


//自 Kotlin 1.1 起，可以使用 enumValues<T>() 和 enumValueOf<T>() 函数以泛型的方式访问枚举类中的常量 ：

enum class RGB { RED, GREEN, BLUE }
inline fun <reified T : Enum<T>> printAllValues() {
    print(enumValues<T>().joinToString { it.name })
}
fun main(args: Array<String>) {
    printAllValues<RGB>() // 输出 RED, GREEN, BLUE
}

//对象表达式
fun countClicks(window: JComponent) {
    var clickCount = 0
    var enterCount = 0
//在对象表达中可以方便的访问到作用域中的其他变量
    window.addMouseListener(object : MouseAdapter() {
        override fun mouseClicked(e: MouseEvent) {
            clickCount++
        }

        override fun mouseEntered(e: MouseEvent) {
            enterCount++
        }
    })
    // ……
}
open class A(x: Int) {
    public open val y: Int = x
}
interface B {……}
val ab: A = object : A(1), B {
    override val y = 15
}
val site = object {
    var name: String = "菜鸟教程"
    var url: String = "www.runoob.com"
}
class C {
    // 私有函数，所以其返回类型是匿名对象类型
    private fun foo() = object {
        val x: String = "x"
    }
    // 公有函数，所以其返回类型是 Any
    fun publicFoo() = object {
        val x: String = "x"
    }
    fun bar() {
        val x1 = foo().x        // 没问题
        val x2 = publicFoo().x  // 错误：未能解析的引用“x”
    }
}

object Site {
    var url:String = ""
    val name: String = "kotlin"
}
fun main(args: Array<String>) {
    var s1 =  Site
    var s2 = Site
    s1.url = "www.baidu.com"
    println(s1.url)//www.baidu.com
    println(s2.url)//www.baidu.com
}
//与对象表达式不同，当对象声明在另一个类的内部时，
//这个对象并不能通过外部类的实例访问到该对象，而只能通过类名来访问，
//同样该对象也不能直接访问到外部类的方法和变量。
class Site {
    var name = "baidu"
    object DeskTop{
        var url = "www.baidu.com"
        fun showName(){
            print{"desk legs $name"} // 错误，不能访问到外部类的方法和变量
        }
    }
}
fun main(args: Array<String>) {
    var s = Site()
    s.DeskTop.url // 错误，不能通过外部类的实例访问到该对象
    Site.DeskTop.url // 正确
}


//伴生对象
//一个类里面只能声明一个内部关联对象，companion 只能使用一次。
class MyClass {
    companion object Factory {
        fun create(): MyClass = MyClass()
    }
}
val instance = MyClass.create()   // 访问到对象的内部元素

interface Factory<T> {
    fun create(): T
}
class MyClass {
    companion object : Factory<MyClass> {
        override fun create(): MyClass = MyClass()
    }
}

//委托
// 创建接口
interface Base {   
    fun print()
}
// 实现此接口的被委托的类
class BaseImpl(val x: Int) : Base {
    override fun print() { print(x) }
}
// 通过关键字 by 建立委托类
class Derived(b: Base) : Base by b
fun main(args: Array<String>) {
    val b = BaseImpl(10)
    Derived(b).print() // 输出 10
}
//ToDo




