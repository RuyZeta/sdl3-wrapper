//
// Created by rodrigo on 20/07/25.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <map>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <map>

typedef std::map<std::string, SDL_Texture*> Map_of_Textures;


//singleton
// como el nombre lo dice maneja las texturas, las carga y las dibuja y entrega algunas dimensiones
class TextureManager {

    Map_of_Textures mTextureMap;
    TextureManager() {};
public:
    static TextureManager* s_pInstance;
    ~TextureManager() {};
    static TextureManager* getInstance() {

        if (s_pInstance == nullptr) {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }

    void GetTextureDimensions(std::string id, SDL_FRect &dimensions);

    bool load(std::string filename, std::string id, SDL_Renderer* pRenderer);

    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer,
        SDL_FlipMode flip = SDL_FLIP_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
        SDL_Renderer* pRenderer, SDL_FlipMode flip = SDL_FLIP_NONE);

};

typedef TextureManager TheTextureManager;




#endif //TEXTUREMANAGER_H
