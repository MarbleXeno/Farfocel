#include "Log.hpp"

std::vector<std::string> fr::Log::s_logMessages;
std::ofstream fr::Log::s_logFile;

const char* fr::Log::getAnsiColor(LogColor logColor)
{
	switch (logColor)
	{
	case fr::LogColor::Black:
		return "\u001b[30m";
		break;
	case fr::LogColor::Red:
		return "\u001b[31m";
		break;
	case fr::LogColor::Green:
		return "\u001b[32m";
		break;
	case fr::LogColor::Yellow:
		return "\u001b[33m";
		break;
	case fr::LogColor::Blue:
		return "\u001b[34m";
		break;
	case fr::LogColor::Magenta:
		return "\u001b[35m";
		break;
	case fr::LogColor::Cyan:
		return "\u001b[36m";
		break;
	case fr::LogColor::White:
		return "\u001b[37m";
		break;
	case fr::LogColor::Reset:
		return "\u001b[0m";
		break;
	default:
		return "\u001b[0m";
		break;
	}
}

void fr::Log::printSpace()
{
	std::cout << "\n";
}

void fr::Log::print(LogColor logColor, const bool addSpace,const std::string& message)
{
	std::string logMessage = message;
	
	s_logMessages.push_back(logMessage);
	std::cout << getAnsiColor(logColor) + logMessage + getAnsiColor(LogColor::Reset);
	if (addSpace)
	{
		printSpace();
	}
}

void fr::Log::printDebug(LogColor logColor, const bool addSpace, const std::string& message)
{
	std::string logMessage = message;
	s_logMessages.push_back(logMessage);

#ifdef FR_DEBUG
	//plus + plus + plus + plus; i hate string in c++
	std::cout << "\u001b[30;1m[DEBUG] ";
	std::cout << getAnsiColor(logColor) + logMessage + getAnsiColor(LogColor::Reset);
	if (addSpace)
	{
		printSpace();
	}
#endif // FR_DEBUG
}

void fr::Log::writeLogsToFile(std::string& directory)
{
	s_logFile.open(directory);

	for (auto i = 0; i < s_logMessages.size(); i++)
	{
		s_logFile << s_logMessages[i] << "\n";
	}

	s_logFile.close();
}
