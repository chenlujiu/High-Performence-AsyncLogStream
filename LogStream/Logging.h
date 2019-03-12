// @Author Chenlujiu
// @Email 434425042@qq.com
#pragma once
#include"LogStream.h"
#include<pthread.h>
#include<string.h>
#include<string>
#include<stdio.h>

class AsyncLogging;

class Logger
{
public:
	Logger(const char *fileName,int line);
	~Logger();
	LogStream& stream()
	{
		return impl_.stream_;
	}
	static void setLogFileName(std:: string fileName)
	{
		logFileName_=fileName;
	}
	static std::string getLogFileName()
	{
		return logFileName_;
	}
private:
	class Impl
	{
	public:
		Impl(const char* fileName,int line);
		void formatTime();

		LogStream  stream_;
		int line_;
		std:: string basename_;
	};
	Impl impl_;
	static std::string logFileName_;
};

#define LOG Logger(__FILE__,__LINE__).stream()