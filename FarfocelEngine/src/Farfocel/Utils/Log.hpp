/*
	A simple logging class.
*/

#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
namespace fr
{
	enum class LogColor
	{
		Black = 0,
		Red,
		Green,
		Yellow,
		Blue,
		Magenta,
		Cyan,
		White,
		Reset,
	};

	class Log
	{
	public:
		static void print(LogColor logColor, const std::string& message);
		static void writeLogsToFile(std::string& directory);
	private:
		static std::vector<std::string> s_logMessages;
		static std::ofstream s_logFile;

		static const char* getAnsiColor(LogColor logColor);
	};
}