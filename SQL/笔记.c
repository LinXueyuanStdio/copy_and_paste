**MySQL**
<html>
<head>
<meta charset="utf-8"> 
<title>ɾ�� MySQL ���ݿ�</title>
</head>
<body>
<?php
//***************** �������ݿ� ******************//
$dbhost = 'localhost:3036';
$dbuser = 'root';
$dbpass = 'rootpassword';
$conn = mysql_connect($dbhost, $dbuser, $dbpass);
if (! $conn ) {
  die('����ʧ��: ' . mysql_error());
}
echo '���ӳɹ�<br />';
//***************** �������ݿ� ******************//
$sql = 'CREATE DATABASE RUNOOB';				 {	
$retval = mysql_query( $sql, $conn );					
if(! $retval ){
  die('�������ݿ�ʧ��: ' . mysql_error());
}
echo "���ݿ� RUNOOB �����ɹ�\n";				 }
//***************** �������ݱ� ******************//
$sql = "CREATE TABLE runoob_tbl( ".
       "runoob_id INT NOT NULL AUTO_INCREMENT, ".
       "runoob_title VARCHAR(100) NOT NULL, ".
       "runoob_author VARCHAR(40) NOT NULL, ".
       "submission_date DATE, ".
       "PRIMARY KEY ( runoob_id )); ";			 {
/*
��������Ҫ�޸����ݱ��������޸����ݱ��ֶ�ʱ������Ҫʹ�õ�MySQL ALTER���
�����
	ALTER TABLE testalter_tbl ADD i INT;
	ALTER TABLE testalter_tbl ADD i INT FIRST;
	ALTER TABLE testalter_tbl ADD i INT AFTER c;
	i �ֶλ��Զ���ӵ����ݱ��ֶε�ĩβ��
	FIRST (�趨λ��һ��)�� AFTER �ֶ������趨λ��ĳ���ֶ�֮�󣩡�
ɾ����
	ALTER TABLE testalter_tbl  DROP i;
	������ݱ���ֻʣ��һ���ֶ����޷�ʹ��DROP��ɾ��i�ֶΡ�
�޸��ֶ����ͼ�����
	ALTER TABLE testalter_tbl MODIFY c CHAR(10);//MODIFY
	ALTER TABLE testalter_tbl CHANGE i j BIGINT;//CHANGE
	ALTER TABLE testalter_tbl CHANGE j j INT;
		//�� CHANGE �ؼ���֮�󣬽����ŵ�����Ҫ�޸ĵ��ֶ�����Ȼ��ָ�����ֶ���������
	ALTER TABLE testalter_tbl MODIFY j BIGINT NOT NULL DEFAULT 100;
		//�� Null ֵ��Ĭ��ֵ
�޸��ֶ�Ĭ��ֵ
	ALTER TABLE testalter_tbl ALTER i SET DEFAULT 1000;//�޸��ֶε�Ĭ��ֵ
	ALTER TABLE testalter_tbl ALTER i DROP DEFAULT;	   //ɾ���ֶε�Ĭ��ֵ����ΪNULL
	
	ALTER TABLE testalter_tbl ENGINE = MYISAM;;
		//���� testalter_tbl �������޸�Ϊ MYISAM 
�޸ı���
	ALTER TABLE testalter_tbl RENAME TO alter_tbl;
ɾ����������
	ALTER TABLE testalter_tbl DROP PRIMARY KEY;
�������
	ALTER TABLE testalter_tbl ADD CONSTRAINT PK_STUDENT PRIMARY KEY (id,class);
ʹ��AUTO_INCREMENT
	INSERT INTO insect (id,name,date,origin) VALUES
    -> (NULL,'housefly','2001-09-10','kitchen'),
    -> (NULL,'millipede','2001-09-10','driveway'),
    -> (NULL,'grasshopper','2001-09-10','front yard');
��ȡAUTO_INCREMENTֵ
	mysql_query ("INSERT INTO insect (name,date,origin)
	VALUES('moth','2001-09-14','windowsill')", $conn_id);
	$seq = mysql_insert_id ($conn_id);
	ͨ�� mysql_insert_id ()��������ȡִ�еĲ���SQL����� AUTO_INCREMENT�е�ֵ
��������
	ALTER TABLE insect DROP id;
	-> ALTER TABLE insect
    -> ADD id INT UNSIGNED NOT NULL AUTO_INCREMENT FIRST,
    -> ADD PRIMARY KEY (id);
	�����ɾ�������ݱ��еĶ�����¼��
		��ϣ����ʣ�����ݵ�AUTO_INCREMENT�н����������У�
	��ô�����ͨ��ɾ���������У�
		Ȼ�����������ʵ�֡� 
	�����ò���Ҫ�ǳ�С�ģ������ɾ����ͬʱ�����¼�¼��ӣ��п��ܻ�������ݻ���
�������еĿ�ʼֵ
	����ʱid INT UNSIGNED NOT NULL AUTO_INCREMENT = 100,
	������ALTER TABLE t AUTO_INCREMENT = 100;
	
��������
	ֱ�Ӵ���
	CREATE INDEX indexName ON mytable(username(length)); 
		�����CHAR��VARCHAR���ͣ�length����С���ֶ�ʵ�ʳ��ȣ�
		�����BLOB��TEXT���ͣ�����ָ�� length��
	�޸ı�ṹ
		ALTER mytable ADD INDEX [indexName] ON (username(length)) 
	�������ʱ��ֱ��ָ��
	CREATE TABLE mytable(  
		ID INT NOT NULL,   
		username VARCHAR(16) NOT NULL,  
		INDEX [indexName] (username(length))  
	); 
	Ψһ����
		CREATE UNIQUE INDEX indexName ON mytable(username(length)) 
		ALTER table mytable ADD UNIQUE [indexName] (username(length))
		CREATE TABLE mytable(  
			ID INT NOT NULL,   
			username VARCHAR(16) NOT NULL,  
			UNIQUE [indexName] (username(length))  
		);  
�������
	ALTER TABLE testalter_tbl ADD INDEX index_name (name);
�鿴����
	SHOW INDEX FROM testalter_tbl;
���Ψһ������������
	ALTER TABLE testalter_tbl ADD UNIQUE emp_name(age);
ɾ������
	ALTER TABLE testalter_tbl DROP INDEX index_name;
*/
/*
��ʱ��
	CREATE TEMPORARY TABLE SalesSummary (...)
		��ʱ��ֻ�ڵ�ǰ���ӿɼ������ر�����ʱ��Mysql���Զ�ɾ�����ͷ����пռ䡣
		��ʹ��PHP�ű�������MySQL��ʱ����û��PHP�ű�ִ����ɺ󣬸���ʱ��Ҳ���Զ����١�
*/
}
//***************** ѡ�����ݿ� ******************//
mysql_select_db( 'RUNOOB' );					 {
$retval = mysql_query( $sql, $conn );
if(! $retval ){
  die('���ݱ���ʧ��: ' . mysql_error());
}
echo "���ݱ����ɹ�\n";						 }
//***************** ��ѯ���� ********************//
$sql = 'SELECT runoob_id,     runoob_title, 
               runoob_author, submission_date
        FROM   runoob_tbl';						 {
/*
SELECT field1, field2,...fieldN FROM table_name1, table_name2...
[WHERE condition1 [AND [OR]] condition2.....
       /condition��/  field1 LIKE condition1 [AND [OR]] filed2 = 'somevalue'
ORDER BY field1, [field2...] [ASC [DESC]]
	//ASC �� DESC �����ò�ѯ����ǰ�����������С�Ĭ����������
GROUP BY name		
	//SELECT name, COUNT(*) FROM   employee_tbl GROUP BY name;
	//�ڷ�������Ͽ��� COUNT, SUM, AVG,�Ⱥ���
	//**
	SELECT column_name, function(column_name)
	FROM table_name
	WHERE column_name operator value
	GROUP BY column_name;
	//**
WITH ROLLUP
	//WITH ROLLUP ����ʵ���ڷ���ͳ�����ݻ������ٽ�����ͬ��ͳ�ƣ�SUM,AVG,COUNT����
	//SELECT name, SUM(singin) as singin_count FROM  employee_tbl GROUP BY name WITH ROLLUP;
	//SELECT coalesce(name, '����'), SUM(singin) as singin_count FROM  employee_tbl GROUP BY name WITH ROLLUP;
[OFFSET M ][LIMIT N]
	//OFFSETָ��SELECT��俪ʼ��ѯ������ƫ������Ĭ�������ƫ����Ϊ0
	//LIMIT �������趨���صļ�¼��
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
		//Ҳ����ʡ�� INNER��ʹ�� JOIN��Ч��һ��
		//inner join ȡ����
		//left  join ȡ�󼯣�������������ı�� ���ݣ�
		//right join ȡ�Ҽ�
SELECT country, name FROM Websites
WHERE country='CN'
UNION ALL   //DISTINCT: ��ѡ��ɾ����������ظ������ݡ�Ĭ������� UNION �������Ѿ�ɾ�����ظ����ݣ����� DISTINCT ���η��Խ��ûɶӰ�졣
			//ALL:		��ѡ���������н�����������ظ����ݡ�
SELECT country, app_name FROM apps
WHERE country='CN'
ORDER BY country;
|--------+---------|
|country +  name   |
|--------+---------|
|CN      +�Ա� web |
|CN      +�Ա� app |
|CN      +QQ web   |
|CN      +QQ app   |
|--------+---------|
//������ʽ
//����name�ֶ�����Ԫ���ַ���ͷ����'ok'�ַ�����β����������
SELECT name FROM person_tbl WHERE name REGEXP '^[aeiou]|ok$';
*/
mysql_select_db('RUNOOB');
$retval = mysql_query( $sql, $conn );
if(! $retval ){
  die('Could not get data: ' . mysql_error());
}
//MYSQL_NUM   ������������
//MYSQL_ASSOC ���ع�������
while($row = mysql_fetch_array($retval, MYSQL_ASSOC)){// mysql_fetch_assoc($retval)
    echo "Tutorial ID :{$row['runoob_id']}  <br> ".
         "Title: {$row['runoob_title']} <br> ".
         "Author: {$row['runoob_author']} <br> ".
         "Submission Date : {$row['submission_date']} <br> ".
         "--------------------------------<br>";
} 
//ִ����SELECT�����ͷ��α��ڴ���һ���ܺõ�ϰ��
mysql_free_result($retval);
echo "Fetched data successfully\n";				}
//***************** �������� ********************//
$sql = "INSERT INTO runoob_tbl ".
       "(runoob_title,runoob_author, submission_date) ".
       "VALUES ".
       "('$runoob_title','$runoob_author','$submission_date')";{
/*
��ֹ���г����ظ�����
	1.CREATE TABLE person_tbl(
		first_name CHAR(20) NOT NULL,
		last_name CHAR(20) NOT NULL,
		sex CHAR(10),
		PRIMARY KEY (last_name, first_name)
	  );
	  ����ָ�����ֶ�Ϊ PRIMARY KEY�������� ���� UNIQUE��Ψһ�� ��������֤���ݵ�Ψһ��
	  ���ñ����ֶ�first_name��last_name���ݲ����ظ���˫����ģʽ��֤
	  �������������Ψһ��������ô�ڲ����ظ�����ʱ��SQL��佫�޷�ִ�гɹ�,���׳������ݵ�Ψһ��
	  �������ݿ����Ѿ����ڵ�����
	2.INSERT IGNORE INTO person_tbl (last_name, first_name)VALUES( 'Jay', 'Thomas');
	  INSERT IGNORE INTO����������ʱ���������˼�¼��Ψһ�Ժ�
	  ��������ظ����ݣ��������ش���ֻ�Ծ�����ʽ���ء� 
	  ��REPLACE INTO into
	  �������primary �� unique��ͬ�ļ�¼������ɾ������
	  �ٲ����¼�¼��
	3.���һ��UNIQUE����
	  CREATE TABLE person_tbl(
		first_name CHAR(20) NOT NULL,
		last_name CHAR(20) NOT NULL,
		sex CHAR(10)
		UNIQUE (last_name, first_name)
	  );
ͳ���ظ�����
	SELECT COUNT(*) as repetitions, last_name, first_name//COUNT(*)�г��������ظ����ݵ���
    -> FROM person_tbl
    -> GROUP BY last_name, first_name
    -> HAVING repetitions > 1;//HAVING�Ӿ������ظ�������1
�����ظ�����
	ʹ��DISTINCT
		SELECT DISTINCT last_name, first_name
		-> FROM person_tbl
		-> ORDER BY last_name;
	ʹ�� GROUP BY ����ȡ���ݱ��в��ظ�������
		SELECT last_name, first_name
		-> FROM person_tbl
		-> GROUP BY (last_name, first_name);
ɾ���ظ�����
	mysql> CREATE TABLE tmp SELECT last_name, first_name, sex
    ->                  FROM person_tbl;
    ->                  GROUP BY (last_name, first_name);
	mysql> DROP TABLE person_tbl;
	mysql> ALTER TABLE tmp RENAME TO person_tbl;
	������� INDEX�������� �� PRIMAY KEY��������
	mysql> ALTER IGNORE TABLE person_tbl
    -> ADD PRIMARY KEY (last_name, first_name);
*/
mysql_select_db('RUNOOB');
$retval = mysql_query( $sql, $conn );
if(! $retval ){
  die('Could not enter data: ' . mysql_error());
}
	   echo "Entered data successfully\n";}
//***************** �������� ******************//
$sql = 'UPDATE runoob_tbl
        SET runoob_title="Learning JAVA"
        WHERE runoob_id=3';
//***************** ɾ������ ******************//	
$sql = 'DELETE FROM runoob_tbl
        WHERE runoob_id=3';
//***************** ɾ�����ݱ� ******************//
$sql = "DROP TABLE runoob_tbl";					{
mysql_select_db( 'RUNOOB' );
$retval = mysql_query( $sql, $conn );
if(! $retval ){
  die('���ݱ�ɾ��ʧ��: ' . mysql_error());
}
echo "���ݱ�ɾ���ɹ�\n";}

//***************** ɾ�����ݿ� ******************//
$sql = 'DROP DATABASE RUNOOB';					 {
$retval = mysql_query( $sql, $conn );
if(! $retval ){
  die('ɾ�����ݿ�ʧ��: ' . mysql_error());
}
echo "���ݿ� RUNOOB ɾ���ɹ�\n";}
//***************** �ر����ݿ� ******************//
mysql_close($conn);


//***************** ���� *******************//
$handler=mysql_connect("localhost","root","password");
mysql_select_db("task");
mysql_query("SET AUTOCOMMIT=0");//����Ϊ���Զ��ύ����ΪMYSQLĬ������ִ��
mysql_query("BEGIN");//��ʼ������
if(!mysql_query("insert into trans (id) values('2')")){
	mysql_query("ROLLBACK");//�жϵ�ִ��ʧ��ʱ�ع�
}
if(!mysql_query("insert into trans (id) values('4')")){
	mysql_query("ROLLBACK");//�ж�ִ��ʧ�ܻع�
}
mysql_query("COMMIT");//ִ������
mysql_close($handler);

//***************** ���Ʊ� *******************//
//����һ����ȡ���ݱ�������ṹ
SHOW CREATE TABLE runoob_tbl \G;
//��������޸�SQL�������ݱ�������ִ��SQL��䡣
//�Ӳ���һ����ʾ��ֱ�ӳ�
CREATE TABLE `runoob_tbl` (
  `runoob_id` int(11) NOT NULL auto_increment,
  `runoob_title` varchar(100) NOT NULL default '',
  `runoob_author` varchar(40) NOT NULL default '',
  `submission_date` date default NULL,
  PRIMARY KEY  (`runoob_id`),
  UNIQUE KEY `AUTHOR_INDEX` (`runoob_author`)
) ENGINE=InnoDB 
//��������ִ����ڶ�������㽫�����ݿ��д����µĿ�¡�� clone_tbl�� 
//������뿽�����ݱ�����������ʹ�� INSERT INTO... SELECT �����ʵ�֡�
INSERT INTO clone_tbl (runoob_id,
                       runoob_title,
                       runoob_author,
                       submission_date)
    SELECT runoob_id,runoob_title,
           runoob_author,submission_date
    FROM   runoob_tbl;
	
//***************** Ԫ���� ****************//
		��ȡ������Ԫ����
����				����
SELECT VERSION( )	�������汾��Ϣ
SELECT DATABASE( )	��ǰ���ݿ��� (���߷��ؿ�)
SELECT USER( )		��ǰ�û���
SHOW STATUS			������״̬
SHOW VARIABLES		���������ñ���

//***************** �������� ****************//
mysql> SELECT * FROM passwd     INTO OUTFILE '/tmp/tutorials.txt'
    -> FIELDS TERMINATED BY ',' ENCLOSED BY '"'
    -> LINES  TERMINATED BY '\r\n';
	//��UNIX�У����ļ����������ǿɶ��ģ�Ȩ����MySQL��������ӵ�С�
	//����ζ�ţ���Ȼ��Ϳ��Զ�ȡ���ļ����������޷�����ɾ����

//***************** �������� ****************//
LOAD DATA LOCAL INFILE 'dump.txt' INTO TABLE mytbl;
	//ָ��LOCAL�ؼ��ʣ������ӿͻ������ϰ�·����ȡ�ļ���
	//���û��ָ�������ļ��ڷ������ϰ�·����ȡ�ļ�
mysql> LOAD DATA LOCAL INFILE 'dump.txt' INTO TABLE mytbl
  -> FIELDS TERMINATED BY ':'
  -> LINES TERMINATED BY '\r\n';
	//����û�ָ��һ�� FIELDS �Ӿ䣬
	//�����Ӿ� ��TERMINATED BY��[OPTIONALLY] ENCLOSED BY �� ESCAPED BY) Ҳ�ǿ�ѡ�ģ�
	//�û���������ָ�������е�һ����
mysql> LOAD DATA LOCAL INFILE 'dump.txt' 
    -> INTO TABLE mytbl (b, c, a);
	//�������ļ��е���˳���� a,b,c�����ڲ�������˳��Ϊb,c,a�������ݵ����﷨���£�

?>
</body>
</html>

