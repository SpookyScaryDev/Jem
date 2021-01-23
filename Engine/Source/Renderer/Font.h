#pragma once

#include <Core/Maths/Rectangle.h>
#include <Renderer/Texture.h>

namespace Jem {

// ===============================================================================
//
//     Wrapper for a texture atlas containing ASCII characters from space (32) to
//     ~ (127) and clipping information for each character. Clips store the 
//     characters position in the texture and their width and height.
//
// ===============================================================================
class Font {
public:
                        Font(const char* name, unsigned int size, bool isMonoSpace = false);
                        ~Font();

    void                LoadTTF(const char* name, unsigned int size, bool isMonoSpace = false);
    Rectangle           GetGlyphClip(char letter) const;
    Texture*            GetTextureAtlas() const;

private:
    Texture*            mTextureAtlas;
    Rectangle           mClips[127 - 32];
};

}