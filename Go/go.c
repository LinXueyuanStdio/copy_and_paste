//变量声明(声明常变量，把var改为const)空nil
//一般
var a, b, c int8
a, b, c = 10, 20, 30

var a, b, c = 10, 20, 30

var {
    a int8
    b int16
    c int32
}

//全局专属
var a, b
a, b := 10, 20

//在函数体内
func main (){
    //直接声明
    g, h := 10, "string"
    //局部变量必须被使用
    fmt.Println("hello, world", g, h)
    //iota用法
    const (
        a = iota   //0
        b          //1
        c          //2
        d = "ha"   //独立值，iota += 1
        e          //"ha"   iota += 1
        f = 100    //iota +=1
        g          //100  iota +=1
        h = iota   //7,恢复计数
        i          //8
    )
}




//交换两个变量的值
a, b = b, a
//_ 实际上是一个只写变量，你不能得到它的值
//5将被抛弃
_, b = 5, 7

//使用 if 语句判断布尔表达式
if a < 20 {
	//如果条件为 true 则执行以下语句
   fmt.Printf("a 小于 20\n" )
} else {
    //如果条件为 false 则执行以下语句
    fmt.Printf("a 不小于 20\n" );
}

switch marks {
    case 90: grade = "A"
    case 80: grade = "B"
    case 50,60,70 : grade = "C"
    default: grade = "D"  
}

switch {
    case grade == "A" :
        fmt.Printf("优秀!\n" )     
    case grade == "B", grade == "C" :
        fmt.Printf("良好\n" )      
    case grade == "D" :
        fmt.Printf("及格\n" )      
    case grade == "F":
        fmt.Printf("不及格\n" )
    default:
        fmt.Printf("差\n" );
}
var x interface{}
switch i := x.(type) {
    case nil:	  
        fmt.Printf(" x 的类型 :%T",i)                
    case int:	  
        fmt.Printf("x 是 int 型")                       
    case float64:
        fmt.Printf("x 是 float64 型")           
    case func(int) float64:
        fmt.Printf("x 是 func(int) 型")                      
    case bool, string:
        fmt.Printf("x 是 bool 或 string 型" )       
    default:
        fmt.Printf("未知型")     
} 

func main() {
   var c1, c2, c3 chan int
   var i1, i2 int
   select {
      case i1 = <-c1:
         fmt.Printf("received ", i1, " from c1\n")
      case c2 <- i2:
         fmt.Printf("sent ", i2, " to c2\n")
      case i3, ok := (<-c3):  // same as: i3, ok := <-c3
         if ok {
            fmt.Printf("received ", i3, " from c3\n")
         } else {
            fmt.Printf("c3 is closed\n")
         }
      default:
         fmt.Printf("no communication\n")
   }    
}

for i,x:= range numbers {
    fmt.Printf("第 %d 位 x 的值 = %d\n", i,x)
} 
for true  {
	fmt.Printf("这是无限循环。\n");
}
for i = 0; i < 10; i++ {
    n[i] = i + 100 /* 设置元素为 i + 100 */
}
break continue goto

//函数
func swap(x, y string) (string, string) {
	//声明
   return y, x
}
func main() {
	//调用
   a, b := swap("Mahesh", "Kumar")
   fmt.Println(a, b)
}


//数组
//声明数组
var balance [10] float32
var ptr [MAX]*int //指针数组
//初始化数组
var balance = [5]float32{1000.0, 2.0, 3.4, 7.0, 50.0}
var balance = [...]float32{1000.0, 2.0, 3.4, 7.0, 50.0}
balance[4] = 50.0
//多维数组
a = [3][4]int{  
 {0, 1, 2, 3},   /*  第一行索引为 0 */
 {4, 5, 6, 7},   /*  第二行索引为 1 */
 {8, 9,10,11}   /*  第三行索引为 2 */
}
//数组传函数
func getAverage(arr []int, size int) float{
	var i int
	var sum float32
	//声明
	for i = 0; i < size; ++i{
		sum += arr[i]
	}
	return sum / size
}
func main(){
	var a = []int{1, 1, 1, 1, 1}
	var b = getAverage(a, 5)//调用
	fmt.println(b)
}


//指针
var a int = 20
var b *int
var c **int
b = &a //b指向数据a
c = &b //c指向指针b
fmt.Printf("%x\n", *b)

//结构体
type Books struct {
   title string
   id int
}
var book Books //声明
book.title = "a"
book.id = 0
//Bools当int等数据类型用


//切片
//声明
var slice1 []type = make([]type, len) //make([]T, length, capacity)
//初始化
s :=[] int {1,2,3 } 
s := arr[:] 
s :=make([]int,len,cap) 
//len() cap()
fmt.Printf("len=%d cap=%d slice=%v\n", len(s), cap(s), s)
//**len=3 cap=5 slice=[0 0 0]
//append()追加, copy()
a = append(a, 2, 3, 4)
copy(b, a)//复制a给b

//接口
/* 定义接口 */
type interface_name interface {
   method_name1 [return_type]
   method_name2 [return_type]
   method_name3 [return_type]
   ...
   method_namen [return_type]
}
/* 定义结构体 */
type struct_name struct {
   /* variables */
}
/* 实现接口方法 */
func (struct_name_variable struct_name) method_name1() [return_type] {
   /* 方法实现 */
}
...
func (struct_name_variable struct_name) method_namen() [return_type] {
   /* 方法实现*/
}

//********
import (
    "fmt"
)
type Phone interface {
    call()
}
type NokiaPhone struct {
}
func (nokiaPhone NokiaPhone) call() {
    fmt.Println("I am Nokia, I can call you!")
}
type IPhone struct {
}
func (iPhone IPhone) call() {
    fmt.Println("I am iPhone, I can call you!")
}
func main() {
    var phone Phone
    phone = new(NokiaPhone)
    phone.call()
    phone = new(IPhone)
    phone.call()
}


//range
func main() {
    //这是我们使用range去求一个slice的和。使用数组跟这个很类似
    nums := []int{2, 3, 4}
    sum := 0
    for _, num := range nums {
        sum += num
    }
    fmt.Println("sum:", sum)
    //在数组上使用range将传入index和值两个变量。上面那个例子我们不需要使用该元素的序号，所以我们使用空白符"_"省略了。有时侯我们确实需要知道它的索引。
    for i, num := range nums {
        if num == 3 {
            fmt.Println("index:", i)
        }
    }
    //range也可以用在map的键值对上。
    kvs := map[string]string{"a": "apple", "b": "banana"}
    for k, v := range kvs {
        fmt.Printf("%s -> %s\n", k, v)
    }
    //range也可以用来枚举Unicode字符串。第一个参数是字符的索引，第二个是字符（Unicode的值）本身。
    for i, c := range "go" {
        fmt.Println(i, c)
    }
}


//map
func main() {
   var countryCapitalMap map[string]string
   /* 创建集合 */
   countryCapitalMap = make(map[string]string)
   /* map 插入 key-value 对，各个国家对应的首都 */
   countryCapitalMap["France"] = "Paris"
   countryCapitalMap["Italy"] = "Rome"
   countryCapitalMap["Japan"] = "Tokyo"
   countryCapitalMap["India"] = "New Delhi"
   
   /* 使用 key 输出 map 值 */
   for country := range countryCapitalMap {
      fmt.Println("Capital of",country,"is",countryCapitalMap[country])
   }
   /* 查看元素在集合中是否存在 */
   captial, ok := countryCapitalMap["United States"]
   /* 如果 ok 是 true, 则存在，否则不存在 */
   if(ok){
      fmt.Println("Capital of United States is", captial)  
   }else {
      fmt.Println("Capital of United States is not present") 
   }
   /* 删除元素 */
   delete(countryCapitalMap,"France");
}




//错误处理
// 定义一个 DivideError 结构
type DivideError struct {
	dividee int
	divider int
}
// 实现 	`error` 接口
func (de *DivideError) Error() string {
	strFormat := `
	Cannot proceed, the divider is zero.
	dividee: %d
	divider: 0`
	return fmt.Sprintf(strFormat, de.dividee)
}
// 定义 `int` 类型除法运算的函数
func Divide(varDividee int, varDivider int) (result int, errorMsg string) {
	if varDivider == 0 {
		dData := DivideError{
			dividee: varDividee,
			divider: varDivider,
		}
		errorMsg = dData.Error()
		return
	} else {
		return varDividee / varDivider, ""
	}
}
func main() {
	// 正常情况
	if result, errorMsg := Divide(100, 10); errorMsg == "" {
		fmt.Println("100/10 = ", result)
	}
	// 当被除数为零的时候会返回错误信息
	if _, errorMsg := Divide(100, 0); errorMsg != "" {
		fmt.Println("errorMsg is: ", errorMsg)
	}
}
