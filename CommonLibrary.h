#ifndef COMMON_LIBRARY_H_
#define COMMON_LIBRARY_H_
#include<iostream>
#include <stdlib.h>
#include<vector>
#include<string>
#include <sstream>
#include <ctime>
#include<cstdlib>
#pragma  warning(disable:4996) //终止警告
#pragma  warning(disable:4244) //终止警告
using namespace std;

/******************************************************************************************************
1.类的名称：Calculate
2.类的功能：实现一些常用算法，为外部提供功能接口
3.创建时间：2018年8月23号
4.创建作者：吴桌
5.注意事项：此类设计成为单例模式，使用该类的方法时先需要调用方法getInstance()获取该类的对象
6.类成员函数以及功能列表：
  ___________________________________________________________________________________________
  |函数功能名					函数功能介绍                                                |
  |-----------------------------------------------------------------------------------------|                              
  |	getInstance					返回该类的单例对象，是获取该类实例的唯一接口                |
  |	stringToSeperate		    字符串分割函数，获取各个字段值                              |
  |	stringToDecimal				将字符串转换为10进制整数                                    |
  |	stringToUper				将字符串全部转换为大写                                      |
  |	stringToLower				将字符串全部转换为小写                                      |
  |	Dec2String					将十进制数转为字符串                                        |
  |	Hex2String                  将十六进制数转换为字符串                                    |
  | toDelteSubStr				删除一个字符串所有满足条件的子串						    |
  | String2ReplaceSubStr_All    替换满足条件的子串					                        |




*******************************************************************************************************/
//定义数据操作的类型
enum DataScale{
	DECIMAL = 10,//十进制数据
	HEXTYPE = 16 //十六进制数据
};
//定义数据返回值类型
enum CERROR_CODE{
	CODE_SCUSSES = 0,	//返回成功
	CODE_STREMPTY = -1,	//字符串为空
	CODE_DATAERROE = -2	//数据错误
};
class Calculate{//由于没有特定的数据需要保存，设计成单例模式
public:
   /********************************************************************************************************
   1.函数功能名称：getInstance()                                                                         
   2.函数功能介绍：用来返回该类对象的实例的唯一接口，当需要使用该类的方法时，需要调用该方法获取类对象    
   3.函数参数说明：无参数                                                                                
   4.返回值的说明：返回该类的唯一对象【该类设计为单例模式】                                              
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年8月23号                                                       
   ********************************************************************************************************/
   static Calculate & getInstance();

   /********************************************************************************************************
   1.函数功能名称：stringToSeperate()                                                                         
   2.函数功能介绍：字符串分割函数，将原字符串按照分隔符进行分割，然后存储在容器vector   
   3.函数参数说明：strSrc是字符串原串； strSpeator 是字符串分隔符；strVect 是字符串分割后保存的结果                   
   4.返回值的说明：返回值返回的是分割串的个数                                             
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年8月23号                                                       
   ********************************************************************************************************/
   int stringToSeperate(string strSrc, string strSpeator, vector<string>& strVect);

   /********************************************************************************************************
   1.函数功能名称：stringToDecimal()                                                                         
   2.函数功能介绍：将数值字符串转换为对应的数值，十进制数   
   3.函数参数说明：strChar是字符串原串； DataScale 是字符串数值的类型(十进制还是十六进制可以写10或则16)                   
   4.返回值的说明：返回字符串转换后的数值                                            
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年8月26号                                                       
   ********************************************************************************************************/
   int  stringToDecimal(string strChar,DataScale data_type = DECIMAL);

   /********************************************************************************************************
   1.函数功能名称：stringToUper()                                                                         
   2.函数功能介绍：将字符串全部转换为大写   
   3.函数参数说明：strChar是字符串原串；                  
   4.返回值的说明：返回字符串转换后的字符串                                           
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年09月02号                                                       
   ********************************************************************************************************/
   string  stringToUper(string strChar);

   /********************************************************************************************************
   1.函数功能名称：stringToLower()                                                                         
   2.函数功能介绍：将字符串全部转换为小写   
   3.函数参数说明：strChar是字符串原串；                  
   4.返回值的说明：返回字符串转换后的字符串                                           
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年09月02号                                                       
   ********************************************************************************************************/
   string  stringToLower(string strChar);
   /********************************************************************************************************
   1.函数功能名称：Dec2String()                                                                         
   2.函数功能介绍：将十进制整形数据转为字符串   
   3.函数参数说明：decimal需要转换的数据；                  
   4.返回值的说明：返回字符串转换后的字符串                                           
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年09月02号                                                       
   ********************************************************************************************************/
   string  Dec2String(int decimal);
   /********************************************************************************************************
   1.函数功能名称：Hex2String()                                                                         
   2.函数功能介绍：将十六进制整形数据转为字符串   
   3.函数参数说明：hex需要转换的数据；                  
   4.返回值的说明：返回字符串转换后的字符串                                           
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年09月02号                                                       
   ********************************************************************************************************/
   string  Hex2String(long hex);
   /********************************************************************************************************
   1.函数功能名称：toDelteSubStr()                                                                         
   2.函数功能介绍：删除一个字符串的子串   
   3.函数参数说明：strSr源字符串，strSub将要删除的子串；                  
   4.返回值的说明：返回删除子串后得到的新字符串                                           
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年09月02号                                                       
   ********************************************************************************************************/
   string  toDelteSubStr(string strSrc,string strSub);
   /********************************************************************************************************
   1.函数功能名称：toDelteSubStr()                                                                         
   2.函数功能介绍：替换一个字符串的子串   
   3.函数参数说明：strSr源字符串，strSub将要被替换的子串,strNewSub用来替换的子串；                  
   4.返回值的说明：返回替换后得到的新字符串                                           
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年09月02号                                                       
   ********************************************************************************************************/
   string  String2ReplaceSubStr_All(string strSrc,string strOldSub, string strNewSub);

   /********************************************************************************************************
   1.函数功能名称：stringToDouble()                                                                         
   2.函数功能介绍：字符串转化为浮点型数据   
   3.函数参数说明：strSur源字符串；                  
   4.返回值的说明：返回得到double类型的数据                                           
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年09月03号                                                       
   ********************************************************************************************************/
   double  stringToDouble(string strSur);
   /********************************************************************************************************
   1.函数功能名称：DoubleToString()                                                                         
   2.函数功能介绍：浮点型数据转化为字符串   
   3.函数参数说明：strSur源字符串,reserve:保留小数点的位数；                  
   4.返回值的说明：返回得到double类型的数据                                           
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年09月03号                                                       
   ********************************************************************************************************/
   string  DoubleToString(double dData, int reserve = -1);
   /********************************************************************************************************
   1.函数功能名称：genRandomData()                                                                         
   2.函数功能介绍：产生0-1范围内的随机数   
   3.函数参数说明：无参数；                  
   4.返回值的说明：返回得到随机的数据                                         
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年09月05号                                                       
   ********************************************************************************************************/
   float genRandomData();//产生0-1之间的随机数

   /********************************************************************************************************
   1.函数功能名称：int genRandomData(int min, int max)                                                                        
   2.函数功能介绍：产生一定范围内的随机数   
   3.函数参数说明：min范围的下界，max：范围的上界；                  
   4.返回值的说明：返回得到随机的数据                                         
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年09月05号                                                       
   ********************************************************************************************************/
   int genRandomData(int min, int max);//产生任意范围内的随机数

   /********************************************************************************************************
   1.函数功能名称： arraySort()                                                                       
   2.函数功能介绍： 数组排序，快速排序算法  
   3.函数参数说明： arr 数组名，length数组的长度；                  
   4.返回值的说明：无返回值                                         
   5.创建作者说明：吴桌                                                                                  
   6.函数变更履历：由吴桌创建此函数，2018年09月06号                                                       
   ********************************************************************************************************/
   void arraySort(int * arr,int length);
   friend void fastSort(int * arr,int left, int length);
private:
	//单例模式，需要将构造函数声明为私有，防止外部函数进行实例化
	Calculate();
	~Calculate();
};
#endif

