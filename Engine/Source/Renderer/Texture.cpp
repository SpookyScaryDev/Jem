#include "JemPCH.h"
#include "Texture.h"

#include <SDL.h>
#include <Renderer/Renderer.h>

namespace Jem {

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

    SDL_QueryTexture(mTextureData, nullptr, nullptr, &mWidth, &mHeight);
}

// ==================
// Jem::Texture::Texture
// ==================
Texture::Texture(SDL_Texture* texture) :
    mFilePath("") {

    mTextureData = texture;
    SDL_QueryTexture(mTextureData, nullptr, nullptr, &mWidth, &mHeight);
}

// ==================
// Jem::Texture::~Texture
// ==================
Texture::~Texture() {
    if (mTextureData != nullptr) {
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

// ==================
// Jem::Texture::GetWidth
// ==================
int Texture::GetWidth() const {
    return mWidth;
}

// ==================
// Jem::Texture::GetHeight
// ==================
int Texture::GetHeight() const {
    return mHeight;
}

}