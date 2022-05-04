/*
	Name:
	Asset

	Description:
	Stores an individual type of asset.

	Used by:
	ResourceManager
*/

#pragma once
#include <iostream>
#include <unordered_map>
#include <memory>

#include "../Log.hpp"

namespace fr_util
{
	template<typename AssetA>
	class AssetManager
	{
	public:
		AssetManager() {}
		~AssetManager() {}

		template<typename AssetB>
		void add(const std::string& id, std::unique_ptr<AssetB> asset)
		{
			if (m_assetMap.count(id))
			{
				fr::Log::printDebug(fr::LogColor::Red, true, "AssetManager: add -> There's already an asset with the same name.");
				return;
			}


			m_assetMap[id] = std::move(asset);
		}

		template<typename AssetB>
		std::shared_ptr<AssetB> get(const std::string& id)
		{
			if (m_assetMap.count(id))
			{
				auto asset = m_assetMap.find(id);
				return asset->second;
			}

			fr::Log::printDebug(fr::LogColor::Red, true, "AssetManager: get -> Couldn't find an asset with the given id, returning a nullptr.");
			return nullptr;
		}

	private:
		std::unordered_map<std::string, std::shared_ptr<AssetA>> m_assetMap;
	};
}