#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string line1 = "We were her pride of 10 she named us:";
	string line2 = "Benjamin, Phoenix, the Prodigal";
	string line3 = "and perspicacious pacific Suzanne";
	string sentence = line1+' '+line2+' '+line3;
	string separators(" \t:,\v\r\n\f");//用作分隔符的字符
	string word;
	vector<string> longestWords, shortestWords;//存放最长及最短单词的vector容器
	string::size_type maxLen, minLen, wordLen, count=0;//sentence中最长、最短单词以及下一单词的长度，单词数目
	string::size_type startPos = 0, endPos = 0;//单词的起始及结束位置

	endPos = sentence.find_first_of(separators,endPos);//首先获取第一个单词
	if(endPos == string::npos)//找不到下一个分隔符位置，即字符串只有一个单词
        wordLen = sentence.size() - startPos;
    else
        wordLen = endPos-startPos;

    word.assign( sentence.begin() + startPos, sentence.begin() + startPos + wordLen );//获取单词
    startPos = sentence.find_first_not_of(separators,endPos);//设置下次查找的起始位置
    maxLen = minLen = wordLen;//读取的是第一个单词，最长最短都是它
    longestWords.push_back( word );
    shortestWords.push_back( word );
    ++count;

	//每次循环处理sentence中的一个单词
	while( (startPos=sentence.find_first_of( separators,endPos )) != string::npos )//找到下一单词起始位置
	{
		++startPos;
		endPos = sentence.find_first_of( separators,startPos );//找到下一单词的结束位置

		if( (endPos-startPos) == 0 )//判断是否连续获取了用作分隔的字符

			;
		else
		{

			++count;

			if( endPos == string::npos )//找不到下一个分隔符位置，即该单词是最后一个单词
				wordLen = sentence.size() - startPos;
			else
				wordLen = endPos-startPos;

			word.assign( sentence.begin()+startPos,sentence.begin()+startPos+wordLen );//获取单词

			startPos = sentence.find_first_not_of( separators,endPos );//设置下次查找的起始位置

			if( wordLen > maxLen ){//当前单词比目前的最长单词更长
				maxLen = wordLen;
				longestWords.clear();//清空存放最长单词的容器
				longestWords.push_back( word );
			}
			else if( wordLen == maxLen )//当前单词与目前的最长单词等长
				longestWords.push_back( word );

			if( wordLen<minLen ){//当前单词比目前的最长单词更短
				minLen = wordLen;
				shortestWords.clear();//清空存放最短单词的容器
				shortestWords.push_back( word );
			}
			else if( wordLen == minLen )//当前单词与目前的最短单词等长
				shortestWords.push_back( word );
		}
	}

	//输出单词数目
	cout << "word amount:" << count << endl;
	vector<string>::iterator iter;

	//输出最长单词
	cout << "longest word(s):" << endl;
	iter = longestWords.begin();
	while( iter != longestWords.end() )
		cout << *iter++ << endl;

	//输出最短单词
	cout << "shortest word(s):" << endl;
	iter = shortestWords.begin();
	while( iter != shortestWords.end() )
		cout << *iter++ << endl;

	return 0;
}
