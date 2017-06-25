#!/usr/bin/ruby


#�ڳ���ͷʹ�� $KCODE �ı��ַ���
$KCODE = 'u'
# a	-- ASCII ���� none ��ͬ��������Ĭ�ϵġ�
# e	-- EUC��
# n	-- None ���� ASCII ��ͬ����
# u	-- UTF-8��

puts "������ Ruby ����"
=begin 
��������
=end
123                  # Fixnum ʮ����
1_234                # Fixnum �����»��ߵ�ʮ����
-500                 # ���� Fixnum
0377                 # �˽���
0xff                 # ʮ������
0b1011               # ������
"a".ord              # "a" ���ַ�����
?\n                  # ���з���0x0a���ı���
12345678901234567890 # ����
123.4                # ����ֵ
1.0e6                # ��ѧ������
4E20                 # ���Ǳ����
4e+20                # ָ��ǰ�ķ���
#���� Integer ������һЩ���������� 
#��������literal�����������ܼ�����ֵ����ֵ��boolֵ���ַ����ȶ��������� 
#�����µ�0,1_000_000,0xa�� 
a1=0 
 
#��ǧ�ַ������� 
a2=1_000_000 
 
#�������Ƶı�ʾ 
a3=0xa 
puts a1,a2 
puts a3 
#ָ������ 
puts 2**(1/4)#1��4����Ϊ0��Ȼ��2��0�η�Ϊ1 
puts 16**(1/4.0)#1��4.0����Ϊ0.25���ķ�֮һ����Ȼ���Ĵη���

#Ruby �ַ����򵥵�˵��һ�� 8 λ�ֽ����У��������� String �Ķ���
#˫���ű�ǵ��ַ��������滻��ʹ�÷�б�߷��ţ�
#�����ű�ǵ��ַ����������滻��
#��ֻ����ʹ�� \\ �� \' ������б�߷��š�
puts 'That\'s "\\"';#That's "\"
name="Ruby" 
puts name  #Ruby
puts "#{name+",ok"}"#Ruby,ok

=begin
����������ͨ��[]���Զ��ŷָ����壬��֧��range���塣
��1������ͨ��[]��������
��2��ͨ����ֵ�������롢ɾ�����滻Ԫ��
��3��ͨ��+�����Ž��кϲ���ɾ��Ԫ�أ��Ҽ�����Ϊ�¼��ϳ���
��4��ͨ��<<����ԭ����׷��Ԫ��
��5��ͨ��*���ظ�����Ԫ��
��6��ͨ������&�����������ͽ���������ע��˳��
=end
ary = [ "fred", 10, 3.14, "This is a string", "last element", ]
ary.each do |i|
    puts i
end
(10..15).each do |n|
   print n, ' '
end
#��ϣ����
hsh = colors = { "red" => 0xf00, "green" => 0x0f0, "blue" => 0x00f }
hsh.each do |key, value|
   print key, " is ", value, "\n"
end

=begin
��
=end
class Customer
   @@no_of_customers=0  #@@��ͷ���������Class variable��������������������̳�����
   def initialize(id, name, addr)
      @cust_id=id    #@��ͷ��ʵ��������Instance variable��
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
 
# ��������
cust1=Customer.new("1", "John", "Wisdom Apartments, Ludhiya")

# ���÷���
cust1.display_details()
cust1.total_no_of_customers()

=begin
Ruby ֧���������͵ı�����
һ��Сд��ĸ���»��߿�ͷ��������Variable����
$��ͷ��ȫ�ֱ�����Global variable����
    $global_variable = 10
��д��ĸ��ͷ��������Constant����
=end

=begin
�����
=end
#�Ƚ������
.eql?	
#����������Ͳ���������ͬ�����ͺ���ȵ�ֵ��
#�򷵻� true��	1 == 1.0 ���� true��
#���� 1.eql?(1.0) ���� false��
equal?	
#����������Ͳ���������ͬ�Ķ��� id���򷵻� true��	
#��� aObj �� bObj �ĸ�����
#��ô aObj == bObj ���� true��
#a.equal?bObj ���� false��
#���� a.equal?aObj ���� true��


#���и�ֵ
a, b, c = 10, 20, 30
a, b = b, c

#�߼������
and or not 
&&  || !

#��Χ�����
..   #1..10==123456789 10
...  #1...10==12345678  9

# defined? �����   
#�Է������õ���ʽ���жϴ��ݵı��ʽ�Ƿ��Ѷ��塣
defined? variable # ��� variable �Ѿ���ʼ������Ϊ True
defined? method_call # ��������Ѿ����壬��Ϊ True
defined? super  # ������ڿɱ� super �û����õķ�������Ϊ True
defined? yield   # ����Ѵ��ݴ���飬��Ϊ True

#�»��������
#ͨ���ڷ�������ǰ����ģ�����ƺ�һ���»���������ģ�鷽����
#˫ð�������
#������ʹ��ģ�����ƺ�����ð��������һ��������
MR_COUNT = 0        # �������� Object ���ϵĳ���
module Foo
  MR_COUNT = 0
  ::MR_COUNT = 1    # ����ȫ�ּ���Ϊ 1
  MR_COUNT = 2      # ���þֲ�����Ϊ 2
end
puts MR_COUNT       # ����ȫ�ֳ���
puts Foo::MR_COUNT  # ���� "Foo" �ľֲ�����

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
�߼�
=end
#if
       #if
x=1
if x > 2
   puts "x ���� 2"
elsif x <= 2 and x!=0
   puts "x �� 1"
else
   puts "�޷���֪ x ��ֵ"
end
       #if
$debug=1
print "debug\n" if $debug
       #unless����
x=1
unless x>2
   puts "x С�� 2"
 else
  puts "x ���� 2"
end
       #unless
$var = false
print "3 -- ��һ�����\n" unless $var

#case when
$age =  5
case $age
when 0 .. 2
    puts "Ӥ��"
when 3 .. 6 then puts "С��"
when 7 .. 12 then puts "child"
when 13 .. 18 then puts "����"
else
    puts "��������ε�"
end
#������һ����д�������� when ʽ��������� then ��������ʽ�ͳ�ʽ����

#while
$i = 0
$num = 5
while $i < $num do
  $i +=1
end

begin
   puts("��ѭ������� i = #$i" )
   $i +=1
end while $i < $num

#until ֱ��
until $i > $num  do
   puts("��ѭ������� i = #$i" )
   $i +=1;
end

begin
   puts("��ѭ������� i = #$i" )
   $i +=1;
end until $i > $num

#for
for i in 0..5
   puts "�ֲ�������ֵΪ #{i}"
end

(0..5).each do |i|
   puts "�ֲ�������ֵΪ #{i}"
end

#break
#��ֹ���ڲ���ѭ����
#����ڿ��ڵ��ã�����ֹ��ؿ�ķ������������� nil����
for i in 0..5
   if i > 2 then
      break
   end
   puts "�ֲ�������ֵΪ #{i}"
end

#next
#����ѭ������һ��������
#����ڿ��ڵ��ã�����ֹ���ִ�У�yield ���ʽ���� nil����
for i in 0..5
   if i < 2 then
      next
   end
   puts "�ֲ�������ֵΪ #{i}"
end

#redo
#���¿�ʼ���ڲ�ѭ���ĸôε����������ѭ��������
#����ڿ��ڵ��ã������¿�ʼ yield �� call��
for i in 0..5
   if i < 2 then
      puts "�ֲ�������ֵΪ #{i}"
      redo
   end
end

#retry
# ������ begin ���ʽ�� rescue �Ӿ��У�
#��� begin ����Ŀ�ͷ���¿�ʼ��
begin
   do_something   # �׳����쳣
rescue
   # �������
   retry          # ���´� begin ��ʼ
end

#��� retry �����ڵ����ڡ����ڻ��� for ���ʽ�������ڣ�
#�����¿�ʼ�������á������Ĳ���������������
for i in 1..5
   retry if some_condition # ���´� i == 1 ��ʼ
end


#�ɱ������Ĳ���
def sample (*test)
   puts "��������Ϊ #{test.length}"
   for i in 0...test.length
      puts "����ֵΪ #{test[i]}"
   end
end
sample "Zara", "6", "F"
sample "Mac", "36", "M", "MCA"

=begin
��
=end
#����������������ⲿ������Ĭ�ϱ��Ϊ private��
#��һ���棬����������������еģ���Ĭ�ϱ��Ϊ public��
#����Ĭ�ϵĿɼ��Ժ� private ��ǿ�ͨ��ģ�飨Module���� public �� private �ı䡣
class Accounts < Box # �̳�
  attr_accessor :width, :height
  puts "#{self.class},#{self.name}" # Class , Accounts  
  # ��ʼ�������
   @@count = 0
  # ������
  def initialize(w,h) 
    @width, @height = w, h
    @@count += 1 
  end
  
  # ����������
  def getWidth
    @width
  end
  def getHeight
    @height
  end
  private :getWidth, :getHeight # 
  # ����������
  def setWidth=(value)
    @width = value
  end
  def setHeight=(value)
    @height = value
  end

  # ʵ������
  def getArea
    @width * @height
  end
  def to_s # ������κ��඼��һ�� to_s ʵ�����������ض�����ַ�����ʾ��ʽ
    "(w:#@width,h:#@height)"  # ������ַ�����ʽ
    # �Զ����� to_s ����
    # puts "String representation of box is : #{box}"
  end
  # ���������
  def +(other)         # ���� + ��ִ�������ӷ�
    Box.new(@width + other.width, @height + other.height)
  end
 
  def -@               # ����һԪ����� - ���� width �� height ��
    Box.new(-@width, -@height)
  end
 
  def *(scalar)        # ִ�б����˷�
    Box.new(@width*scalar, @height*scalar)
  end
  def reading_charge
  end
  def Accounts.return_date
  end
end
Accounts.return_date #���ʸ÷�������Ҫ������ Accounts �Ķ���
accounts = Accounts.allocate# �� allocate ������һ��δ��ʼ���Ķ���
# �����Ƕ���ö���
accounts.freeze

#alias
#Ϊ������ȫ�ֱ����������
#���������ڷ��������ڶ��塣
alias foo bar #bar �ı���Ϊ foo
alias $MATCH $&  #$& �ı���Ϊ $MATCH

#undef 
undef bar #ȡ����Ϊ bar�ķ�������

=begin
��
=end
#do ~end֮��Ĳ��ֳ�Ϊ�飬Ҳ����дΪ{..}
def test
   puts "�� test ������"
   yield
   puts "���ֻص��� test ������"
   yield
end
test {puts "���ڿ���"}
#�� test ������
#���ڿ���
#���ֻص��� test ������
#���ڿ���
def test
   yield 5
   puts "�� test ������"
   yield 100
end
test {|i| puts "���ڿ� #{i} ��"}
#���ڿ� 5 ��
#�� test ������
#���ڿ� 100 ��

def test(&block)
   block.call
end
test { puts "Hello World!"}
#����������������һ������ǰ���� &����ô��������÷�������һ���飬�������ɱ��������һ��������
#��� * �� & ͬʱ�����ڲ����б��У�& Ӧ���ں��档
#

#һ��������԰������ BEGIN �� END �顣
#BEGIN �鰴�����ǳ��ֵ�˳��ִ�С�
#END �鰴�����ǳ��ֵ��෴˳��ִ�С�
END {
   puts "ֹͣ Ruby ����"
}
BEGIN {
   puts "��ʼ�� Ruby ����"
}
# ����ע�͡�
=begin
����ע�͡�
=end

=begin
ģ��
=end
# ������ moral.rb �ļ��е�ģ��
module Moral
   VERY_BAD = 0
   BAD = 1
   def Moral.sin(badness)
   # ...
   end
end

$LOAD_PATH << '.'  # �� Ruby ֪�������ڵ�ǰĿ¼�����������õ��ļ�
require 'trig.rb'
require 'moral'
#������Ƕ��ģ��
class Decade
include moral
include tring.rb  
#�̳�������ģ��,���Է�������ģ��ķ���
   no_of_yrs=10
   def no_of_months
      puts moral::VERY_BAD
      number=10*12
      puts number
   end
end
moral::VERY_BAD 

=begin
�ַ���
=end
#�ַ��� (! [ { < |
#%q �ǵ��������ù���
#%Q ��˫�������ù���
desc1 = %Q{Ruby ���ַ�������ʹ�� '' �� ""��}
desc2 = %q|Ruby ���ַ�������ʹ�� '' �� ""��|
myStr = String.new("THIS IS TEST")
foo = myStr.downcase
puts "#{foo}" #this is test

#Array
names = Array.new
names = Array.new(10)
names = Array.[](1, 2, 3, 4,5��6,7,8,9,10)
names = Array[1, 2, 3, 4,5,6,7,8,9,10]
names = Array(0..10)
puts names.size  # ���� 10
puts names.length # ���� 10
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
time2 = Time.now # Time.now ������ͬ
puts "��ǰʱ�� : " + time1.inspect
puts "��ǰʱ�� : " + time2.inspect
time = Time.new
# Time �����
puts "��ǰʱ�� : " + time.inspect #2015-09-17 15:24:44 +0800
puts time.year    # 2015 => ���ڵ����
puts time.month   # 9 => ���ڵ��·ݣ�1 �� 12��
puts time.day     # 17 => һ�����еĵڼ��죨1 �� 31��
puts time.wday    # 4 => һ���е����ڼ���0 �������գ�
puts time.yday    # 260 => 365��һ���еĵڼ���
puts time.hour    # 15 => 23��24 Сʱ��
puts time.min     # 24 => 59
puts time.sec     # 44 => 59
puts time.usec    # 921519 => 999999��΢��
puts time.zone    # CST => "UTC"��ʱ������
#Time�������[sec,min,hour,day,month,year,wday,yday,isdst,zone]
time = Time.new
values = time.to_a
 puts Time.utc(*values) #2015-09-17 15:26:09 UTC
time = Time.now.to_i   # ���شӼ�Ԫ����������
Time.at(time) # ������ת��Ϊ Time ����
time = Time.now.to_f # ���شӼ�Ԫ����������������΢��
puts time.to_s
puts time.ctime
puts time.localtime
puts time.strftime("%Y-%m-%d %H:%M:%S")
#ʱ���㷨
now = Time.now           # ��ǰʱ��
past = now - 10          # 10 ��֮ǰ��Time - number => Time
future = now + 10        # �����ڿ�ʼ 10 ��֮��Time + number => Time


=begin
range
=end
#Range

#��Ϊ���еķ�Χ
(1..5)        #==> 1, 2, 3, 4, 5
(1...5)       #==> 1, 2, 3, 4
('a'..'d')    #==> 'a', 'b', 'c', 'd'

$, =", "   # Array ֵ�ָ���
range1 = (1..10).to_a  # to array
range2 = ('bar'..'bat').to_a
puts "#{range1}"  #[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
puts "#{range2}"  #["bar", "bas", "bat"]

# ָ����Χ
digits = 0..9
puts digits.include?(5) #�Ƿ����5

ret = digits.min
puts "��СֵΪ #{ret}"

ret = digits.max
puts "���ֵΪ #{ret}"

ret = digits.reject {|i| i < 5 }
puts "�������������� #{ret}"
 
digits.each do |digit|
   puts "��ѭ���� #{digit}"
end

#��Ϊ�����ķ�Χ
while gets
   print if /start/../end/
end #ÿ�����ϵĵ�һ�а������� start�����һ�а������� end.

score = 70
result = case score
when 0..40
    "���ķ���"
when 41..60
    "��Ҫ����"
end
if ((1..10) === 5) # true
  puts "5 �� (1..10)"
end
 
if (('a'..'j') === 'z') #false
  puts "z �� ('a'..'j')"
end

=begin
������
=end
# ������
#each ������
ary = [1,2,3,4,5]
ary.each do |i|
   puts i
end  # 1 2 3 4 5 
#collect ������
a = [1,2,3,4,5]
b = Array.new
b = a.collect{ |x|x }
puts b # 1 2 3 4 5

a = [1,2,3,4,5]
b = a.collect{|x| 10*x}
puts b #10 20 30 40 50

=begin
�ļ��������
=end
#�ļ������������
str="Hello Ruby!"
putc str # H
puts str # Hello Ruby����ӡ����
print str # Hello Ruby!��ӡ�󲻻���

str = gets

#File.open ���������������� File.new ��������
aFile = File.new("filename", "mode")
  # ... �����ļ�
  if aFile
    content = aFile.sysread(20) # ��ȡ20���ַ�
    puts content
    aFile.syswrite("ABCDEF") # д�� "ABCDEF" ���ļ���
    aFile.rewind
    aFile.each_byte {|ch| putc ch; putc ?. } # A.B.C.D.E.F.�ַ�һ������һ������������ ch��Ȼ����ʾ����Ļ��
  else
    puts "Unable to open file!"
  end
aFile.close

File.open("filename", "mode") do |aFile|
   # ... process the file
end

#mode
#rֻ�� r+���뿪ͷ��д 
#wֻд w+��д a׷�� a+׷�Ӷ�д  # �����򴴽�


arr = IO.readlines("input.txt")
puts arr[0] # ��һ��
puts arr[1] # �ڶ���
IO.foreach("input.txt"){|block| puts block} ��
  # ���ļ� test ���������д������� block��Ȼ���������ʾ����Ļ��

# �������ļ� test1.txt Ϊ test2.txt
File.rename( "test1.txt", "test2.txt" )
# ɾ���ļ� test2.txt
File.delete("text2.txt")
#�ڴ��ļ�ǰ����ļ��Ƿ��Ѵ���
File.open("file.rb") if File::exists?( "file.rb" )
# ���� true ��false
File.file?( "text.txt" )
File::directory?( "/usr/local/bin" ) # => true # һ��Ŀ¼
File::directory?( "file.rb" ) # => false # һ���ļ�
File.readable?( "test.txt" )   # => true # �ɶ�
File.writable?( "test.txt" )   # => true # ��д
File.executable?( "test.txt" ) # => false # ��ִ��
File.zero?( "test.txt" )      # => true # ����ļ��Ƿ��СΪ��
File.size?( "text.txt" )     # => 1002 # �����ļ��Ĵ�С
File::ftype( "test.txt" )     # => file # ����ļ�������
File::ctime( "test.txt" ) # => Fri May 09 10:06:37 -0700 2008 # ����
File::mtime( "text.txt" ) # => Fri May 09 10:44:44 -0700 2008 # �޸�
File::atime( "text.txt" ) # => Fri May 09 10:45:01 -0700 2008 # ������

Dir.mkdir("mynewdir") # ����Ŀ¼
Dir.delete("testdir") # ɾ��Ŀ¼
Dir.chdir("/usr/bin") # �ı䵱ǰĿ¼Ϊ /usr/bin
puts Dir.pwd # ���ص�ǰĿ¼������ /usr/bin
puts Dir.entries("/usr/bin").join(' ') 
  # ��ȡָ��Ŀ¼�ڵ��ļ���Ŀ¼�б�, ����һ�����飬����ָ��Ŀ¼�ڵ�������
Dir.foreach("/usr/bin") do |entry|
   puts entry
end # ͬ��
Dir["/usr/bin/*"] # ͬ��

#������һ����ʱ�ļ�����������д�����ݣ�Ȼ��ɾ���ļ�
require 'tmpdir'
tempfilename = File.join(Dir.tmpdir, "tingtong")
tempfile = File.new(tempfilename, "w")
tempfile.puts "This is a temporary file"
tempfile.close
File.delete(tempfilename)

