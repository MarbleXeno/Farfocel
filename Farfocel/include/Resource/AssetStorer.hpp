
#pragma once
#include <iostream>
#include <unordered_map>
#include <memory>

namespace fru
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
			return nullptr;
		}

	private:
		std::unordered_map<std::string, std::shared_ptr<AssetA>> m_assetMap;
	};
}