//
// Created by rodri on 21/07/2025.
//

#include "gameobject.h"
#include "game.h"
#include "texturemanager.h"

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
    TextureManager::getInstance()->drawFrame(m_textureID, m_x, m_y, m_ancho, m_alto,
        m_currentRow, m_currentFrame, TheGame::getInstance()->getRenderer());
}

void Objeto_en_Juego::update() {
}

void Objeto_en_Juego::clean() {
}



/////////////////////////////
/// Actor class implementation
///


void Actor::draw() {

    Objeto_en_Juego::draw();

}

void Actor::update() {
    m_x -= 1;
}

////////////////////////
/// Enemy class
///

void Enemy::draw() {

    Objeto_en_Juego::draw();
}

void Enemy::update() {
    m_y += 1;
    m_x += 1;
    m_currentFrame = int ((SDL_GetTicks() / 100) % 6);
}


