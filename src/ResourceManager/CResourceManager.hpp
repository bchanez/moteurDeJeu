#pragma once

#include <map>
#include "../Tools/DEBUG.hpp"

template<typename Enum, typename Resource>

class CResourceManager
{
	public:
		explicit CResourceManager()
		{
  		LOG("CResourceManager Constructor\n");
		}

		virtual ~CResourceManager()
		{
  		LOG("CResourceManager Destructor\n");
		}

		const Resource& get(Enum name) const
		{
			return m_resources.at(name);
		}

	protected:
		void addResource(Enum name, const std::string& filePath)
		{
			Resource res;
			res.loadFromFile(filePath);
			m_resources.insert(std::make_pair(name, res));
		}

	private:
		std::map <Enum, Resource> m_resources;

};
