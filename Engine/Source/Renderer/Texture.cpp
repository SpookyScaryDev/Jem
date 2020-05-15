#include "JemPCH.h"
#include "Texture.h"

#include <SDL.h>
#include <Renderer/Renderer.h>

namespace Jem {

// ==================
// Jem::Texture::Texture
// ==================
Texture::Texture() :
    mTextureData(nullptr) {}

// ==================
// Jem::Texture::Texture
//
// Currently only loads .bmp files.
// ==================
Texture::Texture(const std::string& filePath):
    mFilePath(filePath) {

    JEM_CORE_MESSAGE("Loading Texture \"", mFilePath, "\"");
    SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
    mTextureData = SDL_CreateTextureFromSurface(Renderer::GetRawRenderer(), surface);
    JEM_CORE_ASSERT(mTextureData, "Couldn't load texture \"" + mFilePath + "\"");

    SDL_FreeSurface(surface);
}

// ==================
// Jem::Texture::~Texture
// ==================
Texture::~Texture() {
    if (mTextureData == nullptr) {
        SDL_DestroyTexture(mTextureData);
        mTextureData = nullptr;
    }
}

// ==================
// Jem::Texture::GetRawTexture
// ==================
SDL_Texture* Texture::GetRawTexture() const {
    return mTextureData;
}

}