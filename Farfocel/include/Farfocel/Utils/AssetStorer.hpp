#pragma once
#include <iostream>
#include <unordered_map>
namespace fru {
	template<typename AssetType>
	class AssetStorer {
	public:
		AssetStorer() {}
		~AssetStorer() {
			for (auto asset : mAssets) {
				delete asset.second;
			}

			mAssets.clear();
		}

		template<typename Asset>
		void Add(const std::string& id, Asset* assetType) {
			if (mAssets.count(id)) {
				std::cout << "void fru::AssetStorer::Add(const std::string& id, const AssetType& assetType) --> Couldn't add an asset since given id is already occupied\n";
				return;
			}

			mAssets[id] = assetType;
		}

		AssetType* Get(const std::string& id) {
			if (!mAssets.count(id)) {
				std::cout << "AssetType* fru::AssetStorer::Get(const std::string& id) --> Couldn't find an asset with given id\n";
				return nullptr;
			}

			return mAssets[id];
		}


		
	private:
		std::unordered_map<std::string, AssetType*> mAssets;
	};
}