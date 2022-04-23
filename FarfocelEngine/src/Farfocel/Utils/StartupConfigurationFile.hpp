#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

#include "Log.hpp"

namespace fr_util
{
	class StartupConfigurationFile
	{
	public:
		StartupConfigurationFile()
		{
			
		}

		~StartupConfigurationFile()
		{
			if (m_configurationFile.is_open())
				m_configurationFile.close();
		}

		void init(const std::string& directory)
		{
			m_configurationFile = std::fstream(directory);

			std::string key;
			int value;

			if (!m_configurationFile.is_open())
			{
				fr::Log::printDebug(fr::LogColor::Red, true, "StartupConfigurationFile: init -> Couldn't open file at a given directory: " + directory);
			}

			if (m_configurationFile.is_open())
			{
				while (m_configurationFile >> key >> value)
				{
					m_entries[key] = std::to_string(value);
				}

				m_configurationFile.close();
			}
		}

		const std::string& getEntry(const std::string& key)
		{
			if (m_entries.count(key))
			{
				return m_entries[key];
			}

			fr::Log::printDebug(fr::LogColor::Red, true, "StartupConfigurationFile: getEntry -> Couldn't find an entry: " + key);
			return 0;
		}
	private:
		std::fstream m_configurationFile;

		std::unordered_map <std::string, std::string> m_entries;
	};
}