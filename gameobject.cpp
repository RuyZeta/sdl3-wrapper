//
// Created by rodri on 21/07/2025.
//

#include "gameobject.h"
#include "game.h"
#include "texturemanager.h"

Objeto_en_Juego::Objeto_en_Juego(const LoaderParams *pParams) : ObjetoAbstractoBase(/*pParams*/),
m_position(pParams->getX(), pParams->getY()), m_unidad(1,1), m_velocidad(1, 1), m_aceleracion(0, 0),
m_magnitude(1, 0.4), xAxis(700, 0), yAxis(0, 400){


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
    TextureManager::getInstance()->drawFrame(m_textureID, //aqui la textura
        static_cast<int>(m_position.getX()),static_cast<int>(m_position.getY()), //actualiza dinámicamente aquí
        m_ancho, m_alto,
        m_currentRow, m_currentFrame,
        TheGame::getInstance()->getRenderer()); //aquí sale el renderer
}

void Objeto_en_Juego::update() {

    //m_velocidad += m_aceleracion;

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
    m_position += m_unidad;
    Objeto_en_Juego::update();
}
/////////////////////////////////////////
/// circle
///
circle::circle(const int &x, const int &y, const int &radio) : ObjetoAbstractoBase(), x(x), y(y), radio(radio) {
    m_particula = new particula(x, y, radio);
    vel = Vec2r(20, 20);
    m_particula->setVelocity(vel);
    m_particula->setAcceleration(Vec2r(2.0 * PIXELS_POR_METRO, 9.8 * PIXELS_POR_METRO )); // gravedad

}

void circle::draw() {
    filledCircleColor(TheGame::getInstance()->getRenderer(), m_particula->getPosition().getX(),
        m_particula->getPosition().getY(), radio, 0xff000000);
}

void circle::update() {
    //m_particula->setVelocity(Vec2r(1, 1));

    // integra la aceleración con la velocidad  para encontrar la nueva posición
    m_particula->setVelocity(m_particula->getVelocity() += m_particula->getAcceleration() * TheGame::deltaTime);
    m_particula->setPosition(m_particula->getPosition() += m_particula->getVelocity() * TheGame::deltaTime);

    if (m_particula->getPosition().getX() - m_particula->getMasa()<= 0) {
        m_particula->getPosition().setX(m_particula->getMasa());
        m_particula->setVelocity(m_particula->getVelocity()* Vec2r(-0.9, 0.9));
    } else if (m_particula->getPosition().getX() + m_particula->getMasa() >= TheGame::getInstance()->get_Ancho()) {
        m_particula->getPosition().setX(m_particula->getMasa());
        m_particula->setVelocity(m_particula->getVelocity()* Vec2r(-0.9, 0.9));
    }
    if (m_particula->getPosition().getY() - m_particula->getMasa() <= 0) {
        m_particula->getPosition().setY(m_particula->getMasa());
        m_particula->setVelocity(m_particula->getVelocity()* Vec2r(0.9, -0.9));
    } else if (m_particula->getPosition().getY() + m_particula->getMasa() >= TheGame::getInstance()->get_Alto()) {
        m_particula->getPosition().setY(m_particula->getMasa());
        m_particula->setVelocity(m_particula->getVelocity()* Vec2r(0.9, -0.9));
    }
}


