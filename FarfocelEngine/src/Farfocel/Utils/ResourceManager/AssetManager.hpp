/*
	An Asset Manager. Used by Resource Manager. It can store different types of assets.
*/

#pragma once
#include <iostream>
#include <unordered_map>
#include <memory>

#include "../Log.hpp"

namespace fr_util
{
	template<typename AssetC>
	class AssetManager
	{
	public:
		AssetManager() {}
		~AssetManager() {}

		template<typename AssetD>
		void add(const std::string& id, std::unique_ptr<AssetD> asset)
		{
			if (m_assetMap.count(id))
			{
				fr::Log::printDebug(fr::LogColor::Red, true, "AssetManager -> There's already an asset with the same name.");
				return;
			}

			m_assetMap[id] = std::move(asset);
		}

		template<typename AssetD>
		std::shared_ptr<AssetD> get(const std::string& id)
		{
			if (m_assetMap.count(id))
			{
				auto asset = m_assetMap.find(id);
				return asset->second;
			}

			fr::Log::printDebug(fr::LogColor::Red, true, "AssetManager -> Couldn't find the asset with the given id, returning a nullptr.");
			return nullptr;
		}

	private:
		std::unordered_map<std::string, std::shared_ptr<AssetC>> m_assetMap;
	};
}