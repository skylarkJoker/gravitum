template <typename Resource, typename Identifier>

void ResourceLoader<Resource, Identifier>::load(Identifier id, const std::string &filename)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename))
    {
        throw std::runtime_error("ResourceLoader::load - Failed to load " + filename);
    }

    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceLoader<Resource, Identifier>::load(Identifier id, const std::string &filename, const Parameter &parameter)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename, parameter))
    {
        throw std::runtime_error("ResourceLoader::load - Failed to load " + filename);
    }

    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}

template <typename Resource, typename Identifier>
Resource &ResourceLoader<Resource, Identifier>::get(Identifier id)
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *found->second;
}

//for loading const types
template <typename Resource, typename Identifier>
const Resource &ResourceLoader<Resource, Identifier>::get(Identifier id) const
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end());
    return *found->second;
}