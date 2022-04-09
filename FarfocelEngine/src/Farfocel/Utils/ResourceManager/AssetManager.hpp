#pragma once
#include <iostream>
#include <unordered_map>

#include "../Log.hpp"

namespace fr_util
{
	template<typename T>
	class AssetManager
	{
	public:
		AssetManager() {}
		~AssetManager() {}

		template<typename T>
		void add(const std::string& id, std::unique_ptr<T> asset)
		{
			if (m_assetMap.count(id))
			{
				fr::Log::print(fr::LogColor::Red, "AssetManager -> There's already an asset with the same name.");
				return;
			}

			m_assetMap[id] = std::move(asset);
		}

		template<typename T>
		std::shared_ptr<T> get(const std::string& id)
		{
			if (m_assetMap.count(id))
			{
				auto asset = m_assetMap.find(id);
				return asset->second;
			}

			fr::Log::print(fr::LogColor::Red, "AssetManager -> Couldn't find the asset with the given id, returning a nullptr.");
			return nullptr;
		}

	private:
		std::unordered_map<std::string, std::shared_ptr<T>> m_assetMap;
	};
}