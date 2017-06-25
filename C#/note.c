using System;
using Note1;
using Note1.Note2;
#define DEBUG
#define VC_V10
namespace Note1{
    class Rectangle {
        // 成员变量
        private double length;
		
        public void Acceptdetails()   {
            length = 4.5;
        }
        public double GetArea(){
            return length * width;
        }
        public void Display() {
			Console.WriteLine("Size of int: {0}", sizeof(int));
			Console.WriteLine("Type of class: {0}", typeof(StreamReader););
            Console.WriteLine("Length: {0}", length);
            Console.WriteLine("Area: {0}", GetArea());
			If( Ford is Car) {
				Object obj = new StringReader("Hello");
				StringReader r = obj as StringReader;
				for (;;){
					Console.WriteLine("Hey! I am Trapped");
				}//无限循环
			}
        }
    }
	
	class Var{
		double length;//ToDouble()
		bool isRect;//ToBoolean()
		byte value_u8;//ToByte()
		char c_16;//ToChar()
		decimal value_128;//ToDecimal()
		float value_32;//ToSingle()
		int int_32;//ToInt36(),ToInt32(),ToInt64()
		long long_64;
		sbyte value_8;//ToSbyte()
		short short_16;
		uint uint_32;//ToUint16(),ToUint32(),ToUint64()
		ulong ulong_64;
		ushort ushort_16;
		//ToString()
		string str = @"C:\Windows";//不转义
		string str = "C:\\Windows";//转义
		//ToType(int)
		int_32 = (int)length// 强制转换 double 为 int
		
		const double pi = 3.14159; // 常量声明
		public int num;
		private int e;
		protected int a;
		internal int inProject;//带有 internal 的任何成员可以被定义在该成员所定义的应用程序内的任何类或方法访问
		
		//可空类型
		int? num1 = null;//<null>
        int? num2 = 2;//2
        double? num3 = new double?();//<null>
        double? num4 = 3.14157;//3.14157
        bool? boolval = new bool?();//<null>
		num2 = num1 ?? 5;//num1==null，num2=5
			//??为Null合并运算符 
	}
	
	class Function{
		public void swap(ref int x, ref int y){//ref 关键字声明引用参数
			int temp;

			temp = x; //保存 x 的值 
			x = y;    //把 y 赋值给 x 
			y = temp; //把 temp 赋值给 y 
			
			//function.swap(ref a, ref b);
			//调用函数来交换值 
        }
		public void getValue(out int x ){
			int temp = 5;
			x = temp;
			
			//function.getValue(out a);
			//返回a=5,a之前不需要赋值
		}
		
		static void Main(string[] args) {
            Rectangle r = new Rectangle();
            r.Acceptdetails();
            r.Display();
            Console.ReadLine();
			
			int num;
			num = Convert.ToInt32(Console.ReadLine());//get input
			
			#if (DEBUG && !VC_V10)
				Console.WriteLine("DEBUG is defined");
			#elif (!DEBUG && VC_V10)
				Console.WriteLine("VC_V10 is defined");
			#elif (DEBUG && VC_V10)
				Console.WriteLine("DEBUG and VC_V10 are defined");
			#else
				Console.WriteLine("DEBUG and VC_V10 are not defined");
			#endif
			
			//文件
			FileStream F = new FileStream("test.dat", 
				FileMode.OpenOrCreate, FileAccess.ReadWrite);
        }
	}

	class learnArray{
		string [,] names;
		int [,] a = new int [3,4] {
			{0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
			{4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
			{8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
		};//多维数组
		int[][] scores = new int[2][]{
			new int[]{92,93,94},
			new int[]{85,66,87,88}
		};//交错数组是数组的数组
		//参数数组
		public int AddElements(params int[] arr){
			//AddElements(1,2,3,4);
			//AddElements(1,2,3,4,5,6);
		}
		//Array类（看文档）
	}
	
	class StructAndEnum {
		struct Books{
			private string title;
			private string author;
			private string subject;
			private int book_id;
			public void getValues(string t, string a, string s, int id){
				title = t;
				author = a;
				subject = s;
				book_id = id;
			}
			public void display(){
				Console.WriteLine("Title : {0}", title);
				Console.WriteLine("Author : {0}", author);
				Console.WriteLine("Subject : {0}", subject);
				Console.WriteLine("Book_id :{0}", book_id);
			}
		};  
		enum Days { Sun, Mon, tue, Wed, thu, Fri, Sat };
	}
	
	// 基类 PaintCost
	public interface PaintCost {
		int getCost(int area);
	}
	abstract class Shape{//抽象类必须被继承
		public abstract int area();
	}
	public class Base{
		int name;
		public virtual int getArea(){
			return name;
		}
	}
	//通过在类定义前面放置关键字 sealed，可以将类声明为密封类。
	//当一个类被声明为 sealed 时，它不能被继承。
	//抽象类不能被声明为 sealed。
	sealed class Line: Base, Shape, PaintCost{//继承和实现接口
		private double length;   // 线条的长度
		public static int num;	//静态成员，对象未创建前就已存在，一直计数
		public Line(){  // 构造函数
			Console.WriteLine("对象已创建");
		}
		~Line() {	//析构函数
			Console.WriteLine("对象已删除");
		}

		public override int area ()	{ 
			Console.WriteLine("Rectangle 类的面积：");
			return (width * length); 
		}
		
		public int getCost(int area){
			return length * length;
		}
		public override int getArea(){
			return length * length;
		}
		public void setLength( double len ) {
			length = len;
		}
		public static double getLength(){	//静态方法，对象未创建前就已存在
			return length;
		}

		public static bool operator <= (Line lline, Line rline){
			return lline.length <= rline.length ? true : false;
		}
		
		static void Main(string[] args){
			Line line = new Line();
			// 设置线条长度
			line.setLength(6.0);
			Console.WriteLine("线条的长度： {0}", line.getLength());           
		}
	}
	
	// 内嵌命名空间
    namespace Note2 {
        //class
    }
	
	//自定义异常
	public class TempIsZeroException: ApplicationException{
		public TempIsZeroException(string message): base(message) {
			//使用
			//throw (new TempIsZeroException("Zero Temperature found"));
		}
	}
	
	
}