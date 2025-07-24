//
// Created by rodri on 21/07/2025.
//

#include "gameobject.h"
#include "game.h"
#include "texturemanager.h"

Objeto_en_Juego::Objeto_en_Juego(const LoaderParams *pParams) : ObjetoAbstractoBase(pParams),
m_position(pParams->getX(), pParams->getY()), m_unidad(1,1), m_velocidad(0, 0), m_aceleracion(0, 0),
m_magnitude(1, 0.5){


    m_ancho = pParams->getAncho();
    m_alto = pParams->getAlto();
    m_textureID = pParams->getTextureID();
    m_currentFrame = 0; // inicializa el frame actual
    m_currentRow = 0; // inicializa la fila actual
}

// esto va entre medio de clear y present. Es la parte que pinta.
// posiblemente este código se comparte entre todas las clases derivadas
void Objeto_en_Juego::draw() {
    // notar m_position.get que dinamicamente setea la posición de x e y.
    // asi, cambiar x e y en realidad da movimiento a la imagen
    // este código se va a reutilizar en todas las clases derivadas de Objeto en Juego
    // simplificando las cosas ya solo será necesario actualizar x e y para simular movimiento
    TextureManager::getInstance()->drawFrame(m_textureID, static_cast<int>(m_position.getX()),
        static_cast<int>(m_position.getY()), m_ancho, m_alto,
        m_currentRow, m_currentFrame, TheGame::getInstance()->getRenderer());
}

void Objeto_en_Juego::update() {

    //m_velocidad += m_aceleracion;
    //m_position += m_velocidad;
    m_position;
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

    m_position += m_magnitude; // mueve el actor en la dirección de la unidad
    Objeto_en_Juego::update();
}

////////////////////////
/// Enemy class
///

void Enemy::draw() {

    Objeto_en_Juego::draw();
}

void Enemy::update() {

}


