//
// Created by rodrigo on 20/07/25.
//

#include "texturemanager.h"


void TextureManager::GetTextureDimensions(std::string id, SDL_FRect &dimensions) {

    if (mTextureMap.find(id) != mTextureMap.end()) {
        SDL_GetTextureSize(mTextureMap[id], &dimensions.w, &dimensions.h);
        dimensions.x = 0;
        dimensions.y = 0;
    } else {
        SDL_Log("Texture with id %s not found.", id.c_str());
    }
}

void TextureManager::setTextureBlend(std::string id, SDL_BlendMode mode) {
    SDL_SetTextureBlendMode(mTextureMap[id], mode);
}



//string id es para identificar la imagen con un nombre
bool TextureManager::load(std::string filename, std::string id, SDL_Renderer *pRenderer) {

    SDL_Surface *pTempSurface = IMG_Load(filename.c_str());
    if (pTempSurface == nullptr) {
        SDL_Log("Failed to load image %s: %s", filename.c_str(), SDL_GetError());
        return false;
    }
    SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_DestroySurface(pTempSurface);

    if (pTexture == nullptr) {
        SDL_Log("Failed to create texture from surface: %s", SDL_GetError());
        return false;
    }
    mTextureMap[id] = pTexture;
    return true;
}

void TextureManager::draw(std::string id, const int& x, const int& y, const int& width, const int& height, SDL_Renderer *pRenderer,
    SDL_FlipMode flip) {

    SDL_FRect sourceRect;
    SDL_FRect destRect;
    sourceRect.x = 0;
    sourceRect.y = 0;
    sourceRect.w = destRect.w = width;
    sourceRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;

    SDL_RenderTextureRotated(pRenderer, mTextureMap[id], &sourceRect, &destRect,
        0.0f, nullptr, flip);

}

void TextureManager::drawFrame(std::string id, const int& x, const int& y, const int& width, const int& height,
    const int& currentRow, const int& currentFrame,
    SDL_Renderer *pRenderer, SDL_FlipMode flip) {

    SDL_FRect sourceRect;
    SDL_FRect destRect;
    sourceRect.x = currentFrame * width;
    sourceRect.y = currentRow * height; //currentRow starts at 1 not at 0. this could be changed
    sourceRect.w = destRect.w = width;
    sourceRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderTextureRotated(pRenderer, mTextureMap[id], &sourceRect, &destRect,
        0.0f, nullptr, flip);

}

//unica instancia
TextureManager* TextureManager::s_pInstance = 0;