//��������(��������������var��Ϊconst)��nil
//һ��
var a, b, c int8
a, b, c = 10, 20, 30

var a, b, c = 10, 20, 30

var {
    a int8
    b int16
    c int32
}

//ȫ��ר��
var a, b
a, b := 10, 20

//�ں�������
func main (){
    //ֱ������
    g, h := 10, "string"
    //�ֲ��������뱻ʹ��
    fmt.Println("hello, world", g, h)
    //iota�÷�
    const (
        a = iota   //0
        b          //1
        c          //2
        d = "ha"   //����ֵ��iota += 1
        e          //"ha"   iota += 1
        f = 100    //iota +=1
        g          //100  iota +=1
        h = iota   //7,�ָ�����
        i          //8
    )
}




//��������������ֵ
a, b = b, a
//_ ʵ������һ��ֻд�������㲻�ܵõ�����ֵ
//5��������
_, b = 5, 7

//ʹ�� if ����жϲ������ʽ
if a < 20 {
	//�������Ϊ true ��ִ���������
   fmt.Printf("a С�� 20\n" )
} else {
    //�������Ϊ false ��ִ���������
    fmt.Printf("a ��С�� 20\n" );
}

switch marks {
    case 90: grade = "A"
    case 80: grade = "B"
    case 50,60,70 : grade = "C"
    default: grade = "D"  
}

switch {
    case grade == "A" :
        fmt.Printf("����!\n" )     
    case grade == "B", grade == "C" :
        fmt.Printf("����\n" )      
    case grade == "D" :
        fmt.Printf("����\n" )      
    case grade == "F":
        fmt.Printf("������\n" )
    default:
        fmt.Printf("��\n" );
}
var x interface{}
switch i := x.(type) {
    case nil:	  
        fmt.Printf(" x ������ :%T",i)                
    case int:	  
        fmt.Printf("x �� int ��")                       
    case float64:
        fmt.Printf("x �� float64 ��")           
    case func(int) float64:
        fmt.Printf("x �� func(int) ��")                      
    case bool, string:
        fmt.Printf("x �� bool �� string ��" )       
    default:
        fmt.Printf("δ֪��")     
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
    fmt.Printf("�� %d λ x ��ֵ = %d\n", i,x)
} 
for true  {
	fmt.Printf("��������ѭ����\n");
}
for i = 0; i < 10; i++ {
    n[i] = i + 100 /* ����Ԫ��Ϊ i + 100 */
}
break continue goto

//����
func swap(x, y string) (string, string) {
	//����
   return y, x
}
func main() {
	//����
   a, b := swap("Mahesh", "Kumar")
   fmt.Println(a, b)
}


//����
//��������
var balance [10] float32
var ptr [MAX]*int //ָ������
//��ʼ������
var balance = [5]float32{1000.0, 2.0, 3.4, 7.0, 50.0}
var balance = [...]float32{1000.0, 2.0, 3.4, 7.0, 50.0}
balance[4] = 50.0
//��ά����
a = [3][4]int{  
 {0, 1, 2, 3},   /*  ��һ������Ϊ 0 */
 {4, 5, 6, 7},   /*  �ڶ�������Ϊ 1 */
 {8, 9,10,11}   /*  ����������Ϊ 2 */
}
//���鴫����
func getAverage(arr []int, size int) float{
	var i int
	var sum float32
	//����
	for i = 0; i < size; ++i{
		sum += arr[i]
	}
	return sum / size
}
func main(){
	var a = []int{1, 1, 1, 1, 1}
	var b = getAverage(a, 5)//����
	fmt.println(b)
}


//ָ��
var a int = 20
var b *int
var c **int
b = &a //bָ������a
c = &b //cָ��ָ��b
fmt.Printf("%x\n", *b)

//�ṹ��
type Books struct {
   title string
   id int
}
var book Books //����
book.title = "a"
book.id = 0
//Bools��int������������


//��Ƭ
//����
var slice1 []type = make([]type, len) //make([]T, length, capacity)
//��ʼ��
s :=[] int {1,2,3 } 
s := arr[:] 
s :=make([]int,len,cap) 
//len() cap()
fmt.Printf("len=%d cap=%d slice=%v\n", len(s), cap(s), s)
//**len=3 cap=5 slice=[0 0 0]
//append()׷��, copy()
a = append(a, 2, 3, 4)
copy(b, a)//����a��b

//�ӿ�
/* ����ӿ� */
type interface_name interface {
   method_name1 [return_type]
   method_name2 [return_type]
   method_name3 [return_type]
   ...
   method_namen [return_type]
}
/* ����ṹ�� */
type struct_name struct {
   /* variables */
}
/* ʵ�ֽӿڷ��� */
func (struct_name_variable struct_name) method_name1() [return_type] {
   /* ����ʵ�� */
}
...
func (struct_name_variable struct_name) method_namen() [return_type] {
   /* ����ʵ��*/
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
    //��������ʹ��rangeȥ��һ��slice�ĺ͡�ʹ����������������
    nums := []int{2, 3, 4}
    sum := 0
    for _, num := range nums {
        sum += num
    }
    fmt.Println("sum:", sum)
    //��������ʹ��range������index��ֵ���������������Ǹ��������ǲ���Ҫʹ�ø�Ԫ�ص���ţ���������ʹ�ÿհ׷�"_"ʡ���ˡ���ʱ������ȷʵ��Ҫ֪������������
    for i, num := range nums {
        if num == 3 {
            fmt.Println("index:", i)
        }
    }
    //rangeҲ��������map�ļ�ֵ���ϡ�
    kvs := map[string]string{"a": "apple", "b": "banana"}
    for k, v := range kvs {
        fmt.Printf("%s -> %s\n", k, v)
    }
    //rangeҲ��������ö��Unicode�ַ�������һ���������ַ����������ڶ������ַ���Unicode��ֵ������
    for i, c := range "go" {
        fmt.Println(i, c)
    }
}


//map
func main() {
   var countryCapitalMap map[string]string
   /* �������� */
   countryCapitalMap = make(map[string]string)
   /* map ���� key-value �ԣ��������Ҷ�Ӧ���׶� */
   countryCapitalMap["France"] = "Paris"
   countryCapitalMap["Italy"] = "Rome"
   countryCapitalMap["Japan"] = "Tokyo"
   countryCapitalMap["India"] = "New Delhi"
   
   /* ʹ�� key ��� map ֵ */
   for country := range countryCapitalMap {
      fmt.Println("Capital of",country,"is",countryCapitalMap[country])
   }
   /* �鿴Ԫ���ڼ������Ƿ���� */
   captial, ok := countryCapitalMap["United States"]
   /* ��� ok �� true, ����ڣ����򲻴��� */
   if(ok){
      fmt.Println("Capital of United States is", captial)  
   }else {
      fmt.Println("Capital of United States is not present") 
   }
   /* ɾ��Ԫ�� */
   delete(countryCapitalMap,"France");
}




//������
// ����һ�� DivideError �ṹ
type DivideError struct {
	dividee int
	divider int
}
// ʵ�� 	`error` �ӿ�
func (de *DivideError) Error() string {
	strFormat := `
	Cannot proceed, the divider is zero.
	dividee: %d
	divider: 0`
	return fmt.Sprintf(strFormat, de.dividee)
}
// ���� `int` ���ͳ�������ĺ���
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
	// �������
	if result, errorMsg := Divide(100, 10); errorMsg == "" {
		fmt.Println("100/10 = ", result)
	}
	// ��������Ϊ���ʱ��᷵�ش�����Ϣ
	if _, errorMsg := Divide(100, 0); errorMsg != "" {
		fmt.Println("errorMsg is: ", errorMsg)
	}
}
