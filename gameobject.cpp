//
// Created by rodri on 21/07/2025.
//

#include "gameobject.h"
#include "game.h"
#include "texturemanager.h"

Objeto_en_Juego::Objeto_en_Juego(const LoaderParams *pParams) : ObjetoAbstractoBase(pParams),
m_position(pParams->getX(), pParams->getY()), m_unidad(1,1), m_velocidad(0, 0), m_aceleracion(0, 0){


    m_ancho = pParams->getAncho();
    m_alto = pParams->getAlto();
    m_textureID = pParams->getTextureID();
    m_currentFrame = 1; // inicializa el frame actual
    m_currentRow = 1; // inicializa la fila actual
}

// esto va entre medio de clear y present. Es la parte que pinta.
// posiblemente este código se comparte entre todas las clases derivadas
void Objeto_en_Juego::draw() {
    TextureManager::getInstance()->drawFrame(m_textureID, static_cast<int>(m_position.getX()),
        static_cast<int>(m_position.getY()), m_ancho, m_alto,
        m_currentRow, m_currentFrame, TheGame::getInstance()->getRenderer());
}

void Objeto_en_Juego::update() {

    m_velocidad += m_aceleracion;
    m_position += m_velocidad;
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
    if (!(m_currentFrame = static_cast<int>((SDL_GetTicks() / 100) % 8)))
        m_currentRow = (m_currentRow+1)%3;

    Objeto_en_Juego::update();
}

////////////////////////
/// Enemy class
///

void Enemy::draw() {

    Objeto_en_Juego::draw();
}

void Enemy::update() {
    m_position += m_unidad*2;
}


