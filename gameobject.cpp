//
// Created by rodri on 21/07/2025.
//

#include "gameobject.h"
Objeto_en_Juego::Objeto_en_Juego(const LoaderParams *pParams) : ObjetoAbstractoBase(pParams) {

    m_x = pParams->getX();
    m_y = pParams->getY();
    m_ancho = pParams->getAncho();
    m_alto = pParams->getAlto();
    m_textureID = pParams->getTextureID();
    m_currentFrame = 1; // inicializa el frame actual
    m_currentRow = 1; // inicializa la fila actual
}

void Objeto_en_Juego::draw() {
    TextureManager::getInstance()->drawFrame(m_textureID, m_x, m_y, m_ancho, m_alto,)
        m_currentRow, m_currentFrame, TheGame::getInstance()->getRenderer());
}

void Objeto_en_Juego::update() {
}

void Objeto_en_Juego::clean() {
}


///////////////////////
/// GameObject class implementation
///
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
    // cuando actualiza x, al final de todos los frames, incrementa 1 al y
    m_x += 1;
}


/////////////////////////////
/// Actor class implementation
///
void Actor::load(int x, int y, int ancho, int alto, std::string textureID) {

    GameObject::load(x, y, ancho, alto, textureID);
}

void Actor::draw(SDL_Renderer *pRenderer) {

    GameObject::draw(pRenderer);

}

void Actor::update() {
    m_x -= 1;
}

////////////////////////
/// Enemy class
///

void Enemy::load(int x, int y, int ancho, int alto, std::string textureID) {

    GameObject::load(x, y, ancho, alto, textureID);

}

void Enemy::draw(SDL_Renderer *pRenderer) {

    GameObject::draw(pRenderer);
}

void Enemy::update() {
    m_y += 1;
    m_x += 1;
    m_currentFrame = int ((SDL_GetTicks() / 100) % 6);
}


//actor
