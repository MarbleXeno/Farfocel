/*
	Name:
	Log

	Description:
	Prints and stores logs. Then, it can write them into a file.

	To do:
	Add better color handling.
	Add timestamps to the logs.
*/

#pragma once

#include <string>
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
		Reset
	};

	class Log
	{
	public:
		static void printSpace();
		static void print(LogColor logColor, const bool addSpace, const std::string& message);
		static void printDebug(LogColor logColor, const bool addSpace, const std::string& message);
		static void writeLogsToFile(std::string& directory);
	private:
		static std::vector<std::string> s_logMessages;
		static std::ofstream s_logFile;

		static const char* getAnsiColor(LogColor logColor);
	};
}