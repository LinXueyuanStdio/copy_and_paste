**MySQL**
<html>
<head>
<meta charset="utf-8"> 
<title>删除 MySQL 数据库</title>
</head>
<body>
<?php
//***************** 连接数据库 ******************//
$dbhost = 'localhost:3036';
$dbuser = 'root';
$dbpass = 'rootpassword';
$conn = mysql_connect($dbhost, $dbuser, $dbpass);
if (! $conn ) {
  die('连接失败: ' . mysql_error());
}
echo '连接成功<br />';
//***************** 创建数据库 ******************//
$sql = 'CREATE DATABASE RUNOOB';				 {	
$retval = mysql_query( $sql, $conn );					
if(! $retval ){
  die('创建数据库失败: ' . mysql_error());
}
echo "数据库 RUNOOB 创建成功\n";				 }
//***************** 创建数据表 ******************//
$sql = "CREATE TABLE runoob_tbl( ".
       "runoob_id INT NOT NULL AUTO_INCREMENT, ".
       "runoob_title VARCHAR(100) NOT NULL, ".
       "runoob_author VARCHAR(40) NOT NULL, ".
       "submission_date DATE, ".
       "PRIMARY KEY ( runoob_id )); ";			 {
/*
当我们需要修改数据表名或者修改数据表字段时，就需要使用到MySQL ALTER命令。
添加列
	ALTER TABLE testalter_tbl ADD i INT;
	ALTER TABLE testalter_tbl ADD i INT FIRST;
	ALTER TABLE testalter_tbl ADD i INT AFTER c;
	i 字段会自动添加到数据表字段的末尾。
	FIRST (设定位第一列)， AFTER 字段名（设定位于某个字段之后）。
删除列
	ALTER TABLE testalter_tbl  DROP i;
	如果数据表中只剩余一个字段则无法使用DROP来删除i字段。
修改字段类型及名称
	ALTER TABLE testalter_tbl MODIFY c CHAR(10);//MODIFY
	ALTER TABLE testalter_tbl CHANGE i j BIGINT;//CHANGE
	ALTER TABLE testalter_tbl CHANGE j j INT;
		//在 CHANGE 关键字之后，紧跟着的是你要修改的字段名，然后指定新字段名及类型
	ALTER TABLE testalter_tbl MODIFY j BIGINT NOT NULL DEFAULT 100;
		//对 Null 值和默认值
修改字段默认值
	ALTER TABLE testalter_tbl ALTER i SET DEFAULT 1000;//修改字段的默认值
	ALTER TABLE testalter_tbl ALTER i DROP DEFAULT;	   //删除字段的默认值，变为NULL
	
	ALTER TABLE testalter_tbl ENGINE = MYISAM;;
		//将表 testalter_tbl 的类型修改为 MYISAM 
修改表名
	ALTER TABLE testalter_tbl RENAME TO alter_tbl;
删除表中主键
	ALTER TABLE testalter_tbl DROP PRIMARY KEY;
添加主键
	ALTER TABLE testalter_tbl ADD CONSTRAINT PK_STUDENT PRIMARY KEY (id,class);
使用AUTO_INCREMENT
	INSERT INTO insect (id,name,date,origin) VALUES
    -> (NULL,'housefly','2001-09-10','kitchen'),
    -> (NULL,'millipede','2001-09-10','driveway'),
    -> (NULL,'grasshopper','2001-09-10','front yard');
获取AUTO_INCREMENT值
	mysql_query ("INSERT INTO insect (name,date,origin)
	VALUES('moth','2001-09-14','windowsill')", $conn_id);
	$seq = mysql_insert_id ($conn_id);
	通过 mysql_insert_id ()函数来获取执行的插入SQL语句中 AUTO_INCREMENT列的值
重置序列
	ALTER TABLE insect DROP id;
	-> ALTER TABLE insect
    -> ADD id INT UNSIGNED NOT NULL AUTO_INCREMENT FIRST,
    -> ADD PRIMARY KEY (id);
	如果你删除了数据表中的多条记录，
		并希望对剩下数据的AUTO_INCREMENT列进行重新排列，
	那么你可以通过删除自增的列，
		然后重新添加来实现。 
	不过该操作要非常小心，如果在删除的同时又有新记录添加，有可能会出现数据混乱
设置序列的开始值
	表创建时id INT UNSIGNED NOT NULL AUTO_INCREMENT = 100,
	表创建后ALTER TABLE t AUTO_INCREMENT = 100;
	
创建索引
	直接创建
	CREATE INDEX indexName ON mytable(username(length)); 
		如果是CHAR，VARCHAR类型，length可以小于字段实际长度；
		如果是BLOB和TEXT类型，必须指定 length。
	修改表结构
		ALTER mytable ADD INDEX [indexName] ON (username(length)) 
	创建表的时候直接指定
	CREATE TABLE mytable(  
		ID INT NOT NULL,   
		username VARCHAR(16) NOT NULL,  
		INDEX [indexName] (username(length))  
	); 
	唯一索引
		CREATE UNIQUE INDEX indexName ON mytable(username(length)) 
		ALTER table mytable ADD UNIQUE [indexName] (username(length))
		CREATE TABLE mytable(  
			ID INT NOT NULL,   
			username VARCHAR(16) NOT NULL,  
			UNIQUE [indexName] (username(length))  
		);  
添加索引
	ALTER TABLE testalter_tbl ADD INDEX index_name (name);
查看索引
	SHOW INDEX FROM testalter_tbl;
添加唯一限制条件索引
	ALTER TABLE testalter_tbl ADD UNIQUE emp_name(age);
删除索引
	ALTER TABLE testalter_tbl DROP INDEX index_name;
*/
/*
临时表
	CREATE TEMPORARY TABLE SalesSummary (...)
		临时表只在当前连接可见，当关闭连接时，Mysql会自动删除表并释放所有空间。
		若使用PHP脚本来创建MySQL临时表，那没当PHP脚本执行完成后，该临时表也会自动销毁。
*/
}
//***************** 选择数据库 ******************//
mysql_select_db( 'RUNOOB' );					 {
$retval = mysql_query( $sql, $conn );
if(! $retval ){
  die('数据表创建失败: ' . mysql_error());
}
echo "数据表创建成功\n";						 }
//***************** 查询数据 ********************//
$sql = 'SELECT runoob_id,     runoob_title, 
               runoob_author, submission_date
        FROM   runoob_tbl';						 {
/*
SELECT field1, field2,...fieldN FROM table_name1, table_name2...
[WHERE condition1 [AND [OR]] condition2.....
       /condition：/  field1 LIKE condition1 [AND [OR]] filed2 = 'somevalue'
ORDER BY field1, [field2...] [ASC [DESC]]
	//ASC 或 DESC 来设置查询结果是按升序或降序排列。默认升序排列
GROUP BY name		
	//SELECT name, COUNT(*) FROM   employee_tbl GROUP BY name;
	//在分组的列上可用 COUNT, SUM, AVG,等函数
	//**
	SELECT column_name, function(column_name)
	FROM table_name
	WHERE column_name operator value
	GROUP BY column_name;
	//**
WITH ROLLUP
	//WITH ROLLUP 可以实现在分组统计数据基础上再进行相同的统计（SUM,AVG,COUNT…）
	//SELECT name, SUM(singin) as singin_count FROM  employee_tbl GROUP BY name WITH ROLLUP;
	//SELECT coalesce(name, '总数'), SUM(singin) as singin_count FROM  employee_tbl GROUP BY name WITH ROLLUP;
[OFFSET M ][LIMIT N]
	//OFFSET指定SELECT语句开始查询的数据偏移量。默认情况下偏移量为0
	//LIMIT 属性来设定返回的记录数
$sql = 'SELECT runoob_id,	  runoob_title, 
               runoob_author, submission_date
        FROM   runoob_tbl
        WHERE  runoob_author="Sanjay"';
$sql = 'SELECT runoob_id, runoob_title, 
               runoob_author, submission_date
        FROM runoob_tbl
        WHERE runoob_author LIKE "%jay%"';
$sql = 'SELECT a.runoob_id, a.runoob_author, 
			   b.runoob_count 
		FROM   runoob_tbl a INNER JOIN tcount_tbl b 
		ON 	   a.runoob_author = b.runoob_author';
		//也可以省略 INNER，使用 JOIN，效果一样
		//inner join 取交集
		//left  join 取左集（语句中先声明的表的 数据）
		//right join 取右集
SELECT country, name FROM Websites
WHERE country='CN'
UNION ALL   //DISTINCT: 可选，删除结果集中重复的数据。默认情况下 UNION 操作符已经删除了重复数据，所以 DISTINCT 修饰符对结果没啥影响。
			//ALL:		可选，返回所有结果集，包含重复数据。
SELECT country, app_name FROM apps
WHERE country='CN'
ORDER BY country;
|--------+---------|
|country +  name   |
|--------+---------|
|CN      +淘宝 web |
|CN      +淘宝 app |
|CN      +QQ web   |
|CN      +QQ app   |
|--------+---------|
//正则表达式
//查找name字段中以元音字符开头或以'ok'字符串结尾的所有数据
SELECT name FROM person_tbl WHERE name REGEXP '^[aeiou]|ok$';
*/
mysql_select_db('RUNOOB');
$retval = mysql_query( $sql, $conn );
if(! $retval ){
  die('Could not get data: ' . mysql_error());
}
//MYSQL_NUM   返回数字数组
//MYSQL_ASSOC 返回关联数组
while($row = mysql_fetch_array($retval, MYSQL_ASSOC)){// mysql_fetch_assoc($retval)
    echo "Tutorial ID :{$row['runoob_id']}  <br> ".
         "Title: {$row['runoob_title']} <br> ".
         "Author: {$row['runoob_author']} <br> ".
         "Submission Date : {$row['submission_date']} <br> ".
         "--------------------------------<br>";
} 
//执行完SELECT语句后，释放游标内存是一个很好的习惯
mysql_free_result($retval);
echo "Fetched data successfully\n";				}
//***************** 插入数据 ********************//
$sql = "INSERT INTO runoob_tbl ".
       "(runoob_title,runoob_author, submission_date) ".
       "VALUES ".
       "('$runoob_title','$runoob_author','$submission_date')";{
/*
防止表中出现重复数据
	1.CREATE TABLE person_tbl(
		first_name CHAR(20) NOT NULL,
		last_name CHAR(20) NOT NULL,
		sex CHAR(10),
		PRIMARY KEY (last_name, first_name)
	  );
	  设置指定的字段为 PRIMARY KEY（主键） 或者 UNIQUE（唯一） 索引来保证数据的唯一性
	  设置表中字段first_name，last_name数据不能重复，双主键模式保证
	  如果我们设置了唯一索引，那么在插入重复数据时，SQL语句将无法执行成功,并抛出错。数据的唯一性
	  忽略数据库中已经存在的数据
	2.INSERT IGNORE INTO person_tbl (last_name, first_name)VALUES( 'Jay', 'Thomas');
	  INSERT IGNORE INTO当插入数据时，在设置了记录的唯一性后，
	  如果插入重复数据，将不返回错误，只以警告形式返回。 
	  而REPLACE INTO into
	  如果存在primary 或 unique相同的记录，则先删除掉。
	  再插入新记录。
	3.添加一个UNIQUE索引
	  CREATE TABLE person_tbl(
		first_name CHAR(20) NOT NULL,
		last_name CHAR(20) NOT NULL,
		sex CHAR(10)
		UNIQUE (last_name, first_name)
	  );
统计重复数据
	SELECT COUNT(*) as repetitions, last_name, first_name//COUNT(*)列出可能有重复数据的列
    -> FROM person_tbl
    -> GROUP BY last_name, first_name
    -> HAVING repetitions > 1;//HAVING子句设置重复数大于1
过滤重复数据
	使用DISTINCT
		SELECT DISTINCT last_name, first_name
		-> FROM person_tbl
		-> ORDER BY last_name;
	使用 GROUP BY 来读取数据表中不重复的数据
		SELECT last_name, first_name
		-> FROM person_tbl
		-> GROUP BY (last_name, first_name);
删除重复数据
	mysql> CREATE TABLE tmp SELECT last_name, first_name, sex
    ->                  FROM person_tbl;
    ->                  GROUP BY (last_name, first_name);
	mysql> DROP TABLE person_tbl;
	mysql> ALTER TABLE tmp RENAME TO person_tbl;
	或者添加 INDEX（索引） 和 PRIMAY KEY（主键）
	mysql> ALTER IGNORE TABLE person_tbl
    -> ADD PRIMARY KEY (last_name, first_name);
*/
mysql_select_db('RUNOOB');
$retval = mysql_query( $sql, $conn );
if(! $retval ){
  die('Could not enter data: ' . mysql_error());
}
	   echo "Entered data successfully\n";}
//***************** 更新数据 ******************//
$sql = 'UPDATE runoob_tbl
        SET runoob_title="Learning JAVA"
        WHERE runoob_id=3';
//***************** 删除数据 ******************//	
$sql = 'DELETE FROM runoob_tbl
        WHERE runoob_id=3';
//***************** 删除数据表 ******************//
$sql = "DROP TABLE runoob_tbl";					{
mysql_select_db( 'RUNOOB' );
$retval = mysql_query( $sql, $conn );
if(! $retval ){
  die('数据表删除失败: ' . mysql_error());
}
echo "数据表删除成功\n";}

//***************** 删除数据库 ******************//
$sql = 'DROP DATABASE RUNOOB';					 {
$retval = mysql_query( $sql, $conn );
if(! $retval ){
  die('删除数据库失败: ' . mysql_error());
}
echo "数据库 RUNOOB 删除成功\n";}
//***************** 关闭数据库 ******************//
mysql_close($conn);


//***************** 事务 *******************//
$handler=mysql_connect("localhost","root","password");
mysql_select_db("task");
mysql_query("SET AUTOCOMMIT=0");//设置为不自动提交，因为MYSQL默认立即执行
mysql_query("BEGIN");//开始事务定义
if(!mysql_query("insert into trans (id) values('2')")){
	mysql_query("ROLLBACK");//判断当执行失败时回滚
}
if(!mysql_query("insert into trans (id) values('4')")){
	mysql_query("ROLLBACK");//判断执行失败回滚
}
mysql_query("COMMIT");//执行事务
mysql_close($handler);

//***************** 复制表 *******************//
//步骤一：获取数据表的完整结构
SHOW CREATE TABLE runoob_tbl \G;
//步骤二：修改SQL语句的数据表名，并执行SQL语句。
//从步骤一的显示中直接抄
CREATE TABLE `runoob_tbl` (
  `runoob_id` int(11) NOT NULL auto_increment,
  `runoob_title` varchar(100) NOT NULL default '',
  `runoob_author` varchar(40) NOT NULL default '',
  `submission_date` date default NULL,
  PRIMARY KEY  (`runoob_id`),
  UNIQUE KEY `AUTHOR_INDEX` (`runoob_author`)
) ENGINE=InnoDB 
//步骤三：执行完第二步骤后，你将在数据库中创建新的克隆表 clone_tbl。 
//如果你想拷贝数据表的数据你可以使用 INSERT INTO... SELECT 语句来实现。
INSERT INTO clone_tbl (runoob_id,
                       runoob_title,
                       runoob_author,
                       submission_date)
    SELECT runoob_id,runoob_title,
           runoob_author,submission_date
    FROM   runoob_tbl;
	
//***************** 元数据 ****************//
		获取服务器元数据
命令				描述
SELECT VERSION( )	服务器版本信息
SELECT DATABASE( )	当前数据库名 (或者返回空)
SELECT USER( )		当前用户名
SHOW STATUS			服务器状态
SHOW VARIABLES		服务器配置变量

//***************** 导出数据 ****************//
mysql> SELECT * FROM passwd     INTO OUTFILE '/tmp/tutorials.txt'
    -> FIELDS TERMINATED BY ',' ENCLOSED BY '"'
    -> LINES  TERMINATED BY '\r\n';
	//在UNIX中，该文件被创建后是可读的，权限由MySQL服务器所拥有。
	//这意味着，虽然你就可以读取该文件，但可能无法将其删除。

//***************** 导出数据 ****************//
LOAD DATA LOCAL INFILE 'dump.txt' INTO TABLE mytbl;
	//指定LOCAL关键词，表明从客户主机上按路径读取文件。
	//如果没有指定，则文件在服务器上按路径读取文件
mysql> LOAD DATA LOCAL INFILE 'dump.txt' INTO TABLE mytbl
  -> FIELDS TERMINATED BY ':'
  -> LINES TERMINATED BY '\r\n';
	//如果用户指定一个 FIELDS 子句，
	//它的子句 （TERMINATED BY、[OPTIONALLY] ENCLOSED BY 和 ESCAPED BY) 也是可选的，
	//用户必须至少指定它们中的一个。
mysql> LOAD DATA LOCAL INFILE 'dump.txt' 
    -> INTO TABLE mytbl (b, c, a);
	//在数据文件中的列顺序是 a,b,c，但在插入表的列顺序为b,c,a，则数据导入语法如下：

?>
</body>
</html>

