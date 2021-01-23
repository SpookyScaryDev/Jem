#include "JemPCH.h"
#include "Font.h"

#include <SDL_ttf.h>
#include <Renderer/Renderer.h>
#include <Renderer/Texture.h>


namespace Jem {


// ==================
// Font::Font
//
// Currently only loads TTF files.
// ==================
Font::Font(const char* name, unsigned int size, bool isMonoSpace) :
    mTextureAtlas(nullptr) {

    LoadTTF(name, size, isMonoSpace);
}

// ==================
// Font::~Font
// ==================
Font::~Font() {
    delete mTextureAtlas;
    mTextureAtlas = nullptr;
}

// ==================
// Font::LoadTTF
//
// Generates a texture atlas of all characters and an array of clips for each character
// from a TTF file.
// ==================
void Font::LoadTTF(const char* name, unsigned int size, bool isMonoSpace) {
    if (mTextureAtlas != nullptr) {
        delete mTextureAtlas;
    }
    JEM_CORE_MESSAGE("Loading Font \"",  name, "\"");

    TTF_Font* font = TTF_OpenFont(name, size);
    JEM_CORE_ASSERT(font, "Renderer::SetFont: Failed to load font ", name);

    char characterArray[] = " ";
    char* character = characterArray;
    int width = 0;
    int height = 0;
    int maxWidth = 0;
    int maxHeight = 0;

    // Get width and height for each character.
    // Get space first so width can be used for mono space fonts,
    TTF_SizeText(font, " ", &width, &height);
    mClips[0].size.x = width;
    mClips[0].size.y = height;
    maxWidth = width;
    maxHeight = height;

    // Go through the rest of the characters.
    for (int i = 33; i < 127; i++) {
        character[0] = (char)i;
        TTF_SizeText(font, character, &width, &height);

        mClips[i - 32].size.x = isMonoSpace ? maxWidth : width;
        mClips[i - 32].size.y = height;

        // Save max width and height for grid size.
        if (width > maxWidth && !isMonoSpace) maxWidth = width;
        if (height > maxHeight) maxHeight = height;
    }

    SDL_Surface* fontCache = SDL_CreateRGBSurface(NULL, maxWidth * (128 - 32), maxHeight, 32, 0xff, 0xff00, 0xff0000, 0xff000000);
    SDL_Surface* glyph;
    SDL_Rect dst;

    // Go through each character and render it to the atlas.
    for (int i = 32; i < 127; i++) {
        character[0] = (char)i;

        // Grid position.
        dst.x = (i - 32) * maxWidth;
        dst.y = 0;

        mClips[i - 32].position.x = dst.x;
        mClips[i - 32].position.y = dst.y;

        // Don't bother rendering space.
        if (i != (int)' ') {
            glyph = TTF_RenderGlyph_Blended(font, i, { 255, 255, 255, 255 });
            SDL_BlitSurface(glyph, nullptr, fontCache, &dst);
        }
    }

    mTextureAtlas = new Texture(SDL_CreateTextureFromSurface(Renderer::GetRawRenderer(), fontCache));

    SDL_FreeSurface(glyph);
    SDL_FreeSurface(fontCache);
    TTF_CloseFont(font);
}

// ==================
// Font::GetGlyphClip
// ==================
Rectangle Font::GetGlyphClip(char letter) const {
    return mClips[(int)letter - 32];
}

// ==================
// Font::GetTextureAtlas
// ==================
Texture* Font::GetTextureAtlas() const {
    return mTextureAtlas;
}

}