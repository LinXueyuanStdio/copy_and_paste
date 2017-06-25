using System;
using Note1;
using Note1.Note2;
#define DEBUG
#define VC_V10
namespace Note1{
    class Rectangle {
        // ��Ա����
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
				}//����ѭ��
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
		string str = @"C:\Windows";//��ת��
		string str = "C:\\Windows";//ת��
		//ToType(int)
		int_32 = (int)length// ǿ��ת�� double Ϊ int
		
		const double pi = 3.14159; // ��������
		public int num;
		private int e;
		protected int a;
		internal int inProject;//���� internal ���κγ�Ա���Ա������ڸó�Ա�������Ӧ�ó����ڵ��κ���򷽷�����
		
		//�ɿ�����
		int? num1 = null;//<null>
        int? num2 = 2;//2
        double? num3 = new double?();//<null>
        double? num4 = 3.14157;//3.14157
        bool? boolval = new bool?();//<null>
		num2 = num1 ?? 5;//num1==null��num2=5
			//??ΪNull�ϲ������ 
	}
	
	class Function{
		public void swap(ref int x, ref int y){//ref �ؼ����������ò���
			int temp;

			temp = x; //���� x ��ֵ 
			x = y;    //�� y ��ֵ�� x 
			y = temp; //�� temp ��ֵ�� y 
			
			//function.swap(ref a, ref b);
			//���ú���������ֵ 
        }
		public void getValue(out int x ){
			int temp = 5;
			x = temp;
			
			//function.getValue(out a);
			//����a=5,a֮ǰ����Ҫ��ֵ
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
			
			//�ļ�
			FileStream F = new FileStream("test.dat", 
				FileMode.OpenOrCreate, FileAccess.ReadWrite);
        }
	}

	class learnArray{
		string [,] names;
		int [,] a = new int [3,4] {
			{0, 1, 2, 3} ,   /*  ��ʼ��������Ϊ 0 ���� */
			{4, 5, 6, 7} ,   /*  ��ʼ��������Ϊ 1 ���� */
			{8, 9, 10, 11}   /*  ��ʼ��������Ϊ 2 ���� */
		};//��ά����
		int[][] scores = new int[2][]{
			new int[]{92,93,94},
			new int[]{85,66,87,88}
		};//�������������������
		//��������
		public int AddElements(params int[] arr){
			//AddElements(1,2,3,4);
			//AddElements(1,2,3,4,5,6);
		}
		//Array�ࣨ���ĵ���
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
	
	// ���� PaintCost
	public interface PaintCost {
		int getCost(int area);
	}
	abstract class Shape{//��������뱻�̳�
		public abstract int area();
	}
	public class Base{
		int name;
		public virtual int getArea(){
			return name;
		}
	}
	//ͨ�����ඨ��ǰ����ùؼ��� sealed�����Խ�������Ϊ�ܷ��ࡣ
	//��һ���౻����Ϊ sealed ʱ�������ܱ��̳С�
	//�����಻�ܱ�����Ϊ sealed��
	sealed class Line: Base, Shape, PaintCost{//�̳к�ʵ�ֽӿ�
		private double length;   // �����ĳ���
		public static int num;	//��̬��Ա������δ����ǰ���Ѵ��ڣ�һֱ����
		public Line(){  // ���캯��
			Console.WriteLine("�����Ѵ���");
		}
		~Line() {	//��������
			Console.WriteLine("������ɾ��");
		}

		public override int area ()	{ 
			Console.WriteLine("Rectangle ��������");
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
		public static double getLength(){	//��̬����������δ����ǰ���Ѵ���
			return length;
		}

		public static bool operator <= (Line lline, Line rline){
			return lline.length <= rline.length ? true : false;
		}
		
		static void Main(string[] args){
			Line line = new Line();
			// ������������
			line.setLength(6.0);
			Console.WriteLine("�����ĳ��ȣ� {0}", line.getLength());           
		}
	}
	
	// ��Ƕ�����ռ�
    namespace Note2 {
        //class
    }
	
	//�Զ����쳣
	public class TempIsZeroException: ApplicationException{
		public TempIsZeroException(string message): base(message) {
			//ʹ��
			//throw (new TempIsZeroException("Zero Temperature found"));
		}
	}
	
	
}