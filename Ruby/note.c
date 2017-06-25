#!/usr/bin/ruby


#在程序开头使用 $KCODE 改变字符集
$KCODE = 'u'
# a	-- ASCII （与 none 相同）。这是默认的。
# e	-- EUC。
# n	-- None （与 ASCII 相同）。
# u	-- UTF-8。

puts "这是主 Ruby 程序"
=begin 
数据类型
=end
123                  # Fixnum 十进制
1_234                # Fixnum 带有下划线的十进制
-500                 # 负的 Fixnum
0377                 # 八进制
0xff                 # 十六进制
0b1011               # 二进制
"a".ord              # "a" 的字符编码
?\n                  # 换行符（0x0a）的编码
12345678901234567890 # 大数
123.4                # 浮点值
1.0e6                # 科学记数法
4E20                 # 不是必需的
4e+20                # 指数前的符号
#整型 Integer 以下是一些整型字面量 
#字面量（literal）：代码中能见到的值，数值，bool值，字符串等都叫字面量 
#如以下的0,1_000_000,0xa等 
a1=0 
 
#带千分符的整型 
a2=1_000_000 
 
#其它进制的表示 
a3=0xa 
puts a1,a2 
puts a3 
#指数算术 
puts 2**(1/4)#1与4的商为0，然后2的0次方为1 
puts 16**(1/4.0)#1与4.0的商为0.25（四分之一），然后开四次方根

#Ruby 字符串简单地说是一个 8 位字节序列，它们是类 String 的对象。
#双引号标记的字符串允许替换和使用反斜线符号，
#单引号标记的字符串不允许替换，
#且只允许使用 \\ 和 \' 两个反斜线符号。
puts 'That\'s "\\"';#That's "\"
name="Ruby" 
puts name  #Ruby
puts "#{name+",ok"}"#Ruby,ok

=begin
数组字面量通过[]中以逗号分隔定义，且支持range定义。
（1）数组通过[]索引访问
（2）通过赋值操作插入、删除、替换元素
（3）通过+，－号进行合并和删除元素，且集合做为新集合出现
（4）通过<<号向原数据追加元素
（5）通过*号重复数组元素
（6）通过｜和&符号做并集和交集操作（注意顺序）
=end
ary = [ "fred", 10, 3.14, "This is a string", "last element", ]
ary.each do |i|
    puts i
end
(10..15).each do |n|
   print n, ' '
end
#哈希类型
hsh = colors = { "red" => 0xf00, "green" => 0x0f0, "blue" => 0x00f }
hsh.each do |key, value|
   print key, " is ", value, "\n"
end

=begin
类
=end
class Customer
   @@no_of_customers=0  #@@开头：类变量（Class variable）类变量被共享在整个继承链中
   def initialize(id, name, addr)
      @cust_id=id    #@开头：实例变量（Instance variable）
      @cust_name=name
      @cust_addr=addr
   end
   def display_details()
      puts "Customer id #@cust_id"
      puts "Customer name #@cust_name"
      puts "Customer address #@cust_addr"
   end
   def total_no_of_customers()
      @@no_of_customers += 1
      puts "Total number of customers: #@@no_of_customers"
   end
end
 
# 创建对象
cust1=Customer.new("1", "John", "Wisdom Apartments, Ludhiya")

# 调用方法
cust1.display_details()
cust1.total_no_of_customers()

=begin
Ruby 支持五种类型的变量。
一般小写字母、下划线开头：变量（Variable）。
$开头：全局变量（Global variable）。
    $global_variable = 10
大写字母开头：常数（Constant）。
=end

=begin
运算符
=end
#比较运算符
.eql?	
#如果接收器和参数具有相同的类型和相等的值，
#则返回 true。	1 == 1.0 返回 true，
#但是 1.eql?(1.0) 返回 false。
equal?	
#如果接收器和参数具有相同的对象 id，则返回 true。	
#如果 aObj 是 bObj 的副本，
#那么 aObj == bObj 返回 true，
#a.equal?bObj 返回 false，
#但是 a.equal?aObj 返回 true。


#并行赋值
a, b, c = 10, 20, 30
a, b = b, c

#逻辑运算符
and or not 
&&  || !

#范围运算符
..   #1..10==123456789 10
...  #1...10==12345678  9

# defined? 运算符   
#以方法调用的形式来判断传递的表达式是否已定义。
defined? variable # 如果 variable 已经初始化，则为 True
defined? method_call # 如果方法已经定义，则为 True
defined? super  # 如果存在可被 super 用户调用的方法，则为 True
defined? yield   # 如果已传递代码块，则为 True

#下划线运算符
#通过在方法名称前加上模块名称和一条下划线来调用模块方法。
#双冒号运算符
#您可以使用模块名称和两个冒号来引用一个常量。
MR_COUNT = 0        # 定义在主 Object 类上的常量
module Foo
  MR_COUNT = 0
  ::MR_COUNT = 1    # 设置全局计数为 1
  MR_COUNT = 2      # 设置局部计数为 2
end
puts MR_COUNT       # 这是全局常量
puts Foo::MR_COUNT  # 这是 "Foo" 的局部常量

CONST = ' out there'
class Inside_one
   CONST = proc {' in there'}
   def where_is_my_CONST
      ::CONST + ' inside one'
   end
end
class Inside_two
   CONST = ' inside two'
   def where_is_my_CONST
      CONST
   end
end
puts Inside_one.new.where_is_my_CONST
puts Inside_two.new.where_is_my_CONST
puts Object::CONST + Inside_two::CONST
puts Inside_two::CONST + CONST
puts Inside_one::CONST
puts Inside_one::CONST.call + Inside_two::CONST

=begin
逻辑
=end
#if
       #if
x=1
if x > 2
   puts "x 大于 2"
elsif x <= 2 and x!=0
   puts "x 是 1"
else
   puts "无法得知 x 的值"
end
       #if
$debug=1
print "debug\n" if $debug
       #unless除非
x=1
unless x>2
   puts "x 小于 2"
 else
  puts "x 大于 2"
end
       #unless
$var = false
print "3 -- 这一行输出\n" unless $var

#case when
$age =  5
case $age
when 0 .. 2
    puts "婴儿"
when 3 .. 6 then puts "小孩"
when 7 .. 12 then puts "child"
when 13 .. 18 then puts "少年"
else
    puts "其他年龄段的"
end
#若想在一行内写出完整的 when 式，则必须以 then 隔开条件式和程式区块

#while
$i = 0
$num = 5
while $i < $num do
  $i +=1
end

begin
   puts("在循环语句中 i = #$i" )
   $i +=1
end while $i < $num

#until 直到
until $i > $num  do
   puts("在循环语句中 i = #$i" )
   $i +=1;
end

begin
   puts("在循环语句中 i = #$i" )
   $i +=1;
end until $i > $num

#for
for i in 0..5
   puts "局部变量的值为 #{i}"
end

(0..5).each do |i|
   puts "局部变量的值为 #{i}"
end

#break
#终止最内部的循环。
#如果在块内调用，则终止相关块的方法（方法返回 nil）。
for i in 0..5
   if i > 2 then
      break
   end
   puts "局部变量的值为 #{i}"
end

#next
#跳到循环的下一个迭代。
#如果在块内调用，则终止块的执行（yield 表达式返回 nil）。
for i in 0..5
   if i < 2 then
      next
   end
   puts "局部变量的值为 #{i}"
end

#redo
#重新开始最内部循环的该次迭代，不检查循环条件。
#如果在块内调用，则重新开始 yield 或 call。
for i in 0..5
   if i < 2 then
      puts "局部变量的值为 #{i}"
      redo
   end
end

#retry
# 出现在 begin 表达式的 rescue 子句中，
#则从 begin 主体的开头重新开始。
begin
   do_something   # 抛出的异常
rescue
   # 处理错误
   retry          # 重新从 begin 开始
end

#如果 retry 出现在迭代内、块内或者 for 表达式的主体内，
#则重新开始迭代调用。迭代的参数会重新评估。
for i in 1..5
   retry if some_condition # 重新从 i == 1 开始
end


#可变数量的参数
def sample (*test)
   puts "参数个数为 #{test.length}"
   for i in 0...test.length
      puts "参数值为 #{test[i]}"
   end
end
sample "Zara", "6", "F"
sample "Mac", "36", "M", "MCA"

=begin
类
=end
#当方法定义在类的外部，方法默认标记为 private。
#另一方面，如果方法定义在类中的，则默认标记为 public。
#方法默认的可见性和 private 标记可通过模块（Module）的 public 或 private 改变。
class Accounts < Box # 继承
  attr_accessor :width, :height
  puts "#{self.class},#{self.name}" # Class , Accounts  
  # 初始化类变量
   @@count = 0
  # 构造器
  def initialize(w,h) 
    @width, @height = w, h
    @@count += 1 
  end
  
  # 访问器方法
  def getWidth
    @width
  end
  def getHeight
    @height
  end
  private :getWidth, :getHeight # 
  # 设置器方法
  def setWidth=(value)
    @width = value
  end
  def setHeight=(value)
    @height = value
  end

  # 实例方法
  def getArea
    @width * @height
  end
  def to_s # 定义的任何类都有一个 to_s 实例方法来返回对象的字符串表示形式
    "(w:#@width,h:#@height)"  # 对象的字符串格式
    # 自动调用 to_s 方法
    # puts "String representation of box is : #{box}"
  end
  # 运算符重载
  def +(other)         # 定义 + 来执行向量加法
    Box.new(@width + other.width, @height + other.height)
  end
 
  def -@               # 定义一元运算符 - 来对 width 和 height 求反
    Box.new(-@width, -@height)
  end
 
  def *(scalar)        # 执行标量乘法
    Box.new(@width*scalar, @height*scalar)
  end
  def reading_charge
  end
  def Accounts.return_date
  end
end
Accounts.return_date #访问该方法不需要创建类 Accounts 的对象
accounts = Accounts.allocate# 用 allocate 来创建一个未初始化的对象
# 让我们冻结该对象
accounts.freeze

#alias
#为方法或全局变量起别名。
#别名不能在方法主体内定义。
alias foo bar #bar 的别名为 foo
alias $MATCH $&  #$& 的别名为 $MATCH

#undef 
undef bar #取消名为 bar的方法定义

=begin
块
=end
#do ~end之间的部分称为块，也可以写为{..}
def test
   puts "在 test 方法内"
   yield
   puts "你又回到了 test 方法内"
   yield
end
test {puts "你在块内"}
#在 test 方法内
#你在块内
#你又回到了 test 方法内
#你在块内
def test
   yield 5
   puts "在 test 方法内"
   yield 100
end
test {|i| puts "你在块 #{i} 内"}
#你在块 5 内
#在 test 方法内
#你在块 100 内

def test(&block)
   block.call
end
test { puts "Hello World!"}
#但是如果方法的最后一个参数前带有 &，那么您可以向该方法传递一个块，且这个块可被赋给最后一个参数。
#如果 * 和 & 同时出现在参数列表中，& 应放在后面。
#

#一个程序可以包含多个 BEGIN 和 END 块。
#BEGIN 块按照它们出现的顺序执行。
#END 块按照它们出现的相反顺序执行。
END {
   puts "停止 Ruby 程序"
}
BEGIN {
   puts "初始化 Ruby 程序"
}
# 这是注释。
=begin
这是注释。
=end

=begin
模块
=end
# 定义在 moral.rb 文件中的模块
module Moral
   VERY_BAD = 0
   BAD = 1
   def Moral.sin(badness)
   # ...
   end
end

$LOAD_PATH << '.'  # 让 Ruby 知道必须在当前目录中搜索被引用的文件
require 'trig.rb'
require 'moral'
#在类中嵌入模块
class Decade
include moral
include tring.rb  
#继承了两个模块,可以访问所有模块的方法
   no_of_yrs=10
   def no_of_months
      puts moral::VERY_BAD
      number=10*12
      puts number
   end
end
moral::VERY_BAD 

=begin
字符串
=end
#字符串 (! [ { < |
#%q 是单引号引用规则
#%Q 是双引号引用规则
desc1 = %Q{Ruby 的字符串可以使用 '' 和 ""。}
desc2 = %q|Ruby 的字符串可以使用 '' 和 ""。|
myStr = String.new("THIS IS TEST")
foo = myStr.downcase
puts "#{foo}" #this is test

#Array
names = Array.new
names = Array.new(10)
names = Array.[](1, 2, 3, 4,5，6,7,8,9,10)
names = Array[1, 2, 3, 4,5,6,7,8,9,10]
names = Array(0..10)
puts names.size  # 返回 10
puts names.length # 返回 10
puts "#{names}" #["mac", "mac", "mac", "mac"]
nums = Array.new(10) { |e| e = e * 2 }
puts "#{nums}" #[0, 2, 4, 6, 8, 10, 12, 14, 16, 18]

#hash
months = Hash.new( "month" )
months = Hash.new "month"
puts "#{months[0]}"  #month
puts "#{months[72]}" #month
H = Hash["a" => 100, "b" => 200]
puts "#{H['a']}" #100
puts "#{H['b']}" #200

#Date & Time
time1 = Time.new
time2 = Time.now # Time.now 功能相同
puts "当前时间 : " + time1.inspect
puts "当前时间 : " + time2.inspect
time = Time.new
# Time 的组件
puts "当前时间 : " + time.inspect #2015-09-17 15:24:44 +0800
puts time.year    # 2015 => 日期的年份
puts time.month   # 9 => 日期的月份（1 到 12）
puts time.day     # 17 => 一个月中的第几天（1 到 31）
puts time.wday    # 4 => 一周中的星期几（0 是星期日）
puts time.yday    # 260 => 365：一年中的第几天
puts time.hour    # 15 => 23：24 小时制
puts time.min     # 24 => 59
puts time.sec     # 44 => 59
puts time.usec    # 921519 => 999999：微秒
puts time.zone    # CST => "UTC"：时区名称
#Time组件数组[sec,min,hour,day,month,year,wday,yday,isdst,zone]
time = Time.new
values = time.to_a
 puts Time.utc(*values) #2015-09-17 15:26:09 UTC
time = Time.now.to_i   # 返回从纪元以来的秒数
Time.at(time) # 把秒数转换为 Time 对象
time = Time.now.to_f # 返回从纪元以来的秒数，包含微妙
puts time.to_s
puts time.ctime
puts time.localtime
puts time.strftime("%Y-%m-%d %H:%M:%S")
#时间算法
now = Time.now           # 当前时间
past = now - 10          # 10 秒之前。Time - number => Time
future = now + 10        # 从现在开始 10 秒之后。Time + number => Time


=begin
range
=end
#Range

#作为序列的范围
(1..5)        #==> 1, 2, 3, 4, 5
(1...5)       #==> 1, 2, 3, 4
('a'..'d')    #==> 'a', 'b', 'c', 'd'

$, =", "   # Array 值分隔符
range1 = (1..10).to_a  # to array
range2 = ('bar'..'bat').to_a
puts "#{range1}"  #[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
puts "#{range2}"  #["bar", "bas", "bat"]

# 指定范围
digits = 0..9
puts digits.include?(5) #是否包含5

ret = digits.min
puts "最小值为 #{ret}"

ret = digits.max
puts "最大值为 #{ret}"

ret = digits.reject {|i| i < 5 }
puts "不符合条件的有 #{ret}"
 
digits.each do |digit|
   puts "在循环中 #{digit}"
end

#作为条件的范围
while gets
   print if /start/../end/
end #每个集合的第一行包含单词 start，最后一行包含单词 end.

score = 70
result = case score
when 0..40
    "糟糕的分数"
when 41..60
    "快要及格"
end
if ((1..10) === 5) # true
  puts "5 在 (1..10)"
end
 
if (('a'..'j') === 'z') #false
  puts "z 在 ('a'..'j')"
end

=begin
迭代器
=end
# 迭代器
#each 迭代器
ary = [1,2,3,4,5]
ary.each do |i|
   puts i
end  # 1 2 3 4 5 
#collect 迭代器
a = [1,2,3,4,5]
b = Array.new
b = a.collect{ |x|x }
puts b # 1 2 3 4 5

a = [1,2,3,4,5]
b = a.collect{|x| 10*x}
puts b #10 20 30 40 50

=begin
文件输入输出
=end
#文件的输入与输出
str="Hello Ruby!"
putc str # H
puts str # Hello Ruby！打印后换行
print str # Hello Ruby!打印后不换行

str = gets

#File.open 方法可与块关联，而 File.new 方法不能
aFile = File.new("filename", "mode")
  # ... 处理文件
  if aFile
    content = aFile.sysread(20) # 读取20个字符
    puts content
    aFile.syswrite("ABCDEF") # 写入 "ABCDEF" 到文件中
    aFile.rewind
    aFile.each_byte {|ch| putc ch; putc ?. } # A.B.C.D.E.F.字符一个接着一个被传到变量 ch，然后显示在屏幕上
  else
    puts "Unable to open file!"
  end
aFile.close

File.open("filename", "mode") do |aFile|
   # ... process the file
end

#mode
#r只读 r+插入开头读写 
#w只写 w+读写 a追加 a+追加读写  # 若无则创建


arr = IO.readlines("input.txt")
puts arr[0] # 第一行
puts arr[1] # 第二行
IO.foreach("input.txt"){|block| puts block} 、
  # 把文件 test 的内容逐行传给变量 block，然后输出将显示在屏幕上

# 重命名文件 test1.txt 为 test2.txt
File.rename( "test1.txt", "test2.txt" )
# 删除文件 test2.txt
File.delete("text2.txt")
#在打开文件前检查文件是否已存在
File.open("file.rb") if File::exists?( "file.rb" )
# 返回 true 或false
File.file?( "text.txt" )
File::directory?( "/usr/local/bin" ) # => true # 一个目录
File::directory?( "file.rb" ) # => false # 一个文件
File.readable?( "test.txt" )   # => true # 可读
File.writable?( "test.txt" )   # => true # 可写
File.executable?( "test.txt" ) # => false # 可执行
File.zero?( "test.txt" )      # => true # 检查文件是否大小为零
File.size?( "text.txt" )     # => 1002 # 返回文件的大小
File::ftype( "test.txt" )     # => file # 检查文件的类型
File::ctime( "test.txt" ) # => Fri May 09 10:06:37 -0700 2008 # 创建
File::mtime( "text.txt" ) # => Fri May 09 10:44:44 -0700 2008 # 修改
File::atime( "text.txt" ) # => Fri May 09 10:45:01 -0700 2008 # 最后访问

Dir.mkdir("mynewdir") # 创建目录
Dir.delete("testdir") # 删除目录
Dir.chdir("/usr/bin") # 改变当前目录为 /usr/bin
puts Dir.pwd # 返回当前目录，类似 /usr/bin
puts Dir.entries("/usr/bin").join(' ') 
  # 获取指定目录内的文件和目录列表, 返回一个数组，包含指定目录内的所有项
Dir.foreach("/usr/bin") do |entry|
   puts entry
end # 同上
Dir["/usr/bin/*"] # 同上

#创建了一个临时文件，并向其中写入数据，然后删除文件
require 'tmpdir'
tempfilename = File.join(Dir.tmpdir, "tingtong")
tempfile = File.new(tempfilename, "w")
tempfile.puts "This is a temporary file"
tempfile.close
File.delete(tempfilename)

