//
// Created by rodri on 21/07/2025.
//

#include "gameobject.h"

void GameObject::load(int x, int y, int ancho, int alto, std::string textureID) {

    m_x = x;
    m_y = y;
    m_ancho = ancho;
    m_alto = alto;
    m_sTextureID = textureID;

    m_currentFrame = 1;
    m_currentRow = 1;
}

void GameObject::draw(SDL_Renderer* pRenderer) {

    TextureManager::getInstance()->drawFrame(m_sTextureID, m_x, m_y, m_ancho, m_alto,
        m_currentRow, m_currentFrame, pRenderer);

}

void GameObject::update() {

    m_x += m_currentFrame;
    m_y += m_currentRow;
}
