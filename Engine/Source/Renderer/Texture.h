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
                       Texture(const std::string& filePath);
                       Texture(SDL_Texture* texture);
                       ~Texture();

    SDL_Texture*       GetRawTexture() const;
    int                GetWidth() const;
    int                GetHeight() const;

private:
    std::string        mFilePath;
    SDL_Texture*       mTextureData;
    int                mWidth;
    int                mHeight;
};

}