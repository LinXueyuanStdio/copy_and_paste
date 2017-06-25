<?php 
//变量
/*
全局变量存储在一个名为 $GLOBALS[index] 的数组中。 
index 保存变量的名称。
这个数组可以在函数内部访问，也可以直接用来更新全局变量。
*/
$x=5; // 全局变量 
$cars=array("Volvo","BMW","Toyota");
echo "我车的品牌是 {$cars[0]}", PHP_EOL;//PHP_EOL 是一个换行符
print $txt1;//echo = print = print()
function myTest($xx, $yy) { 
    $y=10; // 局部变量 
    echo "<p>变量 x 为: $x<p>"; //可以有HTML标签
    echo "变量 y 为: $y"; 
	//在函数内调用函数外定义的全局变量，我们需要在函数中的变量前加上 global 关键字
	global $x,$y;
	$y=$x+$y;
	//全局变量存储在 $GLOBALS[index]
	$GLOBALS['y']=$GLOBALS['x']+$GLOBALS['y'];
	//函数结束时static变量不删除
	//静态属性不可以由对象通过 -> 操作符来访问
	static $x=0;
	// 不区分大小写的常量名(true大小写不敏感。默认是大小写敏感的)
	define("GREETING", "aaaaaaa", true);
	//在定义和使用常量的时候不需要使用 $ 符号
	const constant = '常量值';
	return ($xx + $yy);
}  
myTest(); 
echo "<p>变量 x 为: $x<p>"; //可以有HTML标签
echo "变量 y 为: $y"; 

//字符串
//连接 并置运算符.
$txt1="Hello world!"; 
$txt2="What a nice day!"; 
echo $txt1 . " " . $txt2; 
//运算 $text1 .= $text2;
//strlen() 字符数
//strpos() 返回第一个匹配的字符位置。如果未找到匹配，则返回 FALSE
echo strpos("Hello world!","world"); 

//运算符
x != y不等于
x <> y不等于
x !==y不恒等于
&& and 与
|| or  或
xor    异或
<=>    组合比较符,返回左-右

//数组
//数值数组 - 带有数字 ID 键的数组
$cars=array("Volvo","BMW","Toyota");

$cars[0]="Volvo";
$cars[3]="BMW";
$cars[2]="Toyota";

$arrlength=count($cars);
for($x=0;$x<$arrlength;$x++){
	echo $cars[$x];
}
//关联数组 - 带有指定的键的数组，每个键关联一个值
$age = array("Peter"=>"35","Ben"=>"37","Joe"=>"43");

$age['Peter']="35";
$age['Ben']="37";
$age['Joe']="43";

foreach($age as $x => $x_value){
	echo "Key=" . $x .
		 ", Value=" . $x_value;
}
//多维数组 - 包含一个或多个数组的数组

//排序
sort() - 对数组进行升序排列
rsort() - 对数组进行降序排列
asort() - 根据关联数组的值，对数组进行升序排列
ksort() - 根据关联数组的键，对数组进行升序排列
arsort() - 根据关联数组的值，对数组进行降序排列
krsort() - 根据关联数组的键，对数组进行降序排列

//PHP预定义了几个超级全局变量（superglobals）
{
$GLOBALS 
	//包含了全部变量的全局组合数组。变量的名字就是数组的键
	//$GLOBALS['z']
$_SERVER
	//包含了诸如头信息(header)、路径(path)、以及脚本位置(script locations)等等信息的数组。
	//这个数组中的项目由 Web 服务器创建
$_REQUEST
	//用于收集HTML表单提交的数据
$_POST
	//用于收集表单数据，在HTML form标签的指定该属性："method="post"。
$_GET
	//用于收集表单数据，在HTML form标签的指定该属性："method="get"
	<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
		<input type="text" name="fname">//输入框
		<input type="submit">//按钮
	</form>
	<a href="test.php?subject=PHP&web=runoob.com">Test $GET</a>
	
	<?php //test.php
		echo $_REQUEST['fname']; //输入框内输入的字符串
		echo $_POST['fname'];  
		echo "Study " . $_GET['subject'] . " at " . $_GET['web'];
			//点击链接 "Test $GET", 
			//参数 "subject" 和 "web" 将发送至"test_get.php",
			//可以在 "test.php" 文件中使用 $_GET 变量来获取这些数据。
	?>
	
$_FILES
$_ENV
$_COOKIE
$_SESSION
}
//魔术变量
{
//很多常量都是由不同的扩展库定义的，
//只有在加载了这些扩展库时才会出现，或者动态加载后，或者在编译时已经包括进去了
__LINE__
	//文件中的当前行号
	//2
__FILE__
	//文件的完整路径和文件名
	//E:\wamp\www\test\index.php
__DIR__
	//文件所在的目录=dirname(__FILE__)
	//E:\wamp\www\test
__FUNCTION__
	//函数名称，区分大小写
	function test(){echo __FUNCTION__;}  //test
__CLASS__
	//类的名称
	class Test{function test(){echo __CLASS__;}}//Test
__TRAIT__
	//Trait 的名字
	class Base {
		public function sayHello() {
			echo 'Hello ';
		}
	}
 
	trait SayWorld {
		public function sayHello() {
			parent::sayHello();
			echo 'World!';
		}
	}
 
	class MyHelloWorld extends Base {
		use SayWorld;
	}
 
	$o = new MyHelloWorld();
	$o->sayHello();//Hello World！
__METHOD__
	//类的方法名
__NAMESPACE__
	//当前命名空间的名称（区分大小写）
	namespace MyProject;
	echo __NAMESPACE__;//MyProject
}
//命名空间
{
//如果一个文件中包含命名空间，它必须在其它所有代码之前声明命名空间
declare(encoding='UTF-8'); //定义多个命名空间和不包含在命名空间中的代码格式，唯一有用
namespace MyProject1;  
// MyProject1 命名空间中的PHP代码  
 
namespace MyProject2;  
// MyProject2 命名空间中的PHP代码    

namespace MyProject\Sub\Level;  
//声明分层次的单个命名空间，子命名空间
 
// 另一种语法
namespace MyProject3 {  
 // MyProject3 命名空间中的PHP代码    
}  
//命名空间使用
file1.php
	<?php
	namespace Foo\Bar\subnamespace; 

	const FOO = 1;
	function foo() {}
	class foo{
		static function staticmethod() {}
	}
	?>
file2.php
	<?php
	namespace Foo\Bar;
	include 'file1.php';

	const FOO = 2;
	function foo() {}
	class foo{
		static function staticmethod() {}
	}

	/* 非限定名称 */
	foo(); // 解析为 Foo\Bar\foo resolves to function Foo\Bar\foo
	foo::staticmethod(); // 解析为类 Foo\Bar\foo的静态方法staticmethod。resolves to class Foo\Bar\foo, method staticmethod
	echo FOO; // resolves to constant Foo\Bar\FOO

	/* 限定名称 */
	subnamespace\foo(); // 解析为函数 Foo\Bar\subnamespace\foo
	subnamespace\foo::staticmethod(); // 解析为类 Foo\Bar\subnamespace\foo,
                                  // 以及类的方法 staticmethod
	echo subnamespace\FOO; // 解析为常量 Foo\Bar\subnamespace\FOO
                                  
	/* 完全限定名称 */
	\Foo\Bar\foo(); // 解析为函数 Foo\Bar\foo
	\Foo\Bar\foo::staticmethod(); // 解析为类 Foo\Bar\foo, 以及类的方法 staticmethod
	echo \Foo\Bar\FOO; // 解析为常量 Foo\Bar\FOO
	
	$a = \strlen('hi'); // 调用全局函数strlen
	$b = \INI_ALL; // 访问全局常量 INI_ALL
	$c = new \Exception('error'); // 实例化全局类 Exception
	
	//命名空间和动态语言特征
	$a = 'classname';//动态设定
	$obj = new $a; // prints classname::__construct
	$b = 'funcname';
	$b(); // prints funcname
	echo constant('constname'), "\n"; // prints global
	
	//在命名空间中访问类，必须确定路径
	//对于函数和常量来说，
	//如果当前命名空间中不存在该函数或常量，
	//PHP 会退而使用全局空间中的函数或常量。
	?>
//关键字 namespace 可用来显式访问当前命名空间或子命名空间中的元素。
//它等价于类中的 self 操作符。
<?php
namespace MyProject;

use blah\blah as mine; // see "Using namespaces: importing/aliasing"

blah\mine(); // calls function blah\blah\mine()
namespace\blah\mine(); // calls function MyProject\blah\mine()

namespace\func(); // calls function MyProject\func()
namespace\sub\func(); // calls function MyProject\sub\func()
namespace\cname::method(); // calls static method "method" of class MyProject\cname
$a = new namespace\sub\cname(); // instantiates object of class MyProject\sub\cname
$b = namespace\CONSTANT; // assigns value of constant MyProject\CONSTANT to $b
?>
//导入命名空间
<?php
namespace foo;
use My\Full\Classname as Another;
use My\Full\NSname;//与 use My\Full\NSname as NSname 相同

use My\Full\Classname as Another, My\Full\NSname;

// 导入一个全局类
use \ArrayObject;

$obj = new namespace\Another; // 实例化 foo\Another 对象
$obj = new Another; // 实例化 My\Full\Classname　对象
NSname\subns\func(); // 调用函数 My\Full\NSname\subns\func
$a = new ArrayObject(array(1)); // 实例化 ArrayObject 对象
// 如果不使用 "use \ArrayObject" ，则实例化一个 foo\ArrayObject 对象
?>
}

//类
//类方法默认公有
//要执行父类的构造方法，需要在子类的构造方法中调用 parent::__construct()
//声明类属性或方法为 static(静态)，就可以不实例化类而直接访问。
//静态属性不能通过一个类已实例化的对象来访问（但静态方法可以）。
//由于静态方法不需要通过对象即可调用，所以伪变量 $this 在静态方法中不可用

//接口
// 声明一个'iTemplate'接口
interface iTemplate{
    public function setVariable($name, $var);
    public function getHtml($template);
}
// 实现接口
class Template implements iTemplate{
    private $vars = array();
  
    public function setVariable($name, $var) {
        $this->vars[$name] = $var;
    }
  
    public function getHtml($template)    {
        foreach($this->vars as $name => $value) {
            $template = str_replace('{' . $name . '}', $value, $template);
        }
        return $template;
    }
}
?>