<?php 
//����
/*
ȫ�ֱ����洢��һ����Ϊ $GLOBALS[index] �������С� 
index ������������ơ�
�����������ں����ڲ����ʣ�Ҳ����ֱ����������ȫ�ֱ�����
*/
$x=5; // ȫ�ֱ��� 
$cars=array("Volvo","BMW","Toyota");
echo "�ҳ���Ʒ���� {$cars[0]}", PHP_EOL;//PHP_EOL ��һ�����з�
print $txt1;//echo = print = print()
function myTest($xx, $yy) { 
    $y=10; // �ֲ����� 
    echo "<p>���� x Ϊ: $x<p>"; //������HTML��ǩ
    echo "���� y Ϊ: $y"; 
	//�ں����ڵ��ú����ⶨ���ȫ�ֱ�����������Ҫ�ں����еı���ǰ���� global �ؼ���
	global $x,$y;
	$y=$x+$y;
	//ȫ�ֱ����洢�� $GLOBALS[index]
	$GLOBALS['y']=$GLOBALS['x']+$GLOBALS['y'];
	//��������ʱstatic������ɾ��
	//��̬���Բ������ɶ���ͨ�� -> ������������
	static $x=0;
	// �����ִ�Сд�ĳ�����(true��Сд�����С�Ĭ���Ǵ�Сд���е�)
	define("GREETING", "aaaaaaa", true);
	//�ڶ����ʹ�ó�����ʱ����Ҫʹ�� $ ����
	const constant = '����ֵ';
	return ($xx + $yy);
}  
myTest(); 
echo "<p>���� x Ϊ: $x<p>"; //������HTML��ǩ
echo "���� y Ϊ: $y"; 

//�ַ���
//���� ���������.
$txt1="Hello world!"; 
$txt2="What a nice day!"; 
echo $txt1 . " " . $txt2; 
//���� $text1 .= $text2;
//strlen() �ַ���
//strpos() ���ص�һ��ƥ����ַ�λ�á����δ�ҵ�ƥ�䣬�򷵻� FALSE
echo strpos("Hello world!","world"); 

//�����
x != y������
x <> y������
x !==y�������
&& and ��
|| or  ��
xor    ���
<=>    ��ϱȽϷ�,������-��

//����
//��ֵ���� - �������� ID ��������
$cars=array("Volvo","BMW","Toyota");

$cars[0]="Volvo";
$cars[3]="BMW";
$cars[2]="Toyota";

$arrlength=count($cars);
for($x=0;$x<$arrlength;$x++){
	echo $cars[$x];
}
//�������� - ����ָ���ļ������飬ÿ��������һ��ֵ
$age = array("Peter"=>"35","Ben"=>"37","Joe"=>"43");

$age['Peter']="35";
$age['Ben']="37";
$age['Joe']="43";

foreach($age as $x => $x_value){
	echo "Key=" . $x .
		 ", Value=" . $x_value;
}
//��ά���� - ����һ���������������

//����
sort() - �����������������
rsort() - ��������н�������
asort() - ���ݹ��������ֵ�������������������
ksort() - ���ݹ�������ļ��������������������
arsort() - ���ݹ��������ֵ����������н�������
krsort() - ���ݹ�������ļ�����������н�������

//PHPԤ�����˼�������ȫ�ֱ�����superglobals��
{
$GLOBALS 
	//������ȫ��������ȫ��������顣���������־�������ļ�
	//$GLOBALS['z']
$_SERVER
	//����������ͷ��Ϣ(header)��·��(path)���Լ��ű�λ��(script locations)�ȵ���Ϣ�����顣
	//��������е���Ŀ�� Web ����������
$_REQUEST
	//�����ռ�HTML���ύ������
$_POST
	//�����ռ������ݣ���HTML form��ǩ��ָ�������ԣ�"method="post"��
$_GET
	//�����ռ������ݣ���HTML form��ǩ��ָ�������ԣ�"method="get"
	<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
		<input type="text" name="fname">//�����
		<input type="submit">//��ť
	</form>
	<a href="test.php?subject=PHP&web=runoob.com">Test $GET</a>
	
	<?php //test.php
		echo $_REQUEST['fname']; //�������������ַ���
		echo $_POST['fname'];  
		echo "Study " . $_GET['subject'] . " at " . $_GET['web'];
			//������� "Test $GET", 
			//���� "subject" �� "web" ��������"test_get.php",
			//������ "test.php" �ļ���ʹ�� $_GET ��������ȡ��Щ���ݡ�
	?>
	
$_FILES
$_ENV
$_COOKIE
$_SESSION
}
//ħ������
{
//�ܶೣ�������ɲ�ͬ����չ�ⶨ��ģ�
//ֻ���ڼ�������Щ��չ��ʱ�Ż���֣����߶�̬���غ󣬻����ڱ���ʱ�Ѿ�������ȥ��
__LINE__
	//�ļ��еĵ�ǰ�к�
	//2
__FILE__
	//�ļ�������·�����ļ���
	//E:\wamp\www\test\index.php
__DIR__
	//�ļ����ڵ�Ŀ¼=dirname(__FILE__)
	//E:\wamp\www\test
__FUNCTION__
	//�������ƣ����ִ�Сд
	function test(){echo __FUNCTION__;}  //test
__CLASS__
	//�������
	class Test{function test(){echo __CLASS__;}}//Test
__TRAIT__
	//Trait ������
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
	$o->sayHello();//Hello World��
__METHOD__
	//��ķ�����
__NAMESPACE__
	//��ǰ�����ռ�����ƣ����ִ�Сд��
	namespace MyProject;
	echo __NAMESPACE__;//MyProject
}
//�����ռ�
{
//���һ���ļ��а��������ռ䣬���������������д���֮ǰ���������ռ�
declare(encoding='UTF-8'); //�����������ռ�Ͳ������������ռ��еĴ����ʽ��Ψһ����
namespace MyProject1;  
// MyProject1 �����ռ��е�PHP����  
 
namespace MyProject2;  
// MyProject2 �����ռ��е�PHP����    

namespace MyProject\Sub\Level;  
//�����ֲ�εĵ��������ռ䣬�������ռ�
 
// ��һ���﷨
namespace MyProject3 {  
 // MyProject3 �����ռ��е�PHP����    
}  
//�����ռ�ʹ��
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

	/* ���޶����� */
	foo(); // ����Ϊ Foo\Bar\foo resolves to function Foo\Bar\foo
	foo::staticmethod(); // ����Ϊ�� Foo\Bar\foo�ľ�̬����staticmethod��resolves to class Foo\Bar\foo, method staticmethod
	echo FOO; // resolves to constant Foo\Bar\FOO

	/* �޶����� */
	subnamespace\foo(); // ����Ϊ���� Foo\Bar\subnamespace\foo
	subnamespace\foo::staticmethod(); // ����Ϊ�� Foo\Bar\subnamespace\foo,
                                  // �Լ���ķ��� staticmethod
	echo subnamespace\FOO; // ����Ϊ���� Foo\Bar\subnamespace\FOO
                                  
	/* ��ȫ�޶����� */
	\Foo\Bar\foo(); // ����Ϊ���� Foo\Bar\foo
	\Foo\Bar\foo::staticmethod(); // ����Ϊ�� Foo\Bar\foo, �Լ���ķ��� staticmethod
	echo \Foo\Bar\FOO; // ����Ϊ���� Foo\Bar\FOO
	
	$a = \strlen('hi'); // ����ȫ�ֺ���strlen
	$b = \INI_ALL; // ����ȫ�ֳ��� INI_ALL
	$c = new \Exception('error'); // ʵ����ȫ���� Exception
	
	//�����ռ�Ͷ�̬��������
	$a = 'classname';//��̬�趨
	$obj = new $a; // prints classname::__construct
	$b = 'funcname';
	$b(); // prints funcname
	echo constant('constname'), "\n"; // prints global
	
	//�������ռ��з����࣬����ȷ��·��
	//���ں����ͳ�����˵��
	//�����ǰ�����ռ��в����ڸú���������
	//PHP ���˶�ʹ��ȫ�ֿռ��еĺ���������
	?>
//�ؼ��� namespace ��������ʽ���ʵ�ǰ�����ռ���������ռ��е�Ԫ�ء�
//���ȼ������е� self ��������
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
//���������ռ�
<?php
namespace foo;
use My\Full\Classname as Another;
use My\Full\NSname;//�� use My\Full\NSname as NSname ��ͬ

use My\Full\Classname as Another, My\Full\NSname;

// ����һ��ȫ����
use \ArrayObject;

$obj = new namespace\Another; // ʵ���� foo\Another ����
$obj = new Another; // ʵ���� My\Full\Classname������
NSname\subns\func(); // ���ú��� My\Full\NSname\subns\func
$a = new ArrayObject(array(1)); // ʵ���� ArrayObject ����
// �����ʹ�� "use \ArrayObject" ����ʵ����һ�� foo\ArrayObject ����
?>
}

//��
//�෽��Ĭ�Ϲ���
//Ҫִ�и���Ĺ��췽������Ҫ������Ĺ��췽���е��� parent::__construct()
//���������Ի򷽷�Ϊ static(��̬)���Ϳ��Բ�ʵ�������ֱ�ӷ��ʡ�
//��̬���Բ���ͨ��һ������ʵ�����Ķ��������ʣ�����̬�������ԣ���
//���ھ�̬��������Ҫͨ�����󼴿ɵ��ã�����α���� $this �ھ�̬�����в�����

//�ӿ�
// ����һ��'iTemplate'�ӿ�
interface iTemplate{
    public function setVariable($name, $var);
    public function getHtml($template);
}
// ʵ�ֽӿ�
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