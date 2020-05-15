#pragma once

struct SDL_Texture;

namespace Jem {

// ===============================================================================
//
//     Wrapper for an SDL_Texture to handle creation
//
// ===============================================================================
class Texture {
public:
                       Texture();
                       Texture(const std::string& filePath);
                       ~Texture();

    SDL_Texture*       GetRawTexture() const;

private:
    std::string        mFilePath;
    SDL_Texture*       mTextureData;
};

}